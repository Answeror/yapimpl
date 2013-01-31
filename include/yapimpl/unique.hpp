#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __BC00CC76_1F1B_4BAB_84BF_84A7A2723818__
#define __BC00CC76_1F1B_4BAB_84BF_84A7A2723818__

/**
 * @file unique.hpp
 * @brief Pimpl with unique storage sementics.
 * @author answeror <answeror@gmail.com>
 * @version 
 * @date 2013-01-26
 */

#include <memory> // unique_ptr

namespace yapimpl
{
    /**
     * @brief Use std::unique_ptr to hold data.
     *
     * @tparam Impl
     */
    template<class Impl>
    class unique;

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
    class unique
    {
    protected:
        typedef Impl impl;

    private:
        typedef unique this_type;

    public:
        template<class Dummy>
        unique(detail::use_default_ctor<Dummy>);

        template<class A1>
        unique(A1 &&a1);

        template<class A1, class A2>
        unique(A1 &&a1, A2 &&a2);

        ~unique();

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
        std::unique_ptr<impl> m;
    };
}

#endif // __BC00CC76_1F1B_4BAB_84BF_84A7A2723818__
