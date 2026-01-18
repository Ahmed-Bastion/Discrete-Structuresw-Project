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
- Muhammad Ahmed Waseem (25I-2037)
- Huzaifa Anwar (25I-2152)
```

---

## LinkedIn Post Guide

### Option 1: Technical Focus (Recommended)
```
🔐 Cryptography in Action: First Semester Project

Just completed my Discrete Structures project at FAST University Islamabad, implementing three fundamental cryptographic algorithms from scratch in C++:

✅ Caesar Cipher with custom modular arithmetic
✅ RSA Encryption with Chinese Remainder Theorem optimization
✅ XOR Cipher integrated with Diffie-Hellman key exchange

Key Technical Achievements:
- Implemented all mathematical operations without built-in modulo operators
- Applied CRT to reduce RSA decryption time by ~75%
- Built dynamic prime generation and Extended Euclidean Algorithm for key computation

This project deepened my understanding of:
→ Modular arithmetic and number theory
→ Asymmetric vs symmetric encryption
→ Algorithm optimization techniques
→ The mathematical foundations of cybersecurity

While these are educational implementations (not production-ready), they demonstrate the core principles that underpin modern cryptographic systems.

🔗 Full code and documentation on GitHub: [your-link]

#CyberSecurity #Cryptography #CPlusPlus #ComputerScience #Learning #FASTUniversity #InfoSec

---

Special thanks to Ms. Rabail Zahid for guidance and my project partner Huzaifa Anwar.
```

### Option 2: Career-Focused
```
📚 From Theory to Code: My Cryptography Journey

As a first-semester BS Cyber Security student at FAST University, I just completed a project that brought mathematical concepts to life through code.

The Challenge:
Implement Caesar Cipher, RSA, and XOR+Diffie-Hellman algorithms in C++ with strict constraints—no built-in modulo operators, custom mathematical functions, and optimization requirements.

What I Learned:
🔹 How theoretical math translates into practical security systems
🔹 The importance of algorithm optimization (achieved 75% faster RSA decryption)
🔹 Why understanding fundamentals matters in cybersecurity
🔹 How to document and present technical work professionally

The Result:
Three working implementations that encrypt and decrypt data, complete with comparative analysis and correctness proofs.

This is just the beginning of my cybersecurity journey. Excited to build on these foundations and contribute to making digital systems more secure.

📂 Project details: [GitHub link]

#CyberSecurityStudent #LearningJourney #Cryptography #TechEducation #FASTUniversity

What cryptographic concepts fascinate you the most? Drop your thoughts below! 👇
