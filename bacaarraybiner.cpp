#include <iostream>
#include <fstream>
using namespace std;

// Fungsi untuk membaca array dari keyboard
void inputArray(int A[], int n) {
    cout << "Masukkan " << n << " elemen array:\n";
    for (int i = 0; i < n; i++) {
        cout << "A[" << i + 1 << "] = ";
        cin >> A[i];
    }
}

// Fungsi untuk menyimpan array ke file biner
void simpanKeFileBiner(int A[], int n) {
    ofstream file("data.dat", ios::binary);
    if (file.is_open()) {
        file.write(reinterpret_cast<char*>(A), n * sizeof(int)); // Menyimpan data array
        file.close();
        cout << "Data array berhasil disimpan ke file data.dat\n";
    } else {
        cout << "File biner tidak dapat dibuka!\n";
    }
}

// Fungsi untuk membaca array dari file biner
void bacaDariFileBiner(int B[], int n) {
    ifstream file("data.dat", ios::binary);
    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(B), n * sizeof(int)); // Membaca data array
        file.close();
        cout << "\nData array yang dibaca dari file data.dat:\n";
        for (int i = 0; i < n; i++) {
            cout << "B[" << i + 1 << "] = " << B[i] << endl; // Menampilkan data array
        }
    } else {
        cout << "File biner tidak dapat dibuka!\n";
    }
}
int main() {
    const int n = 5; // Ukuran array
    int A[n]; // Array input
    int B[n]; // Array untuk membaca dari file

    // Langkah 1: Membaca data array dari keyboard
    inputArray(A, n);

    // Langkah 2: Menyimpan data array ke file biner
    simpanKeFileBiner(A, n);

    // Langkah 3: Membaca data dari file biner dan menampilkannya
    bacaDariFileBiner(B, n);
    return 0;
}
