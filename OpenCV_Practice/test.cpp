#include <opencv2\opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat image;
	image = imread("C://Racket.jpg", IMREAD_COLOR);
	if (image.empty()) { cout << "������ ���� �� ����" << endl; }

	imshow("��� ����", image);
	waitKey(0);
	return 0;
}