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


void yuv2rgb() {
    void* ps = malloc(1600*1200*2);
    void* pd = malloc(1600*1200*3);
    cv::Mat src(1200, 1600, CV_8UC2, ps);
    cv::Mat dst(1200, 1600, CV_8UC3, pd);
    FILE* fp = fopen("1.yuv", "r");
    if (!fp) {
        printf("fail to open yuv data\n");
        return;
    }

    fread(ps, 1600*1200*2, 1, fp);
    cv::cvtColor(src, dst, CV_YUV2BGR_YUYV);
    cv::imshow("dst", dst);

    fclose(fp);
}

void show_png() {
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
}

int main(int argc, char* argv[]){
    yuv2rgb();

    cv::waitKey(0);
    return 0;
}
/********************************** END **********************************************/

