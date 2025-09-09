//Array 2D

#include <iostream>
using namespace std;

int main(){
    int matriks[3][3] = {{ 10,20,30 },{40,50,60},{70,80,90}};

    int sumMainDiagonal = 0;
    int sumSecDiagonal = 0;

    for(int i=0; i<3; i++){
        sumMainDiagonal += matriks[i][i];
        sumSecDiagonal += matriks[i][2-i];
    }

    cout << "Matriks 3x3: " << endl;

    for (int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nJumlah diagonal utama: " << sumMainDiagonal << endl;
    cout << "Jumlah diagonal sekunder: " << sumSecDiagonal << endl;
}