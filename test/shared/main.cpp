#define BOOST_TEST_MODULE shared
#include <boost/test/unit_test.hpp>

#include "someclass.hpp"

BOOST_AUTO_TEST_CASE(t_shared)
{
    someclass something;
    BOOST_REQUIRE_EQUAL(-42, something.neg());
    someclass another = something;
    BOOST_REQUIRE_EQUAL(-42, another.neg());
    something.set(24);
    BOOST_REQUIRE_EQUAL(-24, another.neg());
}

