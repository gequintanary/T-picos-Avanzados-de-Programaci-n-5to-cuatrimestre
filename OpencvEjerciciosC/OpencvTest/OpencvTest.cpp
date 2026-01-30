// Opencv_Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <opencv2/opencv.hpp>
#include <iostream>

#include "Dimensiones.h"
#include "Resize.h"
#include "Figuras.h"
#include "CamaraWeb.h"

using namespace cv;
using namespace std;

/**
 * Codigo modificado para realizar los ejercicios de OpenCV:
 * 1. Dimensiones, 2. Redimensionado, 3. Figuras, 4. Cámara Web
 */
int main() {
    Mat img_resized;
    Mat img = imread("../img/descarga.jpg");
    if (img.empty()) {
        cout << "No se pudo cargar la imagen. Verifica la ruta '../img/descarga.jpg'" << endl;
        return -1;
    }

    // -----------------------------------------------------
    // EJERCICIO 1: DIMENSIONES
    // -----------------------------------------------------
    // 1. Mostrar dimensiones (Rows, Cols, Channels)
   // cout << "--- EJERCICIO 1: Dimensiones ---" << endl;
    mostrarDimensiones(img);


    // -----------------------------------------------------
    // EJERCICIO 2: REDIMENSIONADO
    // -----------------------------------------------------
    // 2. Redimensionar a 1024x1024 
    Resize(img);
    cout << "\nPresiona la barra espaciadora para continuar a FIGURAS..." << endl;
    waitKey(0);
    destroyAllWindows();
    // -----------------------------------------------------


    // -----------------------------------------------------
    // EJERCICIO 3: FIGURAS
    // -----------------------------------------------------
    // 3. Dibujar figuras sobre la imagen original
    //cout << "--- EJERCICIO 3: Figuras ---" << endl;
    dibujarFiguras(img);
    cout << "\nPresiona la barra espaciadora para iniciar la CAMARA..." << endl;
    waitKey(0);
    destroyAllWindows();

    // -----------------------------------------------------
    // EJERCICIO 4: CÁMARA WEB
    // -----------------------------------------------------
   // cout << "--- EJERCICIO 4: Cámara web ---" << endl;
    iniciarCamara();

    return 0;
}

/*************************************************************************/
//21-Enero-2026 GabrielaQuintanar Setup de OpenCV en Visual Studio
//27-Enero-2026 GabrielaQuintanar Creación de repositorio en Github
//29-Enero-2026 GabrielaQuintanar Ejercicios: Dimensiones, Redimensionado, Figuras y Cámara Web
/************************************************************************/