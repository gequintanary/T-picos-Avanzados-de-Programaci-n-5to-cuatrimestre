#pragma once

// Incluimos las librerías de OpenCV
#include <opencv2/opencv.hpp>
#include <msclr/marshal_cppstd.h>

namespace miPrimerGUII {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Resumen de miForm
    /// </summary>
    public ref class miForm : public System::Windows::Forms::Form
    {
    public:
        miForm(void)
        {
            InitializeComponent();
            //
            //TODO: agregar código de constructor aquí
            //
        }

    protected:
        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        ~miForm()
        {
            if (components)
            {
                delete components;
            }
        }

        // Aquí declaramos los controles que vamos a usar
    private: PictureBox^ pictureBox1;
    private: Button^ btnCargar;

    private:
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Método necesario para admitir el Diseñador.
        /// </summary>
        void InitializeComponent(void)
        {
            this->components = gcnew System::ComponentModel::Container();

            // Inicializamos los controles
            this->pictureBox1 = gcnew PictureBox();
            this->btnCargar = gcnew Button();

            // Configuración del Formulario Principal
            this->Size = System::Drawing::Size(500, 400); // Aumenté el tamaño para que quepa la imagen
            this->Text = L"miForm - OpenCV";
            this->Padding = System::Windows::Forms::Padding(0);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;

            // 
            // Configuración de pictureBox1
            // 
            this->pictureBox1->Location = System::Drawing::Point(20, 20);
            this->pictureBox1->Size = System::Drawing::Size(400, 300);
            this->pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;
            this->Controls->Add(this->pictureBox1); // Agregamos al formulario

            // 
            // Configuración de btnCargar
            // 
            this->btnCargar->Location = System::Drawing::Point(20, 340);
            this->btnCargar->Text = L"Cargar Imagen";
            // Aquí conectamos el botón con TU clase (miForm)
            this->btnCargar->Click += gcnew EventHandler(this, &miForm::btnCargar_Click);
            this->Controls->Add(this->btnCargar); // Agregamos al formulario
        }
#pragma endregion

        // ---------------------------------------------------------
        // TUS FUNCIONES PERSONALIZADAS
        // ---------------------------------------------------------

        // Función para convertir de OpenCV Mat a .NET Bitmap
        System::Drawing::Bitmap^ MatToBitmap(const cv::Mat& mat)
        {
            cv::Mat temp;
            // OpenCV usa BGR, Windows Forms usa RGB, hay que convertir
            cv::cvtColor(mat, temp, cv::COLOR_BGR2RGB);

            System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(
                temp.cols, temp.rows,
                System::Drawing::Imaging::PixelFormat::Format24bppRgb
            );

            // Copia lenta pixel por pixel (funciona, pero no es lo más optimo para video en vivo)
            for (int y = 0; y < temp.rows; y++)
            {
                for (int x = 0; x < temp.cols; x++)
                {
                    cv::Vec3b color = temp.at<cv::Vec3b>(y, x);
                    System::Drawing::Color c = System::Drawing::Color::FromArgb(color[0], color[1], color[2]);
                    bmp->SetPixel(x, y, c);
                }
            }
            return bmp;
        }

        // Evento del clic del botón
        void btnCargar_Click(System::Object^ sender, System::EventArgs^ e) {
            // Asegúrate de que esta ruta sea correcta en tu PC
            // Si la imagen no existe, saldrá el mensaje de error.
            // Prueba poner una ruta absoluta tipo: "C:\\imagen.jpg" para probar primero.
            cv::Mat imagen = cv::imread("../img/descarga.jpg");

            if (!imagen.empty()) {
                pictureBox1->Image = MatToBitmap(imagen);
            }
            else {
                MessageBox::Show("No se pudo cargar la imagen. Revisa la ruta.");
            }
        }
    };
}