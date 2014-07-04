#ifndef GALAXY_CONSOLE___BASE_HPP
#define GALAXY_CONSOLE___BASE_HPP

#include <string>
#include <deque>
#include <sstream>

#include <gal/std/shared.hpp>


namespace gal { namespace console {
	
	class __base: virtual public gal::std::shared {
		public:
			::std::deque< ::std::string >			lines_;
			::std::stringstream				ss_;
	};
	
}}

#endif
