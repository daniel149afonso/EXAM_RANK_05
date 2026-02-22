/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:17:21 by daniel149af       #+#    #+#             */
/*   Updated: 2026/02/22 15:19:42 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

set::set()
{
	_bag = NULL;
}

set::set(const set& other)
{

}

set& set::operator=(const set& other)
{
	
}
	
set::~set()
{
	
}

set::set(const searchable_bag& other)
{
	if (dynamic_cast<const searchable_array_bag*>(&other))
		_bag = new searchable_array_bag(other);
	else
		_bag = new searchable_tree_bag(other);
		
}

set& set::operator=(const searchable_bag& other)
{
	
}