#include <iostream>
#include <string>
#include <Windows.h> //Sleep
#include "all_currencies.h"
#include "market.h"
#include "market.cpp"
using namespace std;

void AddRandomCoin(Wallet<CryptoCurrency*> *W){
    int r = rand()%8;
    float amount = float(rand()%1000+1)/100;
                    /*short form, name, amount, exchange rate, exchange fee, feature(*)*/
    switch(r){
        case 0:
            *W += new StoreOfValue("BTC", "Bitcoin", amount, 63620.70, 0.012, "stonks");
            return;
        case 1:
            *W += new DigitalCurrency("CN", "Coinye", amount, 6.08, 0.13, "gold digger");
            return;
        case 2:
            *W += new UtilityToken("ETH", "Ethereum", amount, 4606.46, 0.095, "McD");
            return;
        case 3:
            *W += new ScamToken("SCA", "Scammereum", amount, 0.12, 2.137, "McAfee");
            return;
        case 4:
            *W += new StoreOfValue("BEC", "Beercoin", amount, 14112.10, 0.13, "spills");
            return;
        case 5:
            *W += new DigitalCurrency("DGM", "DigiMax", amount, 13.08, 0.125, "mega digital");
            return;
        case 6:
            *W += new UtilityToken("FF", "Funfair", amount, 0.2, 0.035, "Six flags");
            return;
        case 7:
            *W += new ScamToken("ST", "Squid Token", amount, 10.25, 1.9701, "Front Man");
            return;
    }
}

int main()
{
    srand (time(NULL));
    string username, id;
    int n, r;
    float amount, pSell, pBuy;

    cout<<"Pleased to see you, before trading, please provide the following information:\n";
    cout<<"username: ";
    getline(cin, username);
    cout<<"ID: ";
    getline(cin, id);

    Wallet<CryptoCurrency*> cWallet(id, username);
    Wallet<FiatMoney*> portmonetka(id, username);
    cWallet.printHello();

    cout<<"number of crypto-currency coins: ";
    cin>>n;

    cout<<"\nADDING COINS TO THE WALLET...\n";
    for(int i=0; i<n; i++)
        AddRandomCoin(&cWallet);
    
    cout<<"\nEnter the amount of dollars you want to have in the wallet: ";
    cin>>amount;
    portmonetka += new FiatMoney("USD", "Dollar", amount, 1.00, 0, "USA");

    cout<<"pSell (large pls): ";
    cin>>pSell;
    cout<<"pBuy (small pls): ";
    cin>>pBuy;
    Market* M = new Market(pSell, pBuy);

    cout<<"\nCRYPTOWALLET:\n";
    cWallet.printContents();
    cout<<"\nWALLET:\n";
    portmonetka.printContents();

    cout<<"\nAll set! Trading will start in 5 seconds...\n";
    Sleep(5000);

    while (cWallet.NoCoins()!=0)
    {
        M->trade(&cWallet, &portmonetka);
        cout<<"___________________"<<endl;
        cout<<"\nCRYPTOWALLET:\n";
        cWallet.printContents();
        cout<<"\nWALLET:\n";
        portmonetka.printContents();
        cout<<"\nTRADING TIME...\n";
        
    }
    cout<<"\nTHE END!\n";
    return 0;
}