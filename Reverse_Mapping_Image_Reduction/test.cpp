#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	int newX, newY;	// ȭ�Ҹ� ���ġ�� ��ġ

	Mat input = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat output = Mat::zeros(Size(input.cols / 2, input.rows / 2), input.type());
	// �ʱ�ȭ�Ұ� 0, ���� �̹����� ũ���� 0.5��

	for (int y = 0; y < output.rows; y++) {
		for (int x = 0; x < output.cols; x++) {
			newX = x * 2; newY = y * 2;
			output.at<uchar>(y, x) = input.at<uchar>(newY, newX);
			// 50% ����� �̹����� �ȼ� ���ġ (������ ���)
		}
	}
	imshow("�Է� ����", input);
	imshow("��� ����", output);
	waitKey(0);
	return 0;
}