#if !defined(_INCLUDE_pngValidateHeader_h)
#define _INCLUDE_pngValidateHeader_h


#include "../common/file_type.h"


#include <stdbool.h>


#define ________pngValidateHeader_func_decl   \
    bool                                        \
    png_validate_header                         \
    (                                           \
        file_t file                             \
    )


________pngValidateHeader_func_decl;


#endif
