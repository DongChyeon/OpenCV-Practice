#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat src = imread("C://Racket.jpg", IMREAD_COLOR);
	if (src.empty()) { cout << "영상을 읽을 수 없음." << endl; }

	imshow("이미지", src);

	while (1) {
		int key = waitKeyEx();	// 사용자로부터 키 입력을 기다린다.
		if (key == 'q') break;
		else if (key == 2424832) {	// 왼쪽 방향키를 누르면
			src -= 50;	// 영상이 어두워진다.
		}
		else if (key == 2555904) {	// 오른쪽 방향키를 누르면
			src += 50;	// 영상이 밝아진다.
		}
		imshow("이미지", src);
	}
	return 0;
}