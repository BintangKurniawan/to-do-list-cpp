#include <iostream>
#include <cstdlib>
#include <iomanip>

#include <limits>

using namespace std;

struct list
{
    string name;
    string priority;
    string description;
    string status;
    list *next;
};

list *head;
list *tail;

bool isEmpty()
{
    if (head == NULL)
        return true;
    return false;
}

void insertLast(string name, string priority, string description)
{
    list *new_list, *current;
    new_list = new list();
    new_list->name = name;
    new_list->priority = priority;
    new_list->description = description;
    new_list->status = "Belum Selesai";
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
             << setw(20) << "Nama List"
             << setw(15) << "Prioritas"
             << setw(40) << "Deskripsi" << endl;

        cout << string(75, '-') << endl;
        while (current != NULL)
        {
            cout << left
                 << setw(20) << current->name
                 << setw(15) << current->priority
                 << setw(40) << current->description << endl;

            current = current->next;
        }
    }
    else
    {
        cout << "List kosong." << endl;
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

void cariList()
{
    cin.ignore();
    string keyword;
    cout << "Masukkan keyword untuk mencari list: ";
    getline(cin, keyword);
    keyword = toLower(keyword);

    list *current = head;
    bool found = false;

    cout << left
         << setw(20) << "Nama List"
         << setw(15) << "Prioritas"
         << setw(40) << "Deskripsi" << endl;
    cout << string(75, '-') << endl;

    while (current != NULL)
    {
        string lowerName = toLower(current->name);
        if (lowerName.find(keyword) != string::npos)
        {
            found = true;
            cout << left
                 << setw(20) << current->name
                 << setw(15) << current->priority
                 << setw(40) << current->description << endl;
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "Tidak ada list yang cocok dengan keyword." << endl;
    }
}

void lihatList()
{

    while (true)
    {
        system("cls");

        cetakList();
        cout << endl;
        cout << "Pilih salah satu opsi (ketik dalam angka):" << endl;
        cout << "1. Cari list" << endl;
        cout << "2. Urutkan berdasarkan prioritas" << endl;
        cout << "3. Urutkan berdasarkan status" << endl;
        cout << "4. Keluar" << endl;

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
            cariList();
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
        cout << "Masukkan nama list: ";
        string name;
        getline(cin, name);

        cout << "Masukkan prioritas list: ";
        string priority;
        getline(cin, priority);

        cout << "Masukkan deskripsi list: ";
        string description;
        getline(cin, description);
        insertLast(name, priority, description);
        cout << "List berhasil ditambahkan" << endl;

        cout << "Pilih salah satu opsi (ketik dalam angka):" << endl;
        cout << "1. Menambah list lagi" << endl;
        cout << "2. Keluar" << endl;

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

        cout << "========Welcome to HMP To do List========" << endl;
        cout << "Pilih salah satu opsi (ketik dalam angka):" << endl;
        cout << "1. Lihat list" << endl;
        cout << "2. Tambah list" << endl;
        cout << "3. Edit list" << endl;
        cout << "4. Hapus list" << endl;
        cout << "5. Keluar" << endl;

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