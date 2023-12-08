#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#define first(L) (L).first
#define info(P) (P)->info
#define next(P) (P)->next
#define babyList(P) (P).babyList
#define prev(P) (P)->prev

using namespace std;

typedef string name;
typedef struct elmBaby *adrBaby;
struct elmBaby
{
    name info;
    adrBaby next;
    adrBaby prev;
};
struct ListBaby
{
    adrBaby first;
};

typedef string date;
typedef struct elmDate *adrDate;
struct elmDate
{
    date info;
    adrDate next;
    ListBaby babyList;
};
struct ListDate
{
    adrDate first;
};

void insertDate(ListDate &LD, adrDate d);
void showDate(ListDate LD);
void deleteDate(ListDate &LD);
adrDate searchDate(ListDate LD, date d);
void insertBaby(ListBaby &LB, adrBaby b);
void connectList(ListDate &LD, ListBaby LB);
void showAll(ListDate LD);
adrBaby searchBaby(ListDate LD, date d, name b);
void deleteBaby(ListDate &LD, date d, name b);
void showLowestBirthRate(ListDate LD);

#endif