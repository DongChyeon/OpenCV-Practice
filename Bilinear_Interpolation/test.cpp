#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

float lerp(float s, float e, float t) {
	return s + (e - s) * t;
}	// 선형 비례식을 통해 중간값을 반환

float blerp(float c00, float c10, float c01, float c11, float tx, float ty) {
	return lerp(lerp(c00, c10, tx), lerp(c01, c11, tx), ty);
}	// 구한 두 픽셀의 값을 선형 비례식을 통해 중간값을 반환

float getPixel(Mat img, int x, int y) {
	if (x > 0 && y > 0 && x < img.cols && y < img.rows)
		return (float)(img.at<uchar>(y, x));
	else
		return 0.0;
}	// 해당 좌표의 화소값을 얻어내는 함수

int main() {
	Mat input = imread("C://OpenCV_Pictures//Racket.jpg", IMREAD_GRAYSCALE);
	Mat output = Mat::zeros(Size(input.cols * 2, input.rows * 2), input.type());
	// 초기화소값이 0, 원본 이미지의 2.0배의 크기

	for (int y = 0; y < output.rows; y++) {
		for (int x = 0; x < output.cols; x++) {
			float gx = ((float)x) / 2.0;
			float gy = ((float)y) / 2.0;
			int gxi = (int)gx;
			int gyi = (int)gy;
			float c00 = getPixel(input, gxi, gyi);
			float c10 = getPixel(input, gxi + 1, gyi);
			float c01 = getPixel(input, gxi, gyi + 1);
			float c11 = getPixel(input, gxi + 1, gyi + 1);

			int value = (int)blerp(c00, c10, c01, c11, gx - gxi, gy - gyi);	// 구한 화소값
			output.at<uchar>(y, x) = value;
		}
	}
	imshow("입력 영상", input);
	imshow("출력 영상", output);
	waitKey(0);
	return 0;
}