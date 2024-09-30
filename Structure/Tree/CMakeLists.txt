
message(STATUS "-> RBTree")

add_executable(RBTree RBTree.cpp RBTree.hpp)

add_executable(BiTree BiTree.cpp)

# SegmentTree
add_executable(SegmentTree SegmentTree.cpp SegmentTree.hpp)

# SegmentTreeTest
add_executable(SegmentTreeTest SegmentTreeTest.cpp SegmentTree.hpp)
add_test(SegmentTreeTest SegmentTreeTest)
target_link_libraries(SegmentTreeTest PRIVATE Catch2::Catch2WithMain)
