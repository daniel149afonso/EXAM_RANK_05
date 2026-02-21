/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:52:21 by daniel149af       #+#    #+#             */
/*   Updated: 2026/02/21 12:58:50 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(): tree_bag(), searchable_bag()
{
	
}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other): tree_bag(other)
{

}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag &other)
{
	if (this != &other)
		tree_bag::operator=(other);
	return *this;
}

searchable_tree_bag::~searchable_tree_bag()
{

}

bool searchable_tree_bag::has(int x) const
{
	const node *tmp = tree;
	while (tmp)
	{
		if (x < tmp->value)
			tmp = tmp->l;
		else if (x > tmp->value)
			tmp = tmp->r;
		else if (x == tmp->value)
			return true;
	}
	return false;
}