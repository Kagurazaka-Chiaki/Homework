#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE DemoTests
#endif

#include <boost/test/unit_test.hpp>
#include <../include/Solution.hpp>

BOOST_AUTO_TEST_SUITE(test)

BOOST_AUTO_TEST_CASE(normal_test) {
    printf("In test\n ---------------------------------");
    Solution S;
    BOOST_CHECK_EQUAL(5, S.fib(5));
    
}

BOOST_AUTO_TEST_SUITE_END()