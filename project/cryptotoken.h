#pragma once
#include "cryptocurrency.h"
using namespace std;

class CryptoToken : public CryptoCurrency{
public:
    CryptoToken(string cID, string cname, float am, float ex_rate, float ex_fee);
    void Mine();
    virtual void getMoreTokens() = 0;
};