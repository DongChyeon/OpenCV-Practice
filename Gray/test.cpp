#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	Mat src = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_COLOR);
	if (src.empty()) { cout << "영상을 읽을 수 없음" << endl; }
	imshow("src", src);

	Mat gray, edge, output;
	cvtColor(src, gray, COLOR_BGR2GRAY);

	imshow("그레이 스케일 이미지", gray);
	imwrite("C://grayRacket.jpg", gray);
	waitKey(0);
	return 0;
}