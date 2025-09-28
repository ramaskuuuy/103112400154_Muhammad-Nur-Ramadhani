#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Masukan angka : ";
    cin >> n;
    
    cout << "Hasil : " << endl;
    

    for (int i = n; i >= 1; i--) {
     
        for (int space = 0; space < n - i; space++) {
            cout << " ";
        }
        
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        
        cout << " * ";
        
        for (int k = 1; k <= i; k++) {
            cout << k;
        }
        
        cout << endl;
    }
    
    for (int space = 0; space < n; space++) {
        cout <<" ";
    }
    cout << " * " << endl;
    
    return 0;
}