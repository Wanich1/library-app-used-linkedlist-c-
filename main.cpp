#include <iostream>
//#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

using namespace std;

//deklarasu linked list user
struct user
{
    int id_user;
    char nama[50];
    char username[50];
    char password[50];
    char jKelamin;
    char alamat[50];
    int no_telp;
    int borr_book_id;
    user *next,*prev;
}*front=NULL,*back=NULL,*helper_a=NULL,*helper_b=NULL; //setting pointer
//end of declare linked list/struct user

int id_user=0;//untuk auto increment id user

//method untuk input/daftar data pengguna
void regis_user()
{
    user *baru;
    baru= new user;//membuat struct baru untuk diisi

    baru->id_user=id_user++;
    cin.ignore();
    cin.sync();
    cout <<"Nama : ";
    cin.getline(baru->nama,50);
    cout << "Username : ";
    cin >> baru->username;
    cout << "Password : ";
    cin >> baru->password;
    cout << "Alaamat : ";
    cin >> baru->alamat;
    cout << "Jenis Kelamin (L/P) : ";
    cin >> baru->jKelamin;
    cout << "No telp : ";
    cin >> baru->no_telp;
    baru->next=NULL;
    baru->prev=NULL;

    if (front==NULL)
    {
        front=back=baru;
    }
    else{
        back->next=baru;
        baru->prev=back;
        back=baru;
    }
    system("pause");
}

//method untuk melihat pengguna yang sudah terdaftar
void read_user()
{
    helper_a=front;
    while(helper_a!=NULL)
    {
        cout << "\nNama = " << helper_a->nama;
        helper_a=helper_a->next;
    }
    cout << endl;
    system("pause");
}

//deklarasu linked list user
struct buku
{
    int isbn;
    char judul[50];
    char kategori[50];
    char genre[50];
    bool status;
    int patron_id;
    char borr_date[10];
    buku *next,*prev;
}*depan_b=NULL,*belakang_b=NULL,*help=NULL,*help_b=NULL; //setting pointer
//end of declare linked list/struct user


void hardcode_book()
{
    buku *baru;
    baru = new buku;
    char judul1[50]="Harry potter";
    char kategori1[50]="fiction";
    char genre1[50]="fantasy";
    char judul2[50]="Harry potter2";
    char kategori2[50]="fiction";
    char genre2[50]="fantasy";
    //hardcode buku1
    cin.sync();
    baru->isbn=100;
    //baru->judul={'h','a','r','r','y',' ','p','o','t','t','e','r'};
    strncpy(baru->judul,judul1,50);
    strncpy(baru->kategori,kategori1,50);
    strncpy(baru->genre,genre1,50);
    baru->status=true;
    baru->patron_id=0;

    baru->next=baru->prev=NULL;
    depan_b=belakang_b=baru;
    //hardcode buku 1

    buku *bantu;
    bantu = new buku;
    //hardcode buku 2
    strncpy(bantu->judul,judul2,50);
    strncpy(bantu->kategori,kategori2,50);
    strncpy(bantu->genre,genre2,50);
    bantu->isbn=101;
    bantu->status=true;

    bantu->next=bantu->prev=NULL;

    belakang_b->next=bantu;
    bantu->prev=belakang_b;
    belakang_b=bantu;
    //hardcode buku 2
}

void tambah_buku()
{
    buku *baru;
    baru = new buku;
    bool input=true;
    do
    {
        cout << "Masukkan ISBN = ";
        cin >> baru->isbn;
        help=depan_b;
        while(help!=NULL)
        {
            if(baru->isbn==help->isbn)
            {
                cout << "ISBN sudah ada"<<endl;
                input=true;
                break;
            }
            else
            {
                input=false;
            }
            help=help->next;
        }

    }while(input);
    cin.sync();
    cout << "Masukkan Judul = ";
    cin.getline(baru->judul,50);
    cout << "Masukkan Kategori = ";
    cin.getline(baru->kategori,50);
    cout << "Masukkan Genre = ";
    cin.getline(baru->genre,50);
    baru->status=true;

    baru->next=baru->prev=NULL;
    belakang_b->next=baru;
    baru->prev=belakang_b;
    belakang_b=baru;

    cout << "\n\nBerhasil tambah buku";
    system("pause");
}

void read_buku()
{
    help=depan_b;
    while(help!=NULL)
    {
        cout << "\nISBN= " << help->isbn;
        cout << "\nJudul buku = " << help->judul;
        cout << "\nKategori = " << help->kategori;
        cout << "\nGenre = " << help->genre;
        cout << endl;
        help=help->next;
    }
    cout << endl;
    system("pause");
}

