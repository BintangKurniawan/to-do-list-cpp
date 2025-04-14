#include <iostream>
#include <cstdlib>
#include <iomanip>

#include <limits>

using namespace std;

struct list
{
    string id;
    string name;
    string brand;
    float value;
    string category;
    string status;
    string condition;
    int stock;
    list *next;
};

list *head;
list *tail;

int idCounter = 1;

bool isEmpty()
{
    if (head == NULL)
        return true;
    return false;
}

void insertLast(string name, string brand, float value, string category, string status, string condition, int stock)
{
    list *new_list, *current;

    current = head;
    while (current != NULL)
    {
        if (current->name == name && current->brand == brand)
        {
            current->stock += stock;
            cout << "Stok berhasil ditambah ke barang yang sudah ada" << endl;
            return;
        }

        current = current->next;
    }

    new_list = new list();

    new_list->id = "ID" + to_string(idCounter);
    idCounter++;

    new_list->name = name;
    new_list->brand = brand;
    new_list->value = value;
    new_list->category = category;
    new_list->status = status;
    new_list->condition = condition;
    new_list->stock = stock;
    new_list->next = NULL;

    if (isEmpty())
    {
        head = new_list;
        head->next = NULL;
    }
    else
    {
        current = head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_list;
        new_list->next = NULL;
        cout << "Barang berhasil ditambahkan" << endl;
    }
}

void cetakList()
{
    if (!isEmpty())
    {
        list *current = head;

        cout << left
             << setw(20) << "ID Barang"
             << setw(20) << "Nama Barang"
             << setw(15) << "Brand"
             << setw(15) << "Value"
             << setw(20) << "Category"
             << setw(12) << "Status"
             << setw(12) << "Condition"
             << setw(8) << "Stock"
             << endl;

        cout << string(122, '-') << endl;
        while (current != NULL)
        {
            cout << left
                 << setw(20) << current->id
                 << setw(20) << current->name
                 << setw(15) << current->brand
                 << setw(15) << fixed << setprecision(0) << current->value
                 << setw(20) << current->category
                 << setw(12) << current->status
                 << setw(12) << current->condition
                 << setw(8) << current->stock
                 << endl;

            current = current->next;
        }
    }
    else
    {
        cout << "Barang kosong." << endl;
    }
}

string toLower(string str)
{
    for (char &c : str)
    {
        c = tolower(c);
    }
    return str;
}

void cariBarang()
{
    while (true)
    {
        system("cls");
        cetakList();

        string keyword;
        string searchId = "", searchName = "", searchCategory = "", searchStatus = "", searchCondition = "", searchBrand = "";

        cout << endl;
        cout << "Cari barang berdasarkan kriteria berikut:" << endl;
        cout << "1. ID Barang" << endl;
        cout << "2. Nama Barang" << endl;
        cout << "3. Kategori" << endl;
        cout << "4. Status" << endl;
        cout << "5. Kondisi" << endl;
        cout << "6. Brand" << endl;
        cout << "7. Semua kriteria (multi-criteria)" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilih kriteria pencarian (masukkan angka): ";

        int pilihan;
        cin >> pilihan;

        if (pilihan == 1)
        {
            cout << endl;
            cout << "Masukkan ID Barang: ";
            cin >> searchId;
        }
        else if (pilihan == 2)
        {
            cout << endl;
            cout << "Masukkan Nama Barang: ";
            cin.ignore();
            getline(cin, searchName);
        }
        else if (pilihan == 3)
        {
            cout << endl;
            cout << "Masukkan Kategori Barang: ";
            cin.ignore();
            getline(cin, searchCategory);
        }
        else if (pilihan == 4)
        {
            cout << endl;
            cout << "Masukkan Status Barang: ";
            cin.ignore();
            getline(cin, searchStatus);
        }
        else if (pilihan == 5)
        {
            cout << endl;
            cout << "Masukkan Kondisi Barang: ";
            cin.ignore();
            getline(cin, searchCondition);
        }
        else if (pilihan == 6)
        {
            cout << endl;
            cout << "Masukkan Brand Barang: ";
            cin.ignore();
            getline(cin, searchBrand);
        }
        else if (pilihan == 7)
        {
            cout << endl;
            cin.ignore();
            cout << "Masukkan Nama Barang (Kosongkan jika tidak dicari): ";
            getline(cin, searchName);
            cout << "Masukkan Kategori Barang (Kosongkan jika tidak dicari): ";
            getline(cin, searchCategory);
            cout << "Masukkan Status Barang (Kosongkan jika tidak dicari): ";
            getline(cin, searchStatus);
            cout << "Masukkan Kondisi Barang (Kosongkan jika tidak dicari): ";
            getline(cin, searchCondition);
            cout << "Masukkan Brand Barang (Kosongkan jika tidak dicari): ";
            getline(cin, searchBrand);
        }
        else if (pilihan == 8)
        {
            cout << "Berhasil keluar dari program" << endl;
            break;
        }
        else
        {
            cout << "Pilihan tidak valid. Kembali ke menu utama.\n";
            return;
        }

        list *current = head;
        bool found = false;

        cout << left
             << setw(20) << "ID Barang"
             << setw(20) << "Nama Barang"
             << setw(15) << "Brand"
             << setw(15) << "Value"
             << setw(20) << "Category"
             << setw(12) << "Status"
             << setw(12) << "Condition"
             << setw(8) << "Stock"
             << endl;

        cout << string(122, '-') << endl;

        while (current != NULL)
        {
            bool match = true;

            if (!searchId.empty() && current->id != searchId)
                match = false;
            if (!searchName.empty() && toLower(current->name).find(toLower(searchName)) == string::npos)
                match = false;
            if (!searchCategory.empty() && toLower(current->category).find(toLower(searchCategory)) == string::npos)
                match = false;
            if (!searchStatus.empty() && toLower(current->status).find(toLower(searchStatus)) == string::npos)
                match = false;
            if (!searchCondition.empty() && toLower(current->condition).find(toLower(searchCondition)) == string::npos)
                match = false;
            if (!searchBrand.empty() && toLower(current->brand).find(toLower(searchBrand)) == string::npos)
                match = false;

            if (match)
            {
                found = true;
                cout << left
                     << setw(20) << current->id
                     << setw(20) << current->name
                     << setw(15) << current->brand
                     << setw(15) << fixed << setprecision(0) << current->value
                     << setw(20) << current->category
                     << setw(12) << current->status
                     << setw(12) << current->condition
                     << setw(8) << current->stock
                     << endl;
            }

            current = current->next;
        }

        if (!found)
        {
            cout << "Tidak ada barang yang cocok dengan keyword." << endl;
        }

        system("pause");
    }
}

