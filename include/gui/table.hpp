// Copyright (C) 2025 The OnePointer Authors
//

#pragma once

extern "C" {
#include <nuklear.h>
}

#include <utility>


namespace nuklear {


class Table {
    static unsigned int seq_now;

public:
    struct nk_table table;

    struct nk_table* next;
    struct nk_table* prev;

    Table( const unsigned int tsize = NK_VALUE_PAGE_CAPACITY
         , Table* next_table = nullptr, Table* prev_table = nullptr );

    operator struct nk_table*() const;

    typedef typename std::pair< nk_hash, nk_uint > nk_value_pair;

    s;
    nk_uint operator[]( const nk_hash key );
};


} // namespace nuklear