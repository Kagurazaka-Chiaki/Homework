cmake_minimum_required(VERSION 3.30)


add_executable(cpp_ref main.cpp)


# 输入输出
add_subdirectory(PIO)

# 面试 Top101
add_subdirectory(Top101)

# 笔试 Top101
add_subdirectory(BISHI)

# 临时题库 Quiz
# add_subdirectory(Quiz)

# 真题
add_subdirectory(REAL)
