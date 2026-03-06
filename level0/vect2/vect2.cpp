#include "vect2.hpp"

vect2::vect2(): _x(0), _y(0)
{

}

vect2::vect2(int x, int y): _x(x), _y(y)
{

}

vect2::vect2(const vect2& other): _x(other._x), _y(other._y)
{
    
}

vect2& vect2::operator=(const vect2& other)
{
    if (this == &other)
        return *this;
    _x = other._x;
    _y = other._y;
    return *this;
}

vect2::~vect2()
{

}

// Operators
vect2 vect2::operator+(int nb) const
{
    vect2 a(*this);

    a._x += nb;
    a._y += nb;
    return a;
}

vect2 vect2::operator+(const vect2& other) const
{
    vect2 a(*this);

    a._x += other._x;
    a._y += other._y;
    return a;
}

vect2& vect2::operator+=(const vect2& other)
{
    _x += other._x;
    _y += other._y;
    return *this;
}

vect2 vect2::operator-(int nb) const
{
    vect2 a(*this);

    a._x -= nb;
    a._y -= nb;
    return a;
}

vect2 vect2::operator-(const vect2& other) const
{
    vect2 a(*this);

    a._x -= other._x;
    a._y -= other._y;
    return a;
}

vect2& vect2::operator-=(const vect2& other)
{
    _x -= other._x;
    _y -= other._y;
    return *this;
}

vect2 vect2::operator*(int nb) const
{
    vect2 a(*this);
    a._x *= nb;
    a._y *= nb;
    return a;
}

vect2& vect2::operator*=(int nb)
{
    _x *= nb;
    _y *= nb;
    return *this;
}

int vect2::operator[](const int i) const
{
    if (i == 0)
        return _x;
    return (_y);
}

int& vect2::operator[](const int i)
{
    if (i == 0)
        return _x;
    return (_y);
}

// Pre---post
vect2& vect2::operator++()
{
    _x += 1;
    _y += 1;
    return *this;
}

vect2 vect2::operator++(int)
{
    vect2 a(*this);
    ++(*this);
    return (a);
}

vect2& vect2::operator--()
{
    _x -= 1;
    _y -= 1;
    return *this;
}

vect2 vect2::operator--(int)
{
    vect2 a(*this);
    --(*this);
    return (a);
}

vect2& vect2::operator-()
{
    _x *= (-1);
    _y *= (-1);
    return *this;
}

// arithmetic operators
bool vect2::operator==(const vect2& other) const
{
    if ((_x == other._x) && (_y == other._y))
        return true;
    return false;
}

bool vect2::operator!=(const vect2& other) const
{
    if ((_x != other._x) && (_y != other._y))
        return true;
    return false;
}

// operator multiply
vect2 operator*(const int nb, vect2 v)
{
    v *= nb;
    return v;
}

// print object <<
std::ostream& operator<<(std::ostream& out, const vect2& v)
{
    out << "{" << v[0] << ", " << v[1] << "}" << std::endl;
    return out;
}