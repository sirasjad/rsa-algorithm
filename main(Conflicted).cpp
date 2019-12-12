#include "rsa.hpp"

int main(){
    RSA rsa;
    rsa.getPrimes(); // 7, 97
    rsa.setN(); // Formula: n = p*q
    rsa.calculatePhi();
    rsa.setE();
    rsa.generatePrivateKey();
    rsa.encrypt();
    //rsa.decrypt();
    
    return 0;
}