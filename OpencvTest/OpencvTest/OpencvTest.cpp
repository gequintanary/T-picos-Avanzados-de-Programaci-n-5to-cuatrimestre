// Opncv_Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/**
 * Codigo de prueba para verificar la instalacion y configuracion de OpenCV
 */
int main() {
    Mat img_resized;
    Mat img = imread("../img/descarga.jpg"); // coloca una imagen en la carpeta del proyecto
    resize(img, img_resized, Size(636, 316)); // redimensionar a 1024x1024
    if (img.empty()) {
        cout << "No se pudo cargar la imagen" << std::endl;
        return -1;
    }
    imshow("Imagen Original", img);
    imshow("Imagen de prueba", img_resized);
    waitKey(0);
    return 0;
}

/*************************************************************************/
//21-Enero-2026 GabrielaQuintanar Setup de OpenCV en Visual Studio
//27-Enero-2026 GabrielaQuintanar Creación de repositorio en Github
/************************************************************************/