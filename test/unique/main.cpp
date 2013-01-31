#define BOOST_TEST_MODULE unique
#include <boost/test/unit_test.hpp>

#include "someclass.hpp"

BOOST_AUTO_TEST_CASE(t_unique)
{
    someclass something;
    BOOST_REQUIRE_EQUAL(-42, something.foo());
}

