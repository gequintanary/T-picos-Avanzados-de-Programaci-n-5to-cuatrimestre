#include "Figuras.h"
#include <iostream>

using namespace std;
using namespace cv;

void dibujarFiguras(Mat& img) {
    cout << "--- EJERCICIO 3: Figuras ---" << endl;

    // 1. Rectángulo rojo (borde)
	rectangle(img, Point(0, 0), Point(img.cols, img.rows), Scalar(0, 0, 255), 10);  // Borde de 10 píxeles, color rojo (BGR), grosor 10, sin rellen y el point es la esquina superior izquierda y la esquina inferior derecha

    // 2. Círculo verde en el centro
    Point centro(img.cols / 2, img.rows / 2);
	circle(img, centro, 50, Scalar(0, 255, 0), -1); // Relleno completo (-1), color verde (BGR), radio 50 píxeles, y el point es el centro del círculo

    // 3. Texto
    putText(img, "Gabriela Q.", Point(50, img.rows - 50), 
        FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255), 2);

    // Mostrar el resultado
    imshow("Imagen original con figuras", img);
}