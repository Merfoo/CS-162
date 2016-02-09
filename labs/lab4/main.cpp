#include <iostream>
#include <string>
#include "Rational.h"

using namespace std;

int main()
{
	Rational l;
	Rational r;

	while (true)
	{
		
		cin >> l >> r;
		cout << endl;

		cout << "1 Simplified:\n" << l << endl;
		cout << "2 Simplified:\n" << r << endl;

		//  ==, <, <=, >, >=, +, -, *, and /
		cout << "l == r\n\t" << (l == r) << endl;
		cout << "l < r\n\t" << (l < r) << endl;
		cout << "l <= r\n\t" << (l <= r) << endl;
		cout << "l > r\n\t" << (l > r) << endl;
		cout << "l >= r\n\t" << (l >= r) << endl;
		cout << endl;

		cout << "Again? [y]es [n]o" << endl;
		string in;
		cin >> in;

		if (in != "y")
			break;
	}

    return 0;
}

