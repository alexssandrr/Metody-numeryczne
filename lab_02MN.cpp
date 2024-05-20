#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

/*double NewtonInterpolation(double X, int x[], int y[], int n ){
    double w = 0; 
// OBLICZANIE P
    for(int k = 0; k < n; k++){             
        double p = 1;
        for(int i = 0; i < k; i++){
            p *= (X - x[i]);
        };
        double b = 0;
        for(int i = 0; i < k+1; i++){           
            double X1 = 1;
            for(int j = 0; j < k+1; j++){
                if(i!= j){
                X1 = X1*(x[i] - x[j]);
                }
            }
            b +=y[i]/X1; 
        }
        cout <<"Polynomial coefficients"<<" "<<round(b*100)/100 <<endl;
        w += b*p;
    }
   
    return w;
}
*/

int main(){
    ifstream plik;
    plik.open("MN-2-p2.txt");
    int size;
    plik >> size;
    int x[size];
    int y[size];
    for(int i = 0; i < size; i++){
        plik >> x[i] >> y[i];
        cout <<"x:" <<x[i] << " y: "<<y[i]<<endl;
    }
    plik.close();
    /*cout << "The numbers of nodes" << " " << size << endl;
    cout<<"Give an interpolation point"<<endl;
    double point;
    cin>> point;
    cout << "Point where we count interpolation"<< " "<< point << endl;
    cout<<"Interpolation "<< NewtonInterpolation(point, x, y, size)<<endl;*/
}