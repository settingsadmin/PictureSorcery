#if !defined(_INCLUDE_fileOpen_h)
#define _INCLUDE_fileOpen_h


#include "file_t.h"


#define ________fileOpen_func_decl  \
    void                            \
    fileOpen                        \
    (                               \
        file_t      *   dst,        \
        char        *   path,       \
        file_mode_t     mode,       \

    )


________fileOpen_func_decl;


#endif
