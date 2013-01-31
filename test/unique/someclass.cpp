#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __771EACD4_9A04_41CC_910F_F80CF839EB21__
#define __771EACD4_9A04_41CC_910F_F80CF839EB21__

/**
 * @file someclass.cpp
 * @brief 
 * @author answeror <answeror@gmail.com>
 * @version 
 * @date 2013-01-26
 */

#include <yapimpl/include/unique_impl.hpp>
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

int someclass::foo() const
{
    return m(this)->neg(m->x);
}

#endif // __771EACD4_9A04_41CC_910F_F80CF839EB21__
