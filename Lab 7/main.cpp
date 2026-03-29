#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SIZE = 4;
// matrix class, in order to follow oop 
class Matrix {
private:
    int data[SIZE][SIZE];

public:
    void readFromFile(ifstream& file) { //reading from file, which is expected to be a matrix
        // Provided by template
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                file >> data[i][j];
            }
        }
    }

    void display() const { //used to display the matrix, gonig through each line, assinging cout
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < SIZE; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    // summing the diagonals function 
    int sumDiagonals() const {
        int sum = 0;
        for (int i = 0; i < SIZE; ++i) {
            sum += data[i][i];
            sum += data[i][SIZE - 1 - i];
        }
        return sum;
    }
    // swapping rows function
    void swapRows(int r1, int r2) {
        if (r1 >= 0 && r1 < SIZE && r2 >= 0 && r2 < SIZE) {
            for (int j = 0; j < SIZE; ++j) {
                int temp = data[r1][j];
                data[r1][j] = data[r2][j];
                data[r2][j] = temp;
            }
        }
    }
};

int main() {
    // Provided by template
    string filePath = "matrix_data.txt";
    ifstream file(filePath);

    // Provided by template
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filePath << endl;
        return 1;
    }
    // making two matrices using matrix, creating m1 and m2 here
    Matrix m1, m2;
    m1.readFromFile(file); //reading through using readfromfile operation
    m2.readFromFile(file);

    cout << "Matrix 1:" << endl; 
    m1.display(); //displaying the output for both after assignment and reading
    cout << "Matrix 2:" << endl;
    m2.display();

    cout << "Addition:" << endl; //
    (m1 + m2).display(); //displaying the addition result 

    cout << "Multiplication:" << endl;
    (m1 * m2).display(); //displaying the result of multiplication between the two matrices

    cout << "Diagonal Sum: " << m1.sumDiagonals() << endl;

    m1.swapRows(0, 2); //swapping rows 0 and 2
    cout << "After Swapping Rows 0 and 2:" << endl; //telling the user we did that
    m1.display(); //displaying the result of the swap

    file.close(); // Provided by template
    return 0; //ending the program after all of this has been done
}