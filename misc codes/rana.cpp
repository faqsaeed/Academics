#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void inputMatrix(int** matrix, const int& rows, const int& cols) 
{
    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++) 
        {
            cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void autoinputMatrix(int** matrix, const int& rows, const int& cols) 
{
    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++) 
        {
            matrix[i][j] = rand()%100;
        }
    }
}

void printMatrix(int** matrix, const int& rows, const int& cols) 
{
    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int** addMatrices(int** A, int** B, const int& rows, const int& cols) 
{
    int** result = new int*[rows];

    for(int i = 0; i < rows; i++)
    {
        result[i] = new int[cols];
    }

    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++) 
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

int** subtractMatrices(int** A, int** B, const int& rows, const int& cols) 
{
    srand(time(0));
    int** result = new int*[rows];

    for(int i = 0; i < rows; i++)
    {
        result[i] = new int[cols];
    }

    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++) 
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

int** multiplyMatrices(int** A, int** B, const int& rowsA, const int& colsA, const int& rowsB, const int& colsB) 
{
    int** result = new int*[rowsA];

    for(int i = 0; i < rowsA; i++)
        result[i] = new int[colsB];

    for(int i = 0; i < rowsA; i++) 
    {
        for(int j = 0; j < colsB; j++) 
        {
            result[i][j] = 0;
            for(int k = 0; k < colsA; k++) 
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

int** transposeMatrix(int** matrix, int& rows, int& cols) 
{
    int** result = new int*[cols];
    for(int i = 0; i < cols; i++)
    {
        result[i] = new int[rows];
    }

    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++) 
        {
            result[j][i] = matrix[i][j];
        }
    }
    swap(rows, cols);
    return result;
}


void freeMatrix(int**& matrix, const int rows) 
{
    for(int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}

int main() 
{
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter rows and columns for matrix A: ";
    cin >> rowsA >> colsA;


    int** A = new int*[rowsA];
    for(int i = 0; i < rowsA; i++)
    {
        A[i] = new int[colsA];
    }

    cout << "Enter elements of matrix A:\n";
    inputMatrix(A, rowsA, colsA);

    cout << "Enter rows and columns for matrix B: ";
    cin >> rowsB >> colsB;

//  system("cls") // for windows ewww ;)
    system("clear");//for LINUX

    int** B = new int*[rowsB];
    for(int i = 0; i < rowsB; i++)
    {
        B[i] = new int[colsB];
    }

    cout << "Enter elements of matrix B:\n";
    inputMatrix(B, rowsB, colsB);

    int choice;
//  system("cls") // for windows ewww ;)
    system("clear");//for LINUX
    do{
        cout << "\nChoose an operation: \n1. Add\n2. Subtract\n3. Multiply\n4. Transpose A\n5. Transpose B\n";
        cin >> choice;
    
        //  system("cls") // for windows ewww ;)
        system("clear");  //for LINUX

        

        if(choice == 1)
        {
            if(rowsA == rowsB && colsA == colsB) 
            {
                int** sum = addMatrices(A, B, rowsA, colsA);

                cout << "\nResult of Addition:\n";
                printMatrix(sum, rowsA, colsA);
                freeMatrix(sum, rowsA);
            } 
            else 
            {
                cout << "Matrix dimensions do not match for addition!\n";
            }
        }
        
        else if(choice == 2)
        {
            if(rowsA == rowsB && colsA == colsB) 
            {
                int** difference = subtractMatrices(A, B, rowsA, colsA);

                cout << "\nResult of Subtraction:\n";
                printMatrix(difference, rowsA, colsA);
                freeMatrix(difference, rowsA);
            }   
            else 
            {
                cout << "Matrix dimensions do not match for subtraction!\n";
            }
        }

        else if(choice == 3)
        {
            if(colsA == rowsB) 
            {
                int** product = multiplyMatrices(A, B, rowsA, colsA, rowsB, colsB);

                cout << "\nResult of Multiplication:\n";
                printMatrix(product, rowsA, colsB);
                freeMatrix(product, rowsA);
            }   
            else 
            {
                cout << "Matrix dimensions do not match for multiplication!\n";
            }
        }

        else if(choice == 4)
        {
            int** transposeA = transposeMatrix(A, rowsA, colsA);

            cout << "\nTranspose of Matrix A:\n";
            printMatrix(transposeA, colsA, rowsA);
            freeMatrix(transposeA, colsA);
                
        }
        else if(choice == 5)
        {
                
            int** transposeB = transposeMatrix(B, rowsB, colsB);

            cout << "\nTranspose of Matrix B:\n";
            printMatrix(transposeB, colsB, rowsB);
            freeMatrix(transposeB, colsB);
        }
        else
        {
            cout << "Invalid choice!\n";
        }   
    }while(choice > 0 && choice < 6);

    // Free allocated memory
    freeMatrix(A, rowsA);
    freeMatrix(B, rowsB);

    return 0;
}

