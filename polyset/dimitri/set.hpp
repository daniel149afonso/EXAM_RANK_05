#pragma once

# include "searchable_bag.hpp"
# include "tree_bag.hpp"
# include "array_bag.hpp"

class	set {

	private:
		searchable_bag	&_bag;
		set&	operator=(const set &o);

	public:
		set(searchable_bag &bag_to_wrap);
		set(const set &o);
		~set();

		searchable_bag	&get_bag() const;
		void			insert(int item);
		void			insert(int *items, int count);
		void			print() const;
		void			clear();
		bool			has(int item) const;
};
