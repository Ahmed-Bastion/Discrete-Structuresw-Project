#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

bool primecheck(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int modfxn(int a, int b) {
    while (a >= b) a = a - b;
    return a;
}

int modPow(int base, int exp, int mod) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result = result * base;
        result = modfxn(result, mod);
    }
    return result;
}

int findGenerator(int p) {
    for (int g = 2; g < p; g++) {
        bool seen[256] = {false};
        bool valid = true;
        for (int i = 1; i < p; i++) {
            int val = modPow(g, i, p);
            if (val <= 0 || val >= p || seen[val]) {
                valid = false;
                break;
            }
            seen[val] = true;
        }
        if (valid) return g;
    }
    return -1;
}

void xorEncryptDecrypt(char* message, int length, int key) {
    for (int i = 0; i < length; i++) {
        message[i] = message[i] ^ key;
    }
}

int main() {
    srand(time(0));
    ofstream outfile("xor.txt");
    if (!outfile) {
        cerr << "Failed to open file!" << endl;
        return 1;
    }

    int prime = 0;
    while (true) {
        int n = 1 + modfxn(rand(), 49);
        if (primecheck(n)) {
            prime = n;
            break;
        }
    }

    int g = findGenerator(prime);
    int alicePrivate = 1 + modfxn(rand(), prime - 2);
    int bobPrivate = 1 + modfxn(rand(), prime - 2);

    int alicePublic = modPow(g, alicePrivate, prime);
    int bobPublic = modPow(g, bobPrivate, prime);

    int sharedSecretAlice = modPow(bobPublic, alicePrivate, prime);
    int sharedSecretBob = modPow(alicePublic, bobPrivate, prime);
    int key = modfxn(sharedSecretAlice, 256);

    cout << "Prime number (p): " << prime << endl;
    cout << "Generator (g): " << g << endl;
    cout << "Alice's Private Key: " << alicePrivate << endl;
    cout << "Bob's Private Key: " << bobPrivate << endl;
    cout << "Alice's Public Key: " << alicePublic << endl;
    cout << "Bob's Public Key: " << bobPublic << endl;
    cout << "Shared Secret computed by Alice: " << sharedSecretAlice << endl;
    cout << "Shared Secret computed by Bob: " << sharedSecretBob << endl;
    

    cout << "Enter the message to encrypt: ";
    char message[500];
    cin.getline(message, 500);

    int length = 0;
    while (message[length] != '\0') length++;

    char originalMessage[500];
    for (int i = 0; i <= length; i++) originalMessage[i] = message[i];

    xorEncryptDecrypt(message, length, key);
    char encryptedMessage[500];
    for (int i = 0; i <= length; i++) encryptedMessage[i] = message[i];

    xorEncryptDecrypt(message, length, key);
    char decryptedMessage[500];
    for (int i = 0; i <= length; i++) decryptedMessage[i] = message[i];

    outfile << "Original message: " << originalMessage << endl;
    outfile << "Encrypted message: " << encryptedMessage << endl;
    outfile << "Decrypted message: " << decryptedMessage << endl;
    outfile.close();

    cout << "\nOriginal Message: " << originalMessage << endl;
    cout << "Encrypted Message: " << encryptedMessage << endl;
    cout << "Decrypted Message: " << decryptedMessage << endl;
  

    return 0;
}
