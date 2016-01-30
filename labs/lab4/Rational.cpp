#include "Rational.h"

Rational::Rational()
{
    m_num = 0;
    m_dem = 1;
}

Rational::Rational(int wholeNum)
{
    m_num = wholeNum;
    m_dem = 1;
}

Rational::Rational(int num, int dem)
{
    m_num = num;
    m_dem = dem;
}

std::ostream& operator<<(std::ostream& out, const Rational& r)
{
    out << "Numerator: " << r.m_num << std::endl;
    out << "Denominator: " << r.m_dem << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, Rational& r)
{
    in >> r.m_num >> r.m_dem;

    return in;
}
