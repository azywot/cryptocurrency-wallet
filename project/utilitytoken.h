#pragma once
#include "cryptotoken.h"
using namespace std;

class UtilityToken : public CryptoToken{
private:
    char * company;
public:
    UtilityToken(string cID, string cname, float am, float ex_rate, float ex_fee, string com);
    ~UtilityToken();
    void toString();
    void getMoreTokens();
};