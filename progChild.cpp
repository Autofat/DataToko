#include "Header.h"

adr_child alokasiChild(adr_barang B){
    adr_child P = new elemenChild;
    barang(P) = B;
    next(P) = NULL;

    return P;
}


void createListChild(listChild &LC){
    first(LC)=NULL;
}

bool cekBarangDiToko(adr_toko T, adr_barang B){
    adr_child P = first(child(T));
    while (P!=NULL){
        if(barang(P)==B){
            return true;
        }
        P = next(P);
    }
    return false;
}

void insertDataBarang(adr_toko T, adr_child C){
    if(first(child(T)) == NULL){
        first(child(T)) = C;
    } else {
        next(C) = first(child(T));
        first(child(T)) = C;
    }
}


void deleteChildOnList(listToko &LT, adr_barang B){
    adr_toko T = first(LT);

    while(T!=NULL){
        adr_child C = first(child(T));
        while(C!=NULL){
            if(barang(C) == B){
                adr_child tempC;
                if(C == first(child(T))){
                    deleteFirstChild(child(T),tempC);
                } else if(next(C)==NULL){
                    deleteLastChild(child(T),tempC);
                } else {
                    adr_child prec = first(child(T));
                    while(next(prec)!=C){
                        prec = next(prec);
                    }
                    deleteAfterChild(child(T),prec,tempC);
                }
            }
            C = next(C);
        }
        T = next(T);
    }
}

void deleteFirstChild(listChild &LC, adr_child C){
    if(first(LC)==NULL){
        cout << "- List Child Kosong ! -"<<endl;
    } else if(next(first(LC))==NULL) {
        C = first(LC);
        first(LC) = NULL;
    } else {
        C = first(LC);
        first(LC) = next(C);
        next(C) = NULL;
    }
}

void deleteAfterChild(listChild &LC, adr_child prec, adr_child C){
    C = next(prec);
    next(prec) = next(C);
    next(C)=NULL;
}

void deleteLastChild(listChild &LC, adr_child C){
    if(first(LC)==NULL){
        cout << "- List Child Kosong ! -"<<endl;
    } else if(next(first(LC))==NULL) {
        C = first(LC);
        first(LC) = NULL;
    } else {
        adr_child P = first(LC);
        while(next(next(P))!=NULL){
            P = next(P);
        }
        C = next(P);
        next(P) = NULL;
    }
}
