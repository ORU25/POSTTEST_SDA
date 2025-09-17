#include <iostream>

using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string type;
};

struct Node {
    Item item;
    Node* next;
};

void addItem(Node *&head, Node *&tail, string namaItem, int jumlah, string type){
    if (head == nullptr && tail == nullptr) {
        Node* newNode = new Node;
        newNode->item.namaItem = namaItem;
        newNode->item.jumlah = jumlah;
        newNode->item.type = type;
        newNode->next = nullptr;
        head = newNode;
        tail = newNode;
    }else{
        Node* newNode = new Node;
        newNode->item.namaItem = namaItem;
        newNode->item.jumlah = jumlah;
        newNode->item.type = type;
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }
};

void addSpesific(Node *&head, Node *&tail, string namaItem, int jumlah, string type){
    int posisi = 5+1;
    int mulai = 1;
    if(head == nullptr && tail == nullptr){
        cout << "Inventory kosong, menambahkan item sebagai item pertama." << endl;
        addItem(head, tail, namaItem, jumlah, type);
        return;
    }
    Node *temp = head;
    while(temp != nullptr && mulai < posisi -1){
        temp = temp->next;
        mulai++;
    }
    if(temp == nullptr){
        cout << "Posisi 5+1 melebihi panjang inventory, menambahkan item di akhir." << endl;
        addItem(head, tail, namaItem, jumlah, type);
    }else if(temp->next == nullptr){
        addItem(head, tail, namaItem, jumlah, type);
    }else {
        Node* newNode = new Node;
        newNode->item.namaItem = namaItem;
        newNode->item.jumlah = jumlah;
        newNode->item.type = type;
        newNode->next = temp->next;
        temp->next = newNode;
    }
};

void deleteLast(Node *&head, Node *&tail){
    Node* temp = head;
    if(head == nullptr){
          cout << "Inventory kosong, tidak ada yang dihapus" << endl;
          return;
    }

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    
    while(temp->next != tail){
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = nullptr;
    
};

void useItem(Node *&head, Node *&tail, string namaItem){
    if(head == nullptr){
        cout << "Inventory kosong, tidak ada item yang bisa digunakan." << endl;
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp->item.namaItem != namaItem){
        prev = temp;
        temp = temp->next;
        if(temp == nullptr){
            cout << "Item tidak ditemukan dalam inventory." << endl;
            return;
        }
    }

    if(temp->item.jumlah > 0){
        temp->item.jumlah--;
        cout << "Item " << namaItem << " telah digunakan. Sisa jumlah: " << temp->item.jumlah << endl;
        if(temp->item.jumlah == 0){
            cout << "Item " << namaItem << " telah habis dan dihapus dari inventory." << endl;
            if(prev == nullptr){
                head = head->next;
                delete temp;
                if(head == nullptr){
                    tail = nullptr;
                }
            }else{
                prev->next = temp->next;
                if(temp == tail){
                    tail = prev;
                }
                delete temp;
            }
        }
        
    }else{
        cout << "Item " << namaItem << "tidak ditemukan atau telah habis." << endl;
    }
};

void showInventory(Node* head, Node* tail){
    if(head == nullptr){
        cout << "Inventory kosong." << endl;
        return;
    }
    Node* temp = head;
    int index = 1;
    cout << "\nDaftar Item dalam Inventory:\n";
    while(temp != nullptr){
        cout << index << ". Nama Item: " << temp->item.namaItem << endl;
        cout << "   Jumlah: " << temp->item.jumlah << endl;
        cout << "   Tipe: " << temp->item.type << endl;
        cout << "------------------" << endl;
        temp = temp->next;
        index++;
    }
};

int main(){
    Node *head = nullptr;
    Node *tail = nullptr;

    
    string nama;
    string nim;
    
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);
    
    int jumlah = nim.back() - '0';
    
    int pilihan = -1;
    
    while(pilihan != 0){
        string namaItem, type;

        cout << "\n+---------------------------------------------------+\n";
        cout << "GAME INVENTORY MANAGEMENT\n";
        cout << nama << " - " << nim << "\n";
        cout << "+---------------------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                               |\n";
        cout << "| 2. Sisipkan Item                                  |\n";
        cout << "| 3. Hapus Item Terakhir                            |\n";
        cout << "| 4. Gunakan Item                                   |\n";
        cout << "| 5. Tampilkan Inventory                            |\n";
        cout << "| 0. Keluar                                         |\n";
        cout << "+---------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        cin.ignore();

        switch(pilihan) {
            case 1:
                cout << "Masukkan nama item: ";
                getline(cin, namaItem);
                cout << "Masukkan jumlah item: " << jumlah << endl;
                cout << "Masukkan tipe item (Consumable/Equipment/Misc): ";
                getline(cin, type);
                addItem(head, tail, namaItem, jumlah, type);
                break;
            case 2:
                cout << "Masukkan nama item: ";
                getline(cin, namaItem);
                cout << "Jumlah item: " << jumlah << endl;
                cout << "Masukkan tipe item (Consumable/Equipment/Misc): ";
                getline(cin, type);
                addSpesific(head, tail, namaItem, jumlah, type);
                break;
            case 3:
                deleteLast(head, tail);
                cout << "Item terakhir telah dihapus dari inventory." << endl;
                break;
            case 4:
                cout << "Masukkan nama item yang ingin digunakan: ";
                getline(cin, namaItem);

                useItem(head, tail, namaItem);
                break;
            case 5:
                showInventory(head, tail);
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }
    }
    return 0;
}