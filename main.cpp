#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;


int** transpose(int** arr, int rows, int cols) {
    int** transposed = new int*[cols];

    for (int i = 0; i < cols; ++i) {
        transposed[i] = new int[rows];
        for (int j = 0; j < rows; ++j) {
            transposed[i][j] = arr[j][i];
        }
    }

    return transposed;
}

int** funct(int arr[][COLS], int rows, int cols){
    int** array = new int*[rows]; 
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols]; 
    }

    array[0][0] = 1 * ((arr[1][1] * arr[2][2]) - (arr[1][2] * arr[2][1])); // c11
    array[0][1] = -1 * ((arr[1][0] * arr[2][2]) - (arr[1][2] * arr[2][0])); // c12
    array[0][2] = 1 * ((arr[1][0] * arr[2][1]) - (arr[1][1] * arr[2][0])); // c13

    array[1][0] = -1 * ((arr[0][1] * arr[2][2]) - (arr[0][2] * arr[2][1])); // 21
    array[1][1] = 1 * ((arr[0][0] * arr[2][2]) - (arr[0][2] * arr[2][0])); // c22
    array[1][2] = -1 * ((arr[0][0] * arr[2][1]) - (arr[0][1] * arr[2][0])); // c23

    array[2][0] = 1 * ((arr[0][1] * arr[1][2]) - (arr[0][2] * arr[1][1])); // c31
    array[2][1] = -1 * ((arr[0][0] * arr[1][2]) - (arr[1][0] * arr[0][2])); // c32
    array[2][2] = 1 * ((arr[0][0] * arr[1][1]) - (arr[1][0] * arr[0][1])); // c33

    return array;
}


int determinant(int arr[][COLS], int rows, int cols) {
    int modulus = 0;
    modulus = arr[0][0]*((arr[1][1]*arr[2][2]) - (arr[1][2]*arr[2][1])) -arr[0][1]*((arr[1][0]*arr[2][2]) - (arr[1][2]*arr[2][0]))+arr[0][2]*((arr[1][0]*arr[2][1])-(arr[1][1]*arr[2][0]));

    return modulus;
}

int main() {
    int myArray[ROWS][COLS];
    cout<<endl<<endl;
    cout<<"Enter a 3x3 matrix :"<<endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cin >> myArray[i][j];
        }
    }

    int modulus = determinant(myArray, ROWS, COLS);
    if(modulus==0){
        cout<<"System has no solution !!"<<endl;
    }
    
    
    cout<<endl;
    cout<<endl;

    cout<<"Modulus = "<<modulus<<endl;

    cout<<endl;


    //......Print C11 to C33..........

    cout<<"Value of c11-c33 :"<<endl<<endl;

    int** resultArray = funct(myArray, ROWS, COLS);

    

    int** arrPtr = new int*[ROWS];
    for (int i = 0; i < ROWS; ++i) {
        arrPtr[i] = resultArray[i];
    }


    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << resultArray[i][j] << "  ";
        }
        cout << endl;
    }

    cout<<endl;
    cout<<endl;


    //Making Transpose Matrix.......


    for (int i = 0; i < ROWS; i++) {
        for (int j = i + 1; j < COLS; j++) {

            int temp = resultArray[i][j];
            resultArray[i][j] = resultArray[j][i];
            resultArray[j][i] = temp;
        }
    }

    cout<<"Transpose Matrix is : "<<endl<<endl;
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            cout << resultArray[i][j] << "  ";
        }
        cout <<endl;
    }



    // Finally modulas and transpose multiply
    cout<<"Our inverse matrix is :"<<endl<<endl;
        for (int i = 0; i < COLS; i++) {
            for (int j = 0; j < ROWS; j++) {
            cout << resultArray[i][j] * modulus << "  ";
        }
        cout <<endl;
    }

    for (int i = 0; i < ROWS; i++) {
        delete[] resultArray[i];
    }
    delete[] resultArray;

        // .......Uporer tar........
    for (int i = 0; i < ROWS; i++) {
        delete[] resultArray[i];
    }
    delete[] resultArray;

    // .... Ager tar......
    for (int i = 0; i < ROWS; i++) {
        delete[] resultArray[i];
    }
    delete[] resultArray;

   
    return 0;
}
