/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:48:27 by danielafons       #+#    #+#             */
/*   Updated: 2026/01/26 18:59:53 by danielafons      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <vector>

class Bigint {
    private:
        std::vector<int> digits;
    public:
    Bigint();
    Bigint(int nb);
    Bigint operator+(const Bigint& other);
    //std::ostream &operator<<(std::ostream &out, const Bigint& n);
    void normalize(Bigint& bigint, const std::vector<int>& v1);
    void remove_zeros(std::vector<int>& v1);
    void print_bigint(std::vector<int>& v1);
};

#endif
