#include "scamtoken.h"
#include <iostream>
#include <cstring>
using namespace std;

ScamToken::ScamToken(string cID, string cname, float am, float ex_rate, float ex_fee, string scammer):  
    CryptoToken(cID, cname, am, ex_rate, ex_fee){
    scammer_name = new char[scammer.length()+1];
    strcpy(scammer_name, scammer.c_str());
}

ScamToken::~ScamToken() {delete scammer_name;}

void ScamToken::toString()
    {
        cout<<"<SCAM TOKEN>\n";
        Currency::toString();
        cout<<"scammer: "<<scammer_name<<"\n";
    }
    
void ScamToken::getMoreTokens() {Currency::SetAmount(0.0);}