#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	double alpha = 1.0;
	int beta = 0;
	Mat image = imread("C://OpenCV_Pictures//Racket.jpg");
	Mat oimage = Mat::zeros(image.size(), image.type());	// �ʱ� ȭ�Ұ� 0, ��� ���� �̹��� ������� Ÿ��
	cout << "���İ��� �Է��Ͻÿ� [1.0 ~ 3.0] : "; cin >> alpha;
	cout << "��Ÿ���� �Է��Ͻÿ� [0 ~ 100] : "; cin >> beta;
	for (int row = 0; row < image.rows; row++) {
		for (int col = 0; col < image.cols; col++) {
			for (int BGR = 0; BGR < 3; BGR++) {
				oimage.at<Vec3b>(row, col)[BGR] = saturate_cast<uchar>(alpha * (image.at<Vec3b>(row, col)[BGR] + beta));
			}	// <Vec3b>�� 3���� ����Ʈ ���� ���� Ŭ���� (0�̸� B, 1�̸� G, 2�̸� R);
		}
	}
	imshow("���� �̹���", image);
	imshow("����� �̹���", oimage);
	waitKey(0);
	return 0;
}