cmake_minimum_required(VERSION 3.9)

project("ffmpeg_linux"
        LANGUAGES C CXX)

set(FFMPEG_FFTOOLS "../../../android/app/src/main/cpp")
set(FFMPEG_SRC "${PROJECT_SOURCE_DIR}/..")
set(LIB_NAME "mobileffmpeg")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(
        ${LIB_NAME}
        SHARED
        "${FFMPEG_FFTOOLS}/fftools_ffmpeg.c"
        ffmpeg_linux.c
        "${FFMPEG_FFTOOLS}/fftools_ffmpeg_filter.c"
        "${FFMPEG_FFTOOLS}/fftools_ffmpeg_hw.c"
        "${FFMPEG_FFTOOLS}/fftools_cmdutils.c"
        "${FFMPEG_FFTOOLS}/fftools_ffprobe.c"
        "${FFMPEG_FFTOOLS}/fftools_ffmpeg_opt.c"
        "${FFMPEG_FFTOOLS}/mobileffmpeg_exception.c"

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

if (APPLE)
    set(VIDEOTOOLBOX_FMWK "-framework VideoToolbox")
endif()

target_link_libraries(${LIB_NAME}
        avdevice
        avfilter
        avformat
        swresample
        swscale
        avcodec
        avutil
        ${VIDEOTOOLBOX_FMWK}
        pthread
        m
        z)

install(TARGETS ${LIB_NAME})
install(FILES ffmpeg_cli.h DESTINATION include)
