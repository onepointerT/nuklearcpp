// Copyright (C) 2025 The OnePointer Authors
//

#pragma once

extern "C" {
#include <nuklear.h>
}

#include "buffer.hpp"
#include "clipboard.hpp"
#include "command_buffer.hpp"
#include "configuration_stack.hpp"
#include "font.hpp"
#include "input.hpp"
#include "page.hpp"
#include "pool.hpp"
#include "style.hpp"
#include "window.hpp"

#include <set>


namespace nuklear {


class Context {
protected:
    Buffer& buffer;
    CommandBuffer& commandBuffer;
    ConfigurationStack& configStack;

public:
    struct nk_context ctx;

    Clipboard& clipboard;
    Font& font;
    Font::Atlas& fontAtlas;
    FontConfig& fontConfig;
    Input& input;
    Pool& pool;
    Style& style;
    Window* win_active;
    Window& win_current;

    Context( plugin_clipboard_copy_f ccopy_func = &nk_clipboard_copy
           , plugin_clipboard_paste_f cpaste_func = &nk_clipboard_paste
           , const nk_button_behavior bbehavior = NK_BUTTON_DEFAULT );

    CommandBuffer& cmd() const;

    operator struct nk_context*() const;
};


} // namespace nuklear