// Copyright (C) 2025 The OnePointer Authors
//

#include "allocator.hpp"

namespace nuklear {


inline int Handle::id_now = 0;


Handle::Handle()
    :   handle{ .ptr: nullptr, .id = ++Handle::id_now }
{}

Handle::operator void*() const {
    return this->handle.ptr;
}

Handle::operator int() const {
    return this->handle.id;
}

Handle::operator nk_handle() const {
    return this->handle;
}


Allocator::Allocator()
    :   h( *new Handle() )
    ,   alloc_plugin( nullptr )
    ,   free_plugin( nullptr )
{}


void* Allocator::alloc( void* old, nk_size size ) {
    return this->alloc_plugin( this->h.handle, old, size );
}

void Allocator::free( void* old ) {
    return this->free_plugin( this->h.handle, old );
}

Allocator::operator nk_allocator*() const {
    return new nk_allocator{ .userdata = this->h
                           , .alloc = this->alloc_plugin
                           , .free = this->free_plugin };
}

} // namespace nuklear