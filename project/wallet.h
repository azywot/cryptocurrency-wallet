#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class T>
class Wallet{
private:
    char * user_ID, * username;
    vector<T> contents;
public:
    Wallet(string ID, string user){
        user_ID = new char[ID.length()+1];
        strcpy(user_ID, ID.c_str());

        username = new char[user.length()+1];
        strcpy(username, user.c_str());
    }
    ~Wallet(){
        delete user_ID;
        delete username;
        for(auto c: contents){
            delete c;
        }
        contents.clear();
    }
    Wallet& operator+=(T newCoin){
        for(int i=0; i<contents.size(); i++){
            if (!strcmp(contents[i]->GetName(), newCoin->GetName())){
                contents[i]->AddAmount(newCoin->GetAmount());
                cout<<"Added "<<newCoin->GetAmount()<<newCoin->GetID()<<"! (current balance: "<<contents[i]->GetAmount()<<contents[i]->GetID()<<")\n";
                delete newCoin;
                return *this;
            }
        } 
        contents.push_back(newCoin);
        cout<<"Created "<<newCoin->GetName()<<"! (current balance: "<<newCoin->GetAmount()<<newCoin->GetID()<<")\n";
        return *this;
    }
    Wallet& operator-=(T oldCoin){ 
        for(int i=0; i<contents.size(); i++){
            if (contents[i] == oldCoin){
                contents.erase(contents.begin()+i);
                return *this;
            }
        } 
        return *this;  
    }
    void printHello(){
        cout<<"Hello: "<<username<<"! (ID: "<<user_ID<<")\n";
    }
    void printContents(){
        if(contents.size()==0){cout<<"----EMPTY----\n"; return;}
        for (const auto& coin : contents)
            coin->toString();
    }

    int NoCoins(){ return contents.size(); }

    friend class Market;
};