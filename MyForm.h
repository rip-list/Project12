#pragma once
#include <sqlite3.h>
#include <string>
#include <msclr/marshal_cppstd.h> 


namespace Project12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	sqlite3* db = nullptr;
	/// <summary>
	/// ������ ��� MyForm&
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			if (sqlite3_open("database.db", &db) != SQLITE_OK) {
				MessageBox::Show("������ �������� ���� ������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}


			RefreshDataGridView();

			const char* createTableSQL =
				"CREATE TABLE IF NOT EXISTS Personal ("
				"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
				"FIO TEXT NOT NULL,"
				"Position TEXT NOT NULL,"
				"Departament TEXT NOT NULL,"
				"People TEXT NOT NULL,"
				"Salary REAL NOT NULL);";
			char* errMsg;
			if (sqlite3_exec(db, createTableSQL, 0, 0, &errMsg) != SQLITE_OK) {
				MessageBox::Show(gcnew String(errMsg), "������ SQL", MessageBoxButtons::OK, MessageBoxIcon::Error);
				sqlite3_free(errMsg);
			}

		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm() {
			if (db != nullptr) {
				sqlite3_close(db);
			}

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonEdit;
	protected:

	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ fiotextBox;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ buttonDelete;
	private: System::Windows::Forms::Button^ importData;







	private: System::Windows::Forms::Button^ button5;





	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;




	private: System::Windows::Forms::TextBox^ salaryBox;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ����������;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ���������;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ �����;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ��������;



	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->fiotextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->���������� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->��������� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->����� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->�������� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->importData = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->salaryBox = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonEdit
			// 
			this->buttonEdit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonEdit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonEdit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->buttonEdit->Location = System::Drawing::Point(195, 271);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(139, 30);
			this->buttonEdit->TabIndex = 0;
			this->buttonEdit->Text = L"�������������";
			this->buttonEdit->UseVisualStyleBackColor = true;
			this->buttonEdit->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button2->Location = System::Drawing::Point(49, 280);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(94, 49);
			this->button2->TabIndex = 1;
			this->button2->Text = L"������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// fiotextBox
			// 
			this->fiotextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->fiotextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->fiotextBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->fiotextBox->Location = System::Drawing::Point(581, 68);
			this->fiotextBox->Multiline = true;
			this->fiotextBox->Name = L"fiotextBox";
			this->fiotextBox->Size = System::Drawing::Size(168, 28);
			this->fiotextBox->TabIndex = 2;
			this->fiotextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"AcadEref", 26.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label1->Location = System::Drawing::Point(192, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(163, 37);
			this->label1->TabIndex = 3;
			this->label1->Text = L"��������";
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->ID, this->����������,
					this->���������, this->�����, this->��������
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dataGridView1->Location = System::Drawing::Point(12, 66);
			this->dataGridView1->Name = L"dataGridView1";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->Size = System::Drawing::Size(563, 186);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellClick);
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			// 
			// ����������
			// 
			this->����������->HeaderText = L"����������";
			this->����������->Name = L"����������";
			// 
			// ���������
			// 
			this->���������->HeaderText = L"���������";
			this->���������->Name = L"���������";
			// 
			// �����
			// 
			this->�����->HeaderText = L"�����";
			this->�����->Name = L"�����";
			// 
			// ��������
			// 
			this->��������->HeaderText = L"��������";
			this->��������->Name = L"��������";
			// 
			// buttonDelete
			// 
			this->buttonDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDelete->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->buttonDelete->Location = System::Drawing::Point(340, 271);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(139, 30);
			this->buttonDelete->TabIndex = 5;
			this->buttonDelete->Text = L"�������";
			this->buttonDelete->UseVisualStyleBackColor = true;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &MyForm::buttonDelete_Click);
			// 
			// importData
			// 
			this->importData->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->importData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->importData->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->importData->Location = System::Drawing::Point(195, 307);
			this->importData->Name = L"importData";
			this->importData->Size = System::Drawing::Size(139, 30);
			this->importData->TabIndex = 6;
			this->importData->Text = L"������";
			this->importData->UseVisualStyleBackColor = true;
			this->importData->Click += gcnew System::EventHandler(this, &MyForm::importData_Click);
			// 
			// button5
			// 
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button5->Location = System::Drawing::Point(340, 307);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(139, 30);
			this->button5->TabIndex = 7;
			this->button5->Text = L"�������� ";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button6->Location = System::Drawing::Point(771, 3);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(27, 28);
			this->button6->TabIndex = 8;
			this->button6->Text = L"X\r\n";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->comboBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"��. �����", L"���. ������", L"�����", L"������",
					L"�����", L"��������", L"������", L"���. ��������"
			});
			this->comboBox1->Location = System::Drawing::Point(581, 104);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(168, 28);
			this->comboBox1->TabIndex = 9;
			// 
			// comboBox2
			// 
			this->comboBox2->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->comboBox2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"�����������", L"�����", L"���", L"���" });
			this->comboBox2->Location = System::Drawing::Point(581, 143);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(168, 28);
			this->comboBox2->TabIndex = 10;
			// 
			// salaryBox
			// 
			this->salaryBox->AccessibleDescription = L"��������";
			this->salaryBox->AllowDrop = true;
			this->salaryBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->salaryBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->salaryBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->salaryBox->ImeMode = System::Windows::Forms::ImeMode::On;
			this->salaryBox->Location = System::Drawing::Point(581, 185);
			this->salaryBox->Multiline = true;
			this->salaryBox->Name = L"salaryBox";
			this->salaryBox->Size = System::Drawing::Size(168, 28);
			this->salaryBox->TabIndex = 11;
			this->salaryBox->Tag = L"��������";
			this->salaryBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(810, 423);
			this->Controls->Add(this->salaryBox);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->importData);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->fiotextBox);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->buttonEdit);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->Text = L" ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}


