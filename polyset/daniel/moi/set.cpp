/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:17:21 by daniel149af       #+#    #+#             */
/*   Updated: 2026/02/23 13:13:15 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

set::set(searchable_bag& other): _bag(other)
{
	
}

set::~set()
{
	
}

void set::insert(const int nb)
{
	if (_bag.has(nb))
		return ;
	_bag.insert(nb);
}

bool set::has(const int nb) const
{
	return _bag.has(nb);
}

void set::print() const 
{
	_bag.print();
}

searchable_bag& set::get_bag() const
{
	return _bag;
}

void set::clear()
{
	_bag.clear();
}

