#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat src = imread("C://Racket.jpg", IMREAD_COLOR);
	if (src.empty()) { cout << "������ ���� �� ����." << endl; }

	imshow("�̹���", src);

	while (1) {
		int key = waitKeyEx();	// ����ڷκ��� Ű �Է��� ��ٸ���.
		if (key == 'q') break;
		else if (key == 2424832) {	// ���� ����Ű�� ������
			src -= 50;	// ������ ��ο�����.
		}
		else if (key == 2555904) {	// ������ ����Ű�� ������
			src += 50;	// ������ �������.
		}
		imshow("�̹���", src);
	}
	return 0;
}