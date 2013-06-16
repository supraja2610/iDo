#pragma once
#using<system.dll>
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
	private: System::Windows::Forms::TextBox^  textBox2;

	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  No;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Description;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Start;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  End;





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
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->No = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Description = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Start = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->End = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 264);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(224, 20);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"Enter Command";
			//this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(242, 261);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(29, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"..";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(489, 81);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(30, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->No, this->Description, 
				this->Start, this->End});
			this->dataGridView1->GridColor = System::Drawing::SystemColors::AppWorkspace;
			this->dataGridView1->Location = System::Drawing::Point(-4, 36);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(487, 202);
			this->dataGridView1->TabIndex = 6;
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
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(519, 297);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"iDO";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


				 System::String^ s;
				 s=textBox2->Text;
				 StreamWriter ^ AppendText();
				StreamWriter^ sw = gcnew StreamWriter("Input.txt",true);
				 sw->WriteLine(s);
				 sw->Close();
		
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	  StreamReader^ din= File::OpenText ("text2.txt");
	  String^ str;
	  int cellIndex=0;
	  //array<datatype*>^ strarray = gcnew array<datatype*>(100);
	  int count=1;
	  if(str=din->ReadLine())
			  dataGridView1->Rows[0]->Cells[0]->Value=count.ToString();
			  dataGridView1->Rows[0]->Cells[1]->Value=str;
			  dataGridView1->Rows[0]->Cells[2]->Value=din->ReadLine();
			  dataGridView1->Rows[0]->Cells[3]->Value=din->ReadLine();
	  while ((str = din->ReadLine()) != nullptr) 
		  {

		      int cellIndex=0;
			  count++;
			  dataGridView1->Rows->Add();
			  dataGridView1->Rows[0]->Cells[0]->Value=count.ToString();
			  dataGridView1->Rows[0]->Cells[1]->Value=str;
			  dataGridView1->Rows[0]->Cells[2]->Value=din->ReadLine();
			  dataGridView1->Rows[0]->Cells[3]->Value=din->ReadLine();
			
     }
	 din->Close();
   }

};
}

