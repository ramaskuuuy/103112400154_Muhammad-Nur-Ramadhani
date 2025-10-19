#include "singlylist.h"

void CreateList(List &L) {
    L.first = NULL;
}
address alokasi (infoType X) {
    address P = new Elmlist;
    P->info = X;
    P->next = NULL;
    return P;
}

void dealokasi (address &P) {
    delete P;
}
void printInfo (List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
void insertFirst (List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

