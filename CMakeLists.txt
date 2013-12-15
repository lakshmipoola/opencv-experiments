cmake_minimum_required(VERSION 2.8)
project(OpenCV-Experiments)
find_package(OpenCV REQUIRED)

SET(RASPICAM ~/dev/userland/host_applications/linux/apps/raspicam)
include_directories(/opt/vc/include)
include_directories(/opt/vc/include/interface/vcos/pthreads)
include_directories(/opt/vc/include/interface/vmcs_host/linux)
include_directories(${RASPICAM})
include_directories(~/dev/userland)
SET(DISPLAY_CAMERA_INCLUDES
    ${RASPICAM}/RaspiCamControl.c
    ${RASPICAM}/RaspiCLI.c
    ${RASPICAM}/RaspiPreview.c
    ${RASPICAM}/RaspiTex.c
    ${RASPICAM}/RaspiTexUtil.c
    ${RASPICAM}/tga.c
    ${RASPICAM}/gl_scenes/teapot.c
    ${RASPICAM}/gl_scenes/models.c
    ${RASPICAM}/gl_scenes/square.c
    ${RASPICAM}/gl_scenes/mirror.c
    ${RASPICAM}/gl_scenes/yuv.c
    ${RASPICAM}/gl_scenes/sobel.c)
SET(MMAL_LIBS
    /opt/vc/lib/libmmal_core.so
    /opt/vc/lib/libmmal_util.so
    /opt/vc/lib/libmmal_vc_client.so
    /opt/vc/lib/libvcos.so)
SET(BCM_LIBS /opt/vc/lib/libbcm_host.so)
SET(GLES_LIBS /opt/vc/lib/libGLESv2.so)
SET(EGL_LIBS /opt/vc/lib/libEGL.so)

SET(DISPLAY_IMAGE build/display-image)
SET(DISPLAY_CAMERA build/display-camera)
add_executable(${DISPLAY_IMAGE} src/display-image.cpp)
add_executable(${DISPLAY_CAMERA} src/display-camera.c ${DISPLAY_CAMERA_INCLUDES})
target_link_libraries(${DISPLAY_IMAGE} ${OpenCV_LIBS})
target_link_libraries(${DISPLAY_CAMERA} ${MMAL_LIBS} ${BCM_LIBS} ${GLES_LIBS}
    ${EGL_LIBS} ${OpenCV_LIBS})
