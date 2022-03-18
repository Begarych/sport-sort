#pragma once

#include "Players.h"
#include <msclr/marshal_cppstd.h>



	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Form1 : public System::Windows::Forms::Form
	{


	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  closeButton;
	private: System::Windows::Forms::DataGridView^  dataGridView1;


	private: System::Windows::Forms::Button^  saveButton;
	private: System::Windows::Forms::Button^  loadButton;







	private: System::Windows::Forms::TextBox^  familyTextBox;
	private: System::Windows::Forms::TextBox^  nameTextBox;
	private: System::Windows::Forms::TextBox^  secondNameTextBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  searchButton;
	private: System::Windows::Forms::Button^  sortButton;
	private: System::Windows::Forms::ComboBox^  sortComboBox;

	private: System::Windows::Forms::Button^  deleteButton;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  familyNameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  nameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  secondNameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ageColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  weightColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  heightColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  playerNumberColumn;


	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->closeButton = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->familyNameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->nameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->secondNameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ageColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->weightColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->heightColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->playerNumberColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->loadButton = (gcnew System::Windows::Forms::Button());
			this->familyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->secondNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->sortButton = (gcnew System::Windows::Forms::Button());
			this->sortComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// closeButton
			// 
			this->closeButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->closeButton->Location = System::Drawing::Point(1003, 328);
			this->closeButton->Name = L"closeButton";
			this->closeButton->Size = System::Drawing::Size(75, 23);
			this->closeButton->TabIndex = 0;
			this->closeButton->Text = L"Выход";
			this->closeButton->UseVisualStyleBackColor = true;
			this->closeButton->Click += gcnew System::EventHandler(this, &Form1::closeButton_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->familyNameColumn,
					this->nameColumn, this->secondNameColumn, this->ageColumn, this->weightColumn, this->heightColumn, this->playerNumberColumn
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 41);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(985, 281);
			this->dataGridView1->TabIndex = 1;
			// 
			// familyNameColumn
			// 
			this->familyNameColumn->HeaderText = L"Фамилия";
			this->familyNameColumn->Name = L"familyNameColumn";
			this->familyNameColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// nameColumn
			// 
			this->nameColumn->HeaderText = L"Имя";
			this->nameColumn->Name = L"nameColumn";
			this->nameColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// secondNameColumn
			// 
			this->secondNameColumn->HeaderText = L"Отчество";
			this->secondNameColumn->Name = L"secondNameColumn";
			this->secondNameColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// ageColumn
			// 
			this->ageColumn->HeaderText = L"Возраст";
			this->ageColumn->Name = L"ageColumn";
			this->ageColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// weightColumn
			// 
			this->weightColumn->HeaderText = L"Вес";
			this->weightColumn->Name = L"weightColumn";
			this->weightColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// heightColumn
			// 
			this->heightColumn->HeaderText = L"Рост";
			this->heightColumn->Name = L"heightColumn";
			this->heightColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// playerNumberColumn
			// 
			this->playerNumberColumn->HeaderText = L"Номер";
			this->playerNumberColumn->Name = L"playerNumberColumn";
			this->playerNumberColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// saveButton
			// 
			this->saveButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->saveButton->Location = System::Drawing::Point(1003, 76);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(75, 23);
			this->saveButton->TabIndex = 2;
			this->saveButton->Text = L"Сохранить";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &Form1::saveButton_Click);
			// 
			// loadButton
			// 
			this->loadButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->loadButton->Location = System::Drawing::Point(1003, 49);
			this->loadButton->Name = L"loadButton";
			this->loadButton->Size = System::Drawing::Size(75, 21);
			this->loadButton->TabIndex = 3;
			this->loadButton->Text = L"Загрузить";
			this->loadButton->UseVisualStyleBackColor = true;
			this->loadButton->Click += gcnew System::EventHandler(this, &Form1::loadButton_Click);
			// 
			// familyTextBox
			// 
			this->familyTextBox->Location = System::Drawing::Point(155, 14);
			this->familyTextBox->Name = L"familyTextBox";
			this->familyTextBox->Size = System::Drawing::Size(197, 20);
			this->familyTextBox->TabIndex = 4;
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(393, 14);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(222, 20);
			this->nameTextBox->TabIndex = 5;
			// 
			// secondNameTextBox
			// 
			this->secondNameTextBox->Location = System::Drawing::Point(681, 14);
			this->secondNameTextBox->Name = L"secondNameTextBox";
			this->secondNameTextBox->Size = System::Drawing::Size(246, 20);
			this->secondNameTextBox->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(93, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Фамилия";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(358, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Имя";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(621, 17);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Отчество";
			// 
			// searchButton
			// 
			this->searchButton->Location = System::Drawing::Point(12, 12);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(75, 23);
			this->searchButton->TabIndex = 10;
			this->searchButton->Text = L"Найти";
			this->searchButton->UseVisualStyleBackColor = true;
			this->searchButton->Click += gcnew System::EventHandler(this, &Form1::searchButton_Click);
			// 
			// sortButton
			// 
			this->sortButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->sortButton->Location = System::Drawing::Point(12, 328);
			this->sortButton->Name = L"sortButton";
			this->sortButton->Size = System::Drawing::Size(85, 23);
			this->sortButton->TabIndex = 11;
			this->sortButton->Text = L"Сортировать";
			this->sortButton->UseVisualStyleBackColor = true;
			this->sortButton->Click += gcnew System::EventHandler(this, &Form1::sortButton_Click);
			// 
			// sortComboBox
			// 
			this->sortComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->sortComboBox->FormattingEnabled = true;
			this->sortComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"по имени", L"по фамилии", L"по отчеству",
					L"по возрасту", L"по весу", L"по росту", L"по номеру"
			});
			this->sortComboBox->Location = System::Drawing::Point(113, 328);
			this->sortComboBox->Name = L"sortComboBox";
			this->sortComboBox->Size = System::Drawing::Size(239, 21);
			this->sortComboBox->TabIndex = 12;
			// 
			// deleteButton
			// 
			this->deleteButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->deleteButton->Location = System::Drawing::Point(1004, 105);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(75, 23);
			this->deleteButton->TabIndex = 13;
			this->deleteButton->Text = L"Удалить";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &Form1::deleteButton_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1090, 363);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->sortComboBox);
			this->Controls->Add(this->sortButton);
			this->Controls->Add(this->searchButton);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->secondNameTextBox);
			this->Controls->Add(this->nameTextBox);
			this->Controls->Add(this->familyTextBox);
			this->Controls->Add(this->loadButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->closeButton);
			this->Name = L"Form1";
			this->Text = L"Sport v2.0";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
   

	private: System::Void closeButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void loadButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: void SetUIData(const std::vector<Player>& players);

	private: std::vector<Player> GetUIData();

	private: System::Void saveButton_Click(System::Object^  sender, System::EventArgs^  e);


	private: System::Void searchButton_Click(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void deleteButton_Click(System::Object^  sender, System::EventArgs^  e);

	private: System::Void sortButton_Click(System::Object^  sender, System::EventArgs^  e);
};

