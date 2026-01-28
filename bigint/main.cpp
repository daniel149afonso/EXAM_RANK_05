/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:48:37 by danielafons       #+#    #+#             */
/*   Updated: 2026/01/28 20:26:30 by danielafons      ###   ########.fr       */
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
    Bigint a(111);
    Bigint b(111);
    
    if (a==b)
        std::cout << "true\n";
    return (0);
}