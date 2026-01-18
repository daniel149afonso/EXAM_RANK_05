/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:48:31 by danielafons       #+#    #+#             */
/*   Updated: 2026/01/18 20:26:24 by danielafons      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

int main ()
{
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {8, 9};
    std::vector<int> v3;

    while ()
    {
        /* code */
    }
    
    for (int i = v1.size() - 1; i >= 0; i--)
    {
        for (int i = v2.size() - 1; i >= 0; i--)
        {
            
        }
    }
    
    int sum = v1[v1.size() - 1] + v2[v2.size() - 1];
    int result = sum % 10;
    int carry = sum / 10;
    
    v3.push_back(result);
    
    sum = v1[v1.size() - 2] + v2[v2.size() - 2] + carry;
    result = sum % 10;
    carry = sum / 10;

    v3.push_back(result);
    
    sum = v1[v1.size() - 2] + 0 + carry;
    v3.push_back(result);
    
    for (int i = 0; i < v3.size(); i++)
    {
        std::cout << v3[i] << std::endl;
    }
    return (0);
}