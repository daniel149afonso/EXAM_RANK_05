/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:52:21 by daniel149af       #+#    #+#             */
/*   Updated: 2026/02/21 12:58:50 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag(): array_bag(), searchable_bag()
{

}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &other): array_bag(other)
{

}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag &other)
{
	if (this != &other)
		array_bag::operator=(other);
	return *this;
}

searchable_array_bag::~searchable_array_bag()
{

}

bool searchable_array_bag::has(int x) const
{
	for (int i = 0; i < size; i++)
	{
		if (x == data[i])
			return true;
	}
	return false;
}