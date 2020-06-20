#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	int newX, newY;	// ȭ�Ҹ� ���ġ�� ��ġ

	Mat input = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat output = Mat::zeros(Size(input.cols, input.rows), input.type());
	// �ʱ�ȭ�Ұ��� 0, ���� �̹����� �Ȱ��� ũ��

	for (int y = 0; y < input.rows; y++) {
		for (int x = 0; x < input.cols; x++) {
			newX = x + 30; newY = y + 30;
			if (newX > 0 && newY > 0 && newX < input.cols && newY < input.rows) {
				output.at<uchar>(newY, newX) = input.at<uchar>(y, x);
			}
		}	// x, y �������� 30�� �̵��� ������ ȭ�Ҹ� ���ġ
	}
	imshow("�Է� ����", input);
	imshow("��� ����", output);
	waitKey(0);
	return 0;
}