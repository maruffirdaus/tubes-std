#include "hospital.h"

/*adrDate createElmDate(date d)
{
    adrDate pDate = new elmDate;
    info(pDate) = d;
    next(pDate) = NULL;
    first(babyList(pDate)) = NULL;
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
    cout << "  Daftar Tanggal" << endl;
    cout << "--------------------------------" << endl << endl;
    if (first(LD) != NULL) {
        adrDate d = first(LD);
        while (d != NULL) {
            cout << " " << info(d) << endl;
            d = next(d);
        }
        cout << endl;
    } else {
        cout << " Data tanggal kelahiran kosong." << endl << endl;
    }
    cout << "--------------------------------" << endl << endl;
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
    if (first(LD) != NULL) {
        adrDate pDate = first(LD);
        while (info(pDate) != d && next(pDate) != NULL){
            pDate = next(pDate);
        }
        if (info(pDate) == d) {
            return pDate;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
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
            ListBaby LB = babyList(pDate);
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
    cout << "  Daftar Tanggal dan Bayi yang Lahir" << endl;
    cout << "--------------------------------" << endl << endl;
    if (first(LD) != NULL) {
        adrDate d = first(LD);
        while (d != NULL) {
            cout << " Tanggal: " << info(d) << endl;
            ListBaby LB = babyList(d);
            if (first(LB) != NULL) {
                adrBaby b = first(LB);
                int i = 1;
                do {
                    cout << " " << i << ". " << info(b) << endl;
                    b = next(b);
                    i++;
                } while (b != first(LB));
            } else {
                cout << " Tidak terdapat bayi yang lahir pada tanggal ini." << endl;
            }
            cout << endl;
            d = next(d);
        }
    } else {
        cout << " Data tanggal kelahiran kosong." << endl << endl;
    }
    cout << "--------------------------------" << endl << endl;
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

void deleteBaby(ListDate &LD, date d, ListBaby &LB, name b)
{
    adrDate pDate = searchDate(LD, d);
    if (pDate != NULL) {
        ListBaby LBTemp = babyList(pDate);
        if (first(LBTemp) != NULL) {
            adrBaby pBaby = searchBaby(LBTemp, b);
            if (pBaby != NULL) {
                if (first(LBTemp) != pBaby && next(pBaby) != first(LBTemp)) {
                    next(prev(pBaby)) = next(pBaby);
                    prev(next(pBaby)) = prev(pBaby);
                } else if (next(pBaby) != first(LBTemp)) {
                    first(LBTemp) = next(pBaby);
                    prev(first(LBTemp)) = prev(pBaby);
                    next(prev(pBaby)) = first(LBTemp);
                } else if (first(LBTemp) != pBaby) {
                    next(prev(pBaby)) = first(LBTemp);
                    prev(first(LBTemp)) = prev(pBaby);
                } else {
                    first(babyList(pDate)) = NULL;
                }
            }
            pBaby = searchBaby(LB, b);
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
            }
            delete pBaby;
        }
    }
}

void showLowestBirthRate(ListDate LD)
{
    cout << "  Tanggal dengan Kelahiran Terendah" << endl;
    cout << "--------------------------------" << endl << endl;
    if (first(LD) != NULL) { 
    adrDate pMin;
    int i;
    int min = 1874919423;
    adrDate pDate = first(LD);
    while (pDate != NULL) {
        i = 0;
        if (first(babyList(pDate)) != NULL) {
        adrBaby pBaby = first(babyList(pDate));
            do {
                i++;
                pBaby = next(pBaby);
            } while (pBaby != first(babyList(pDate)));
        }
        if (i < min) {
            pMin = pDate ; 
            min = i ;
        }
        pDate = next(pDate);
    }
    cout << " Tanggal " << info(pMin) << " sebanyak " << min << " kelahiran." << endl << endl;
    } else {
        cout << " Data tanggal kelahiran kosong." << endl << endl;
    }
    cout << "--------------------------------" << endl << endl;
}*/
adrDate createElmDate(date d){
    adrDate tgl = new elmDate;
    next(tgl) = NULL;
    info(tgl) = d;
    return tgl;
}
adrBaby createElmBaby(name b){
    adrBaby bayi = new elmBaby;
    nextB(bayi) = NULL;
    prevB(bayi) = NULL;
    info(bayi) = b;
    return bayi;
}
void insertDate(hospital &h, adrDate d){
    if (first(h) == NULL){
        first(h) = d;
    }else{
        next(d) = first(h);
        first(h) = d;
    }
}
void showDate(hospital h){
    cout << "  Daftar Tanggal" << endl;
       cout << "--------------------------------" << endl << endl;
       if (first(h) != NULL) {
           adrDate d = first(h);
           while (d != NULL) {
               cout << " " << info(d) << endl;
               d = next(d);
           }
           cout << endl;
       } else {
           cout << " Data tanggal kelahiran kosong." << endl << endl;
       }
       cout << "--------------------------------" << endl << endl;
}
void removeBabyDate(hospital &h, date d){
    adrDate pDate = searchDate(h, d);
    adrBaby b = firstBaby(pDate);
    do {
        adrBaby del = b;
        b = nextB(b);
        prevB(b) = prevB(del);
        nextB(prevB(b)) = b;
        nextB(del) = NULL;
        
    } while (nextB(firstBaby(pDate)) == b);
    firstBaby(pDate) = NULL;
}
void deleteDate(hospital &h, date d){
    adrDate pDate = searchDate(h, d);
    if (pDate == first(h)){
        if (firstBaby(pDate) != NULL){
            removeBabyDate(h, d);
        }
        first(h) = next(pDate);
        next(pDate) = NULL;
    }else if ( next(pDate) != NULL and pDate != first(h)){
        if (firstBaby(pDate) != NULL){
            removeBabyDate(h, d);
        }
        adrDate prec = first(h);
        while (next(prec) != pDate){
            prec = next(prec);
        }
        next(prec) = next(pDate);
        next(pDate) = NULL;
    }else{
        adrDate prec = first(h);
        while (next(prec) != pDate){
            prec = next(prec);
        }
        next(prec) = next(pDate);
        next(pDate) = NULL;
    }
}
adrDate searchDate(hospital &h, date d){
    adrDate pDate = first(h);
    while (pDate != NULL) {
        if (info(pDate) == d) {
            return pDate;
        }
        pDate = next(pDate);
    }
    return NULL;
}
void insertBaby(hospital &h, name b, adrDate pDate){
    adrBaby bayi;
    bayi = createElmBaby(b);

    if (firstBaby(pDate) == NULL) {
        // The list is empty, make 'bayi' the only element in the list.
        firstBaby(pDate) = bayi;
        nextB(bayi) = bayi;
        prevB(bayi) = bayi;
    } else if(nextB(firstBaby(pDate)) == firstBaby(pDate)){
        // Insert 'bayi' after the last baby with the same birth date.
        prevB(bayi) = firstBaby(pDate);
        nextB(bayi) = firstBaby(pDate);
        nextB(firstBaby(pDate)) = bayi;
        prevB(firstBaby(pDate)) = bayi;
    }else{
        adrBaby last = prevB(firstBaby(pDate));
        nextB(last) = bayi;
        prevB(bayi) = last;
        prevB(firstBaby(pDate)) = bayi;
        nextB(bayi) = firstBaby(pDate);
    }
}
void connectList(hospital &h, name b,date d){
    adrDate pDate = searchDate(h, d);
    if( pDate != NULL){
        insertBaby(h, b, pDate);
    }else{
        pDate = createElmDate(d);
        insertDate(h, pDate);
        insertBaby(h, b, pDate);
    }
}
void showAll(hospital h){
    cout << "  Daftar Tanggal dan Bayi yang Lahir" << endl;
       cout << "--------------------------------" << endl << endl;
       if (first(h) != NULL) {
           adrDate d = first(h);
           while (d != NULL) {
               cout << " Tanggal: " << info(d) << endl;
               adrBaby b = firstBaby(d);
               if (firstBaby(d) != NULL) {
                   int i = 1;
                   do {
                       cout << " " << i << ". " << info(b) << endl;
                       b = nextB(b);
                       i++;
                   } while (b != firstBaby(d));
               } else {
                   cout << " Tidak terdapat bayi yang lahir pada tanggal ini." << endl;
               }
               cout << endl;
               d = next(d);
           }
       } else {
           cout << " Data tanggal kelahiran kosong." << endl << endl;
       }
       cout << "--------------------------------" << endl << endl;
}
adrBaby searchBaby(hospital &h, name b, date d)
{
    adrDate pDate = searchDate(h, d);
    adrBaby pBaby = firstBaby(pDate);
        while (info(pBaby) != b && nextB(pBaby) != firstBaby(pDate)) {
            pBaby = nextB(pBaby);
        }
        if (info(pBaby) == b) {
            return pBaby;
        } else {
            return NULL;
        }
}

