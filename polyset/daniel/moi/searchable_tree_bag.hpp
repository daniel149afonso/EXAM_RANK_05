/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:52:18 by daniel149af       #+#    #+#             */
/*   Updated: 2026/02/22 13:49:41 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstddef>
#include "../tree_bag.hpp"
#include "../searchable_bag.hpp"

class searchable_tree_bag: public tree_bag, public searchable_bag {
	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag& other);
		searchable_tree_bag  &operator=(const searchable_tree_bag& other);
		~searchable_tree_bag();

		//public method
		bool has(int) const;
};