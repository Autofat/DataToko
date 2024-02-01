#include "Header.h"
#include "progToko.cpp"
#include "progBarang.cpp"
#include "progChild.cpp"
#include "windows.h"

void menu(){
    clearScreen();
    cout<<"---------------[DATA PENJUALAN]---------------"<<endl;
    cout<<"(1) DATA TOKO"<<endl;
    cout<<"(2) DATA BARANG"<<endl;
    cout<<"(X) EXIT"<<endl;
    cout<<"=============================================="<<endl;
}


// MENU TOKO
void menuToko(){
    clearScreen();
    cout<<"-----------------[DATA TOKO]-----------------"<<endl;
    cout<<"(1) MENAMBAH DAFTAR TOKO"<<endl;
    cout<<"(2) MENGHAPUS TOKO"<<endl;
    cout<<"(3) MENGISI BARANG DARI TOKO"<<endl;
    cout<<"(4) MENAMPILKAN SELURUH TOKO DENGAN BARANG YANG DIJUAL"<<endl;
    cout<<"(5) MENAMPILKAN TOKO TERTENTU DENGAN BARANG YANG DIJUAL"<<endl;
    cout<<"(6) MENAMPILKAN TOKO YANG PALING LENGKAP"<<endl;
    cout<<"(7) MENAMPILKAN TOKO YANG TIDAK LENGKAP"<<endl;
    cout<<"(0) BACK"<<endl;
    cout<<"=============================================="<<endl;
}

void tambahToko(listToko &LT){
    infotypeToko infoToko;
    adr_toko elmToko,cariToko;
    clearScreen();
    cout<<"-----------------[TAMBAH TOKO]-----------------"<<endl;
    cout<<"Kode Toko: ";
    cin>> infoToko.KodeToko;
    cout<<"Jenis Toko: ";
    cin>> infoToko.JenisToko;
    cariToko = searchToko(infoToko.KodeToko,LT);
    if(cariToko!=NULL){
        cout << "Kode toko sudah ada !, silahkan buat yang baru"<<endl;
        delay();
    } else {
        elmToko = alokasiToko(infoToko);
        insertFirstToko(LT, elmToko);
        cout<<"Toko berhasil ditambahkan !"<<endl;
        delay();
    }
}

void hapusToko(listToko &LT){
    string hapus;
    adr_toko cariToko;
    clearScreen();
    cout<<"-----------------[HAPUS TOKO]-----------------"<<endl;
    showAllToko(LT);
    cout<<endl;
    cout<<"Masukan kode toko yang ingin di hapus (KETIK X JIKA TIDAK JADI): ";
    cin >> hapus;
    if(hapus!="X" && hapus!="x"){
        cariToko = searchToko(hapus, LT);
        if(cariToko !=NULL){
            if(cariToko == first(LT)){
                deleteFirstToko(LT, cariToko);
            } else if(next(cariToko) == NULL){
                deleteLastToko(LT, cariToko);
            } else {
                adr_toko prec = first(LT);
                while(next(prec)!=cariToko){
                    prec = next(prec);
                }
                deleteAfterToko(LT, prec, cariToko);
            }
            cout << "Toko berhasil dihapus !"<<endl;
            delay();
        } else {
            cout << "--[Toko tidak ditemukan !]--"<<endl;
            delay();
        }

    } else {
        cout << "Kembali ke menu utama...";
        delay();
    }
}

void tambahBarangToko(listBarang LB, listToko LT){
    string input;
    adr_toko cariToko;
    adr_barang cariBarang;
    clearScreen();
    cout<<"----------------[TAMBAH BARANG KE TOKO ]----------------"<<endl;
    cout<<"List Toko : "<<endl;
    showAllToko(LT);
    cout<<endl;
    cout<<"Masukan kode toko: ";
    cin>>input;
    cariToko = searchToko(input, LT);
    if(cariToko!=NULL){
        cout<< "List Barang Yang Tersedia: "<<endl;;
        showAllBarang(LB);
        cout<<endl;
        cout<< "List Barang Yang Ada Di Toko Ini: "<<endl;;
        showAllBarangInToko(cariToko);
        cout<<endl;
        cout<<"Masukan nama barang: ";
        cin>>input;
        cariBarang = searchBarang(input,LB);
        if(cariBarang !=NULL){
            if(!cekBarangDiToko(cariToko, cariBarang)){
                adr_child elmChild = alokasiChild(cariBarang);
                insertDataBarang(cariToko, elmChild);
                cout<<"Barang berhasil di tambahkan ke toko "<< info(cariToko).KodeToko<<endl;
                delay();
            } else {
                cout << "Barang sudah terdaftar !"<<endl;
                delay();
            }
        } else {
            cout << "--[Barang tidak ditemukan !]--"<<endl;
            delay();
        }
    } else {
        cout << "--[Toko tidak ditemukan !]--"<<endl;
        delay();
    }
}

