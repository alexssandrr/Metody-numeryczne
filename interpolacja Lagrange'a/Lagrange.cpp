#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

double interpolation(double X, int x[],int y[],int n ){
    double L = 0;
    for(int i = 0; i < n; i++){
        double l=1;
        for(int j = 0; j < n; j++){
            if(i!=j){
                //cout << i << " " << j << endl;
                l = l *(X-x[j])/(x[i]-x[j]);
            } 
        }
    L += l*y[i];
    }
    return L;
}


int main(){
    ifstream plik;
    plik.open("interpolation.txt");
    int size;
    plik >> size;
    int x[size];
    int y[size];
    for(int i = 0; i < size; i++){
        plik >> x[i] >> y[i];
        cout <<"x:" <<x[i] << " y: "<<y[i]<<endl;
    }
    plik.close();
    cout << "The numbers of nodes" << " " << size << endl;
    cout<<"Give an interpolation point"<<endl;
    double point;
    cin>> point;
    cout<<"Interpolation "<< interpolation(point, x, y, size)<<endl;


    plik.open("wielomian.txt");
    int size1;
    plik >> size1;
    int x2[size1];
    int y2[size1];
    for(int i = 0; i < size1; i++){
        plik >> x2[i] >> y2[i];
        cout <<"x:" <<x2[i] << " y: "<<y2[i]<<endl;
    }
    plik.close();

    point = 50;
    cout << "The numbers of nodes" << " " << size1 << endl;
    cout << "The interpolation node" << " " << point << endl;
    cout<<"Interpolation "<< interpolation(point, x2, y2, size1);
    
    return 0;
}