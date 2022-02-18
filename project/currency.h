#pragma once
using namespace std;

class Currency{
private: 
    char * curr_ID, * curr_name;
    float * amount, * exchange_rate, * exchange_fee;
public:
    Currency(string cID, string cname, float am, float ex_rate, float ex_fee);
    ~Currency();
    virtual void toString();
    virtual void someVoid()=0;
    char * GetName();
    char * GetID();
    float GetExchangeRate();
    float GetExchangeFee();
    float GetAmount();
    void AddAmount(float add);
    void SetAmount(float a);
};