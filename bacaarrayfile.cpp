#include <iostream>
#include <fstream>
using namespace std;

// Fungsi untuk membaca matriks dari keyboard
void input(int A[3][4]) {
    cout << "Masukkan elemen matriks 3x4:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> A[i][j];
        }
    }
}

// Fungsi untuk menyimpan matriks ke file teks
void simpanKeFileTeks(int A[3][4]) {
    ofstream file("data.txt");
    if (file.is_open()) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                file << A[i][j] << " "; // Menyimpan elemen matriks
            }
            file << endl; // Baris baru untuk setiap baris matriks
        }
        file.close();
        cout << "Data matriks berhasil disimpan ke file data.txt\n";
    } else {
        cout << "File tidak dapat dibuka!\n";
    }
}

// Fungsi untuk membaca matriks dari file teks dan menampilkannya ke monitor
void bacaFileTeks() {
    ifstream file("data.txt");
    if (file.is_open()) {
        string baris;
        cout << "\nIsi file data.txt:\n";
        while (getline(file, baris)) { // Membaca file baris per baris
            cout << baris << endl; // Menampilkan baris ke monitor
        }
        file.close();
    } else {
        cout << "File tidak dapat dibuka!\n";
    }
}

int main() {
    int matriks[3][4];

    // Langkah 1: Membaca matriks dari keyboard
    input(matriks);

    // Langkah 2: Menyimpan matriks ke file teks
    simpanKeFileTeks(matriks);

    // Langkah 3: Membaca dan menampilkan isi file teks
    bacaFileTeks();

    return 0;
}
