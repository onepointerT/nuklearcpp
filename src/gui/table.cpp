// Copyright (C) 2025 The OnePointer Authors
//

#include "table.hpp"

#include <cstddef>
#include <cstring>

namespace nuklear {


unsigned int Table::seq_now = 0;


Table::Table( const unsigned int tsize, Table* next_table, Table* prev_table )
    :   table{ .seq = ++Table::seq_now, .size = tsize
             , .keys = new[NK_VALUE_PAGE_CAPACITY] nk_hash
             , .values = new[NK_VALUE_PAGE_CAPACITY] nk_uint
             , .next = next_table, .prev = prev_table }
    ,   next( next_table )
    ,   prev( prev_table )
{}

Table::operator struct nk_table*() const {
    return &this->table;
}


Table::nk_value_pair Table::operator()( const unsigned int pos ) const {
    if ( pos >= this->table->size ) return { "", 0 };
    return { this->table->keys[pos], this->table->values[pos] };
}


nk_uint Table::operator[]( const nk_hash key ) {
    for ( unsigned int p = 0; p < this->table->size; p++ ) {
        if ( strcmp( this->table->keys[p], nk_key )
            return this->table->values[p];
    }
    return 0;
}


} // namespace nuklear