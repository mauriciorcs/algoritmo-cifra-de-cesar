#include <iostream>
#include <string>

std::string alf = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?!@# ";

std::string encryption(const std::string& msg, int key) {
    std::string encoded = "";
    
    for (char i : msg) {
        size_t pos = alf.find(i);
        if (pos != std::string::npos) {
            size_t numeroEncode = (pos + key) % alf.length();
            encoded += alf[numeroEncode];
        } else {
            encoded += i;
        }
    }
    
    return encoded;
}

std::string decryption(const std::string& crypto, int key) {
    std::string decoded = "";
    
    for (char i : crypto) {
        size_t pos = alf.find(i);
        if (pos != std::string::npos) {
            size_t numeroDecode = (pos + alf.length() - key) % alf.length();
            decoded += alf[numeroDecode];
        } else {
            decoded += i;
        }
    }
    
    return decoded;
}

int main() {
    std::string msg;
    int key;
    
    std::cout << "Digite a mensagem que deseja encriptar: ";
    std::getline(std::cin, msg);
    std::cout << "Digite a chave de criptografia (um numero inteiro): ";
    std::cin >> key;

    std::string encriptacao = encryption(msg, key);
    std::cout << "Texto encriptado: " << encriptacao << std::endl;

    char opcao;
    std::cout << "Deseja descriptografar a mensagem? (s/n): ";
    std::cin >> opcao;
    if (opcao == 's' || opcao == 'S') {
        std::string decriptacao = decryption(encriptacao, key);
        std::cout << "Texto decriptado: " << decriptacao << std::endl;
    } else {
        std::cout << "A mensagem nao foi descriptografada." << std::endl;
    }

    return 0;
}
