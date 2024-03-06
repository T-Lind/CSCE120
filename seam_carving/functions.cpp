#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using std::cout, std::endl, std::string;

void initializeImage(Pixel image[][MAX_HEIGHT]) {
    // iterate through columns
    for (unsigned int col = 0; col < MAX_WIDTH; col++) {
        // iterate through rows
        for (unsigned int row = 0; row < MAX_HEIGHT; row++) {
            // initialize pixel
            image[col][row] = {0, 0, 0};
        }
    }
}

void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int &width, unsigned int &height) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open " + filename);
    }

    string type;
    file >> type;
    if (type != "P3" && type != "p3") {
        throw std::runtime_error("Invalid type " + type);
    }

    file >> width >> height;
    if (width <= 0 || width > MAX_WIDTH || height <= 0 || height > MAX_HEIGHT) {
        throw std::runtime_error("Invalid dimensions");
    }

    int maxColor;
    file >> maxColor;
    if (maxColor != 255) {
        throw std::runtime_error("Invalid color value");

    }

    for (unsigned int row = 0; row < height; row++) {
        for (unsigned int col = 0; col < width; col++) {
            int r, g, b;
            file >> r >> g >> b;
            if (file.fail()) {
                throw std::runtime_error("Invalid color value");
            }
            if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
                throw std::runtime_error("Invalid color value");
            }
            image[col][row] = {static_cast<short>(r), static_cast<short>(g), static_cast<short>(b)};
        }
    }

    int r;
    file >> r;
    if (!file.fail()) {
        throw std::runtime_error("Too many values");
    }

    file.close();
}

void outputImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open " + filename);
    }

    file << "P3" << endl;
    file << width << " " << height << endl;
    file << "255" << endl;
    for (unsigned int row = 0; row < height; row++) {
        for (unsigned int col = 0; col < width; col++) {
            file << image[col][row].r << " " << image[col][row].g << " " << image[col][row].b << " ";
        }
        file << endl;
    }

}

unsigned int
energy(Pixel image[][MAX_HEIGHT], unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    // Use dual-gradient energy function for PPM file
    unsigned int deltaX = 0;
    unsigned int deltaY = 0;

    if (x == 0) {
        deltaX = static_cast<unsigned int>(pow(image[x + 1][y].r - image[width - 1][y].r, 2) +
                                           pow(image[x + 1][y].g - image[width - 1][y].g, 2) +
                                           pow(image[x + 1][y].b - image[width - 1][y].b, 2));
    } else if (x == width - 1) {

        deltaX = static_cast<unsigned int>(pow(image[0][y].r - image[x - 1][y].r, 2) +
                                           pow(image[0][y].g - image[x - 1][y].g, 2) +
                                           pow(image[0][y].b - image[x - 1][y].b, 2));
    } else {
        deltaX = static_cast<unsigned int>(pow(image[x + 1][y].r - image[x - 1][y].r, 2) +
                                           pow(image[x + 1][y].g - image[x - 1][y].g, 2) +
                                           pow(image[x + 1][y].b - image[x - 1][y].b, 2));
    }


    if (y == 0) {
        deltaY = static_cast<unsigned int>(pow(image[x][y + 1].r - image[x][height - 1].r, 2) +
                                           pow(image[x][y + 1].g - image[x][height - 1].g, 2) +
                                           pow(image[x][y + 1].b - image[x][height - 1].b, 2));
    } else if (y == height - 1) {
        deltaY = static_cast<unsigned int>(pow(image[x][0].r - image[x][y - 1].r, 2) +
                                           pow(image[x][0].g - image[x][y - 1].g, 2) +
                                           pow(image[x][0].b - image[x][y - 1].b, 2));
    } else {
        deltaY = static_cast<unsigned int>(pow(image[x][y + 1].r - image[x][y - 1].r, 2) +
                                           pow(image[x][y + 1].g - image[x][y - 1].g, 2) +
                                           pow(image[x][y + 1].b - image[x][y - 1].b, 2));
    }

    return deltaX + deltaY;

}

// uncomment functions as you implement them (part 2)


