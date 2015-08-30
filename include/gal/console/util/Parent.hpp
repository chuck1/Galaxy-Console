#ifndef GAL_CONSOLE_UTIL_PARENT_HPP
#define GAL_CONSOLE_UTIL_PARENT_HPP

#include <gal/mng/managed_object.hpp>

namespace gal { namespace console { namespace util {
	class Parent:
		virtual public gal::managed_object
	{
	public:
		virtual ~Parent() {}
	};
}}}

#endif

