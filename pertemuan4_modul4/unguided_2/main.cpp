#include "singlylist.h"

int main (){
    list L;
    address p1, p2, p3, p4, p5 = NULL; 
    CreateList(L);
    p1 = alokasi(2);
    insertFirst(L, p1);
    p2 = alokasi(0);
    insertFirst(L, p2);
    p3 = alokasi(8);
    insertFirst(L, p3);
    p4 = alokasi(12);
    insertFirst(L, p4);
    p5 = alokasi(9);
    insertFirst(L, p5);
 

    deleteFirst(L, p1);
    deleteLast(L, p5);

    address p;
    deleteAfter(L, p, p4);
    dealokasi(p);
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    deleteList(L);
    cout << "List berhasil terhapus " << endl;
    cout << "Jumlah node : " << nbList(L) << endl;
    
}