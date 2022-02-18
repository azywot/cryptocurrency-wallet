#include <string>
#include <iostream>
#include <cstdio> // printf
#include "currency.h"

Currency::Currency(string cID, string cname, float am, float ex_rate, float ex_fee){
    curr_ID = new char[cID.length()+1];
    strcpy(curr_ID, cID.c_str());

    curr_name = new char[cname.length()+1];
    strcpy(curr_name, cname.c_str());

    amount = new float;
    *amount = am;

    exchange_rate = new float;
    *exchange_rate = ex_rate;

    exchange_fee = new float;
    *exchange_fee = ex_fee;
}

Currency::~Currency(){
    delete curr_ID;
    delete curr_name;
    delete amount;
    delete exchange_rate;
}

void Currency::toString(){
    printf("%s (%s)\namount: %.2f\nexchange rate: %.2f\n", curr_name, curr_ID, *amount, *exchange_rate);
}

char * Currency::GetName() {return curr_name;}
char * Currency::GetID() {return curr_ID;}
float  Currency::GetExchangeRate(){return *exchange_rate;}
float  Currency::GetExchangeFee(){return *exchange_fee;}
float  Currency::GetAmount() {return *amount;}
void Currency::AddAmount(float add) {*amount += add;}
void Currency::SetAmount(float a) {*amount = a;}