void filterStockKosong()
{
    system("cls");

    if (isEmpty())
    {
        cout << "Tidak ada data barang.\n";
        system("pause");
        return;
    }

    list *current = head;
    bool found = false;

    cout << left
         << setw(20) << "ID Barang"
         << setw(20) << "Nama Barang"
         << setw(15) << "Brand"
         << setw(15) << "Value"
         << setw(20) << "Category"
         << setw(12) << "Status"
         << setw(12) << "Condition"
         << setw(8) << "Stock"
         << endl;

    cout << string(122, '-') << endl;

    while (current != NULL)
    {
        if (current->stock == 0)
        {
            found = true;
            cout << left
                 << setw(20) << current->id
                 << setw(20) << current->name
                 << setw(15) << current->brand
                 << setw(15) << current->value
                 << setw(20) << current->category
                 << setw(12) << current->status
                 << setw(12) << current->condition
                 << setw(8) << current->stock
                 << endl;
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "Tidak ada barang dengan stok kosong.\n";
    }
}

void sort(bool descending)
{
    system("cls");
    if (isEmpty())
    {
        cout << "Tidak ada data barang.\n";
        system("pause");
        return;
    }

    list *i, *j;

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if ((descending && i->stock < j->stock) || (!descending && i->stock > j->stock))
            {
                swap(i->id, j->id);
                swap(i->name, j->name);
                swap(i->brand, j->brand);
                swap(i->value, j->value);
                swap(i->category, j->category);
                swap(i->status, j->status);
                swap(i->condition, j->condition);
                swap(i->stock, j->stock);
            }
        }
    }
    cout << "\nData setelah diurutkan berdasarkan stok "
         << (descending ? "tertinggi" : "terendah") << ":\n";
    cetakList();
    system("pause");
}

void lihatList()
{

    while (true)
    {
        system("cls");

        cetakList();
        cout << endl;
        cout << "1. Cari barang" << endl;
        cout << "2. Urutkan barang dengan stok kosong" << endl;
        cout << "3. Urutkan berdasarkan stok stok tertinggi" << endl;
        cout << "4. Urutkan berdasarkan stok terendah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih salah satu opsi (ketik dalam angka): ";

        int pilihan;
        cin >> pilihan;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Masukkan angka saja!" << endl;
        }
        else if (pilihan == 1)
        {
            cariBarang();
        }
        else if (pilihan == 2)
        {
            filterStockKosong();
        }
        else if (pilihan == 3)
        {
            sort(true);
        }
        else if (pilihan == 4)
        {
            sort(false);
        }
        else if (pilihan == 5)
        {
            cout << "Berhasil keluar dari program" << endl;
            break;
        }
        else
        {
            cout << "Pilihan tidak tersedia" << endl;
        }
    }
}

