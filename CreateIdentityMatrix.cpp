#include <iostream>

double** MakeIdentityMat(int n)
{

    double** matrix = new double*[n];
    for (int i = 0; i < n; i++){
        matrix[i] = new double[n];
        for (int j = 0; j < n; j++){
            if (i == j){
                matrix[i][j] = 1.0;
            } else {
                matrix[i][j] = 0.0;
            }
        }
    }
    return matrix;

}

int main(){
    using namespace std;

    cout << "Enter # rows/cols :";
    int n;
    cin >> n;
    double** matrix = MakeIdentityMat(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // have to do the memory deallocation that we learned in class
    for (int i = 0; i < n; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

