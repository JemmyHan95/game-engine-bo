#ifndef __D3DX12_H__
#define __D3DX12_H__

#include "d3d12.h"

#if defined(__cplusplus)

struct CD3DX12_DEFAULT {};
extern const DECLSPEC_SELECTANY CD3DX12_DEFAULT D3D12_DEFAULT;

inline bool operator==(const D3D12_VIEWPORT& l, const D3D12_VIEWPORT& r)
{
    return l.TopLeftX == r.TopLeftX && l.TopLeftY == r.TopLeftY && l.Width == r.Width && l.Height == r.Height && l.MinDepth == r.MinDepth && l.MaxDepth == r.MaxDepth;
}

inline bool operator != (const D3D12_VIEWPORT& l, const D3D12_VIEWPORT& r)
{
    return !(l == r);
}

struct CD3DX12_RECT : public D3D12_RECT
{
    CD3DX12_RECT()
    {}
    explicit CD3DX12_RECT(const D3D12_RECT& o) :
    D3D12_RECT( o )
    {}
    explicit CD3DX12_RECT(
        LONG Left,
        LONG Top,
        LONG Right,
        LONG Bottom
    )
    {
        left = Left;
        right = Right;
        top = Top;
        bottom = Bottom;
    }
    ~CD3DX12_RECT() {}
    operator const D3D12_RECT&() const { return *this; }
};

#endif // defined(__cplusplus)

#endif // __D3DX12_H__