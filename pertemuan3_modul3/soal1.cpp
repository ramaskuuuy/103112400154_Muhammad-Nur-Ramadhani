#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama, nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.35 * uts) + (0.4 * uas) + (0.25 * tugas);
}

int main(){
    Mahasiswa mhs[10];
    int jumlahMhs;

    cout << "=== PROGRAM DATA MAHASISWA ===" << endl;
    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> jumlahMhs;

    if (jumlahMhs <1 || jumlahMhs > 10) {
        cout << "Jumlah mahasiswa harus antara 1 sampai 10." << endl;
        return 1;
    }

    for (int i = 0; i < jumlahMhs; i++) {
        cout << "\nData Mahasiswa ke-" << (i + 1) << endl;
        cout << "Nama: ";
        getline(cin >> ws, mhs[i].nama);
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "Nilai UTS: ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS: ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }
    
 for(int i = 0; i < jumlahMhs; i++) {
        cout << "\n=== DAFTAR NILAI MAHASISWA ===" << endl;
        cout << "Nama : " << mhs[i].nama << endl;
        cout << "NIM : " << mhs[i].nim << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
    }
    
    return 0; 
}