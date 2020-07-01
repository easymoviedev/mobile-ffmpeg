cmake_minimum_required(VERSION 3.9)

project("ffmpeg_linux"
        LANGUAGES C CXX)

set(FFMPEG_FFTOOLS "${PROJECT_SOURCE_DIR}/../fftools")
set(FFMPEG_SRC "${PROJECT_SOURCE_DIR}/..")
set(LIB_NAME "ffmpeg")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(${FFMPEG_BUILD} ${FFMPEG_SRC} ${FFMPEG_FFTOOLS})
link_directories(
        "${FFMPEG_BUILD}/libavformat"
        "${FFMPEG_BUILD}/libavutil"
        "${FFMPEG_BUILD}/libavcodec"
        "${FFMPEG_BUILD}/libswscale"
        "${FFMPEG_BUILD}/libswresample"
        "${FFMPEG_BUILD}/libavdevice"
        "${FFMPEG_BUILD}/libavfilter"
)

add_library(
        ${LIB_NAME}
        SHARED
        ffmpeg_linux.c
        "${FFMPEG_FFTOOLS}/ffmpeg_filter.c"
        "${FFMPEG_FFTOOLS}/ffmpeg_hw.c"
        "${FFMPEG_FFTOOLS}/ffmpeg_opt.c"
        "${FFMPEG_FFTOOLS}/ffmpeg_cuvid.c"
        "${FFMPEG_FFTOOLS}/cmdutils.c"
)

target_link_libraries(${LIB_NAME}
        avdevice
        avfilter
        avformat
        swresample
        swscale
        avcodec
        avutil
        pthread
        va-drm
        va
        va-x11
        xcb
        Xv
        va
        vdpau
        X11
        m
        z
        Xext)

install(TARGETS ${LIB_NAME})