void tambahList()
{
    while (true)
    {
        cin.ignore();
        system("cls");
        cout << "Masukkan nama barang: ";
        string name;
        getline(cin, name);

        if (!name.empty())
        {
            name[0] = toupper(name[0]);
            for (int i = 1; i < name.length(); i++)
            {
                name[i] = tolower(name[i]);
            }
        }

        cout << "Masukkan brand barang: ";
        string barang;
        getline(cin, barang);

        if (!barang.empty())
        {
            barang[0] = toupper(barang[0]);
            for (int i = 1; i < barang.length(); i++)
            {
                barang[i] = tolower(barang[i]);
            }
        }

        cout << "Masukkan value barang: ";
        float value;
        cin >> value;

        cin.ignore();
        cout << "Masukkan category barang: ";
        string category;
        getline(cin, category);

        cout << "Masukkan status barang: ";
        string status;
        getline(cin, status);

        cout << "Masukkan kondisi barang: ";
        string condition;
        getline(cin, condition);

        cout << "Masukkan stock barang: ";
        int stock;
        cin >> stock;

        insertLast(name, barang, value, category, status, condition, stock);

        cout << "1. Menambah list lagi" << endl;
        cout << "2. Keluar" << endl;
        cout << "Pilih salah satu opsi (ketik dalam angka): ";

        int pilihan;
        cin >> pilihan;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Masukkan angka saja!" << endl;
        }
        else if (pilihan == 2)
        {
            break;
        }
    }
}

void cetakbyId(string id)
{
    list *current = head;
    bool found = false;

    while (current != NULL)
    {
        if (current->id == id)
        {
            found = true;

            cout << left
                 << setw(20) << "ID Barang"
                 << setw(20) << "Nama Barang"
                 << setw(15) << "Brand"
                 << setw(15) << "Value"
                 << setw(20) << "Category"
                 << setw(12) << "Status"
                 << setw(12) << "Condition"
                 << setw(8) << "Stock"
                 << endl;

            cout << string(122, '-') << endl;

            cout << left
                 << setw(20) << current->id
                 << setw(20) << current->name
                 << setw(15) << current->brand
                 << setw(15) << fixed << setprecision(0) << current->value
                 << setw(20) << current->category
                 << setw(12) << current->status
                 << setw(12) << current->condition
                 << setw(8) << current->stock
                 << endl;
            break;
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "Barang dengan ID " << id << " tidak ditemukan." << endl;
    }
}
void editList()
{
    string id, name, brand, category, status, condition;
    float value;
    int stock;
    cetakList();
    cout << endl;
    list *current = head;

    while (true)
    {
        cout << "Masukkan ID barang yang akan diedit: ";
        cin >> id;

        current = head;
        bool found = false;

        while (current != NULL)
        {
            if (current->id == id)
            {
                found = true;
                break;
            }
            current = current->next;
        }

        if (!found)
        {
            cout << "ID tidak ditemukan, silakan masukkan ulang." << endl;
        }
        else
        {
            cetakbyId(id);
            break;
        }
    }

    cout << endl;

    while (true)
    {

        cout << "========Pilih data yang ingin diedit========" << endl;
        cout << "1. Nama barang" << endl;
        cout << "2. Brand " << endl;
        cout << "3. Value" << endl;
        cout << "4. Category" << endl;
        cout << "5. Status" << endl;
        cout << "6. Condition" << endl;
        cout << "7. Stock" << endl;
        cout << "8. Keluar" << endl;

        cout << "Pilih salah satu opsi (ketik dalam angka): ";

        int pilihan;
        cin >> pilihan;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Masukkan angka saja!" << endl;
        }
        else if (pilihan == 1)
        {
            while (current != NULL)
            {
                if (current->id == id)
                {
                    cout << "Masukkan nama barang: ";

                    cin >> name;
                    current->name = name;
                    cetakbyId(id);
                    break;
                }
                current = current->next;
            }
        }
        else if (pilihan == 2)
        {
            while (current != NULL)
            {
                if (current->id == id)
                {
                    cout << "Masukkan nama Brand: ";

                    cin >> brand;
                    current->brand = brand;
                    cetakbyId(id);
                    break;
                }
                current = current->next;
            }
        }
        else if (pilihan == 3)
        {
            while (current != NULL)
            {
                if (current->id == id)
                {
                    cout << "Masukkan Value Barang: ";

                    cin >> value;
                    current->value = value;
                    cetakbyId(id);
                    break;
                }
                current = current->next;
            }
        }
        else if (pilihan == 4)
        {
            while (current != NULL)
            {
                if (current->id == id)
                {
                    cout << "Masukkan Category Barang: ";

                    cin >> category;
                    current->category = category;
                    cetakbyId(id);
                    break;
                }
                current = current->next;
            }
        }
        else if (pilihan == 5)
        {
            while (current != NULL)
            {
                if (current->id == id)
                {
                    cout << "Masukkan Status Barang: ";
                    cin >> status;
                    current->status = status;
                    cetakbyId(id);
                    break;
                }
                current = current->next;
            }
        }
        else if (pilihan == 6)
        {
            while (current != NULL)
            {
                if (current->id == id)
                {
                    cout << "Masukkan kondisi Barang: ";

                    cin >> condition;
                    current->condition = condition;
                    cetakbyId(id);
                    break;
                }
                current = current->next;
            }
        }
        else if (pilihan == 7)
        {
            while (current != NULL)
            {
                if (current->id == id)
                {
                    cout << "Masukkan Stock Barang: ";

                    cin >> stock;
                    current->stock = stock;
                    cetakbyId(id);
                    break;
                }
                current = current->next;
            }
        }
        else if (pilihan == 8)
        {
            cout << "" << endl;
            break;
        }
        else
        {
            cout << "Pilihan tidak tersedia" << endl;
        }
        cout << "Data berhasil di edit" << endl;
    }
}
void hapusBarangById()
{
    system("cls");
    cetakList();

    if (isEmpty())
    {
        cout << "\nTidak ada barang untuk dihapus. " << endl;
        return;
    }

    string id;
    cout << "\nMasukkan ID barang yang ingin dihapus: ";
    cin >> id;

    list *current = head;
    list *prev = NULL;
    bool found = false;

    while (current != NULL)
    {
        if (current->id == id)
        {
            found = true;
            break;
        }
        prev = current;
        current = current->next;
    }

    if (found)
    {
        // Jika data di awal list
        if (current == head)
        {
            head = head->next;
            delete current;
        }
        else
        {
            // Hapus node di tengah atau akhir
            prev->next = current->next;
            delete current;
        }

        cetakList();
        cout << endl;
        cout << "Barang dengan ID " << id << " berhasil dihapus." << endl;
    }
    else
    {
        cout << endl;
        cout << "Barang dengan ID " << id << " tidak ditemukan." << endl;
    }
}

