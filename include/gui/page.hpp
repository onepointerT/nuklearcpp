// Copyright (C) 2025 The OnePointer Authors
//

#pragma once

extern "C" {
#include <nuklear.h>
}

#include "panel.hpp"
#include "table.hpp"
#include "window.hpp"

namespace nuklear {


class PageData {
public:
    nk_page_data pdata;

    Table& tbl;
    Panel& pan;
    Window& win;

    PageData( Table* table = nullptr, Panel* panel = nullptr
            , Window* window = nullptr );

    operator nk_page_data() const;
};


class PageElement {
public:
    nk_page_element elem;

    PageData& data;

    PageElement* next;
    PageElement* prev;

    PageElement( PageData* pdata = nullptr
               , PageElement* next_elem = nullptr
               , PageElement* prev_elem = nullptr );
    PageElement( nk_page_element* next_elem, nk_page_element* prev_elem = nullptr );

    operator struct nk_page_element*() const;
};


class Page {
public:
    nk_page page;

    Page* next;

    Page( struct nk_page_element* windows, struct nk_page* = nullptr );

    operator struct nk_page*() const;
    operator struct nk_page_element*() const;
};


} // namespace nuklear