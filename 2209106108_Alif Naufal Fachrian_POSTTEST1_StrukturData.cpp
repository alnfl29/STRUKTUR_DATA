#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// TAMPILAN NAMA POSTTEST

// cout << "-----------------------------------------------\n";
// cout << "|           Selamat Datang Di POSTTEST 1      |\n";
// cout << "-----------------------------------------------\n";

// cout << "'______________________________________________'"<<endl;
// cout << "': *             *               *            :'"<<endl;
// cout << "':     *                                 *    :'"<<endl;
// cout << "':                SELAMAT DATANG  *           :'"<<endl;
// cout << "':             DI TOKO SEPATU KAMI           *:'"<<endl;
// cout << "':   *                                        :'"<<endl;
// cout << "':           *                *        *      :'"<<endl;
// cout << "'_______*_____________________*________________'"<<endl;

// ARRAY
const int MAX = 100; // Maksimum jumlah sepatu


// STRUCT SEPATU

struct Sepatu {
    string merk;
    int ukuran;
    string warna;
    string jenis;
    double harga;
};

// CONTOH DATA LIST SEPATU

Sepatu batas[100]={{"Nike", 42, "Merah", "Olahraga", 600000.0},
				   {"Adidas", 41, "Biru", "Kasual", 450000.0},
				   {"Puma", 43, "Hitam", "Lari", 550000.0},
				 };
int indextabel = 5;
int merk,ukuran,warna,jenis,harga;


// ERROR HANDLING INPUT SIZE/UKURAN SEPATU

int inputInteger(const string& prompt) {
    int value;
    cout << prompt;

    while(!(cin >> value)) { // Jika gagal membaca tipe int
        cout << "Masukan tidak valid. Silakan masukkan angka." << endl;
        cin.clear(); // Membersihkan status gagal/buruk dari 'cin'
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input yang salah
        cout << prompt;
    }

    // Mengosongkan buffer sebelum kembali ke menu utama atau operasi lainnya
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}


// ERROR HANDLING INPUT HARGA SEPATU
double inputDouble(const string& prompt) {
    double value;
    cout << prompt;

    while(!(cin >> value)) { // Jika gagal membaca tipe double
        cout << "Masukan tidak valid. Silakan masukkan angka yang benar." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << prompt;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}


// MENAMPILKAN DATA SEPATU

void tampilkanData(Sepatu *data, int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << "+----+-----+---------------+--------+------------+------------+--------------+" << endl;
        cout << "| No | Idx |    Merk       | Ukuran |    Warna   |    Jenis   |     Harga    |" << endl;
        cout << "+----+-----+---------------+--------+------------+------------+--------------+" << endl;

        cout << "| " << setw(3) << left << i+1
             << "| " << setw(4) << left << i  
             << "| " << setw(14) << left << data[i].merk 
             << "| " << setw(7) << data[i].ukuran 
             << "| " << setw(11) << data[i].warna 
             << "| " << setw(11) << data[i].jenis 
             << "| " << setw(12) << right << data[i].harga 
             << " |" << endl;
        cout << "+----+-----+---------------+--------+------------+------------+--------------+" << endl << endl; 
        

    }
    cout << "+--------------------------------------+" << endl;
    cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
    cout << "+--------------------------------------+" ;
    cin.ignore();
    cin.get();
    system("cls");
}


// MENAMBAHKAN DATA SEPATU

void tambahData(Sepatu *data, int &jumlah) {
    if (jumlah < MAX) {
        cout << "Masukkan Merk: "; cin >> data[jumlah].merk;
        data[jumlah].ukuran = inputInteger("Masukkan Ukuran: ");
        cout << "Masukkan Warna: "; cin >> data[jumlah].warna;
        cout << "Masukkan Jenis: "; cin >> data[jumlah].jenis;
        data[jumlah].harga = inputDouble("Masukkan Harga: ");
        jumlah++;
    } else {
        cout << "+--------------------------+" << endl;
        cout << "|      Database Penuh!     |" << endl;
        cout << "+--------------------------+" ;
        
    }
}


// MENGUBAH DATA SEPATU

void ubahData(Sepatu *data, int jumlah) {
    int index;
    cout << "Masukkan indeks sepatu yang ingin diubah: ";
    cin >> index;

    if (index >= 0 && index < jumlah) {
        cout << "Masukkan Merk: "; cin >> data[index].merk;
        cout << "Masukkan Ukuran: "; cin >> data[index].ukuran;
        cout << "Masukkan Warna: "; cin >> data[index].warna;
        cout << "Masukkan Jenis: "; cin >> data[index].jenis;
        cout << "Masukkan Harga: "; cin >> data[index].harga;
    } else {
        cout << "+--------------------------+" << endl;
        cout << "|   Indeks tidak valid!    |" << endl;
        cout << "+--------------------------+" ;
        
    }
}


// MENGHAPUS DATA SEPATU

void hapusData(Sepatu *data, int &jumlah) {
    int index;
    cout << "Masukkan indeks sepatu yang ingin dihapus: ";
    cin >> index;

    if (index >= 0 && index < jumlah) {
        for (int i = index; i < jumlah - 1; i++) {
            data[i] = data[i+1];
        }
        jumlah--;
    } else {
        cout << "+--------------------------+" << endl;
        cout << "|   Indeks tidak valid!    |" << endl;
        cout << "+--------------------------+" ;
        
    }
}


// MENAMPILKAN POINTER DATA SEPATU

