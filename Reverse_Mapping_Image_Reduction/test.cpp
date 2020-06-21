#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	int newX, newY;	// 화소를 재배치할 위치

	Mat input = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat output = Mat::zeros(Size(input.cols / 2, input.rows / 2), input.type());
	// 초기화소값 0, 원본 이미지의 크기의 0.5배

	for (int y = 0; y < output.rows; y++) {
		for (int x = 0; x < output.cols; x++) {
			newX = x * 2; newY = y * 2;
			output.at<uchar>(y, x) = input.at<uchar>(newY, newX);
			// 50% 축소한 이미지에 픽셀 재배치 (역방향 사상)
		}
	}
	imshow("입력 영상", input);
	imshow("출력 영상", output);
	waitKey(0);
	return 0;
}