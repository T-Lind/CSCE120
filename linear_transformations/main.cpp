#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    // Create a grid of points in x-y space
    vector<double> xvals = {-1.0, 0.0, 1.0};
    vector<double> yvals = {-1.0, 0.0, 1.0};
    vector<vector<double>> xygrid;
    for (double x: xvals) {
        for (double y: yvals) {
            xygrid.push_back({x, y});
        }
    }

    // Apply linear transform
    double theta = 45.0 * M_PI / 180.0;
    vector<vector<double>> a = {{cos(theta), -sin(theta)},
                                {sin(theta), cos(theta)}};
    vector<vector<double>> uvgrid;
    for (const vector<double> &point: xygrid) {
        double u = a[0][0] * point[0] + a[0][1] * point[1];
        double v = a[1][0] * point[0] + a[1][1] * point[1];
        uvgrid.push_back({u, v});
    }


    // Print the transformed coordinates and original coordinates
    for (int i = 0; i < xygrid.size(); i++) {
        cout << "Original: (" << xygrid[i][0] << ", " << xygrid[i][1] << ") ";
        cout << "Transformed: (" << uvgrid[i][0] << ", " << uvgrid[i][1] << ") " << endl;
    }
    return 0;
}