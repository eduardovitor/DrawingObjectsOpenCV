#include <stdio.h> 
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

Mat myImage= imread("opencv2.jpg");

void desenharCirculo(int x, int y) {
	Point posicao(x, y);
	Scalar cor(10, 255, 247);
	//circle(Mat, Point, int, Point, int, );
	circle(myImage, posicao, 20, cor, -6);
}

void desenharRetangulo(int x, int y){
	Point inicial(x, y);
	Point final(x+30, y+30);
	Scalar cor(163, 9, 7);
	rectangle(myImage, inicial, final, cor, -6);
}


void eventosMouse(int event, int x, int y, int flags, void* userdata) {
	if (event == EVENT_LBUTTONDOWN) {
		desenharRetangulo(x, y);
	}
	else if (event == EVENT_RBUTTONDOWN) {
		desenharCirculo(x,y);
	}
	imshow("Imagem do logo", myImage);
}

int main() {
	if (myImage.empty()) {
		printf("Nao e possivel ler a imagem.");
		return -1;
	}
	namedWindow("Imagem do logo", WINDOW_AUTOSIZE);
	setMouseCallback("Imagem do logo", eventosMouse, NULL);
	waitKey(0);
	return 0;
}
