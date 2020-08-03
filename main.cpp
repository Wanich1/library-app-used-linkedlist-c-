#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

using namespace std;

void regis_user();

//method utama untuk memanggil method lain yang  akan dikerjakan
int main()
{
    hardcode_book();
    int pil;
    do
    {
        system("cls");
        cout << "1. DAFTAR USER BARU"<< endl;
        cout << "2. LIHAT USER TERDAFTAR" << endl;
        cout << "3. LIHAT BUKU" << endl;
        cout << "4. TAMBAH BUKU" << endl;
        cout << "masukkan pilihan = ";
        cin>> pil;
        switch(pil)
        {
        case 1:
            regis_user();
            break;
        case 2:
            read_user();
            cin.get();
            break;
        case 3:
            read_buku();
            break;
        case 4:
            tambah_buku();
            break;
        default :
            cout << "Wrong input" << endl;
        }
    }while(pil<5);
    return 0;
}
