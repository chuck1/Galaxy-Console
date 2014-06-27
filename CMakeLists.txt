CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

INCLUDE($ENV{HOME}/.config.cmake)

<<<<<<< HEAD
PROJECT(galaxy_console)

SET(galaxy_console_STATIC TRUE)
=======
PROJECT(galaxy_console_shared)
>>>>>>> ccaae796688a5efa2ae049a02c2937fb17ac9e0c

FIND_PACKAGE(CMakeHelper)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_STATIC_RUNTIME OFF)
<<<<<<< HEAD
add_definitions( -DBOOST_ALL_DYN_LINK )

FIND_PACKAGE(Boost 1.55 COMPONENTS
	system
	thread
	program_options
	python
	REQUIRED)

INCLUDE_DIRECTORIES("/usr/include/python2.7")


SET(libs
	${Boost_LIBRARIES}
	pthread
	python2.7
	rt
	dl
	)




cmh_library()

#ADD_SUBDIRECTORY(test)
=======
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
>>>>>>> ccaae796688a5efa2ae049a02c2937fb17ac9e0c

