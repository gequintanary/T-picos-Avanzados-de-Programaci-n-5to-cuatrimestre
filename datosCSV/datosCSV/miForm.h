#pragma once
#include <fstream>   // Librería para leer el archivo CSV
#include <sstream>   // Librería para partir los textos
#include <vector>    // Para usar las listas dinámicas
#include <string>
#include <algorithm> // Librería para ordenar listas 


namespace datosCSV {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//Estructura con los 5 campos correspondientes a cada estudiante
	struct Estudiante {
		std::string nombre;
		std::string apPaterno;
		std::string apMaterno;
		std::string matricula;
		std::string curp;
	};

	// Creamos una variable que se encargará de cargar los datos del CSV a la memoria del formulario
	// Esta variable es global para que pueda ser accedida por cualquier función del formulario
	// Es una lista dinámica de tipo Estudiante, es decir, cada elemento de la lista es un estudiante con sus 5 campos
	std::vector<Estudiante> listaGlobalAlumnos;

	// Función para leer el archivo CSV y cargar los datos a una lista de tipo Estudiante (con los 5 campos)
	// Recibe el nombre del archivo CSV como parámetro y devuelve una lista de estudiantes con los datos cargados
	// La función abre el archivo, lee cada línea, parte los campos por comas y los guarda en la estructura Estudiante
	std::vector<Estudiante> leerCSV(const std::string& nombreArchivo)
	{
		std::vector<Estudiante> lista;
		std::ifstream archivo(nombreArchivo);

		if (!archivo.is_open())
		{
			MessageBox::Show("Error: no se pudo abrir el archivo alumnos.csv");
			return lista;
		}

		std::string linea;
		std::getline(archivo, linea); // Con esto saltamos la primera línea del CSV que contiene los nombres de los campos

		while (std::getline(archivo, linea))
		{
			std::stringstream ss(linea);
			Estudiante e;

			// Leemos y cortamos por comas cada campo del estudiante y los guardamos en la estructura Estudiante para que
			// cada campo quede guardado en su respectiva variable dentro de la estructura, por ejemplo, el nombre del estudiante se guarda en e.nombre, el apellido paterno en e.apPaterno, etc
			std::getline(ss, e.nombre, ',');
			std::getline(ss, e.apPaterno, ',');
			std::getline(ss, e.apMaterno, ',');
			std::getline(ss, e.matricula, ',');
			std::getline(ss, e.curp, ',');

			lista.push_back(e); // Agregamos el estudiante a la lista de estudiantes que se devolverá al final de la función
		}
		archivo.close();
		return lista;
	}

	// Método de ordenamiento de la lista de estudiantes por un campo específico, dependiendo del número que se le pase como parámetro
	// Dependiendo del número que le pasemos (0 a 4), ordena por un campo diferente
	void ordenarPorCampo(std::vector<Estudiante>& lista, int opcionCampo)
	{
		if (opcionCampo == 0) {
			// Ordena por Nombre
			std::sort(lista.begin(), lista.end(), [](const Estudiante& a, const Estudiante& b) { return a.nombre < b.nombre; });
		}
		else if (opcionCampo == 1) {
			// Ordena por Apellido Paterno
			std::sort(lista.begin(), lista.end(), [](const Estudiante& a, const Estudiante& b) { return a.apPaterno < b.apPaterno; });
		}
		else if (opcionCampo == 2) {
			// Ordena por Apellido Materno
			std::sort(lista.begin(), lista.end(), [](const Estudiante& a, const Estudiante& b) { return a.apMaterno < b.apMaterno; });
		}
		else if (opcionCampo == 3) {
			// Ordena por Matrícula
			std::sort(lista.begin(), lista.end(), [](const Estudiante& a, const Estudiante& b) { return a.matricula < b.matricula; });
		}
		else if (opcionCampo == 4) {
			// Ordena por CURP
			std::sort(lista.begin(), lista.end(), [](const Estudiante& a, const Estudiante& b) { return a.curp < b.curp; });
		}
	}

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
	private: System::Windows::Forms::Button^ botonCargarD;
	private: System::Windows::Forms::DataGridView^ tablaAlumnos;
	private: System::Windows::Forms::ComboBox^ comboCampoOrdenamiento;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ etiquetaOrdenamiento;

