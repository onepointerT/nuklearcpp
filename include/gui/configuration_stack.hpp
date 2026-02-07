// Copyright (C) 2025 The OnePointer Authors
//

#pragma once

extern "C" {
#include <nuklear.h>
}




namespace nuklear {


class ConfigurationStack
    :   public nk_configuration_stacks
{
public:
    ConfigurationStack();
};


} // namespace nuklear