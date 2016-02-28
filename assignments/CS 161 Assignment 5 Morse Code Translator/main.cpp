#include <iostream>>

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

	return length + 1;
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
		if (compare(data, length, morseCode[i], getLength(morseCode[i]) - 1))
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
			if (data[i + 6] == ' ')
				i += 7;

			else
				i += 2;

			lettersCount++;
		}
	}

	return lettersCount + 1;
}

char* convertMorseString(char* data, int length, char** morseCode, char* morseVal, int morseLength, int& resultLength)
{
	char* letters = new char[getNumberOfLettersFromMorseCode(data, length)];
	resultLength = 0;
	int begI = 0;

	for (int i = 0; i < length; i++)
	{
		if (data[i] == ' ' && data[i + 2] == ' ')
		{
			letters[resultLength++] = convertFromMorse(morseCode, morseVal, morseLength, getSubstring(data, begI, i), i - begI);
			i += 3;
			begI = i;
		}

		else if (data[i] == ' ' && data[i + 6] == ' ')
		{
			letters[resultLength++] = ' ';
			i += 7;
			begI = i;
		}
	}

	letters[resultLength++] = convertFromMorse(morseCode, morseVal, morseLength, getSubstring(data, begI, length), length - begI);

	return letters;
}

char* convertTextString(char* data, int length, char** morseCode, char* morseVal, int morseLength, int& resultLength)
{
	resultLength = 0;
	char* result = 0;

	for (int i = 0; i < length; i++)
	{
		char* converted = convertFromText(morseCode, morseVal, morseLength, data[i]);
		int convertedLength = getLength(converted) - 1;

		result = concat(result, resultLength, converted, convertedLength);
		resultLength += convertedLength;

		if (i < length - 1)
		{
			result = concat(result, resultLength, "   \0", 3);
			resultLength += 3;
		}
	}

	return result;
}
/*
	WARNING
	There are currently memory leaks every at the moment.
	I am too lazy to fix them right now
*/
int main()
{
	const int morseLength = 27;
	
	char* morseCode[morseLength] =
	{
		".-\0",		// A
		"-...\0",	// B
		"-.-.\0",	// C
		"-..\0",	// D
		".\0",		// E
		"..-.\0",	// F
		"--.\0",	// G
		"....\0",	// H
		"..\0",		// I
		".---\0",	// J
		"-.-\0",	// K
		".-..\0",	// L
		"--\0",		// M
		"-.\0",		// N
		"---\0",	// O
		".--.\0",	// P
		"--.-\0",	// Q
		".-.\0",	// R
		"...\0",	// S
		"-\0",		// T
		"..-\0",	// U
		"...-\0",	// V
		".--\0",	// W
		"-..-\0",	// X
		"-.--\0",	// Y
		"--..\0",	// Z
		"       \0"
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
			result = convertMorseString(input, length, morseCode, morseVal, morseLength, resultLength);

		for (int i = 0; i < resultLength; i++)
			cout << result[i];

		cout << endl;
		break;
	}

	cout << "Enter something to quit..." << endl;
	char x;
	cin >> x;

	return 0;
}