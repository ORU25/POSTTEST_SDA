#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};


// Anda bisa menggunakan fungsi push dan pop dari soal sebelumnya.
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0'; // Return null character jika stack kosong
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    // loop setiap karakter dalam string expr
    for(int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        // cek apakah karakter adalah kurung buka atau tutup
        if(c == '(' || c == '{' || c == '[') {
            //jika kurung buka, push ke stack
            push(stackTop, c);
        } else if(c == ')' || c == '}' || c == ']') {
            // jika kurung tutup, cek apakah stack kosong
            if(stackTop == nullptr) {
                return false;
            }
            // pop stack dan cek apakah kurung tutup cocok dengan kurung buka
            char topChar = pop(stackTop);
            if((c == ')' && topChar != '(') ||
               (c == '}' && topChar != '{') ||
               (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    
    // setelah loop selesai, cek apakah stack kosong
    if(stackTop == nullptr) {
        return true;
    }


    return false; // Placeholder
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    // Expected output: Seimbang
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}
