#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	Mat src = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_COLOR);
	if (src.empty()) { cout << "������ ���� �� ����" << endl; }
	imshow("src", src);

	Mat gray, edge, output;
	cvtColor(src, gray, COLOR_BGR2GRAY);

	imshow("�׷��� ������ �̹���", gray);
	imwrite("C://grayRacket.jpg", gray);
	waitKey(0);
	return 0;
}