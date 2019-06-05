#pragma once
#include "Map.h"

namespace Navigrap {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Podsumowanie informacji o FirstF
	/// </summary>
	public ref class FirstF : public System::Windows::Forms::Form
	{
	public:
		FirstF(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~FirstF()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FirstF::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(341, 361);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 60);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Wyjscie";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FirstF::Button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(341, 295);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(154, 60);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Opcje";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FirstF::Button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(341, 229);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(154, 60);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Mapa";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FirstF::Button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(308, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(220, 220);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// FirstF
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(836, 433);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"FirstF";
			this->Text = L"NaviGraph: Menu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Opcja w budowie");
	}
	private: System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e) {
		
		Map^ map = gcnew Map;
		map->ShowDialog();
	}
	};
}
