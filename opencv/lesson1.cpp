#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/viz.hpp>
#include <iostream>

using namespace cv;

int main(){

    viz::Viz3d window("w");

    // XYZ-> RGB (右手系:X红->右,Y绿->上;Z蓝黑->外);
    window.showWidget("Coordinate", viz::WCoordinateSystem());

    viz::WLine l1(Point3d(0,0,0), Point3d(1,1,1), viz::Color::white());

    window.showWidget("line1", l1);

    window.spin();

    return 0;
}