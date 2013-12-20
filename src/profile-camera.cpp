/* An OpenCV experiment
 * Take and display 100 pictures. Shoud be run with time.
 * Daniel Lee, 2013
 */

#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "RaspiCamCV.h"

int WIDTH = 640;
int HEIGHT = 480;

int main(int argc, char** argv) {
    RaspiCamCvCapture * camera =
        raspiCamCvCreateCameraCaptureWithDims(WIDTH, HEIGHT);
    cv::Mat image(raspiCamCvQueryFrame(camera));
    std::string window_name = "Display";
    cv::namedWindow(window_name, CV_WINDOW_AUTOSIZE);
    int i = 0;
    do {
        cv::Mat image(raspiCamCvQueryFrame(camera));
        cv::imshow(window_name, image);
        i += 1;
    } while (i < 100);
    return 0;
}
