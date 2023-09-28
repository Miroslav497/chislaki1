#include <iostream>
#include <iomanip>

using namespace std;

void Swap(int line1, int line2, double** a)
{
  double* tmp = a[line1];
  a[line1] = a[line2];
  a[line2] = tmp;
}



int main() {
  const int N = 3, M = 4;

  int rows = 3;
  int cols = 4;


  double** matrix = new double* [rows];



  matrix[0] = new double[cols] { 1.0, 2.0, 1.0, 1.0 };
  matrix[1] = new double[cols] {-1.0, -2.0, 2.0, 1.0};
  matrix[2] = new double[cols] {0, 1.0, 1.0, 2.0 };

  //out
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) 
        cout << setw(5) << matrix[i][j];
        cout << endl;
  }

  cout << endl << endl;

  int tmp;
  int i, j, k;
  for (i = 0; i < N; i++) {
    tmp = matrix[i][i];
    if (tmp != 0) {
      for (j = N; j >= i; j--)
        matrix[i][j] /= tmp;
    }
    else Swap(i, i+1, matrix);

    for (j = i + 1; j < N; j++) {
        tmp = matrix[j][i];
        for (k = N;k >= i;k--)
            matrix[j][k] -= tmp * matrix[i][k];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      cout << setw(5) << matrix[i][j];
    cout << endl;
  }
  delete[] matrix[0];
  delete[] matrix[1];
  delete[] matrix[2];
  delete[] matrix;
}