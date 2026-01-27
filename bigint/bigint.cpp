/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:48:31 by danielafons       #+#    #+#             */
/*   Updated: 2026/01/26 19:15:14 by danielafons      ###   ########.fr       */
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
    for (size_t i = 0; i < this->digits.size(); i++)
    {
       std::cout << this->digits[i];
    }
    std::cout << std::endl;
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
    remove_zeros(v1);
    //debug
    std::cout << "Result V1: ";
    print_bigint(v1);
    normalize(bigint, v1);
    //debug
    std::cout << "Result Addition: ";
    for (size_t i = 0; i < bigint.digits.size(); i++)
    {
       std::cout << bigint.digits[i];
    }
    std::cout << std::endl;
    return (bigint);
}

void Bigint::normalize(Bigint& bigint, const std::vector<int>& v1)
{
    int i = static_cast<int>(v1.size() - 1);
    int end = i;

    while (i >= 0)
    {
        if (bigint.digits[0] == 0)
            bigint.digits[0] = v1[i];
        else
            bigint.digits.push_back(v1[i]);
        i--;
    }
}

void Bigint::remove_zeros(std::vector<int>& v1)
{
    int i = static_cast<int>(v1.size() - 1);
    while (v1.size() > 1 && v1.back() == 0)
    {
        v1.pop_back();
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