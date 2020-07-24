#include <iostream>
#include <conio.h>
#include <string.h>
#include "header.h"

using namespace std;

void regis_user();

//method utama untuk memanggil method lain yang  akan dikerjakan
int main()
{
    int pil;
    do
    {
        system("cls");
        cout << "1. DAFTAR USER BARU"<< endl;
        cout << "2. LIHAT USER TERDAFTAR" << endl;
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
        default :
            cout << "Wrong input" << endl;
        }
    }while(pil<3);
    return 0;
}
