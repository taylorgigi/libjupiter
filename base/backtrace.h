//
// Created by taylor on 2020/8/24.
//

#ifndef JUPITER_BACKTRACE_H
#define JUPITER_BACKTRACE_H

namespace jupiter
{

#include <execinfo.h>

#define FRAME_BUFFER_SIZE 512

#define BACKTRACE() \
{\
        void *frame_buffer[FRAME_BUFFER_SIZE];\
        int sz = backtrace(frame_buffer, FRAME_BUFFER_SIZE);\
        char **frame_str = backtrace_symbols(frame_buffer, sz);\
        if(frame_str) {\
                for(int i = 0; i < sz; ++i) {\
                        printf("%s\n", frame_str[i]);\
                }\
        }\
}

} // namespace jupiter

#endif //JUPITER_BACKTRACE_H
