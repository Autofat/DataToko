#include "Header.h"

adr_toko alokasiToko(infotypeToko x){
    adr_toko P = new elemenToko;
    info(P).KodeToko = x.KodeToko;
    info(P).JenisToko = x.JenisToko;
    next(P) = NULL;
    createListChild(child(P));

    return P;
};

void createListToko(listToko &LT){
    first(LT)=NULL;
}

void insertFirstToko(listToko &LT, adr_toko T){
    if (first(LT)==NULL){
        first(LT) = T;
    } else {
        next(T) = first(LT);
        first(LT) = T;
    }
}

void deleteFirstToko(listToko &LT, adr_toko &T){
    if(first(LT)==NULL){
        cout<<"== [LIST TOKO KOSONG] =="<<endl;
    } else if (next(first(LT))==NULL){
        T = first(LT);
        first(LT) = NULL;
    } else {
        T = first(LT);
        first(LT) = next(T);
        next(T) = NULL;
    }
}

void deleteAfterToko(listToko &LT, adr_toko prec, adr_toko &T){
    T = next(prec);
    next(prec) = next(T);
    next(T) = NULL;
}

void deleteLastToko(listToko &LT, adr_toko &T){
    if(first(LT)==NULL){
        cout<<"== [LIST TOKO KOSONG] =="<<endl;
    } else if (next(first(LT))==NULL){
        T = first(LT);
        first(LT) = NULL;
    } else {
        adr_toko P = first(LT);
        while(next(next(P))!=NULL){
            P = next(P);
        }
        T = next(P);
        next(p)=NULL;
    }
}

void showAllToko(listToko LT){
    string input;
    adr_toko prec = first(LT);
    if(first(LT)==NULL){
        cout<<"== [LIST TOKO KOSONG] ==";
    }else{
        while(prec != NULL){
            cout<<info(prec).KodeToko<<" | "<<info(prec).JenisToko<<endl;
            prec = next(prec);
        }
    }

}

void showAllBarangInToko(adr_toko T){
    string input;
    if(first(child(T))==NULL){
        cout << "== [LIST BARANG KOSONG !] ==" <<endl;
    } else {
        cout <<endl;
        cout<<"Toko "<<info(T).KodeToko<<endl;
        adr_child C = first(child(T));
        while(C!=NULL){
            cout<<"- Nama: "<<info(barang(C)).NamaBarang<<" | Harga: "<<info(barang(C)).HargaJual<<endl;
            C = next(C);
        }
        cout<<endl;
        delay();
    }
}

void showAllTokoWithBarang(listToko LT){
    string input;
    if(first(LT)==NULL){
        cout << "== [LIST TOKO KOSONG] ==" <<endl;
    } else {
        adr_toko T = first(LT);
        while(T!=NULL){
            cout <<endl;
            cout <<"Toko "<<info(T).KodeToko<<endl;
            adr_child P = first(child(T));
            while(P !=NULL){
                cout<<"- Nama: "<<info(barang(P)).NamaBarang<<" | Harga: "<<info(barang(P)).HargaJual<<endl;
                P = next(P);
            }
            cout<<"-"<<endl;
            T = next(T);
        }
    }
    cout <<"Ketik 'X' untuk kembali ke menu !"<<endl;
    while(input != "X"){
        cin>>input;
    }
}

void searchTokoPalingBanyakBarang(listToko LT){
    adr_toko P = first(LT);
    adr_toko maxToko = NULL;
    int maxBarang = 0;
    string input;

    while(P != NULL){
    adr_child C = first(child(P));
    int jumlahBarang = 0;
    while(C != NULL){
      jumlahBarang++;
      C = next(C);
    }

    if(jumlahBarang > maxBarang){
      maxBarang = jumlahBarang;
      maxToko = P;
    }

    P = next(P);
    }

    if(maxToko != NULL){
        cout<<"Toko dengan jumlah barang terbanyak adalah "<< info(maxToko).KodeToko <<" dengan jumlah barang "<<maxBarang<<endl;
        delay();
    } else {
        printf("Tidak ada toko dengan barang.\n");
        delay();
    }
    cout <<"Ketik 'X' untuk kembali ke menu !"<<endl;
    while(input != "X"){
        cin>>input;
    }
}

void searchTokoPalingSedikitBarang(listToko LT){
    adr_toko P = first(LT);
    adr_toko minToko = NULL;
    int minBarang = INT_MAX;
    string input;

    while(P != NULL){
        adr_child C = first(child(P));
        int jumlahBarang = 0;
        while(C != NULL){
          jumlahBarang++;
          C = next(C);
        }

        if(jumlahBarang < minBarang){
          minBarang = jumlahBarang;
          minToko = P;
        }

        P = next(P);
    }

    if(minToko != NULL){
       cout<<"Toko dengan jumlah barang sedikit adalah "<< info(minToko).KodeToko <<" dengan jumlah barang "<<minBarang;
    } else {
        printf("Semua toko memiliki barang.\n");
    }
    cout <<"Ketik 'X' untuk kembali ke menu !"<<endl;
    while(input != "X"){
        cin>>input;
    }
}

adr_toko searchToko(string kodeToko, listToko LT){
    adr_toko prec = first(LT);
    if(first(LT)==NULL){
        return NULL;
    }else{
        while(prec != NULL){
            if(info(prec).KodeToko == kodeToko){
                return prec;
            }
            prec = next(prec);
        }
        return NULL;
    }
}

