#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat src = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat dst = Mat::zeros(Size(src.cols * 2, src.rows * 2), src.type());	
	// 초기화소값 0, 원본 이미지의 크기의 2배

	for (int y = 0; y < src.rows; y++) {
		for (int x = 0; x < src.cols; x++) {
			const int newX = x * 2;
			const int newY = y * 2;
			dst.at<uchar>(newY, newX) = src.at<uchar>(y, x);
			// 두 배 늘린 이미지에 픽셀의 위치를 두 배 늘려 재배치
		}
	}
	imshow("원래 이미지", src);
	imshow("확대한 이미지", dst);
	waitKey(0);
	return 0;
}