#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __CEC1F7E5_FDA8_49A8_9783_5A9BB2077B55__
#define __CEC1F7E5_FDA8_49A8_9783_5A9BB2077B55__

#include "host_traits.hpp"
#include "cast.hpp"
#include "remove_all.hpp"

namespace yapimpl
{
    namespace outside_detail
    {
        // template declaration will be instantated first, 
        // so impl with pointer ot const will not pass
        template<class Host>
        struct method
        {
            typedef typename host_traits::method<
                typename detail::remove_all<Host>::type
            >::type type;
        };

        template<class Host>
        typename method<Host>::type* mp(Host *host)
        {
            return cast<typename host_traits::impl<Host>::type>(host);
        }

        template<class Host>
        const typename method<Host>::type* mpc(const Host *host)
        {
            return cast<typename host_traits::impl<Host>::type>(host);
        }
    }

    template<class Host>
    const typename outside_detail::method<Host>::type* m(const Host *host)
    {
        return outside_detail::mpc(host);
    }

    template<class Host>
    typename outside_detail::method<Host>::type* m(Host *host)
    {
        return outside_detail::mp(host);
    }

    template<class Host>
    const typename outside_detail::method<Host>::type& m(const Host &host)
    {
        return *outside_detail::mpc(&host);
    }

    template<class Host>
    typename outside_detail::method<Host>::type& m(Host &host)
    {
        return *outside_detail::mp(&host);
    }
}

#endif // __CEC1F7E5_FDA8_49A8_9783_5A9BB2077B55__
