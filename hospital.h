#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <iostream>
#define first(L) (L).first
#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define nextB(P) (P)->nextB
#define prevB(P) (P)->prevB
#define firstBaby(P) (P)->firstBaby

using namespace std;

typedef string name;
typedef struct elmBaby *adrBaby;
struct elmBaby
{
    name info;
    adrBaby nextB;
    adrBaby prevB;
};

typedef string date;
typedef struct elmDate *adrDate;
struct elmDate
{
    date info;
    adrDate next;
    adrBaby firstBaby;
};
struct hospital
{
    adrDate first;
};

adrDate createElmDate(date d);
adrBaby createElmBaby(name b);
void insertDate(hospital &h, adrDate pDate);
void showDate(hospital h);
void deleteDate(hospital &h, date d);
void removeBabyDate(hospital &h, adrDate pDate);
adrDate searchDate(hospital &h, date d);
void insertBaby(name b, adrDate pDate);
void connectList(hospital &h, name b, date d);
void showAll(hospital h);
adrBaby searchBaby(hospital &h, name b, date d);
void deleteBaby(hospital &h, date d, name b);
void showLowestBirthRate(hospital h);

#endif