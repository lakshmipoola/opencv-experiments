/* An OpenCV experiment
 * Daniel Lee, 2013
 */

#include <iostream>
#include <sstream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "RaspiCamCV.h"

int main(int argc, char** argv) {
    int ret_value = 0;
    const std::string binary_name(argv[0]);
    const std::string USAGE =
        "Usage: " + binary_name + " [still/video] [width] [height]\n"
        "\n"
        "Width and height determine the dimensions of the picture.\n"
        "Width and height should be proportioned 4:3. Possible values:\n"
        "    640 480 (small picture)\n"
        "    1280 960 (larger picture)\n"
        "    2592 1944 (camera's native resolution)\n"
        "If no value is provided, width and height default to 640 480.\n"
        ;
    bool valid;
    std::string run_type;
    int width = 640;
    int height = 480;
    if (argc == 2 || argc == 4) {
        run_type= argv[1];
        valid = run_type == "still" || run_type == "video";
        if (argc == 4) {
            std::stringstream string_width(argv[2]);
            std::stringstream string_height(argv[3]);
            string_width >> width;
            string_height >> height;
            if (string_width.fail() || string_height.fail())
                valid = false;
        }
    }
    else valid = false;

    if (valid) {
        RaspiCamCvCapture * camera =
            raspiCamCvCreateCameraCaptureWithDims(width, height);
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
