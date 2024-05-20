#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;
double f1(double x){
    return sin(x);
}
double f2(double x){
    return x*x + 2*x + 5;
}
double f3(double x){
    return exp(x);
}
double calkowanie(double f(double), double a, double b, int n){ 
    double Y = 0;
    double s = (b-a)/n;
    double F = a +s/2;

for(int i = 0; i < n; i++){
    //cout <<F+i*s<<endl;
    Y += f(F+i*s);
    }
    return Y*s;
}

double trapez(double f(double), double a, double b, int n){
    double s = (b-a)/n;
    double c = a;
    double d = c + s;
    double F = 0;
    for(int i = 0; i < n; i++){
        F += ((d-c)/2)*(f(c) + f(d));
        c = d;
        d = d + s;
    }
    return F;
}

double Simpsona(double f(double),double a, double b, int n){
    double s = (b-a)/n;
    double x = a;
    double t = a + s/2;
    double Y = 0;
    double y = 0;
    for(int i = 1; i < n + 1; i++){
        y += f(t);          
        t+=s;
        if(i < n)
            Y += f(x+i*s);            
    }
    double F = ((b-a)/(6*n))*(f(a) + f(b) + 2*Y + 4*y);
    return F;
}

int main(){
    int n;
    double a,b;
   
    //cout << "Liczba przedzialow" << n << endl;
    cout << "Metoda prostokatow wzor: sin(x)" << endl;
    cout <<"Obliczanie calki metoda prostokatow\n"<<calkowanie(f1,0.5,2.5,4)<<endl;
    cout << "Metoda trapezow wzor:x*x + 2*x + 5 "<< endl;
    cout << "Obliczanie calki metoda trapezow\n"<<trapez(f1,0.5,5,4)<<endl;
    cout << "Metoda Simpsona wzor: exp(x)" << endl;
    cout << "Obliczanie calki metoda Simpsona\n"<<Simpsona(f1,0.5,5,4);

   /*q/ ofstream myfile;
    myfile.open ("MN_lab_03_033.txt");
    for (int i=1;i<20;i++){
        myfile << calkowanie(f3,0.5,5,i) << "\t" << trapez(f3,0.5,5,i)<<"\t"<< Simpsona(f3,0.5,5,i)<<"\n";
    }
    myfile.close();*/
   
}
