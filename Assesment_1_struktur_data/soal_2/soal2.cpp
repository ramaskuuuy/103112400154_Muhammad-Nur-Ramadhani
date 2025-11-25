#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;


void insertLast(int x) {
    Node* p = new Node;
    p->data = x;
    p->prev = nullptr;
    p->next = nullptr;

    if (head == nullptr) {  
        head = tail = p;
    } else {
        tail->next = p;
        p->prev = tail;
        tail = p;
    }
}

void deleteLast() {
    if (head == nullptr) {
        cout << "List kosong.\n";
        return;
    }

    if (head == tail) { 
        delete head;
        head = tail = nullptr;
    } else {
        Node* del = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete del;
    }
}


void viewForward() {
    if (head == nullptr) {
        cout << "List kosong.\n";
        return;
    }

    Node* p = head;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


void reverseList() {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
       
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

       
        current = current->prev;
    }

    
    if (temp != nullptr) {
        head = temp->prev;
    }
}


int main() {
    int pilihan, nilai;

    do {
        cout << "Menu: 1. Insert (end) , 2. Delete (last), 3.View depan, 4. Reverse & view depa, 0. exit\n";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan nilai: ";
            cin >> nilai;
            insertLast(nilai);
            break;

        case 2:
            deleteLast();
            break;

        case 3:
            viewForward();
            break;

        case 4:
            reverseList();
            cout << "List setelah di-reverse: ";
            viewForward();
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}
