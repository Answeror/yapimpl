#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __A4E0896F_A48A_421E_8DB8_E7C015C7B756__
#define __A4E0896F_A48A_421E_8DB8_E7C015C7B756__

#include "impl_traits.hpp"
#include "access.hpp"

namespace yapimpl
{
    namespace host_traits
    {
        template<class Host>
        struct impl
        {
            typedef typename access<Host>::impl type;
        };

        template<class Host>
        struct method
        {
            typedef typename impl_traits::method<
                typename impl<Host>::type
            >::type type;
        };
    }
}

#endif // __A4E0896F_A48A_421E_8DB8_E7C015C7B756__
