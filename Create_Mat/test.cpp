#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat img(720, 480, CV_8UC3, Scalar(0, 255, 255));
	if (img.empty()) { cout << "������ ���� �� ����" << endl;	return -1; }
	imshow("�̹���", img);

	waitKey(0);
	return 0;
}