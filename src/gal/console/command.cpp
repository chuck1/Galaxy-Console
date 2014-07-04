
#include <gal/console/backend/command.hpp>

void			gal::std::command::operator()(terminal_type term, int ac, char const ** av) {

	bpo::variables_map vm;

	bpo::store(bpo::parse_command_line(ac, av, desc_), vm);

	bpo::notify(vm);

	if(func_) {
		func_(term, vm);
	}
}





