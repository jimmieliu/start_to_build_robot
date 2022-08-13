#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

using namespace cv;

int main()
{
    std::string image_path = samples::findFile("resources/opencv-logo-small.png");
    Mat img = imread(image_path, IMREAD_COLOR); // BGR

    if (img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }

    std::cout << "img.dims = " << img.dims << std::endl;
    std::cout << "img.size = " << img.size << std::endl;
    std::cout << "img.channels = " << img.channels() << std::endl;
    std::cout << "img.depth = " << img.depth() << std::endl;
    std::cout << "img.cols = " << img.cols << std::endl;
    std::cout << "img.rows = " << img.rows << std::endl;
    std::cout << "img.type = " << img.type() << std::endl;
    // std::cout << "img = " << img() << std::endl;

    Mat img2(img.rows, img.cols, CV_8UC3);
    int from_to[] = {0, 1, 1, 2, 2, 0}; // move B to G, G to R, R to B
    mixChannels(&img, 1, &img2, 1, from_to, 3);

    Mat img3(img.rows, img.cols * 2, CV_8UC3);
    ;
    hconcat(img, img2, img3);

    imshow("Display window", img);
    // Block the program from existing
    char k = waitKey(0); // Wait for a keystroke in the window
    while (k != 'q')
    {
        if (k == 'a')
        {
            imshow("Display window", img);
        }
        else if (k == 'b')
        {
            imshow("Display window", img2);
        }
        else if (k == 'c')
        {
            imshow("Display window", img3);
        }
        k = waitKey(0);
    }

    return 0;
}