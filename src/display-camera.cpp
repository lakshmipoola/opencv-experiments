/* An OpenCV experiment
 * Daniel Lee, 2013
 */

#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "RaspiCamCV.h"

int main(int argc, char** argv) {
    RaspiCamCvCapture * camera = raspiCamCvCreateCameraCapture(0);
    cv::Mat image(raspiCamCvQueryFrame(camera));
    std::string window_name = "Display";
    cv::namedWindow(window_name, CV_WINDOW_AUTOSIZE);
    cv::imshow(window_name, image);
    cv::waitKey(0);
}
