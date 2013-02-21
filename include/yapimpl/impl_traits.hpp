#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __5666F628_F1B4_4B5F_B6AB_1F054C79C25A__
#define __5666F628_F1B4_4B5F_B6AB_1F054C79C25A__

namespace yapimpl
{
    namespace impl_traits
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
}

#endif // __5666F628_F1B4_4B5F_B6AB_1F054C79C25A__
