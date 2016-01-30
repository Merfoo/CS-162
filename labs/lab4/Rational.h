#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational
{
    public:
        Rational();
        Rational(int wholeNum);
        Rational(int num, int dem);        

        friend std::ostream& operator<<(std::ostream& out, const Rational& r);
        friend std::istream& operator>>(std::istream& in, Rational& r);

    private:
        int m_num;
        int m_dem;
};

std::ostream& operator<<(std::ostream& out, const Rational& r);
std::istream& operator>>(std::istream& in, Rational& r);

#endif // RATIONAL_H
