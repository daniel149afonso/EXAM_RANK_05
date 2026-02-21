# include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() {}
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &o) : tree_bag(o) {}
searchable_tree_bag&	searchable_tree_bag::operator=(const searchable_tree_bag &o) {
	if (this != &o)
		tree_bag::operator=(o);
	return (*this);
}
searchable_tree_bag::~searchable_tree_bag() {}

bool	searchable_tree_bag::has_node(node *current, int item) const {
	if (!current)
		return (false);
	if (current->value == item)
		return (true);
	if (item < current->value)
		return (has_node(current->l, item));
	else
		return (has_node(current->r, item));
}

bool	searchable_tree_bag::has(int item) const {
	return (has_node(this->tree, item));
}
