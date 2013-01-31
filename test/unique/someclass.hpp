#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __E057EEF2_729B_4D1C_9C8A_405B3B184BC5__
#define __E057EEF2_729B_4D1C_9C8A_405B3B184BC5__

/**
 * @file someclass.hpp
 * @brief 
 * @author answeror <answeror@gmail.com>
 * @version 
 * @date 2013-01-26
 */

#include <yapimpl/include/unique.hpp>

class someclass
{
public:
    someclass();
    ~someclass();

public:
    int foo() const;

private:
    struct impl;
    yapimpl::unique<impl> m;
};

#endif // __E057EEF2_729B_4D1C_9C8A_405B3B184BC5__
