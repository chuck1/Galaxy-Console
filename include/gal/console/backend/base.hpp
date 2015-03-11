#ifndef GAL_CONSOLE_BACKEND_BASE_HPP
#define GAL_CONSOLE_BACKEND_BASE_HPP

#include <sstream>

#include <gal/stl/child.hpp>

#include <gal/console/decl.hpp>

namespace gal { namespace console { namespace backend {
	class base:
		virtual public gal::stl::child<gal::console::base>
	{
	public:
		virtual void	init(parent_t * const & p) = 0;
		virtual void	eval(std::string const & s) = 0;
		virtual void	exec_file(std::string filename) = 0;
	};
}}}

#endif

