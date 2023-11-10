#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// TAMPILAN NAMA POSTTEST

// cout << "-----------------------------------------------\n";
// cout << "|           Selamat Datang Di POSTTEST 2      |\n";
// cout << "-----------------------------------------------\n";

// cout << "'______________________________________________'"<<endl;
// cout << "': *             *               *            :'"<<endl;
// cout << "':     *                                 *    :'"<<endl;
// cout << "':                SELAMAT DATANG  *           :'"<<endl;
// cout << "':             DI TOKO SEPATU KAMI           *:'"<<endl;
// cout << "':   *                                        :'"<<endl;
// cout << "':           *                *        *      :'"<<endl;
// cout << "'______________________________________________'"<<endl;


// STRUCT SEPATU

struct Node {
    string merk;
    int ukuran;
    string warna;
    string jenis;
    double harga;
    Node* next;
};


// NODE SEPATU

Node* head = NULL;

int jumlahdata = 0;

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

void tampilkanData(Node* head) {
    int no = 1;  // Variabel untuk nomor urut

    // Header tabel
    cout << "+-----+------------------+--------+------------+------------+--------------+" << endl;
    cout << "| No  |       Merk       | Ukuran |    Warna   |    Jenis   |     Harga    |" << endl;
    cout << "+-----+------------------+--------+------------+------------+--------------+" << endl;

    while (head != NULL) {
        cout << "| " << setw(4) <<  no  // Menampilkan nomor urut
             << "| " << setw(17) << left << head->merk
             << "| " << setw(7) <<  head->ukuran 
             << "| " << setw(11) << left << head->warna 
             << "| " << setw(11) << left << head->jenis 
             << "| " << setw(12) << right << fixed << setprecision(2) << head->harga 
             << " |" << endl;
        cout << "+-----+------------------+--------+------------+------------+--------------+" << endl; 
        head = head->next;
        no++;  // Menambahkan nomor urut
    }

    cout << "+--------------------------------------+" << endl;
    cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
    cout << "+--------------------------------------+" ;
    cin.ignore();
    cin.get();
    system("cls");
}


// TAMBAHKAN DATA SEPATU DI AKHIR

void tambahDataLast(Node** head) {
    Node *nodeBaru = new Node;
    cout << "Masukkan Merk: "; cin >> nodeBaru->merk;
    nodeBaru->ukuran = inputInteger("Masukkan Ukuran: ");
    cout << "Masukkan Warna: "; cin >> nodeBaru->warna;
    cout << "Masukkan Jenis: "; cin >> nodeBaru->jenis;
    nodeBaru->harga = inputDouble("Masukkan Harga: ");
	nodeBaru->next = NULL;
	// jika linked list kosong
	if (*head == NULL){
	*head = nodeBaru;
	return;
	}
	// jika tidak
	// traversal ke node terakhir
	Node *temp = *head;
	while (temp->next != NULL){
	temp = temp->next;
	}
	temp->next = nodeBaru;
	jumlahdata += 1;
}


// TAMBAHKAN DATA SEPATU DI TENGAH

void tambahDataMiddle(Node** head) {
    if (*head == NULL) {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }

    Node* nodeBaru = new Node;
    cout << "Masukkan Merk: "; cin >> nodeBaru->merk;
    nodeBaru->ukuran = inputInteger("Masukkan Ukuran: ");
    cout << "Masukkan Warna: "; cin >> nodeBaru->warna;
    cout << "Masukkan Jenis: "; cin >> nodeBaru->jenis;
    nodeBaru->harga = inputDouble("Masukkan Harga: ");

    Node* slow = *head;
    Node* fast = *head;

    // Menggunakan teknik "tortoise and the hare" untuk menemukan tengah
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    nodeBaru->next = slow->next;
    slow->next = nodeBaru;
    jumlahdata += 1;
}


// TAMBAHKAN DATA SEPATU DI AWAL

void tambahDataFirst(Node **head) {
    Node *nodeBaru = new Node;
    cout << "Masukkan Merk: "; cin >> nodeBaru->merk;
    nodeBaru->ukuran = inputInteger("Masukkan Ukuran: ");
    cout << "Masukkan Warna: "; cin >> nodeBaru->warna;
    cout << "Masukkan Jenis: "; cin >> nodeBaru->jenis;
    nodeBaru->harga = inputDouble("Masukkan Harga: ");
    nodeBaru->next = *head;
    *head = nodeBaru;
}


// MENGUBAH DATA SEPATU

void ubahData(Node** head) {
    if (*head == NULL){
        cout << "LinkedList masih kosong" << endl;
        return;
    }
    int posisi;
    cout << "Masukan posisi data yang akan diubah : ";
    cin >> posisi;

    Node *temp = (*head);
    int jumlahdata = 0;

    // Menghitung jumlah data dalam linked list
    while (temp != NULL) {
        jumlahdata++;
        temp = temp->next;
    }

    // Memeriksa apakah posisi yang dimasukkan valid
    if (posisi < 1 || posisi > jumlahdata) {
        cout << "Posisi tidak valid" << endl;
        return;
    }

    temp = (*head);

    // Menggerakkan pointer 'temp' ke posisi yang ditentukan
    for(int i = 1; i < posisi; i++){
        temp = temp->next;
    }

    // Memasukkan data baru ke dalam node
    cout << "Masukkan data yang baru : " << endl;
    cout << "Masukkan Merk: "; 
    cin >> temp->merk;
    temp->ukuran = inputInteger("Masukkan Ukuran: ");
    cout << "Masukkan Warna: "; 
    cin >> temp->warna;
    cout << "Masukkan Jenis: "; 
    cin >> temp->jenis;
    temp->harga = inputDouble("Masukkan Harga: ");
    cout << "Data berhasil diubah" << endl;
}


