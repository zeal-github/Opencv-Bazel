#include <iostream>
#include <string>

#include "opencv2/opencv.hpp"


int main(int argc, char* argv[]) {
    int width = 400;
    int height = 400;
    auto mat_type = CV_8UC3;
    cv::Mat cur_mat = cv::Mat(height, width, mat_type);
    std::cout << "End";
}