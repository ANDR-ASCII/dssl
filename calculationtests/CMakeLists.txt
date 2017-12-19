cmake_minimum_required(VERSION 2.8.11)
project(${CalculationTests})

set(CalculationTestsSourceDir src)
set(CalculationTestsHeaderDir include)

# deps headers
set(CalculationHeadersDir ../calculation/include)
set(GoogleTestHeadersDir ../googletest/googletest/include)

aux_source_directory(${CalculationTestsSourceDir} CalculationTestsSourcesList)
file(GLOB_RECURSE CalculationTestsHeaderList "include/*.h")

list(REMOVE_ITEM CalculationTestsSourcesList src/stdafx.cpp)

add_msvc_precompiled_header("stdafx.h" "src/stdafx.cpp" CalculationTestsSourcesList)

source_group("Precompiled Headers" FILES include/stdafx.h src/stdafx.cpp)

add_executable(
	${CalculationTests} 
	${CalculationTestsSourcesList} 
	${CalculationTestsHeaderList}
)

add_definitions(
	${QT_DEFINITIONS}
)

if(MSVC)
	add_definitions(
		/EHsc
		/MP
		/permissive-
		/std:c++latest
	)
	
	set_target_properties(
		${CalculationTests}
		PROPERTIES COMPILE_FLAGS "/FI\"stdafx.h\""
	)
	
	set_target_properties(
		${CalculationTests} 
		PROPERTIES WIN32_EXECUTABLE YES
		LINK_FLAGS "/ENTRY:mainCRTStartup"
		LINK_FLAGS "/SUBSYSTEM:CONSOLE"
	)

endif()

include_directories(
	${CalculationTestsHeaderDir}
	${CalculationHeadersDir}
)

target_link_libraries(
	${CalculationTests}
	${CalculationLibName}
	gtest
)