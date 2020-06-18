#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	double alpha = 1.0;
	int beta = 0;
	Mat image = imread("C://OpenCV_Pictures//Racket.jpg");
	Mat oimage = Mat::zeros(image.size(), image.type());	// 초기 화소값 0, 운본과 같은 이미지 사이즈와 타입
	cout << "알파값을 입력하시오 [1.0 ~ 3.0] : "; cin >> alpha;
	cout << "베타값을 입력하시오 [0 ~ 100] : "; cin >> beta;
	for (int row = 0; row < image.rows; row++) {
		for (int col = 0; col < image.cols; col++) {
			for (int BGR = 0; BGR < 3; BGR++) {
				oimage.at<Vec3b>(row, col)[BGR] = saturate_cast<uchar>(alpha * (image.at<Vec3b>(row, col)[BGR] + beta));
			}	// <Vec3b>는 3개의 바이트 값을 가진 클래스 (0이면 B, 1이면 G, 2이면 R);
		}
	}
	imshow("원래 이미지", image);
	imshow("밝아진 이미지", oimage);
	waitKey(0);
	return 0;
}