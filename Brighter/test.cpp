#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
	Mat img = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	imshow("원래 이미지", img);

	for (int row = 0; row < img.rows; row++) {
		for (int col = 0; col < img.cols; col++) {
			//img.at<uchar>(row, col) = img.at<uchar>(row, col) + 50;	// 오버플로우 일어남
			img.at<uchar>(row, col) = saturate_cast<uchar>(img.at<uchar>(row, col) + 50);	// 오버플로우가 일어날 시 255로 고정
		}
	}

	imshow("밝아진 이미지", img);
	waitKey(0);
	return 0;
}