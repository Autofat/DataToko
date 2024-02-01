#include "Header.h"

adr_barang alokasiBarang(infotypeBarang x){
    adr_barang P = new elemenBarang;
    info(P).NamaBarang = x.NamaBarang;
    info(P).HargaJual = x.HargaJual;
    next(P) = NULL;
    return P;
};

void createListBarang(listBarang &LB){
    first(LB)=NULL;
}

void insertLastBarang(listBarang &LB, adr_barang B){
    if (first(LB)==NULL){
        first(LB) = B;
    } else {
        adr_barang P = first(LB);
        while(next(P)!=NULL){
            P = next(P);
        }
        next(P) = B;
    }
}

void deleteFirstBarang(listBarang &LB, listToko &LT, adr_barang &B){
    if(first(LB)==NULL){
        cout<<"== [LIST BARANG KOSONG] =="<<endl;
    } else {
         if (next(first(LB))==NULL){
            B = first(LB);
            first(LB)=NULL;
        } else {
            B = first(LB);
            first(LB) = next(B);
            next(B) = NULL;
        }

       deleteChildOnList(LT, B);
    }
}
void deleteAfterBarang(listBarang &LB, listToko &LT, adr_barang prec, adr_barang &B){
    B = next(prec);
    next(prec) = next(B);
    next(B) = NULL;
    deleteChildOnList(LT, B);
}

void deleteLastBarang(listBarang &LB,listToko &LT, adr_barang &B){
    if(first(LB)==NULL){
        cout<<"== [LIST BARANG KOSONG] =="<<endl;
    } else if (next(first(LB))==NULL){
        B = first(LB);
        first(LB)=NULL;
    } else {
        adr_barang prec = first(LB);
        while(next(next(prec))!=NULL){
            prec = next(prec);
        }
        B = next(prec);
        next(prec) = NULL;

        deleteChildOnList(LT, B);
    }
}

void showAllBarang(listBarang LB){
    string input;
    adr_barang prec = first(LB);
    if(first(LB)==NULL){
        cout<<"== [LIST BARANG KOSONG] ==";
    }else{
        while(prec != NULL){
            cout<<info(prec).NamaBarang<<"|"<<info(prec).HargaJual<<endl;
            prec = next(prec);
        }
    }

}

adr_barang searchBarang(string namaBarang, listBarang LB){
    adr_barang prec = first(LB);
    if(first(LB) == NULL){
        return NULL;
    }else{
        while(prec!=NULL){
            if (namaBarang == info(prec).NamaBarang){
                return prec;
            }
            prec = next(prec);
        }
        return NULL;
    }
}

void showTokoContainBarang(listToko LT, adr_barang B){
    string input;
    if (first(LT)==NULL){
        cout << "- List Toko Kosong -"<<endl;
    } else {
        cout << "List Toko Yang Menjual Barang "<<info(B).NamaBarang<<": "<<endl;
        adr_toko T = first(LT);
        while(T!=NULL){
            adr_child C = first(child(T));
            while(C!=NULL){
                if(barang(C)==B){
                    cout<<"- Toko "<<info(T).KodeToko<<endl;
                    C = NULL; //Agar langsung stop
                } else {
                    C = next(C);
                }
            }
            T = next(T);
        }
    }

}
