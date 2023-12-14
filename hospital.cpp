#include "hospital.h"

adrDate createElmDate(date d)
{
    adrDate pDate = new elmDate;
    info(pDate) = d;
    next(pDate) = NULL;
    return pDate;
}

adrBaby createElmBaby(name b)
{
    adrBaby pBaby = new elmBaby;
    info(pBaby) = b;
    next(pBaby) = NULL;
    return pBaby;
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
        cout << "  Daftar Tanggal" << endl;
        cout << "--------------------------------" << endl;
        while (d != NULL) {
            cout << info(d) << endl;
            d = next(d);
        }
        cout << "--------------------------------" << endl;
    }
}

void deleteDate(ListDate &LD, date d, ListBaby &LB)
{
    adrDate pDate = searchDate(LD, d);
    if (first(LD) != NULL) {
        adrDate pDate = searchDate(LD, d);
        if (first(LD) != pDate && next(pDate) != NULL) {
            adrDate d = first(LD);
            while (next(d) != pDate) {
                d = next(d);
            }
            next(d) = next(pDate);
        } else if (next(pDate) != NULL) {
            first(LD) = next(pDate);
        } else if (first(LD) != pDate) {
            adrDate d = first(LD);
            while (next(d) != pDate) {
                d = next(d);
            }
            next(d) = NULL;
        } else {
            first(LD) = NULL;
        }
        next(pDate) = NULL;
        ListBaby LBTemp = babyList(pDate);
        delete pDate;
        while (first(LBTemp) != NULL) {
            adrBaby b = first(LBTemp);
            if (next(b) == b) {
                first(LBTemp) = NULL;
            } else {
                first(LBTemp) = next(b);
                prev(first(LBTemp)) = prev(b);
                next(prev(b)) = first(LBTemp);
            }
            adrBaby pBaby = searchBaby(LB, info(b));
            if (pBaby != NULL) {
                if (first(LB) != pBaby && next(pBaby) != first(LB)) {
                    next(prev(pBaby)) = next(pBaby);
                    prev(next(pBaby)) = prev(pBaby);
                } else if (next(pBaby) != first(LB)) {
                    first(LB) = next(pBaby);
                    prev(first(LB)) = prev(pBaby);
                    next(prev(pBaby)) = first(LB);
                } else if (first(LB) != pBaby) {
                    next(prev(pBaby)) = first(LB);
                    prev(first(LB)) = prev(pBaby);
                } else {
                    first(LB) = NULL;
                }
                delete pBaby;
            }
            delete b;
        }
    }
}

adrDate searchDate(ListDate LD, date d)
{
    adrDate pDate = first(LD);
    while (info(pDate) != d and pDate != NULL){
        pDate = next(pDate);
    }
    return pDate;
}

void insertBaby(ListBaby &LB, name b, ListDate &LD, date d)
{
    adrBaby pBaby = createElmBaby(b);
    if (first(LB) == NULL) {
        first(LB) = pBaby;
        next(first(LB)) = first(LB);
        prev(first(LB)) = first(LB);
    } else {
        next(pBaby) = first(LB);
        prev(pBaby) = prev(first(LB));
        prev(first(LB)) = pBaby;
        next(prev(pBaby)) = pBaby;
        first(LB) = pBaby;
    }
    connectList(pBaby, LD, d);
}

void connectList(adrBaby b, ListDate &LD, date d)
{
    adrDate pDate = searchDate(LD, d);
    if (pDate == NULL) {
        adrDate pDateNull = createElmDate(d);
        insertDate(LD, pDateNull);
        ListBaby LB;
        first(LB) = createElmBaby(info(b));
        next(first(LB)) = first(LB);
        prev(first(LB)) = first(LB);
        babyList(pDateNull) = LB;
    } else {
        if (first(babyList(pDate)) == NULL) {
            ListBaby LB;
            first(LB) = createElmBaby(info(b));
            next(first(LB)) = first(LB);
            prev(first(LB)) = first(LB);
            babyList(pDate) = LB;
        } else {
            ListBaby LB = babyList(pDate);
            adrBaby pBaby = createElmBaby(info(b));
            next(pBaby) = first(LB);
            prev(pBaby) = prev(first(LB));
            prev(first(LB)) = pBaby;
            next(prev(pBaby)) = pBaby;
            first(LB) = pBaby;
        }
    }
}

void showAll(ListDate LD)
{
    if (first(LD) != NULL) {
        adrDate d = first(LD);
        cout << "  Daftar Tanggal dan Bayi yang Lahir" << endl;
        cout << "--------------------------------" << endl;
        while (d != NULL) {
            cout << " Tanggal: " << info(d) << endl;
            cout << "----------------" << endl;
            ListBaby LB = babyList(d);
            adrBaby b = first(LB);
            int i = 1;
            do {
                cout << " Nama bayi " << i << " : " << info(b) << endl;
                b = next(b);
                i++;
            } while (b != first(LB));
            cout << endl;
            d = next(d);
        }
        cout << "--------------------------------" << endl;
    }
}

adrBaby searchBaby(ListBaby LB, name b)
{
    adrBaby pBaby = first(LB);
    while (info(pBaby) != b && next(pBaby) != first(LB)) {
        pBaby = next(pBaby);
    }
    if (info(pBaby) == b) {
        return pBaby;
    } else {
        return NULL;
    }
}

void deleteBaby(ListDate &LD, date d, name b)
{
    adrDate pDate = searchDate(LD,d);
    adrBaby pBaby = searchBaby(LD,d,b);
    adrBaby firstB = first(babyList(pDate));

    if (next(pBaby) == firstB){
        next(firstB) = prev(pBaby);
        next(prev(pBaby)) = firstB;
    }else if (firstB == pBaby){
        prev(next(pBaby)) = prev(firstB);
        next(prev(firstB)) = next(pBaby);
        first(babyList(pDate)) = next(pBaby);
        next(pBaby) = NULL;
    }else{
        next(prev(pBaby)) = next(pBaby);
        prev(next(pBaby)) = prev(pBaby);
        prev(pBaby) = NULL ; next(pBaby) = NULL;
    }
}

void showLowestBirthRate(ListDate LD)
{
    adrDate pMin;
    int i;
    int min = 9999999999999999;
    adrDate pDate = first(LD);
    while (pDate != NULL) {
        i = 0;
        adrBaby pBaby = first(babyList(pDate));
        do {
            i++;
            pBaby = next(pBaby);
        } while (pBaby != first(babyList(pDate)));
        if (i < min) {
            pMin = pDate ; 
            min = i ;
        }
        pDate = next(pDate);
    }
    cout << "  Tanggal dengan Kelahiran Terendah" << endl;
    cout << "--------------------------------" << endl;
    cout << info(pMin) << endl;
    cout << "--------------------------------" << endl;
}