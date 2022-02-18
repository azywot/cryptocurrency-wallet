#pragma once
#include "currency.h"
using namespace std;

class CryptoCurrency : public Currency{
public:
    CryptoCurrency(string cID, string cname, float am, float ex_rate, float ex_fee);
    void someVoid();
    virtual void Mine()=0;
};