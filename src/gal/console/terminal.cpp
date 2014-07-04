
#include <gal/console/base.hpp>
#include <gal/console/backend/command_set.hpp>



gal::console::base::base():
	lines_max_(20),
	prompt_end_("$ ")
{}
void					gal::console::base::push(char c) {
	line_.push_back(c);
}
void					gal::console::base::enter() {

	
	operator<<(prompt_end_) << line_;
	
	eval(line_);
	
	line_.clear();
	
	return;

	while(lines_.size() > lines_max_) {
		lines_.pop_front();
	}

}



