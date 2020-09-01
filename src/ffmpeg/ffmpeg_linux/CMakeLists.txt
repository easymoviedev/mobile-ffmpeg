cmake_minimum_required(VERSION 3.9)

project("ffmpeg_linux"
        LANGUAGES C CXX)

set(FFMPEG_FFTOOLS "${PROJECT_SOURCE_DIR}/../fftools")
set(FFMPEG_SRC "${PROJECT_SOURCE_DIR}/..")
set(LIB_NAME "mobileffmpeg")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

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

target_include_directories(${LIB_NAME} PUBLIC ${FFMPEG_BUILD} ${FFMPEG_SRC} ${FFMPEG_FFTOOLS})
target_link_directories(${LIB_NAME} PUBLIC
        "${FFMPEG_BUILD}/libavformat"
        "${FFMPEG_BUILD}/libavutil"
        "${FFMPEG_BUILD}/libavcodec"
        "${FFMPEG_BUILD}/libswscale"
        "${FFMPEG_BUILD}/libswresample"
        "${FFMPEG_BUILD}/libavdevice"
        "${FFMPEG_BUILD}/libavfilter"
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
        m
        z)

install(TARGETS ${LIB_NAME})
install(FILES ffmpeg_cli.h DESTINATION include)
