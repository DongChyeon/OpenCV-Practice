#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat image = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat dst;
	int threshold_value = 127;	// �Ӱ�ġ�� 127��
	threshold(image, dst, threshold_value, 255, THRESH_BINARY);	// ����ȭ
	imshow("���� �̹���", image);
	imshow("�ٲ� �̹���", dst);
	waitKey(0);
	return 0;
}