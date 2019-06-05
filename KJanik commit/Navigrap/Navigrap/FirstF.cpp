#include "FirstF.h"
using namespace System;
[STAThreadAttribute]

int main()
{
	Windows::Forms::Application::EnableVisualStyles();
	Windows::Forms::Application::Run(gcnew Navigrap::FirstF());
	return 0;
}