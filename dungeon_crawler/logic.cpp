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
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
    ifstream file(fileName);
    if (!file) {
        cout << "Failed to open file: " << fileName << endl;
        return nullptr;
    }

    file >> maxRow >> maxCol;
    char** map = createMap(maxRow, maxCol);

    for(int i = 0; i < maxRow; i++) {
        for(int j = 0; j < maxCol; j++) {
            file >> map[i][j];
            if(map[i][j] == TILE_PLAYER) {
                player.row = i;
                player.col = j;
            }
        }
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
void getDirection(char input, int& nextRow, int& nextCol) {
    switch(input) {
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
char** createMap(int maxRow, int maxCol) {
    char** map = new char*[maxRow];
    for(int i = 0; i < maxRow; i++) {
        map[i] = new char[maxCol];
    }

    for(int i = 0; i < maxRow; i++) {
        for(int j = 0; j < maxCol; j++) {
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
void deleteMap(char**& map, int& maxRow) {
    for(int i = 0; i < maxRow; i++) {
        delete[] map[i];
    }
    delete[] map;
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
char** resizeMap(char** map, int& maxRow, int& maxCol) {
    // Create a new map with double the size
    int newMaxRow = maxRow * 2;
    int newMaxCol = maxCol * 2;
    char** newMap = createMap(newMaxRow, newMaxCol);

    // Copy the old map into the new map
    for(int i = 0; i < maxRow; i++) {
        for(int j = 0; j < maxCol; j++) {
            newMap[i][j] = map[i][j]; // Copy to the same position
            newMap[i + maxRow][j] = map[i][j]; // Copy below
            newMap[i][j + maxCol] = map[i][j]; // Copy to the right
            newMap[i + maxRow][j + maxCol] = map[i][j]; // Copy diagonal down
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
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
    // Check if the next position is out of bounds
    if(nextRow < 0 || nextRow >= maxRow || nextCol < 0 || nextCol >= maxCol) {
        return STATUS_STAY;
    }

    // Check the tile at the next position
    char tile = map[nextRow][nextCol];
    switch(tile) {
        case TILE_OPEN:
            // Move the player to the next position
            map[player.row][player.col] = TILE_OPEN;
            map[nextRow][nextCol] = TILE_PLAYER;
            player.row = nextRow;
            player.col = nextCol;
            return STATUS_MOVE;

        case TILE_TREASURE:
            // Move the player to the next position and increment the treasure count
            map[player.row][player.col] = TILE_OPEN;
            map[nextRow][nextCol] = TILE_PLAYER;
            player.row = nextRow;
            player.col = nextCol;
            player.treasure++;
            return STATUS_TREASURE;

        case TILE_EXIT:
            // Check if the player has at least one treasure
            if(player.treasure > 0) {
                // Move the player to the next position and decrement the treasure count
                map[player.row][player.col] = TILE_OPEN;
                map[nextRow][nextCol] = TILE_PLAYER;
                player.row = nextRow;
                player.col = nextCol;
                player.treasure--;
                return STATUS_LEAVE;
            } else {
                return STATUS_STAY;
            }

        case TILE_PILLAR:
        case TILE_MONSTER:
            // The player cannot move onto a pillar or monster
            return STATUS_STAY;

        default:
            // Do nothing if the tile is not recognized
            return STATUS_STAY;
    }
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
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
    // Directions to check for monsters
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for(int d = 0; d < 4; d++) {
        int dx = directions[d][0];
        int dy = directions[d][1];

        for(int i = 1; i < maxRow; i++) {
            int checkRow = player.row + i * dx;
            int checkCol = player.col + i * dy;

            // Check if the position is out of bounds
            if(checkRow < 0 || checkRow >= maxRow || checkCol < 0 || checkCol >= maxCol) {
                break;
            }

            // Check the tile at the position
            char tile = map[checkRow][checkCol];
            switch(tile) {
                case TILE_MONSTER:
                    // Move the monster towards the player
                    map[checkRow][checkCol] = TILE_OPEN;
                    map[checkRow - dx][checkCol - dy] = TILE_MONSTER;
                    break;

                case TILE_PILLAR:
                case TILE_EXIT:
                    // Stop checking in this direction if we hit an obstacle
                    i = maxRow;
                    break;

                case TILE_PLAYER:
                    // A monster has moved onto the player's tile
                    return true;

                default:
                    // Continue checking in this direction
                    break;
            }
        }
    }

    return false;
}
