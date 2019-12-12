#include <iostream>
#include <cmath>

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
    void getPrimes();
    void setN();
    void setE();
    void calculatePhi();
    void generatePrivateKey();
    void encrypt();
    void decrypt(double);

private:
    Primes primes;
    Keys::publicKey pubKey;
    Keys::privateKey privKey;

    int buffer = new int[4096];

    double phi;
};