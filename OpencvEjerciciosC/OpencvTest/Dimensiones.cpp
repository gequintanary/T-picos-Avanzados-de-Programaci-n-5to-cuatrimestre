#include "Dimensiones.h"
#include <iostream>

using namespace std;
using namespace cv; // Lo usamos para que no haya que poner cv:: cada vez que usemos algo de OpenCV

void mostrarDimensiones(const Mat& img) {
    cout << "--- EJERCICIO 1: Dimensiones ---" << endl;
	cout << "Ancho (cols): " << img.cols << endl;  // cols es el ancho
	cout << "Alto (rows) : " << img.rows << endl;  // rows es el alto
	cout << "Canales     : " << img.channels() << endl;  // channels() devuelve el número de canales, esto se refiere a si la imagen es en escala de grises (1 canal) o en color (3 canales para BGR)
    cout << "--------------------------------" << endl;
}