#include "hospital.h"

adrDate createElmDate(string tgl){
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

    if (first(babyList(datePointer)) != NULL) {
        while (first(babyList(datePointer)) != NULL) {
            adrBaby b = prev(first(babyList(datePointer));
            if (first(babyList(datePointer) != b) {
                prev(first(babyList(datePointer)) = prev(b);
                next(prev(b)) = first(babyList(datePointer));
            } else {
                first(babyList(datePointer)) = NULL;
            }
            delete b;
        }
    }
}

adrDate searchDate(ListDate LD, date d);
void insertBaby(ListBaby &LB, adrBaby b);
void connectList(ListDate &LD, ListBaby LB);
void showAll(ListDate LD);
adrBaby searchBaby(ListDate LD, date d, name b);
void deleteBaby(ListDate &LD, date d, name b);
void showLowestBirthRate(ListDate LD);