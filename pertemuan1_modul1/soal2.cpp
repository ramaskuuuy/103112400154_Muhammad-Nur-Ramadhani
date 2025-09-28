#include <iostream>
#include <string>
using namespace std;

string DigitToString (int digit) {

    string satuan [] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", 
                        "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas",
                         "tujuh belas", "delapan belas", "sembilan belas"};

    string puluhan [] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

 if (digit == 0) {
    return "nol";
    }

    else if (digit < 20) {
    return satuan[digit];
    }

    else if (digit < 100) {
    int puluhan_digit = digit / 10;
    int satuan_digit = digit % 10;
    if (satuan_digit == 0) {
        return puluhan[puluhan_digit];
    } else {
        return puluhan[puluhan_digit] + " " + satuan[satuan_digit];
    }
    }

 else if (digit == 100) {
        return "seratus";
        
    }
    return "angka di luar jangkauan";
}

int main (){
    int digit;
    cout << "Masukkan angka (0-100): ";
    cin >> digit;
    cout << "Angka dalam kata: " << DigitToString(digit) << endl;
    return 0;
}