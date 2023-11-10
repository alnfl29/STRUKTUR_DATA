// cout << "------------------------------------------------\n";
// cout << "|           PROJEK AKHIR STRUKTUR DATA         |\n";
// cout << "------------------------------------------------\n";

// cout << "'______________________________________________'" << endl;
// cout << "': *             *               *            :'" << endl;
// cout << "':     *                                 *    :'" << endl;
// cout << "':                SELAMAT DATANG  *           :'" << endl;
// cout << "':             DI TOKO BARANG ANTIK          *:'" << endl;
// cout << "':   *                                        :'" << endl;
// cout << "':           *                *        *      :'" << endl;
// cout << "'______________________________________________'" << endl;


// cout << "------------------------------------------------\n";
// cout << "|             NAMA ANGGOTA KELOMPOK            |\n";
// cout << "------------------------------------------------\n";
// cout << "|  1. Alif Naufal Fachrian   / 2209106108      |\n";
// cout << "------------------------------------------------\n";
// cout << "|  2. M. Rizky Putra Pratama / 2209106102      |\n";
// cout << "------------------------------------------------\n";
// cout << "|  3. Rangga Kristiawan      / 2209106116      |\n";
// cout << "------------------------------------------------\n";


// -----------------------------------------------------------------
// |                     URUTAN CODINGAN                           |
// -----------------------------------------------------------------

// -----------------------------------------------------------------
// | 1.   INCLUDE YANG DI PAKE                                     |
// -----------------------------------------------------------------
// | 2.   LOGIN ADMIN = USERNAME DAN PASSWOR ADMIN                 |
// -----------------------------------------------------------------
// | 3.   STRUCT BARANG                                            |
// -----------------------------------------------------------------
// | 4.   STRUCT USER                                              |
// -----------------------------------------------------------------
// | 5.   STRUCT PEMBELI                                           |
// -----------------------------------------------------------------
// | 6.   NODE BARANG                                              |
// -----------------------------------------------------------------
// | 7.   FUNGSI GLOBAL                                            |
// -----------------------------------------------------------------
// | 8.   HAPUS AKUN USER MENGGUNAKAN DEQUEUE                      |
// -----------------------------------------------------------------
// | 9.   FUNGSI REGISTER USERNAME TIDAK BISA SAMA                 |
// -----------------------------------------------------------------
// | 10.  FUNGSI REGISTER PADA USER                                |
// -----------------------------------------------------------------
// | 11.  FUNGSI LOGIN ADMIN ATAU USER                             |
// -----------------------------------------------------------------
// | 12.  FUNGSI KETIKA ID TIDAK BISA SAMA INPUT DATA BARANG       |
// -----------------------------------------------------------------
// | 13.  INPUT DATA BARANG                                        |
// -----------------------------------------------------------------
// | 14.  CLASS PADA DOUBLE LINKED LIST YANG DI GUNAKAN            |
// -----------------------------------------------------------------
// | 15.  FUNGSI YANG DI GUNAKAN DALAM DOUBLE LINKED LIST          |
// -----------------------------------------------------------------
// | 16.  FUNGSI MEMBELI BARANG PADA MENU USER                     |
// -----------------------------------------------------------------
// | 17.  FUNGSI TAMPILAN DATA USER REGISTRATION PADA MENU ADMIN   |
// -----------------------------------------------------------------
// | 18.  FUNGSI TAMPILAN STRUK BELANJA PADA USER                  |
// -----------------------------------------------------------------
// | 19.  CREATE                                                   |
// |    19_A  TAMBAH DATA DI AWAL BARANG                           |
// |    19_B   TAMBAH DATA DI TENGAH BARANG                        |
// |    19_C  TAMBAH DATA DI AKHIR BARANG                          |
// -----------------------------------------------------------------
// | 20.  READ                                                     |
// |    20_A  TAMPILAN DATA BARANG                                 |
// |    20_B        HEADER TABEL                                   |
// |    20_C       TAMPILAN DATA BARANG                            |
// -----------------------------------------------------------------
// | 21.        UPDATE                                             |
// -----------------------------------------------------------------
// | 22.         DELETE                                            |
// |    22_A       HAPUS DATA AWAL BARANG                          |
// |    22_B    HAPUS DATA YANG BERADA DI TENGAH BARANG            |
// |    22_C      HAPUS DATA AKHIR BARANG                          |
// -----------------------------------------------------------------
// | 23.    SORTING                                                |
// |    23_A      SORTING TAMPILAN DATA MENGGUNAKAN QUICK SORT     |
// |    23_B      FUNGSI UTAMA DI QUICK SORT                       |
// -----------------------------------------------------------------
// | 24.  SEARCHNG                                                 |
// -----------------------------------------------------------------
// | 25.  INT MAIN DAN CASE PADA PROGRAM                           |
// ----------------------------------------------------------------
// | 26.  TAMPILAN DATA BARANG TETAP                               |
// -----------------------------------------------------------------
// | 27.  TAMPILAN PADA MENU AWAL                                  |
// -----------------------------------------------------------------
// | 28.  TAMPILAN PADA MENU ADMIN                                 |
// -----------------------------------------------------------------
// | 29.  TAMPILAN PADA MENU USER                                  |
// -----------------------------------------------------------------
// | 30.  TAMPILAN PADA MENU KELUAR                                |
// -----------------------------------------------------------------



// ------------------------------
// | 1.  INCLUDE YANG DI PAKE   |
// ------------------------------
#include <iostream>     // Library standar untuk masukan/keluaran.
#include <string>       // Library untuk bekerja dengan tipe data string.
#include <iomanip>      // Library untuk mengatur tampilan output, seperti lebar kolom.
#include <limits>       // Library untuk mengakses batasan nilai tipe data (misalnya, batas nilai integer).
#include <stack>        // Library untuk struktur data tumpukan (stack).
#include <queue>        // Library untuk struktur data antrian (queue).
#include <set>          // Library untuk deklarasi objek set untuk menyimpan nilai integer unik yang terurut
#include <conio.h>      // Library untuk menggunakan getch() (Windows only)
using namespace std;



// --------------------------------------------------
// | 2.  LOGIN ADMIN = USERNAME DAN PASSWOR ADMIN   |
// --------------------------------------------------
const string ADMIN_USERNAME = "admin"; 
const string ADMIN_PASSWORD = "admin";

// const: Kata kunci ini digunakan untuk mendeklarasikan sebuah konstanta 
// string: Ini menentukan tipe dari variabel ADMIN_USERNAME dan ADMIN_PASSWORD



// ------------------------------
// | 3.    STRUCT BARANG        |
// ------------------------------
struct BarangAntik
{
    int id;
    string nama_barang;
    int tahun_pembuatan;
    double harga;
    string deskripsi;
};



// ------------------------------
// | 4.     STRUCT USER         |
// ------------------------------
struct User
{
    string username;
    string password;
    string userType; // "admin" atau "user"
};



// ------------------------------
// | 5.    STRUCT PEMBELI       |
// ------------------------------
struct Pembelian
{
    int idBarang;
    string namaBarang;
    double harga;
    string usernamePembeli;
};



