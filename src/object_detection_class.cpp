#include "object_detection.hpp"



Mat image_data::read_image(void){

   VideoCapture cap;
   cap.open(cam_num + apiID);

   if(!cap.isOpened())
   {
	   cerr << "Error - Cam not accessible !" << endl;
       //return -1;
	   
   }
  
    cap.read(Input);

    if(Input.empty())
    {
        cerr << "error reading camera";
        //return -1;
    }
       
    return Input;
       
}

int image_data::object_detection(cv::Mat input)
{
    cvtColor(input, input, COLOR_BGR2GRAY);
    medianBlur(input, Blur, 3);
    
    HoughCircles(Blur, Hough_Circle, HOUGH_GRADIENT, 1,
                 Blur.rows/16,  // change this value to detect circles with different distances to each other
                 100, 30, 1, 100 // change the last two parameters
            // (min_radius & max_radius) to detect larger circles
    );

    for(size_t i=0; i<Hough_Circle.size(); i++)
    {
        Vec3i c = Hough_Circle[i];
        Point center = Point(c[0], c[1]);
         circle( Blur, center, 1, Scalar(0,100,100), 3, LINE_AA);
        // circle outline
        int radius = c[2];
        circle( Blur, center, radius, Scalar(255,0,255), 3, LINE_AA);
    }
    imshow("detected circle", Blur);
    waitKey(10);
    return 1;

}