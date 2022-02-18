#pragma once
#include "wallet.h"
#include "cryptocurrency.h"
#include "fiatmoney.h"
using namespace std;

class Market{
private:
    float pSell, pBuy;
public:
    Market(float ps, float pb);
    void trade(Wallet<CryptoCurrency*> * W, Wallet<FiatMoney*> * PORTFEL);
};