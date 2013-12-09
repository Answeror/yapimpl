#include <boost/test/unit_test.hpp>

#include "yapimpl/include/shared.hpp"
#include "yapimpl/include/shared_impl.hpp"

namespace {
    struct no {
        no() : m(yapimpl::use_default_ctor) {}
        ~no() {}

        int a() const { return m->a; }

        struct impl {
            int a;
            impl() : a(1) {}
        };
        yapimpl::shared<impl> m;
    };
}

BOOST_AUTO_TEST_CASE(test_ctor_no_params) {
    no o;
    BOOST_CHECK_EQUAL(o.a(), 1);
}

namespace {
    struct single {
        single() : m(1) {}
        ~single() {}

        int a() const { return m->a; }

        struct impl {
            int a;
            impl(int a) : a(a) {}
        };
        yapimpl::shared<impl> m;
    };
}

BOOST_AUTO_TEST_CASE(test_ctor_single_params) {
    single o;
    BOOST_CHECK_EQUAL(o.a(), 1);
}

namespace {
    struct many {
        many() : m(1, 2, 3) {}
        ~many() {}

        int a() const { return m->a; }
        int b() const { return m->b; }
        int c() const { return m->c; }

        struct impl {
            int a, b, c;
            impl(int a, int b, int c) : a(a), b(b), c(c) {}
        };
        yapimpl::shared<impl> m;
    };
}

BOOST_AUTO_TEST_CASE(test_ctor_many_params) {
    many o;
    BOOST_CHECK_EQUAL(o.a(), 1);
    BOOST_CHECK_EQUAL(o.b(), 2);
    BOOST_CHECK_EQUAL(o.c(), 3);
}
