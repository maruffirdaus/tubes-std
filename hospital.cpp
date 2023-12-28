#include "hospital.h"

adrDate createElmDate(date d) {
    adrDate pDate = new elmDate;
    info(pDate) = d;
    next(pDate) = NULL;
    firstBaby(pDate) = NULL;
    return pDate;
}

adrBaby createElmBaby(name b) {
    adrBaby pBaby = new elmBaby;
    nextB(pBaby) = NULL;
    prevB(pBaby) = NULL;
    info(pBaby) = b;
    return pBaby;
}

void insertDate(hospital &h, adrDate pDate) {
    if (first(h) == NULL){
        first(h) = pDate;
    }else{
        next(pDate) = first(h);
        first(h) = pDate;
    }
}

void showDate(hospital h) {
    cout << "  Daftar Tanggal" << endl;
       cout << "--------------------------------" << endl << endl;
       if (first(h) != NULL) {
           adrDate pDate = first(h);
           while (pDate != NULL) {
               cout << " " << info(pDate) << endl;
               pDate = next(pDate);
           }
           cout << endl;
       } else {
           cout << " Data tanggal kelahiran kosong." << endl << endl;
       }
       cout << "--------------------------------" << endl << endl;
}

void removeBabyDate(hospital &h, adrDate pDate) {
    adrBaby pBaby = firstBaby(pDate);
    while (nextB(firstBaby(pDate)) != pBaby) {
        adrBaby del = pBaby;
        pBaby = nextB(pBaby);
        prevB(pBaby) = prevB(del);
        nextB(prevB(pBaby)) = pBaby;
        delete del;
    }
    firstBaby(pDate) = NULL;
    delete pBaby;
}

void deleteDate(hospital &h, date d) {
    adrDate pDate = searchDate(h, d);
    if (pDate != NULL) {
        if (firstBaby(pDate) != NULL){
            removeBabyDate(h, pDate);
        }
        if (pDate == first(h)) {
            first(h) = next(pDate);
        } else if (next(pDate) != NULL && pDate != first(h)) {
            adrDate prec = first(h);
            while (next(prec) != pDate){
                prec = next(prec);
            }
            next(prec) = next(pDate);
        } else {
            adrDate prec = first(h);
            while (next(prec) != pDate){
                prec = next(prec);
            }
            next(prec) = next(pDate);
        }
        delete pDate;
    }
}

adrDate searchDate(hospital &h, date d) {
    adrDate pDate = first(h);
    while (pDate != NULL) {
        if (info(pDate) == d) {
            return pDate;
        }
        pDate = next(pDate);
    }
    return NULL;
}

void insertBaby(name b, adrDate pDate) {
    adrBaby pBaby = createElmBaby(b);
    if (firstBaby(pDate) == NULL) {
        // The list is empty, make 'pBaby' the only element in the list.
        firstBaby(pDate) = pBaby;
        nextB(pBaby) = pBaby;
        prevB(pBaby) = pBaby;
    } else {
        // Insert 'pBaby' after the last baby with the same birth date.
        adrBaby last = prevB(firstBaby(pDate));
        nextB(last) = pBaby;
        prevB(pBaby) = last;
        prevB(firstBaby(pDate)) = pBaby;
        nextB(pBaby) = firstBaby(pDate);
    }
}

void connectList(hospital &h, name b, date d) {
    adrDate pDate = searchDate(h, d);
    if (pDate != NULL) {
        insertBaby(b, pDate);
    } else {
        pDate = createElmDate(d);
        insertDate(h, pDate);
        insertBaby(b, pDate);
    }
}

void showAll(hospital h) {
    cout << "  Daftar Tanggal dan Bayi yang Lahir" << endl;
       cout << "--------------------------------" << endl << endl;
       if (first(h) != NULL) {
           adrDate pDate = first(h);
           while (pDate != NULL) {
               cout << " Tanggal: " << info(pDate) << endl;
               adrBaby pBaby = firstBaby(pDate);
               if (firstBaby(pDate) != NULL) {
                   int i = 1;
                   do {
                       cout << " " << i << ". " << info(pBaby) << endl;
                       pBaby = nextB(pBaby);
                       i++;
                   } while (pBaby != firstBaby(pDate));
               } else {
                   cout << " Tidak terdapat bayi yang lahir pada tanggal ini." << endl;
               }
               cout << endl;
               pDate = next(pDate);
           }
       } else {
           cout << " Data tanggal kelahiran kosong." << endl << endl;
       }
       cout << "--------------------------------" << endl << endl;
}

adrBaby searchBaby(hospital &h, name b, date d) {
    adrDate pDate = searchDate(h, d);
    adrBaby pBaby = NULL;
    if (pDate != NULL) {
        pBaby = firstBaby(pDate);
    }
    if (pDate != NULL && pBaby != NULL) { 
        while (info(pBaby) != b && nextB(pBaby) != firstBaby(pDate)) {
            pBaby = nextB(pBaby);
        }
        if (info(pBaby) == b) {
            return pBaby;
        } else {
            return NULL;
        }
    } else {
        return NULL;
    }
}

void deleteBaby(hospital &h, date d, name b) {
    adrDate pDate = searchDate(h, d);
    adrBaby pBaby = searchBaby(h, b, d);
    if (pBaby != NULL && pDate != NULL){
        if (pBaby == firstBaby(pDate) && nextB(pBaby) == pBaby) {
            firstBaby(pDate) = NULL;
        } else if (pBaby == firstBaby(pDate)) {
            firstBaby(pDate) = nextB(pBaby);
            nextB(pBaby) = NULL;
            prevB(firstBaby(pDate)) = prevB(pBaby);
            nextB(prevB(pBaby)) = firstBaby(pDate);
            prevB(pBaby) = NULL;
        } else if (pBaby == prevB(firstBaby(pDate))) {
            nextB(prevB(pBaby)) = firstBaby(pDate);
            prevB(firstBaby(pDate)) = prevB(pBaby);
            prevB(pBaby) = NULL;
            nextB(pBaby) = NULL;
        } else {
            prevB(nextB(pBaby)) = prevB(pBaby);
            nextB(prevB(pBaby)) = nextB(pBaby);
            prevB(pBaby) = NULL; nextB(pBaby) = NULL;
        }
    }
}

void showLowestBirthRate(hospital h) {
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
