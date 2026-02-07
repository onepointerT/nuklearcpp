// Copyright (C) 2025 The OnePointer Authors
//

#pragma once

extern "C" {
#include <nuklear.h>
}

#include "buffer.hpp"


namespace nuklear {


class CommandBuffer
    :   public nk_command_buffer
{
public:
    CommandBuffer( Buffer* buf = nullptr );
};


} // namespace nuklear