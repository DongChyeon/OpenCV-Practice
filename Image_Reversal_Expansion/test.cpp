#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat image = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);	// 그레이스케일로 읽어들임
	imshow("원래 이미지", image);

	Mat dst;
	dst = 255 - image;	// 이미지 반전
	imshow("반전된 이미지", dst);

	waitKey(0);
	return 0;
}