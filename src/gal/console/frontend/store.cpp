#include <gal/console/base.hpp>
#include <gal/console/frontend/store.hpp>

typedef gal::console::frontend::store THIS;

THIS::store():
	lines_max_(1000)
{
}
void			THIS::init(parent_t * const & p)
{
	init_verb(p->get_vr());
	
	setParent(p);
}
void			THIS::write_line(std::string const & s)
{	
	lines_.push_back(s);

	while(lines_.size() > lines_max_) {
		lines_.pop_front();
	}
}
void			gal::console::frontend::store::enter()
{	
	auto p = getParent();

	p->operator<<(p->prompt_end_) << p->line_.container;
	
	p->eval(p->line_.container);
	
	p->line_.clear();
	
	return;
}
THIS::D const &		THIS::lines_ref()
{
	return lines_;
}

