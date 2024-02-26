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

void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int& height) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open " + filename);
    }

    string type;
    file >> type;
    if (type != "P3" && type != "p3")
    {
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
        if (file.fail())
        {
            throw std::runtime_error("Invalid color value");
        } if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
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

unsigned int energy(Pixel image[][3], unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    // Use dual-gradient energy function for PPM file

    // check if pixel isn't on edge or corner
    if (x > 0 && x < width - 1 && y > 0 && y < height - 1) {
        unsigned int rX = image[x + 1][y].r - image[x - 1][y].r;
        unsigned int gX = image[x + 1][y].g - image[x - 1][y].g;
        unsigned int bX = image[x + 1][y].b - image[x - 1][y].b;
        unsigned int deltaX = rX * rX + gX * gX + bX * bX;

        unsigned int rY = image[x][y + 1].r - image[x][y - 1].r;
        unsigned int gY = image[x][y + 1].g - image[x][y - 1].g;
        unsigned int bY = image[x][y + 1].b - image[x][y - 1].b;
        unsigned int deltaY = rY * rY + gY * gY + bY * bY;

        return deltaX + deltaY;
    }
    else {
        // solve for edge/corner cases using a wrap around method
        unsigned int rX = image[(x + 1) % width][y].r - image[(x - 1 + width) % width][y].r;
        unsigned int gX = image[(x + 1) % width][y].g - image[(x - 1 + width) % width][y].g;
        unsigned int bX = image[(x + 1) % width][y].b - image[(x - 1 + width) % width][y].b;
        unsigned int deltaX = rX * rX + gX * gX + bX * bX;

        unsigned int rY = image[x][(y + 1) % height].r - image[x][(y - 1 + height) % height].r;
        unsigned int gY = image[x][(y + 1) % height].g - image[x][(y - 1 + height) % height].g;
        unsigned int bY = image[x][(y + 1) % height].b - image[x][(y - 1 + height) % height].b;
        unsigned int deltaY = rY * rY + gY * gY + bY * bY;

        return deltaX + deltaY;d
    }
}

// uncomment functions as you implement them (part 2)

// unsigned int loadVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_col, unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
//   return 0;
// }

// unsigned int loadHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_row, unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
//   return 0;
// }

// void findMinVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
// }

// void findMinHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
// }

// void removeVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int height, unsigned int verticalSeam[]) {
//   // TODO: implement (part 2)
// }

// void removeHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int& height, unsigned int horizontalSeam[]) {
//   // TODO: implement (part 2)
// }
