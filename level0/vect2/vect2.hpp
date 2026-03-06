#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2{
    private:
        int _x;
        int _y;
    public:
        vect2();
        vect2(int x, int y);
        vect2(const vect2& other);
        vect2& operator=(const vect2& other);
        ~vect2();

        // Operators
        vect2 operator+(const int nb) const;
        vect2 operator+(const vect2& other) const;
        vect2& operator+=(const vect2& other);
        vect2 operator-(const int nb) const;
        vect2 operator-(const vect2& other) const;
        vect2& operator-=(const vect2& other);
        vect2 operator*(const int nb) const;
        vect2& operator*=(int nb);

        int operator[](const int i) const;
        int& operator[](const int i);

        //Pre ---post
        vect2& operator++();
        vect2 operator++(int);
        vect2& operator--();
        vect2 operator--(int);
        vect2& operator-();

        // Arithmetic operators
        bool operator==(const vect2& other) const;
        bool operator!=(const vect2& other) const;
};

vect2 operator*(const int nb, vect2 v);
std::ostream& operator<<(std::ostream& out, const vect2& v);
#endif