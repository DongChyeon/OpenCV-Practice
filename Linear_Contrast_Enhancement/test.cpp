#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int contrastEnhancement(int input, int x1, int y1, int x2, int y2);

int main() {
	Mat image = imread("C://OpenCV_Pictures//Racket.jpg");
	Mat oimage = image.clone();

	int x1, y1, x2, y2;
	cout << "x1 값을 입력하세요 : "; cin >> x1;
	cout << "y1 값을 입력하세요 : "; cin >> y1;
	cout << "x2 값을 입력하세요 : "; cin >> x2;
	cout << "y2 값을 입력하세요 : "; cin >> y2;

	for (int row = 0; row < image.rows; row++) {
		for (int col = 0; col < image.cols; col++) {
			for (int BGR = 0; BGR < 3; BGR++) {
				int output = contrastEnhancement(image.at<Vec3b>(row, col)[BGR], x1, y1, x2, y2);
				oimage.at<Vec3b>(row, col)[BGR] = saturate_cast<uchar>(output);
			}
		}
	}

	imshow("원래 이미지", image);
	imshow("바뀐 이미지", oimage);
	waitKey(0);
	return 0;
}

int contrastEnhancement(int input, int x1, int y1, int x2, int y2) {
	double output;
	if (0 <= input && input <= x1) {
		output = y1 / x1 * input;
	}
	else if (x1 < input && input <= x2) {
		output = ((y2 - y1) / (x2 - x1)) * (input - x1) * y1;
	}
	else if (x2 < input && input <= 255) {
		output = ((255 - y2) / (255 - x2)) * (input - x2) * y2;
	}
	return (int)output;
}