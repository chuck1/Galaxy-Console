#ifndef GAL_CONSOLE_FRONTEND_STORE_HPP
#define GAL_CONSOLE_FRONTEND_STORE_HPP

#include <deque>
#include <string>

#include <gal/console/frontend/base.hpp>

namespace gal { namespace console { namespace frontend {
	class store:
		virtual public gal::console::frontend::base
	{
	public:
		typedef std::vector<std::string> V;
		typedef std::deque<std::string> D;
		store();
		virtual void				init(parent_t * const & p);
		virtual void				write_line(::std::string const & s);
		virtual void				enter();
		virtual D const &			lines_ref();
		unsigned int				lines_max_;
		D					lines_;
	};
}}}

#endif
