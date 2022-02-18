#pragma once
#include "currency.h"
using namespace std;

class FiatMoney : public Currency{
private:
    char * country;
public:
    FiatMoney(string cID, string cname, float am, float ex_rate, float ex_fee, string cntry);
    ~FiatMoney();
    void someVoid();
    void toString();
};