// Copyright (C) 2025 The OnePointer Authors
//

#pragma once

extern "C" {
#include <nuklear.h>
}

#include <string>
#include <utility>


namespace nuklear {


class Input
    :   public nk_input
{
protected:


public:
    typedef typename enum nk_buttons mouse_buttons_t;
    typedef typename enum nk_keys keyboard_keys_t;

    Input();

    typedef typename std::pair< struct nk_vec2*, Input::mouse_buttons_t > mouse_click_t;
    typedef typename std::pair< struct nk_rect*, Input::mouse_buttons_t > mouse_position_t;

    bool mouse_button_down( const mouse_buttons_t mbuttons ) const;
    bool mouse_button_released( const mouse_buttons_t mbuttons ) const;
    mouse_click_t mouse_clicked( const mouse_buttons_t mbuttons ) const;
    mouse_position_t mouse_clicked_in_rect( const struct nk_rect mpos ) const;

    bool keyboard_key_down( const keyboard_keys_t kkey ) const;
    bool keyboard_key_released( const keyboard_keys_t kkey ) const;
    std::pair< std::string, int > keyboard_text() const;
};


} // namespace nuklear