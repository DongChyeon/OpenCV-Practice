#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	int newX, newY;	// ȭ�Ҹ� ���ġ�� ��ġ

	Mat input = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat output = Mat::zeros(Size(input.cols / 2, input.rows / 2), input.type());
	// �ʱ�ȭ�Ұ� 0, ���� �̹����� ũ���� 0.5��

	for (int y = 0; y < input.rows; y++) {
		for (int x = 0; x < input.cols; x++) {
			newX = x / 2; newY = y / 2;
			if (newX > 0 && newY > 0 && newX < output.cols && newY < output.rows) {
				output.at<uchar>(newY, newX) = input.at<uchar>(y, x);
			}	// 50% ����� �̹����� �ȼ� ���ġ
		}
	}
	imshow("�Է� ����", input);
	imshow("��� ����", output);
	waitKey(0);
	return 0;
}