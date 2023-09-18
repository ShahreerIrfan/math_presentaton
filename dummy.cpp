#include <iostream>
#include <vector>

using namespace std; // This allows you to use "cin" and "cout" without specifying "std::" prefix

// Function to print a matrix
void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}

// Function to perform Gauss-Jordan elimination for matrix inversion
bool gaussJordan(vector<vector<int>>& A, vector<vector<int>>& inv) {
    int n = A.size();

    // Initialize the inverse matrix as the identity matrix
    inv.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        inv[i][i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        // Find the pivot row
        int pivot_row = -1;
        for (int j = i; j < n; ++j) {
            if (A[j][i] != 0) {
                pivot_row = j;
                break;
            }
        }

        if (pivot_row == -1) {
            cerr << "Matrix is not invertible." << endl;
            return false;
        }

        // Swap rows i and pivot_row
        swap(A[i], A[pivot_row]);
        swap(inv[i], inv[pivot_row]);

        int pivot_val = A[i][i];

        // Scale the pivot row to make the pivot element 1
        for (int j = 0; j < n; ++j) {
            A[i][j] /= pivot_val;
            inv[i][j] /= pivot_val;
        }

        // Eliminate other rows
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                int factor = A[j][i];
                for (int k = 0; k < n; ++k) {
                    A[j][k] -= factor * A[i][k];
                    inv[j][k] -= factor * inv[i][k];
                }
            }
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    // Define the matrix A and inverse matrix
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> inv;

    cout << "Enter the elements of the matrix A:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    if (gaussJordan(A, inv)) {
        cout << "Original Matrix A:\n";
        printMatrix(A);

        cout << "\nInverse Matrix A^-1:\n";
        printMatrix(inv);
    }

    return 0;
}
