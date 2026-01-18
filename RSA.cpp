#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int MOD( int a, int b);
int GCD( int a, int b); // i have wrote this code in recursive form with the help of AI as we are not teached Recursion
bool isprime( int n);
int StringLength( string s);
int MODexp( int base, int exp , int mod);
void extendedGCD(int a, int b, int &gcd, int &x, int &y);
int Inverse ( int a, int m);
void RSAkey (int &e , int &d, int &n , int &p , int &q);
string Encryption ( string plain, int e , int n);
string DecryptwithCRT( string cipher , int d, int n, int p, int q);





int main()
{
	srand(time(0));
	
	int e,d,n,p,q;
	RSAkey (e , d, n, p, q); // calling the function to calculate the keys
	
	
	//reading data from the file
	string read ="";
	string readfile = "text.txt";
	
	ifstream infile( readfile);
	char ch; // basically we are reading data character by character and then storing in a string
	if (infile.is_open())
	{
		while (infile.get(ch)) 
		{
		    read += ch;
		}
        	infile.close();
	} 
	else 
	{
		cout << "Error: Cannot open the reading file\n" << endl;
	}
	
	// encrypting and writing the encrypted data into the file
	string encrypted = Encryption(read, e, n);
	
	ofstream outfile1("encrypted.txt");
	if (outfile1.is_open())
	{
		int len = StringLength(encrypted);
		for (int i = 0; i < len; i++)
		{
		    outfile1 << encrypted[i];
		}
		outfile1.close();
	}
	// now reading the encrypted data we store in the file
	string readData = "";
	ifstream infile2("encrypted.txt");
	if (infile2.is_open()) 
	{
		char ch2;
		while (infile2.get(ch2))
		{
		    readData += ch2;
		}
		infile2.close();
	}
	
	// finally decrypting the data and writing it back into the file using the append mode
	string decrypted = DecryptwithCRT(readData, d, n, p, q);
    
	ofstream outfile2("encrypted.txt", ios::app);
	if (outfile2.is_open())
	{
	outfile2 << "\nDECRYPTED: ";
	int len2 = StringLength(decrypted);
	for (int i = 0; i < len2; i++) 
	{
	    outfile2 << decrypted[i];
	}
	outfile2.close();
	}
    
	cout << "RSA completed successfully!" << endl;	

	return 0;
	
}



// -------------Function definitions----------------------
int MOD( int a, int b)
{
	if (b == 0)
	{
		return 0;
	}
	while (a >= b)
	{
		a = a-b;
	}
	while ( a < 0)
	{
		a = a+b;
	}
	return a;

}

int GCD( int a, int b) // recursive function
{
	if (b == 0) // terminating codition or where the reverse or un binding process began
	{
		return a;
	}
	
	return GCD(b ,MOD(a,b)); // base case: basically where the function calls itself
}

bool isprime( int n)
{
	if ( n < 2)
	{
		return false;
	}
	else if (n == 2)
	{
		return true;
	}
	
	if ( MOD(n,2) == 0)
	{
		return false;
	}
	for (int i=3 ; (i*i) <= n; i+=2)
	{
		if ( MOD(n,i) == 0)
		{
			return false;
		}
	}
	return true;
}

int StringLength( string s)
{
	int length = 0;
	
	while ( s[length] != '\0')
	{
		length++;
	}
	return length;
}

int MODexp( int base, int exp , int mod)
{
	int result =1;
	base = MOD( base , mod);
	
	while ( exp > 0)
	{
		if ( MOD( exp , 2) == 1) // checking wether exponent is odd
		{
			result = MOD (result*base , mod);
			
		}
		exp = exp/2;
		base = MOD( (base*base) , mod);
		
	}
	return result;
	}
	

void extendedGCD(int a, int b, int &gcd, int &x, int &y) 
{
    int x0 = 1, y0 = 0;  // For a
    int x1 = 0, y1 = 1;  // For b
    
    while (b != 0) {
        int q = a / b;
        
        // Update a and b
        int temp = b;
        b = MOD(a, b);
        a = temp;
        
        // Update coefficients
        int temp_x = x0;
        int temp_y = y0;
        
        x0 = x1;
        y0 = y1;
        
        x1 = temp_x - q * x1;
        y1 = temp_y - q * y1;
    }
    
    gcd = a;
    x = x0;
    y = y0;
}

