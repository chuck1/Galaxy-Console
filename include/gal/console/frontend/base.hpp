#ifndef GAL_CONSOLE_FRONTEND_BASE_HPP
#define GAL_CONSOLE_FRONTEND_BASE_HPP

#include <sstream>

#include <gal/stl/child.hpp>

#include <gal/console/decl.hpp>

namespace gal { namespace console { namespace frontend {
	class base:
		virtual public gal::stl::child<gal::console::base>
	{
	public:
		typedef std::deque<std::string> D;
		void			print();
		virtual void		init(parent_t * const & p) = 0;
		virtual D const &	lines_ref() = 0;
		virtual void		enter() = 0;
		virtual void		write_line(std::string const & s) = 0;
		virtual void		release();
	};
}}}

#endif

