#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void populateXYGrid(vector<double> xvals, vector<double> yvals, vector<vector<double>> &xygrid) {
    for (double x: xvals) {
        for (double y: yvals) {
            xygrid.push_back({x, y});
        }
    }


}

void makeRotationMatrixForA(vector<vector<double>> &a, double theta) {
    a = {{cos(theta), -sin(theta)},
         {sin(theta), cos(theta)}};
}

void populateUVGrid(vector<vector<double>> a, vector<vector<double>> xygrid, vector<vector<double>> &uvgrid) {
    for (const vector<double> &point: xygrid) {
        double u = a[0][0] * point[0] + a[0][1] * point[1];
        double v = a[1][0] * point[0] + a[1][1] * point[1];
        uvgrid.push_back({u, v});
    }
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

    // Ensure populateXYGrid works

    vector<vector<double>> expectedXY = {{-1.0, -1.0},
                                         {-1.0, 0.0},
                                         {-1.0, 1.0},
                                         {0.0, -1.0},
                                         {0.0, 0.0},
                                         {0.0, 1.0},
                                         {1.0, -1.0},
                                         {1.0, 0.0},
                                         {1.0, 1.0}};

    for (int i = 0; i < xygrid.size(); i++) {
        for (int j = 0; j < 2; j++) {
            if (abs(xygrid[i][j] - expectedXY[i][j]) > 0.001) {
                cout << "Test failed: xygrid[" << i << "][" << j << "] was " << xygrid[i][j] << " but expected " << expectedXY[i][j] << endl;
                return;
            }
        }

    }

    // ensure makeRotationMatrixForA works
    vector<vector<double>> expectedA = {{0.707107, -0.707107},
                                        {0.707107, 0.707107}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (abs(a[i][j] - expectedA[i][j]) > 0.001) {
                cout << "Test failed: a[" << i << "][" << j << "] was " << a[i][j] << " but expected " << expectedA[i][j] << endl;
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
