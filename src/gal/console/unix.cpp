#include <gal/console/backend/unix.hpp>

void					gal::std::terminal::eval(::std::string const & s) {

	auto self = sp::dynamic_pointer_cast<gal::std::terminal>(shared_from_this());

	if(cs_) {
		(*cs_)(self, line_);
	} else {
		operator<<("No commands exist.");
	}

}
