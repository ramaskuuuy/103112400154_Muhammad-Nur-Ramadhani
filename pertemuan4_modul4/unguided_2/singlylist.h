#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

typedef int infoType;

struct Elmlist {
    infoType info;
    Elmlist* next;
};

typedef Elmlist* address;

struct list {
    address First;
};

typedef list List; // Tambahkan ini untuk konsistensi

void CreateList(List &L);
address alokasi(infoType X);      // Perbaiki: infoType (bukan infotype)
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address Prec);
int nbList(List L);
void deleteList(List &L);

#endif