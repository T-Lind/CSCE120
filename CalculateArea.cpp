#include <iostream>
#include <cmath>

double CalculateArea(double radius) {
    using namespace std;
    return M_PI * pow(radius, 2);
}

int main() {
    using namespace std;
    double userRadius;
    cout << "Enter radius of circle: ";
    cin >> userRadius;
    cout << "Area of circle: " << CalculateArea(userRadius) << endl;
    return 0;
}