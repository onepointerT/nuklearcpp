// Copyright (C) 2025 The OnePointer Authors
//

#pragma once

extern "C" {
#include <nuklear.h>
}

#include "context.hpp"
#include "panel.hpp"
#include "table.hpp"

#include <set>
#include <string>


namespace nuklear {


class Window {
protected:

public:
    struct nk_window window;
    Panel& layout;
    std::set< Table* > tables;

    Window* next;
    Window* prev;
    Window* parent;

    Window( const std::string name
          , const Context& ctx
          , Window* parent = nullptr
          , struct nk_command_buffer* cmdbuf = nullptr
    );

    operator struct nk_panel*() const;
    operator struct nk_window*() const;
    operator std::string() const;
};


} // namespace nuklear