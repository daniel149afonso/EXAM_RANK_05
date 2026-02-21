#pragma once

# include "searchable_bag.hpp"
# include "tree_bag.hpp"

class	searchable_tree_bag : public searchable_bag, public tree_bag {

	private:
		virtual bool	has_node(node *current, int item) const;

	public:
		searchable_tree_bag();
		searchable_tree_bag(const searchable_tree_bag &o);
		searchable_tree_bag&	operator=(const searchable_tree_bag &o);
		~searchable_tree_bag();

		virtual bool	has(int item) const;
};
