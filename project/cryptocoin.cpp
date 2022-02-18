#include "cryptocoin.h"
#include <iostream>
using namespace std;

CryptoCoin::CryptoCoin(string cID, string cname, float am, float ex_rate, float ex_fee, string some_feature):  
    CryptoCurrency(cID, cname, am, ex_rate, ex_fee) {
    feature = new char[some_feature.length()+1];
    strcpy(feature, some_feature.c_str());
}

CryptoCoin::~CryptoCoin() {delete feature;}

void CryptoCoin::toString() {
    Currency::toString();
    cout<<"feature: "<<feature<<"\n";
}
void CryptoCoin::Mine() {}