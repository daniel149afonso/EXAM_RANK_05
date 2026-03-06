/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:52:18 by daniel149af       #+#    #+#             */
/*   Updated: 2026/02/21 13:01:46 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../array_bag.hpp"
#include "../searchable_bag.hpp"
#include <iostream>
#include <cstddef>

class searchable_array_bag: public array_bag, public searchable_bag {
	public:
		searchable_array_bag();
		searchable_array_bag(const searchable_array_bag& other);
		searchable_array_bag  &operator=(const searchable_array_bag& other);
		~searchable_array_bag();

		//public method
		bool has(int) const;
};