#include <iostream>

using namespace std;

char* getInput(int& length)
{
	length = 0;
	char* data = 0;
	char c;

	while ((c = cin.get()) != 10)
	{
		char* tmp = new char[++length];

		for (int i = 0; i < length - 1; i++)
			tmp[i] = data[i];

		tmp[length - 1] = c;
		delete data;
		data = tmp;
	}

	return data;
}

char* concat(char* beg, int begLength, char* end, int endLength)
{
	char* str = new char[begLength + endLength];

	for (int i = 0; i < begLength; i++)
		str[i] = beg[i];

	for (int i = 0; i < endLength; i++)
		str[i + begLength] = end[i];

	return str;
}

int getLength(char* data)
{
	int length = 0;

	while (data[length] != '\0')
		length++;

	return length;
}

char* getSubstring(char* data, int beg, int end)
{
	char* str = new char[end - beg];

	for (int i = beg; i < end; i++)
		str[i - beg] = data[i];

	return str;
}

bool compare(char* a, int aLen, char* b, int bLen)
{
	if (aLen != bLen)
		return false;

	for (int i = 0; i < aLen; i++)
		if (a[i] != b[i])
			return false;

	return true;
}

char convertFromMorse(char** morseCode, char* morseVal, int morseLength, char* data, int length)
{
	for (int i = 0; i < morseLength; i++)
		if (compare(data, length, morseCode[i], getLength(morseCode[i])))
			return morseVal[i];

	return -1;
}

char* convertFromText(char** morseCode, char* morseVal, int morseLength, char data)
{
	for (int i = 0; i < morseLength; i++)
		if (morseVal[i] == data)
			return morseCode[i];

	return 0;
}

// ....   .   .-..   .-..   ---   .--   ---   .-.   .-..   -..
bool isValidMorseCode(char* morseCode, int length)
{
	if (morseCode[0] == ' ' || morseCode[length - 1] == ' ')
		return false;

	int spaceCount = 0;

	for (int i = 0; i < length; i++)
	{
		if (morseCode[i] != '-' && morseCode[i] != '.' && morseCode[i] != ' ')
			return false;

		if (morseCode[i] == ' ')
			spaceCount++;

		else if (spaceCount == 0 || spaceCount == 3 || spaceCount == 7)
			spaceCount = 0;

		else
			return false;
	}

	return true;
}

bool isValidMorseTranslation(char* data, int length)
{
    for(int i = 0; i < length; i++)
        if(data[i] == (char)-1)
            return false;

    return true;
}

bool isValidMessage(char* msg, int length)
{
	for (int i = 0; i < length; i++)
		if (msg[i] != ' ' && (msg[i] < 'A' || msg[i] > 'Z'))
			return false;

	return true;
}

int getNumberOfLettersFromMorseCode(char* data, int length)
{
	int lettersCount = 0;

	for (int i = 0; i < length; i++)
	{
		if (data[i] == ' ')
		{
			char* substring = getSubstring(data, i, i + 7);

			if(compare("       ", 7, substring, 7))
				i += 7;

			else
				i += 2;

			lettersCount++;
			delete[] substring;
		}
	}

	return lettersCount + 1;
}

char* convertMorseString(char* data, int length, char** morseCode, char* morseVal, int morseLength, int& resultLength)
{
	char* letters = new char[getNumberOfLettersFromMorseCode(data, length)];
	char* substring;
	resultLength = 0;
	int begI = 0;

	for (int i = 0; i < length; i++)
	{
		if (data[i] == ' ')
		{
			substring = getSubstring(data, begI, i);
			letters[resultLength++] = convertFromMorse(morseCode, morseVal, morseLength, substring, i - begI);
			delete[] substring;

			substring = getSubstring(data, i, i + 7);

			if (compare("       ", 7, substring, 7))
			{
				letters[resultLength++] = ' ';
				i += 7;
			}

			else
				i += 3;

			begI = i;
			delete[] substring;
		}
	}

	substring = getSubstring(data, begI, length);
	letters[resultLength++] = convertFromMorse(morseCode, morseVal, morseLength, substring, length - begI);
	delete[] substring;

	return letters;
}

char* convertTextString(char* data, int length, char** morseCode, char* morseVal, int morseLength, int& resultLength)
{
	resultLength = 0;
	char* result = 0;

	for (int i = 0; i < length; i++)
	{
		char* converted = convertFromText(morseCode, morseVal, morseLength, data[i]);
		int convertedLength = getLength(converted);
		char* tmp = result;

		result = concat(tmp, resultLength, converted, convertedLength);
		resultLength += convertedLength;
		delete[] tmp;

		if (i < length - 1)
		{
			tmp = result;
			result = concat(tmp, resultLength, "   ", 3);
			resultLength += 3;
			delete[] tmp;
		}
	}

	return result;
}

int main()
{
	const int morseLength = 27;
	
	char* morseCode[morseLength] =
	{
		".-",		// A
		"-...",		// B
		"-.-.",		// C
		"-..",		// D
		".",		// E
		"..-.",		// F
		"--.",		// G
		"....",		// H
		"..",		// I
		".---",		// J
		"-.-",		// K
		".-..",		// L
		"--",		// M
		"-.",		// N
		"---",		// O
		".--.",		// P
		"--.-",		// Q
		".-.",		// R
		"...",		// S
		"-",		// T
		"..-",		// U
		"...-",		// V
		".--",		// W
		"-..-",		// X
		"-.--",		// Y
		"--..",		// Z
		"       "
	};

	char morseVal[morseLength] =
	{
		'A',
		'B',
		'C',
		'D',
		'E',
		'F',
		'G',
		'H',
		'I',
		'J',
		'K',
		'L',
		'M',
		'N',
		'O',
		'P',
		'Q',
		'R',
		'S',
		'T',
		'U',
		'V',
		'W',
		'X',
		'Y',
		'Z',
		' '
	};

	bool translateToMorse = false;

	while (true)
	{
		cout << "Do you want to translate text to Morse code (1) or translate Morse code to text (2)?";

		char input = cin.get();
		cin.ignore();

		if (input == '1')
		{
			translateToMorse = true;
			break;
		}

		else if (input == '2')
		{
			translateToMorse = false;
			break;
		}

		else
			cout << "Invalid input!" << endl;
	}

	while (true)
	{
		if (translateToMorse)
			cout << "Enter Text Message: ";

		else
			cout << "Enter Morse Code: ";

		int length = 0;
		char* input = getInput(length);

		for (int i = 0; i < length; i++)
		{
			cout << (i + 1) << ": " << input[i] << endl;
		}

		if (translateToMorse && !isValidMessage(input, length))
		{
			cout << "Invalid Text Message!" << endl;
			continue;
		}

		else if (!translateToMorse && !isValidMorseCode(input, length))
		{
			cout << "Invalid Morse Code!" << endl;
			continue;
		}

		int resultLength = 0;
		char* result;

		if (translateToMorse)
	        result = convertTextString(input, length, morseCode, morseVal, morseLength, resultLength);

		else
		{
			result = convertMorseString(input, length, morseCode, morseVal, morseLength, resultLength);

			if (!isValidMorseTranslation(result, resultLength))
			{
				cout << "Invalid Morse Code!" << endl;
				continue;
			}
		}

		for (int i = 0; i < resultLength; i++)
			cout << result[i];

		cout << endl;
		delete[] input;
		delete[] result;

		break;
	}

	cout << "Enter something to quit..." << endl;
	char x;
	cin >> x;

	return 0;
}
