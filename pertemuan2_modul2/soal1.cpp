#include <iostream>
#include <iomanip>
using namespace std;


void tampilkanMatriks(int matriks[3][3], string nama) {
    cout << "\n" << nama << ":\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << setw(5) << matriks[i][j] << " ";
        }
        cout << endl;
    }
}


void jumlahMatriks(int A[3][3], int B[3][3], int hasil[3][3]) {
    cout << "\n=== PENJUMLAHAN MATRIKS ===";
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            hasil[i][j] = A[i][j] + B[i][j];
        }
    }
  
}


void kurangMatriks(int A[3][3], int B[3][3], int hasil[3][3]) {
    cout << "\n=== PENGURANGAN MATRIKS ===";
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            hasil[i][j] = A[i][j] - B[i][j];
        }
    }
    
}

void kaliMatriks(int A[3][3], int B[3][3], int hasil[3][3]) {
    cout << "\n=== PERKALIAN MATRIKS ===";
    
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            hasil[i][j] = 0;
        }
    }
    
   
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                hasil[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
}

int main() {
    int matriksA[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    

    int matriksB[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };
    
    int hasil[3][3];
    int pilihan;
    
    do {
       
        cout << "\n========================================";
        cout << "\n       Menu Program Matriks";
        cout << "\n========================================";
        cout << "\n1. Penjumlahan matrix";
        cout << "\n2. Pengurangan matrix";
        cout << "\n3. Perkalian Matrix";
        cout << "\n4. Keluar";
        cout << "\n========================================";
        cout << "\nPilih menu (1-4): ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                jumlahMatriks(matriksA, matriksB, hasil);
                tampilkanMatriks(hasil, "Hasil Penjumlahan");
                break;
            case 2:
                kurangMatriks(matriksA, matriksB, hasil);
                tampilkanMatriks(hasil, "Hasil Pengurangan");
                break;
            case 3:
                kaliMatriks(matriksA, matriksB, hasil);
                tampilkanMatriks(hasil, "Hasil Perkalian");
                break;
            case 4:
                cout << "\nTerima kasih telah menggunakan program ini!\n";
                break;
            default:
                cout << "\nPilihan tidak valid! Silakan pilih 1-4.\n";
        }
        
        
    } while(pilihan != 4);
    
    return 0;
}