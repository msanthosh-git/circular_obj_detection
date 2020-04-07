#ifndef OBJECT_DETECT
#define OBJECT_DETECT
#include <iostream>
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat)
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

class image_data{

public:
   Mat Input, Output;
   Mat Blur;
   vector<Vec3f> Hough_Circle;
   
   Mat read_image();
   int object_detection(Mat Input);

private:
   int cam_num = 0;
   int apiID = cv::CAP_ANY;

};

#endif