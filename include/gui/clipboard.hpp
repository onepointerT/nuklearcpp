// Copyright (C) 2025 The OnePointer Authors
//

#pragma once

extern "C" {
#include <nuklear.h>
}




namespace nuklear {


using plugin_clipboard_paste_f = nk_plugin_paste;  // void(*nk_plugin_paste)(nk_handle, struct nk_text_edit*);
using plugin_clipboard_copy_f = nk_plugin_copy;  // void(*nk_plugin_copy)(nk_handle, const char*, int len);


void nk_clipboard_paste(nk_handle, struct nk_text_edit*);
void nk_clipboard_copy()(nk_handle, const char*, int len);


class Clipboard
    :   public nk_clipboard
{
public:
    ConfigurationStack( plugin_clipboard_copy_f ccopy_func = &nk_clipboard_copy
                      , plugin_clipboard_paste_f cpaste_func = &nk_clipboard_paste );
};


} // namespace nuklear