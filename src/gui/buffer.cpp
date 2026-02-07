// Copyright (C) 2025 The OnePointer Authors
//

#include "buffer.hpp"

extern "C" {
#include "nuklear_internal.h"
}

namespace nuklear {


void* nk_buffer_alloc( nk_handle hndl, void* old, nk_size bufsize ) {
    return nk_malloc( hndl, old, bufsize );
}

void nk_buffer_free( nk_handle hndl, void* old ) {
    nk_mfree( hndl, old );
}


Buffer::Buffer( const enum nk_allocation_type alloc_type )
    :   nk_buffer({ .marker = nk_buffer_marker{ .active = 1, .offset = 0 }
                 , .pool = nk_allocator
        })
{}


} // namespace nuklear