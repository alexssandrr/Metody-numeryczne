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


double* Gauss(double **MS, int Msize)
{

    for (int i = 0; i < Msize; i++)
    {
        if (MS[i][i] == 0)
        {
            cout << "Zero na przekatnych" << endl;
        }
        for (int j = i + 1; j < Msize; j++)
        {
            double m = MS[j][i] / MS[i][i]; // obliczamy m
            for (int q = i; q < Msize + 1; q++)
            {
                MS[j][q] = MS[j][q] - m * MS[i][q];
            }
        }
    }


    double *x = new double[Msize];
    
    x[Msize-1] = MS[Msize-1][Msize]/MS[Msize-1][Msize-1];
    for (int i = Msize-2; i >= 0; i--)
    {
        double SUM = 0.0;
        for (int k = i+1; k < Msize; k++)
        {
            SUM += MS[i][k] * x[k];
        }
        x[i] = (MS[i][Msize] - SUM) / MS[i][i];
    }

    return x;
}

void aproksymacja(double**MS,int m,int n){      // n- wykładnik
    double w = 1;
    n++;
    double **g = new double*[n];        //n-rozmiar macierzy g
    //double *F = new double[n];        // g - połączona macierz g i wektor F
    for(int k = 0; k < n; k++){
        g[k] = new double[n+1];
        for(int j = 0; j < n; j ++){
            double F = 0;
            g[k][j]=0;
            for(int i = 0; i < m; i++){
                g[k][j] += pow(MS[i][0],k)*pow(MS[i][0],j)*w;
                F += pow(MS[i][0],k) * MS[i][1]*w;
            }
            g[k][n] = F;        // do ostatniej kolumny dopisuję wartość która jest w wektorze F
        }
    }
    ShowMatrixGraph(g,n);
    double *a = Gauss(g,n);
    
    
    cout << "Liczba wezlow: "<<m << endl;
    cout <<"Wspolczynniki wielomianu aproksymujacego: " << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << "\t";
    }
    cout << endl<<endl;
    //pkt aproksymowanie
    for (int p = 0; p < m; p++){
        double y = 0;
        for(int i = 0; i < n; i++)
            y += pow(MS[p][0],i)*a[i];
        cout << MS[p][0] <<" "<< MS[p][1] << "\t->   " << MS[p][0] << " " << y << endl;
    }
    
}    


int main()
{
    fstream matrix;
    matrix.open("MN-9.txt");
    int size;
    matrix >> size;
    cout << size << endl;

    double *B = new double [size];
    double **MS = new double *[size];

    for (int i = 0; i < size; i++)
    {
        MS[i] = new double[2];
    
        for (int j = 0; j < 2; j++){
            
            matrix >> MS[i][j];
        }
        
    }
    
    for(int i = 0;i<size;i++)
        cout<<MS[i][0] << " " << MS[i][1]<<endl;
    aproksymacja(MS,size,2);
    
}