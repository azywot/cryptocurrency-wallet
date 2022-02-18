#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio> //printf
#include <cmath>
#include "market.h"
using namespace std;

Market::Market(float ps, float pb) {pSell=ps; pBuy=pb; srand (time(NULL));}

void Market::trade(Wallet<CryptoCurrency*> * W, Wallet<FiatMoney*> * PORTFEL){
        int r; //random variable 
        float profit, fee, def, p;
        auto M = PORTFEL->contents.begin();
        auto coin = W->contents.begin();

        //SELL
        while (coin != W->contents.end()){
            r = rand();
            if ((float)r/(float)RAND_MAX <= pSell){
                def = float(rand()%1000+1)/100;
                if ((*coin)->GetAmount()>def){
                    printf("SELL %.2f units of %s", def, (*coin)->GetName());
                    profit = (*coin)->GetExchangeRate()*def;
                    fee =  (*coin)->GetExchangeFee()*(*coin)->GetExchangeRate()*def;
                    (*coin)->AddAmount(float(-def));
                    coin++;
                }
                else{
                    def = (*coin)->GetAmount();
                    printf("SELL %.2f units of %s", def, (*coin)->GetName());
                    profit = (*coin)->GetExchangeRate()*def;
                    fee =  (*coin)->GetExchangeFee()*(*coin)->GetExchangeRate()*def;
                    (*coin)->AddAmount(float(-def));
                    *W -= *coin;
                    cout<<" -> SOLD ALL!";
                }

                (*M)->AddAmount(float(profit-fee));
                printf(" (sold for %.2f%s, fee: %.2f%s -> added: %.2f%s)\n", 
                    profit,(*M)->GetID(), fee, (*M)->GetID(), profit-fee, (*M)->GetID());
            }
            else{
                cout<<"Keep "<<(*coin)->GetName()<<" as it is\n";
                coin++;
            }
        }

        //BUY
        for (const auto& coin : W->contents){
            r = rand();
            if ((float)r/(float)RAND_MAX <= pBuy){
                cout<<"BUY "<<coin->GetName();
                p = float(rand()%1000+1)/100;
                fee = p*coin->GetExchangeFee()*coin->GetExchangeRate();
                (*M)->AddAmount(float(-p*coin->GetExchangeRate()-fee));
                coin->AddAmount(p);
                printf(" (bought %.2f%s for %.2f%s, fee: %.2f%s -> removed: %.2f%s)\n", 
                    p, coin->GetID(), p*coin->GetExchangeRate(), (*M)->GetID(), fee, (*M)->GetID(), 
                    p*coin->GetExchangeRate()+fee, (*M)->GetID());
            }
            else {cout<<"Don't buy "<<coin->GetName()<<"\n";}
        }
    }