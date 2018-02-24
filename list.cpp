#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) dan last(L) diset Nil
    */
    //-------------your code here-------------
    first(L)=NULL;
    last(L)=NULL;

    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = NULL;
    //-------------your code here-------------
    P = new elmlist;
    info(P) = x;
    next(P)=NULL;
    prev(P)=NULL;

    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    delete P;

    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
    if(first(L)==NULL){
        first(L)=P;
        last(L)=P;
        next(last(L))=first(L);
        prev(first(L))=last(L);
    }else{
        next(P)=first(L);
        first(L)=P;
        next(last(L))=first(L);
        prev(first(L))=last(L);
    }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    if(first(L)==NULL){
        first(L)=P;
        last(L)=P;
        next(last(L))=first(L);
        prev(first(L))=last(L);
    }else{
        next(last(L))=P;
        next(P)=first(L);
        prev(P)=last(L);
        prev(first(L))=P;
        last(L)=P;
    }
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P;
    //-------------your code here-------------
    P = first(L);
    if(first(L)!=NULL){
        do{
            if(P->info.ID == x.ID){
                return P;
            }else{
                P=next(P);
            }
        }while(P!=first(L) && P->info.ID != x.ID);

    }
    if(P->info.ID!=x.ID){
        return NULL;
    }


    //----------------------------------------
    return P;
    //----------------------------------------
}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------
    P = first(L);
    if(first(L)!=NULL){
        do{
            if(P->info.name == x.name){
                return P;
            }else{
                P=next(P);
            }
        }while(P!=first(L) && P->info.ID != x.ID);

    }
    if(P->info.name!=x.name){
        return NULL;
    }
    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if(first(L)!=NULL){
        if(next(first(L))==first(L)){
            P = first(L);
            first(L)=NULL;
            last(L)=NULL;
        }else{
            P = first(L);
            prev(next(P))=last(L);
            next(last(L))=next(P);
            first(L)=next(P);
            next(P)=NULL;
            prev(P)=NULL;
        }
    //----------------------------------------
    }
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if(first(L)!=NULL){
        if(next(first(L))==first(L)){
            deleteFirst(L,P);
        }else{
            P = last(L);
            prev(first(L))=prev(P);
            next(prev(P))=first(L);
            prev(P)=NULL;
            next(P)=NULL;

        }
    }
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
        if(first(L)!=NULL){
            if(Prec!=NULL){
                if(Prec==last(L)){
                    insertLast(L,P);
                }else{
                    next(P)=next(Prec);
                    prev(next(P))=P;
                    next(Prec)=P;
                    prev(P)=Prec;
                }
            }
        }
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if(first(L)!=NULL){
        if(Prec!=NULL){
            if(Prec==last(L)){
                deleteFirst(L,P);
            }else if(next(Prec)==last(L)){
                deleteLast(L,P);
            }else{
                P=next(Prec);
                next(Prec)=next(P);
                prev(next(P))=Prec;
                next(P)=NULL;
                prev(P)=NULL;
            }
        }
    }else{
        insertFirst(L,P);
    }

    //----------------------------------------
}

