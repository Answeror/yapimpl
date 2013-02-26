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
    int outside_neg() const;
    void set(int x);
    void outside_set(int x);
    someclass clone() const;

private:
    friend class yapimpl::access<someclass>;
    struct impl;
    yapimpl::shared<impl> m;
};

#endif // __0C19F3D2_D706_49B4_8B2E_403177D3246D__
