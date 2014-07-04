#ifndef NEBULA_UTIL_TERMINAL_HPP
#define NEBULA_UTIL_TERMINAL_HPP

#include <string>
#include <deque>
#include <sstream>

#include <gal/std/shared.hpp>


namespace gal { namespace console {
	
	class command_set;



	/** @brief terminal */
	class unix: virtual public gal::console::base {
		public:
			unix();
			
			virtual void						eval(::std::string const & s);
		


			/** @brief %command_set
			 *
			 * @note WEAK
			 */
			sp::shared_ptr<gal::std::command_set>		cs_;


				

	};

}}

#endif
