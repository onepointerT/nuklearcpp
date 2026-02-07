// Copyright (C) 2025 The OnePointer Authors
//

#include "window.hpp"

namespace nuklear {


Window::Window( const std::string name
              , Context& ctx
              , Window* parent
              , struct nk_command_buffer* cmdbuf
)   :   window( *static_cast<struct nk_window*>(nk_create_window(ctx)) )
    ,   layout( *new Panel() )
    ,   tables()
    ,   next( nullptr )
    ,   prev( nullptr )
    ,   parent( parent )
{
    this->window.buffer = *cmdbuf;
}

Window::operator nk_panel*() const {
    return this->layout;
}

Window::operator nk_window*() const {
    return &this->window;
}

Window::operator std::string() const {
    return this->window.name_string;
}


} // namespace nuklear