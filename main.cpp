#include "utils.cpp"
using namespace std;

int main()
{
    listToko LToko;
    listBarang LBarang;
    createListToko(LToko);
    createListBarang(LBarang);

    string pilihan, subPilihan;

    while(pilihan!="X"){
        menu();
        cout << "Masukan Pilihan : ";
        cin>>pilihan;
        if(pilihan=="1"){
            while(pilihan=="1"){
                menuToko();
                cout << "Masukan Pilihan : ";
                cin>>subPilihan;
                if (subPilihan=="1"){
                    tambahToko(LToko);
                } else if(subPilihan=="2"){
                    hapusToko(LToko);
                } else if(subPilihan=="3"){
                    tambahBarangToko(LBarang, LToko);
                } else if(subPilihan=="4"){
                    menuShowAllTokoWithBarang(LToko);
                } else if(subPilihan=="5"){
                    menuCariToko(LToko);
                } else if(subPilihan=="6"){
                    menuTokoPalingBanyakBarang(LToko);
                } else if(subPilihan=="7"){
                    menuTokoPalingSedikitBarang(LToko);
                } else if (subPilihan=="0") {
                    pilihan = "0";
                } else {
                    cout << "Masukan pilihan yang disediakan !";
                    delay();
                }
            }
        } else if(pilihan=="2") {
            while(pilihan=="2"){
                menuBarang();
                cout << "Masukan Pilihan : ";
                cin>>subPilihan;
                if(subPilihan=="1"){
                    tambahBarang(LBarang);
                } else if (subPilihan=="2"){
                    hapusBarang(LBarang,LToko);
                } else if (subPilihan=="3"){
                    cariBarangDiSemuaToko(LToko, LBarang);
                } else if (subPilihan=="0") {
                    pilihan = "0";
                } else {
                    cout << "Masukan pilihan yang disediakan !";
                    delay();
                }
            }
        } else if(pilihan !="X"){
            cout << "Masukan pilihan yang disediakan !";
            delay();
        }
    }

}
