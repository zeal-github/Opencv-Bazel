#include <iostream>
#include <string>
#include <chrono>

#include <opencv2/videoio/registry.hpp>
#include "opencv2/core.hpp" // you can also include necessary module only
#include "opencv2/videoio.hpp"

#define HIGH_RES_NOW std::chrono::high_resolution_clock::now();


int main(int argc, char* argv[]) {
    int width = 1280;
    int height = 960;
    auto mat_type = CV_8UC3;
    // auto fourcc =  cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
    auto fourcc = cv::VideoWriter::fourcc('m', 'p', '4', 'v');
    double fps = 10;
    bool is_color = true;

    auto all_backends = cv::videoio_registry::getBackends();
    std::cout << "All avaliable backends: " << std::endl;
    for (auto backend = all_backends.begin(); backend!=all_backends.end(); backend++)
    {
        std::cout << cv::videoio_registry::getBackendName(*backend) << std::endl;
    }
    std::cout << std::endl <<std::endl;

    // std::string video_name = "./test_video_001.avi"; // cv::VideoWriter::fourcc('M', 'J', 'P', 'G')
    std::string video_name = "./test_video_001.mp4"; // cv::VideoWriter::fourcc('m', 'p', '4', 'v')
    cv::VideoWriter video_writer;
    video_writer.open(video_name, fourcc, fps, cv::Size(width, height), is_color);

    std::cout << "Current Used Backend: " << video_writer.getBackendName() << std::endl;

    if (!video_writer.isOpened()) {
        std::cout << "Cannot open video writer" << std::endl;
    }

    cv::Mat cur_mat = cv::Mat(height, width, mat_type);
    auto start_timep = HIGH_RES_NOW;
    int total_frames_count = 1000;
    for (int i = 0; i<total_frames_count; i++) {
        video_writer << cur_mat;
        // std::cout << "Write " << i << " frame" << std::endl;
    }
    auto stop_timp = HIGH_RES_NOW;
    auto time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(stop_timp - start_timep).count();
    std::cout << "Write fps = " << total_frames_count * 1000.0 / time_elapsed << std::endl;
    video_writer.release();
    video_writer.release();
    
    std::cout << "End";
}