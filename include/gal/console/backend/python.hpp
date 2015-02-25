#ifndef GAL_STD_TERMINAL_PYTHON_HPP
#define GAL_STD_TERMINAL_PYTHON_HPP

#include <boost/python.hpp>

#include <sstream>

#include <gal/console/base.hpp>

namespace bp = boost::python;



namespace gal { namespace console { namespace backend {


	class python: virtual public gal::console::base {
		public:
			python();

			virtual void		init();
			virtual void		eval(::std::string const & s);

		public:

			bp::object		main_module_;
			bp::object		main_namespace_;

	};



}}}

#endif

