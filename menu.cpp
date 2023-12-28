#include "hospital.h"
#include "hospital.cpp"

string opt;

void mainMenu(hospital h)
{
    cout << "  Menu Utama" << endl;
    cout << "--------------------------------" << endl << endl;
    cout << " 1. Tambah Data Tanggal Kelahiran" << endl;
    cout << " 2. Hapus Data Tanggal Kelahiran" << endl;
    cout << " 3. Tampilkan Data Tanggal Kelahiran" << endl;
    cout << endl;
    cout << " 4. Tambah Data Bayi" << endl;
    cout << " 5. Hapus Data Bayi" << endl;
    cout << endl;
    cout << " 6. Tampilkan Data Tanggal Kelahiran dan Bayi yang Lahir" << endl;
    cout << " 7. Tampilkan Tanggal dengan Kelahiran Terendah" << endl;
    cout << endl;
    cout << " 0. Keluar" << endl << endl;
    cout << "--------------------------------" << endl << endl;

    cout << " Pilih opsi: "; cin >> opt;
    cout << endl;
    cout << "\033c";

    if (opt == "1") {
        cout << "*------------------------------*" << endl << endl;
        cout << " Isikan tanggal dengan format DD-MONTH-YYYY, contoh: 22-Desember-2023." << endl << endl;
        cout << "*------------------------------*" << endl << endl;

        string d;

        cout << " Tanggal: "; cin >> d;
        cout << endl;

        insertDate(h, createElmDate(d));

        cout << "\033c";
        cout << "*------------------------------*" << endl << endl;
        cout << " Data tanggal kelahiran baru berhasil ditambahkan." << endl << endl;
        cout << "*------------------------------*" << endl << endl;

        mainMenu(h);
    } else if (opt == "2") {
        showDate(h);
        cout << "*------------------------------*" << endl << endl;
        cout << " Isikan tanggal yang akan dihapus datanya dengan format DD-MONTH-YYYY, contoh: 22-Desember-2023." << endl << endl;
        cout << "*------------------------------*" << endl << endl;

        string d;

        cout << " Tanggal: "; cin >> d;
        cout << endl;

        deleteDate(h, d);

        cout << "\033c";
        cout << "*------------------------------*" << endl << endl;
        cout << " Data tanggal kelahiran terpilih berhasil dihapus." << endl << endl;
        cout << "*------------------------------*" << endl << endl;

        mainMenu(h);
    } else if (opt == "3") {
        showDate(h);
        cout << "  Menu" << endl;
        cout << "--------------------------------" << endl << endl;
        cout << " 9. Kembali" << endl;
        cout << " 0. Keluar" << endl << endl;
        cout << "--------------------------------" << endl << endl;

        cout << " Pilih opsi: "; cin >> opt;
        cout << endl;
        cout << "\033c";

        if (opt == "0") {
        } else {
            mainMenu(h);
        }
    } else if (opt == "4") {
        cout << "*------------------------------*" << endl << endl;
        cout << " Isikan nama bayi tanpa spasi, contoh: Gojo_Satoru." << endl << endl;
        cout << "*------------------------------*" << endl << endl;

        string b;

        cout << " Nama: "; cin >> b;
        cout << endl;

        cout << "*------------------------------*" << endl << endl;
        cout << " Isikan tanggal lahir bayi dengan format DD-MONTH-YYYY, contoh: 22-Desember-2023." << endl << endl;
        cout << "*------------------------------*" << endl << endl;

        string d;

        cout << " Tanggal: "; cin >> d;
        cout << endl;

        connectList(h, b, d);

        cout << "\033c";
        cout << "*------------------------------*" << endl << endl;
        cout << " Data bayi baru berhasil ditambahkan." << endl << endl;
        cout << "*------------------------------*" << endl << endl;

        mainMenu(h);
    } else if (opt == "5") {
        showAll(h);
        cout << "*------------------------------*" << endl << endl;
        cout << " Isikan tanggal lahir dari bayi yang akan dihapus datanya dengan format DD-MONTH-YYYY, contoh: 22-Desember-2023." << endl << endl;
        cout << "*------------------------------*" << endl << endl;

        string d;

        cout << " Tanggal: "; cin >> d;
        cout << endl;

        cout << "*------------------------------*" << endl << endl;
        cout << " Isikan nama bayi yang akan dihapus datanya tanpa spasi, contoh: Gojo_Satoru." << endl << endl;
        cout << "*------------------------------*" << endl << endl;

        string b;

        cout << " Nama: "; cin >> b;
        cout << endl;

        deleteBaby(h, d, b);

        cout << "\033c";
        cout << "*------------------------------*" << endl << endl;
        cout << " Data bayi terpilih berhasil dihapus." << endl << endl;
        cout << "*------------------------------*" << endl << endl;

        mainMenu(h);
    } else if (opt == "6") {
        showAll(h);
        cout << "  Menu" << endl;
        cout << "--------------------------------" << endl << endl;
        cout << " 9. Kembali" << endl;
        cout << " 0. Keluar" << endl << endl;
        cout << "--------------------------------" << endl << endl;

        cout << " Pilih opsi: "; cin >> opt;
        cout << endl;
        cout << "\033c";

        if (opt == "0") {
        } else {
            mainMenu(h);
        }
    } else if (opt == "7") {
        showLowestBirthRate(h);
        cout << "  Menu" << endl;
        cout << "--------------------------------" << endl << endl;
        cout << " 9. Kembali" << endl;
        cout << " 0. Keluar" << endl << endl;
        cout << "--------------------------------" << endl << endl;

        cout << " Pilih opsi: "; cin >> opt;
        cout << endl;
        cout << "\033c";

        if (opt == "0") {
        } else {
            mainMenu(h);
        }
    } else if (opt == "0") {
    } else {
        mainMenu(h);
    }
}