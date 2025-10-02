#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    // Cek apakah queue kosong
    if(front == nullptr) {
        //jika kosong, front dan rear sama dengan newNode
        front = newNode;
        rear = newNode;
    } else {
        //jika tidak kosong, sambungkan rear->next ke newNode, lalu update rear
        rear->next = newNode;
        rear = newNode;
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong

    //simpan data dari front node
    Node* temp = front;
    string document = temp->document;

    //geser front ke front->next
    front = front->next;

    //jika front menjadi nullptr, set rear juga ke nullptr
    if(front == nullptr) {
        rear = nullptr;
    }
    //delete node lama dan return data
    delete temp;
    return document; // Placeholder
}

void processAllDocuments(Node*& front, Node*& rear) {

    //perualngan hingga queue kosong
    while(front != nullptr) {
        string document = dequeue(front, rear);
        cout << "Memproses: " << document << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}