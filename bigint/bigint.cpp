/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:48:31 by danielafons       #+#    #+#             */
/*   Updated: 2026/01/19 12:30:45 by danielafons      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bigint.hpp"

Bigint::Bigint(const std::string& str): str(str)
{
    
}

Bigint& Bigint::operator+(const Bigint& other)
{
    
    std::vector<int> this.v1 = {0, 0, 0, 0, 0, 0};
    std::vector<int> other.v2 = {0, 0};
    std::vector<int> v3;

    if (this.v1.size() > 1 || other.v2.size() > 1)
        return (1);

    int i = static_cast<int>(this.v1.size() - 1);
    int j = static_cast<int>(other.v2.size() - 1);
    int sum, result, carry = 0;
    while (i >= 0 || j >= 0)
    {
        int a = (i >= 0) ? this.v1[i] : 0;
        int b = (j >= 0) ? other.v2[j] : 0;

        sum = a + b + carry;
        result = sum % 10;
        carry = sum / 10;

        v3.push_back(result);
        i--;
        j--;
    }
    if (carry)
        v3.push_back(carry);
    i = static_cast<int>(v3.size() - 1);
    while (v3.size() > 1 && v3.back() == 0)
    {
        v3.pop_back();
        i--;
    }

    for (int i = static_cast<int>(v3.size() - 1); i > -1; i--)
        std::cout << v3[i];
    std::cout << std::endl;
    return (0);
}