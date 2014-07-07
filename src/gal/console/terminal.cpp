
#include <gal/console/base.hpp>
#include <gal/console/backend/command_set.hpp>



gal::console::base::base()
{}
void					gal::console::base::push(char c) {
	line_.push_back(c);
}




