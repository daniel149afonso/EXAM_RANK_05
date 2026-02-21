#include "set.hpp"

set::set(searchable_bag &bag_to_wrap) : _bag(bag_to_wrap) {}
set::set(const set &o) : _bag(o._bag) {}
set&	set::operator=(const set &o) {
	if (this != &o)
		_bag = o._bag;
	return (*this);
}
set::~set() {}
searchable_bag&	set::get_bag() const { return (_bag); }

void	set::insert(int item) {
	if (!_bag.has(item))
		_bag.insert(item);
}

void	set::insert(int *items, int count) {
	for (int i = 0; i < count; i++)
		this->insert(items[i]);
}

void	set::print() const {
	_bag.print();
}

void	set::clear() {
	_bag.clear();
}

bool	set::has(int item) const {
	if (_bag.has(item))
		return (true);
	return (false);
}
