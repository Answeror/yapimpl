#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __4CCE9819_EB63_478C_B8FA_73621C7DE34F__
#define __4CCE9819_EB63_478C_B8FA_73621C7DE34F__

#include "impl_traits.hpp"
#include "delay_method.hpp"

namespace yapimpl
{
    template<class Impl, class Host>
    inline const typename impl_traits::method<Impl>::type* cast(const Host *host)
    {
        typedef typename impl_traits::method<Impl>::type method;
        static_assert(boost::is_base_of<Host, method>::value, "Method must derived from Host.");
        static_assert(sizeof(method) == sizeof(Host), "Method cannot have member variable.");
        BOOST_ASSERT(host);
        return static_cast<const method*>(host);
    }

    template<class Impl, class Host>
    inline typename impl_traits::method<Impl>::type* cast(Host *host)
    {
        typedef typename impl_traits::method<Impl>::type method;
        return const_cast<method*>(cast<Impl>(boost::implicit_cast<const Host*>(host)));
    }
}

#endif // __4CCE9819_EB63_478C_B8FA_73621C7DE34F__
