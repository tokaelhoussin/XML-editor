#pragma once
#include<iostream>
#include <fstream>
#include <sstream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include <bits/stdc++.h>
#include<stack>
#include <math.h>
#include <msclr\marshal_cppstd.h>


namespace CppCLR_WinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Xml;
	using namespace std;
	
	vector <string> lines;
	vector <string> T;
	vector <string> t_l;
	vector<string> ptw;
	vector<string> pt;

	void getpt() {
		pt.resize(0);
		for (int x = 0; x < T.size(); x++) {
			if (!T[x].empty()) {
				if (T[x].find(' ') != std::string::npos) {
					string s = T[x].substr(0, T[x].find(' '));
					pt.push_back(s);
				}
				else {
					pt.push_back(T[x]);
				}
			}
		}
	}

	void getdata() {
		vector<std::string> T_L;
		T.resize(0);
		t_l.resize(0);
		for (int x = 0; x < lines.size(); x++) {
			int tagCounter = std::count(lines[x].begin(), lines[x].end(), '<');
			int t1 = lines[x].find('<');
			int t2 = lines[x].find('>');
			char start = lines[x][t1 + 1];
			if (!((start >= 'a' && start <= 'z') || (start >= 'A' && start <= 'Z') || (start == '/'))) {
				continue;
			}
			for (int m = 0; m < tagCounter; m++) {
				T.push_back(lines[x].substr(t1 + 1, t2 - t1 - 1));
				T_L.push_back(lines[x].substr(t1 + 1, t2 - t1 - 1));
				if (lines[x][t2 + 1] != '<') {
					int temp = lines[x].find('<', t1 + 1);
					T_L.push_back("~" + lines[x].substr(t2 + 1, temp - t2 - 1));
				}
				int t3 = lines[x].find('<', t1 + 1);
				int t4 = lines[x].find('>', t2 + 1);
				t1 = t3;
				t2 = t4;
			}
		}
		for (int x = 0; x < T_L.size(); x++) {
			if (!((T_L[x][0] == '~') && (T_L[x].length() == 1))) { t_l.push_back(T_L[x]); }
		}
	}

	void getptw() {
		ptw.resize(0);
		for (int x = 0; x < t_l.size(); x++) {
			if (t_l[x][0] == '/') {
				ptw.push_back(t_l[x].substr(1, t_l[x].length() - 1));
			}
			else {
				if (t_l[x][0] != '~') {
					ptw.push_back(t_l[x]);
				}
				else { ptw.push_back(t_l[x]); }
			}
		}
	}


	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		
		String^ filepath;
		StreamReader^ x ;
		String^ text;
		OpenFileDialog^ openfileDialog1;
	private: System::Windows::Forms::TextBox^  textBox1;
	public:
		bool checkCorrectXml;
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
		void Form1::SomeFunction()
		{
			
			// fill input from GUI
		
			
			// modify GUI using output
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Label^  label2;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(529, 318);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(129, 53);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add File";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(11, 55);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(399, 709);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox1_TextChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->richTextBox1);
			this->groupBox1->Location = System::Drawing::Point(1, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(442, 753);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 35);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 17);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Xml file";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Location = System::Drawing::Point(477, 393);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			this->groupBox2->Size = System::Drawing::Size(228, 359);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Visible = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->Location = System::Drawing::Point(23, 39);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(183, 70);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Check Xml for errors";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button5->Location = System::Drawing::Point(23, 304);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(76, 34);
			this->button5->TabIndex = 9;
			this->button5->Text = L"Restart";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button3->Location = System::Drawing::Point(23, 134);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(183, 70);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Show errors correction";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button4->Location = System::Drawing::Point(23, 226);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(183, 70);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Convert Xml to Json";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->groupBox3->Controls->Add(this->richTextBox2);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Location = System::Drawing::Point(725, 12);
			this->groupBox3->Margin = System::Windows::Forms::Padding(4);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(4);
			this->groupBox3->Size = System::Drawing::Size(511, 753);
			this->groupBox3->TabIndex = 12;
			this->groupBox3->TabStop = false;
			this->groupBox3->Visible = false;
			this->groupBox3->Enter += gcnew System::EventHandler(this, &Form1::groupBox3_Enter);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(28, 55);
			this->richTextBox2->Margin = System::Windows::Forms::Padding(4);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::ForcedBoth;
			this->richTextBox2->Size = System::Drawing::Size(460, 693);
			this->richTextBox2->TabIndex = 3;
			this->richTextBox2->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 34);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Output";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(477, 127);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(228, 22);
			this->textBox1->TabIndex = 13;
			this->textBox1->Visible = false;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1249, 799);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		openfileDialog1 = gcnew OpenFileDialog;
		openfileDialog1->ShowDialog();
		filepath = openfileDialog1->FileName;

		x = gcnew StreamReader(filepath);
		text = x->ReadToEnd();
		richTextBox1->Text = text;
		groupBox1->Visible = true;
		groupBox2->Visible = true;
		label1->Visible = true;
		label1->Text = "Xml file";
		button1->Visible = false;
	}
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		




}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	
		
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	

}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	
	richTextBox1->Clear();
	richTextBox2->Clear();
	label1->Visible = false;
	label2->Visible = false;
	textBox1->Visible = false;
	button1->Visible = true;
	groupBox2->Visible = false;
	button3->Visible = false;
	lines.clear();
	lines1.clear();
	lines2.clear();
	T.clear();   
	t_l.clear();  
	ptw.clear();
	pt.clear();
	mistakes.clear();
	tagsMC.clear();
	mistakeCase.clear();
	tags.clear();
	tagsAndLines.clear();
	pureTags.clear();
	//Node = {};
	Node* current_root = NULL;
	Node* children = NULL;
	
}
private: System::Void groupBox3_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