// ------------------------------
// | 6.     NODE BARANG         |
// ------------------------------
struct Node
{
    BarangAntik data;
    Node *prev;
    Node *next;
};



// ------------------------------
// | 7.     FUNGSI GLOBAL       |
// ------------------------------
queue<User> users; // Deklarasi antrian (queue) "users" yg bakal digunakan untuk menyimpan objek User.
std::stack<Pembelian> riwayatPembelianStack; // Deklarasi tumpukan (stack) "riwayatPembelianStack" yang bakal digunakan untuk menyimpan objek Pembelian.
std::set<int> myExistingIDs; // Membuat objek set<int>
std::set<int>& existingIDs = myExistingIDs; // Menginisialisasi referensi ke objek input barang dengan ID tidak boleh sama menggunakan set<int>



// -----------------------------------------------
// | 8.   HAPUS AKUN USER MENGGUNAKAN DEQUEUE    |
// -----------------------------------------------
void dequeueUser()
{
    if (users.empty()) // Memeriksa apakah antrian users kosong.
    {
        cout << "Antrian user kosong, tidak ada user untuk di-dequeue.\n";
        return;
    }

    User removedUser = users.front();
    users.pop(); // Menghapus elemen pertama (front) dari antrian users dan menyimpannya dalam "removedUser".
    cout << "User " << removedUser.username << " telah di-dequeue dari antrian.\n";
    cout << "+--------------------------------------+" << endl;
    cout << "|          Registrasi Berhasil         |" << endl;
    cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
    cout << "+--------------------------------------+";
    cin.ignore();
    cin.get();
    system("cls"); //biar layar bersih seperti masa depan
}



// ----------------------------------------------------
// | 9.   FUNGSI REGISTER USERNAME TIDAK BISA SAMA    |
// ----------------------------------------------------
bool username_tidak_bisa_sama(const string &username)
{
    queue<User> tempQueue = users; // Salin antrian untuk pemeriksaan
    while (!tempQueue.empty())
    {
        if (tempQueue.front().username == username)
        {
            return true; // Username ditemukan
        }
        tempQueue.pop();
    }
    return false; // Username tidak ditemukan
}



// --------------------------------------
// | 10.   FUNGSI REGISTER PADA USER    |
// --------------------------------------
void registerUser()
{
    User newUser;
    cout << "Masukkan Username: ";
    cin >> newUser.username;

    // Periksa apakah username sudah ada
    if (username_tidak_bisa_sama(newUser.username))
    {
        cout << "+------------------------------------------+" << endl;
        cout << "|  Register Gagal Username sudah digunakan |" << endl;
        cout << "|        Silakan coba username lain        |" << endl;
        cout << "+------------------------------------------+" << endl;

        cout << "+------------------------------------------+" << endl;
        cout << "|    Tekan enter untuk kembali ke menu...  |" << endl;
        cout << "+------------------------------------------+";
        cin.ignore();
        cin.get();
        return; // Keluar dari fungsi jika username sudah ada
    }

    cout << "Masukkan Password: ";
    cin >> newUser.password;
    users.push(newUser);
    cout << "+--------------------------------------+" << endl;
    cout << "|          Registrasi Berhasil         |" << endl;
    cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
    cout << "+--------------------------------------+";
    cin.ignore();
    cin.get();
    system("cls");
}



// ----------------------------------------
// | 11.  FUNGSI LOGIN ADMIN ATAU USER    |
// ----------------------------------------
User *loginUser(bool &isAdmin) {
    string username;
    string password;
    cout << "Masukkan Username: ";
    cin >> username;

    cout << "Masukkan Password: ";
    char ch;
    password = "";
    while ((ch = _getch()) != 13) { // Loop hingga user menekan Enter (kode ASCII 13)
        if (ch == 8) { // Jika user menekan Backspace
            if (password.length() > 0) {
                cout << "\b \b"; // Menghapus karakter dari layar
                password = password.substr(0, password.length() - 1);
            }
        } else {
            cout << '*'; // Menampilkan tanda bintang (*) sebagai ganti karakter password
            password += ch;
        }
    }

    // Cek apakah ini login admin
    if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD)
    {
        isAdmin = true;
        return NULL; // Karena admin bukan bagian dari queue users
    }
    // Membuat antrian sementara tempQueue dan pointer "userFound".
    queue<User> tempQueue;
    User *userFound = NULL;

    while (!users.empty())
    {
        User &currentUser = users.front(); // Mendapatkan referensi ke user saat ini dalam antrian.
        if (currentUser.username == username && currentUser.password == password) // Memeriksa apakah username dan password cocok dengan user saat ini.
        {
            isAdmin = false;
            userFound = &currentUser;
            cout << "                                        " << endl;
            cout << "+--------------------------------------+" << endl;
            cout << "|          Login Berhasil!!!           |" << endl;
            cout << "+--------------------------------------+" << endl;
            cout << "|  Tekan enter untuk melanjutkan...    |" << endl;
            cout << "+--------------------------------------+" << endl;
            cin.ignore();
            cin.get();
        }
        tempQueue.push(currentUser); // Memasukkan user saat ini ke dalam antrian sementara tempQueue.
        users.pop(); // Menghapus user saat ini dari antrian (queue) users.
    }

    // Mengembalikan user ke queue asli
    while (!tempQueue.empty())
    {
        users.push(tempQueue.front());
        tempQueue.pop();
    }

    if (!userFound) // Mengecek Jika user tidak ditemukan.
    {
        cout << "                                        " << endl;
        cout << "+--------------------------------------+" << endl;
        cout << "|              Login Gagal!!!          |" << endl;
        cout << "+--------------------------------------+" << endl;
        cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
        cout << "+--------------------------------------+";
        cin.ignore();
        cin.get();
    }
    return userFound; // Mengembalikan pointer ke user yang berhasil login (atau NULL jika admin).
}



// -----------------------------------------------------------------
// | 12.  FUNGSI KETIKA ID TIDAK BISA SAMA INPUT DATA BARANG       |
// -----------------------------------------------------------------
bool ID_Tidak_Bisa_Sama(const std::set<int>& existingIDs, int id) {
    return existingIDs.find(id) != existingIDs.end();
}



