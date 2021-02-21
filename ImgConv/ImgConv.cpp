// ImgConv.cpp�: fichier projet principal.

#include "stdafx.h"
#include "Form1.h"

using namespace ImgConv;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Activation des effets visuels de Windows�XP avant la cr�ation de tout contr�le
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Cr�er la fen�tre principale et l'ex�cuter
	if (args->Length==0)
		Application::Run(gcnew Form1());else
	if (args->Length==1)
		Application::Run(gcnew Form1(args[0]));
	else {
		MessageBox::Show("Le programme ne peut traiter qu'un seul fichier � la fois et n'en ouvrira donc qu'un","Fichiers multiples");
		Application::Run(gcnew Form1(args[0]));
	}

	return 0;
}
