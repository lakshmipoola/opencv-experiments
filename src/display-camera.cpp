/* An OpenCV experiment
 * Daniel Lee, 2013
 */

#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "RaspiCamCV.h"

int main(int argc, char** argv) {
    int ret_value = 0;
    const std::string binary_name(argv[0]);
    const std::string USAGE =
        "Usage: " + binary_name + " [still/video]\n";
    bool valid;
    std::string run_type;
    if (argc == 2) {
        run_type= argv[1];
        valid = run_type == "still" || run_type == "video";
    }
    else valid = false;

    if (valid) {
        RaspiCamCvCapture * camera = raspiCamCvCreateCameraCapture(0);
        cv::Mat image(raspiCamCvQueryFrame(camera));
        std::string window_name = "Display";
        cv::namedWindow(window_name, CV_WINDOW_AUTOSIZE);
        int pressed_key = 0;
        if (run_type == "still") {
            cv::imshow(window_name, image);
            do {
                pressed_key = cv::waitKey(0);
            } while (pressed_key != 27);
        } else {
            do {
                cv::Mat image(raspiCamCvQueryFrame(camera));
                cv::imshow(window_name, image);
                pressed_key = cv::waitKey(1);
            } while (pressed_key != 27);
        }
    } else {
        std::cout << USAGE;
        ret_value = 1;
    }
    return ret_value;
}
