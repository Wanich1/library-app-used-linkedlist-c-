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
    char borr_date;
    user *next,*prev;
}*front=NULL,*back=NULL,*helper_a=NULL,*helper_b=NULL; //setting pointer
//end of declare linked list/struct user

int id_user=0;//untuk auto increment id user

//method untuk input/daftar data pengguna
void regis_user()
{
    user *baru;
    baru= new user;

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

}


#endif // HEADER_H_INCLUDED
