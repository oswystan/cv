/*
 **************************************************************************************
 *       Filename:  main.cpp
 *    Description:   isource file
 *
 *        Version:  1.0
 *        Created:  2017-07-19 11:57:17
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#include <string>
#include <stdio.h>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(int argc, char* argv[]){
    std::string path = "1.png";
    int resize_height = 256;
    int resize_width = 256;
    cv::Mat src = cv::imread(path);
    cv::Mat dst(256, 256, CV_8UC3);
    printf("\nsrc type=%d %d\n", src.type(), CV_8UC3);
    printf("%dx%d\n", src.size().width, src.size().height);
    imshow("src", src);
    cv::resize(src, dst, dst.size());
    imshow("dst", dst);

    cv::waitKey(0);
    return 0;
}
/********************************** END **********************************************/