	protected:



	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->botonCargarD = (gcnew System::Windows::Forms::Button());
			this->tablaAlumnos = (gcnew System::Windows::Forms::DataGridView());
			this->comboCampoOrdenamiento = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->etiquetaOrdenamiento = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaAlumnos))->BeginInit();
			this->SuspendLayout();
			// 
			// botonCargarD
			// 
			this->botonCargarD->BackColor = System::Drawing::SystemColors::HighlightText;
			this->botonCargarD->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->botonCargarD->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->botonCargarD->Location = System::Drawing::Point(13, 397);
			this->botonCargarD->Name = L"botonCargarD";
			this->botonCargarD->Size = System::Drawing::Size(128, 32);
			this->botonCargarD->TabIndex = 0;
			this->botonCargarD->Text = L"Cargar CSV";
			this->botonCargarD->UseVisualStyleBackColor = false;
			this->botonCargarD->Click += gcnew System::EventHandler(this, &miForm::button1_Click);
			// 
			// tablaAlumnos
			// 
			this->tablaAlumnos->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->tablaAlumnos->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tablaAlumnos->Location = System::Drawing::Point(13, 13);
			this->tablaAlumnos->Name = L"tablaAlumnos";
			this->tablaAlumnos->RowHeadersWidth = 51;
			this->tablaAlumnos->RowTemplate->Height = 24;
			this->tablaAlumnos->Size = System::Drawing::Size(1005, 352);
			this->tablaAlumnos->TabIndex = 1;
			this->tablaAlumnos->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &miForm::tablaAlumnos_CellContentClick);
			// 
			// comboCampoOrdenamiento
			// 
			this->comboCampoOrdenamiento->FormattingEnabled = true;
			this->comboCampoOrdenamiento->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Nombre", L"Apellido Paterno", L"Apellido Materno",
					L"Matrícula", L"CURP"
			});
			this->comboCampoOrdenamiento->Location = System::Drawing::Point(803, 403);
			this->comboCampoOrdenamiento->Name = L"comboCampoOrdenamiento";
			this->comboCampoOrdenamiento->Size = System::Drawing::Size(215, 24);
			this->comboCampoOrdenamiento->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(164, 397);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(151, 32);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Ordenar datos";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &miForm::button1_Click_1);
			// 
			// etiquetaOrdenamiento
			// 
			this->etiquetaOrdenamiento->AutoSize = true;
			this->etiquetaOrdenamiento->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->etiquetaOrdenamiento->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->etiquetaOrdenamiento->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->etiquetaOrdenamiento->Location = System::Drawing::Point(684, 403);
			this->etiquetaOrdenamiento->Name = L"etiquetaOrdenamiento";
			this->etiquetaOrdenamiento->Size = System::Drawing::Size(98, 20);
			this->etiquetaOrdenamiento->TabIndex = 4;
			this->etiquetaOrdenamiento->Text = L"Ordenar por:";
			this->etiquetaOrdenamiento->Click += gcnew System::EventHandler(this, &miForm::label1_Click);
			// 
			// miForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1030, 439);
			this->Controls->Add(this->etiquetaOrdenamiento);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboCampoOrdenamiento);
			this->Controls->Add(this->tablaAlumnos);
			this->Controls->Add(this->botonCargarD);
			this->Name = L"miForm";
			this->Text = L"Listado de alumnos ordenable";
			this->Load += gcnew System::EventHandler(this, &miForm::miForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaAlumnos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Función para actualizar la tabla con los datos de la lista de estudiantes (para mostrar los datos en la tabla después de cargar el CSV o después de ordenar la lista)
		// Esta función se encarga de tomar la lista de estudiantes que tenemos en la variable global y mostrarla en la tabla visual del formulario (tablaAlumnos)
		// De forma general, limpia la tabla para eliminar cualquier renglón que ya tenga, y luego recorre la lista de estudiantes y por cada estudiante convierte sus campos de texto
		// a textos de Windows Forms (String^) para poder mostrarlos en la tabla, y finalmente agrega un renglón a la tabla con los datos del estudiante
	private: void actualizarTablaVisual() {
		tablaAlumnos->Rows->Clear(); // Limpiamos los renglones

		for (const auto& est : listaGlobalAlumnos)
		{
		// Convertimos los textos a textos de Windows Forms
		String^ nom = gcnew String(est.nombre.c_str());
		String^ pat = gcnew String(est.apPaterno.c_str());
		String^ mat = gcnew String(est.apMaterno.c_str());
		String^ matr = gcnew String(est.matricula.c_str());
		String^ curp = gcnew String(est.curp.c_str());

		// Agregamos el renglón a la tabla
		tablaAlumnos->Rows->Add(nom, pat, mat, matr, curp);
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Primero, configuramos la tabla para que tenga las columnas correspondientes a cada campo del estudiante, es decir, una columna para el nombre, otra para el apellido paterno, etc.
		tablaAlumnos->Columns->Clear();
		tablaAlumnos->Columns->Add("c1", "Nombre");
		tablaAlumnos->Columns->Add("c2", "Apellido Paterno");
		tablaAlumnos->Columns->Add("c3", "Apellido Materno");
		tablaAlumnos->Columns->Add("c4", "Matrícula");
		tablaAlumnos->Columns->Add("c5", "CURP");

		// Configuramos la tabla para que las columnas se ajusten al tamaño de la tabla y se vean bien
		tablaAlumnos->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

		// Leemos el archivo y lo guardamos en la variable global listaGlobalAlumnos, que es una lista de tipo Estudiante con los datos cargados del CSV
		// Es decir, cada elemento de la lista es un estudiante con sus 5 campos ya guardados en su respectiva variable dentro de la estructura Estudiante
		listaGlobalAlumnos = leerCSV("alumnos.csv");

		// Mostramos los datos en la tabla
		actualizarTablaVisual();
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		// Verificamos que el usuario haya seleccionado una opción en el ComboBox
		if (comboCampoOrdenamiento->SelectedIndex == -1) {
			MessageBox::Show("Por favor, selecciona un campo para ordenar.");
			return;
		}

		// Obtenemos qué opción eligió (0, 1, 2, 3 o 4)
		int opcion = comboCampoOrdenamiento->SelectedIndex;

		// Llamamos al método que hicimos arriba para ordenar la lista
		ordenarPorCampo(listaGlobalAlumnos, opcion);

		// Como la lista ya se ordenó por detrás, volvemos a pintar la tabla para ver los cambios
		actualizarTablaVisual();


	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tablaAlumnos_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void miForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
