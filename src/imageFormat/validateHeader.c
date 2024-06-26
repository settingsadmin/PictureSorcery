#include "validateHeader.h"


#include "../common/fileRead.h"
#include "../common/string_wrapper.h"/*memcmp*/


________validateHeader_func_decl
{
    return
        file->isOpen
        &&
        (fileRead(fileContentBuffer, file, headerByteCount) == headerByteCount)
        &&
        (memcmp(expectedHeader, fileContents, headerByteCount) == ____MEMCMP_SUCCESS)
    ;
}
