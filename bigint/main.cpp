/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:48:37 by danielafons       #+#    #+#             */
/*   Updated: 2026/01/26 18:37:56 by danielafons      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bigint.hpp"

int ft_isdigit(std::string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return (0);
    }
    return (1);
}

int main()
{
    Bigint a(0000222);
    Bigint b(111);
    
    a + b;
    // Bigint bigint;
    // std::string str;
    // std::vector<int> v1;
    
    // if (!ft_isdigit(str))
    //     return (std::cerr << "Error: only digits accepted\n", 1);
    // int i = 0;
    // while (str[i])
    // {
    //     v1.push_back(str[i] - '0');
    //     i++;
    // }
    
    //debug
    // for (int i = 0; i < v1.size(); i++)
    // {
    //     std::cout << v1[i];
    // }
    // std::cout  << std::endl;
    return (0);
}