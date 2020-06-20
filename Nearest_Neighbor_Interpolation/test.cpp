#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	int originalX, originalY;	// �Է� ������ �ֱ��� ��ǥ

	Mat input = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat output = Mat::zeros(Size(input.cols * 1.5, input.rows * 1.5), input.type());
	// �ʱ�ȭ�Ұ��� 0, ���� �̹����� 1.5���� ũ��

	for (int y = 0; y < output.rows; y++) {
		for (int x = 0; x < output.cols; x++) {
			originalX = (int)(2 * (x + 0.5) / 3); originalY = (int)(2 * (y + 0.5) / 3);
			output.at<uchar>(y, x) = input.at<uchar>(originalY, originalX);
		}	// ���� ����� ȭ���� �Ǽ� ���� 0.5�� ���ϰ� ���������� ����
	}		// 1.5�� Ȯ���߱� ������ ��ǥ�� 2/3�� ����
	imshow("�Է� ����", input);
	imshow("��� ����", output);
	waitKey(0);
	return 0;
}