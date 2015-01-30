"""
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

FIND_PACKAGE(CMakeHelper)

PROJECT(galaxy_console)
INCLUDE(../../../../config.cmake)
INCLUDE(cmh_build_config)

SET(SHARED True)

FIND_PACKAGE(galaxy 0 COMPONENTS std REQUIRED)

INCLUDE(cmh_boost)
FIND_PACKAGE(Boost 1.55 COMPONENTS
	python
	REQUIRED)

SET(libs
	#galaxy_std_0
	${galaxy_LIBRARIES}
	${Boost_LIBRARIES}
	python2.7)

message(STATUS "boost ${Boost_LIBRARIES}")

INCLUDE_DIRECTORIES("/usr/include/python2.7")

INCLUDE(cmh_library)

ADD_SUBDIRECTORY(test)
"""

l = Library("galaxy_console")

l.inc_dirs.append("/usr/include/python2.7")

l.make()


