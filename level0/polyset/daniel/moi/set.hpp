/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:17:19 by daniel149af       #+#    #+#             */
/*   Updated: 2026/02/23 13:12:35 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../searchable_bag.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

class set
{
	private:
		searchable_bag& _bag;
	public:
		set();
		set(const set& other);
		set& operator=(const set& other);
		~set();

		//searchable
		set(searchable_bag& other);
		void insert(const int nb);
		bool has(const int nb) const;
		void print() const;
		searchable_bag& get_bag() const;
		void clear();
		template <int N>
		void insert(const int (&nb)[N], const int size) {
			for (int i = 0; i < size; i++)
				insert(nb[i]);
		}
};
