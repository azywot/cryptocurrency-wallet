#include "utilitytoken.h"
#include <iostream>
#include <cstring>
using namespace std;

UtilityToken::UtilityToken(string cID, string cname, float am, float ex_rate, float ex_fee, string com):  
    CryptoToken(cID, cname, am, ex_rate, ex_fee){
    company = new char[com.length()+1];
    strcpy(company, com.c_str());
}

UtilityToken ::~UtilityToken() {delete company;}

void UtilityToken::toString(){
    cout<<"<UTILITY TOKEN>\n";
    Currency::toString();
    cout<<"company: "<<company<<"\n";
}

void UtilityToken::getMoreTokens() {}