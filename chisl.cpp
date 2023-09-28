#include <iostream>
#include <iomanip>

using namespace std;

void Swap(int line1, int line2, double** a)
{
  double* tmp = a[line1];
  a[line1] = a[line2];
  a[line2] = tmp;
}
void print(double** matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++){cout << setw(5) << matrix[i][j];}
       cout << endl;
  }
}

void otvet(double** matrix, int N, int M, double *F){
    F[N-1] = matrix[N-1][M-1];
    for(int i = N-2; i>-1;i--){
        double sum = 0;
        for(int k=i+1; k<N; k++){
            sum += matrix[i][k] * F[k];
        }
        F[i] = matrix[i][N] - sum;
    }
    
    for (int i = 0; i < N; i++){
        cout << "x" << i+1 << ": " << F[i] << endl;
    }
}

int main() {
  const int N = 3, M = 4;

  int rows = 3;
  int cols = 4;


  double** matrix = new double* [rows];



  matrix[0] = new double[cols] { 1.0, 2.0, 1.0, 1.0 };
  matrix[1] = new double[cols] {-1.0, -2.0, 2.0, 1.0};
  matrix[2] = new double[cols] {0, 1.0, 1.0, 2.0 };

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) 
        cout << setw(5) << matrix[i][j];
        cout << endl;
  }

  cout << endl << endl;

  for (int i = 0; i < N-1; i++) {
        double tmp = 0;
        if (matrix[i][i] == 0) {
            for (int j = i + 1; j < N; j++) {
                if (matrix[j][i] != 0) {
                    Swap(i, j, matrix);
                    break;
                    
                }
            }
        }
        
        for (int k = i + 1; k < N; k++) {
            tmp = matrix[k][i] / matrix[i][i];
            for (int j = i; j < M; j++) {
                matrix[k][j] = matrix[k][j] - matrix[i][j] * tmp;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        double dE = matrix[i][i];
        for (int j = i; j < M; j++) {
            matrix[i][j] /= dE;
        }
        
  }
  print(matrix, N, M);

  double  *F = new double[N];
  otvet(matrix,N,M,F);
  delete [] F;
  
  delete[] matrix[0];
  delete[] matrix[1];
  delete[] matrix[2];
  delete[] matrix;
}