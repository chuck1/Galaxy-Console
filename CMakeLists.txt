CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

PROJECT(galaxy_console_shared)

FIND_PACKAGE(CMakeHelper)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_STATIC_RUNTIME OFF)
add_definitions(-DBOOST_ALL_DYN_LINK)

set(Boost_LIBRARY_DIRS $ENV{HOME}/usr/lib)

FIND_PACKAGE(Boost 1.55 COMPONENTS
	program_options
	python
	system
	thread
	REQUIRED)

INCLUDE_DIRECTORIES("/usr/include/python2.7")
INCLUDE_DIRECTORIES("../../Galaxy-Standard/include")

LINK_DIRECTORIES("../../Galaxy-Standard/Debug")

SET(libs
	${PROJECT_NAME}
	galaxy_std_shared
	${Boost_LIBRARIES}
	python2.7
	)

MESSAGE(STATUS "${Boost_INCLUDE_DIRS}")
MESSAGE(STATUS "${Boost_LIBRARY_DIRS}")


cmh_shared_library()

ADD_SUBDIRECTORY(test)

