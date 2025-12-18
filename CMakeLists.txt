
cmake_minimum_required( VERSION 3.15 )

project( nuklearcpp C CXX )

set( LIBNUKLEAR_STABLE_VERSION 0 )
set( LIBNUKLEAR_RELEASE 0 )
set( LIBNUKLEAR_PATCH_VERSION 1 )
set( LIBNUKLEAR_VERSION "${LIBNUKLEAR_STABLE_VERSION}.${LIBNUKLEAR_RELEASE}.${LIBNUKLEAR_PATCH_VERSION}" )

set( LIBNUKLEAR_SRC_DIR ${PROJECT_SOURCE_DIR}/src )

set ( PROJECT_NAME "${CMAKE_PROJECT_NAME}" )
set ( PROJECT_VERSION "${LIBNUKLEAR_VERSION}" )
set ( PROJECT_DESCRIPTION "A UI backend basing on nuklear for C." )


if( NUKLEAR_DESTDIR )
else()
	set( NUKLEAR_DESTDIR "${CMAKE_INSTALL_PREFIX}" )
endif()

# Build the openGL graphics backend pantheon
add_subdirectory( lib/pantheon )
include_directories( lib/pantheon/lib lib/pantheon/src )
# Build nuklear, the C backend for UI
add_subdirectory( lib/nuklear )
include_directories( lib/nuklear/src )

file ( GLOB LIBNUKLEAR_SOURCE ${LIBNUKLEAR_SRC_DIR}/*.cpp )

if( NUKLEAR_SHARED )
	add_library( nuklearcpp SHARED ${LIBNUKLEAR_SOURCE} )
else()
	add_library( nuklearcpp STATIC ${LIBNUKLEAR_SOURCE} )
endif()
target_link_libraries( nuklearcpp  )


if( NUKLEAR_HEADER_INSTALL_DIR )
else()
	set( NUKLEAR_HEADER_INSTALL_DIR ${NUKLEAR_DESTDIR}/include/LIBNUKLEAR )
endif()

if ( NUKLEAR_LIB_INSTALL_DIR )
else()
	set ( NUKLEAR_LIB_INSTALL_DIR ${NUKLEAR_DESTDIR}/lib )
endif()

if( NUKLEAR_INSTALL_LIBS )
	install(TARGETS NUKLEAR DESTINATION ${NUKLEAR_LIB_INSTALL_DIR} )
	install(FILES ${LIBNUKLEAR_HEADERS} DESTINATION ${NUKLEAR_HEADER_INSTALL_DIR} )
	install(FILES ${PROJECT_SOURCE_DIR}/lib/LIBNUKLEARConfig.cmake DESTINATION "${NUKLEAR_LIB_INSTALL_DIR}/cmake/LIBNUKLEAR" )
	configure_file(${PROJECT_SOURCE_DIR}/lib/LIBNUKLEAR.pc.in ${CMAKE_CURRENT_BINARY_DIR}/LIBNUKLEAR.pc @ONLY)
	install(FILES ${CMAKE_CURRENT_BINARY_DIR}/LIBNUKLEAR.pc DESTINATION "${NUKLEAR_LIB_INSTALL_DIR}/pkgconfig" )
endif()


if( UNIX AND ENABLE_DOC_NUKLEAR )
	find_package(Doxygen)
	if(DOXYGEN_FOUND)
		message("-- Enabled doc_NUKLEAR target for make")
		configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
		add_custom_target(doc_NUKLEAR ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} COMMENT "Generating documentation with Doxygen")
	endif()
endif()
