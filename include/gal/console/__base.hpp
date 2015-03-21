#ifndef GALAXY_CONSOLE___BASE_HPP
#define GALAXY_CONSOLE___BASE_HPP

#include <string>
#include <deque>
#include <sstream>

#include <gal/managed_object.hpp>

#include <gal/console/scroller.hpp>

namespace gal { namespace console {
	/** data for stringstream to interact with */
	class __base:
		virtual public gal::managed_object
	{
	public:
		/** @brief write line
		 * @note frontend
		 *
		 * add line to terminal history
		 */
		virtual void						write_line(::std::string const & s) = 0;
		virtual void						release();
		std::stringstream					ss_;
		scroller<std::string>					line_;
		std::string						prompt_end_;
	};
}}

#endif
