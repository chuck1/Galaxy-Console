
#include <gal/console/sstream.hpp>

gal::std::stringstream::stringstream(sp::shared_ptr<gal::std::__terminal_data> t): t_(t) {
	assert(t_);
}
gal::std::stringstream::stringstream(gal::std::stringstream&& ss):
	t_(::std::move(ss.t_))
{}
gal::std::stringstream::~stringstream() {
	if(t_) {
		t_->lines_.push_back(t_->ss_.str());
		t_->ss_.str(::std::string());
	}
}



