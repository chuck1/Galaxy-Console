#ifndef NEBULA_UTIL_COMMAND_SET_HPP
#define NEBULA_UTIL_COMMAND_SET_HPP

#include <map>
#include <memory>
#include <string>



namespace gal { namespace console {

	class base;
	class command;

	/** @brief %command_set */
	struct command_set {

		typedef ::std::map< ::std::string, ::std::shared_ptr<gal::console::command> >		map_type;

		void			init();
		
		void			list_commands(::std::shared_ptr<gal::console::base> term);

		void			operator()(::std::shared_ptr<gal::console::base>& term, ::std::string const & str);

		map_type		map_;

	};



}}


#endif





