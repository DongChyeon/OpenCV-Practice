#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat image = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);	// �׷��̽����Ϸ� �о����
	imshow("���� �̹���", image);

	Mat dst;
	dst = 255 - image;	// �̹��� ����
	imshow("������ �̹���", dst);

	waitKey(0);
	return 0;
}