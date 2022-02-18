#pragma once
#include "cryptocurrency.h"
using namespace std;

class CryptoCoin : public CryptoCurrency{
private:
    char * feature;
public:
    CryptoCoin(string cID, string cname, float am, float ex_rate, float ex_fee, string some_feature);
    ~CryptoCoin();
    void toString();
    void Mine();
    virtual void getMoreCoins() = 0;
};