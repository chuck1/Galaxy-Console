#ifndef GALAXY_CONSOLE___BASE_HPP
#define GALAXY_CONSOLE___BASE_HPP

#include <string>
#include <deque>
#include <sstream>

#include <gal/std/shared.hpp>

namespace gal { namespace console {
	
	class __base: virtual public gal::std::shared {
		public:
			/** @brief write line
			 * @note frontend
			 *
			 * add line to terminal history
			 */
			virtual void						write_line(::std::string const & s) = 0;



			::std::stringstream					ss_;

			::std::string						line_;
			::std::string						prompt_end_;

	};
	
}}

#endif
