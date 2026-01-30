#include "Resize.h"
#include <iostream>

using namespace std;
using namespace cv;

void Resize(const cv::Mat& imgOriginal)
{
    cout << "--- EJERCICIO 2: Redimensionado ---" << endl;

    Mat imgResized;
    // Redimensionar a 1024x1024
    resize(imgOriginal, imgResized, Size(1024, 1024));

    // Mostrar ambas
    imshow("Original (Resize)", imgOriginal);
    imshow("Redimensionada 1024x1024", imgResized);
}
