#include "rsa.hpp"

int main(){
    RSA rsa;
    //rsa.setPrimes();
    //rsa.setN(); // Formula: n = p*q
    //rsa.calculatePhi();
    //rsa.setE();
    //rsa.generatePrivateKey();
    
    std::cout << "Enter a text message: ";
    char* plaintext = new char[512]; 
    std::cin >> plaintext;
    
    rsa.convertToNumbers(plaintext);

    //rsa.encrypt();
    //rsa.decrypt(); 

    return 0;
}