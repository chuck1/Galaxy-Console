#include <gal/console/util/Parent.hpp>
#include <gal/console/frontend/base.hpp>
#include <gal/console/backend/base.hpp>
#include <gal/console/base.hpp>

void	gal::console::__base::release()
{
}

typedef gal::console::base THIS;
void				THIS::init(parent_t * const & p)
{
	gal::verb::VerbosityBase::init(p->get_vr());

	setParent(p);

	if(_M_frontend) _M_frontend->init(this);
	if(_M_backend) _M_backend->init(this);
}
void				THIS::release()
{
}
void				THIS::push(char c)
{
	char ch[2];
	ch[0] = c;
	ch[1] = 0;
	line_.insert(ch);
}
void				THIS::print()
{
	assert(_M_frontend);
	_M_frontend->print();
}
THIS::D const &			THIS::lines_ref()
{
	assert(_M_frontend);
	return _M_frontend->lines_ref();
}
void				THIS::enter()
{
	assert(_M_frontend);
	_M_frontend->enter();
}
void				THIS::eval(std::string const & s)
{
	assert(_M_backend);
	_M_backend->eval(s);
}
void				THIS::write_line(std::string const & s)
{
	assert(_M_frontend);
	_M_frontend->write_line(s);
}



