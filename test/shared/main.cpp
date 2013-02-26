#define BOOST_TEST_MODULE shared
#include <boost/test/unit_test.hpp>

#include "someclass.hpp"

BOOST_AUTO_TEST_CASE(test_base)
{
    someclass something;
    BOOST_REQUIRE_EQUAL(-42, something.neg());
    BOOST_REQUIRE_EQUAL(-42, something.outside_neg());
    someclass another = something;
    someclass yanother = something.clone();
    BOOST_REQUIRE_EQUAL(-42, another.neg());
    BOOST_REQUIRE_EQUAL(-42, another.outside_neg());
    something.set(24);
    BOOST_REQUIRE_EQUAL(-42, yanother.neg());
    BOOST_REQUIRE_EQUAL(-24, another.neg());
    BOOST_REQUIRE_EQUAL(-24, another.outside_neg());
    something.outside_set(13);
    BOOST_REQUIRE_EQUAL(-13, another.neg());
    BOOST_REQUIRE_EQUAL(-13, another.outside_neg());
}

