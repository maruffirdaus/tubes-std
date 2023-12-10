//
//  hospital.cpp
//  
//
//  Created by Farizsyach Razif Januar on 10/12/23.
//

#include <iostream>
#include "hospital.h"
using namespace std;

void insertDate(ListDate &LD, adrDate d){
    if (first(LD) == NULL){
        first(LD) = d;
    }else{
        next(d) = first(LD);
        first(LD) = d;
    }
}
void showDate(ListDate LD);
void deleteDate(ListDate &LD);
adrDate searchDate(ListDate LD, date d);
void insertBaby(ListBaby &LB, adrBaby b);
void connectList(ListDate &LD, ListBaby LB);
void showAll(ListDate LD);
adrBaby searchBaby(ListDate LD, date d, name b);
void deleteBaby(ListDate &LD, date d, name b);
void showLowestBirthRate(ListDate LD);
