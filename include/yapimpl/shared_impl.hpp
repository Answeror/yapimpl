#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __3EA2762B_2C55_4FE7_A670_694D2A9262E2__
#define __3EA2762B_2C55_4FE7_A670_694D2A9262E2__

#include <boost/assert.hpp>
#include <boost/implicit_cast.hpp>
#include <boost/type_traits/is_base_of.hpp>

#include "shared.hpp"

namespace yapimpl
{
    namespace traits
    {
        template<class Impl>
        struct impl
        {
            typedef Impl type;
        };

        template<class Impl>
        struct method
        {
            typedef typename Impl::method type;
        };
    }

    template<class Impl>
    template<class Dummy>
    shared<Impl>::shared(detail::use_default_ctor<Dummy>) :
        m(new impl()) {}

    template<class Impl>
    template<class A1>
    shared<Impl>::shared(A1 &&a1) :
        m(new impl(
            std::forward<A1>(a1)
            )) {}
 
    template<class Impl>
    template<class A1, class A2>
    shared<Impl>::shared(A1 &&a1, A2 &&a2) :
        m(new impl(
            std::forward<A1>(a1),
            std::forward<A2>(a2)
            )) {}
     
    template<class Impl>
    shared<Impl>::~shared() {}
     
    template<class Impl>
    inline typename const shared<Impl>::impl*
        shared<Impl>::operator->() const
    {
        return m.get();
    }

    template<class Impl>
    inline typename shared<Impl>::impl*
        shared<Impl>::operator->()
    {
        return m.get();
    }

    template<class Impl>
    template<class Host>
    const typename detail::delay_method<Impl, Host>::type*
        shared<Impl>::operator ()(const Host *host) const
    {
        typedef typename traits::method<Impl>::type method;
        static_assert(boost::is_base_of<Host, method>::value, "Method must derived from Host.");
        static_assert(sizeof(method) == sizeof(Host), "Method cannot have member variable.");
        BOOST_ASSERT(host);
        return static_cast<const method*>(host);
    }

    template<class Impl>
    template<class Host>
    typename detail::delay_method<Impl, Host>::type*
        shared<Impl>::operator ()(Host *host)
    {
        typedef typename traits::method<Impl>::type method;
        return const_cast<method*>(
            (*boost::implicit_cast<const shared<Impl>*>(this))(
                boost::implicit_cast<const Host*>(host)
            )
        );
    }
}

#endif // __3EA2762B_2C55_4FE7_A670_694D2A9262E2__
