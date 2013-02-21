#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __D45F06A0_B74D_4626_BCD6_7E2D1E63CF11__
#define __D45F06A0_B74D_4626_BCD6_7E2D1E63CF11__

#include <boost/type_traits/remove_cv.hpp>
#include <boost/type_traits/remove_pointer.hpp>
#include <boost/type_traits/remove_reference.hpp>

namespace yapimpl
{
    namespace detail
    {
        template<class T>
        struct remove_all
        {
            typedef typename boost::remove_cv<
                typename boost::remove_pointer<
                    typename boost::remove_cv<
                        typename boost::remove_reference<T>::type
                    >::type
                >::type
            >::type type;
        };
    }
}

#endif // __D45F06A0_B74D_4626_BCD6_7E2D1E63CF11__
