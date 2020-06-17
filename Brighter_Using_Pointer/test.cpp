#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
	Mat img = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	imshow("���� �̹���", img);

	for (int row = 0; row < img.rows; row++) {
		uchar* p = img.ptr<uchar>(row);	// �����͸� ���
		for (int col = 0; col < img.cols; col++) {
			p[col] = saturate_cast<uchar>(p[col] + 50);
		}
	}
	imshow("����� �̹���", img);
	waitKey(0);

	return 0;
}