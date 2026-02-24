/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:48:31 by danielafons       #+#    #+#             */
/*   Updated: 2026/02/24 21:44:17 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

// Default constructor
Bigint::Bigint(): digits(1, 0)
{

}

// Constructor
Bigint::Bigint(int nb): digits(1, 0)
{
    int mod;
    std::vector<int> v1;

    if (nb == 0)
        v1.push_back(0);
    else
    {
        while (nb > 0)
        {
            mod = nb % 10;
            nb /= 10;
            v1.push_back(mod);
        }
    }
    normalize((*this), v1);
    //debug
    //std::cout << "Object 1: ";
    //print_bigint(this->digits);
}

// Copy constructor
Bigint::Bigint(const Bigint& other): digits(other.digits)
{

}

// Assignement operator
Bigint& Bigint::operator=(const Bigint& other)
{
    if (this == &other)
        return (*this);
    this->digits = other.digits; //copy allowed
    return (*this);
}

// Addition operator
Bigint Bigint::operator+(const Bigint& other) const
{
    Bigint bigint;
    std::vector<int> v1;

    int i = static_cast<int>(this->digits.size() - 1);
    int j = static_cast<int>(other.digits.size() - 1);
    int sum, result, carry = 0;
    while (i >= 0 || j >= 0)
    {
        int a = (i >= 0) ? this->digits[i] : 0;
        int b = (j >= 0) ? other.digits[j] : 0;

        sum = a + b + carry;
        result = sum % 10;
        carry = sum / 10;

        v1.push_back(result);
        i--;
        j--;
    }
    if (carry)
        v1.push_back(carry);
    normalize(bigint, v1);
    return (bigint);
}

Bigint& Bigint::operator+=(const Bigint& other)
{
    std::vector<int> v1;

    int i = static_cast<int>(this->digits.size() - 1);
    int j = static_cast<int>(other.digits.size() - 1);
    int sum, result, carry = 0;
    while (i >= 0 || j >= 0)
    {
        int a = (i >= 0) ? this->digits[i] : 0;
        int b = (j >= 0) ? other.digits[j] : 0;

        sum = a + b + carry;
        result = sum % 10;
        carry = sum / 10;

        v1.push_back(result);
        i--;
        j--;
    }
    if (carry)
        v1.push_back(carry);
    normalize(*this, v1);
    return (*this);
}

bool Bigint::operator==(const Bigint& other) const
{
    if (this->digits.size() != other.digits.size())
        return(false);
    for (size_t i = 0; i < this->digits.size(); i++)
    {
        if (this->digits[i] != other.digits[i])
            return (false);
    }
    return (true);
}

bool Bigint::operator!=(const Bigint& other) const
{
    if (this->digits.size() != other.digits.size())
        return(true);
    for (size_t i = 0; i < this->digits.size(); i++)
    {
        if (this->digits[i] != other.digits[i])
            return (true);
    }
    return (false);
}

bool Bigint::operator>(const Bigint& other) const
{
    if (this->digits.size() > other.digits.size())
        return(true);
    else if (this->digits.size() < other.digits.size())
        return (false);
    else
    {
        for (size_t i = 0; i < this->digits.size(); i++)
        {
            if (this->digits[i] > other.digits[i])
                return (true);
            else if (this->digits[i] < other.digits[i])
                return (false);
        }
    }
    return (false);
}

bool Bigint::operator>=(const Bigint& other) const
{
    if (digits.size() != other.digits.size())
        return digits.size() > other.digits.size();
    for (size_t i = 0; i < this->digits.size(); i++)
    {
        if (this->digits[i] > other.digits[i])
            return (true);
        else if (this->digits[i] < other.digits[i])
            return (false);
    }
    return (true);
}

bool Bigint::operator<(const Bigint& other) const
{
    if (this->digits.size() > other.digits.size())
        return(false);
    else if (this->digits.size() < other.digits.size())
        return (true);
    else
    {
        for (size_t i = 0; i < this->digits.size(); i++)
        {
            if (this->digits[i] > other.digits[i])
                return (false);
            else if (this->digits[i] < other.digits[i])
                return (true);
        }
    }
    return (false);
}

bool Bigint::operator<=(const Bigint& other) const
{
    if (digits.size() != other.digits.size())
        return digits.size() < other.digits.size();
    for (size_t i = 0; i < this->digits.size(); i++)
    {
        if (this->digits[i] < other.digits[i])
            return (true);
        else if (this->digits[i] > other.digits[i])
            return (false);
    }
    return (true);
}

// Digit shiffting
Bigint Bigint::operator<<(int nb) const
{
    if (nb <= 0)
        return *this;
    Bigint bigint(*this);
    for (int i = 0; i < nb; i++)
        bigint.digits.push_back(0);
    return (bigint);
}

Bigint& Bigint::operator<<=(int nb)
{
    if (nb <= 0)
        return *this;
    for (int i = 0; i < nb; i++)
        digits.push_back(0);
    return (*this);
}

Bigint Bigint::operator>>(int nb) const
{
   if (nb <= 0)
        return *this;
    Bigint bigint(*this);
    for (int i = 0; i < nb && !bigint.digits.empty(); i++)
        bigint.digits.pop_back();
    if (bigint.digits.empty())
        bigint.digits.push_back(0);
    return (bigint);
}

Bigint& Bigint::operator>>=(int nb)
{
   if (nb <= 0)
        return *this;
    for (int i = 0; i < nb && !digits.empty(); i++)
        digits.pop_back();
    if (digits.empty())
        digits.push_back(0);
    return (*this);
}

Bigint& Bigint::operator>>=(const Bigint& nb)
{
    // Cas nb = 0
    if (nb.digits.size() == 1 && nb.digits[0] == 0)
        return *this;

    // Convertir nb (Bigint) -> int n (très simple)
    int n = 0;
    for (size_t i = 0; i < nb.digits.size(); ++i)
        n = n * 10 + nb.digits[i];  // nb.digits contient les chiffres en MSB-first

    // Réutiliser ton opérateur existant
    return (*this >>= n);
}

Bigint& Bigint::operator++()
{
    (*this) += Bigint(1);
    return (*this);
}

Bigint Bigint::operator++(int)
{
    Bigint bigint(*this);
    ++(*this);
    return (bigint);
}
    
//out reference to std::cout
std::ostream& operator<<(std::ostream &out, const Bigint& n)
{
    n.print_digits(out);
    return (out);
}

void Bigint::print_digits(std::ostream &out) const
{
    for (int i = 0; i < static_cast<int>(digits.size()); i++)
        out << digits[i];
}

void Bigint::normalize(Bigint& bigint, const std::vector<int>& v1) const
{
    int i = static_cast<int>(v1.size() - 1);

    bigint.digits.clear();
    while (i >= 0)
    {
        bigint.digits.push_back(v1[i]);
        i--;
    }
}
