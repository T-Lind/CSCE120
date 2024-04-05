#include <iostream>

using namespace std;

void increaseArray(int **&ary, int &numRows, int &numColumns, int addRows, int addColumns) {
    // Step 1: Create a new 2D array with the new size
    int newRows = numRows + addRows;
    int newColumns = numColumns + addColumns;
    int **newArray = new int *[newRows];
    for (int i = 0; i < newRows; ++i)
        newArray[i] = new int[newColumns]();

    // Step 2: Copy the old array's data into the new array
    for (int i = 0; i < numRows; ++i)
        for (int j = 0; j < numColumns; ++j)
            newArray[i][j] = ary[i][j];

    // Step 3: Initialize the new cells in a row
    for (int i = 0; i < numRows; ++i)
        for (int j = numColumns; j < newColumns; ++j)
            newArray[i][j] = (i > 0 ? newArray[i - 1][j - 1] : 0) + newArray[i][j - 1] +
                             (i < numRows - 1 ? newArray[i + 1][j - 1] : 0);

    // Step 4: Initialize the new cells in a column
    for (int i = numRows; i < newRows; ++i)
        for (int j = 0; j < newColumns; ++j)
            newArray[i][j] = newArray[i - 1][j] + (j > 0 ? newArray[i - 1][j - 1] : 0) +
                             (j < newColumns - 1 ? newArray[i - 1][j + 1] : 0);

    // Step 5: Delete the old array and update the reference to the new array
    for (int i = 0; i < numRows; ++i)
        delete[] ary[i];
    delete[] ary;
    ary = newArray;

    // Step 6: Update the numRows and numColumns variables to reflect the new size
    numRows = newRows;
    numColumns = newColumns;
}

int **remove_all_zeroes_rows(int **matrix, int nrows, int ncolumns, int &new_nrows) {
    if (nrows == 0 || ncolumns == 0)
        throw std::invalid_argument("Matrix must have at least one row and one column.");

    int **newArr = new int *[new_nrows];
    for (int i = 0; i < new_nrows; ++i)
        newArr[i] = new int[ncolumns];

    int idx = 0;
    for (int j = 0; j < nrows; j++) {
        bool hasNonZero = false;
        for (int k = 0; k < ncolumns; k++) {
            if (matrix[j][k] != 0) {
                hasNonZero = true;
                break;
            }
        }
        if (hasNonZero) {
            for (int k = 0; k < ncolumns; k++) {
                newArr[idx][k] = matrix[j][k];
            }
            idx++;
        }
    }
    return newArr;
}

int main() {
    int rows = 3;
    int cols = 4;
    int** matrix = new int*[rows];
    for(int i = 0; i < rows; ++i)
        matrix[i] = new int[cols];
    matrix[0] = new int[cols]{5, 2, 1, 3};
    matrix[1] = new int[cols]{-1, 1, 3, 2};
    matrix[2] = new int[cols]{0, 1, 1, 2};

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " "; }
        cout << endl;
    }
    increaseArray(matrix, rows, cols, 2, 3);
    cout << endl;

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " "; }
        cout << endl;
    }
    return 0;
}

