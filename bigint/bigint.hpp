/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:48:27 by danielafons       #+#    #+#             */
/*   Updated: 2026/02/02 12:56:34 by danielafons      ###   ########.fr       */
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
    
    // Constructors
    Bigint();
    Bigint(int nb);
    Bigint(const Bigint& other);
    
    // Overloaded Operators
    Bigint& operator=(const Bigint& other);

    // Arithmetic Operators
    Bigint operator+(const Bigint& other) const;
    Bigint& operator+=(const Bigint& other);

    // Incrementation / decrementation
    Bigint& operator++();
    Bigint operator++(int);

    // Comparison Operators
    bool operator==(const Bigint& other) const;
    bool operator!=(const Bigint& other) const;
    bool operator>(const Bigint& other) const;
    bool operator>=(const Bigint& other) const;
    bool operator<(const Bigint& other) const;
    bool operator<=(const Bigint& other) const;

    //Digits shiffting
    Bigint operator<<(int nb) const;
    Bigint operator>>(int nb) const;

    
    // Public Methods
    void normalize(Bigint& bigint, const std::vector<int>& v1) const;
    void print_bigint(std::vector<int>& v1);
    void print_digits(std::ostream &out) const;
};

std::ostream &operator<<(std::ostream &out, const Bigint& n);
#endif
