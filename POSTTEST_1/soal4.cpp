// Pointer dan fungsi

#include <iostream>
using namespace std;

void swap(int **a, int **b){
    int temp = **a;
    **a = **b;
    **b = temp;
    cout << "\nNilai setelah ditukar: " << endl;
        cout << "Alamat a: "<< &**a << " | Nilai: " << **a << endl;
    cout << "Alamat b: "<< &**b << " | Nilai: "<< **b << endl;
}

int main(){
    int a, b;
    int* pa = &a;
    int* pb = &b;
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;

    cout << "\nNilai sebelum ditukar: " << endl;
    cout << "Alamat a: "<< &a << " | Nilai: " << a << endl;
    cout << "Alamat b: "<< &b << " | Nilai: "<< b << endl;

    swap(&pa, &pb);

    return 0;
}