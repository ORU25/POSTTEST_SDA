//Struct + Array
#include <iostream>
using namespace std;

struct Mahasiswa{
    string nama;
    string nim;
    float ipk;
};

int biggestIPK(Mahasiswa mhs[]){
    float biggestIPK = mhs[0].ipk;
    int index = 0;
    for (int i=1; i<5; i++){
        if (mhs[i].ipk > biggestIPK){
            biggestIPK = mhs[i].ipk;
            index = i;
        }
    }
    return index;
}

int main(){
    Mahasiswa mhs[5];

    for (int i=0; i<5; i++){
        cout << "Masukkan data mahasiswa ke-" << i+1 << endl;
        cout << "Nama: ";
        cin >> mhs[i].nama;
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "IPK: ";
        cin >> mhs[i].ipk;
        cout << endl;
    }

    cout <<"===================================="<<endl;
    cout << "Data Mahasiswa: " << endl;
    cout <<"===================================="<<endl;
    for (int i=0; i<5; i++){
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "IPK: " << mhs[i].ipk << endl;
        cout << endl;
    }
    cout <<"===================================="<<endl;

    cout << "\nMahasiswa dengan IPK terbesar: " << endl;
    int index = biggestIPK(mhs);
    cout << "Nama: " << mhs[index].nama << endl;
    cout << "NIM: " << mhs[index].nim << endl;
    cout << "IPK: " << mhs[index].ipk << endl;

    return 0;
}