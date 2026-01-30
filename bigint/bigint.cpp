/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:48:31 by danielafons       #+#    #+#             */
/*   Updated: 2026/01/30 17:57:48 by danielafons      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bigint.hpp"

Bigint::Bigint(): digits(1, 0)
{

}

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
    remove_zeros(v1);
    normalize((*this), v1);
    //debug
    std::cout << "Object 1: ";
    print_bigint(this->digits);
}

Bigint::Bigint(const Bigint& other): digits(other.digits)
{

}

Bigint& Bigint::operator=(const Bigint& other)
{
    if (this == &other)
        return (*this);
    this->digits = other.digits; //copy allowed
    return (*this);
}

Bigint Bigint::operator+(const Bigint& other)
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

Bigint Bigint::operator+=(const Bigint& other)
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

bool Bigint::operator==(const Bigint& other)
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

bool Bigint::operator!=(const Bigint& other)
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

bool Bigint::operator>(const Bigint& other)
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

bool Bigint::operator>=(const Bigint& other)
{
    if (this->digits.size() > other.digits.size())
        return(true);
    else if (this->digits.size() < other.digits.size())
        return (false);
    else
    {
        for (size_t i = 0; i < this->digits.size(); i++)
        {
            if (this->digits[i] >= other.digits[i])
                return (true);
            else if (this->digits[i] < other.digits[i])
                return (false);
        }
    }
    return (false);
}

bool Bigint::operator<(const Bigint& other)
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

bool Bigint::operator<=(const Bigint& other)
{
    if (this->digits.size() > other.digits.size())
        return(false);
    else if (this->digits.size() <= other.digits.size())
        return (true);
    else
    {
        for (size_t i = 0; i < this->digits.size(); i++)
        {
            if (this->digits[i] > other.digits[i])
                return (false);
            else if (this->digits[i] <= other.digits[i])
                return (true);
        }
    }
    return (false);
}

Bigint Bigint::operator<<(int nb)
{
    Bigint bigint;

    for (size_t i = 0; i < this->digits.size(); i++)
    {
        if (i == 0)
            bigint.digits[0] = this->digits[i];
        else
            bigint.digits.push_back(this->digits[i]);
    }  
    print_bigint(bigint.digits);
    if (nb == 0)
        return (bigint);
    for (int i = 0; i < nb; i++)
        bigint.digits.push_back(0);
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

void Bigint::normalize(Bigint& bigint, const std::vector<int>& v1)
{
    int i = static_cast<int>(v1.size() - 1);

    bigint.digits.clear();
    while (i >= 0)
    {
        bigint.digits.push_back(v1[i]);
        i--;
    }
}

void Bigint::print_bigint(std::vector<int>& v1)
{
    for (size_t i = 0; i < v1.size(); i++)
    {
       std::cout << v1[i];
    }
    std::cout << std::endl;
}