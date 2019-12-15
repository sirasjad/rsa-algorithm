#include "rsa.hpp"

int main(){
    std::cout << "Enter two prime numbers (separated with whitespace): ";
    int p, q; std::cin >> p >> q;
    
    RSA rsa(p, q);
    rsa.exponent();
    rsa.privateKey();

    std::cout << "Enter a text message: ";
    char* plaintext = new char[512];
    std::cin >> plaintext;
    rsa.convertToNumbers(plaintext);

    rsa.encrypt();
    rsa.decrypt();
    return 0;
}