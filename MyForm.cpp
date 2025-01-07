#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project12::MyForm form; //«аменить при необходимости им€ проекта, на текущее им€, которое дано при его создании  
	Application::Run(% form);
}