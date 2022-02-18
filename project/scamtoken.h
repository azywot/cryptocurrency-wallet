#pragma once
#include "cryptotoken.h"
using namespace std;

class ScamToken : public CryptoToken{
private:
    char * scammer_name;
public:
    ScamToken(string cID, string cname, float am, float ex_rate, float ex_fee, string scammer);
    ~ScamToken();
    void toString();
    void getMoreTokens();
};
