#pragma once

namespace Navigrap {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o Map
	/// </summary>
	public ref class Map : public System::Windows::Forms::Form
	{
	public:
		Map(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyść wszystkie używane zasoby.
		/// </summary>
		~Map()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obsługi projektanta — nie należy modyfikować
		/// jej zawartości w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Map::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 361);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 60);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Wyjście";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Map::Button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(812, 409);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Coral;
			this->button2->Location = System::Drawing::Point(72, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(40, 40);
			this->button2->TabIndex = 2;
			this->button2->Text = L"+";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Map::Button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Coral;
			this->button3->Location = System::Drawing::Point(118, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(40, 40);
			this->button3->TabIndex = 3;
			this->button3->Text = L"-";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Map::Button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button4->Location = System::Drawing::Point(784, 12);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(40, 40);
			this->button4->TabIndex = 4;
			this->button4->Text = L"→ ";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Map::Button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comfortaa", 8.999999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(12, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 24);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Zoom";
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button5->Location = System::Drawing::Point(692, 12);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(40, 40);
			this->button5->TabIndex = 6;
			this->button5->Text = L"↑";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Map::Button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button6->Location = System::Drawing::Point(646, 12);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(40, 40);
			this->button6->TabIndex = 7;
			this->button6->Text = L"←";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Map::Button6_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button7->Location = System::Drawing::Point(738, 12);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(40, 40);
			this->button7->TabIndex = 8;
			this->button7->Text = L"↓";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Map::Button7_Click);
			// 
			// Map
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(836, 433);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Map";
			this->Text = L"NaviGraph: Mapa";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->pictureBox1->Scale(2, 2);
	}
	private: System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->pictureBox1->Scale(0.5, 0.5);
	}
	private: System::Void Button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->pictureBox1->Left += -30;
	}
	private: System::Void Button7_Click(System::Object^ sender, System::EventArgs^ e) {
		this->pictureBox1->Top += -30;
	}
	private: System::Void Button6_Click(System::Object^ sender, System::EventArgs^ e) {
		this->pictureBox1->Left += 30;
	}
	private: System::Void Button5_Click(System::Object^ sender, System::EventArgs^ e) {
		this->pictureBox1->Top += 30;
	}
};
}
