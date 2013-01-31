#ifdef _MSC_VER
    #pragma once
#endif
#ifndef __0C19F3D2_D706_49B4_8B2E_403177D3246D__
#define __0C19F3D2_D706_49B4_8B2E_403177D3246D__

#include <yapimpl/include/shared.hpp>

class someclass
{
public:
    someclass();
    ~someclass();

public:
    int neg() const;
    void set(int x);

private:
    struct impl;
    yapimpl::shared<impl> m;
};

#endif // __0C19F3D2_D706_49B4_8B2E_403177D3246D__
