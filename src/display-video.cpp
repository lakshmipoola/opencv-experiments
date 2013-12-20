/* An OpenCV experiment
 * Daniel Lee, 2013
 */

#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv) {
    int ret_value = 0;
    const std::string binary_name(argv[0]);
    const std::string USAGE =
            "Usage: " + binary_name + " [file to display]\n";
    if (argc != 2) {
        std::cout << USAGE;
        return 1;
    }
    cv::VideoCapture video = cv::VideoCapture(argv[1]);
    if (!video.isOpened()) {
        std::cout << "Invalid image!\n" << USAGE;
        ret_value = 1;
    } else {
        cv::Mat image;
        std::string window_name = "Display";
        cv::namedWindow(window_name, CV_WINDOW_AUTOSIZE);
        while (cv::waitKey(1) != 27) {
            video >> image;
            if (!image.data) break;
            cv::imshow(window_name, image);
        }
    }
    return ret_value;
}
