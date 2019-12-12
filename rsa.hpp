#include <iostream>
#include <cmath>
#include <string>

char Alphabet[26] = {
    'A', 'B', 'C', 'D', 'E', 'F', 
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

struct Primes{
    double p, q;
};

namespace Keys{
    struct publicKey{
        double n, e;
    };

    struct privateKey{
        double d;
    };
    
};

class RSA{
public:
    RSA();
    double gcd(double, double);
    void setPrimes();
    void setN();
    void setE();
    void calculatePhi();
    void generatePrivateKey();
    void convertToNumbers(char*);
    unsigned long long int encrypt();
    unsigned long long int decrypt(unsigned long long int);

private:
    Primes primes;
    Keys::publicKey pubKey;
    Keys::privateKey privKey;

    char* buffer = new char[512];
    double phi;
};
