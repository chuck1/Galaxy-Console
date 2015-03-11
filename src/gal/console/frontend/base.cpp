#include <gal/console/frontend/base.hpp>

typedef gal::console::frontend::base THIS;

void		THIS::print()
{
	for(std::string s : lines_ref())
		printf("%s\n", s.c_str());
}
void		THIS::release()
{
}


