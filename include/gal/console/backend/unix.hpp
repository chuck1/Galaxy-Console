#ifndef NEBULA_UTIL_TERMINAL_UNIX_HPP
#define NEBULA_UTIL_TERMINAL_UNIX_HPP

#include <string>
#include <deque>
#include <sstream>

#include <gal/console/base.hpp>

namespace gal { namespace console {
	
	class command_set;


	/** @brief terminal */
	class unix: virtual public gal::console::base {
		public:
			unix();
			virtual ~unix() {}	
			
			virtual void						eval(::std::string const & s);
			

			/** @brief %command_set
			 *
			 * @note WEAK
			 */
			::std::shared_ptr<gal::console::command_set>		cs_;


				

	};

}}

#endif



