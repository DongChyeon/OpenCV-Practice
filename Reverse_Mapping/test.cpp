#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat src = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat dst = Mat::zeros(Size(src.cols * 2, src.rows * 2), src.type());

	for (int y = 0; y < dst.rows; y++) {
		for (int x = 0; x < dst.cols; x++) {
			const int newX = x / 2.0;
			const int newY = y / 2.0;
			dst.at<uchar>(y, x) = src.at<uchar>(newY, newX);
		}
	}
	imshow("원래 이미지", src);
	imshow("확대된 이미지", dst);
	waitKey(0);
	return 0;
}