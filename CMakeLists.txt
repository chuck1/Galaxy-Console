CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

PROJECT(galaxy_console)

FIND_PACKAGE(CMakeHelper)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_STATIC_RUNTIME OFF)
add_definitions( -DBOOST_ALL_DYN_LINK )


FIND_PACKAGE(Galaxy COMPONENTS
	std
	REQUIRED)
FIND_PACKAGE(Boost 1.55 COMPONENTS
	python
	REQUIRED)

SET(include_dirs ${include_dirs} "/usr/include/python2.7")

INCLUDE_DIRECTORIES("/usr/include/python2.7")

set(Boost_LIBRARY_DIRS $ENV{HOME}/usr/lib)

SET(libs
	${Galaxy_LIBRARIES}
	${Boost_LIBRARIES}
	python2.7)


cmh_static_library()


ADD_SUBDIRECTORY(test)





PROJECT(galaxy_console_shared)

SET(libs)

SET(Galaxy_SHARED TRUE)
FIND_PACKAGE(Galaxy COMPONENTS
	std
	REQUIRED)

cmh_shared_library()


