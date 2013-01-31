#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __E46B9F27_CB1C_4D98_8FE7_8CD296297367__
#define __E46B9F27_CB1C_4D98_8FE7_8CD296297367__

#include <yapimpl/include/shared_impl.hpp>
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

void someclass::set(int x)
{
    m->x = x;
}

#endif // __E46B9F27_CB1C_4D98_8FE7_8CD296297367__
