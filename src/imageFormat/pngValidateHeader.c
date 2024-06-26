#include "pngValidateHeader.h"


#include "validateHeader.h"


#include <stdint.h>


#define ________png_header_byte_count 8


________pngValidateHeader_func_decl
{
    uint8_t expectedHeader[________png_header_byte_count] = 
    {
        0x89, 0x50, 0x4e, 0x47, 
        0x0d, 0x0a, 0x1a, 0x0a
    };

    uint8_t fileContents[________png_header_byte_count];

    return validateHeader(expectedHeader, ________png_header_byte_count, file, fileContents);
}
