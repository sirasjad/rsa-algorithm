#include <iostream>
#include <cmath>
#include <string>

static const char Alphabet[26] = {
    'A', 'B', 'C', 'D', 'E', 'F', 
    'G', 'H', 'I', 'J', 'K', 'L', 
    'M', 'N', 'O', 'P', 'Q', 'R', 
    'S', 'T', 'U', 'V', 'W', 'X', 
    'Y', 'Z'
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
    RSA(int, int);
    double gcd(double, double);
    void exponent();
    void privateKey();
    void convertToNumbers(char*);
    void encrypt();
    void decrypt();

private:
    Primes primes;
    Keys::publicKey pubKey;
    Keys::privateKey privKey;

    int* buffer = new int[512];
    int size = 0;
    double phi;
};
