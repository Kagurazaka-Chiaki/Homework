


file(GLOB_RECURSE SRC_FILES "*.cpp")
foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(SRC_FILE_NAME ${SRC_FILE} NAME_WE)
    add_executable(InOut${SRC_FILE_NAME} ${SRC_FILE})
endforeach(SRC_FILE)
