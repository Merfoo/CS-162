#include <iostream>
#include <string>
#include <math.h>
#include <stdexcept>

using namespace std;

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

int getInt()
{
    string input;
    
    cout << "Enter Single Digit Number: ";
    getline(cin, input);

    if(isDigit(input[0]))
        return (int)input[0] - 48;

    else
        throw runtime_error("Thats not a number!");
}

int raiseTo(int base, int exponent)
{
    return pow(base, exponent);   
}

bool isLetter(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

string getString()
{
    string input;

    cout << "Enter string with only letters: ";
    getline(cin, input);

    for(int i = 0; i < input.length(); i++)
        if(!isLetter(input[i]))
            throw runtime_error("String contains a non-letter!");

    return input;
}

string concatenate(string left, string right)
{
    return left + right;
}

int main()
{
    cout << "Beginning..." << endl;
    
    try
    {
        int a = getInt();
        int b = getInt();
        cout << "Raising " << a << " to " << b << endl;
        cout << "Value: " << raiseTo(a, b) << endl;
    }

    catch(runtime_error e)
    {
        cout << "Caught an exception: " << e.what() << endl;
    }
   
    try
    {
        string a = getString();
        string b = getString();
        cout << "Adding '" << a << "' to '" << b << "'" << endl;
        cout << "Value: " << concatenate(a, b) << endl;
    }

    catch(runtime_error e)
    {
        cout << "Caught an exception: " << e.what() << endl;
    }
    
    return 0;
}
