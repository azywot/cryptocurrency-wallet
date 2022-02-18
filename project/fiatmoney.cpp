#include <iostream>
#include "fiatmoney.h"
using namespace std;

FiatMoney::FiatMoney(string cID, string cname, float am, float ex_rate, float ex_fee, string cntry):  Currency(cID, cname, am, ex_rate, ex_fee) {
    country = new char[cntry.length()+1];
    strcpy(country, cntry.c_str());
}

FiatMoney::~FiatMoney() {delete country;}

void FiatMoney::someVoid(){}

void FiatMoney::toString(){
    cout<<"<FIAT MONEY>\n";
    Currency::toString();
    cout<<"country: "<<country<<"\n";
}