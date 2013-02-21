#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __53493451_50DF_4613_B42C_9ED22B6D0D84__
#define __53493451_50DF_4613_B42C_9ED22B6D0D84__

namespace yapimpl
{
    namespace detail
    {
        /**
         * @brief Act as placeholder.
         *
         * @tparam Dummy Just to make this class dependent on template argument.
         */
        template<class Impl, class Dummy>
        struct delay_method
        {
            typedef typename Impl::method type;
        };
    }
}

#endif // __53493451_50DF_4613_B42C_9ED22B6D0D84__
