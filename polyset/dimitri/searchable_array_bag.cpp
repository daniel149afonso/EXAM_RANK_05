# include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() {}
searchable_array_bag::searchable_array_bag(const searchable_array_bag &o) : array_bag(o) {}
searchable_array_bag&	searchable_array_bag::operator=(const searchable_array_bag &o) {
	if (this != &o)
		array_bag::operator=(o);
	return (*this);
}
searchable_array_bag::~searchable_array_bag() {}

bool	searchable_array_bag::has(int item) const {
	for (int i = 0; i < size; i++) {
		if (data[i] == item)
			return (true);
	}
	return (false);
}

