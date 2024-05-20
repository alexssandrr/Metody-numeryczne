#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

double calkowanie(double f(double), double a, double b, int n, double x[], double A[]){ 
    double  Y = 0;
    for(int i = 0; i < n; i++){
        double t = (a + b)/2 + (b - a)/2 * x[i];
        Y += A[i]*f(t);
    }
    return ((b - a)/2) *Y;
} 
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
    double x1[] = {(-sqrt(3)/3), sqrt(3)/3};
    double A1[] = {1.0,1.0};
    double x2[] = {(-sqrt(3.0/5.0)), 0, sqrt(3.0/5.0)};
    double A2[] = {(5.0/9.0),(8.0/9.0), (5.0/9.0)};
    double x3[] = {-(sqrt(525+70*sqrt(30))/35), -(sqrt(525-70*sqrt(30))/35), (sqrt(525-70*sqrt(30))/35), (sqrt(525+70*sqrt(30))/35)};
    double A3[] = {(18-sqrt(30))/36,(18+sqrt(30))/36, (18+sqrt(30))/36, (18-sqrt(30))/36 };
    
    cout << "Kwadratura 2-wezlowa" << endl;
    cout << calkowanie(f1, 0.5, 2.5, 2,x1, A1) <<endl;
    cout << "Kwadratura 3-wezlowa" << endl;
    cout << calkowanie(f1, 0.5, 2.5, 3 ,x2, A2)<<endl;
    cout << "Kwadratura 4-wezlowa" << endl;
    cout << calkowanie(f1, 0.5, 2.5, 4 ,x3, A3)<<endl;

    cout << "Metoda prostokatow wzor: sin(x)" << endl;
    cout <<"Obliczanie calki metoda prostokatow\n"<<calkowanie(f1,0.5,2.5,20)<<endl;
    cout << "Metoda trapezow wzor:x*x + 2*x + 5 "<< endl;
    cout << "Obliczanie calki metoda trapezow\n"<<trapez(f1,0.5,2.5,20)<<endl;
    cout << "Metoda Simpsona wzor: exp(x)" << endl;
    cout << "Obliczanie calki metoda Simpsona\n"<<Simpsona(f1,0.5,2.5,20);


}