void menuShowAllTokoWithBarang(listToko LT){
    clearScreen();
    string input;
    cout<<"----------------[ LIST SEMUA TOKO BESERTA BARANG YANG DIJUAL ]----------------"<<endl;
    showAllTokoWithBarang(LT);
    cout<<endl;
    delay();
}

void menuCariToko(listToko LT){
    string input;
    adr_toko cariToko;
    clearScreen();
    showAllToko(LT);
    cout<<"----------------[ CARI TOKO ]----------------"<<endl;
    cout<<"Cari Toko: ";
    cin>>input;
    cariToko = searchToko(input, LT);
    if(cariToko!=NULL){
        showAllBarangInToko(cariToko);
        cout <<"Ketik 'X' untuk kembali ke menu !"<<endl;
        while(input != "X"){
            cin>>input;
        }
        delay();
    } else {
        cout<<"--[Toko tidak ditemukan !]--"<<endl;
        delay();
    }
}

void menuTokoPalingBanyakBarang(listToko LT){
    clearScreen();
    string input;
    cout<<"----------------[ TOKO PALING BANYAK BARANG DIJUAL ]----------------"<<endl;
    searchTokoPalingBanyakBarang(LT);
    cout<<endl;
    cout <<"Ketik 'X' untuk kembali ke menu !"<<endl;
    while(input != "X"){
        cin>>input;
    }
    delay();
}

void menuTokoPalingSedikitBarang(listToko LT){
    clearScreen();
    string input;
    cout<<"----------------[ TOKO PALING SEDIKIT BARANG DIJUAL ]----------------"<<endl;
    searchTokoPalingSedikitBarang(LT);
    cout<<endl;
    cout <<"Ketik 'X' untuk kembali ke menu !"<<endl;
    while(input != "X"){
        cin>>input;
    }
    delay();
}


// MENU BARANG
void menuBarang(){
    clearScreen();
    cout<<"----------------[DATA BARANG]----------------"<<endl;
    cout<<"(1) MENAMBAH DAFTAR BARANG"<<endl;
    cout<<"(2) MENGHAPUS BARANG"<<endl;
    cout<<"(3) MENAMPILKAN TOKO YANG MENJUAL BARANG TERTENTU"<<endl;
    cout<<"(0) BACK"<<endl;
    cout<<"=============================================="<<endl;
}

void tambahBarang(listBarang &LB){
    infotypeBarang infoBarang;
    adr_barang elmBarang;
    clearScreen();
    cout<<"----------------[TAMBAH BARANG]----------------"<<endl;
    cout<<"Nama Barang: ";
    cin>> infoBarang.NamaBarang;
    cout<<"Harga Jual: ";
    cin>> infoBarang.HargaJual;
    elmBarang = alokasiBarang(infoBarang);
    insertLastBarang(LB, elmBarang);
    cout<<"Data berhasil ditambahkan !"<<endl;
    delay();
}

void hapusBarang(listBarang &LB, listToko &LT){
    string hapus;
    adr_barang cariBarang;
    clearScreen();
    cout<<"----------------[HAPUS BARANG]----------------"<<endl;
    showAllBarang(LB);
    cout<<endl;
    cout<<"Masukan nama barang yang ingin di hapus (KETIK X JIKA TIDAK JADI): ";
    cin >> hapus;
    if(hapus!="X" && hapus!="x"){
        cariBarang = searchBarang(hapus, LB);
        if(cariBarang !=NULL){
            if(cariBarang == first(LB)){
                deleteFirstBarang(LB, LT, cariBarang);
            } else if (next(cariBarang)==NULL){
                deleteLastBarang(LB, LT,cariBarang);
            } else {
                adr_barang prec = first(LB);
                while(next(prec)!= cariBarang){
                    prec = next(prec);
                }
                cout<<info(prec).NamaBarang<<endl;
                deleteAfterBarang(LB, LT,prec, cariBarang);
            }
            cout << "Barang berhasil dihapus !"<<endl;
            delay();
        } else {
            cout << "--[Barang tidak ditemukan !]--";
            delay();
        }
    } else {
        cout << "Kembali ke menu utama...";
        delay();
    }
}

void cariBarangDiSemuaToko(listToko LT,listBarang LB){
    string input;
    adr_barang cariBarang;
    clearScreen();
    cout<<"----------------[CARI BARANG]----------------"<<endl;
    cout << "Cari Barang: ";
    cin >> input;
    cariBarang = searchBarang(input, LB);
    if(cariBarang != NULL){
        showTokoContainBarang(LT,cariBarang);
        cout <<"Ketik 'X' untuk kembali ke menu !"<<endl;
        while(input != "X"){
            cin>>input;
        }
    } else {
        cout <<"--[Barang tidak ditemukan !]--"<<endl;
        delay();
    }
}

// SYSTEM

void clearScreen() {
    system("cls");
}

void delay(){
    _sleep(1000);
}