int Inverse ( int a, int m)
{
	int gcd, x,y;
	
	extendedGCD (a ,m ,gcd ,x ,y);
	
	if ( gcd != 1)
		return -1;
		
	int result = MOD(x,m);
	
	if (result < 0)
	{
		result += m;
	}
	
	return result;
}

void RSAkey(int &e, int &d, int &n, int &p, int &q)
{
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    
    int primeCount = 15;
    
    int idx1 = rand() % primeCount;
    int idx2;
    do {
        idx2 = rand() % primeCount;
    } while (idx1 == idx2);
    
    p = primes[idx1];
    q = primes[idx2];
    
    n = p * q;
    int phi = (p - 1) * (q - 1);
    
    int e_candidates[] = {3, 5, 17, 19}; // these are the suitable e we can find which would coprime with our phi 
    e = -1; // giving an initial value suppose if we didn't find than it will return -1
    
    for (int i = 0; i < 4; i++) {
        if (GCD(e_candidates[i], phi) == 1)  // condition for checking the co-prime
        {
            e = e_candidates[i];
            break;
        }
    }
    
    d = Inverse (e , phi); // What number d makes (e × d) mod φ = 1 , basically finding the private key ,  This line finds the secret number d that "undoes" what e does in modular arithmetic
    
}
// PURPOSE: Encrypts plaintext using RSA
// MATH: For each character M: C = Mᵉ mod n
string Encryption ( string plain, int e , int n)
{
    string result = "";
    int len = StringLength(plain);
    
    for (int i = 0; i < len; i++) 
    {
        char c = plain[i];
        
        int M;
        
        if (c >= 'A' && c <= 'Z') {
            M = c - 'A';
        }
        else if (c >= 'a' && c <= 'z') {
            M = c - 'a';
        }
        else if( c == ' ')
        {
        	M = 26 ;// special case for space handling( since 26 is out of range as from A-z its 0-25 inclusive)
        }
        else {
            M = c;
        }
        
        int C = MODexp(M, e, n);  // C = Mᵉ mod n
        
        if (i > 0) result += " ";
        
        string numStr = "";
        if (C == 0)
         {
            numStr = "0";
         }
        else {
            int temp = C;
            while (temp > 0) {
                char digit = '0' + MOD(temp, 10);
                numStr = digit + numStr;
                temp = temp / 10;
            }
        }
        
        result += numStr;
    }
    
    return result;
}
// PURPOSE: Decrypts ciphertext using Chinese Remainder Theorem
// MATH: Instead of M = Cd mod n directly:
//       1. Compute Mp = Cdp mod p where dp = d mod (p-1)
//       2. Compute Ms = Cd(phi) mod q where ds = d mod (q-1)
//       3. Combine using CRT formula
string DecryptwithCRT( string cipher , int d, int n, int p, int q)
{
	string result = "";
	string num = "";
	int len = StringLength(cipher);

	for (int i = 0; i <= len; i++) 
	{
		if (i == len || cipher[i] == ' ') 
		{
		    if (StringLength(num) > 0) 
		    {
			int C = 0;
			int numLen = StringLength(num);
			for (int j = 0; j < numLen; j++) 
			{
			    C = C * 10 + (num[j] - '0');
			}	
			
			// CRT Calculations ( basically took help from Ai tool for CRT calculation as i myself was getting confused in this while calculating i tried multiple times but made an error so at the end i took help from AI
			int dP = MOD(d, p - 1);      
			int dQ = MOD(d, q - 1);      
			int qInv = Inverse(q, p);       
			
			int Mp = MODexp(C, dP, p);        
			int Mq = MODexp(C, dQ, q);         
			
			int h = MOD(qInv * (Mp - Mq), p);  
			if (h < 0)
			 	h += p;
			int M = Mq + h * q;                
			M = MOD(M, n);               

			char c;
			if (M == 26)
			{
				c = ' ';
			}
			else if (M >= 0 && M <= 25) 
			{
				c = 'A' + M;
			}
			else if (M >= 26 && M <= 51) 
			{
				c = 'a' + (M - 26);
			}
			else 
			{
				c = M;
			}

			result += c;
			num = "";
		  }
	      }
			else 
			{
				num += cipher[i];
			}
	}
			
    
    return result;
}

    
			
	 
































