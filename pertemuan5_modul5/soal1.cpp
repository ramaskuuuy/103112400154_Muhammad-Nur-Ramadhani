#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; 
};


void displayList(Node* head) {
    if (!head) {
        cout << "Linked list kosong\n";
        return;
    }
    
    cout << "Linked List yang dibuat: ";
    
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL\n";
}


Node* binarySearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    

    int size = 0;
    for (Node* current = head; current; current = current->next) {
        size++;
    }
    
    Node* start = head;
    int iteration = 1;
    
    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;
        
        
        for (int i = 0; i < mid; i++) {
            midNode = midNode->next;
        }
        
        if (midNode->data == key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) - DITEMUKAN!\n";
            return midNode;
        }
        
        
        if (midNode->data < key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kanan\n";
            
            int newSize = size - mid - 1;
            
        
            if (newSize == 1) {
                Node* lastNode = midNode->next;
                if (lastNode && lastNode->data == key) {
                    return lastNode;
                }
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            
            start = midNode->next;
            size = newSize;
            
            if (size <= 0) {
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
        }
        
        else {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kiri\n";
            
            
            if (mid == 1) {
                if (start->data == key) {
                    return start;
                }
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            
            size = mid;
            
            if (size <= 0) {
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
        }
        
        iteration++;
    }
    
    cout << "Tidak ada elemen tersisa\n";
    return nullptr;
}


void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    
    cout << "BINARY SEARCH PADA LINKED LIST\n";
    
   
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    
    displayList(head);
    
    
    cout << "Mencari nilai: 40";
    
    Node* result = binarySearch(head, 40);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << "\n";
        cout << "Data node: " << result->data << "\n";
        if (result->next) {
            cout << "Node berikutnya: " << result->next->data << "\n";
        } else {
            cout << "Node berikutnya: NULL\n";
        }
    } else {
        cout << "\nHasil: Nilai 40 TIDAK DITEMUKAN dalam linked list!\n";
    }
    
 
    cout << "Mencari nilai: 25\n";
    
    result = binarySearch(head, 25);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << "\n";
        cout << "Data node: " << result->data << "\n";
        if (result->next) {
            cout << "Node berikutnya: " << result->next->data << "\n";
        } else {
            cout << "Node berikutnya: NULL\n";
        }
    } else {
        cout << "\nHasil: Nilai 25 TIDAK DITEMUKAN dalam linked list!\n";
    }
    
  
    deleteList(head);
    
    return 0;
}