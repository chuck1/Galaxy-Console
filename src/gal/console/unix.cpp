#include <gal/console/backend/command_set.hpp>
#include <gal/console/backend/unix.hpp>

gal::console::unix::unix() {
	prompt_end_ = "$ =";
}
void				gal::console::unix::eval(::std::string const & s) {

	auto self = sp::dynamic_pointer_cast<gal::console::base>(shared_from_this());

	if(cs_) {
		(*cs_)(self, s);
	} else {
		operator<<("No commands exist.");
	}

}
