#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

void ShowMatrixGraph(double **MS, int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size + 1; j++)
            cout << MS[i][j]  << " ";
        cout << endl;
    }
}


void Doolittle(double **MS, int n){
    
    double **U = new double *[n];
    double **L = new double *[n];
    double *B = new  double[n];
    double *Y = new double[n];
    double *X = new double[n];
    for(int i = 0; i<n;i++){
        U[i] = new double[n];
        L[i] = new double[n];
        for (int j=0;j<n;j++){
            U[i][j] = 0;
            L[i][j] = 0;
        }
    }
    
    
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            double SUM = 0;
            for (int k = 0; k< i;k++){
                SUM += L[i][k] * U[k][j];   
            }
            if (i<=j){
                if (i==j){
                    L[i][j] = 1;
                }
                U[i][j] = MS[i][j] - SUM;
                    
            }
            else{
                L[i][j] = (MS[i][j] - SUM)/U[j][j];
                    
            }
        }
        B[i] = MS[i][n];
    }
    cout << "Macierz U" << endl;
    ShowMatrixGraph(U, n);
    cout << "Macierz L" << endl;
    ShowMatrixGraph(L, n);
    
    Y[0] = B[0];
    cout << "Wektor Y" << endl;
    for(int i = 0; i < n; i++){
        double sum = 0;
        for(int j = 0; j < i; j++){
            sum += L[i][j]*Y[j];
        }
        Y[i] = B[i] - sum;
        cout << Y[i] << endl;
    }
    
    cout << endl;
    X[n-1] = Y[n-1]/U[n-1][n-1];
    
    for(int i = n - 2; i > -1 ; i --){
        double sum = 0;
        for( int j = i +1; j < n; j++){
           sum += U[i][j]*X[j];
        }
        X[i] = (Y[i] - sum)/U[i][i];
    
    }
    cout<<"Rozwiązanie"<< endl;
    for(int i = 0; i < n; i++){
        cout << X[i]<< endl;
    }
    
}


    
int main()
{
    fstream matrix;
    matrix.open("RURL_dane1.txt");
    int n;
    matrix >> n;
    cout << n << endl;

    double **MS = new double *[n];

    for (int i = 0; i < n; i++)
    {
        MS[i] = new double[n + 1];

        for (int j = 0; j < n + 1; j++)
            matrix >> MS[i][j];
    }
    cout << "Macierz przed obliczeniami" << endl;
    ShowMatrixGraph(MS, n);
  
    Doolittle(MS,n);
    
}
    


