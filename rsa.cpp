#include "rsa.hpp"

RSA::RSA(){
    //
}

double RSA::gcd(double a, double b) {
   double temp;
    while(true){
        temp = (int)a % (int)b;
        if(temp == 0) return b;
        a = b;
        b = temp;
    }
}

void RSA::setPrimes(){
    std::cout << "Enter two prime numbers (separated with whitespace): ";
    std::cin >> primes.p >> primes.q;
}

void RSA::setN(){
    pubKey.n = primes.p * primes.q; 
}

void RSA::setE(){
    // Formula: 1 < e < Φ(n)
    std::cout << "Enter a value for e: ";
    double _e; std::cin >> _e;
    if(_e < 1) std::cout << "Exponent must be greater than 1.\n";
    else if(_e > phi) std::cout << "Exponent must be smaller than phi.\n";

    while(_e < phi){ 
        if(gcd(_e, phi) == 1) break; 
        else _e++;
    }
    pubKey.e = _e;
}

void RSA::calculatePhi(){
    // Formula: phi = (p-1) * (q-1)
    phi = (primes.p - 1) * (primes.q - 1);
}

void RSA::generatePrivateKey(){
    double d1 = 1/pubKey.e;
    double d = fmod(d1, phi);
    
    //double d, k = 2;
    //d = ((k * phi) + 1)/pubKey.e;
    privKey.d = d;
}

unsigned long long int RSA::encrypt(){
    std::cout << "Enter a message: ";
    double msg; std::cin >> msg;

    unsigned long long int ctext = pow(msg, pubKey.e);
    ctext = fmod(ctext, pubKey.n);
    return ctext;
}

unsigned long long int RSA::decrypt(unsigned long long int ctext){
    unsigned long long int ptext = pow(ctext, privKey.d);
    ptext = fmod(ptext, pubKey.n);
    return ptext;
}

void RSA::convertToNumbers(char* plaintext){
    for(int i = 0; i < strlen(plaintext); i++){
        std::cout << plaintext[i];
    }
    std::cout << std::endl;
}