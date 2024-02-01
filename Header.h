#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#define info(P) P->info
#define next(P) P->next
#define child(P) P->child
#define barang(Q) Q->barang
#define first(L) L.first

using namespace std;

struct Toko {
    string KodeToko, JenisToko;
};

struct Barang {
    string NamaBarang;
    int HargaJual;
};

typedef Toko infotypeToko;
typedef Barang infotypeBarang;
typedef struct elemenToko *adr_toko;
typedef struct elemenBarang *adr_barang;
typedef struct elemenChild *adr_child;

struct elemenChild{
    adr_barang barang;
    adr_child next;
};

struct listChild{
    adr_child first;
};

struct elemenToko{
    infotypeToko info;
    adr_toko next;
    listChild child;
};

struct elemenBarang{
    infotypeBarang info;
    adr_barang next;
};

struct listToko{
    adr_toko first;
};

struct listBarang{
    adr_barang first;
};



// TOKO COMPONENT //
adr_toko alokasiToko(infotypeToko x);
void createListToko(listToko &LT);
void insertFirstToko(listToko &LT, adr_toko T);
void deleteFirstToko(listToko &LT, adr_toko &T);
void deleteAfterToko(listToko &LT, adr_toko prec, adr_toko &T);
void deleteLastToko(listToko &LT, adr_toko &T);
adr_toko searchToko(string kodeToko, listToko LT);
void showAllToko(listToko LT);
void showAllBarangInToko(adr_toko T);
void showAllTokoWithBarang(listToko LT);

// CHILD COMPONENT //
adr_child alokasiChild(adr_barang B);
bool cekBarangDiToko(adr_toko T, adr_barang B);
void createListChild(listChild &LC);
void insertDataBarang(adr_toko T, adr_child C);
void deleteFirstChild(listChild &LC, adr_child C);
void deleteAfterChild(listChild &LC, adr_child prec, adr_child C);
void deleteLastChild(listChild &LC, adr_child C);
void deleteChildOnList(listToko &LT, adr_barang B);
void showAllBarangInToko(adr_toko T);


// BARANG COMPONENT //
adr_barang alokasiBarang(infotypeBarang x);
void createListBarang(listBarang &LB);
void insertLastBarang(listBarang &LB, adr_barang B);
void deleteFirstBarang(listBarang &LB, listToko &LT, adr_barang &B);
void deleteAfterBarang(listBarang &LB, listToko &LT, adr_barang prec, adr_barang &B);
void deleteLastBarang(listBarang &LB, listToko &LT, adr_barang &B);
adr_barang searchBarang(string namaBarang, listBarang LB);
void showTokoContainBarang(listToko LT, adr_barang B);
void showAllBarang(listBarang LB);

// UTILITIES //
void menu();
void clearScreen();
void delay();

void menuToko();
void tambahToko(listToko &LT);
void hapusToko(listToko &LT);
void tambahBarangToko(listBarang LB, listToko LT);
void cariBarangDiSemuaToko(listToko LT, listBarang LB);
void menuCariToko(listToko LT);
void menuShowAllTokoWithBarang(listToko LT);
void searchTokoPalingBanyakBarang(listToko LT);
void searchTokoPalingSedikitBarang(listToko LT);
void menuTokoPalingBanyakBarang(listToko LT);
void menuTokoPalingSedikitBarang(listToko LT);

void menuBarang();
void tambahBarang(listBarang &LB);
void hapusBarang(listBarang &LB, listToko &LT);









#endif // HEADER_H_INCLUDED