int main()
{
    insertLast("Mouse", "Logitech", 300000, "Aksesoris", "Bekas", "Baik", 5);
    insertLast("Flashdisk", "Transcend", 280000, "Aksesoris", "Bekas", "Baik", 20);
    insertLast("Monitor", "BenQ", 4200000, "Elektronik", "Bekas", "Baik", 10);

    insertLast("Laptop", "HP", 7500000, "Elektronik", "Bekas", "Baik", 5);
    insertLast("Flashdisk", "Kingston", 250000, "Aksesoris", "Baru", "Sempurna", 50);
    insertLast("Keyboard", "Corsair", 1600000, "Aksesoris", "Baru", "Bagus", 15);

    insertLast("Laptop", "Asus", 8000000, "Elektronik", "Baru", "Bagus", 10);
    insertLast("Mouse", "Razer", 350000, "Aksesoris", "Baru", "Sempurna", 7);
    insertLast("Keyboard", "Logitech", 1400000, "Aksesoris", "Bekas", "Baik", 25);

    insertLast("Monitor", "Samsung", 4000000, "Elektronik", "Baru", "Bagus", 15);
    insertLast("Laptop", "Dell", 8500000, "Elektronik", "Baru", "Sempurna", 8);
    insertLast("Keyboard", "Razer", 1500000, "Aksesoris", "Baru", "Sempurna", 20);

    insertLast("Flashdisk", "Sandisk", 300000, "Aksesoris", "Baru", "Bagus", 30);
    insertLast("Monitor", "LG", 4500000, "Elektronik", "Baru", "Sempurna", 12);
    insertLast("Mouse", "SteelSeries", 400000, "Aksesoris", "Baru", "Bagus", 10);

    while (true)
    {
        system("cls");

        cout << "========Welcome to HMP Inventory Management========" << endl;
        cout << "1. Lihat barang" << endl;
        cout << "2. Tambah barang" << endl;
        cout << "3. Edit barang" << endl;
        cout << "4. Hapus barang" << endl;
        cout << "5. Pinjam Barang" << endl;
        cout << "6. Kembalikan Barang" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilih salah satu opsi (ketik dalam angka): ";

        int pilihan;
        cin >> pilihan;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Masukkan angka saja!" << endl;
        }
        else if (pilihan == 1)
        {
            lihatList();
        }
        else if (pilihan == 2)
        {
            tambahList();
        }
        else if (pilihan == 3)
        {
            editList();
        }
        else if (pilihan == 4)
        {
            hapusBarangById();
        }
        else if (pilihan == 5)
        {
            cout << "Sedang Proses" << endl;
            break;
        }
        else if (pilihan == 6)
        {
            cout << "Sedang Proses" << endl;
            break;
        }
        else if (pilihan == 7)
        {
            cout << "Berhasil keluar dari program" << endl;
            break;
        }
        else
        {
            cout << "Pilihan tidak tersedia" << endl;
        }

        system("pause");
    }
}
