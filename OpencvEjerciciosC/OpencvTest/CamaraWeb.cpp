#include "CamaraWeb.h"
#include <iostream>

using namespace std;
using namespace cv;

void iniciarCamara() {
    cout << "--- EJERCICIO 4: Cámara Web ---" << endl;

	VideoCapture cap(0); // Abre la cámara web (0 es el ID de la cámara predeterminada)
	if (!cap.isOpened()) { // Verifica si se abrió correctamente la cámara
        cout << "Error: No se puede acceder a la camara." << endl;
        return;
    }

	Mat frame, gray; // Para mostrar el frame y su versión en gris
    cout << "Presiona 'ESC' para salir." << endl;

    while (true) {
		cap >> frame; // Para guardar el frame capturado mientras se reproduce el video
		if (frame.empty()) break; // Si no hay frame (imagen vacía), se sale del bucle

        // Convertir a grises
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        imshow("Video color", frame);
        imshow("Video gris", gray);

        if (waitKey(1) == 27) break; // Salir con ESC
    }
    cap.release();
}