void tampilkanDataBerdasarkanPointer(Sepatu *data, int jumlah) {
    int index;
    tampilkanData(data, jumlah);
    cout << "Masukkan indeks sepatu yang ingin ditampilkan (0-" << jumlah-1 << "): ";
    cin >> index;
    

    if (index >= 0 && index < jumlah) {
        cout << "+-----+----------------+--------+------------+------------+--------------+" << endl;
        cout << "| No  |     Merk       | Ukuran |    Warna   |    Jenis   |     Harga    |" << endl;
        cout << "+-----+----------------+--------+------------+------------+--------------+" << endl;

        cout << "| " << setw(4) << left << index+1  
             << "| " << setw(15) << left << data[index].merk 
             << "| " << setw(7) << data[index].ukuran 
             << "| " << setw(11) << data[index].warna 
             << "| " << setw(11) << data[index].jenis 
             << "| " << setw(12) << right << data[index].harga 
             << " |" << endl;

        cout << "+-----+----------------+--------+------------+------------+--------------+" << endl << endl; 

    } else {
        cout << "+--------------------------+" << endl;
        cout << "|   Indeks tidak valid!    |" << endl;
        cout << "+--------------------------+" ;
        
    }
     cout << "+--------------------------------------+" << endl;
     cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
     cout << "+--------------------------------------+" ;
     cin.ignore();
     cin.get();
     system("cls");
  
}


// MENAMPILKAN ALAMAT MEMORI SEPATU

void tampilkanAlamat(Sepatu *data, int jumlah) {
    int index;
    tampilkanData(data, jumlah);
    cout << "Masukkan indeks sepatu untuk melihat alamat memori (0-" << jumlah-1 << "): ";
    cin >> index;

    if (index >= 0 && index < jumlah) {
        cout << "Alamat memori untuk sepatu indeks " << index << " adalah: " << &data[index] << endl;
    } else {
        cout << "+--------------------------+" << endl;
        cout << "|   Indeks tidak valid!    |" << endl;
        cout << "+--------------------------+" ;
    }
     cout << "+--------------------------------------+" << endl;
     cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
     cout << "+--------------------------------------+" ;
     cin.ignore();
     cin.get();
     system("cls");
}


// TAMPILAN AWAL PROGRAM

int main() {
    system("cls");
    Sepatu data[MAX];
    int jumlah = 0;
    int pilihan;

    // list 3 sepatu
    data[0] = {"Nike", 42, "Merah", "Olahraga", 600000.0};
    data[1] = {"Adidas", 41, "Biru", "Kasual", 450000.0};
    data[2] = {"Puma", 43, "Hitam", "Lari", 550000.0};
    jumlah = 3; 

    do {
        try {
        cout << "------------------------------------------------\n";
        cout << "|                   POSTTEST 1                 |\n";
        cout << "------------------------------------------------\n";

        cout << "'______________________________________________'"<<endl;
        cout << "': *             *               *            :'"<<endl;
        cout << "':     *                                 *    :'"<<endl;
        cout << "':                SELAMAT DATANG  *           :'"<<endl;
        cout << "':             DI TOKO SEPATU KAMI           *:'"<<endl;
        cout << "':   *                                        :'"<<endl;
        cout << "':           *                *        *      :'"<<endl;
        cout << "'_______*_____________________*________________'"<<endl;

		cout << "                                " << endl;
		cout << "--------------------------------" << endl;
		cout << "| 1 | Tambah Data Sepatu       |" << endl;
        cout << "--------------------------------" << endl;
        cout << "| 2 | Ubah Data Sepatu         |" << endl;
        cout << "--------------------------------" << endl;
        cout << "| 3 | Hapus Data Sepatu        |" << endl;
        cout << "--------------------------------" << endl;
        cout << "| 4 | Tampilan Data Sepatu     |" << endl;
        cout << "--------------------------------" << endl;
        cout << "| 5 | Pointer Data Sepatu      |" << endl;
        cout << "--------------------------------" << endl;
        cout << "| 6 | Tampilkan Alamat Pointer |" << endl;
        cout << "--------------------------------" << endl;
        cout << "| 7 | Keluar                   |" << endl;
        cout << "--------------------------------" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        // Jika cin mengalami error (misalnya pengguna memasukkan huruf)
            if (cin.fail()) {
                throw "Masukan harus berupa angka!";
            }

            if (pilihan < 1 || pilihan > 7) {
                throw "Pilihan menu tidak valid!";
            }

        
        system("cls");
        


        // CRUD DALAM DATA DAN JULAH SEPATU

        switch(pilihan) {
            case 1:
                tambahData(data, jumlah);
                break;
            case 2:
                ubahData(data, jumlah);
                break;
            case 3:
                hapusData(data, jumlah);
                break;
            case 4:
                tampilkanData(data, jumlah);
                break;
            case 5:
                tampilkanDataBerdasarkanPointer(data, jumlah);
                break;
            case 6:
                tampilkanAlamat(data, jumlah);
                break;
            case 7:
                cout << "'______________________________________________'"<<endl;
                cout << "': *             *               *            :'"<<endl;
                cout << "':     *                                 *    :'"<<endl;
                cout << "':                TERIMA KASIH   *            :'"<<endl;
                cout << "':         TELAH BELANJA DI TOKO KAMI        *:'"<<endl;
                cout << "':   *                                        :'"<<endl;
                cout << "':           *                *        *      :'"<<endl;
                cout << "'_______*_____________________*________________'"<<endl;
                break;
            cout << "+--------------------------+" << endl;
            cout << "|   Pilihan tidak valid!   |" << endl;
            cout << "+--------------------------+" ;
            }

        // ERROR HANDLING PADA MENU UTAMA

        } catch (const char* error) {
            cout << "Error: " << error << endl;
            cin.clear();  // Bersihkan error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Menghapus buffer
            system("pause"); // Berhenti sejenak untuk membiarkan pengguna membaca pesan kesalahan
            system("cls");
        }
    } while(pilihan != 7);

    return 0;
}



