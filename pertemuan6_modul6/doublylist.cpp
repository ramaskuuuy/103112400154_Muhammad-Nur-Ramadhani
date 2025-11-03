#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { 
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) { 
    address P = new ElmList; 
    P->info = x; 
    P->next = Nil; 
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P; 
}

void insertLast(List &L, address P) {
    if (L.first == Nil) { 
        L.first = P;
        L.last = P;
    } else { 
        P->prev = L.last; 
        (L.last)->next = P; 
        L.last = P;
    }
}


address findElm(List L, string nopol) {
    address P = L.first; 
    while (P != Nil) {
        
        if (P->info.nopol == nopol) {
            return P; 
        }
        P = P->next; 
    }
    return Nil; 
}


void printInfo(List L) { 
    address P = L.first; 
    if (P == Nil) {
        cout << "List Kosong.\n";
    } else {
        while (P != Nil) {
            cout << "no polisi : " << P->info.nopol << endl;
            cout << "warna     : " << P->info.warna << endl;
            cout << "tahun     : " << P->info.thnBuat << endl << endl;
            P = P->next;
        }
    }
}

void deleteFirst(List &L, address &P){
    P = L.first;
    L.first = (L.first) -> next;
    P -> prev = Nil;
    (L.first) -> prev = Nil;
    P -> next = Nil;
    dealokasi(P);
}
void deleteLast(List &L, address &P){
    P = L.last;
    L.last = (L.last) -> prev;
    P-> next = Nil;
    (L.last) -> next = Nil;
    dealokasi(P);
}
void deleteAfter(address prev, address &P) {
    if (prev != NULL && prev->next != NULL) {
        P = prev->next;               
        prev->next = P->next;          
        if (P->next != NULL) {         
            P->next->prev = prev;      
        }
        P->next = NULL;                
        P->prev = NULL;
        dealokasi(P);                 
    }
}

bool cekList(List L, string nopol){
    address Q = L.first;
    while(Q != Nil){
        if(Q -> info.nopol == nopol)
            return true;
        Q = Q -> next;
    }
    return false;
}
