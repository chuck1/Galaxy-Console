CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

PROJECT(galaxy_console)

MESSAGE(STATUS "project galaxy_console")
MESSAGE(STATUS "libs ${libs}")

SET(galaxy_console_STATIC TRUE)

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

LIST(APPEND libs
	${Boost_LIBRARIES}
	python2.7)


cmh_library()

MESSAGE(STATUS "libs ${libs}")

ADD_SUBDIRECTORY(test)

