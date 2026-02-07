// Copyright (C) 2025 The OnePointer Authors
//

#pragma once

extern "C" {
#include <nuklear.h>
}

#include "allocator.hpp"
#include "page.hpp"

#include <set>


namespace nuklear {

void* nk_pool_alloc( nk_handle hndl, void* old, nk_size bufsize );
void nk_pool_free( nk_handle hndl, void* old );


class PoolAllocator
    :   public Allocator
{
public:
    PoolAllocator();
};


class Pool {
public:
    struct nk_pool pool;

    std::set< Page* > pages;
    std::set< PageElement* > page_elements;

    Pool( nk_allocation_type alloc_type = NK_BUFFER_DYNAMIC
        , PoolAllocator& alloc = *new PoolAllocator() );
    
    operator struct nk_pool*() const;
    
    Page* operator[]( const unsigned int pos ) const;
    PageElement* operator()( const unsigned int pos ) const;
};


} // namespace nuklear