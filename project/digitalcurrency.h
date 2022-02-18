#pragma once
#include "cryptocoin.h"
using namespace std;

class DigitalCurrency : public CryptoCoin{
public:
    DigitalCurrency(string cID, string cname, float am, float ex_rate, float ex_fee, string feature);
    void toString();
    void getMoreCoins();
};