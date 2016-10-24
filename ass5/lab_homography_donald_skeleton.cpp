// Lab-5 template file provided by Kaustubh Pathak
// Add your code in all places where it says "Fill-in".

//compile with 
//g++ lab_homography_donald_skeleton.cpp -o lab5 
//-lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_calib3d

#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/calib3d/calib3d.hpp"

using namespace std;
using namespace cv;

int main()
{

	//-- Localize the object
	std::vector<Point2f> srcPoints;
	std::vector<Point2f> dstPoints;

	// Example: Point V
	dstPoints.push_back(Point2f(0, 0)); srcPoints.push_back(Point2f(69, 354));
	dstPoints.push_back(Point2f(50, 0)); srcPoints.push_back(Point2f(159, 360));
	dstPoints.push_back(Point2f(100, 0)); srcPoints.push_back(Point2f(248, 365));
	dstPoints.push_back(Point2f(150, 0)); srcPoints.push_back(Point2f(337, 371));
	dstPoints.push_back(Point2f(200, 0)); srcPoints.push_back(Point2f(427, 377));
	dstPoints.push_back(Point2f(250, 0)); srcPoints.push_back(Point2f(518, 383));
	dstPoints.push_back(Point2f(300, 0)); srcPoints.push_back(Point2f(612, 389));

	dstPoints.push_back(Point2f(0, 50)); srcPoints.push_back(Point2f(100, 286));
	dstPoints.push_back(Point2f(50, 50)); srcPoints.push_back(Point2f(184, 291));
	dstPoints.push_back(Point2f(250, 50)); srcPoints.push_back(Point2f(519, 313));
	dstPoints.push_back(Point2f(300, 50)); srcPoints.push_back(Point2f(605, 319));

	dstPoints.push_back(Point2f(0, 100)); srcPoints.push_back(Point2f(130, 228));
	dstPoints.push_back(Point2f(300, 100)); srcPoints.push_back(Point2f(600, 256));

	dstPoints.push_back(Point2f(0, 150)); srcPoints.push_back(Point2f(153, 178));
	dstPoints.push_back(Point2f(300, 150)); srcPoints.push_back(Point2f(596, 202));

	dstPoints.push_back(Point2f(0, 200)); srcPoints.push_back(Point2f(173, 133));
	dstPoints.push_back(Point2f(50, 200)); srcPoints.push_back(Point2f(243, 137));
	dstPoints.push_back(Point2f(250, 200)); srcPoints.push_back(Point2f(522, 152));
	dstPoints.push_back(Point2f(300, 200)); srcPoints.push_back(Point2f(593, 155));

	dstPoints.push_back(Point2f(0, 250)); srcPoints.push_back(Point2f(193, 92));
	dstPoints.push_back(Point2f(50, 250)); srcPoints.push_back(Point2f(257, 96));
	dstPoints.push_back(Point2f(100, 250)); srcPoints.push_back(Point2f(323, 100));
	dstPoints.push_back(Point2f(150, 250)); srcPoints.push_back(Point2f(388, 103));
	dstPoints.push_back(Point2f(200, 250)); srcPoints.push_back(Point2f(454, 107));
	dstPoints.push_back(Point2f(250, 250)); srcPoints.push_back(Point2f(522, 109));
	dstPoints.push_back(Point2f(300, 250)); srcPoints.push_back(Point2f(590, 109));
	// Fill-in:
	// Push all other points A, B, C,...,Z

	// Fill-in: use the OpenCV findHomography to compute the homography matrix H.
	// Take the third parameter as just 0, which means use regular method using all points.

	Mat H = findHomography(srcPoints, dstPoints); 
	

	cout << "The computed homography matrix size is: " << endl;
	cout << "rows: "<< H.rows << ", cols= "<< H.cols << endl;
	for (int i = 0; i < H.rows; ++i) {
		for (int j = 0; j < H.cols; ++j) {
			cout << H.at<float>(i, j) << ",\t";
		}
		cout << endl;
	}
	
	Mat Img = imread("donald_annotated_points.png" , 1);
	Mat Out_Img;

	// Fill-in:
	// Use the warpPerspective method of OpenCV to convert the input image Img to
	// the corrected image Out_Img of size 300x300 using H.

	warpPerspective(Img, Out_Img, H, Size(300, 300), INTER_LINEAR);

	imshow("Input", Img);
	imshow("Output", Out_Img);
	imwrite("donald_annotated_points_out.png", Out_Img);
	waitKey(0);

}

