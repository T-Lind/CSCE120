#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    // Create a grid of points in x-y space
    vector<double> xvals = {-1.0, 0.0, 1.0};
    vector<double> yvals = {-1.0, 0.0, 1.0};
    vector<vector<double>> xygrid;

    // TODO: Insert all possible permutations of (x, y) for x, y in xvals, yvals into xygrid.


    // TODO: Define a as a 45 degree CCW rotation matrix.
    vector<vector<double>> a;


    vector<vector<double>> uvgrid;
    // TODO: Compute the matrix product of a and (x, y) for each (x, y) in xygrid and store the result in uvgrid.


    // Print the transformed coordinates and original coordinates
    for (int i = 0; i < xygrid.size(); i++) {
        cout << "Original: (" << xygrid[i][0] << ", " << xygrid[i][1] << ") ";
        cout << "Transformed: (" << uvgrid[i][0] << ", " << uvgrid[i][1] << ") " << endl;
    }
    return 0;
}