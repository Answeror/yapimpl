#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __DC55FBB5_EF51_4F43_896E_6CEAC923B6B1__
#define __DC55FBB5_EF51_4F43_896E_6CEAC923B6B1__

/**
 * @file unique_impl.hpp
 * @brief 
 * @author answeror <answeror@gmail.com>
 * @version 
 * @date 2013-01-26
 */

#include <boost/assert.hpp>
#include <boost/implicit_cast.hpp>
#include <boost/type_traits/is_base_of.hpp>

#include "unique.hpp"
#include "cast.hpp"

namespace yapimpl
{
    template<class Impl>
    template<class T>
    unique<Impl>::unique(const unique<T> &other) : m(other.m) {}

    template<class Impl>
    unique<Impl>::unique(this_type &&other) : m(std::move(other.m)) {}

    template<class Impl>
    template<class Dummy>
    unique<Impl>::unique(detail::use_default_ctor<Dummy>) :
        m(new Impl()) {}

    template<class Impl>
    template<class A1>
    unique<Impl>::unique(A1 &&a1) :
        m(new Impl(
            std::forward<A1>(a1)
            )) {}
 
    template<class Impl>
    template<class A1, class A2>
    unique<Impl>::unique(A1 &&a1, A2 &&a2) :
        m(new Impl(
            std::forward<A1>(a1),
            std::forward<A2>(a2)
            )) {}
     
    template<class Impl>
    unique<Impl>::~unique() {}
     
    template<class Impl>
    inline const Impl*
        unique<Impl>::operator->() const
    {
        return m.get();
    }

    template<class Impl>
    inline Impl*
        unique<Impl>::operator->()
    {
        return m.get();
    }

    template<class Impl>
    template<class Host>
    const typename detail::delay_method<Impl, Host>::type*
        unique<Impl>::operator ()(const Host *host) const
    {
        return cast<Impl>(host);
    }

    template<class Impl>
    template<class Host>
    typename detail::delay_method<Impl, Host>::type*
        unique<Impl>::operator ()(Host *host)
    {
        return cast<Impl>(host);
    }

    template<class Impl>
    inline bool unique<Impl>::empty() const
    {
        return bool(m);
    }
}

#endif // __DC55FBB5_EF51_4F43_896E_6CEAC923B6B1__
