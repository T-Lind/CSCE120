#include <iostream>

double* InitializeDoubleArray(int n){
    double* array = new double[n];
    for (int i = 0; i < n; i++){
        array[i] = 0;
    }
    return array;
}

int main(){
    using namespace std;

    cout << "Enter number of elements :";
    int n;
    cin >> n;
    double* array = InitializeDoubleArray(n);
    // print array
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}