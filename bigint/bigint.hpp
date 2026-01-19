/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:48:27 by danielafons       #+#    #+#             */
/*   Updated: 2026/01/19 12:26:52 by danielafons      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <vector>

class Bigint {
    private:
        unsigned int bigint;
        std::vector<int> v1;
        std::string str;
    public:
    Bigint(const std::string& str);
    Bigint& operator+(const Bigint& other);
    Bigint& operator<<(const Bigint& other);
};

#endif