private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// ���������, ������� �� ������
	if (dataGridView1->SelectedRows->Count > 0) {
		DataGridViewRow^ row = dataGridView1->SelectedRows[0];

		// �������� �������� ID �� ��������� ������
		String^ id = row->Cells[0]->Value->ToString();

		// ���������, ��� ID �� ������
		if (String::IsNullOrWhiteSpace(id)) {
			MessageBox::Show("�� ������� �������� ������������� ������ ��� ��������������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		// �������� ����� �������� �� ��������� �����
		String^ fio = fiotextBox->Text;
		String^ position = comboBox1->Text;
		String^ departament = comboBox2->Text;
		String^ salary = salaryBox->Text;

		// ���������, ��� ��� ���� ���������
		if (String::IsNullOrWhiteSpace(fio) || String::IsNullOrWhiteSpace(position) ||
			String::IsNullOrWhiteSpace(departament) || String::IsNullOrWhiteSpace(salary)) {
			MessageBox::Show("����������, ��������� ��� ����.", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// SQL-������ ��� ���������� ������
		std::string updateSQL = "UPDATE Personal SET FIO = ?, Position = ?, Departament = ?, Salary = ? WHERE ID = ?";
		sqlite3_stmt* stmt;

		// �������������� �����
		std::string fioStr = msclr::interop::marshal_as<std::string>(fio);
		std::string positionStr = msclr::interop::marshal_as<std::string>(position);
		std::string departamentStr = msclr::interop::marshal_as<std::string>(departament);
		double salaryVal = 0;

		try {
			salaryVal = System::Convert::ToDouble(salary, System::Globalization::CultureInfo::InvariantCulture);
		}
		catch (System::FormatException^) {
			MessageBox::Show("������ ����� ������ � ���� '��������'.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		int idVal = System::Convert::ToInt32(id);

		// ���������� �������
		if (sqlite3_prepare_v2(db, updateSQL.c_str(), -1, &stmt, 0) == SQLITE_OK) {
			sqlite3_bind_text(stmt, 1, fioStr.c_str(), -1, SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, positionStr.c_str(), -1, SQLITE_STATIC);
			sqlite3_bind_text(stmt, 3, departamentStr.c_str(), -1, SQLITE_STATIC);
			sqlite3_bind_double(stmt, 4, salaryVal);
			sqlite3_bind_int(stmt, 5, idVal);

			// ���������� �������
			if (sqlite3_step(stmt) == SQLITE_DONE) {
				MessageBox::Show("������ ������� ���������.", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);
				RefreshDataGridView();
			}
			else {
				MessageBox::Show("������ ��� ���������� ������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			// ���������� �������
			sqlite3_finalize(stmt);
		}
		else {
			MessageBox::Show("������ SQL ��� ���������� �������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else {
		MessageBox::Show("����������, �������� ������ ��� ��������������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}


private: void RefreshDataGridView() {
	// Clear the current DataGridView data
	dataGridView1->Rows->Clear();

	// Query the updated data from the database and fill the DataGridView
	const char* selectSQL = "SELECT * FROM Personal";
	sqlite3_stmt* stmt;
	if (sqlite3_prepare_v2(db, selectSQL, -1, &stmt, 0) == SQLITE_OK) {
		while (sqlite3_step(stmt) == SQLITE_ROW) {
			String^ id = gcnew String(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
			String^ fio = gcnew String(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
			String^ position = gcnew String(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
			String^ departament = gcnew String(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
			String^ salary = gcnew String(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));

			// Add a new row to the DataGridView
			dataGridView1->Rows->Add(id, fio, position, departament, salary);
		}
		sqlite3_finalize(stmt);
	}
	else {
		MessageBox::Show("������ ��� ��������� ������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}


private: System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	// Check if a row is selected
	if (dataGridView1->SelectedRows->Count > 0) {
		DataGridViewRow^ row = dataGridView1->SelectedRows[0];
		// Get the ID of the selected row
		String^ id = row->Cells[0]->Value->ToString();
		// Prepare SQL statement to delete the row
		std::string deleteSQL = "DELETE FROM Personal WHERE ID = ?";
		sqlite3_stmt* stmt;
		// Convert .NET string to C++ string
		int idVal = Convert::ToInt32(id);
		// Prepare the SQLite statement
		if (sqlite3_prepare_v2(db, deleteSQL.c_str(), -1, &stmt, 0) == SQLITE_OK) {
			sqlite3_bind_int(stmt, 1, idVal);
			// Execute the SQL statement
			if (sqlite3_step(stmt) != SQLITE_DONE) {
				MessageBox::Show("������ ��� �������� ������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else {
				MessageBox::Show("������ ������� �������", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);
				// Refresh the DataGridView
				RefreshDataGridView();
			}
			// Finalize the prepared statement
			sqlite3_finalize(stmt);
		}
		else {
			MessageBox::Show("������ SQL ��� ���������� �������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	else {
		MessageBox::Show("����������, �������� ������ ��� ��������", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}


private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	// ���������, ��� ���� ������� ������, � �� ��������� �������
	if (e->RowIndex >= 0) {
		// �������� ��������� ������
		DataGridViewRow^ row = dataGridView1->Rows[e->RowIndex];

		// ��������� ��������� ���� ������� �� ��������� ������
		fiotextBox->Text = row->Cells[1]->Value != nullptr ? row->Cells[1]->Value->ToString() : "";
		comboBox1->Text = row->Cells[2]->Value != nullptr ? row->Cells[2]->Value->ToString() : "";
		comboBox2->Text = row->Cells[3]->Value != nullptr ? row->Cells[3]->Value->ToString() : "";
		salaryBox->Text = row->Cells[4]->Value != nullptr ? row->Cells[4]->Value->ToString() : "";
	}
}




	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// Get the values from the TextBoxes
		String^ fio = fiotextBox->Text;
		String^ position = comboBox1->Text;
		String^ departament = comboBox2->Text;
		String^ salary = salaryBox->Text;
		// Check if the TextBoxes are empty
		if (fio == "" || position == "" || departament == "" || salary == "") {
			MessageBox::Show("����������, ��������� ��� ����", "������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		// Prepare SQL statement to insert data
		std::string insertSQL = "INSERT INTO Personal (FIO, Position, Departament, Salary) VALUES (?, ?, ?, ?)";
		sqlite3_stmt* stmt;
		// Convert .NET strings to C++ strings
		std::string fioStr = msclr::interop::marshal_as<std::string>(fio);
		std::string positionStr = msclr::interop::marshal_as<std::string>(position);
		std::string departamentStr = msclr::interop::marshal_as<std::string>(departament);
		double salaryVal = System::Convert::ToDouble(salary, System::Globalization::CultureInfo::InvariantCulture);

		// Prepare the SQLite statement
		if (sqlite3_prepare_v2(db, insertSQL.c_str(), -1, &stmt, 0) == SQLITE_OK) {
			sqlite3_bind_text(stmt, 1, fioStr.c_str(), -1, SQLITE_STATIC);
			sqlite3_bind_text(stmt, 2, positionStr.c_str(), -1, SQLITE_STATIC);
			sqlite3_bind_text(stmt, 3, departamentStr.c_str(), -1, SQLITE_STATIC);
			sqlite3_bind_double(stmt, 4, salaryVal);
			// Execute the SQL statement
			if (sqlite3_step(stmt) != SQLITE_DONE) {
				String^ errorMessage = gcnew String(sqlite3_errmsg(db));
				MessageBox::Show("������ ��� ���������� ������: " + errorMessage, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			
				RefreshDataGridView();
			// Finalize the prepared statement
			sqlite3_finalize(stmt);
		}
		
	}

private: System::Void importData_Click(System::Object^ sender, System::EventArgs^ e) {
	// Check if the file exists
	if (!System::IO::File::Exists("data.csv")) {
		MessageBox::Show("���� 'data.csv' �� ������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Read the file
	System::IO::StreamReader^ file = gcnew System::IO::StreamReader("data.csv");
	// Read the file line by line
	int lineCount = 0;
	while (!file->EndOfStream) {
		String^ line = file->ReadLine();
		array<String^>^ columns = line->Split(',');

		// Check if the line has 4 columns
		if (columns->Length == 4) {
			// Prepare SQL statement to insert data
			std::string insertSQL = "INSERT INTO Personal (FIO, Position, Departament, Salary) VALUES (?, ?, ?, ?)";
			sqlite3_stmt* stmt;

			// Convert .NET strings to C++ strings
			std::string fioStr = msclr::interop::marshal_as<std::string>(gcnew System::String(columns[0]->ToCharArray()));

			std::string positionStr = msclr::interop::marshal_as<std::string>(gcnew System::String(columns[1]->ToCharArray()));
			std::string departamentStr = msclr::interop::marshal_as<std::string>(gcnew System::String(columns[2]->ToCharArray())); // Changed to columns[2] for Departament
			double salaryVal = 0;

			try {
				salaryVal = System::Convert::ToDouble(columns[3], System::Globalization::CultureInfo::InvariantCulture);
			}
			catch (System::FormatException^) {
				MessageBox::Show("������ ������� ������ � ������ CSV: " + line, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
				continue;  // Skip this line if salary is invalid
			}

			// Prepare the SQLite statement
			if (sqlite3_prepare_v2(db, insertSQL.c_str(), -1, &stmt, 0) == SQLITE_OK) {
				sqlite3_bind_text(stmt, 1, fioStr.c_str(), -1, SQLITE_STATIC);
				sqlite3_bind_text(stmt, 2, positionStr.c_str(), -1, SQLITE_STATIC);
				sqlite3_bind_text(stmt, 3, departamentStr.c_str(), -1, SQLITE_STATIC);
				sqlite3_bind_double(stmt, 4, salaryVal);

				// Execute the SQL statement
				if (sqlite3_step(stmt) != SQLITE_DONE) {
					String^ errorMessage = gcnew String(sqlite3_errmsg(db));
					MessageBox::Show("������ ��� ���������� ������: " + errorMessage, "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}

				// Finalize the prepared statement
				sqlite3_finalize(stmt);
				lineCount++;
			}
			else {
				MessageBox::Show("������ SQL ��� ���������� �������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	file->Close();

	// Show message after import is complete
	MessageBox::Show("������ ��������. ��������� " + lineCount + " �������.", "�����", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	// Clear the TextBoxes
	fiotextBox->Text = "";
	comboBox1->Text = "";
	comboBox2->Text = "";
	salaryBox->Text = "";
	//clear datagridviwe 
}
};
}
