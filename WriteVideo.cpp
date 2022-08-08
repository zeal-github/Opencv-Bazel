#include <iostream>
#include <string>

#include "opencv2/opencv.hpp" // opencv.hpp will include all modules
// #include "opencv2/core.hpp" // you can also include necessary module only
// #include "opencv2/videoio.hpp"



int main(int argc, char* argv[]) {
    int width = 400;
    int height = 400;
    auto mat_type = CV_8UC3;
    // auto fourcc =  cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
    auto fourcc = cv::VideoWriter::fourcc('m', 'p', '4', 'v');
    double fps = 10;
    bool is_color = true;

    std::string video_name = "./test_video_001.avi"; // cv::VideoWriter::fourcc('M', 'J', 'P', 'G')
    std::string video_name = "./test_video_001.mp4"; // cv::VideoWriter::fourcc('m', 'p', '4', 'v')
    cv::VideoWriter video_writer;
    video_writer.open(video_name, fourcc, fps, cv::Size(width, height), is_color);
    if (!video_writer.isOpened()) {
        std::cout << "Cannot open video writer" << std::endl;
    }

    for (int i = 0; i<10; i++) {
        cv::Mat cur_mat = cv::Mat(height, width, mat_type);
        video_writer << cur_mat;
        std::cout << "Write " << i << " frame" << std::endl;
    }
    video_writer.release();
    
    std::cout << "End";
}