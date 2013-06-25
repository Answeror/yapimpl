#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __0A5AC748_BE03_4148_B706_A09E0E7F7FC5__
#define __0A5AC748_BE03_4148_B706_A09E0E7F7FC5__

#include <boost/shared_ptr.hpp>

#include "use_default_ctor.hpp"
#include "delay_method.hpp"
#include "access_fwd.hpp"

namespace yapimpl
{
    /**
     * @brief Use boost::shared_ptr to hold data.
     *
     * @tparam Impl
     */
    template<class Impl>
    class shared
    {
    private:
        typedef shared this_type;

    public:
        template<class T>
        shared(const shared<T> &other);

        template<class Dummy>
        shared(detail::use_default_ctor<Dummy>);

        template<class A1>
#define restrict_to(x) typename std::enable_if<x>::type *dummy = 0
        shared(A1 &&a1, restrict_to((std::is_convertible<A1, Impl>::value)));
#undef restrict_to

        template<class A1, class A2>
        shared(A1 &&a1, A2 &&a2);

        ~shared();

    public:
        const Impl* operator->() const;

        Impl* operator->();

        template<class Host>
        const typename detail::delay_method<Impl, Host>::type*
            operator ()(const Host *host) const;

        template<class Host>
        typename detail::delay_method<Impl, Host>::type*
            operator ()(Host *host);

        void reset(Impl *impl);

        this_type clone() const;

        bool last() const;

    private:
        template<class> friend class shared;
        std::shared_ptr<Impl> m;
    };
}

#endif // __0A5AC748_BE03_4148_B706_A09E0E7F7FC5__
