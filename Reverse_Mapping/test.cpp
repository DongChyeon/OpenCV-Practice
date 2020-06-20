#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	int newX, newY;	// 화소를 재배치할 위치

	Mat input = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat output = Mat::zeros(Size(input.cols * 1.5 , input.rows * 1.5), input.type());
	// 초기화소값 0, 원본 이미지의 크기의 1.5배

	for (int y = 0; y < output.rows; y++) {
		for (int x = 0; x < output.cols; x++) {
			newX = x / 1.5; newY = y / 1.5;
			output.at<uchar>(y, x) = input.at<uchar>(newY, newX);
			// 출력 영상의 화소를 스캔해 대응되는 입력 영상의 화소를 찾음
		}
	}
	imshow("입력 영상", input);
	imshow("출력 영상", output);
	waitKey(0);
	return 0;
}