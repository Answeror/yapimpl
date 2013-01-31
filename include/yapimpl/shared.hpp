#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __0A5AC748_BE03_4148_B706_A09E0E7F7FC5__
#define __0A5AC748_BE03_4148_B706_A09E0E7F7FC5__

#include <boost/shared_ptr.hpp>

namespace yapimpl
{
    /**
     * @brief Use boost::shared_ptr to hold data.
     *
     * @tparam Impl
     */
    template<class Impl>
    class shared;

    namespace detail
    {
        /**
         * @brief Act as placeholder.
         *
         * @tparam Dummy Just to make this class dependent on template argument.
         */
        template<class Dummy>
        struct use_default_ctor {};

        template<class Impl, class Dummy>
        struct delay_method
        {
            typedef typename Impl::method type;
        };
    }

    typedef detail::use_default_ctor<void> use_default_ctor;

    template<class Impl>
    class shared
    {
    protected:
        typedef Impl impl;

    private:
        typedef shared this_type;

    public:
        template<class Dummy>
        shared(detail::use_default_ctor<Dummy>);

        template<class A1>
        shared(A1 &&a1);

        template<class A1, class A2>
        shared(A1 &&a1, A2 &&a2);

        ~shared();

    public:
        const impl* operator->() const;

        impl* operator->();

        template<class Host>
        const typename detail::delay_method<impl, Host>::type*
            operator ()(const Host *host) const;

        template<class Host>
        typename detail::delay_method<impl, Host>::type*
            operator ()(Host *host);

    private:
        std::shared_ptr<impl> m;
    };
}

#endif // __0A5AC748_BE03_4148_B706_A09E0E7F7FC5__
