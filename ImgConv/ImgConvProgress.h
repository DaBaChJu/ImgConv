#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ImgConv {

	/// <summary>
	/// Description résumée de ImgConvProgress
	///
	/// AVERTISSEMENT : si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propriété 'Nom du fichier de ressources' de l'outil de compilation de ressource managée
	///          pour tous les fichiers .resx dont dépend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localisées associées à ce formulaire.
	/// </summary>
	public ref class ImgConvProgress : public System::Windows::Forms::Form {

	public:
		/// <summary>
		/// Constructeur par défaut
		/// </summary>
		ImgConvProgress(void) {
			InitializeComponent();
		}

	public:
		/// <summary>
		/// Constructeur personnalisé
		/// </summary>
		ImgConvProgress(int valeur_maximum) {
			InitializeComponent();
			GUI_progressform_progressBar1->Maximum=valeur_maximum;
			GUI_progressform_progressBar1->Value=0;
/*
			while (valeur_progression->valeur < valeur_maximum) {
				if( valeur_progression->valeur > GUI_progressform_progressBar1->Value)
					GUI_progressform_progressBar1->PerformStep();
			}
			GUI_progressform_progressBar1->PerformStep();

			GUI_progressform_bouton_annuler->Text::set("Ok");
			this->AcceptButton::set(GUI_progressform_bouton_annuler);
*/

		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~ImgConvProgress() {
			if (components) {
				delete components;
			}
		}

	/// <summary>
	/// Variables du concepteur.
	/// </summary>
	private: System::Windows::Forms::ProgressBar^  GUI_progressform_progressBar1;
	private: System::Windows::Forms::Label^  GUI_progressform_textefixe;
	private: System::Windows::Forms::Label^  GUI_progressform_textevariable;
	private: System::Windows::Forms::Label^  GUI_progressform_textefixe2;



	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void) {
			this->GUI_progressform_progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->GUI_progressform_textefixe = (gcnew System::Windows::Forms::Label());
			this->GUI_progressform_textevariable = (gcnew System::Windows::Forms::Label());
			this->GUI_progressform_textefixe2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// GUI_progressform_progressBar1
			// 
			this->GUI_progressform_progressBar1->Location = System::Drawing::Point(12, 18);
			this->GUI_progressform_progressBar1->Name = L"GUI_progressform_progressBar1";
			this->GUI_progressform_progressBar1->Size = System::Drawing::Size(268, 42);
			this->GUI_progressform_progressBar1->TabIndex = 0;
			// 
			// GUI_progressform_textefixe
			// 
			this->GUI_progressform_textefixe->AutoSize = true;
			this->GUI_progressform_textefixe->Location = System::Drawing::Point(63, 79);
			this->GUI_progressform_textefixe->Margin = System::Windows::Forms::Padding(0);
			this->GUI_progressform_textefixe->Name = L"GUI_progressform_textefixe";
			this->GUI_progressform_textefixe->Size = System::Drawing::Size(65, 13);
			this->GUI_progressform_textefixe->TabIndex = 1;
			this->GUI_progressform_textefixe->Text = L"Progression:";
			// 
			// GUI_progressform_textevariable
			// 
			this->GUI_progressform_textevariable->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->GUI_progressform_textevariable->AutoSize = true;
			this->GUI_progressform_textevariable->Location = System::Drawing::Point(128, 79);
			this->GUI_progressform_textevariable->Margin = System::Windows::Forms::Padding(0);
			this->GUI_progressform_textevariable->Name = L"GUI_progressform_textevariable";
			this->GUI_progressform_textevariable->Size = System::Drawing::Size(13, 13);
			this->GUI_progressform_textevariable->TabIndex = 2;
			this->GUI_progressform_textevariable->Text = L"0";
			// 
			// GUI_progressform_textefixe2
			// 
			this->GUI_progressform_textefixe2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->GUI_progressform_textefixe2->AutoSize = true;
			this->GUI_progressform_textefixe2->Location = System::Drawing::Point(141, 79);
			this->GUI_progressform_textefixe2->Margin = System::Windows::Forms::Padding(0);
			this->GUI_progressform_textefixe2->Name = L"GUI_progressform_textefixe2";
			this->GUI_progressform_textefixe2->Size = System::Drawing::Size(15, 13);
			this->GUI_progressform_textefixe2->TabIndex = 3;
			this->GUI_progressform_textefixe2->Text = L"%";
			// 
			// ImgConvProgress
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 114);
			this->ControlBox = false;
			this->Controls->Add(this->GUI_progressform_textefixe2);
			this->Controls->Add(this->GUI_progressform_textevariable);
			this->Controls->Add(this->GUI_progressform_textefixe);
			this->Controls->Add(this->GUI_progressform_progressBar1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"ImgConvProgress";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Progression de l\'opération";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion //Windows Form Designer generated code

#pragma region Fonctions permettant une manipulation externe

	public:
		/// <summary>
		/// Augmente la progression de la barre
		/// </summary>
		void AugmenteProgression(int nProgress) {
			GUI_progressform_progressBar1->Step=nProgress-GUI_progressform_progressBar1->Value;
			GUI_progressform_progressBar1->PerformStep();
			GUI_progressform_textevariable->Text::set( ( (100*GUI_progressform_progressBar1->Value) / GUI_progressform_progressBar1->Maximum ).ToString() );
		}

	public:
		/// <summary>
		/// Ferme la barre de progression
		/// </summary>
		void FinirProgression() {
			GUI_progressform_progressBar1->Step=(GUI_progressform_progressBar1->Maximum-GUI_progressform_progressBar1->Value)/3;
			GUI_progressform_progressBar1->PerformStep();
			GUI_progressform_textevariable->Text::set( ( (100*GUI_progressform_progressBar1->Value) / GUI_progressform_progressBar1->Maximum ).ToString() );
			GUI_progressform_progressBar1->PerformStep();
			GUI_progressform_textevariable->Text::set( ( (100*GUI_progressform_progressBar1->Value) / GUI_progressform_progressBar1->Maximum ).ToString() );
			GUI_progressform_progressBar1->PerformStep();
			GUI_progressform_textevariable->Text::set("100");
			this->Close();
		}

#pragma endregion //Fonctions permettant une manipulation externe

	}; //public ref class ImgConvProgress : public System::Windows::Forms::Form
} //namespace ImgConv
