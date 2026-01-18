# Cryptographic Algorithms Implementation

**Course**: Discrete Structures (Fall 2025)  
**Institution**: FAST University Islamabad  
**Program**: BS Cyber Security - Semester 1

## 📋 Overview

Educational implementation of three fundamental cryptographic algorithms as part of a semester project:
- **Caesar Cipher** with customizable shift value
- **RSA Encryption** with Chinese Remainder Theorem optimization
- **XOR Cipher** with Diffie-Hellman key exchange

⚠️ **Note**: This is an academic project for learning purposes. These implementations are not suitable for production use due to simplified security parameters and known limitations.

## 🎯 Project Objectives

- Implement cryptographic algorithms from mathematical foundations
- Understand modular arithmetic and number theory concepts
- Practice file I/O operations and string manipulation in C++
- Apply optimization techniques (CRT for RSA decryption)

## 🔧 Implementation Details

### 1. Caesar Cipher
- **Shift Value**: 4 (configurable)
- **Features**: Preserves case sensitivity, handles non-alphabetic characters
- **Constraints**: Custom MOD function without built-in modulo operator

### 2. RSA with Chinese Remainder Theorem
- **Key Generation**: Dynamic prime selection (p, q < 50)
- **Public Exponent**: Selected from {3, 5, 17, 19}
- **Optimization**: CRT reduces decryption time by ~75%
- **Special Features**: Extended Euclidean Algorithm for modular inverse

### 3. XOR Cipher with Diffie-Hellman
- **Key Exchange**: Diffie-Hellman protocol for secure key generation
- **Encryption**: XOR operation with derived shared secret
- **Security**: New key generated each execution

## 📊 Comparative Analysis

| Algorithm | Time Complexity | Security Level | Use Case |
|-----------|----------------|----------------|----------|
| Caesar Cipher | O(n) | Very Low | Educational |
| RSA with CRT | O(log n) per char | High* | Asymmetric encryption |
| XOR + DH | O(n) | Moderate-High* | Symmetric encryption |

*In production implementations with appropriate key sizes

## 🚀 Usage

### Compilation
```bash
g++ caeserCipher_25I-2037_25I-2152_CY-A.cpp -o caesar
g++ RSA_25I-2037_25I-2152_CY-A.cpp -o rsa
g++ XOR_25I-2037_25I-2152_CY-A.cpp -o xor
```

### Execution
```bash
./caesar  # Reads from caeser.txt, outputs to output.txt
./rsa     # Reads from text.txt, outputs to encrypted.txt
./xor     # Interactive input, outputs to xor.txt
```

## ⚠️ Known Limitations

- **Small key space**: Primes limited to <50 for educational purposes
- **RSA bug**: Newline character handling issue in decryption
- **No error handling**: Limited input validation
- **Security**: Not cryptographically secure for real-world use

## 📚 Learning Outcomes

- Implemented custom modular arithmetic functions
- Understood the mathematical foundations of cryptography
- Applied loop invariants for correctness verification
- Gained experience with file handling and data persistence
- Learned optimization techniques (CRT for RSA)

## 🤝 Acknowledgments

- Instructor: Ms. Rabail Zahid
- AI assistance was used for understanding recursion in GCD and CRT calculations
- Group project completed with Huzaifa Anwar (25I-2152)

## 📝 Future Improvements

- [ ] Fix newline handling bug in RSA
- [ ] Implement larger prime generation (1024-bit+)
- [ ] Add comprehensive error handling
- [ ] Include unit tests for each algorithm
- [ ] Optimize modular exponentiation further
- [ ] Add encryption/decryption modes selection

## 📄 License

This project is for educational purposes only.

---

**Team Members**:
- Muhammad Ahmed Waseem 
- Huzaifa Anwar 
```

---

