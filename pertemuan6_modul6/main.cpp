#include "Doublylist.h"

using namespace std;

int main() { // penggunaan fungsi-fungsi dalam Doublylist
    List L; // deklarasi list
    CreateList(L); // buat list kosong
    address P; // deklarasi pointer elemen list
    infotype data; // deklarasi variabel info kendaraan
    
    int n ;
    cout << "Masukan banyak data : ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) { 
        cout << "masukkan nomor polisi: ";
        cin >> data.nopol;

        if (cekList(L, data.nopol)) {
            cout << "masukkan warna kendaraan: ";
            cin >> data.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> data.thnBuat;
            cout << "nomor polisi sudah terdaftar \n";
        } else {
            cout << "masukkan warna kendaraan: ";
            cin >> data.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> data.thnBuat;

            P = alokasi(data);
            insertLast(L, P);
        }
        cout << endl;
    }

    cout << "DATA LIST 1 " << endl;
    printInfo(L);

    //cari nopol 
    string cariNopol = "D001";
    cout << "Masukan Nomor polisi yang dicari : "<< cariNopol  << endl;
    address found = findElm(L, cariNopol); 
    if (found != Nil) { 
        cout << "Nomor Polisi : " << found->info.nopol 
        << "\nWarna : " << found->info.warna 
        << "\nTahun : " << found -> info.thnBuat << endl << endl;
    } else {
        cout << cariNopol << " tidak ditemukan." << endl << endl;
    }

    
    address prev = L.first; 
    while(prev != Nil && prev -> next != Nil){
        if(prev -> next -> info.nopol == "D003"){
            break;
        }
        prev = prev -> next;
    }
    if(prev != Nil && prev -> next != Nil){
        deleteAfter(prev, P);
        cout << "Data dengan nomor polisi D003 berhasil dihapus\n";
    }else{
        cout << "Data dengan nomor polisi D003 tidak ditemukan\n";
    }
    
    cout << "DATA LIST 1" << endl;
    printInfo(L);
    return 0;
}