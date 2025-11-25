#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

// Check if the stack is empty
bool isEmpty(StackMahasiswa& S) {
    return (S.Top == -1);
}

// Check if the stack is full
bool isFull(StackMahasiswa& S) {
    return (S.Top == MAX - 1);
}

// Initialize the stack
void createStack(StackMahasiswa& S) {
    S.Top = -1;
}

// Insert data (push) into the stack
void push(StackMahasiswa& S, Mahasiswa m) {
    if (isFull(S)) {
        cout << "Stack is full!" << endl;
    } else {
        S.Top++;
        S.dataMahasiswa[S.Top] = m;
    }
}

// Remove data (pop) from the stack
void pop(StackMahasiswa& S) {
    if (isEmpty(S)) {
        cout << "Stack is empty!" << endl;
    } else {
        S.Top--;
    }
}

// View all data in the stack
void view(StackMahasiswa& S) {
    if (isEmpty(S)) {
        cout << "Stack is empty!" << endl;
    } else {
        for (int i = 0; i <= S.Top; i++) {
            cout << "Nama: " << S.dataMahasiswa[i].Name << ", NIM: " << S.dataMahasiswa[i].NIM 
                 << ", Nilai Tugas: " << S.dataMahasiswa[i].NilaiTugas << ", Nilai UTS: " 
                 << S.dataMahasiswa[i].NilaiUTS << ", Nilai UAS: " << S.dataMahasiswa[i].NilaiUAS << endl;
        }
    }
}

// Update student data at a specific position
void update(StackMahasiswa& S, int pos, Mahasiswa m) {
    if (pos < 0 || pos > S.Top) {
        cout << "Invalid position!" << endl;
    } else {
        S.dataMahasiswa[pos] = m;
    }
}

// Search and display students with NilaiAkhir within the range [min, max]
void searchNilaiAkhir(StackMahasiswa& S, float min, float max) {
    for (int i = 0; i <= S.Top; i++) {
        float nilaiAkhir = (S.dataMahasiswa[i].NilaiTugas * 0.2) + (S.dataMahasiswa[i].NilaiUTS * 0.4) + (S.dataMahasiswa[i].NilaiUAS * 0.4);
        if (nilaiAkhir >= min && nilaiAkhir <= max) {
            cout << "Nama: " << S.dataMahasiswa[i].Name << ", NIM: " << S.dataMahasiswa[i].NIM
                 << ", Nilai Akhir: " << nilaiAkhir << endl;
        }
    }
}