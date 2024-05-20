#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

void ShowMatrixGraph(double **MS, int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {        for (int j = 0; j < 2 ; j++)
            cout << MS[i][j]  << " ";
        cout << endl;
    }
}

double Newton(double n, double k){
    double silniaN = 1;
    double silniaK = 1;
    double silniaNK = 1;
    for(int i = 1; i <= n; i++){
        silniaN = silniaN*i;
    }
    for(int j = 1; j <= k; j++){
        silniaK = silniaK*(j);
    }
    for(int i = 1; i <= n - k; i++){
        silniaNK = silniaNK*i;
    }
    return silniaN/(silniaK*silniaNK);
}

double wielomianCzynnikowy(double x,double n){
    if (n == 0)
        return 1;
    double SUM = 1;
    for(int j = 0; j < n; j++){
        SUM *= (x - j);
    }
    return SUM;
}

double wielomianyGram(double k, double q, double n){
    if(q == 0)
        return 1;
    double SUMA = 0;
    for(int s = 0; s <= k; s++){
        SUMA += pow((-1),s)*Newton(k,s)*Newton(k+s, s)*(wielomianCzynnikowy(q,s)/wielomianCzynnikowy(n,s));
    }
    return SUMA;
}

double Gram(double **MS, double m, double x, int n){
    double SUM = 0;
    double q = (x - MS[0][0])/(MS[1][0] - MS[0][0]);
    for(int k = 0; k < m + 1; k++){
        double c = 0;
        double s = 0;
        for(int i = 0; i < n+1; i++){
            c += pow(wielomianyGram(k,i,n), 2);
            s += MS[i][1]*wielomianyGram(k,i,n);
        }
        SUM += (s/c)*wielomianyGram(k,q,n);
    }
    return SUM; 
}

void Gram_c_s(double **MS, double m, double x, int n){
    double SUM = 0;
    double q = (x - MS[0][0])/(MS[1][0] - MS[0][0]);
    for(int k = 0; k < m + 1; k++){
        double c = 0;
        double s = 0;
        for(int i = 0; i < n+1; i++){
            c += pow(wielomianyGram(k,i,n), 2);
            s += MS[i][1]*wielomianyGram(k,i,n);
        }
        cout << "Współczynnik c\t" << c << "\tWspółczynnik s\t"<< s <<endl;
    }
}


int main(){
    
    fstream matrix;
    matrix.open("points.txt");
    int Msize;
    matrix >> Msize;
    cout << Msize << endl;

    double **MS = new double *[Msize];

    for (int i = 0; i < Msize; i++)
    {
        MS[i] = new double[2];

        for (int j = 0; j < 2; j++)
            matrix >> MS[i][j];
    }
    cout << "Macierz przed obliczeniami" << endl;
    ShowMatrixGraph(MS, Msize);

    cout << endl;
    matrix.close();
    
    cout << "Liczba węzłów\t" << Msize << endl;
    Gram_c_s(MS, 2, 1, Msize-1);
    cout << "\nWartości aproksymowanej funkcji" << endl;
    for (int i = 0; i < Msize;i++){
        cout << MS[i][0] << " " << MS[i][1] << "\t=>\t" << MS[i][0] << " " << Gram(MS, 2, MS[i][0], Msize-1)<<endl;
    }
    cout << "Wartości aproksymowanej funkcji dla pkt 2.5" << endl;
    cout << Gram(MS, 2, 2.5, Msize-1)<<endl;
    cout << "Wartości aproksymowanej funkcji dla pkt 6.5" << endl;
    cout << Gram(MS, 2, 6.5, Msize-1)<<endl;

}