#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
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
    char kategori1[50]="fictioin";
    char genre1[50]="fantasy";
    char judul2[50]="Harry potter2";
    char kategori2[50]="fictioin";
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


#endif // HEADER_H_INCLUDED
