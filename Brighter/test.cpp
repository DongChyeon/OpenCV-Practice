#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
	Mat img = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	imshow("���� �̹���", img);

	for (int row = 0; row < img.rows; row++) {
		for (int col = 0; col < img.cols; col++) {
			//img.at<uchar>(row, col) = img.at<uchar>(row, col) + 50;	// �����÷ο� �Ͼ
			img.at<uchar>(row, col) = saturate_cast<uchar>(img.at<uchar>(row, col) + 50);	// �����÷ο찡 �Ͼ �� 255�� ����
		}
	}

	imshow("����� �̹���", img);
	waitKey(0);
	return 0;
}