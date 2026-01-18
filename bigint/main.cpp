/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:48:37 by danielafons       #+#    #+#             */
/*   Updated: 2026/01/18 16:21:21 by danielafons      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"
int ft_isdigit(std::string bigint)
{
    for (int i = 0; i < bigint.size(); i++)
    {
        if (!isdigit(bigint[i]))
            return (0);
    }
    return (1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cerr << "Error: missing argument\n", 1);
   
    int nb;
    std::string bigint;
    std::vector<int> v1;
    
    bigint = argv[1];
    if (!ft_isdigit(bigint))
        return (std::cerr << "Error: only digits accepted\n", 1);
    int i = 0;
    while (bigint[i])
    {
        v1.push_back(bigint[i] - '0');
        i++;
    }
    
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << std::endl;
    }
    return (0);
}