#include "fileOpen.h"


#include "stdio_wrapper.h"


________fileOpen_func_decl
{
    if(dst == NULL)
    {
        return;
    }

    uint8_t stdio_fopen_attempt_counter = 0, stdio_fopen_attempt_count_max = 5;
    char stdio_fopen_mode_str[4];

    /*"normal" modes*/
    if(dst->isOpen)
    {
        dst->status = file_status_failure_alreadyOpen;
        return;
    }

    if(dst->mode == file_mode_read)
    {
        stdio_fopen_mode_str = "r";
    }
    else
    if(dst->mode == file_mode_write)
    {
        stdio_fopen_mode_str = "w";
    }
    else
    if(dst->mode == file_mode_append)
    {
        stdio_fopen_mode_str = "a";
    }
    else
    if(dst->mode == file_mode_read_write)
    {
        stdio_fopen_mode_str = "r+";
    }
    else
    if(dst->mode == file_mode_read_append)
    {
        stdio_fopen_mode_str = "a+";
    }
    else

    /*binary modes*/
    if(dst->mode == file_mode_read_binary_binary)
    {
        stdio_fopen_mode_str = "rb";
    }
    else
    if(dst->mode == file_mode_write_binary)
    {
        stdio_fopen_mode_str = "wb";
    }
    else
    if(dst->mode == file_mode_append_binary)
    {
        stdio_fopen_mode_str = "ab";
    }
    else
    if(dst->mode == file_mode_read_write_binary)
    {
        stdio_fopen_mode_str = "rb+";
    }
    else
    if(dst->mode == file_mode_read_append_binary)
    {
        stdio_fopen_mode_str = "ab+";
    }
    else

    {
        dst->status = file_status_invalidMode;
        return;
    }

    _label_fopen:
    dst->stdio_file = fopen(path, stdio_fopen_mode_str);

    if(dst->stdio_file != NULL)
    {
        dst->isOpen = true;
        return;
    }

    if(stdio_fopen_attempt_counter < (stdio_fopen_attempt_count_max - 1))
    {
        stdio_fopen_attempt_counter++;
        goto _label_fopen;
    }

    dst->status = file_status_failure_stdioFopen;
    return;
}
