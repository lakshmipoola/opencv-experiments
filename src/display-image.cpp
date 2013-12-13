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
        ret_value = 1;
        return ret_value;
    }
    cv::Mat image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
    if (!image.data) {
        std::cout << "Invalid image!\n" << USAGE;
        ret_value = 1;
    } else {
        std::string window_name = "Display";
        cv::namedWindow(window_name, CV_WINDOW_AUTOSIZE);
        cv::imshow(window_name, image);
        cv::waitKey(0);
    }
    return ret_value;
}
