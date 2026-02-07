// Copyright (C) 2025 The OnePointer Authors
//

#pragma once

extern "C" {
#define NK_INCLUDE_FONT_BAKING 1
#define NK_INCLUDE_STANDARD_IO 1
#include <nuklear.h>
}

#include "context.hpp"

#include <cstdint>
#include <stack>
#include <string>


namespace nuklear {


using FontConfig = struct nk_font_config;
inline FontConfig font_config;


class Font
    :   public nk_user_font
{
public:
    const std::string name;
    // struct nk_font font;

    Font( uint8_t height, uint8_t width, std::string filepath );
    Font( struct nk_font* font );

    //operator struct nk_font*() const;

    class Atlas
        :   public std::stack< struct nk_font* >
        ,   public nk_font_atlas
    {
    public:
        Atlas();
    };
};


} // namespace nuklear