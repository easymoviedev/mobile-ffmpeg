#include "libavutil/log.h"


void mobileffmpeg_log_callback_function(void *ptr, int level, const char* format, va_list vargs){
    av_log_default_callback(ptr, level, format, vargs);
}
