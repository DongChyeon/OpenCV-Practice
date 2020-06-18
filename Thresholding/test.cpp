#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat image = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat dst;
	int threshold_value = 127;	// 임계치는 127로
	threshold(image, dst, threshold_value, 255, THRESH_BINARY);	// 양자화
	imshow("원래 이미지", image);
	imshow("바뀐 이미지", dst);
	waitKey(0);
	return 0;
}