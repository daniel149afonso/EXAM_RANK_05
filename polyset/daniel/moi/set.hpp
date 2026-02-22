/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:17:19 by daniel149af       #+#    #+#             */
/*   Updated: 2026/02/22 15:13:24 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../searchable_bag.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

class set
{
	private:
		searchable_bag* _bag;
	public:
		set();
		set(const set& other);
		set& operator=(const set& other);
		~set();

		//searchable
		set(const searchable_bag& other);
		set& operator=(const searchable_bag& other);
};

