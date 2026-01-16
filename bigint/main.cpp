/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:48:37 by danielafons       #+#    #+#             */
/*   Updated: 2026/01/16 10:54:14 by danielafons      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cerr << "Error: missing argument\n", 1);
    int nb;
    std::string bigint;
    std::vector<int> v1;
    bigint = argv[1];
    nb = static_cast<int>(bigint[0]);
    v1[0] = nb;
    std::cout << v1[0] << std::endl;
    return (0);
}