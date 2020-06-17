#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
	Mat img = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	imshow("원래 이미지", img);

	for (int row = 0; row < img.rows; row++) {
		uchar* p = img.ptr<uchar>(row);	// 포인터를 사용
		for (int col = 0; col < img.cols; col++) {
			p[col] = saturate_cast<uchar>(p[col] + 50);
		}
	}
	imshow("밝아진 이미지", img);
	waitKey(0);

	return 0;
}