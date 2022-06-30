#include "application.h"

Application::Application(QObject *parent) : QObject(parent)
{

}

void Application::load(QString imagePath)
{
    // read an image
    cv::Mat image = cv::imread(imagePath.toStdString(), 1);
    // create image window named "Preview"
    cv::namedWindow("Preview");
    // show the image on window
    cv::imshow("Preview", image);
}
