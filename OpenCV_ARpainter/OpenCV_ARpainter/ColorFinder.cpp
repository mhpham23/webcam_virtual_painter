#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap(0);
	Mat img;
	Mat imgHSV, mask, imgColor;
	int hmin = 0, smin = 0, vmin = 0;
	int hmax = 180, smax = 260, vmax = 260;

	//namedWindow(“Trackbars”, (640, 200)); // Create Window
	namedWindow("Color Finder", (650, 250));
	//createTrackbar(“Hue Min”, “Trackbars”, &hmin, 179);
	createTrackbar("Hue Min", "Color Finder", &hmin, 180);
	//createTrackbar(“Hue Max”, “Trackbars”, &hmax, 179);
	createTrackbar("Hue Max", "Color Finder", &hmax, 180);
	/*createTrackbar(“Sat Min”, “Trackbars”, &smin, 255);
	createTrackbar(“Sat Max”, “Trackbars”, &smax, 255);
	createTrackbar(“Val Min”, “Trackbars”, &vmin, 255);
	createTrackbar(“Val Max”, “Trackbars”, &vmax, 255);*/
	createTrackbar("Satur Min", "Color Finder", &smin, 260);
	createTrackbar("Satur Max", "Color Finder", &smax, 260);
	createTrackbar("Val Min", "Color Finder", &vmin, 260);
	createTrackbar("Val Max", "Color Finder", &vmax, 260);

	while (true) {

		cap.read(img);
		cvtColor(img, imgHSV, COLOR_BGR2HSV);

		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, mask);
		// hmin, smin, vmin, hmax, smax, vmax;
		cout << "Cutie!!! Here are your values:";
		cout << hmin << "," << smin << ", " << vmin << " , " << hmax << ", " << smax << ", " << vmax << endl;
		imshow("Image", img);
		imshow("Mask", mask);
		waitKey(1);
	}
}