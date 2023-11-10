#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// TAMPILAN NAMA POSTTEST

// cout << "-----------------------------------------------\n";
// cout << "|           Selamat Datang Di POSTTEST 5      |\n";
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

struct Node
{
    string merk;
    int ukuran;
    string warna;
    string jenis;
    double harga;
    Node *next;
    Node *prev; // Pointer ke node sebelumnya
};

// NODE SEPATU

Node *head = NULL;

int jumlahdata = 0;

int merk, ukuran, warna, jenis, harga;

// Fungsi  mendapatkan tengah dari linked list
Node *getMiddle(Node *head)
{
    if (!head)
        return head;

    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// ERROR HANDLING INPUT SIZE/UKURAN SEPATU

int inputInteger(const string &prompt)
{
    int value;
    cout << prompt;

    while (!(cin >> value))
    { // Jika gagal membaca tipe int
        cout << "Masukan tidak valid. Silakan masukkan angka." << endl;
        cin.clear();                                         // Membersihkan status gagal/buruk dari 'cin'
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input yang salah
        cout << prompt;
    }

    // Mengosongkan buffer sebelum kembali ke menu utama atau operasi lainnya
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

// ERROR HANDLING INPUT HARGA SEPATU

double inputDouble(const string &prompt)
{
    double value;
    cout << prompt;

    while (!(cin >> value))
    { // Jika gagal membaca tipe double
        cout << "Masukan tidak valid. Silakan masukkan angka yang benar." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << prompt;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

// MENAMPILKAN DATA SEPATU

void tampilkanData(Node *head)
{
    int no = 1; // Variabel untuk nomor urut

    // Header tabel
    cout << "+-----+------------------+--------+------------+------------+--------------+" << endl;
    cout << "| No  |       Merk       | Ukuran |    Warna   |    Jenis   |     Harga    |" << endl;
    cout << "+-----+------------------+--------+------------+------------+--------------+" << endl;

    while (head != NULL)
    {
        cout << "| " << setw(4) << no // Menampilkan nomor urut
             << "| " << setw(17) << left << head->merk
             << "| " << setw(7) << head->ukuran
             << "| " << setw(11) << left << head->warna
             << "| " << setw(11) << left << head->jenis
             << "| " << setw(12) << right << fixed << setprecision(2) << head->harga
             << " |" << endl;
        cout << "+-----+------------------+--------+------------+------------+--------------+" << endl;
        head = head->next;
        no++; // Menambahkan nomor urut
    }

    cout << "+--------------------------------------+" << endl;
    cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
    cout << "+--------------------------------------+";
    cin.ignore();
    cin.get();
    system("cls");
}

// TAMBAHKAN DATA SEPATU DI AKHIR

void tambahDataLast(Node **head)
{
    Node *nodeBaru = new Node;
    cout << "Masukkan Merk: ";
    cin >> nodeBaru->merk;
    nodeBaru->ukuran = inputInteger("Masukkan Ukuran: ");
    cout << "Masukkan Warna: ";
    cin >> nodeBaru->warna;
    cout << "Masukkan Jenis: ";
    cin >> nodeBaru->jenis;
    nodeBaru->harga = inputDouble("Masukkan Harga: ");
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;

    if (*head == NULL)
    {
        *head = nodeBaru;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nodeBaru;
        nodeBaru->prev = temp; // Set pointer prev dari nodeBaru
    }
    jumlahdata += 1;
}

// TAMBAHKAN DATA SEPATU DI TENGAH

void tambahDataMiddle(Node **head)
{
    if (*head == NULL)
    {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }

    Node *nodeBaru = new Node;
    cout << "Masukkan Merk: ";
    cin >> nodeBaru->merk;
    nodeBaru->ukuran = inputInteger("Masukkan Ukuran: ");
    cout << "Masukkan Warna: ";
    cin >> nodeBaru->warna;
    cout << "Masukkan Jenis: ";
    cin >> nodeBaru->jenis;
    nodeBaru->harga = inputDouble("Masukkan Harga: ");

    Node *middle = getMiddle(*head);

    nodeBaru->next = middle->next;
    if (middle->next)
        middle->next->prev = nodeBaru;
    middle->next = nodeBaru;
    nodeBaru->prev = middle;

    jumlahdata += 1;
}

// TAMBAHKAN DATA SEPATU DI AWAL

void tambahDataFirst(Node **head)
{
    Node *nodeBaru = new Node;
    cout << "Masukkan Merk: ";
    cin >> nodeBaru->merk;
    nodeBaru->ukuran = inputInteger("Masukkan Ukuran: ");
    cout << "Masukkan Warna: ";
    cin >> nodeBaru->warna;
    cout << "Masukkan Jenis: ";
    cin >> nodeBaru->jenis;
    nodeBaru->harga = inputDouble("Masukkan Harga: ");
    nodeBaru->next = *head;
    nodeBaru->prev = NULL;

    if (*head != NULL)
        (*head)->prev = nodeBaru;

    *head = nodeBaru;
}

// MENGUBAH DATA SEPATU

void ubahData(Node **head)
{
    if (*head == NULL)
    {
        cout << "LinkedList masih kosong" << endl;
        return;
    }
    int posisi;
    cout << "Masukan posisi data yang akan diubah : ";
    cin >> posisi;

    Node *temp = (*head);
    int jumlahdata = 0;

    // Menghitung jumlah data dalam linked list
    while (temp != NULL)
    {
        jumlahdata++;
        temp = temp->next;
    }

    // Memeriksa apakah posisi yang dimasukkan valid
    if (posisi < 1 || posisi > jumlahdata)
    {
        cout << "Posisi tidak valid" << endl;
        return;
    }

    temp = (*head);

    // Menggerakkan pointer 'temp' ke posisi yang ditentukan
    for (int i = 1; i < posisi; i++)
    {
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

void hapusDataFirst(Node **head)
{
    if (*head == NULL)
    {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    if (*head)
        (*head)->prev = NULL;
    delete temp;
    jumlahdata -= 1;
    cout << "+--------------------------------------+" << endl;
    cout << "|  Data sepatu sudah terhapus          |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
    cout << "+--------------------------------------+";
    cin.ignore();
    cin.get();
    system("cls");
}

// MENGHAPUS DATA SEPATU DI TENGAH

void hapusDataMiddle(Node **head)
{
    if (*head == NULL)
    {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }

    Node *middle = getMiddle(*head);
    if (middle->next == NULL) // Jika tidak ada node setelah tengah
    {
        return;
    }

    Node *temp = middle->next;
    middle->next = temp->next;
    if (temp->next)
        temp->next->prev = middle;
    delete temp;
    jumlahdata -= 1;
    cout << "+--------------------------------------+" << endl;
    cout << "|  Data sepatu sudah terhapus          |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
    cout << "+--------------------------------------+";
    cin.ignore();
    cin.get();
    system("cls");
}

// MEENGHAPUS DATA SEPATU DI AKHIR

void hapusDataLast(Node **head)
{
    if (*head == NULL)
    {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev)
        temp->prev->next = NULL;
    else
        *head = NULL;
    delete temp;
    jumlahdata -= 1;
    cout << "+--------------------------------------+" << endl;
    cout << "|  Data sepatu sudah terhapus          |" << endl;
    cout << "+--------------------------------------+" << endl;
    cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
    cout << "+--------------------------------------+";
    cin.ignore();
    cin.get();
    system("cls");
}

// TAMPILAN  DATA SEPATU PADA TAMPILAN AWAL

void inisialisasiDataAwal(Node **head)
{
    string merks[] = {"Nike", "Adidas", "Puma", "Reebok", "Converse"};
    int ukurans[] = {40, 41, 42, 43, 44};
    string warnas[] = {"Merah", "Hitam", "Biru", "Kuning", "Putih"};
    string jeniss[] = {"Olahraga", "Santai", "Formal", "Lari", "Kasual"};
    double hargas[] = {500000, 600000, 700000, 800000, 900000};

    for (int i = 0; i < 5; i++)
    {
        Node *nodeBaru = new Node;
        nodeBaru->merk = merks[i];
        nodeBaru->ukuran = ukurans[i];
        nodeBaru->warna = warnas[i];
        nodeBaru->jenis = jeniss[i];
        nodeBaru->harga = hargas[i];
        nodeBaru->next = NULL;

        if (*head == NULL)
        {
            *head = nodeBaru;
        }
        else
        {
            Node *temp = *head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nodeBaru;
        }
    }
}

// Fungsi untuk menggabungkan dua linked list yang sudah diurutkan
Node *merge(Node *a, Node *b, int criteria, bool ascending)
{
    Node *result = NULL;

    // Base cases
    if (!a)
        return b;
    if (!b)
        return a;

    // Urutkan berdasarkan kriteria yang dipilih
    if (criteria == 1)
    { // Merk
        if ((ascending && a->merk <= b->merk) || (!ascending && a->merk >= b->merk))
        {
            result = a;
            result->next = merge(a->next, b, criteria, ascending);
        }
        else
        {
            result = b;
            result->next = merge(a, b->next, criteria, ascending);
        }
    }
    else if (criteria == 2)
    { // Ukuran
        if ((ascending && a->ukuran <= b->ukuran) || (!ascending && a->ukuran >= b->ukuran))
        {
            result = a;
            result->next = merge(a->next, b, criteria, ascending);
        }
        else
        {
            result = b;
            result->next = merge(a, b->next, criteria, ascending);
        }
    }
    else
    { // Harga
        if ((ascending && a->harga <= b->harga) || (!ascending && a->harga >= b->harga))
        {
            result = a;
            result->next = merge(a->next, b, criteria, ascending);
        }
        else
        {
            result = b;
            result->next = merge(a, b->next, criteria, ascending);
        }
    }

    return result;
}

// FUNGSI UTAMA MERGE SORT
Node *mergeSort(Node *head, int criteria, bool ascending)
{
    if (!head || !head->next)
        return head;

    Node *middle = getMiddle(head);
    Node *nextOfMiddle = middle->next;

    middle->next = NULL;

    Node *left = mergeSort(head, criteria, ascending);
    Node *right = mergeSort(nextOfMiddle, criteria, ascending);

    Node *sortedList = merge(left, right, criteria, ascending);
    return sortedList;
}


// FUNGSI FIBONACCI SEARCH
int fibonacciSearch(Node *head, int x, bool isSize)
{
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < jumlahdata)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;
    Node *curr = head;

    while (fibM > 1)
    {
        int i = min(offset + fibMMm2, jumlahdata - 1);
        curr = head;
        for (int j = 0; j <= i; j++)
        {
            if (j != 0)
                curr = curr->next;
        }

        if ((isSize && curr->ukuran < x) || (!isSize && curr->harga < x))
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (isSize && curr->ukuran > x || !isSize && curr->harga > x)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
            return i;
    }

    if (fibMMm1 && curr && ((isSize && curr->ukuran == x) || (!isSize && curr->harga == x)))
        return offset + 1;

    return -1;
}

// FUNGSI BOYER MOORE SEARCH
#define NO_OF_CHARS 256

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
    int i;

    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

int searchBoyerMoore(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            return s;
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }
        else
        {
            s += max(1, j - badchar[txt[s + j]]);
        }
    }
    return -1;
}

// TAMPILAN AWAL PROGRAM

int main()
{
    system("cls");
    inisialisasiDataAwal(&head); // Inisialisasi data awal
    int pilihan;

    do
    {
        try
        {
            cout << "------------------------------------------------\n";
            cout << "|                   POSTTEST 5                 |\n";
            cout << "------------------------------------------------\n";

            cout << "'______________________________________________'" << endl;
            cout << "': *             *               *            :'" << endl;
            cout << "':     *                                 *    :'" << endl;
            cout << "':                SELAMAT DATANG  *           :'" << endl;
            cout << "':             DI TOKO SEPATU KAMI           *:'" << endl;
            cout << "':   *                                        :'" << endl;
            cout << "':           *                *        *      :'" << endl;
            cout << "'______________________________________________'" << endl;

            cout << "                                     " << endl;
            cout << "-------------------------------------" << endl;
            cout << "|  1 | Tampilan Data Sepatu         |" << endl;
            cout << "-------------------------------------" << endl;
            cout << "|  2 | Ubah Data Sepatu             |" << endl;
            cout << "-------------------------------------" << endl;
            cout << "|  3 | Tambah First Data Sepatu     |" << endl;
            cout << "-------------------------------------" << endl;
            cout << "|  4 | Tambah Middle Data Sepatu    |" << endl;
            cout << "-------------------------------------" << endl;
            cout << "|  5 | Tambah Last Data Sepatu      |" << endl;
            cout << "-------------------------------------" << endl;
            cout << "|  6 | Hapus First Data Sepatu      |" << endl;
            cout << "-------------------------------------" << endl;
            cout << "|  7 | Hapus Middle Data Sepatu     |" << endl;
            cout << "-------------------------------------" << endl;
            cout << "|  8 | Hapus Last Data Sepatu       |" << endl;
            cout << "-------------------------------------" << endl;
            cout << "|  9 | Sorting Data Sepatu          |" << endl;
            cout << "-------------------------------------" << endl;
            cout << "| 10 | Fibonacci Searching          |" << endl;
            cout << "-------------------------------------" << endl;
            cout << "| 11 | Boyer-Moore Searching        |" << endl;
            cout << "-------------------------------------" << endl;
            cout << "| 12 | Keluar                       |" << endl;
            cout << "-------------------------------------" << endl;
            cout << "Pilih menu: ";
            cin >> pilihan;
            // Jika cin mengalami error (misalnya pengguna memasukkan huruf)
            if (cin.fail())
            {
                throw "Masukan harus berupa angka!";
            }

            if (pilihan < 1 || pilihan > 12)
            {
                throw "Pilihan menu tidak valid!";
            }

            system("cls");

            // CRUD DALAM DATA DAN JULAH SEPATU

            switch (pilihan)
            {
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
                int criteria;
                bool ascending;
                int order;
                cout << "-----------------------------" << endl;
                cout << "|  Pilih kriteria sorting:  |" << endl;
                cout << "-----------------------------" << endl;
                cout << "| 1. | Merk                 |" << endl;
                cout << "-----------------------------" << endl;
                cout << "| 2. | Ukuran               |" << endl;
                cout << "-----------------------------" << endl;
                cout << "| 3. | Harga                |" << endl;
                cout << "-----------------------------" << endl;
                cout << "Pilihan Anda: ";
                cin >> criteria;

                if (cin.fail() || criteria < 1 || criteria > 3)
                {
                    throw "Pilihan kriteria tidak valid!";
                }

                cout << "-----------------------------" << endl;
                cout << "|  Pilih urutan sorting:    |" << endl;
                cout << "-----------------------------" << endl;
                cout << "| 1. | Ascending            |" << endl;
                cout << "-----------------------------" << endl;
                cout << "| 2. | Descending           |" << endl;
                cout << "-----------------------------" << endl;
                cout << "Pilihan Anda: ";
                cin >> order;

                if (cin.fail() || order < 1 || order > 2)
                {
                    throw "Pilihan urutan tidak valid!";
                }

                ascending = (order == 1);

                head = mergeSort(head, criteria, ascending);
                cout << "Data berhasil diurutkan!" << endl;
                break;

            case 10:
                int searchChoice, searchValue;
                cout << "-----------------------------" << endl;
                cout << "|  Pilih ATRIBUT searching: |" << endl;
                cout << "-----------------------------" << endl;
                cout << "| 1. | Ukuran               |" << endl;
                cout << "-----------------------------" << endl;
                cout << "| 2. | Harga                |" << endl;
                cout << "-----------------------------" << endl;
                cout << "Pilihan Anda: ";
                cin >> searchChoice;

                if (searchChoice == 1)
                {
                    cout << "Masukkan ukuran yang dicari: ";
                    cin >> searchValue;
                    int result = fibonacciSearch(head, searchValue, true);
                    if (result >= 0)
                    {
                        cout << "Ukuran " << searchValue << " ditemukan pada posisi " << result + 1 << endl;
                    }
                    else
                    {
                        cout << "Ukuran " << searchValue << " tidak ditemukan." << endl;
                    }
                }
                else if (searchChoice == 2)
                {
                    cout << "Masukkan harga yang dicari: ";
                    cin >> searchValue;
                    int result = fibonacciSearch(head, searchValue, false);
                    if (result >= 0)
                    {
                        cout << "Harga " << searchValue << " ditemukan pada posisi " << result + 1 << endl;
                    }
                    else
                    {
                        cout << "Harga " << searchValue << " tidak ditemukan." << endl;
                    }
                }
                else
                {
                    cout << "Pilihan tidak valid!" << endl;
                }
                break;

            case 11:
            {
                string searchMerk;
                cout << "Masukkan merk sepatu yang dicari: ";
                cin.ignore(); // Jika sebelumnya Anda menggunakan cin untuk input lain
                getline(cin, searchMerk);

                Node *temp = head;
                int pos = 0;
                bool found = false;
                while (temp)
                {
                    int result = searchBoyerMoore(temp->merk, searchMerk);
                    if (result >= 0)
                    {
                        cout << "Merk " << searchMerk << " ditemukan pada posisi " << pos + 1 << endl;
                        found = true;
                        // Jika Anda ingin menampilkan hanya yang pertama, gunakan break di sini
                    }
                    temp = temp->next;
                    pos++;
                }
                if (!found)
                {
                    cout << "Merk " << searchMerk << " tidak ditemukan." << endl;
                }
                break;
            }

            case 12:
                cout << "'______________________________________________'" << endl;
                cout << "': *             *               *            :'" << endl;
                cout << "':     *                                 *    :'" << endl;
                cout << "':                TERIMA KASIH   *            :'" << endl;
                cout << "':         TELAH BELANJA DI TOKO KAMI        *:'" << endl;
                cout << "':   *                                        :'" << endl;
                cout << "':           *                *        *      :'" << endl;
                cout << "'__*_______*___________________________________'" << endl;
                break;
                cout << "+--------------------------+" << endl;
                cout << "|   Pilihan tidak valid!   |" << endl;
                cout << "+--------------------------+";
            }

            // ERROR HANDLING PADA MENU UTAMA
        }
        catch (const char *error)
        {
            cout << "Error: " << error << endl;
            cin.clear();                                         // Bersihkan error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Menghapus buffer
            system("pause");                                     // Berhenti sejenak untuk membiarkan pengguna membaca pesan kesalahan
            system("cls");
        }

    } while (pilihan != 12);

    return 0;

}
