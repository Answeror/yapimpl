#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __4270441A_E070_4078_BB82_BD6021CC2952__
#define __4270441A_E070_4078_BB82_BD6021CC2952__

#include <type_traits>

#include "use_default_ctor.hpp"

namespace yapimpl { namespace traits {
    template<class T>
    struct is_default_ctor : std::is_same<
        typename std::decay<T>::type,
        detail::use_default_ctor<void>
    > {};
}}

#endif // __4270441A_E070_4078_BB82_BD6021CC2952__
