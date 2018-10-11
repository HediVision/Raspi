#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace cv;
using namespace std;

int main()
{
	Mat img;
	VideoCapture cap("/dev/stdin", cv::CAP_FFMPEG );
	cv::namedWindow("out",0);
    //VideoCapture cap(0);
	while (true)
	{
		cap >> img;
		CascadeClassifier face_cascade;
    	face_cascade.load( "haarcascade_frontalface_alt2.xml" );
 	    // Detect faces
    	std::vector<Rect> faces;
    	face_cascade.detectMultiScale( img, faces, 1.1, 2, 0, Size(30, 30) );
 	    // Draw circles on the detected faces
    	for( int i = 0; i < faces.size(); i++ )
    	{
        	Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
       		 ellipse( img, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
    	}
      	imshow("out", img);
		int key=waitKey(1);
		if (key==27)
				break;
	}

	return 0;
}
