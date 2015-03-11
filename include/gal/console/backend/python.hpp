#ifndef GAL_STD_TERMINAL_PYTHON_HPP
#define GAL_STD_TERMINAL_PYTHON_HPP

#include <boost/python.hpp>

#include <sstream>

#include <gal/console/backend/base.hpp>

namespace bp = boost::python;

namespace gal { namespace console { namespace backend {
	class python:
		virtual public gal::console::backend::base
	{
	public:
		virtual void	init(parent_t * const & parent);
		virtual void	release();
		virtual void	eval(std::string const & s);
		void		exec_file(std::string filename);
	public:
		bp::object	main_module_;
		bp::object	main_namespace_;
	};
}}}

#endif

