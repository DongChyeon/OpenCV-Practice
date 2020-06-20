#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat input = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat output = Mat::zeros(Size(input.cols, input.rows), input.type());
	// �ʱ�ȭ�Ұ��� 0, ���� �̹����� �Ȱ��� ũ��
	int newX, newY;	// ȭ�Ҹ� ���ġ�� ��ġ
	double pi = 3.141592653589793238562643383279;	// ���� ��
	double radian = (50 * pi) / 180.0;	// ����
	int centerX = input.cols / 2, centerY = input.rows / 2;	// �̹����� �߽�

	for (int y = 0; y < input.rows; y++) {
		for (int x = 0; x < input.cols; x++) {
			newX = (x - centerX) * cos(radian) + (y - centerY) * sin(radian) + centerX;
			newY = - (x - centerX) * sin(radian) + (y - centerY) * cos(radian) + centerY;
			if (newX > 0 && newY > 0 && newX < input.cols && newY < input.rows) {
				output.at<uchar>(newY, newX) = input.at<uchar>(y, x);
			}
		}	// �ݽð�������� �̹����� 50�� ȸ��
	}
	imshow("�Է� ����", input);
	imshow("��� ����", output);
	waitKey(0);
	return 0;
}