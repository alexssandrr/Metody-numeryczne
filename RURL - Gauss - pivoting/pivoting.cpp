#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

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

void GaussCrout(double **MS, int Msize)
{
    int *vector = new int [Msize];
    for(int v = 0; v < Msize; v++){
        vector[v] = v;
    }
    for (int i = 0; i < Msize; i++)
        {
            double max = abs(MS[i][i]);
            int kolumna = i;
            for(int z = i + 1; z < Msize; z++){
                if(abs(MS[i][z]) > max){
                    max = abs(MS[i][z]);
                    kolumna = z;
                }
            }
            if(i != kolumna){
                for(int p = 0; p < Msize; p++){
                    double temp = MS[p][i];
                    MS[p][i] = MS[p][kolumna];
                    MS[p][kolumna] = temp;
                    
                }
                int t = vector[i];
                vector[i] = vector[kolumna];
                vector[kolumna] = t;
            }

            ShowMatrixGraph(MS, Msize);
            
            
            for (int j = i + 1; j < Msize; j++)
            {
                double m = MS[j][i] / MS[i][i]; // obliczamy m
                for (int q = i; q < Msize + 1; q++)
                {
                    MS[j][q] = MS[j][q] - m * MS[i][q];
                }
            }
        }

    ShowMatrixGraph(MS, Msize);

    double *x;
    
    x[Msize-1] = MS[Msize-1][Msize]/MS[Msize-1][Msize-1];
    for (int i = Msize-2; i >= 0; i--)
    {
        cout << "i"<< i <<endl;
        double SUM = 0.0;
        for (int k = i+1; k < Msize; k++)
        {
            SUM += MS[i][k] * x[k];
        }
        x[i] = (MS[i][Msize] - SUM) / MS[i][i];
    }

    cout << "\nRozwiazanie ukladu rownan" << endl;
    for (int i = 0; i < Msize; i++)
        cout << vector[i] << " ";
    cout << endl;
    for (int i = 0; i < Msize; i++)
    {
        cout << "x" << i << "=" << x[vector[Msize-i-1]] << endl;
        // cout << x[0] - x[i] << endl;
    }
}



void partialPivotingGauss(double **MS, int Msize)
{
        for (int i = 0; i < Msize; i++)
        {
            double max = abs(MS[i][i]);
            int wiersz = i;
            for(int z = i + 1; z < Msize; z++){
                if(abs(MS[z][i]) > max){
                    max = abs(MS[z][i]);
                    wiersz = z;
                }
            }
            if(i != wiersz){
                for(int p = 0; p < Msize + 1; p++){
                    double temp = MS[i][p];
                    MS[i][p] = MS[wiersz][p];
                    MS[wiersz][p] = temp;
                }
            }

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

    ShowMatrixGraph(MS, Msize);

    double *x;
    
    x[Msize-1] = MS[Msize-1][Msize]/MS[Msize-1][Msize-1];
    for (int i = Msize-2; i >= 0; i--)
    {
        cout << "i"<< i <<endl;
        double SUM = 0.0;
        for (int k = i+1; k < Msize; k++)
        {
            SUM += MS[i][k] * x[k];
        }
        x[i] = (MS[i][Msize] - SUM) / MS[i][i];
    }

    cout << "\nRozwiazanie ukladu rownan" << endl;

    for (int i = 0; i < Msize; i++)
    {
        cout << "x" << i << "=" << x[i] << endl;
        // cout << x[0] - x[i] << endl;
    }
}

int main()
{
    fstream matrix;
    matrix.open("MN-6-2.txt");
    int Msize;
    matrix >> Msize;
    cout << Msize << endl;

    double **MS = new double *[Msize];

    for (int i = 0; i < Msize; i++)
    {
        MS[i] = new double[Msize + 1];

        for (int j = 0; j < Msize + 1; j++)
            matrix >> MS[i][j];
    }
    cout << "Macierz przed obliczeniami" << endl;
    ShowMatrixGraph(MS, Msize);

    cout << endl;
    matrix.close();

    cout << "Macierz po pierwszym etapie obliczen" << endl;

    ShowMatrixGraph(MS, Msize);

    GaussCrout(MS,Msize);
   // partialPivotingGauss(MS, Msize);
}