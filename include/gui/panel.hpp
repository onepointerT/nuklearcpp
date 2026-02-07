// Copyright (C) 2025 The OnePointer Authors
//

#pragma once

extern "C" {
#include <nuklear.h>
}

#include "context.hpp"

namespace nuklear {


class Panel {
public:
    typedef enum nk_panel_type panel_type;

    struct nk_panel panel;

    Panel( Context& ctx
         , panel_type ptype = NK_PANEL_NONE
         , Panel* parent = nullptr
         , struct nk_command_buffer* cmdbuf = nullptr );

    operator struct nk_panel*() const;
};


} // namespace nuklear