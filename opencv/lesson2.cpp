#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/viz.hpp>

#include <opencv2/calib3d.hpp>

#include <iostream>

using namespace cv;
using namespace std;

int main()
{

    viz::Viz3d window("w");
    // XYZ-> RGB (右手系:X红->右,Y绿->上;Z蓝黑->外);
    window.showWidget("Coordinate", viz::WCoordinateSystem());

    Mat rot_vec = Mat::zeros(1, 3, CV_32F);
    string widget_name = "plane";

    // viz::WLine w1(Point3d(0, 0, 0), Point3d(1, 1, 1), viz::Color::white());
    viz::WPlane w1;
    window.showWidget(widget_name, w1);

    int cnt = 0;

    while (!window.wasStopped())
    {
        Mat rot_mat;
        if (cnt % 100 == 0)
        {

            rot_vec.at<float>(0, 0) = (float)CV_PI * 0.00f;
            rot_vec.at<float>(0, 1) = (float)CV_PI * 0.00f;
            rot_vec.at<float>(0, 2) = (float)CV_PI * 0.00f;

            Rodrigues(rot_vec, rot_mat);
            Affine3f pose(rot_mat, Vec3f(0, 0, 0));
            window.setWidgetPose(widget_name, pose);
        }
        else
        {

            if (cnt < 100)
            {
                rot_vec.at<float>(0, 0) = (float)2 * CV_PI * 0.01f;
                rot_vec.at<float>(0, 1) = (float)2 * CV_PI * 0.00f;
                rot_vec.at<float>(0, 2) = (float)2 * CV_PI * 0.00f;
            }
            else if (cnt < 200)
            {
                rot_vec.at<float>(0, 0) = (float)2 * CV_PI * 0.00f;
                rot_vec.at<float>(0, 1) = (float)2 * CV_PI * 0.01f;
                rot_vec.at<float>(0, 2) = (float)2 * CV_PI * 0.00f;
            }
            else
            {
                rot_vec.at<float>(0, 0) = (float)2 * CV_PI * 0.00f;
                rot_vec.at<float>(0, 1) = (float)2 * CV_PI * 0.00f;
                rot_vec.at<float>(0, 2) = (float)2 * CV_PI * 0.01f;
            }

            Rodrigues(rot_vec, rot_mat);

            Affine3f pose(rot_mat, Vec3f(0, 0, 0));
            window.updateWidgetPose(widget_name, pose);
        }
        window.spinOnce(100, false);

        cnt += 1;
        if (cnt > 300)
        {
            cnt = 0;
        }
    }
    return 0;
}