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
    cin.ignore();
    string keyword;
    cout << "Masukkan keyword untuk mencari barang: ";
    getline(cin, keyword);
    keyword = toLower(keyword);

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
        string lowerName = toLower(current->name);
        if (lowerName.find(keyword) != string::npos)
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
        cout << "Tidak ada barang yang cocok dengan keyword." << endl;
    }
}

void lihatList()
{

    while (true)
    {
        system("cls");

        cetakList();
        cout << endl;
        cout << "1. Cari barang" << endl;
        cout << "2. Urutkan berdasarkan nama barang" << endl;
        cout << "3. Urutkan barang dengan stok kosong" << endl;
        cout << "4. Urutkan berdasarkan stok stok tertinggi" << endl;
        cout << "5. Urutkan berdasarkan stok terendah" << endl;
        cout << "6. Keluar" << endl;
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
            cout << "Bentar" << endl;
        }
        else if (pilihan == 3)
        {
            cout << "Bentar" << endl;
        }
        else if (pilihan == 4)
        {
            cout << "Bentar" << endl;
        }
        else if (pilihan == 5)
        {
            cout << "Bentar" << endl;
        }
        else if (pilihan == 6)
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

void tambahList()
{
    while (true)
    {
        cin.ignore();
        system("cls");
        cout << "Masukkan nama barang: ";
        string name;
        getline(cin, name);

        cout << "Masukkan brand barang: ";
        string barang;
        getline(cin, barang);

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
        cout << "List berhasil ditambahkan" << endl;

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

int main()
{
    while (true)
    {
        system("cls");

        cout << "========Welcome to HMP Inventory Management========" << endl;
        cout << "1. Lihat barang" << endl;
        cout << "2. Tambah barang" << endl;
        cout << "3. Edit barang" << endl;
        cout << "4. Hapus barang" << endl;
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
            lihatList();
        }
        else if (pilihan == 2)
        {
            tambahList();
        }
        else if (pilihan == 3)
        {
            cout << "Bentar" << endl;
        }
        else if (pilihan == 4)
        {
            cout << "Bentar" << endl;
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

        system("pause");
    }
}