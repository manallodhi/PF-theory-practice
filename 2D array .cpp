#include <iostream>
using namespace std;

int main()
{
  int row1 , column1 ;
  cout << "Input Rows and Columns of first matrix : " << endl ;
  cin >> row1 >> column1 ;
  int row2 , column2 ;
  cout << "Input Rows and Columns of second matrix : " << endl ;
  cin >> row2 >> column2 ;
  int matrix_1[row1][column1] ;
  cout << "Input elements in the first matrix : " << endl ;
  for (int i = 0 ; i < row1 ; i++){
    for (int j = 0 ; j < column1 ; j++){
        cout << "element-[" << i << "][" << j << "] = " ;
        cin >> matrix_1[i][j] ;
    }
  }
  int matrix_2[row2][column2] ;
  cout << "Input elements in the second matrix : " << endl ;
  for (int i = 0 ; i < row2 ; i++){
    for (int j = 0 ; j < column2 ; j++){
        cout << "element-[" << i << "][" << j << "] = " ;
        cin >> matrix_2[i][j] ;
      }
  }
  cout << "First matrix : " << endl ;
  for (int i = 0 ; i < row1 ; i++){
    for (int j = 0 ; j < column1 ; j++){
        cout << matrix_1[i][j] ;
    }
    cout << endl ;
  }
  cout << "Second matrix : " << endl ;
  for (int i = 0 ; i < row2 ; i++){
    for (int j = 0 ; j < column2 ; j++){
        cout << matrix_2[i][j] ;
      }
      cout << endl ;
  }
  return 0;
}
