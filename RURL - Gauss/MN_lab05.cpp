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
            cout << MS[i][j]<< " ";
        cout << endl;
    }
}

void Gauss(double **MS, int Msize)
{

    for (int i = 0; i < Msize ; i++)
    {
        if (MS[i][i] == 0)
        {
            cout << "Zero na przekatnych" << endl;
        }
        for (int j = i + 1; j < Msize; j++)
        {
            double m = MS[j][i] / MS[i][i];                 // obliczamy mnożnik
            for (int q = i; q < Msize + 1; q++)
            {
                MS[j][q] = MS[j][q] - m * MS[i][q];
            }
        }
    }
    ShowMatrixGraph(MS, Msize);

    double *x;
    
    for (int i = Msize - 1; i >= 0; i--)
    {
        int b = 0;
        for (int k = i + 1; k < Msize ; k++)
        {
            b += MS[i][k] * x[k];
        }
        x[i] = (MS[i][Msize] - b) / MS[i][i];           
    }
      
     
    cout << "\nRozwiazanie ukladu rownan" << endl;

    for (int i = 0; i < Msize; i++)
    {
        cout << "x" << i << "=" << x[i] << endl;
        
       
    }
}

int main()
{
    fstream matrix;
    matrix.open("RURL_dane2.txt");
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

    Gauss(MS, Msize);
}