// --------------------------------
// | 13.  INPUT DATA BARANG       |
// --------------------------------
BarangAntik inputBarang(std::set<int>& existingIDs) {
    BarangAntik barang;

    std::cout << "Masukkan ID (angka): ";
    while (!(std::cin >> barang.id) || ID_Tidak_Bisa_Sama(existingIDs, barang.id)) {
        if (ID_Tidak_Bisa_Sama(existingIDs, barang.id)) {
            std::cout << "ID sudah ada. Masukkan ID lain: ";
        } else {
            std::cout << "Input tidak valid. Masukkan angka: ";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    existingIDs.insert(barang.id);

    std::cin.ignore(); 

    std::cout << "Masukkan Nama Barang: ";
    std::getline(std::cin, barang.nama_barang);

    std::cout << "Masukkan Tahun Pembuatan (angka): ";
    while (!(std::cin >> barang.tahun_pembuatan)) {
        std::cout << "Input tidak valid. Masukkan angka: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Masukkan Harga (angka): ";
    while (!(std::cin >> barang.harga)) {
        std::cout << "Input tidak valid. Masukkan angka: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cin.ignore(); 

    std::cout << "Masukkan Deskripsi: ";
    std::getline(std::cin, barang.deskripsi);

    return barang;
}



// -------------------------------------------------------------
// | 14.    CLASS PADA DOUBLE LINKED LIST YANG DI GUNAKAN      |
// -------------------------------------------------------------
class DoubleLinkedList
{
private:
    Node *head; // Pointer ke elemen pertama dalam Double Linklist.
    Node *tail; // Pointer ke elemen terakhir dalam Double Linklist.



// -----------------------------------------------------------
// | 15.   FUNGSI YANG DI GUNAKAN DALAM DOUBLE LINKED LIST   |
// -----------------------------------------------------------
public:
    DoubleLinkedList() : head(NULL), tail(NULL) {}

    void Tambah_Data_Awal(BarangAntik barang);
    void Tambah_Data_Tengah(int id, BarangAntik barang);
    void Tambah_Data_Akhir(BarangAntik barang);
    void Hapus_Data_Awal();
    void Hapus_Data_Tengah(int id);
    void Hapus_Data_Akhir();
    void Tampilan_data_barang();
    void Update_data_barang(int id, BarangAntik newBarang);
    void Membeli_barang(int id, const string &username);
    void Sorting_Tahun_Pembuatan(bool ascending);
    void Searching_Nama_Barang(const string& name);
};



// --------------------------------------------------
// | 16.    FUNGSI MEMBELI BARANG PADA MENU USER    |
// --------------------------------------------------
void DoubleLinkedList::Membeli_barang(int id, const string &username)
{
    Node *temp = head;
    while (temp != NULL) // Iterasi melalui daftar barang.
    {
        if (temp->data.id == id)
        {
            // Rekam pembelian
            Pembelian pembelian = {temp->data.id, temp->data.nama_barang, temp->data.harga, username}; // Membuat objek "Pembelian" dan menginisialisasi dengan detail pembelian.
            riwayatPembelianStack.push(pembelian); // Menambahkan pembelian ke stack "riwayatPembelianStack".

            if (temp->prev) // Menghapus node dari linked list (daftar barang).
            {
                temp->prev->next = temp->next;
            }
            else
            {
                head = temp->next; // Jika temp adalah head
            }

            if (temp->next)
            {
                temp->next->prev = temp->prev;
            }
            else
            {
                tail = temp->prev; // Jika temp adalah tail
            }

            delete temp; // Menghapus temp yang sudah tidak diperlukan.
            cout << "Barang dengan ID " << id << " berhasil dibeli.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Barang dengan ID " << id << " tidak ditemukan.\n";
}



// ---------------------------------------------------------------------------
// | 17.     FUNGSI TAMPILAN DATA USER YANG REGISTRATION PADA MENU ADMIN     |
// ---------------------------------------------------------------------------
void Tampilkan_User()
{
    if (users.empty()) //untuk mengecek jika antria kosong atau tidak
    {
        cout << "Tidak ada user yang terdaftar.\n";
        return; //jika tidak ada maka system akan mengembalikan(return) dari fungsi
    }

    const int usernameWidth = 20; //ini untuk mengatur lebar kolom pada username di tampilan  
    queue<User> tempQueue; //membuat sebuah antrian sementara dan menyimpan salinan data pengguna dari antrian

    cout << "\nDaftar User Terdaftar:\n";
    cout << "+" << string(usernameWidth, '-') << "+\n";
    cout << "| " << left << setw(usernameWidth - 2) << "Username"
         << " |\n";
    cout << "+" << string(usernameWidth, '-') << "+\n";
        //mencetak baris pemisah dengan lebar yang sesuai dengan usernameWidth
    while (!users.empty())
    {
        User currentUser = users.front(); //program mengambil data pengguna pertama dari antrian users menggunakan front(), program mengambil data pengguna pertama dari antrian users menggunakan front()
        cout << "| " << left << setw(usernameWidth - 2) << currentUser.username << " |\n"; //untuk menampilkan 
        users.pop(); // Setelah user ditampilkan user tersebut dihapus dari antrian users dengan menggunakan pop(), dan dipindahkan ke antrian sementara tempQueue
        tempQueue.push(currentUser); //data akan disimpan kembali ke antrian tempQueue, ini agar urutan data pengguna di antrian sementara sesuai dengan urutan asli di antrian users
    }

    cout << "+" << string(usernameWidth, '-') << "+\n"; // untuk menampilkan 

    // Mengembalikan user ke queue asli
    while (!tempQueue.empty()) //ini akan mengeloop dan berjalan selama antrian sementara tempQueue masih berisi elemen
    {
        users.push(tempQueue.front());// selama loop, elemen pertama dari antrian sementara (tempQueue) diambil menggunakan front(), dan di kembalikan ke antrian users menggunakan push()
        tempQueue.pop(); //ini di gunakan untuk menghapus antrian sementara, setelah data di pindah ke antrian Users
    }
}



// ---------------------------------------------------------------------------
// |  18.          FUNGSI TAMPILAN STRUK BELANJA PADA USER                   |
// ---------------------------------------------------------------------------
void Struk_Belanja_Users(const string &username)
{
    std::stack<Pembelian> tempStack; // Stack sementara untuk menyimpan data saat pop 
    bool found = false; // untuk menandai apakah riwayat pembelian pengguna dengan username tertentu ditemukan atau tidak, awalnya di atur sebagai false
    double totalHarga = 0.0;//digunakan untuk menghitung total harga pembelian, Nilai awalnya diatur sebagai 0.0

    // Setup tampilan
    cout << "\nRiwayat Pembelian untuk " << username << ":\n";
    cout << "+----------+------------------------------+-------------------+\n";
    cout << "| ID Barang| Nama Barang                  | Harga             |\n";
    cout << "+----------+------------------------------+-------------------+\n";

    // Proses stack
    while (!riwayatPembelianStack.empty()) //ini adalah loop yang bakal terus berjalan selama riwayat pembelian gak kosong
    {
        Pembelian pembelian = riwayatPembelianStack.top();//mengambil elemen paling atas (top) dari stack, dan menyimpannya dalam variabel pembelian (peeking)
        riwayatPembelianStack.pop();//Setelah mengambil elemen teratas, elemen tersebut dihapus dari stack.

        if (pembelian.usernamePembeli == username)//untuk mengecek username sama atau tidak dengan yang di gunakan
        {
            // Tampilkan pembelian
            cout << "| " << left << setw(9) << pembelian.idBarang
                 << "| " << setw(29) << pembelian.namaBarang
                 << "| " << right << setw(13) << fixed << setprecision(2) << pembelian.harga << " IDR |\n";
            totalHarga += pembelian.harga; //untuk menghitung total harga pembelian, dan total akan di save ke totalHarga
            found = true;
        }

        tempStack.push(pembelian); // Simpan di stack sementara
    }

    // Mengembalikan data ke stack asli
    while (!tempStack.empty()) //loop yang di gunakan untuk mengenbalikan element ke riwayatPembelianStack
    {
        riwayatPembelianStack.push(tempStack.top());
        tempStack.pop();
    }

    if (!found) //program melakukan pemeriksaan dengan kondisi if (!found). Jika found masih false artinya gak ada pembelian yang sesuai dengan username yang diproses.
    {
        cout << "|                       Tidak ada riwayat pembelian                       |\n";
    }
    else
    {
        cout << "+----------+------------------------------+-------------------+\n";
        cout << "| Total    |                              | " << right << setw(13) << fixed << setprecision(2) << totalHarga << " IDR |\n";
    }
    cout << "+----------+------------------------------+-------------------+\n";
}



// ------------------------------
// | 19.         CREATE         |
// ------------------------------

// ---------------------------------------
// | 19_A  TAMBAH DATA DI AWAL BARANG    |
// ---------------------------------------
void DoubleLinkedList::Tambah_Data_Awal(BarangAntik barang)//untuk menambah element baru ke depan 
{
    Node *newNode = new Node{barang, NULL, head};
    if (head)
    {
        head->prev = newNode;
    }
    else
    {
        tail = newNode;
    }
    head = newNode;
}



// ------------------------------------------
// | 19_B   TAMBAH DATA DI TENGAH BARANG    |
// ------------------------------------------
void DoubleLinkedList::Tambah_Data_Tengah(int id, BarangAntik barang)
{
    // Memeriksa apakah daftar kosong. Jika ya, maka tambahkan barang ke depan.
    if (!head)
    {
        Tambah_Data_Awal(barang);
        return;
    }
    // Inisialisasi pointer sementara (temp) untuk mengiterasi melalui daftar.
    Node *temp = head;
    while (temp)
    {
        // Memeriksa apakah ID pada node saat ini sama dengan ID yang diinginkan.
        if (temp->data.id == id)
        {
            // Membuat node baru dengan data barang yang akan ditambahkan.
            // Mengatur pointer 'prev' dan 'next' dari node baru sesuai dengan node saat ini dan node berikutnya.
            Node *newNode = new Node{barang, temp, temp->next};
            if (temp->next) // Memeriksa apakah ada node setelah node saat ini. Jika ya, mengatur 'prev' dari node berikutnya.
            {
                temp->next->prev = newNode;
            }
            else
            {
                tail = newNode; // Jika node saat ini adalah node terakhir, maka mengatur tail ke newNode.
            }
            temp->next = newNode; // Mengatur 'next' dari node saat ini untuk menunjuk ke newNode.
            return;
        }
        temp = temp->next;
    }
    cout << "Barang dengan ID " << id << " tidak ditemukan.\n";
}



// -----------------------------------------
// | 19_C  TAMBAH DATA DI AKHIR BARANG     |
// -----------------------------------------
void DoubleLinkedList::Tambah_Data_Akhir(BarangAntik barang)
{
    // Membuat node baru (newNode) dengan data barang dan mengatur prev dan next ke NULL.
    Node *newNode = new Node{barang, NULL, NULL};
    if (!head) // Memeriksa apakah daftar kosong. Jika ya, maka newNode akan menjadi elemen pertama dan terakhir.
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;// Jika daftar tidak kosong, maka mengatur 'next' dari node terakhir (tail) untuk menunjuk ke newNode.
        newNode->prev = tail;// Mengatur 'prev' dari newNode untuk menunjuk ke node terakhir (tail).
        tail = newNode;// Mengatur tail untuk menunjuk ke newNode, menjadikannya elemen terakhir dalam daftar.
    }
}



// -------------------------------
// | 20.         READ            |
// -------------------------------

// ---------------------------------
// | 20_A  TAMPILAN DATA BARANG    |
// ---------------------------------

void DoubleLinkedList::Tampilan_data_barang()
{
    if (!head)// Memeriksa apakah daftar kosong. 
    {
        cout << "Tidak ada barang untuk ditampilkan.\n";
        return;
    }

    // Menentukan lebar (width) dari kolom untuk tampilan data barang.
    const int idWidth = 9;
    const int nameWidth = 20;
    const int yearWidth = 16;
    const int priceWidth = 17;
    const int descWidth = 45;

// ---------------------------------------
// | 20_B        HEADER TABEL            |
// ---------------------------------------

    cout << "+" << string(idWidth, '-') << "-+-" << string(nameWidth, '-') << "+-" << string(yearWidth, '-') << "+-" << string(priceWidth, '-') << "+-" << string(descWidth, '-') << "-+\n";
    cout << "| " << left << setw(idWidth) << "ID"
         << "| " << setw(nameWidth) << "Nama Barang"
         << "| " << setw(yearWidth) << "Tahun Pembuatan"
         << "| " << setw(priceWidth) << "Harga (IDR)"
         << "| " << setw(descWidth) << "Deskripsi"
         << " |\n";
    cout << "+" << string(idWidth, '-') << "-+-" << string(nameWidth, '-') << "+-" << string(yearWidth, '-') << "+-" << string(priceWidth, '-') << "+-" << string(descWidth, '-') << "-+\n";


// ------------------------------------------
// | 20_C       TAMPILAN DATA BARANG        |
// ------------------------------------------
    // Inisialisasi pointer sementara (temp) untuk mengiterasi melalui daftar.
    Node *temp = head;
    while (temp)
    {
        cout << "+" << string(idWidth, '-') << "-+-" << string(nameWidth, '-') << "+-" << string(yearWidth, '-') << "+-" << string(priceWidth, '-') << "+-" << string(descWidth, '-') << "-+\n";
        cout << "| " << left << setw(idWidth) << temp->data.id
             << "| " << setw(nameWidth) << temp->data.nama_barang.substr(0, nameWidth)
             << "| " << setw(yearWidth) << temp->data.tahun_pembuatan
             << "| " << right << setw(priceWidth - 4) << fixed << setprecision(2) << temp->data.harga << " IDR"
             << "| " << left << setw(descWidth) << temp->data.deskripsi.substr(0, descWidth) << " |\n";
        temp = temp->next; // Pindah ke node berikutnya.
    }
    cout << "+" << string(idWidth, '-') << "-+-" << string(nameWidth, '-') << "+-" << string(yearWidth, '-') << "+-" << string(priceWidth, '-') << "+-" << string(descWidth, '-') << "-+\n";
}



// --------------------------------
// | 21.        UPDATE            |
// --------------------------------

// -----------------------------------
// |        UPDATE DATA BARANG       |
// -----------------------------------
void DoubleLinkedList::Update_data_barang(int id, BarangAntik newBarang)
{
    // Inisialisasi pointer sementara (temp) untuk mengiterasi melalui daftar.
    Node *temp = head;
    while (temp)
    {
        if (temp->data.id == id) // Memeriksa apakah ID dari barang pada node saat ini sesuai dengan ID yang diinginkan.
        {
            temp->data = newBarang; // Jika ID sesuai, maka update data barang pada node saat ini dengan data baru (newBarang).

            // Tampilkan pesan sukses di sini.
            cout << "+---------------------------------------------+" << endl;
            cout << "|  Data Barang Berhasil Di Update             |" << endl;
            cout << "|  Barang dengan ID " << id << " telah diperbarui        |" <<endl;
            cout << "+---------------------------------------------+" << endl;
            cout << "                                               " << endl;

            return;
        }
        temp = temp->next; // Pindah ke node berikutnya.
    }

    // Jika sampai di sini, berarti barang tidak ditemukan.
    cout << "+---------------------------------------------+" << endl;
    cout << "|  Data Barang Tidak Berhasil Di Update       |" << endl;
    cout << "|  Barang dengan ID " << id << " tidak ditemukan         |" <<endl;
    cout << "+---------------------------------------------+" << endl;
    cout << "                                               " << endl;
}



// ---------------------------------
// | 22.         DELETE            |
// ---------------------------------

// -------------------------------------------
// | 22_A       HAPUS DATA AWAL BARANG       |
// -------------------------------------------
void DoubleLinkedList::Hapus_Data_Awal()
{
    if (!head) // Memeriksa apakah daftar kosong
        return;

    Node *temp = head; // Inisialisasi pointer sementara (temp) untuk menunjuk ke node pertama (head).
    head = head->next; // Mengubah head untuk menunjuk ke node berikutnya sebagai elemen pertama baru.
    if (head) // Memeriksa apakah masih ada node lain setelah perubahan head.
    {
        head->prev = NULL; // Jika ada, mengatur prev dari elemen pertama baru menjadi NULL.
    }
    else
    {
        tail = NULL; // Jika tidak ada elemen lain dalam daftar, mengatur tail menjadi NULL.
    }
    delete temp; // Menghapus node pertama (temp).
}



// ------------------------------------------------------
// | 22_B    HAPUS DATA YANG BERADA DI TENGAH BARANG    |
// ------------------------------------------------------
void DoubleLinkedList::Hapus_Data_Tengah(int id)
{
    if (!head) // Memeriksa apakah daftar kosong. Jika ya, tampilkan pesan dan kembali.
    {
        cout << "List kosong, tidak ada yang bisa dihapus.\n";
        return;
    }

    Node *temp = head; // Inisialisasi pointer sementara (temp) untuk mengiterasi melalui daftar.
    while (temp)
    {
        if (temp->data.id == id) // Memeriksa apakah ID dari barang pada node saat ini sesuai dengan ID yang diinginkan.
        {
            if (temp->prev) // Memeriksa apakah ada node sebelum node saat ini.
            {
                temp->prev->next = temp->next; // Jika ada, mengatur next dari node sebelumnya untuk mengarah ke node setelah node saat ini.
            }
            else
            {
                head = temp->next; // Jika node saat ini adalah elemen pertama, maka mengubah head untuk menunjuk ke node berikutnya.
            }

            if (temp->next) // Memeriksa apakah ada node setelah node saat ini.
            {
                temp->next->prev = temp->prev; // Jika ada, mengatur prev dari node setelah node saat ini untuk mengarah ke node sebelumnya.
            }
            else
            {
                tail = temp->prev; // Jika node saat ini adalah elemen terakhir, maka mengubah tail untuk menunjuk ke node sebelumnya.
            }

            delete temp; // Menghapus node saat ini.
            return;
        }
        temp = temp->next; // Pindah ke node berikutnya.
    }
    cout << "Barang dengan ID " << id << " tidak ditemukan.\n";
}



// --------------------------------------------
// | 22_C      HAPUS DATA AKHIR BARANG        |
// --------------------------------------------
void DoubleLinkedList::Hapus_Data_Akhir()
{
    if (!tail) // Memeriksa apakah daftar kosong. 
        return;

    Node *temp = tail; // Inisialisasi pointer sementara (temp) untuk menunjuk ke elemen terakhir (tail).
    tail = tail->prev; // Mengubah tail untuk menunjuk ke elemen sebelumnya sebagai elemen terakhir yang baru.
    if (tail) // Memeriksa apakah masih ada elemen lain sebelum perubahan tail.
    {
        tail->next = NULL; // Jika ada, mengatur next dari elemen terakhir yang baru untuk mengarah ke NULL.
    }
    else
    {
        head = NULL; // Jika tidak ada elemen lain dalam daftar, mengatur head menjadi NULL.
    }
    delete temp; // Menghapus elemen terakhir (temp).
}



// ------------------------
// | 23.    SORTING      |
// -----------------------

// ----------------------------------------------------------------
// | 23_A      SORTING TAMPILAN DATA MENGGUNAKAN QUICK SORT       |
// ----------------------------------------------------------------


// Fungsi ini digunakan untuk mendapatkan node terakhir dalam doubly linked list.
// - head: Node pertama dalam list
// Fungsi ini melakukan iterasi melalui list hingga mencapai node terakhir.
Node* getLastNode(Node* head) {
    while (head && head->next) {
        head = head->next;
    }
    return head;
}

// Fungsi partition digunakan dalam algoritma quicksort untuk membagi list menjadi dua bagian berdasarkan elemen pivot.
// - low: Node terendah dalam bagian list yang akan diurutkan
// - high: Node tertinggi dalam bagian list yang akan diurutkan
// - ascending: Boolean yang menentukan apakah pengurutan dilakukan secara ascending (true) atau descending (false)
Node* partition(Node* low, Node* high, bool ascending) {
    // Menentukan pivot sebagai tahun pembuatan dari elemen tertinggi
    double pivot = high->data.tahun_pembuatan;
    Node* i = low->prev;

    for (Node* iterasi = low; iterasi != high; iterasi = iterasi->next) {
        // Membandingkan elemen dengan pivot sesuai dengan urutan yang ditentukan
        if ((ascending && iterasi->data.tahun_pembuatan <= pivot) || (!ascending && iterasi->data.tahun_pembuatan >= pivot)) {
            // Jika elemen lebih kecil atau lebih besar dari pivot, tukar posisinya dengan elemen di "low"
            i = (i == NULL) ? low : i->next;
            swap(i->data, iterasi->data);
        }
    }

    // Tukar posisi elemen pivot dengan elemen "i" (posisi yang tepat dalam urutan yang diinginkan)
    i = (i == NULL) ? low : i->next;
    swap(i->data, high->data);

    return i; // Mengembalikan posisi elemen pivot yang sudah benar
}


// ----------------------------------------------
// | 23_B      FUNGSI UTAMA DI QUICK SORT       |
// ----------------------------------------------
// Fungsi quickSort digunakan untuk mengurutkan elemen-elemen dalam doubly linked list
// dengan menggunakan algoritma quicksort.
// - low: Node terendah dalam bagian list yang akan diurutkan
// - high: Node tertinggi dalam bagian list yang akan diurutkan
// - ascending: Boolean yang menentukan apakah pengurutan dilakukan secara ascending (true) atau descending (false)
void quickSort(Node* low, Node* high, bool ascending) {
    // Pengecekan apakah list valid dan dapat diurutkan
    if (high != NULL && low != high && low != high->next) {
        // Mencari pivot dan membagi list menjadi dua bagian
        Node* p = partition(low, high, ascending);

        // Memanggil rekursif quickSort untuk bagian kiri dan kanan dari pivot
        quickSort(low, p->prev, ascending);
        quickSort(p->next, high, ascending);
    }
}

// Fungsi sortItems digunakan untuk memulai proses pengurutan doubly linked list.
// - ascending: Boolean yang menentukan apakah pengurutan dilakukan secara ascending (true) atau descending (false)
void DoubleLinkedList::Sorting_Tahun_Pembuatan(bool ascending) {
    // Pengecekan apakah list kosong
    if (!head) {
        cout << "List kosong, tidak ada yang bisa di-sort.\n";
        return;
    }

    // Mencari node terakhir dalam list
    Node* lastNode = getLastNode(head);

    // Memanggil fungsi quickSort untuk mengurutkan seluruh list
    quickSort(head, lastNode, ascending);
}



// -------------------------------
// | 24.       SEARCHNG          |
// -------------------------------

// ------------------------------------------------------------
// |      SEARCHING TAMPILAN DATA MENGGUNAKAN JUMP SEARCH     |
// ------------------------------------------------------------
void DoubleLinkedList::Searching_Nama_Barang(const string& searchNama) {
    Node* temp = head; // Inisialisasi node sementara dari kepala list
    bool found = false; // Penanda apakah ada barang yang ditemukan sesuai dengan pencarian

    // Setup lebar kolom tabel
    const int idWidth = 9;
    const int nameWidth = 20;
    const int yearWidth = 16;
    const int priceWidth = 17;
    const int descWidth = 45;

    // Header tabel
    cout << "\nHasil Pencarian:\n";
    cout << "+" << string(idWidth, '-') << "-+-" << string(nameWidth, '-') << "+-" << string(yearWidth, '-') << "+-" << string(priceWidth, '-') << "+-" << string(descWidth, '-') << "-+\n";
    cout << "| " << left << setw(idWidth) << "ID"
         << "| " << setw(nameWidth) << "Nama Barang"
         << "| " << setw(yearWidth) << "Tahun Pembuatan"
         << "| " << setw(priceWidth) << "Harga (IDR)"
         << "| " << setw(descWidth) << "Deskripsi"
         << " |\n";
    cout << "+" << string(idWidth, '-') << "-+-" << string(nameWidth, '-') << "+-" << string(yearWidth, '-') << "+-" << string(priceWidth, '-') << "+-" << string(descWidth, '-') << "-+\n";

    // Pencarian dan tampilan data
    while (temp) {
        if (temp->data.nama_barang.find(searchNama) != string::npos) {
            // Menampilkan baris tabel hasil pencarian
            cout << "+" << string(idWidth, '-') << "-+-" << string(nameWidth, '-') << "+-" << string(yearWidth, '-') << "+-" << string(priceWidth, '-') << "+-" << string(descWidth, '-') << "-+\n";
            cout << "| " << left << setw(idWidth) << temp->data.id
                 << "| " << setw(nameWidth) << temp->data.nama_barang.substr(0, nameWidth)
                 << "| " << setw(yearWidth) << temp->data.tahun_pembuatan
                 << "| " << right << setw(priceWidth - 4) << fixed << setprecision(2) << temp->data.harga << " IDR"
                 << "| " << left << setw(descWidth) << temp->data.deskripsi.substr(0, descWidth) << " |\n";
            found = true; // Menandai bahwa ada barang yang cocok ditemukan
        }
        temp = temp->next; // Pindah ke node berikutnya dalam list
    }

    if (!found) {
        // Pesan jika tidak ada barang yang cocok ditemukan
        cout << "|                       Tidak ada barang yang cocok                       |\n";
    }
    cout << "+" << string(idWidth, '-') << "-+-" << string(nameWidth, '-') << "+-" << string(yearWidth, '-') << "+-" << string(priceWidth, '-') << "+-" << string(descWidth, '-') << "-+\n";
}



// ----------------------------------------------
// | 25.    INT MAIN DAN CASE PADA PROGRAM      |
// ----------------------------------------------

int main()
{


// ----------------------------------------------
// | 26.      TAMPILAN DATA BARANG TETAP        |
// ----------------------------------------------
    system("cls");
    DoubleLinkedList list;
    list.Tambah_Data_Awal({1, "Jam Saku Patek Philippe", 1890, 1500000.00, "Jam saku emas mewah dari Patek Philippe"});
    list.Tambah_Data_Akhir({2, "Lemari Victorian", 1870, 4500000.00, "Lemari kayu jati bergaya Victorian"});
    list.Tambah_Data_Akhir({3, "Vas Porcelain Ming", 1600, 2000000.00, "Vas porcelain langka dari Dinasti Ming"});
    list.Tambah_Data_Akhir({4, "Lukisan Monet", 1910, 3000000.00, "Lukisan asli Claude Monet, awal abad ke-20"});
    list.Tambah_Data_Akhir({5, "Koin Emas Romawi", 100, 5000000.00, "Koin emas kuno dari masa Kekaisaran Romawi"});
    int mainpilih;



// -----------------------------------------------
// | 27.        TAMPILAN PADA MENU AWAL          |
// -----------------------------------------------
    do
    {
        system("cls");
        cout << "------------------------------------------------\n";
        cout << "|           PROJEK AKHIR STRUKTUR DATA         |\n";
        cout << "------------------------------------------------\n";

        cout << "'______________________________________________'" << endl;
        cout << "': *             *               *            :'" << endl;
        cout << "':     *                                 *    :'" << endl;
        cout << "':                SELAMAT DATANG  *           :'" << endl;
        cout << "':             DI TOKO BARANG ANTIK          *:'" << endl;
        cout << "':   *                                        :'" << endl;
        cout << "':           *                *        *      :'" << endl;
        cout << "'______________________________________________'" << endl;

        cout << "                                     " << endl;
        cout << "-------------------------------------" << endl;
        cout << "|  1 | REGISTRASI                   |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "|  2 | LOGIN                        |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "|  3 | EXIT / KELUAR                |" << endl;
        cout << "-------------------------------------" << endl;

        cout << "Pilih opsi (1-3): ";
        if (!(cin >> mainpilih))
        {
            cin.clear();                                         
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Input tidak valid. Silakan coba lagi.\n";
            cout << "+--------------------------------------+" << endl;
            cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
            cout << "+--------------------------------------+";
            cin.ignore();
            cin.get();
            continue; 
        }

        switch (mainpilih)
        {
        case 1:
            registerUser();
            break;

        case 2:
        {
            bool isAdmin = false;
            User *loggedInUser = loginUser(isAdmin);
            if (loggedInUser || isAdmin)
            {
                if (isAdmin)
                {
                    int pilihanadmin;
                    do
                    {
// ------------------------------------------------
// | 28.        TAMPILAN PADA MENU ADMIN          |
// ------------------------------------------------
                        system("cls");
                        cout << "-------------------------------------" << endl;
                        cout << "|            Menu Admin             |" << endl;
                        cout << "-------------------------------------" << endl;
                        cout << "| 1. | Tambah Barang                |" << endl;
                        cout << "| 2. | Tampilkan Semua Barang       |" << endl;
                        cout << "| 3. | Update Barang                |" << endl;
                        cout << "| 4. | Hapus Barang                 |" << endl;
                        cout << "| 5. | Tampilkan Daftar User        |" << endl;
                        cout << "| 6. | Keluar Dari Menu Admin       |" << endl;
                        cout << "-------------------------------------" << endl;
                        cout << "Pilih opsi (1-6): ";
                        if (!(cin >> pilihanadmin))
                        {
                            cin.clear();                                         
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                            cout << "Input tidak valid. Silakan coba lagi.\n";
                            cout << "+--------------------------------------+" << endl;
                            cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
                            cout << "+--------------------------------------+";
                            cin.ignore();
                            cin.get();
                            system("cls");
                            continue; 
                        }

                        switch (pilihanadmin)
                        {
                        case 1:
                            system("cls");
                            cout << "-------------------------------------" << endl;
                            cout << "|       Pilih Posisi Penambahan     |" << endl;
                            cout << "-------------------------------------" << endl;
                            cout << "| 1. | Di Awal                      |" << endl;
                            cout << "| 2. | Di Tengah ID Tertentu        |" << endl;
                            cout << "| 3. | Di Akhir                     |" << endl;
                            cout << "-------------------------------------" << endl;
                            cout << "Pilih opsi (1-3): ";
                            int addpilihan;
                            cin >> addpilihan;

                            switch (addpilihan)
                            {
                            case 1:
                                list.Tambah_Data_Awal(inputBarang(existingIDs));
                                cout << "+------------------------------------------------+" << endl;
                                cout << "|  Data Barang Berhasil Di Tambahkan Di Awal     |" << endl;
                                cout << "+------------------------------------------------+" << endl;
                                cout << "                                                  " << endl;
                                cout << "+------------------------------------------------+" << endl;
                                cout << "|       Tekan enter untuk kembali ke menu        |" << endl;
                                cout << "+------------------------------------------------+" << endl;
                                cin.ignore();
                                cin.get();
                                break;

                            case 2:
                                cout << "Masukkan ID barang setelah mana item akan ditambahkan: ";
                                int idtambah;
                                cin >> idtambah;
                                list.Tambah_Data_Tengah(idtambah, inputBarang(existingIDs));
                                cout << "+------------------------------------------------+" << endl;
                                cout << "|  Data Barang Berhasil Di Tambahkan Di Tengah   |" << endl;
                                cout << "+------------------------------------------------+" << endl;
                                cout << "                                                  " << endl;
                                cout << "+------------------------------------------------+" << endl;
                                cout << "|       Tekan enter untuk kembali ke menu        |" << endl;
                                cout << "+------------------------------------------------+" << endl;
                                cin.ignore();
                                cin.get();
                                break;

                            case 3:
                                list.Tambah_Data_Akhir(inputBarang(existingIDs));
                                cout << "+------------------------------------------------+" << endl;
                                cout << "|  Data Barang Berhasil Di Tambahkan Di Akhir    |" << endl;
                                cout << "+------------------------------------------------+" << endl;
                                cout << "                                                  " << endl;
                                cout << "+------------------------------------------------+" << endl;
                                cout << "|       Tekan enter untuk kembali ke menu        |" << endl;
                                cout << "+------------------------------------------------+" << endl;
                                cin.ignore();
                                cin.get();
                                break;

                            default:
                                cout << "+-------------------------------------------+" << endl;
                                cout << "|  Pilihan Tidak Valid, Silahkan Coba Lagi  |" << endl;
                                cout << "+-------------------------------------------+" << endl;
                                cout << "                                            " << endl;
                                cout << "+-------------------------------------------+" << endl;
                                cout << "|    Tekan enter untuk kembali ke menu      |" << endl;
                                cout << "+-------------------------------------------+" << endl;
                                cin.ignore();
                                cin.get();
                                break;
                            }
                            break;

                        case 2:
                            cout << "-----------------------------------------------" << endl;
                            cout << "|   Pilih Jenis Sorting Pada Tahun Pembuatan  |" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "| 1. | Tampilkan Data / Tidak di Sorting      |" << endl;
                            cout << "| 2. | Ascending                              |" << endl;
                            cout << "| 3. | Descending                             |" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "Pilih opsi (1-3): ";
                            int sortpilih;
                            cin >> sortpilih;

                            if (sortpilih == 1)
                            {
                                list.Tampilan_data_barang();
                            }
                            else if (sortpilih == 2)
                            {
                                list.Sorting_Tahun_Pembuatan(true); // ASCENDING
                                list.Tampilan_data_barang();
                            }
                            else if (sortpilih == 3)
                            {
                                list.Sorting_Tahun_Pembuatan(false); // DESCENDING
                                list.Tampilan_data_barang();
                            }
                            else
                            {
                                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                            }
                            cout << "+--------------------------------------+" << endl;
                            cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
                            cout << "+--------------------------------------+";
                            cin.ignore();
                            cin.get();
                            break;

                        case 3:
                            system("cls");
                            list.Tampilan_data_barang();
                            cout << "Masukkan ID barang yang ingin diupdate: ";
                            int idubah;
                            cin >> idubah;
                            list.Update_data_barang(idubah, inputBarang(existingIDs));
                            cout << "+--------------------------------------+" << endl;
                            cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
                            cout << "+--------------------------------------+";
                            cin.ignore();
                            cin.get();
                            break;

                        case 4:
                            system("cls");
                            list.Tampilan_data_barang();
                            cout << "-------------------------------------" << endl;
                            cout << "|      Pilih Posisi Penghapusan     |" << endl;
                            cout << "-------------------------------------" << endl;
                            cout << "| 1. | Di Awal                      |" << endl;
                            cout << "| 2. | Di Tengah ID Tertentu        |" << endl;
                            cout << "| 3. | Di Akhir                     |" << endl;
                            cout << "-------------------------------------" << endl;
                            cout << "Pilih opsi (1-3): ";
                            int pilihanhapus;
                            cin >> pilihanhapus;

                            switch (pilihanhapus)
                            {
                            case 1:
                                list.Hapus_Data_Awal();
                                cout << "+--------------------------------------+" << endl;
                                cout << "|  Data Barang sudah terhapus          |" << endl;
                                cout << "+--------------------------------------+" << endl;
                                break;

                            case 2:
                                cout << "Masukkan ID barang yang ingin dihapus: ";
                                int idkedelete;
                                cin >> idkedelete;
                                list.Hapus_Data_Tengah(idkedelete);
                                cout << "+--------------------------------------+" << endl;
                                cout << "|  Data Barang sudah terhapus          |" << endl;
                                cout << "+--------------------------------------+" << endl;
                                break;

                            case 3:
                                list.Hapus_Data_Akhir();
                                cout << "+--------------------------------------+" << endl;
                                cout << "|  Data Barang sudah terhapus          |" << endl;
                                cout << "+--------------------------------------+" << endl;
                                break;

                            default:
                                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                                break;
                            }
                            cout << "+--------------------------------------+" << endl;
                            cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
                            cout << "+--------------------------------------+";
                            cin.ignore();
                            cin.get();
                            break;

                        case 5:
                            system("cls");
                            int pilihanusermenu;
                            do
                            {
                                system("cls");
                                cout << "-------------------------------------" << endl;
                                cout << "|          Menu Daftar User         |" << endl;
                                cout << "-------------------------------------" << endl;
                                cout << "| 1. | Tampilkan Semua User         |" << endl;
                                cout << "| 2. | Dequeue User                 |" << endl;
                                cout << "| 3. | Kembali ke Menu Admin        |" << endl;
                                cout << "-------------------------------------" << endl;
                                cout << "Pilih opsi (1-3): ";
                                if (!(cin >> pilihanusermenu))
                                {
                                    cin.clear();                                         
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                                }

                                switch (pilihanusermenu)
                                {
                                case 1:
                                    Tampilkan_User();
                                    break;
                                case 2:
                                    dequeueUser();
                                    break;
                                case 3:
                                    cout << "Kembali ke Menu Admin.\n";
                                    break;
                                default:
                                    cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                                    break;
                                }
                                cout << "+--------------------------------------+" << endl;
                                cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
                                cout << "+--------------------------------------+";
                                cin.ignore();
                                cin.get();
                            } while (pilihanusermenu != 3);
                            break;

                        case 6:
                            cout << "Keluar dari menu Admin.\n";
                            cout << "+--------------------------------------+" << endl;
                            cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
                            cout << "+--------------------------------------+";
                            cin.ignore();
                            cin.get();
                            break;

                        default:
                            cout << "+-------------------------------------------+" << endl;
                            cout << "|  Pilihan Tidak Valid, Silahkan Coba Lagi  |" << endl;
                            cout << "+-------------------------------------------+" << endl;
                            cout << "                                             " << endl;
                            cout << "+-------------------------------------------+" << endl;
                            cout << "|    Tekan enter untuk kembali ke menu      |" << endl;
                            cout << "+-------------------------------------------+" << endl;
                            break;
                        }
                    } while (pilihanadmin != 6);
                }
                else
                {
                    int userppilih;
                    do
                    {
// ------------------------------------------------
// | 29.        TAMPILAN PADA MENU USER           |
// ------------------------------------------------
                        system("cls");
                        cout << "-------------------------------------" << endl;
                        cout << "|             Menu User             |" << endl;
                        cout << "-------------------------------------" << endl;
                        cout << "| 1. | Tampilkan Semua Barang       |" << endl;
                        cout << "| 2. | Membeli Barang               |" << endl;
                        cout << "| 3. | Struk belanja                |" << endl;
                        cout << "| 4. | Cari Barang Berdasarkan Nama |" << endl;
                        cout << "| 5. | Keluar dari menu User        |" << endl;
                        cout << "-------------------------------------" << endl;
                        cout << "Pilih opsi (1-5): ";
                        if (!(cin >> userppilih))
                        {
                            cin.clear();                                         // Bersihkan stream
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Abaikan input yang salah
                            cout << "Input tidak valid. Silakan coba lagi.\n";
                            cout << "+--------------------------------------+" << endl;
                            cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
                            cout << "+--------------------------------------+";
                            cin.ignore();
                            cin.get();
                            system("cls");
                            continue; // Lanjutkan ke iterasi berikutnya dari loop
                        }

                        switch (userppilih)
                        {
                        case 1:
                            system("cls");
                            cout << "-----------------------------------------------" << endl;
                            cout << "|   Pilih Jenis Sorting Pada Tahun Pembuatan  |" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "| 1. | Tampilkan Data / Tidak di Sorting      |" << endl;
                            cout << "| 2. | Ascending                              |" << endl;
                            cout << "| 3. | Descending                             |" << endl;
                            cout << "-----------------------------------------------" << endl;
                            cout << "Pilih opsi (1-3): ";
                            int sortpilih;
                            cin >> sortpilih;

                            if (sortpilih == 1)
                            {
                                list.Tampilan_data_barang();
                            }
                            else if (sortpilih == 2)
                            {
                                list.Sorting_Tahun_Pembuatan(true); // Ascending
                                list.Tampilan_data_barang();
                            }
                            else if (sortpilih == 3)
                            {
                                list.Sorting_Tahun_Pembuatan(false); // Descending
                                list.Tampilan_data_barang();
                            }
                            else
                            {
                                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                            }
                            cout << "+--------------------------------------+" << endl;
                            cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
                            cout << "+--------------------------------------+";
                            cin.ignore();
                            cin.get();
                            break;
                        case 2:
                            list.Tampilan_data_barang();
                            cout << "Masukkan ID barang yang ingin dibeli: ";
                            int idbeli;
                            cin >> idbeli;
                            list.Membeli_barang(idbeli, loggedInUser->username);
                            cout << "+--------------------------------------+" << endl;
                            cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
                            cout << "+--------------------------------------+";
                            cin.ignore();
                            cin.get();
                            break;
                        case 3:
                            Struk_Belanja_Users(loggedInUser->username);
                            cout << "+--------------------------------------+" << endl;
                            cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
                            cout << "+--------------------------------------+";
                            cin.ignore();
                            cin.get();
                            break;
                        case 4:
                            {
                            cout << "Masukkan nama barang yang ingin dicari: ";
                            string searchNama;
                            cin.ignore();
                            getline(cin, searchNama);
                            list.Searching_Nama_Barang(searchNama);
                            cout << "+--------------------------------------+" << endl;
                            cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
                            cout << "+--------------------------------------+";
                            cin.ignore();
                            cin.get();
                            break;
                            }
                        case 5:
                            cout << "Keluar dari menu User.\n";
                            cout << "+--------------------------------------+" << endl;
                            cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
                            cout << "+--------------------------------------+";
                            cin.ignore();
                            cin.get();
                            break;
                        default:
                            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                            cout << "+--------------------------------------+" << endl;
                            cout << "|  Tekan enter untuk kembali ke menu...|" << endl;
                            cout << "+--------------------------------------+";
                            cin.ignore();
                            cin.get();
                            break;
                        }
                    } while (userppilih != 5);
                }
            }
            break;
        }
// -------------------------------------------------
// | 30.        TAMPILAN PADA MENU KELUAR          |
// -------------------------------------------------
        case 3:
        {
            system("cls");
            cout << "'______________________________________________'" << endl;
            cout << "': *             *               *            :'" << endl;
            cout << "':     *                                 *    :'" << endl;
            cout << "':                TERIMA KASIH   *            :'" << endl;
            cout << "':         TELAH BELANJA DI TOKO KAMI        *:'" << endl;
            cout << "':   *                                        :'" << endl;
            cout << "':           *                *        *      :'" << endl;
            cout << "'_*__*_________________________________________'" << endl;
            break;
        }
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
            break;
        }
    } while (mainpilih != 3);

    return 0;
    
}



// cout << "'______________________________________________'" << endl;
// cout << "': *             *               *            :'" << endl;
// cout << "':     *                                 *    :'" << endl;
// cout << "':                    SEKIAN      *           :'" << endl;
// cout << "':                 TERIMA KASIH              *:'" << endl;
// cout << "':   *                                        :'" << endl;
// cout << "':           *                *        *      :'" << endl;
// cout << "'______________________________________________'" << endl;


