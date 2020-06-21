#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	int newX, newY;	// ȭ�Ҹ� ���ġ�� ��ġ

	Mat input = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat output = Mat::zeros(Size(input.cols * 1.5, input.rows * 1.5), input.type());
	// �ʱ�ȭ�Ұ� 0, ���� �̹����� ũ���� 1.5��

	for (int y = 0; y < input.rows; y++) {
		for (int x = 0; x < input.cols; x++) {
			newX = x * 1.5; newY = y * 1.5;
			output.at<uchar>(newY, newX) = input.at<uchar>(y, x);
			// 1.5 �ø� �̹����� �ȼ��� ��ġ�� 1.5�� �÷� ���ġ
		}
	}
	imshow("�Է� ����", input);
	imshow("��� ����", output);
	waitKey(0);
	return 0;
}