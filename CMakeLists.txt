cmake_minimum_required(VERSION 2.8)
project(OpenCV-Experiments)
find_package(OpenCV REQUIRED)

SET(RASPICAM_CV $ENV{HOME}/dev/robidouille/raspicam_cv)
SET(USERLAND $ENV{HOME}/dev/userland)
#SET(RASPICAM ${USERLAND}/host_applications/linux/apps/raspicam)
#include_directories(/opt/vc/include)
#include_directories(/opt/vc/include/interface/vcos/pthreads)
#include_directories(/opt/vc/include/interface/vmcs_host/linux)
#include_directories(${RASPICAM})
#include_directories(${USERLAND})
include_directories(${RASPICAM_CV})

SET(MMAL_LIBS
    ${USERLAND}/build/lib/libmmal_core.so
    ${USERLAND}/build/lib/libmmal_util.so
    ${USERLAND}/build/lib/libmmal_vc_client.so
    ${USERLAND}/build/lib/libvcos.so)
SET(BCM_LIBS ${USERLAND}/build/lib/libbcm_host.so)
SET(GLES_LIBS ${USERLAND}/build/lib/libGLESv2.so)
SET(EGL_LIBS ${USERLAND}/build/lib/libEGL.so)
SET(DISPLAY_CAMERA_LIBS
    ${RASPICAM_CV}/libraspicamcv.a
    ${MMAL_LIBS} ${BCM_LIBS} ${OpenCV_LIBS})

SET(DISPLAY_IMAGE build/display-image)
SET(DISPLAY_VIDEO build/display-video)
SET(DISPLAY_CAMERA build/display-camera)
add_executable(${DISPLAY_IMAGE} src/display-image.cpp)
add_executable(${DISPLAY_VIDEO} src/display-video.cpp)
add_executable(${DISPLAY_CAMERA} src/display-camera.cpp)
target_link_libraries(${DISPLAY_IMAGE} ${OpenCV_LIBS})
target_link_libraries(${DISPLAY_VIDEO} ${OpenCV_LIBS})
target_link_libraries(${DISPLAY_CAMERA} ${DISPLAY_CAMERA_LIBS})
