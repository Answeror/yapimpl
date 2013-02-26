#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __E46B9F27_CB1C_4D98_8FE7_8CD296297367__
#define __E46B9F27_CB1C_4D98_8FE7_8CD296297367__

#include <yapimpl/include/shared_impl.hpp>
#include <yapimpl/include/outside.hpp>

#include "someclass.hpp"

struct someclass::impl
{
    int x;

    impl(int x) : x(x) {}

    struct method : someclass
    {
        int neg(int x) const
        {
            return -x;
        }

        void _set(int x)
        {
            m->x = x;
        }
    };
};

someclass::someclass() : m(42)
{
}

someclass::~someclass()
{
}

int someclass::neg() const
{
    return m(this)->neg(m->x);
}

int someclass::outside_neg() const
{
    return yapimpl::m(*this).neg(m->x);
}

void someclass::set(int x)
{
    // test nonconst method
    m(this)->_set(x);
}

void someclass::outside_set(int x)
{
    // test nonconst method
    yapimpl::m(*this)._set(x);
}

someclass someclass::clone() const
{
    someclass res;
    res.m = m.clone();
    return res;
}

#endif // __E46B9F27_CB1C_4D98_8FE7_8CD296297367__
