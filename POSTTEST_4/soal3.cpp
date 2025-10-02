// ## SOAL 3

// Buat implementasi Queue manual menggunakan linked list untuk simulasi antrian printer yang memproses dokumen berdasarkan urutan kedatangan (FIFO).
// Struktur Data:

// ```c++
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};
// ```

// Lengkapi Fungsi berikut:

// ```c++
void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    // --- LENGKAPI DI SINI ---
    // 1. Jika queue kosong (front == nullptr), set front dan rear ke newNode
    // 2. Jika tidak kosong, sambungkan rear->next ke newNode, lalu update rear
    // --- LENGKAPI DI SINI ---

    if(front == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong

    // --- LENGKAPI DI SINI ---
    // 1. Simpan data dari front node
    // 2. Geser front ke front->next
    // 3. Jika front menjadi nullptr, set rear juga ke nullptr
    // 4. Delete node lama dan return data
    // --- LENGKAPI DI SINI ---
    Node* temp = front;
    string document = temp->document;
    front = front->next;
    if(front == nullptr) {
        rear = nullptr;
    }
    delete temp;

    return document; // Placeholder
}

void processAllDocuments(Node*& front, Node*& rear) {
    // --- LENGKAPI DI SINI ---
    // Loop hingga queue kosong, dequeue dan print setiap dokumen
    // Format: "Memproses: [nama_dokumen]"
    // --- LENGKAPI DI SINI ---
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
// ```

// Hanya Info:

// Queue menggunakan prinsip FIFO (First-In, First-Out). Dokumen yang pertama masuk antrian akan diproses pertama kali. Pointer front menunjuk ke elemen yang akan dikeluarkan, dan rear menunjuk ke posisi untuk elemen baru.

// Output:

// ```c++
// Memulai pemrosesan antrian printer:
// Memproses: Document1.pdf
// Memproses: Report.docx
// Memproses: Presentation.pptx
// ```

// ---