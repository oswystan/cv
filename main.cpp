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

void decode_jpg() {
    int buf_size = 1024*1024;
    std::string path = "1.jpg";
    void* data = malloc(buf_size);
    FILE* fp = fopen(path.c_str(), "r");
    if (!fp) {
        printf("ERROR: fail to open %s\n", path.c_str());
        return;
    }
    int cnt = fread(data, 1, buf_size, fp);
    cv::Mat jpg(1, cnt, CV_8UC1, data);
    cv::Mat dec_jpg = cv::imdecode(jpg, CV_LOAD_IMAGE_COLOR);
    imshow("dec jpg", dec_jpg);
}

void rect_overlap() {
    cv::Rect r1(0, 0, 640, 480);
    cv::Rect r2(10, 10, 640, 480);
    cv::Rect r3 = r1 & r2;
    printf("%d %d %d %d\n", r3.x, r3.y, r3.width, r3.height);
}

int main(int argc, char* argv[]){
    //yuv2rgb();
    //decode_jpg();
    rect_overlap();

    cv::waitKey(0);
    return 0;
}
/********************************** END **********************************************/

