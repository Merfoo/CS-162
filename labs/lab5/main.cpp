// This program demonstrates an application 
// of pure virtual functions.
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Encryption
{
 protected:
    char m_modifier;
   ifstream inFile;
   ofstream outFile;   
 public:
   Encryption(char *inFileName, char *outFileName);
   ~Encryption();
   // Pure virtual function
   virtual char transform(char ch) const = 0;
   virtual char untransform(char ch) const  = 0;
    // Do the actual work.
   void encrypt();
    void decrypt();
    void close();
};

//**************************************************
// Constructor opens the input and output file.    *
//**************************************************
Encryption::Encryption(char *inFileName, char *outFileName)
{
   inFile.open(inFileName);
   outFile.open(outFileName);
   if (!inFile) 
     {
       cout <<  "The file " << inFileName 
            << " cannot be opened.";
       exit(1);
     }
   if (!outFile)
    {
      cout << "The file " << outFileName
           << " cannot be opened.";
      exit(1);
    }
}

//**************************************************
//Destructor closes files.                         *
//**************************************************
Encryption::~Encryption()
{
   inFile.close();
   outFile.close(); 
}

void Encryption::close()
{
    inFile.close();
    outFile.close(); 
}

//*****************************************************
//Encrypt function uses the virtual transform         *
//member function to transform individual characters. *
//***************************************************** 
void Encryption::encrypt()
{
  char ch;
  char transCh;
  inFile.get(ch);
  while (!inFile.fail())
    {
      transCh = transform(ch);
      outFile.put(transCh);
      inFile.get(ch);
    }
    
    inFile.clear();
    inFile.seekg(0);
}

void Encryption::decrypt()
{
    char ch;
    char transCh;
    
    inFile.get(ch);

    while(!inFile.fail())
    {
        transCh = untransform(ch);
        outFile.put(transCh);
        inFile.get(ch);
    }

    inFile.clear();
    inFile.seekg(0);
}

// The subclass simply overides the virtual
// transformation function
class SimpleEncryption : public Encryption
{
public:
   char transform(char ch) const
   {
     return ch + m_modifier;
   }
    char untransform(char ch) const
    {
        return ch - m_modifier;
    }

   SimpleEncryption(char *inFileName, char *outFileName, char modifier)
   : Encryption(inFileName, outFileName)
   {
        m_modifier = modifier;
   }
};

class TransformEncryption : public Encryption
{
    public:
        void writeToFile()
        {
            string str = "";
            
            while(!inFile.fail())
            {
                char ch;
                inFile.get(ch);
                cout << "Char: " << ch << endl;
                str += ch;
            }

            for(int i = m_offset; i < str.length(); i++)
            {
                cout << "NewChar: " << str[i] << endl;
                outFile.put(str[i]);
            }

            for(int i = 0; i < m_offset; i++)
                outFile.put(str[i]);

            cout << str << endl;           
        }
    TransformEncryption(char* inFileName, char* outFileName, int offset)
    : Encryption(inFileName, outFileName)
    {
        m_offset = offset;
    }

    private:
        int m_offset;

        char transform(char ch) const { return 'a'; }
        char untransform(char ch) const { return 'a'; }
  
};

int main()
{
  char inFile[80], encFile[80], offFile[80], decFile[80], modifier;
  int offset = 4;
  cout << "Enter name of file to encrypt: ";
  cin >> inFile;
  cout << "Enter name of file to receive " 
       << "the encrypted text: ";
  cin >> encFile;

    cout << "Enter name of file to receive decrypt: ";
    cin >> decFile;
    cout << "Enter modifer character: ";
    cin >> modifier;

    cout << "Enter name of file to recieve offset file: ";
    cin >> offFile;

    SimpleEncryption obfuscate(inFile, encFile, modifier);
    obfuscate.encrypt();
    obfuscate.close();    

    TransformEncryption transform(inFile, offFile, offset);
    transform.writeToFile();
    transform.close();

    SimpleEncryption deobfuscate(encFile, decFile, modifier);
    deobfuscate.decrypt();
    deobfuscate.close();
  return 0;
}
