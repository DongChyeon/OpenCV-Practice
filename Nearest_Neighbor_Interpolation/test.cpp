#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	int originalX, originalY;	// 입력 영상의 최근접 좌표

	Mat input = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat output = Mat::zeros(Size(input.cols * 1.5, input.rows * 1.5), input.type());
	// 초기화소값이 0, 원본 이미지의 1.5배의 크기

	for (int y = 0; y < output.rows; y++) {
		for (int x = 0; x < output.cols; x++) {
			originalX = (int)(2 * (x + 0.5) / 3); originalY = (int)(2 * (y + 0.5) / 3);
			output.at<uchar>(y, x) = input.at<uchar>(originalY, originalX);
		}	// 가장 가까운 화소의 실수 값에 0.5를 더하고 정수값으로 만듦
	}		// 1.5배 확대했기 때문에 좌표에 2/3을 곱함
	imshow("입력 영상", input);
	imshow("출력 영상", output);
	waitKey(0);
	return 0;
}