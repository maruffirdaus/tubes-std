#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#define first(L) (L).first
#define info(P) (P)->info
#define next(P) (P)->next
//#define babyList(P) (P)->babyList
#define prev(P) (P)->prev

#define nextB(P) (P)->nextB
#define prevB(P) (P)->prevB
#define firstBaby(P) (P)->firstBaby


using namespace std;

typedef string name;
typedef struct elmBaby *adrBaby;
/*struct elmBaby
{
    name info;
    adrBaby next;
    adrBaby prev;
}; */
struct elmBaby
{
    name info;
    adrBaby nextB;
    adrBaby prevB;
};
/*struct ListBaby
{
    adrBaby first;
};*/

typedef string date;
typedef struct elmDate *adrDate;
/*struct elmDate
{
    date info;
    adrDate next;
    ListBaby babyList;
}; */
struct elmDate
{
    date info;
    adrDate next;
    adrBaby firstBaby;
};
/*struct ListDate
{
    adrDate first;
}; */
struct hospital
{
    adrDate first;
};


/*adrDate createElmDate(date d);
adrBaby createElmBaby(name b);
void insertDate(ListDate &LD, adrDate d);
void showDate(ListDate LD);
void deleteDate(ListDate &LD, date d, ListBaby &LB);
adrDate searchDate(ListDate LD, date d);
void insertBaby(ListBaby &LB, name b, ListDate &LD, date d);
void connectList(adrBaby b, ListDate &LD, date d);
void showAll(ListDate LD);
adrBaby searchBaby(ListBaby LB, name b);
void deleteBaby(ListDate &LD, date d, ListBaby &LB, name b);
void showLowestBirthRate(ListDate LD);*/

adrDate createElmDate(date d);
adrBaby createElmBaby(name b);
void insertDate(hospital &h, adrDate d);
void showDate(hospital h);
void deleteDate(hospital &h, date d);
void removeBabyDate(hospital &h, date d);
adrDate searchDate(hospital &h, date d);
void insertBaby(hospital &h, name b, adrDate pdate);
void connectList(hospital &h, name b, date d);
void showAll(hospital h);
adrBaby searchBaby(hospital &h, name b, date d);
void deleteBaby(hospital &h, date d, name b);
void showLowestBirthRate(hospital h);

#endif