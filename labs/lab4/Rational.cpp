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

	simplify();
}

bool Rational::operator==(const Rational& rhs)
{
	return (m_num * rhs.m_dem) == (m_dem * rhs.m_num);
}

bool Rational::operator<(const Rational& rhs)
{
	return (m_num * rhs.m_dem) < (m_dem * rhs.m_num);
}

bool Rational::operator<=(const Rational& rhs)
{
	return (m_num * rhs.m_dem) <= (m_dem * rhs.m_num);
}

bool Rational::operator>(const Rational& rhs)
{
	return (m_num * rhs.m_dem) > (m_dem * rhs.m_num);
}

bool Rational::operator>=(const Rational& rhs)
{
	return (m_num * rhs.m_dem) >= (m_dem * rhs.m_num);
}

Rational Rational::operator+(const Rational& rhs)
{
	int num = (m_num * rhs.m_dem) + (rhs.m_num * m_dem);
	int dem = m_dem * rhs.m_dem;

	return Rational(num, dem);
}

Rational Rational::operator-(const Rational& rhs)
{
	int num = (m_num * rhs.m_dem) - (rhs.m_num * m_dem);
	int dem = m_dem * rhs.m_dem;

	return Rational(num, dem);
}

Rational Rational::operator*(const Rational& rhs)
{
	return Rational(m_num * rhs.m_num, m_dem * rhs.m_dem);
}

Rational Rational::operator/(const Rational& rhs)
{
	return Rational(m_num * rhs.m_dem, m_dem * rhs.m_num);
}

std::ostream& operator<<(std::ostream& out, const Rational& r)
{
    out << "Numerator: " << r.m_num << std::endl;
    out << "Denominator: " << r.m_dem << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, Rational& r)
{
	std::cout << "Num: ";
	in >> r.m_num;
	
	std::cout << "Dem: ";
	in >> r.m_dem;

	if (r.m_dem == 0)
		r.m_dem = 1;

	else
		r.simplify();

    return in;
}

void Rational::simplify()
{
	int min = abs(m_num) < abs(m_dem) ? abs(m_num) : abs(m_dem);

	for (int i = min; i > 1; i--)
	{
		if (m_num % i == 0 && m_dem % i == 0)
		{
			m_num /= i;
			m_dem /= i;
			return;
		}
	}
}