unsigned int loadVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_col, unsigned int width, unsigned int height, unsigned int seam[]) {
    /*
     * A vertical seam is loaded by starting at the provided starting column and row 0 and utilizing a greedy algorithm. The total energy of the seam is the sum of the energies of each pixel represented in the seam. From the starting pixel, follow a path to the next pixel which is the pixel in the next row with minimal energy that is adjacent to the current pixel. For example, if we start at pixel(1, 0). Following a path, we walk from the top down toward the next pixel that is on the next row, the options are
go directly forward - pixel(1, 1) i.e. keep the same column (⬇ in context of the table)
go to the left - pixel(2, 1) i.e. increase the column by 1 (⬊ in context of the table)
go to the right - pixel(0, 1) i.e. decrease the column by 1 (⬋ in context of the table)
Sometimes, more than one pixel has the same minimum energy value. In those cases
First prefer to go directly forward (i.e. keep the same column) (⬇ in context of the table)
Next prefer to go left (i.e. increase the column by 1) (⬊ in context of the table)
Note: you will only go right (i.e. decrease the column by 1) when it is strictly less than other options.
Store the column index for the winner in the corresponding location in the seam.
Note: seams cannot cross over the bounds of an image.
     */
    unsigned int totalEnergy = 0;
    seam[0] = start_col;
    totalEnergy += energy(image, start_col, 0, width, height);
    for (unsigned int row = 1; row < height; row++) {
        unsigned int col = seam[row - 1];
        unsigned int minEnergy = energy(image, col, row, width, height);
        unsigned int minCol = col;
        if (col < width - 1) {
            unsigned int rightEnergy = energy(image, col + 1, row, width, height);
            if (rightEnergy < minEnergy) {
                minEnergy = rightEnergy;
                minCol = col + 1;
            }
        }
        if (col > 0) {
            unsigned int leftEnergy = energy(image, col - 1, row, width, height);
            if (leftEnergy < minEnergy) {
                minEnergy = leftEnergy;
                minCol = col - 1;
            }
        }
        seam[row] = minCol;
        totalEnergy += minEnergy;
    }
    return totalEnergy;
}


 unsigned int loadHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_row, unsigned int width, unsigned int height, unsigned int seam[]) {
/*
 *
This is analogous to loading a vertical seam but now the path starts in the left hand column (i.e. index 0). In the horizontal seam, the index now represents the column and the value is the row.

Moving options are now:
Moving forward keeps the same row. ➡
Moving right increases the row. ⬊
Moving left decreases the row. ⬈
For tiebreaks (Same rules used for loading a vertical seam):
First prefer to go directly forward (i.e. keep the same row) ➡
Next prefer to go left (i.e. decrease the row by 1) ⬈
Note: you will only go right (i.e. increase the row by 1) when it is strictly less than other options.
 */
    unsigned int totalEnergy = 0;
    seam[0] = start_row;
    totalEnergy += energy(image, 0, start_row, width, height);
    for (unsigned int col = 1; col < width; col++) {
        unsigned int row = seam[col - 1];
        unsigned int minEnergy = energy(image, col, row, width, height);
        unsigned int minRow = row;
        if (row < height - 1) {
            unsigned int downEnergy = energy(image, col, row + 1, width, height);
            if (downEnergy < minEnergy) {
                minEnergy = downEnergy;
                minRow = row + 1;
            }
        }
        if (row > 0) {
            unsigned int upEnergy = energy(image, col, row - 1, width, height);
            if (upEnergy < minEnergy) {
                minEnergy = upEnergy;
                minRow = row - 1;
            }
        }
        seam[col] = minRow;
        totalEnergy += minEnergy;
    }
    return totalEnergy;

}

void findMinVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
/*
 * You will want to find the vertical seam with minimal energy. You will have to determine the seam starting at the first row of each column and keep track of the seam and the corresponding energy that is lowest.
 *
 * If you have more than one seam with minimal energy, then prefer the one that starts at the lowest column index.
 */

    unsigned int minEnergy = loadVerticalSeam(image, 0, width, height, seam);
    for (unsigned int col = 1; col < width; col++) {
        unsigned int newSeam[MAX_HEIGHT];
        unsigned int newEnergy = loadVerticalSeam(image, col, width, height, newSeam);
        if (newEnergy < minEnergy) {
            minEnergy = newEnergy;
            for (unsigned int row = 0; row < height; row++) {
                seam[row] = newSeam[row];
            }
        }
    }
}

 void findMinHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
   // TODO: implement (part 2)
   /*
    *
Finding a horizontal seam is analogous to finding the minimal energy vertical seam. You will start at the first column of each row.
If you have more than one seam with minimal energy, then prefer the one that starts at the lowest row index.
    */
    unsigned int minEnergy = loadHorizontalSeam(image, 0, width, height, seam);
    for (unsigned int row = 1; row < height; row++) {
        unsigned int newSeam[MAX_WIDTH];
        unsigned int newEnergy = loadHorizontalSeam(image, row, width, height, newSeam);
        if (newEnergy < minEnergy) {
            minEnergy = newEnergy;
            for (unsigned int col = 0; col < width; col++) {
                seam[col] = newSeam[col];
            }
        }
    }
 }

void removeVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int &width, unsigned int height, unsigned int verticalSeam[]) {
    for (unsigned int row = 0; row < height; row++) {
        unsigned int col = verticalSeam[row];

        for (unsigned int j = col; j < width - 1; j++) {
            image[j][row] = image[j + 1][row];
        }
    }
    width--;
}


 void removeHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int& height, unsigned int horizontalSeam[]) {
   // TODO: implement (part 2)
   /*
Removing a horizontal seam is analogous to removing a vertical seam.
    */
    for (unsigned int col = 0; col < width; col++) {
        unsigned int row = horizontalSeam[col];

        for (unsigned int j = row; j < height - 1; j++) {
            image[col][j] = image[col][j + 1];
        }
    }
 }
