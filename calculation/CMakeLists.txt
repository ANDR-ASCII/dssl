cmake_minimum_required(VERSION 2.8.11)
project(${CalculationLibName})

set(CalculationSourcesDir src)
set(CalculationHeadersDir include)

aux_source_directory(${CalculationSourcesDir} CalculationSourcesList)
file(GLOB_RECURSE CalculationHeadersList "include/*.h")

list(REMOVE_ITEM CalculationSourcesList src/stdafx.cpp)
add_msvc_precompiled_header("stdafx.h" "src/stdafx.cpp" CalculationSourcesList)

source_group("Precompiled Headers" FILES include/stdafx.h src/stdafx.cpp)

add_library(
 	${CalculationLibName} 
 	${CalculationSourcesList} 
 	${CalculationHeadersList}
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
		/Zi
	)
	
	set_target_properties(
		${CalculationLibName}
		PROPERTIES COMPILE_FLAGS "/FI\"stdafx.h\""
		LINK_FLAGS /DEBUG
	)

endif()

include_directories(
	${CalculationHeadersDir}
)

target_link_libraries(
	${CalculationLibName}
)