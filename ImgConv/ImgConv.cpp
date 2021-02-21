// ImgConv.cpp : fichier projet principal.

#include "stdafx.h"
#include "Form1.h"

using namespace ImgConv;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Activation des effets visuels de Windows XP avant la création de tout contrôle
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Créer la fenêtre principale et l'exécuter
	if (args->Length==0)
		Application::Run(gcnew Form1());else
	if (args->Length==1)
		Application::Run(gcnew Form1(args[0]));
	else {
		MessageBox::Show("Le programme ne peut traiter qu'un seul fichier à la fois et n'en ouvrira donc qu'un","Fichiers multiples");
		Application::Run(gcnew Form1(args[0]));
	}

	return 0;
}
