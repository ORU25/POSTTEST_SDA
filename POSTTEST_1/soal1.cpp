//Array + Pointer

#include <iostream>
using namespace std;

void referse(int* arr){
    int *awal = arr;
    int *akhir = arr + 6;
    
    while (awal < akhir){
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal ++;
        akhir --;
    }
}

int main(){
    int arr[7];

    for(int i=1; i<8; i++){
        arr[i-1] = 3*i;
    }

    cout << "Sebelum diubah: " << endl;
    for(int i=0; i<7; i++){
        cout  << "arr[" << i << "] ";
        cout << &arr[i] << "\t";
        cout << arr[i] << "\t" << endl;
    }

    referse(arr);

    cout << "\nSetelah diubah: " << endl;
    for(int i=0; i<7; i++){
        cout  << "arr[" << i << "] ";
        cout << &arr[i] << "\t";
        cout << arr[i] << "\t" << endl;
    }


    return 0;
}