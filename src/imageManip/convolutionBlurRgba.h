#if !defined(_INCLUDE_convolutionBlurRgba_h)
#define _INCLUDE_convolutionBlurRgba_h


#include "../imageData/pxRgbaVec2_type.h"
#include "convolutionBlur_status_type.h"


#include <stdint.h>


enum convolutionBlurRadiusShape_t {
    convolutionBlurRadiusShape_rectangular,
    convolutionBlurRadiusShape_circular
};


#define ________convolutionBlurRgba_func_decl   \
    convolutionBlur_status_t                    \
    convolutionBlurRgba                         \
    {                                           \
        struct  pxRgbaVec2_t        src,        \
        struct  pxRgbaVec2_t    *   dst,        \
                double              radius      \
        enum    convolutionBlurRadiusShape_t        \
                                    radiusShape     \
    }


________convolutionBlurRgba_func_decl;


#endif
