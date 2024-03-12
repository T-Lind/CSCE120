#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void populateXYGrid(/*TODO: Figure out parameters*/) {
    // TODO: Implement
}

void makeRotationMatrixForA(/*TODO: Figure out parameters*/) {
    // TODO: Implement
}

void populateUVGrid(/*TODO: Figure out parameters*/) {
    // TODO: Implement
}

void runTests() {
    vector<double> xvals = {-1.0, 0.0, 1.0};
    vector<double> yvals = {-1.0, 0.0, 1.0};
    vector<vector<double>> xygrid;
    populateXYGrid(xvals, yvals, xygrid);

    vector<vector<double>> a;
    makeRotationMatrixForA(a, 45.0 * M_PI / 180.0);

    vector<vector<double>> uvgrid;
    populateUVGrid(a, xygrid, uvgrid);

    // Check the transformed coordinates
    vector<vector<double>> expected = {{-1.11022e-16, -1.41421},
                                       {-0.707107, -0.707107},
                                       {-1.41421, 1.11022e-16},
                                       {0.707107, -0.707107},
                                       {0, 0},
                                       {-0.707107, 0.707107},
                                       {1.41421, -1.11022e-16},
                                       {0.707107, 0.707107},
                                       {1.11022e-16, 1.41421}};



    for (int i = 0; i < xygrid.size(); i++) {
        for (int j = 0; j < 2; j++) {
            if (abs(uvgrid[i][j] - expected[i][j]) > 0.001) {
                cout << "Test failed: uvgrid[" << i << "][" << j << "] was " << uvgrid[i][j] << " but expected " << expected[i][j] << endl;
                return;
            }
        }
    }
    cout << "Tests passed!" << endl;
}


int main() {
    // Create a grid of points in x-y space
    vector<double> xvals = {-1.0, 0.0, 1.0};
    vector<double> yvals = {-1.0, 0.0, 1.0};

    vector<vector<double>> xygrid;
    // TODO: Insert all possible permutations of (x, y) for x, y in xvals, yvals into xygrid.
    populateXYGrid(xvals, yvals, xygrid);


    vector<vector<double>> a;
    // TODO: Define a as a 45 degree CCW rotation matrix.
    makeRotationMatrixForA(a, 45.0 * M_PI / 180.0);



    vector<vector<double>> uvgrid;
    // TODO: Compute the matrix product of a and (x, y) for each (x, y) in xygrid and store the result in uvgrid.
    populateUVGrid(a, xygrid, uvgrid);


    // Print the transformed coordinates and original coordinates
    for (int i = 0; i < xygrid.size(); i++) {
        cout << "Original: (" << xygrid[i][0] << ", " << xygrid[i][1] << ") ";
        cout << "Transformed: (" << uvgrid[i][0] << ", " << uvgrid[i][1] << ") " << endl;
    }

    runTests();

    return 0;
}