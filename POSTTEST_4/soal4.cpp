#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    // Kasus 1: List masih kosong
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }


    //jika data lebih kecil dari head, sisipkan di awal
    if(data < head_ref->data) {
        Node* temp = head_ref;
        newNode->next = head_ref;
        newNode->prev = head_ref->prev;
        head_ref->prev->next = newNode;
        head_ref->prev = newNode;
        head_ref = newNode;
        return;
    }

    //simpan posisi saat ini
    Node* current = head_ref;
    // cari posisi yang tepat untuk sisipan
    while(current->next != head_ref && current->next->data < data) {
        current = current->next;
    }
    
    // sisipkan node baru setelah current
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;

}

void printList(Node *head_ref)
{
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main()
{
    Node *head = nullptr;

    // Test sorted insert
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    // Expected output: 10 20 30 40
    printList(head);

    return 0;
}