void deleteBaby(hospital &h, date d, name b)
{
    adrDate pDate = searchDate(h, d);
    adrBaby pBaby = searchBaby(h, b, d);
    cout<<pDate <<" " << pBaby<<endl;
    if (pBaby != NULL and pDate != NULL){
        if (pBaby == firstBaby(pDate) and nextB(pBaby) == pBaby){
            firstBaby(pDate) = NULL;
        }else if (pBaby == firstBaby(pDate)){
            cout<<"del first\n";
            firstBaby(pDate) = nextB(pBaby);
            nextB(pBaby) = NULL;
            prevB(firstBaby(pDate)) = prevB(pBaby);
            nextB(prevB(pBaby)) = firstBaby(pDate);
            prevB(pBaby) = NULL;
        }else if (pBaby == prevB(firstBaby(pDate))){
            cout<<"del last\n";
            nextB(prevB(pBaby)) = firstBaby(pDate);
            prevB(firstBaby(pDate)) = prevB(pBaby);
            prevB(pBaby) = NULL;
            nextB(pBaby) = NULL;
        }else{
            cout<<"del aft\n";
            prevB(nextB(pBaby)) = prevB(pBaby);
            nextB(prevB(pBaby)) = nextB(pBaby);
            prevB(pBaby) = NULL; nextB(pBaby) = NULL;
        }
    }
    
     /*if (pDate != NULL) {
        ListBaby LBTemp = babyList(pDate);
        if (first(LBTemp) != NULL) {
            adrBaby pBaby = searchBaby(LBTemp, b);
            if (pBaby != NULL) {
                if (first(LBTemp) != pBaby && next(pBaby) != first(LBTemp)) {
                    next(prev(pBaby)) = next(pBaby);
                    prev(next(pBaby)) = prev(pBaby);
                } else if (next(pBaby) != first(LBTemp)) {
                    first(LBTemp) = next(pBaby);
                    prev(first(LBTemp)) = prev(pBaby);
                    next(prev(pBaby)) = first(LBTemp);
                } else if (first(LBTemp) != pBaby) {
                    next(prev(pBaby)) = first(LBTemp);
                    prev(first(LBTemp)) = prev(pBaby);
                } else {
                    first(babyList(pDate)) = NULL;
                }
            }
            pBaby = searchBaby(LB, b);
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
            }
            delete pBaby;
        }
    } */
}

void showLowestBirthRate(hospital h)
{
    cout << "  Tanggal dengan Kelahiran Terendah" << endl;
    cout << "--------------------------------" << endl << endl;
    if (first(h) != NULL) {
        adrDate pMin = NULL;
        int i;
        int min = 1874919423;
        adrDate pDate = first(h);
        while (pDate != NULL) {
            i = 0;
            if (firstBaby(pDate) != NULL) {
                adrBaby pBaby = firstBaby(pDate);
                do {
                    i++;
                    pBaby = nextB(pBaby);
                } while (pBaby != firstBaby(pDate));
            }
            if (i < min) {
                pMin = pDate ;
                min = i ;
            }
            pDate = next(pDate);
        }
        cout << " Tanggal " << info(pMin) << " sebanyak " << min << " kelahiran." << endl << endl;
    } else {
        cout << " Data tanggal kelahiran kosong." << endl << endl;
    }
    cout << "--------------------------------" << endl << endl;
}
