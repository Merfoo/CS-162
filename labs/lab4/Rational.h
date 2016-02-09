#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <stdlib.h>

class Rational
{
    public:
        Rational();
        Rational(int wholeNum);
        Rational(int num, int dem);        

		//  ==, <, <=, >, >=, +, -, *, and /
		bool operator==(const Rational& rhs);

		bool operator<(const Rational& rhs);
		bool operator<=(const Rational& rhs);
		bool operator>(const Rational& rhs);
		bool operator>=(const Rational& rhs);
		
		Rational operator+(const Rational& rhs);
		Rational operator-(const Rational& rhs);
		Rational operator*(const Rational& rhs);
		Rational operator/(const Rational& rhs);

        friend std::ostream& operator<<(std::ostream& out, const Rational& r);
        friend std::istream& operator>>(std::istream& in, Rational& r);

    private:
		void simplify();

        int m_num;
        int m_dem;
};

std::ostream& operator<<(std::ostream& out, const Rational& r);
std::istream& operator>>(std::istream& in, Rational& r);

#endif // RATIONAL_H