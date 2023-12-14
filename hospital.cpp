#include "hospital.h"

adrDate createElmDate(date tgl){
    adrDate d = new elmDate;
    info(d) = tgl;
    next(d) = NULL;
}

void insertDate(ListDate &LD, adrDate d)
{
    if (first(LD) != NULL) {
        next(d) = first(LD);
        first(LD) = d;
    } else {
        first(LD) = d;
    }
}

void showDate(ListDate LD)
{
    if (first(LD) != NULL) {
        adrDate d = first(LD);
        while (d != NULL) {
            cout << info(d) << endl;
            d = next(d);
        }
    }
}

void deleteDate(ListDate &LD, date d)
{
    adrDate datePointer = searchDate(LD, d);

    if (first(LD) != NULL) {
        adrDate datePointer = searchDate(LD, d);
        if (first(LD) != datePointer && next(datePointer) != NULL) {
            adrDate d = first(LD);
            while (next(d) != datePointer) {
                d = next(d);
            }
            next(d) = next(datePointer);
        } else if (next(datePointer) != NULL) {
            first(LD) = next(datePointer);
        } else if (first(LD) != datePointer) {
            adrDate d = first(LD);
            while (next(d) != datePointer) {
                d = next(d);
            }
            next(d) = NULL;
        } else {
            first(LD) = NULL;
        }
        next(datePointer) = NULL;
        ListBaby LB = babyList(datePointer);
        delete datePointer;
        while (first(LB) != NULL) {
            adrBaby b = first(LB);
            if (next(b) == b) {
                first(LB) = NULL;
            } else {
                first(LB) = next(b);
                prev(first(LB)) = prev(b);
                next(prev(b)) = first(LB);
            }
            delete b;
        }
    }
}


adrDate searchDate(ListDate LD, date d){
    adrDate datePointer = first(LD);
    while (info(datePointer) != d and datePointer != NULL){
        datePointer = next(datePointer);
    }
    return datePointer;
}

void insertBaby(ListBaby &LB, adrBaby b){
    adrBaby Q = first(LB);
    if (first(LB) == NULL){
        first(LB) = b;
        next(b) = b;
        prev(b) = b;
    }else if(next(first(LB)) == first(LB)) {
        next(first(LB)) = b;
        next(b) = first(LB);
        prev(first(LB)) = b;
    }else {
        next(prev(first(LB))) = b;
        next(b) = first(LB);
        prev(first(LB)) = b;
    }
}
void connectList(ListDate &LD, ListBaby LB);
void showAll(ListDate LD);

adrBaby searchBaby(ListDate LD, date d, name b){
    adrDate tgl = searchDate(LD,d);
    if (tgl != NULL){
        adrBaby pBayi = first(babyList(tgl));
        while (pBayi != NULL and info(pBayi) != b){
            pBayi = next(pBayi);
        }
        return pBayi;
    }else{
        return NULL;
    }

}

void deleteBaby(ListDate &LD, date d, name b){
    adrDate pTgl = searchDate(LD,d);
    adrBaby pBayi = searchBaby(LD,d,b);
    adrBaby firstB = first(babyList(pTgl));

    if (next(pBayi) == firstB){
        next(firstB) = prev(pBayi);
        next(prev(pBayi)) = firstB;
    }else if (firstB == pBayi){
        prev(next(pBayi)) = prev(firstB);
        next(prev(firstB)) = next(pBayi);
        first(babyList(pTgl)) = next(pBayi);
        next(pBayi) = NULL;
    }else{
        next(prev(pBayi)) = next(pBayi);
        prev(next(pBayi)) = prev(pBayi);
        prev(pBayi) = NULL ; next(pBayi) = NULL;
    }

    

}
void showLowestBirthRate(ListDate LD){
    
}