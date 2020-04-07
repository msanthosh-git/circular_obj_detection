#include "object_detection.hpp"

int main(){

    for(;;)
    {
        Mat obj_det;
        image_data id;
        obj_det = id.read_image();
        id.object_detection(obj_det);
        imshow("output", id.Input);
        waitKey(10);
    }

}