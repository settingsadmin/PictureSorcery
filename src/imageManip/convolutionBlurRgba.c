#include "convolutionBlurRgba.h"


#include "convolutionBlur_status_type.h"
#include "../imageData/pxRgba_type.h"
#include "../imageData/pxRgbaVec2_type.h"


#include <malloc.h>
#include <math.h>


________convolutionBlurRgba_func_decl
{
    if(radius == 0){
        *dst = src;
        return convolutionBlur_status_success;
    }

    uint32_t radiusPxCount = radius * radius;
    uint8_t *radiusPxWeights = malloc(radiusPxCount);
    double radiusPxDistance;
    uint32_t radiusPxOffsetX, radiusPxOffsetY, radiusPxOffsetXAbs, radiusPxOffsetYAbs, 
        radiusPxOffsetXMax = radius, 
        radiusPxOffsetYMax = radius
    ;
    int32_t 
        radiusPxOffsetXMin = 0 - radius, 
        radiusPxOffsetYMin = 0 - radius
    ;

    radiusPxOffsetX = radiusPxOffsetXMin;
    radiusPxOffsetY = radiusPxOffsetYMin;

    if(radiusShape == convolutionBlurRadiusShape_rectangular){
    for(uint32_t radiusPxIndex; radiusPxIndex < (radiusPxCount - 1); radiusPxIndex++;)
        {
            radiusPxWeights[radiusPxIndex] = UINT8_MAX;
            
        }
        goto _weightsEnd;
    }

    if(radiusShape == convolutionBlurRadiusShape_circular)
    {
        for(uint32_t radiusPxIndex; radiusPxIndex < (radiusPxCount - 1); radiusPxIndex++;)
        {
            if(radiusPxOffsetX < radiusPxOffsetXMax)
            {
                radiusPxOffsetX++;
            }
            else
            {
                if(radiusPxOffsetY < radiusPxOffsetYMax)
                {
                    radiusPxOffsetY++;
                    radiusPxOffsetX = radiusPxOffsetXMin;
                }
                else
                {
                    /*should be unreachable*/
                }
            }

            radiusPxOffsetXAbs = abs(radiusPxOffsetX);
            radiusPxOffsetYAbs = abs(radiusPxOffsetY);
            radiusPxDistance = sqrt(radiusPxOffsetXAbs * radiusPxOffsetXAbs + radiusPxOffsetYAbs * radiusPxOffsetYAbs);

            if(radiusPxDistance > (radius + 1))
            {
                radiusPxWeights[radiusPxIndex] = UINT8_MIN;
            }
            else
            if(radiusPxDistance > radius)
            {
                radiusPxWeights[radiusPxIndex] = round(UINT8_MAX * (1 - (radiusPxDistance - radius)));
            }
            else
            {
                radiusPxWeights[radiusPxIndex] = UINT8_MAX;
            }
        }
        goto _weightsEnd;
    }

    _weightsEnd:


    return convolutionBlur_status_success;
}
