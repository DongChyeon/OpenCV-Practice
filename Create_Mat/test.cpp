#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat img(720, 480, CV_8UC3, Scalar(0, 255, 255));
	if (img.empty()) { cout << "영상을 읽을 수 없음" << endl;	return -1; }
	imshow("이미지", img);

	waitKey(0);
	return 0;
}