#include "rsa.hpp"

RSA::RSA(int _p, int _q){
    // Set the values for p and q
    primes.p = _p;
    primes.q = _q;

    // Set n = p * q
    pubKey.n = primes.p * primes.q;

    // Phi = (p-1) * (q-1)
    phi = (primes.p - 1) * (primes.q - 1);
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

void RSA::exponent(){
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

void RSA::privateKey(){
    double d1 = 1/pubKey.e;
    double d = fmod(d1, phi);
    privKey.d = d;
}

void RSA::encrypt(){
    unsigned long long int ctext;
    std::cout << "Encrypted ciphertext: ";
    for(int i = 0; i < size; i++){
        ctext = pow(buffer[i], pubKey.e);
        ctext = fmod(ctext, pubKey.n);
        buffer[i] = ctext;
        std::cout << ctext;
    }
    std::cout << std::endl;
}

void RSA::decrypt(){
    unsigned long long int ptext;
    std::cout << "Decrypted plaintext: ";
    for(int i = 0; i < size; i++){
        ptext = pow(buffer[i], privKey.d);
        ptext = fmod(ptext, pubKey.n);
        buffer[i] = ptext;
        std::cout << Alphabet[ptext];
    }
    std::cout << std::endl;
}

void RSA::convertToNumbers(char* plaintext){
    for(int i = 0; i < strlen(plaintext); i++){
        buffer[i] = plaintext[i]-65;
    }
    size = strlen(plaintext);
}