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

#include "use_default_ctor.hpp"
#include "delay_method.hpp"
#include "access_fwd.hpp"

namespace yapimpl
{
    /**
     * @brief Use std::unique_ptr to hold data.
     *
     * @tparam Impl
     */
    template<class Impl>
    class unique
    {
    private:
        typedef unique this_type;

    public:
        template<class T>
        unique(const unique<T> &other);

        unique(this_type &&other);

        template<class Dummy>
        unique(detail::use_default_ctor<Dummy>);

        template<class A1>
        unique(A1 &&a1);

        template<class A1, class A2>
        unique(A1 &&a1, A2 &&a2);

        ~unique();

    public:
        const Impl* operator->() const;

        Impl* operator->();

        template<class Host>
        const typename detail::delay_method<Impl, Host>::type*
            operator ()(const Host *host) const;

        template<class Host>
        typename detail::delay_method<Impl, Host>::type*
            operator ()(Host *host);

        bool empty() const;

    private:
        template<class> friend class unique;
        std::unique_ptr<Impl> m;
    };
}

#endif // __BC00CC76_1F1B_4BAB_84BF_84A7A2723818__
