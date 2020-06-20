#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat input = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat output = Mat::zeros(Size(input.cols, input.rows), input.type());
	// 초기화소값이 0, 원본 이미지와 똑같은 크기
	int newX, newY;	// 화소를 재배치할 위치
	double pi = 3.141592653589793238562643383279;	// 파이 값
	double radian = (50 * pi) / 180.0;	// 라디안
	int centerX = input.cols / 2, centerY = input.rows / 2;	// 이미지의 중심

	for (int y = 0; y < input.rows; y++) {
		for (int x = 0; x < input.cols; x++) {
			newX = (x - centerX) * cos(radian) + (y - centerY) * sin(radian) + centerX;
			newY = - (x - centerX) * sin(radian) + (y - centerY) * cos(radian) + centerY;
			if (newX > 0 && newY > 0 && newX < input.cols && newY < input.rows) {
				output.at<uchar>(newY, newX) = input.at<uchar>(y, x);
			}
		}	// 반시계방향으로 이미지를 50도 회전
	}
	imshow("입력 영상", input);
	imshow("출력 영상", output);
	waitKey(0);
	return 0;
}