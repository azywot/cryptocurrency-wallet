#include "storeofvalue.h"
#include <iostream>
using namespace std;

StoreOfValue::StoreOfValue(string cID, string cname, float am, float ex_rate, float ex_fee, string feature):  CryptoCoin(cID, cname, am, ex_rate, ex_fee, feature) {}

void StoreOfValue::toString(){
    cout<<"<STORE OF VALUE>\n";
    CryptoCoin::toString();
}

void StoreOfValue::getMoreCoins() {}