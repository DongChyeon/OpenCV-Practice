#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	int newX, newY;	// 화소를 재배치할 위치

	Mat input = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat output = Mat::zeros(Size(input.cols * 1.5, input.rows * 1.5), input.type());
	// 초기화소값 0, 원본 이미지의 크기의 1.5배

	for (int y = 0; y < input.rows; y++) {
		for (int x = 0; x < input.cols; x++) {
			newX = x * 1.5; newY = y * 1.5;
			output.at<uchar>(newY, newX) = input.at<uchar>(y, x);
			// 1.5 늘린 이미지에 픽셀의 위치를 1.5배 늘려 재배치
		}
	}
	imshow("입력 영상", input);
	imshow("출력 영상", output);
	waitKey(0);
	return 0;
}