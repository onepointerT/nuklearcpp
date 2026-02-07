// Copyright (C) 2025 The OnePointer Authors
//

#pragma once

extern "C" {
#include <nuklear.h>
}

#include "allocator.hpp"

namespace nuklear {


void* nk_buffer_alloc( nk_handle hndl, void* old, nk_size bufsize );
void nk_buffer_free( nk_handle hndl, void* old );


class BufferAllocator
    :   public Allocator
{
public:
    BufferAllocator( plugin_alloc_f bufalloc_f = &nk_buffer_alloc
                   , plugin_free_f buffree_f = &nk_buffer_free );
};


class Buffer
    :   public nk_buffer
{
public:
    Buffer( const nk_size bufsize = 4096
          , const enum nk_allocation_type alloc_type = NK_BUFFER_FIXED );


};


} // namespace nuklear