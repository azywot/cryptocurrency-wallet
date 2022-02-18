#include "cryptocurrency.h"
using namespace std;

CryptoCurrency::CryptoCurrency(string cID, string cname, float am, float ex_rate, float ex_fee):  Currency(cID, cname, am, ex_rate, ex_fee) {}
void CryptoCurrency::someVoid() {}