// MENGHAPUS DATA SEPATU DI AWAL

void hapusDataFirst(Node** head) {
	if (*head == NULL){
	cout << ">> LinkedList masih kosong <<" << endl;
	return;
	}
	*head = (*head)->next;
	jumlahdata -= 1;

    
    cout << "+--------------------------------------+" << endl;
    cout << "|  Data sepatu sudah terhapus          |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
    cout << "+--------------------------------------+" ;
    cin.ignore();
    cin.get();
    system("cls");
}


// MENGHAPUS DATA SEPATU DI TENGAH

void hapusDataMiddle(Node** head) {
    if (*head == NULL) {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }

    Node* slow = *head;
    Node* fast = *head;
    Node* prev = NULL;

    // Menggunakan teknik "tortoise and the hare" untuk menemukan tengah
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    if (prev != NULL) {
        prev->next = slow->next;
        delete slow;
        jumlahdata -= 1;
    }
    cout << "+--------------------------------------+" << endl;
    cout << "|  Data sepatu sudah terhapus          |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
    cout << "+--------------------------------------+" ;
    cin.ignore();
    cin.get();
    system("cls");
}


// MEENGHAPUS DATA SEPATU DI AKHIR 

void hapusDataLast(Node** head) {
    if (*head == NULL){
	cout << ">> LinkedList masih kosong <<" << endl;
	return;
	}
	if ((*head)->next == NULL){
	*head = NULL;
	return;
	}
	Node *temp = *head;
	while (temp->next->next != NULL){
	temp = temp->next;
	}
	temp->next = NULL;
	jumlahdata -= 1;
    cout << "+--------------------------------------+" << endl;
    cout << "|  Data sepatu sudah terhapus          |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
    cout << "+--------------------------------------+" ;
    cin.ignore();
    cin.get();
    system("cls");
}


// TAMPILAN  DATA SEPATU PADA TAMPILAN AWAL

void inisialisasiDataAwal(Node** head) {
    string merks[] = {"Nike", "Adidas", "Puma", "Reebok", "Converse"};
    int ukurans[] = {40, 41, 42, 43, 44};
    string warnas[] = {"Merah", "Hitam", "Biru", "Kuning", "Putih"};
    string jeniss[] = {"Olahraga", "Santai", "Formal", "Lari", "Kasual"};
    double hargas[] = {500000, 600000, 700000, 800000, 900000};

    for (int i = 0; i < 5; i++) {
        Node* nodeBaru = new Node;
        nodeBaru->merk = merks[i];
        nodeBaru->ukuran = ukurans[i];
        nodeBaru->warna = warnas[i];
        nodeBaru->jenis = jeniss[i];
        nodeBaru->harga = hargas[i];
        nodeBaru->next = NULL;

        if (*head == NULL) {
            *head = nodeBaru;
        } else {
            Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = nodeBaru;
        }
    }
}


// TAMPILAN AWAL PROGRAM

int main() {
    system("cls");
    inisialisasiDataAwal(&head); // Inisialisasi data awal
    int pilihan;

    do {
        try {
        cout << "------------------------------------------------\n";
        cout << "|                   POSTTEST 2                 |\n";
        cout << "------------------------------------------------\n";

        cout << "'______________________________________________'"<<endl;
        cout << "': *             *               *            :'"<<endl;
        cout << "':     *                                 *    :'"<<endl;
        cout << "':                SELAMAT DATANG  *           :'"<<endl;
        cout << "':             DI TOKO SEPATU KAMI           *:'"<<endl;
        cout << "':   *                                        :'"<<endl;
        cout << "':           *                *        *      :'"<<endl;
        cout << "'______________________________________________'"<<endl;

		cout << "                                     " << endl;
		cout << "-------------------------------------" << endl;
		cout << "| 1 | Tampilan Data Sepatu          |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "| 2 | Ubah Data Sepatu              |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "| 3 | Tambah First Data Sepatu      |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "| 4 | Tambah Middle Data Sepatu     |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "| 5 | Tambah Last Data Sepatu       |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "| 6 | Hapus First Data Sepatu       |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "| 7 | Hapus Middle Data Sepatu      |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "| 8 | Hapus Last Data Sepatu        |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "| 9 | Keluar                        |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        // Jika cin mengalami error (misalnya pengguna memasukkan huruf)
        if (cin.fail()) {
            throw "Masukan harus berupa angka!";
        }

        if (pilihan < 1 || pilihan > 9) {
            throw "Pilihan menu tidak valid!";
        }
        
        system("cls");
        
        // CRUD DALAM DATA DAN JULAH SEPATU

        switch(pilihan) {
            case 1:
                tampilkanData(head);
                break;
            case 2:
                ubahData(&head);
                break;
            case 3:
                tambahDataFirst(&head);
                break;
            case 4:
                tambahDataMiddle(&head);
                break;
            case 5:
                tambahDataLast(&head);
                break;
            case 6:
                hapusDataFirst(&head);
                break;
            case 7:
                hapusDataMiddle(&head);
                break;
            case 8:
                hapusDataLast(&head);
                break;
            case 9:
                cout << "'______________________________________________'"<<endl;
                cout << "': *             *               *            :'"<<endl;
                cout << "':     *                                 *    :'"<<endl;
                cout << "':                TERIMA KASIH   *            :'"<<endl;
                cout << "':         TELAH BELANJA DI TOKO KAMI        *:'"<<endl;
                cout << "':   *                                        :'"<<endl;
                cout << "':           *                *        *      :'"<<endl;
                cout << "'__*_______*___________________________________'"<<endl;
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

    } while(pilihan != 9);

    return 0;

}