#ifndef NEBULA_UTIL_TERMINAL_BASE_HPP
#define NEBULA_UTIL_TERMINAL_BASE_HPP

#include <string>
#include <deque>
#include <sstream>

// gal/console/frontend/store.hpp
// gal/console/backend/python.hpp

#include <gal/object/Child.hpp>

#include <gal/console/decl.hpp>
#include <gal/console/__base.hpp>
#include <gal/console/sstream.hpp>

namespace gal { namespace console {
	class base:
		virtual public gal::console::__base,
		virtual public gal::object::Child<gal::console::util::Parent>
	{
	public:
		typedef std::vector<std::string> V;
		typedef std::deque<std::string> D;
		
		/** @brief push formatted text into terminal history */
		template<typename T>
		gal::console::stringstream		operator<<(T const & t)
		{
			auto s = std::dynamic_pointer_cast<gal::console::base>(shared_from_this());
			gal::console::stringstream ss(s);
			return std::move(ss << t);
		}
		/** @brief push character onto current line */
		void			push(char c);
		void			init(parent_t * const & p);
		virtual void		release();
		void			print();
		// interface
		D const &		lines_ref();
		void			enter();
		/** @brief evaluate
		 * @note backend
		 */
		void			eval(std::string const & s);
		virtual void		write_line(std::string const & s);

		std::shared_ptr<gal::console::frontend::base>	_M_frontend;
		std::shared_ptr<gal::console::backend::base>	_M_backend;
	};
}}

#endif



