#if !defined(_INCLUDE_file_t_h)
#define _INCLUDE_file_t_h


#include "stdio_wrapper.h"
#include <stdbool.h>


enum file_status_t
{
    file_status_success,
    file_status_failure_generic,
    file_status_failure_alreadyOpen,
    file_status_failure_invalidMode,
    file_status_failure_stdioFopen,

    FILE_STATUS_COUNT
};


enum file_mode_t
{
    file_mode_null,

    file_mode_overwrite,
    file_mode_append,
    file_mode_read,

    file_mode_overwrite_read,
    file_mode_append_read,

    file_mode_overwrite_binary,
    file_mode_append_binary,
    file_mode_read_binary,

    file_mode_overwrite_read_binary,
    file_mode_append_read_binary,

    FILE_MODE_COUNT
};


struct file_t
{
            FILE            *   stdio_file;
            bool                isOpen;
    enum    file_mode_t         mode;
    enum    file_status_t       status;
}


#endif
