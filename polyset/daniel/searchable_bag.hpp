#pragma once

#include "bag.hpp"
#include <iostream>
#include <cstddef>

class searchable_bag : virtual public bag {
	protected:
		searchable_bag(){};
	public:
		virtual ~searchable_bag(){};
		virtual bool has(int) const = 0;
};
