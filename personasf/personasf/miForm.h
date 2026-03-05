#pragma once

namespace personasf {

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
	private: System::Windows::Forms::Label^ etiquetaNombre;
	protected:
	private: System::Windows::Forms::Label^ etiquetaAPaterno;
	private: System::Windows::Forms::Label^ etiquetaAMaterno;
	private: System::Windows::Forms::Label^ etiquetaFechaN;
	private: System::Windows::Forms::Label^ etiquetaCURP;
	private: System::Windows::Forms::Label^ etiquetaDomicilio;

	protected:





	private: System::Windows::Forms::TextBox^ textoNombre;
	private: System::Windows::Forms::TextBox^ textoAPaterno;
	private: System::Windows::Forms::TextBox^ textoAMaterno;
	private: System::Windows::Forms::TextBox^ textoFechaN;
	private: System::Windows::Forms::TextBox^ textoCURP;
	private: System::Windows::Forms::TextBox^ textoDomicilio;
	private: System::Windows::Forms::Button^ botonGuardarD;








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
			this->etiquetaNombre = (gcnew System::Windows::Forms::Label());
			this->etiquetaAPaterno = (gcnew System::Windows::Forms::Label());
			this->etiquetaAMaterno = (gcnew System::Windows::Forms::Label());
			this->etiquetaFechaN = (gcnew System::Windows::Forms::Label());
			this->etiquetaCURP = (gcnew System::Windows::Forms::Label());
			this->etiquetaDomicilio = (gcnew System::Windows::Forms::Label());
			this->textoNombre = (gcnew System::Windows::Forms::TextBox());
			this->textoAPaterno = (gcnew System::Windows::Forms::TextBox());
			this->textoAMaterno = (gcnew System::Windows::Forms::TextBox());
			this->textoFechaN = (gcnew System::Windows::Forms::TextBox());
			this->textoCURP = (gcnew System::Windows::Forms::TextBox());
			this->textoDomicilio = (gcnew System::Windows::Forms::TextBox());
			this->botonGuardarD = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// etiquetaNombre
			// 
			this->etiquetaNombre->AutoSize = true;
			this->etiquetaNombre->BackColor = System::Drawing::SystemColors::ControlLight;
			this->etiquetaNombre->Location = System::Drawing::Point(12, 22);
			this->etiquetaNombre->Name = L"etiquetaNombre";
			this->etiquetaNombre->Size = System::Drawing::Size(71, 16);
			this->etiquetaNombre->TabIndex = 0;
			this->etiquetaNombre->Text = L"Nombre(s)";
			this->etiquetaNombre->Click += gcnew System::EventHandler(this, &miForm::label1_Click);
			// 
			// etiquetaAPaterno
			// 
			this->etiquetaAPaterno->AutoSize = true;
			this->etiquetaAPaterno->BackColor = System::Drawing::SystemColors::ControlLight;
			this->etiquetaAPaterno->Location = System::Drawing::Point(12, 48);
			this->etiquetaAPaterno->Name = L"etiquetaAPaterno";
			this->etiquetaAPaterno->Size = System::Drawing::Size(107, 16);
			this->etiquetaAPaterno->TabIndex = 1;
			this->etiquetaAPaterno->Text = L"Apellido Paterno";
			this->etiquetaAPaterno->Click += gcnew System::EventHandler(this, &miForm::label2_Click);
			// 
			// etiquetaAMaterno
			// 
			this->etiquetaAMaterno->AutoSize = true;
			this->etiquetaAMaterno->BackColor = System::Drawing::SystemColors::ControlLight;
			this->etiquetaAMaterno->Location = System::Drawing::Point(12, 75);
			this->etiquetaAMaterno->Name = L"etiquetaAMaterno";
			this->etiquetaAMaterno->Size = System::Drawing::Size(109, 16);
			this->etiquetaAMaterno->TabIndex = 2;
			this->etiquetaAMaterno->Text = L"Apellido Materno";
			// 
			// etiquetaFechaN
			// 
			this->etiquetaFechaN->AutoSize = true;
			this->etiquetaFechaN->BackColor = System::Drawing::SystemColors::ControlLight;
			this->etiquetaFechaN->Location = System::Drawing::Point(12, 101);
			this->etiquetaFechaN->Name = L"etiquetaFechaN";
			this->etiquetaFechaN->Size = System::Drawing::Size(132, 16);
			this->etiquetaFechaN->TabIndex = 3;
			this->etiquetaFechaN->Text = L"Fecha de nacimiento";
			// 
			// etiquetaCURP
			// 
			this->etiquetaCURP->AutoSize = true;
			this->etiquetaCURP->BackColor = System::Drawing::SystemColors::ControlLight;
			this->etiquetaCURP->Location = System::Drawing::Point(12, 128);
			this->etiquetaCURP->Name = L"etiquetaCURP";
			this->etiquetaCURP->Size = System::Drawing::Size(45, 16);
			this->etiquetaCURP->TabIndex = 4;
			this->etiquetaCURP->Text = L"CURP";
			// 
			// etiquetaDomicilio
			// 
			this->etiquetaDomicilio->AutoSize = true;
			this->etiquetaDomicilio->BackColor = System::Drawing::SystemColors::ControlLight;
			this->etiquetaDomicilio->Location = System::Drawing::Point(12, 154);
			this->etiquetaDomicilio->Name = L"etiquetaDomicilio";
			this->etiquetaDomicilio->Size = System::Drawing::Size(63, 16);
			this->etiquetaDomicilio->TabIndex = 5;
			this->etiquetaDomicilio->Text = L"Domicilio";
			// 
			// textoNombre
			// 
			this->textoNombre->Location = System::Drawing::Point(92, 16);
			this->textoNombre->Name = L"textoNombre";
			this->textoNombre->Size = System::Drawing::Size(284, 22);
			this->textoNombre->TabIndex = 6;
			this->textoNombre->TextChanged += gcnew System::EventHandler(this, &miForm::textBox1_TextChanged);
			// 
			// textoAPaterno
			// 
			this->textoAPaterno->Location = System::Drawing::Point(125, 42);
			this->textoAPaterno->Name = L"textoAPaterno";
			this->textoAPaterno->Size = System::Drawing::Size(237, 22);
			this->textoAPaterno->TabIndex = 7;
			// 
			// textoAMaterno
			// 
			this->textoAMaterno->Location = System::Drawing::Point(127, 69);
			this->textoAMaterno->Name = L"textoAMaterno";
			this->textoAMaterno->Size = System::Drawing::Size(235, 22);
			this->textoAMaterno->TabIndex = 8;
			// 
			// textoFechaN
			// 
			this->textoFechaN->Location = System::Drawing::Point(150, 95);
			this->textoFechaN->Name = L"textoFechaN";
			this->textoFechaN->Size = System::Drawing::Size(173, 22);
			this->textoFechaN->TabIndex = 9;
			// 
			// textoCURP
			// 
			this->textoCURP->Location = System::Drawing::Point(63, 122);
			this->textoCURP->Name = L"textoCURP";
			this->textoCURP->Size = System::Drawing::Size(229, 22);
			this->textoCURP->TabIndex = 10;
			// 
			// textoDomicilio
			// 
			this->textoDomicilio->Location = System::Drawing::Point(81, 148);
			this->textoDomicilio->Name = L"textoDomicilio";
			this->textoDomicilio->Size = System::Drawing::Size(303, 22);
			this->textoDomicilio->TabIndex = 11;
			// 
			// botonGuardarD
			// 
			this->botonGuardarD->Location = System::Drawing::Point(125, 293);
			this->botonGuardarD->Name = L"botonGuardarD";
			this->botonGuardarD->Size = System::Drawing::Size(120, 23);
			this->botonGuardarD->TabIndex = 12;
			this->botonGuardarD->Text = L"Guardar datos";
			this->botonGuardarD->UseVisualStyleBackColor = true;
			this->botonGuardarD->Click += gcnew System::EventHandler(this, &miForm::btnGuardar_Click);
			// 
			// miForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(388, 349);
			this->Controls->Add(this->botonGuardarD);
			this->Controls->Add(this->textoDomicilio);
			this->Controls->Add(this->textoCURP);
			this->Controls->Add(this->textoFechaN);
			this->Controls->Add(this->textoAMaterno);
			this->Controls->Add(this->textoAPaterno);
			this->Controls->Add(this->textoNombre);
			this->Controls->Add(this->etiquetaDomicilio);
			this->Controls->Add(this->etiquetaCURP);
			this->Controls->Add(this->etiquetaFechaN);
			this->Controls->Add(this->etiquetaAMaterno);
			this->Controls->Add(this->etiquetaAPaterno);
			this->Controls->Add(this->etiquetaNombre);
			this->Name = L"miForm";
			this->Text = L"miForm";
			this->Load += gcnew System::EventHandler(this, &miForm::miForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void miForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {

	// Si algo sale mal al guardar el archivo, el programa no se cerrará de golpe,
	// sino que mostrara un mensaje
	try {

		// Usamos SteamWriter para escribir en archivos de texto en Windows Forms
		// Donde registros.txt sera el nombre del archivo que se va a crear
		// El true es para que si el archivo ya existe, agregue nuevos datos al final 
		// en lugar de borrar lo que ya se tenia guardado
		
		System::IO::StreamWriter^ archivo = gcnew System::IO::StreamWriter("registros.txt", true);

		// 2. ESCRIBIMOS LOS DATOS
		// Escribimos en una linea de texto y luego presionamos Enter automaticamente
		// Aqui juntamos un texto como lo es el nombre con lo que se haya escrito en la caja de texto, por ejemplo, si el usuario escribio "Juan" en la caja de texto del nombre, se guardara "Nombre: Juan" en el archivo txt.
		
		archivo->WriteLine("----- NUEVO REGISTRO -----");
		archivo->WriteLine("Nombre(s): " + textoNombre->Text);
		archivo->WriteLine("Apellido Paterno: " + textoAPaterno->Text);
		archivo->WriteLine("Apellido Materno: " + textoAMaterno->Text);
		archivo->WriteLine("Fecha de nacimiento: " + textoFechaN->Text);
		archivo->WriteLine("CURP: " + textoCURP->Text);
		archivo->WriteLine("Domicilio: " + textoDomicilio->Text);
		archivo->WriteLine("--------------------------");
		archivo->WriteLine(""); // Dejamos una línea en blanco para que se vea ordenado

		// Esto es para cerrar el archivo después de escribir 
		// con esto nos aseguramos de que los datos se guarden correctamente en el disco
		archivo->Close();

		// Este es un mensaje que aparece en la pantalla como una ventana que confirma que 
		// los datos se guardaron sin problemas
		MessageBox::Show("Los datos se han guardado exitosamente en el archivo txt (registros.txt).", "Éxito");

		// Esto borra lo que se haya escrito para que la pantalla quede 
		// lista para registrar a una nueva persona.
		textoNombre->Text = "";
		textoAPaterno->Text = "";
		textoAMaterno->Text = "";
		textoFechaN->Text = "";
		textoCURP->Text = "";
		textoDomicilio->Text = "";
	}
	catch (System::Exception^ error) {
		// Si el try falla (si no hay espacio en el equipo o no se pudi escribir en el archivo), el código se movera para acá
		// y mostrará una ventana de cual fue  el error que ocurrió
		MessageBox::Show("Hubo un problema al guardar el archivo: " + error->Message, "Error");
	}
}
};
}
