#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int MOD(int num, int divisor);
int AlphaCheck(char num);
string EncryptString(string line);  // Returns encrypted string
string DecryptString(string line);  // Returns decrypted string
void WriteToFile(string text, ofstream &file_write);
const int shift = 4;

int main()
{
    string filename1 = "caeser.txt";
    string filename = "output.txt";
    
    // Store all original lines
    string originalLines[100];
    int lineCount = 0;
    
    // 1. Read original text from file
    ifstream infile(filename1);
    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            originalLines[lineCount] = line;
            lineCount++;
        }
        infile.close();
    }
    else
    {
        cout << "Error: Cannot open input file" << endl;
        return 1;
    }
    
    // 2. Open output file
    ofstream outfile(filename, ios::out);
    if (!outfile.is_open())
    {
        cout << "Error: Cannot open output file" << endl;
        return 1;
    }
    
    // 3. Write ENCRYPTED data (encrypt original)
    outfile << "Encrypted Data:\n";
    for (int i = 0; i < lineCount; i++)
    {
        string encrypted = EncryptString(originalLines[i]);
        outfile << encrypted << endl;
    }
    
    // 4. Write DECRYPTED data (decrypt the ENCRYPTED text)
    outfile << "\nDecrypted Data:\n";
    for (int i = 0; i < lineCount; i++)
    {
        // First encrypt it
        string encrypted = EncryptString(originalLines[i]);
        // Then decrypt the encrypted text to get original back
        string decrypted = DecryptString(encrypted);
        outfile << decrypted << endl;
    }
    
    outfile.close();
    cout << "Caesar Cipher completed successfully!" << endl;
    
    return 0;
}

int MOD(int num, int divisor) {
    if (divisor == 0) return 0;
    
    while (num >= divisor) {
        num = num - divisor;
    }
    
    while (num < 0) {
        num = num + divisor;
    }
    
    return num;
}

int AlphaCheck(char num)
{
    if (((num <= 'z') && (num >= 'a')) || ((num <= 'Z') && (num >= 'A')))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string EncryptString(string line)
{
    string result = "";
    int i = 0;
    
    while (line[i] != '\0')
    {
        if (AlphaCheck(line[i]) == 1)
        {
            if (line[i] <= 'z' && line[i] >= 'a')
            {
                int base = 97;
                int newpos = MOD((line[i] - base) + shift, 26);
                char dec_pos = base + newpos;
                result += dec_pos;
            }
            else if (line[i] <= 'Z' && line[i] >= 'A')
            {
                int base = 65;
                int newpos = MOD((line[i] - base) + shift, 26);
                char dec_pos = base + newpos;
                result += dec_pos;
            }
        }
        else
        {
            result += line[i];
        }
        i++;
    }
    
    return result;
}

string DecryptString(string line)
{
    string result = "";
    int i = 0;
    
    while (line[i] != '\0')
    {
        if (AlphaCheck(line[i]) == 1)
        {
            if (line[i] <= 'z' && line[i] >= 'a')
            {
                int base = 97;
                int newpos = MOD((line[i] - base) - shift, 26);
                char dec_pos = base + newpos;
                result += dec_pos;
            }
            else if (line[i] <= 'Z' && line[i] >= 'A')
            {
                int base = 65;
                int newpos = MOD((line[i] - base) - shift, 26);
                char dec_pos = base + newpos;
                result += dec_pos;
            }
        }
        else
        {
            result += line[i];
        }
        i++;
    }
    
    return result;
}
