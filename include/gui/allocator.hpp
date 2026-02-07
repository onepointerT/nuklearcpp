// Copyright (C) 2025 The OnePointer Authors
//

#pragma once

extern "C" {
#define NK_INCLUDE_DEFAULT_ALLOCATOR 1
#include <nuklear.h>
}

namespace nuklear {


class Handle {
    static int id_now;

public:
    nk_handle handle;

    Handle();

    operator void*() const;
    operator int() const;
    operator nk_handle() const;
};


using allocation_type = nk_allocation_type;
using plugin_alloc_f = nk_plugin_alloc;  // void*(*nk_plugin_alloc)(nk_handle, void *old, nk_size);
using plugin_free_f = nk_plugin_free;  // void (*nk_plugin_free)(nk_handle, void *old);


class Allocator {
public:
    Handle& h;
    plugin_alloc_f alloc_plugin;
    plugin_free_f free_plugin;

    Allocator();

    virtual void* alloc( void* old, nk_size size );
    virtual void free( void* old );

    operator struct nk_allocator*() const;
};

} // namespace nuklear