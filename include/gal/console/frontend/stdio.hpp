#ifndef GAL_CONSOLE_FRONTEND_STDIO_HPP
#define GAL_CONSOLE_FRONTEND_STDIO_HPP

#include <gal/console/frontend/base.hpp>

namespace gal { namespace console { namespace frontend {

	class stdio:
		virtual public gal::console::frontend::base
	{
		public:

			virtual void			write_line(::std::string const & s);
			virtual void			enter();

			void				loop();



	};

}}}

#endif
