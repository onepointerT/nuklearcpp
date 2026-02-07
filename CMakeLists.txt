
cmake_minimum_required( VERSION 3.15 )

project( nkcpp C CXX )

set( LIBNUKLEAR_STABLE_VERSION 0 )
set( LIBNUKLEAR_RELEASE 0 )
set( LIBNUKLEAR_PATCH_VERSION 1 )
set( LIBNUKLEAR_VERSION "${LIBNUKLEAR_STABLE_VERSION}.${LIBNUKLEAR_RELEASE}.${LIBNUKLEAR_PATCH_VERSION}" )

set( LIBNUKLEAR_SRC_DIR ${PROJECT_SOURCE_DIR}/src )

set ( PROJECT_NAME "${CMAKE_PROJECT_NAME}" )
set ( PROJECT_VERSION "${LIBNUKLEAR_VERSION}" )
set ( PROJECT_DESCRIPTION "A UI backend basing on nuklear for C." )

set ( CMAKE_CXX_STANDARD 23 )
include_directories( include )

if( NUKLEAR_DESTDIR )
else()
	set( NUKLEAR_DESTDIR "${CMAKE_INSTALL_PREFIX}" )
endif()


## Build VFS dependencies
# Build vfspp
include_directories( lib/fs/vfspp )
add_subdirectory( lib/fs/vfspp )
# Build f2fs
include_directories( lib/fs/f2fs/include )
file ( GLOB LIBF2FS_SOURCE lib/fs/f2fs/fs/*.c )
add_library( f2fs ${LIBF2FS_SOURCE} )
# Build lib56vfs
include_directories( lib/fs/56vfs/ )
include( ${PROJECT_SOURCE_DIR}/cmake/buildproject/56vfs.cmake )




## Build nkvfspp
include_directories( include/fs )
file( GLOB LIBNKVFS_SOURCE src/fs/*.cpp )
add_library( nkvfs ${LIBNKVFS_SOURCE} )
target_link_libraries( nkvfs vfspp f2fs )


## Build the nuklearC++ gui dependencies
# Build the openGL graphics backend pantheon
add_subdirectory( lib/gui/pantheon )
include_directories( lib/gui/pantheon/lib lib/gui/pantheon/src )
# Build nuklear, the C backend for UI
add_subdirectory( lib/gui/nuklear )
include_directories( lib/gui/nuklear/src )



## Build nuklearcpp GUI
include_directories( include/gui )
file ( GLOB LIBNUKLEAR_SOURCE ${LIBNUKLEAR_SRC_DIR}/*.cpp )

if( NUKLEAR_SHARED )
	add_library( nkcpp SHARED ${LIBNUKLEAR_SOURCE} )
else()
	add_library( nkcpp STATIC ${LIBNUKLEAR_SOURCE} )
endif()
target_link_libraries( nkcpp nk )


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
	install(FILES ${PROJECT_SOURCE_DIR}/lib/gui/LIBNUKLEARConfig.cmake DESTINATION "${NUKLEAR_LIB_INSTALL_DIR}/cmake/LIBNUKLEAR" )
	configure_file(${PROJECT_SOURCE_DIR}/lib/gui/LIBNUKLEAR.pc.in ${CMAKE_CURRENT_BINARY_DIR}/LIBNUKLEAR.pc @ONLY)
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
