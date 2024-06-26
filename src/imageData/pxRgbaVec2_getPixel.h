#if !defined(_INCLUDE_pxRgbaVec2_getPixel_h)
#define _INCLUDE_pxRgbaVec2_getPixel_h


/*this function foregoes bounds checking, in favor of speed*/


#include "pxRgba_type.h"
#include "pxRgbaVec2_type.h"
#include "pxVecSize_type.h"
#include "../common/func_decl.h"


#define ________pxRgbaVec2_getPixel_func_decl   \
    _ALWIN                                      \
    struct pxRgba_t                             \
    pxRgbaVec2_getPixel                         \
    (                                           \
        struct  pxRgbaVec2_t    vector          \
                pxVecW_t        x               \
                pxVecH_t        y               \
    )


________rgbaVec2_getPixel_func_decl;


#endif
