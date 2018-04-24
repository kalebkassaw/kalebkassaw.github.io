#include <iostream>
#include <cmath>
using namespace std;

// MATRIX [C] [R]... UNFORTUNATELY IN TRANSPOSE FORM UNTIL FIXED

int getSize () {
    int size = 0;
    while (size == 0) {
        cout << "Enter matrix size: ";
        cin >> size;
    }
    return size;
}

void resetMatrixRow (float matrixR[], int matrixRow, int matrixSize) {
    for (int matrixCol = 0; matrixCol <= matrixSize; matrixCol++) {
        matrixR[matrixCol] = 0;
    }
}

void collectMatrixRow (float matrixR[], int matrixRow, int matrixSize) {
    for (int matrixCol = 0; matrixCol < matrixSize; matrixCol++) {
        cout << "Enter entry a" << matrixRow << matrixCol << ": " ;
        cin >> matrixR[matrixCol];
    }
}

void collectB (float matrixCoeffs[], int matrixSize) {
    for (int i = 0; i<matrixSize; i++) {
    cout << "Enter coefficient b" << i << ": ";
    cin >> matrixCoeffs[i];
}}

int main () {

// Matrix size initialization and subsequent matrix initializations

    const int matrixSize = getSize();
    float matrixT[matrixSize+1][matrixSize];
    float matrix[matrixSize][matrixSize+1];
    float matrixB[matrixSize];

// Collect matrix A and assign to augmented matrix transpose

    float matrixR[matrixSize+1];
    for (int i = 0; i < matrixSize; i++) {
        resetMatrixRow(matrixR, i, matrixSize);
        collectMatrixRow(matrixR, i, matrixSize);
        for (int j=0; j<matrixSize; j++)
            matrixT[j][i] = matrixR[j];
    }

// Collect coefficients in *b* of A*x* = *b* and assign to augmented matrix transpose

    collectB (matrixB, matrixSize);
    for (int i=0; i<matrixSize; i++)
        matrixT[matrixSize][i] = matrixB[i];

    for (int i = 0; i<matrixSize; i++)
        for (int j=0; j<matrixSize + 1; j++)
            matrix[i][j] = matrixT[j][i];

// Print initial matrix

    for (int i = 0; i<matrixSize; i++) {
        for (int j=0; j<matrixSize + 1; j++) {
            cout << matrix[i][j] << "  ";
            if (j == matrixSize - 1)
                cout << "|  ";
        }
        cout << endl;
    }

// Row operations to put into row echelon form (REF)
// KEEP TRACK OF PIVOT LOCATION

int pivotR;
int pivotC = 0;
float divisor = 0.0;
float tempRow[matrixSize + 1];
int zeroCounter = 0;

for (pivotR = 0; pivotR < matrixSize; pivotR++) {

    // ROW SWAP
    for (int i=0; i<matrixSize+1; i++) {
        tempRow[i] = matrix[pivotR][i];
        matrix[pivotR][i] = matrix[matrixSize-zeroCounter][i];
        matrix[matrixSize-zeroCounter][i] = tempRow[i];
    }

    // ROW SCALE
    divisor = matrix[pivotR][pivotC];
    for (int i=0; i<matrixSize+1; i++) {
        matrix[pivotR][i] = matrix[pivotR][i] / divisor;
    }

    // ROW + SCALED ROW
    for 

}

}

// cout << "Matrix is in reduced-row echelon form."
    
    return 0;
}