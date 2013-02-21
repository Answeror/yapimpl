#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __7734171C_79F0_40CB_BE73_1B7F6027A782__
#define __7734171C_79F0_40CB_BE73_1B7F6027A782__

namespace yapimpl
{
    namespace detail
    {
        /**
         * @brief Act as placeholder.
         *
         * @tparam Dummy Just to make this class dependent on template argument.
         */
        template<class Dummy>
        struct use_default_ctor {};
    }

    namespace
    {
        const detail::use_default_ctor<void> use_default_ctor;
    }
}

#endif // __7734171C_79F0_40CB_BE73_1B7F6027A782__
