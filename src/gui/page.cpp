// Copyright (C) 2025 The OnePointer Authors
//

#include "panel.hpp"

namespace nuklear {


Panel::Panel( Context& ctx, panel_type ptype
            , Panel* parent, struct nk_command_buffer* cmdbuf
)   :   panel( *static_cast<struct nk_panel*>(ctx) )
{
    this->panel.type = ptype;
    this->panel.buffer = cmdbuf;
    this->panel.parent = parent;
}


Panel::operator nk_panel*() const {
    return &this->panel;
}


} // namespace nuklear