#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __C52B9B1E_C6A3_46D5_A3A6_4C1FE0970E17__
#define __C52B9B1E_C6A3_46D5_A3A6_4C1FE0970E17__

namespace yapimpl
{
    template<class Host>
    class access
    {
    public:
        typedef typename Host::impl impl;
    };
}

#endif // __C52B9B1E_C6A3_46D5_A3A6_4C1FE0970E17__
