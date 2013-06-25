#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __3EA2762B_2C55_4FE7_A670_694D2A9262E2__
#define __3EA2762B_2C55_4FE7_A670_694D2A9262E2__

#include <boost/assert.hpp>
#include <boost/swap.hpp>
#include <boost/implicit_cast.hpp>
#include <boost/type_traits/is_base_of.hpp>

#include "shared.hpp"
#include "cast.hpp"

namespace yapimpl
{
    template<class Impl>
    template<class T>
    shared<Impl>::shared(const shared<T> &other) : m(other.m) {}

    template<class Impl>
    template<class Dummy>
    shared<Impl>::shared(detail::use_default_ctor<Dummy>) :
        m(new Impl()) {}

    template<class Impl>
    template<class A1>
#define restrict_to(x) typename std::enable_if<x>::type *dummy
    shared<Impl>::shared(A1 &&a1, restrict_to((std::is_convertible<A1, Impl>::value))) :
#undef restrict_to
        m(new Impl(
            std::forward<A1>(a1)
            )) {}
 
    template<class Impl>
    template<class A1, class A2>
    shared<Impl>::shared(A1 &&a1, A2 &&a2) :
        m(new Impl(
            std::forward<A1>(a1),
            std::forward<A2>(a2)
            )) {}

    template<class Impl>
    shared<Impl>::~shared() {}
     
    template<class Impl>
    inline const Impl*
        shared<Impl>::operator->() const
    {
        return m.get();
    }

    template<class Impl>
    inline Impl*
        shared<Impl>::operator->()
    {
        return m.get();
    }

    template<class Impl>
    template<class Host>
    const typename detail::delay_method<Impl, Host>::type*
        shared<Impl>::operator ()(const Host *host) const
    {
        return cast<Impl>(host);
    }

    template<class Impl>
    template<class Host>
    typename detail::delay_method<Impl, Host>::type*
        shared<Impl>::operator ()(Host *host)
    {
        return cast<Impl>(host);
    }

    template<class Impl>
    inline void shared<Impl>::reset(Impl *impl)
    {
        m.reset(impl);
    }

    template<class Impl>
    inline shared<Impl> shared<Impl>::clone() const
    {
        this_type res = *this;
        res.m.reset(new Impl(*m));
        return res;
    }

    template<class Impl>
    inline bool shared<Impl>::last() const
    {
        return m.use_count() == 1;
    }
}

#endif // __3EA2762B_2C55_4FE7_A670_694D2A9262E2__
