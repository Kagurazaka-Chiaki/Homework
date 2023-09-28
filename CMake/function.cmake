
# Help Functions For CMakeLists.txt

function(add_single_hpp_lib lib_name file_name)
    message(STATUS "由 ${file_name} 构建 ${lib_name}")
    add_library(${lib_name} INTERFACE)
    target_sources(${lib_name} INTERFACE ${file_name})
    target_include_directories(${lib_name} INTERFACE .)

    target_link_libraries(${lib_name} INTERFACE spdlog::spdlog)
endfunction()
