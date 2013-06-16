#pragma once
#using<system.dll>
#include <string>
#include <string.h>
using namespace System;
using namespace System::IO;


value struct datatype
{
public:
	int index;
	String^ description;
	String^ start;
	String^ end;
};

namespace samplereadtext {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 





	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  No;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Description;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Start;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  End;
	private: System::Windows::Forms::ComboBox^  comboBox1;









	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->No = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Description = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Start = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->End = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowDrop = true;
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->No, this->Description, 
				this->Start, this->End});
			this->dataGridView1->GridColor = System::Drawing::SystemColors::AppWorkspace;
			this->dataGridView1->Location = System::Drawing::Point(-1, 1);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 70;
			this->dataGridView1->Size = System::Drawing::Size(519, 213);
			this->dataGridView1->TabIndex = 6;
//			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView1_CellContentClick);
			// 
			// No
			// 
			this->No->HeaderText = L"No";
			this->No->Name = L"No";
			this->No->ReadOnly = true;
			// 
			// Description
			// 
			this->Description->HeaderText = L"Description";
			this->Description->Name = L"Description";
			this->Description->ReadOnly = true;
			// 
			// Start
			// 
			this->Start->HeaderText = L"Start";
			this->Start->Name = L"Start";
			this->Start->ReadOnly = true;
			// 
			// End
			// 
			this->End->HeaderText = L"End";
			this->End->Name = L"End";
			this->End->ReadOnly = true;
			// 
			// comboBox1
			// 
			this->comboBox1->AllowDrop = true;
			this->comboBox1->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(6) {L"add", L"delete", L"edit", 
				L"undo", L"redo", L"alternate"});
			this->comboBox1->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->comboBox1->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(42, 220);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(444, 21);
			this->comboBox1->TabIndex = 7;
			this->comboBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::comboBox1_KeyDown);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(519, 297);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->dataGridView1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"iDO";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
private: System::Void comboBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			  //if(e->KeyCode == Keys::Enter)
				 //{
					// comboBox1->Items->Clear();
					// System::String^ str1;
					// str1=comboBox1->Text;
					// StreamWriter ^ AppendText();
					// StreamWriter^ sw1 = gcnew StreamWriter("Input.txt",true);
					// sw1->WriteLine(str1);
					// sw1->Close();



					// StreamReader^ din= File::OpenText ("text2.txt");
					// dataGridView1->RowCount=0;

					// String^ str;
					// int cellIndex=0;
					// //array<datatype*>^ strarray = gcnew array<datatype*>(100);
					// int count=1;
					// if(str=din->ReadLine())
					//	 dataGridView1->Rows[0]->Cells[0]->Value=count.ToString();
					// dataGridView1->Rows[0]->Cells[1]->Value=str;
					// dataGridView1->Rows[0]->Cells[2]->Value=din->ReadLine();
					// dataGridView1->Rows[0]->Cells[3]->Value=din->ReadLine();
					// while ((str = din->ReadLine()) != nullptr) 
					// {

					//	 int cellIndex=0;
					//	 count++;
					//	 //dataGridView1->Rows->Add();
					//	 dataGridView1->Rows[0]->Cells[0]->Value=count.ToString();
					//	 dataGridView1->Rows[0]->Cells[1]->Value=str;
					//	 dataGridView1->Rows[0]->Cells[2]->Value=din->ReadLine();
					//	 dataGridView1->Rows[0]->Cells[3]->Value=din->ReadLine();

					// }
					// din->Close();
				 //
			  //} 
			  if(e->KeyCode == Keys::Enter)
				 {
					 comboBox1->Items->Clear();
					 System::String^ str1;
					 str1=comboBox1->Text;
					 StreamWriter ^ AppendText();
					 StreamWriter^ sw1 = gcnew StreamWriter("Input.txt",true);
					 sw1->WriteLine(str1);
					 sw1->Close();



					 StreamReader^ din= File::OpenText ("text2.txt");
					 dataGridView1->RowCount=0;
					 int countLines=0;
					 while(din->ReadLine()) {
						 countLines++;
					 }
					 countLines/=3;
					 for(int i=0; i<countLines;i++) {
						 dataGridView1->Rows->Add() ;
					 }
					 din->Close();
					 din= File::OpenText ("text2.txt");
					 String^ str;
					 int cellIndex=0;
					 int count=1;
					 for(int i=0;i<countLines;i++)
					 {

						 dataGridView1->Rows[i]->Cells[0]->Value=count.ToString();
						 dataGridView1->Rows[i]->Cells[1]->Value=din->ReadLine();
						 str = din->ReadLine();
						if(str) {
							 dataGridView1->Rows[i]->Cells[2]->Value=str;
						}
						 else {
							 dataGridView1->Rows[i]->Cells[2]->Value=" ";
							 str=din->ReadLine();
						 }
						 if(str) {
							dataGridView1->Rows[i]->Cells[3]->Value=str;
						 }
						 else {
							 dataGridView1->Rows[i]->Cells[3]->Value=" ";
						 }

						 int cellIndex = 0;
						 count++;

					 }
					 din->Close();
				 
			  }
			
		  }

};
}