void cari_buku()
{
    int cari;
    bool found=false;
    do{
        cout << "CARI BERDASAR?" << endl;
        cout << "1. TITTLE" << endl;
        cout << "2. KATEGORI" << endl;
        cout << "3. GENRE" << endl;
        cout << "4. AVAILABILITY" << endl;
        cin >> cari;
        if(cari==1)
        {
            cin.sync();
            char judul_cari[50];
            cout << "Masukkan judul = ";
            cin.getline(judul_cari,50);
            strupr(judul_cari);
            help=depan_b;
            while(help!=NULL)
            {
                char helper[50];
                strcpy(helper,help->judul);
                strupr(helper);
                if (strcmp(judul_cari,helper)==0)
                {
                    cout << judul_cari;
                    cout << "\nISBN= " << help->isbn << endl;
                    cout << "Judul buku = " << help->judul << endl;
                    cout << "Kategori = " << help->kategori << endl;
                    cout << "Genre = " << help->genre << endl;
                    found=true;
                }
                cout << endl;
                help=help->next;
            }
            if (found!=true)
            {
                cout << "Buku tidak ada" << endl;
            }
        }
        else if(cari==2)
        {
            cin.sync();
            char kategori_cari[50];
            cout << "Masukkan kategori = ";
            cin.getline(kategori_cari,50);
            strupr(kategori_cari);
            help=depan_b;
            while(help!=NULL)
            {
                char helper[50];
                strcpy(helper,help->kategori);
                strupr(helper);
                if (strcmp(helper,kategori_cari)==0)
                {
                    cout << "\nISBN= " << help->isbn << endl;
                    cout << "Judul buku = " << help->judul << endl;
                    cout << "Kategori = " << help->kategori << endl;
                    cout << "Genre = " << help->genre << endl;
                    found=true;
                }
                cout << endl;
                help=help->next;
            }
            if (found!=true)
            {
                cout << "Buku tidak ada";
            }
        }
        else if(cari==3)
        {
            cin.sync();
            char genre_cari[50];
            cout << "Masukkan kategori = ";
            cin.getline(genre_cari,50);
            strupr(genre_cari);
            help=depan_b;
            while(help!=NULL)
            {
                char helper[50];
                strcpy(helper,help->genre);
                strupr(helper);
                if (strcmp(helper,genre_cari)==0)
                {
                    cout << "\nISBN= " << help->isbn << endl;
                    cout << "Judul buku = " << help->judul << endl;
                    cout << "Kategori = " << help->kategori << endl;
                    cout << "Genre = " << help->genre << endl;
                    found=true;
                }
                cout << endl;
                help=help->next;
            }
            if (found!=true)
            {
                cout << "Buku tidak ada";
            }
        }
        cout << endl;
    }while(cari<5);
}

void update_buku()
{
    int isbn_baru;
    bool found=false;
    char quest;
    int update_menu;
    do{
        int cari_isbn;
        cout << "MASUKKAN ISBN BUKU = ";
        cin >> cari_isbn;
        help=depan_b;
        while(found==false)
        {
            if (cari_isbn==help->isbn)
            {
                cout << "\nISBN= " << help->isbn << endl;
                cout << "Judul buku = " << help->judul << endl;
                cout << "Kategori = " << help->kategori << endl;
                cout << "Genre = " << help->genre << endl;
                found=true;
            }
            else
            {
                help=help->next;
            }
        }
        cout << "Update buku ini?(y/n)";
        cin >> quest;
        if (quest=='y'||quest=='Y')
        {
            cout << "1. Update ISBN"<< endl;
            cout << "2. Update Judul"<< endl;
            cout << "3. Update Kategori"<< endl;
            cout << "4. Update Genre"<< endl;
            cout << "Apa yang mau di update?";
            cin >> update_menu;
            if (update_menu==1)
            {
                bool input;
                do
                {
                    cout << "Masukkan ISBN baru = ";
                    cin >> isbn_baru;
                    help_b=depan_b;
                    cout << help->isbn;
                    while(help_b!=NULL)
                    {
                        if(isbn_baru=help_b->isbn)
                        {
                            cout << help_b->isbn;
                            cout << "ISBN sudah ada"<<endl;
                            input=true;
                            help_b=help_b->next;
                        }
                        else
                        {
                            input=false;
                            help->isbn=isbn_baru;
                        }
                    }
                }while(input);
                cout << "Isbn Updated" << endl;
            }
        }
    }while(quest!='y');
}

//method utama untuk memanggil method lain yang  akan dikerjakan
int main()
{
    hardcode_book();
    int pil;
    int sub;
    do
    {
        system("cls");
        cout << "1. MENU BUKU"<< endl;
        cout << "2. MENU USER" << endl;
        cout << "3. EXIT" << endl;
        cout << "masukkan pilihan = ";
        cin>> pil;
        switch(pil)
        {
        case 1:
            do{
                cout << "1. LIHAT BUKU" << endl;
                cout << "2. TAMBAH BUKU" << endl;
                cout << "3. CARI BUKU" << endl;
                cout << "4. UPDATE BUKU" << endl;
                cout << "5. BACK" << endl;
                cin >> sub;
                if(sub==1)
                {
                    read_buku();

                }
                else if(sub==2)
                {
                    tambah_buku();

                }
                else if(sub==3)
                {
                    cari_buku();
                }
                else if(sub==4)
                {
                    update_buku();
                }
                else
                {
                    cout << "input salah";

                }
            }while(sub<=4);
            break;
        case 2:
            do{
                cout << "1. REGIS PATRON" << endl;
                cout << "2. SEARCH PATRON" << endl;
                cout << "3. VIEW PATRON WITH ACTIVE  BOOKS BORROWED" << endl;
                cout << "4. DISPLAY LAST 10 BOOKS BORROWED BY PATRON" << endl;
                cout << "5. UPFATE PATRON INFO" << endl;
                cout << "6. BACK" << endl;
                cin >> sub;
                if(sub==1)
                {
                    regis_user();

                }
                else if(sub==2)
                {
                    read_user();

                }
                else if(sub==3)
                {
                    break;
                }
                else if(sub==4)
                {
                    break;
                }
                else if(sub==5)
                {

                }
                else
                {
                    cout << "input salah";

                }
            }while(sub<=5);
        default :
            cout << "Wrong input" << endl;
        }
    }while(pil<3);
    return 0;
}
