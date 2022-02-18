#include "digitalcurrency.h"
#include <iostream>
using namespace std;

DigitalCurrency::DigitalCurrency(string cID, string cname, float am, float ex_rate, float ex_fee, string feature):  
    CryptoCoin(cID, cname, am, ex_rate, ex_fee, feature) {}

void DigitalCurrency::toString(){
    cout<<"<DIGITAL CURRENCY>\n";
    CryptoCoin::toString();
}

void DigitalCurrency::getMoreCoins() {}