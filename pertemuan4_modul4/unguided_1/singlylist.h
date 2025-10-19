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
    address first;
};

typedef list List; 

void CreateList(List &L);
address alokasi(infoType X);     
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif