CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

PROJECT(galaxy_console)

SET(galaxy_console_STATIC TRUE)

FIND_PACKAGE(CMakeHelper)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_STATIC_RUNTIME OFF)
add_definitions( -DBOOST_ALL_DYN_LINK )

FIND_PACKAGE(Boost 1.55 COMPONENTS
	system
	thread
	program_options
	python
	REQUIRED)

FIND_PACKAGE(Galaxy COMPONENTS
	std
	REQUIRED)

INCLUDE_DIRECTORIES("/usr/include/python2.7")


set(Boost_LIBRARY_DIRS $ENV{HOME}/usr/lib)

SET(libs
	${PROJECT_NAME}
	${galaxy_LIBRARIES}
	${Boost_LIBRARIES}
	python2.7
	)

MESSAGE(STATUS "${Boost_INCLUDE_DIRS}")
MESSAGE(STATUS "${Boost_LIBRARY_DIRS}")

cmh_library()

ADD_SUBDIRECTORY(test)

