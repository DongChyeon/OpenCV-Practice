#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	int newX, newY;	// 화소를 재배치할 위치

	Mat input = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat output = Mat::zeros(Size(input.cols, input.rows), input.type());
	// 초기화소값이 0, 원본 이미지와 똑같은 크기

	for (int y = 0; y < input.rows; y++) {
		for (int x = 0; x < input.cols; x++) {
			newX = x + 30; newY = y + 30;
			if (newX > 0 && newY > 0 && newX < input.cols && newY < input.rows) {
				output.at<uchar>(newY, newX) = input.at<uchar>(y, x);
			}
		}	// x, y 방향으로 30씩 이동한 곳으로 화소를 재배치
	}
	imshow("입력 영상", input);
	imshow("출력 영상", output);
	waitKey(0);
	return 0;
}