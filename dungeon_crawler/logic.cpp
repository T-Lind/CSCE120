#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"


using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char **loadLevel(const string &fileName, int &maxRow, int &maxCol, Player &player) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Failed to open file: " << fileName << endl;
        return nullptr;
    }

    // Check if the file is empty
    if (file.peek() == EOF) {
        cout << "File is empty: " << fileName << endl;
        return nullptr;
    }

    file >> maxRow >> maxCol;
    if (maxRow <= 0 || maxCol <= 0 || static_cast<long long>(maxRow) * maxCol > 2147483647) {
        cout << "Invalid map dimensions: " << maxRow << "x" << maxCol << endl;
        return nullptr;
    }

    file >> player.row >> player.col;
    if (player.row < 0 || player.row >= maxRow || player.col < 0 || player.col >= maxCol) {
        cout << "Invalid player starting location: " << player.row << "," << player.col << endl;
        return nullptr;
    }

    char **map = createMap(maxRow, maxCol);
    if (map == nullptr) {
        cout << "Failed to create map" << endl;
        return nullptr;
    }

    int tileCount = 0;
    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < maxCol; j++) {
            char tile;
            do {
                file >> tile;
            } while (std::isspace(tile)); // Skip over any whitespace characters

            if (file.fail()) {
                cout << "Failed to read cell at " << i << "," << j << endl;
                deleteMap(map, maxRow);
                return nullptr;
            }

            map[i][j] = tile;
            tileCount++;

            if (i == player.row && j == player.col) {
                if (tile != TILE_OPEN) {
                    cout << "Player's starting location is not an open spot: " << player.row << "," << player.col
                         << endl;
                    deleteMap(map, maxRow);
                    return nullptr;
                }
                map[i][j] = TILE_PLAYER;
            }
        }
    }

    if (tileCount != maxRow * maxCol) {
        cout << "Invalid number of tiles: " << tileCount << " (expected " << maxRow * maxCol << ")" << endl;
        deleteMap(map, maxRow);
        return nullptr;
    }

    if (file.bad()) {
        cout << "Error while reading file" << endl;
        deleteMap(map, maxRow);
        return nullptr;
    }

    file.close();
    return map;
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int &nextRow, int &nextCol) {
    switch (input) {
        case MOVE_UP:
            nextRow--;
            break;
        case MOVE_DOWN:
            nextRow++;
            break;
        case MOVE_LEFT:
            nextCol--;
            break;
        case MOVE_RIGHT:
            nextCol++;
            break;
        default:
            // Do nothing if the input is not recognized
            break;
    }
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char **createMap(int maxRow, int maxCol) {
    char **map = new char *[maxRow];
    for (int i = 0; i < maxRow; i++) {
        map[i] = new char[maxCol];
    }

    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < maxCol; j++) {
            map[i][j] = TILE_OPEN;
        }
    }

    return map;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char **&map, int &maxRow) {
    // Check if the map is null
    if (map == nullptr) {
        maxRow = 0;
        return;
    }

    // Deallocate each row
    for (int i = 0; i < maxRow; i++) {
        if (map[i] != nullptr) {
            delete[] map[i];
            map[i] = nullptr;
        }
    }

    // Deallocate the array of pointers
    delete[] map;

    // Update map and maxRow
    map = nullptr;
    maxRow = 0;
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char **resizeMap(char **map, int &maxRow, int &maxCol) {
    // Check if the map is null or one of the dimensions is invalid
    if (map == nullptr || maxRow <= 0 || maxCol <= 0) {
        return nullptr;
    }

    // Create a new map with double the size
    int newMaxRow = maxRow * 2;
    int newMaxCol = maxCol * 2;
    char **newMap = createMap(newMaxRow, newMaxCol);

    // Copy the old map into the new map
    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < maxCol; j++) {
            char tile = map[i][j];
            newMap[i][j] = tile; // Copy to the same position
            newMap[i + maxRow][j] = (tile == TILE_PLAYER) ? TILE_OPEN : tile; // Copy below
            newMap[i][j + maxCol] = (tile == TILE_PLAYER) ? TILE_OPEN : tile; // Copy to the right
            newMap[i + maxRow][j + maxCol] = (tile == TILE_PLAYER) ? TILE_OPEN : tile; // Copy diagonal down
        }
    }

    // Delete the old map
    deleteMap(map, maxRow);

    // Update the maxRow and maxCol values
    maxRow = newMaxRow;
    maxCol = newMaxCol;

    return newMap;
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure.
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char **map, int maxRow, int maxCol, Player &player, int nextRow, int nextCol) {
    // Save the current position
    int oldRow = player.row;
    int oldCol = player.col;

    // Check if the next position is out of bounds or on an impassable tile
    if (nextRow < 0 || nextRow >= maxRow || nextCol < 0 || nextCol >= maxCol ||
        map[nextRow][nextCol] == TILE_PILLAR || map[nextRow][nextCol] == TILE_MONSTER) {
        nextRow = player.row;
        nextCol = player.col;
        return STATUS_STAY;
    }

    // Check if the next position is on a treasure tile
    if (map[nextRow][nextCol] == TILE_TREASURE) {
        player.treasure++;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        map[oldRow][oldCol] = TILE_OPEN;
        return STATUS_TREASURE;
    }

    // Check if the next position is on an amulet tile
    if (map[nextRow][nextCol] == TILE_AMULET) {
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        map[oldRow][oldCol] = TILE_OPEN;
        return STATUS_AMULET;
    }

    // Check if the next position is on a door to the next level
    if (map[nextRow][nextCol] == TILE_DOOR) {
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        map[oldRow][oldCol] = TILE_OPEN;
        return STATUS_LEAVE;
    }

    // Check if the next position is on an exit to the whole dungeon
    if (map[nextRow][nextCol] == TILE_EXIT) {
        if (player.treasure > 0) {
            player.row = nextRow;
            player.col = nextCol;
            map[player.row][player.col] = TILE_PLAYER;
            map[oldRow][oldCol] = TILE_OPEN;
            return STATUS_ESCAPE;
        } else {
            nextRow = player.row;
            nextCol = player.col;
            return STATUS_STAY;
        }
    }

    // If none of the above conditions are met, the player simply moves
    player.row = nextRow;
    player.col = nextCol;
    map[player.row][player.col] = TILE_PLAYER;
    map[oldRow][oldCol] = TILE_OPEN;
    return STATUS_MOVE;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char **map, int maxRow, int maxCol, const Player &player) {
    // Directions to check for monsters
    int directions[4][2] = {{-1, 0},
                            {1,  0},
                            {0,  -1},
                            {0,  1}};
    bool playerKilled = false;

    for (int d = 0; d < 4; d++) {
        int dx = directions[d][0];
        int dy = directions[d][1];

        for (int i = 1; i < maxRow; i++) {
            int checkRow = player.row + i * dx;
            int checkCol = player.col + i * dy;

            // Check if the position is out of bounds
            if (checkRow < 0 || checkRow >= maxRow || checkCol < 0 || checkCol >= maxCol) {
                break;
            }

            // Check the tile at the position
            char tile = map[checkRow][checkCol];
            switch (tile) {
                case TILE_MONSTER:
                    // Move the monster towards the player
                    map[checkRow][checkCol] = TILE_OPEN;
                    map[checkRow - dx][checkCol - dy] = TILE_MONSTER;
                    // Check if the monster has moved onto the player's tile
                    if (checkRow - dx == player.row && checkCol - dy == player.col) {
                        playerKilled = true;
                    }
                    break;

                case TILE_PILLAR:
                case TILE_EXIT:
                    // Stop checking in this direction if we hit an obstacle
                    i = maxRow;
                    break;

                default:
                    // Continue checking in this direction
                    break;
            }
        }
    }

    return playerKilled;
}