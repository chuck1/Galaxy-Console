#ifndef GALAXY_CONSOLE_SCROLLER_HPP
#define GALAXY_CONSOLE_SCROLLER_HPP

#include <string>
#include <deque>
#include <sstream>

#include <gal/mng/managed_object.hpp>

namespace gal { namespace console {
	/**
	 * move around the entry line
	 */
	template<typename T>
	struct scroller
	{
		scroller(): pos(0)
		{
		}
		T&		operator=(T const & t)
		{
			container = t;
			return container;
		}
		template<typename U>
			void				insert(U const & u)
			{
				container.insert(pos, u);
				pos++;
			}
		void				backspace()
		{
			if(!container.empty() && pos > 0) {
				pos--;
				container.erase(pos, 1);
			}
		}
		void				home()
		{
			pos = 0;
		}
		void				end()
		{
			pos = container.size();
		}
		void				del()
		{
			if(!container.empty() && pos < container.size())
				container.erase(pos, 1);
		}
		void				clear()
		{
			container.clear();
			pos = 0;
		}
		void				up()
		{
			if(pos < container.size()) pos++;
		}
		void				down()
		{
			if(pos > 0) pos--;
		}
		/** cursor position */
		typename T::size_type		pos;
		T				container;
	};
}}

#endif


