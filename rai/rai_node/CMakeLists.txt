add_executable (bitcoinblack_node
	daemon.cpp
	daemon.hpp
	entry.cpp)

target_link_libraries (bitcoinblack_node
	node
	secure
	argon2
	Boost::boost
	${PLATFORM_LIBS}
)

target_compile_definitions(bitcoinblack_node
	PRIVATE
		-DRAIBLOCKS_VERSION_MAJOR=${CPACK_PACKAGE_VERSION_MAJOR}
		-DRAIBLOCKS_VERSION_MINOR=${CPACK_PACKAGE_VERSION_MINOR})

set_target_properties (bitcoinblack_node
	PROPERTIES
		COMPILE_FLAGS
			"-DQT_NO_KEYWORDS -DBOOST_ASIO_HAS_STD_ARRAY=1")

if (RAIBLOCKS_GUI AND NOT APPLE)
	install(TARGETS bitcoinblack_node
			RUNTIME DESTINATION bin
			LIBRARY DESTINATION lib
			ARCHIVE DESTINATION lib
	)
endif()
