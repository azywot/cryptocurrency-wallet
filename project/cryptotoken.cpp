#include "cryptotoken.h"
using namespace std;

CryptoToken::CryptoToken(string cID, string cname, float am, float ex_rate, float ex_fee):  CryptoCurrency(cID, cname, am, ex_rate, ex_fee) {}
void CryptoToken::Mine() {}