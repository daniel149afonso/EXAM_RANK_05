/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:48:37 by danielafons       #+#    #+#             */
/*   Updated: 2026/01/30 17:56:35 by danielafons      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bigint.hpp"

int main()
{
    Bigint a(111);
    Bigint b(111);
    
    Bigint c;

    c += a;
    std::cout << "test: "<< c << std::endl;

    return (0);
}