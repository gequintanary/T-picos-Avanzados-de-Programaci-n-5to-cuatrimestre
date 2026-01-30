#pragma once
#include <opencv2/opencv.hpp>

// Aquí no usamos const porque vamos a dibujar sobre la imagen porque vamos a modificarla
void dibujarFiguras(cv::Mat& img);