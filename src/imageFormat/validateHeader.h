#if !defined(_INCLUDE_validateHeader_h)
#define _INCLUDE_validateHeader_h


#include "../common/file_type.h"


#include <stdint.h>
#include <stdbool.h>


#define ________validateHeader_func_decl            \
    bool                                            \
    validateHeader                                  \
    {                                               \
        uint8_t         *   expectedHeader,         \
        uint8_t             headerByteCount,        \
        struct file_t       file,                   \
        void            *   fileContentBuffer       \
    }


________validateHeader_func_decl;


#endif
