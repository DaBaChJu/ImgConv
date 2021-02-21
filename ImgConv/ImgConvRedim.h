#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#include "ImgConvApercu.h"

namespace ImgConv {

	/// <summary>
	/// Description résumée de ImgConvRedim
	///
	/// AVERTISSEMENT : si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propriété 'Nom du fichier de ressources' de l'outil de compilation de ressource managée
	///          pour tous les fichiers .resx dont dépend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localisées associées à ce formulaire.
	/// </summary>
	public ref class ImgConvRedim : public System::Windows::Forms::Form {

	/// <summary>
	/// Variables du programme général.
	/// </summary>
	public: ImgConvTools::Bitmap_partage^ image_bitmap;	//image actuellement traitée

	/// <summary>
	///Méthodes de ImgConvApercu
	/// </summary>

	public:		ImgConvRedim::ImgConvRedim(void);
	public:		ImgConvRedim::ImgConvRedim(ImgConvTools::Bitmap_partage^);
	protected:	ImgConvRedim::~ImgConvRedim();
	private:	void ImgConvRedim::InitializeComponent2(void);

	#pragma region Ecouteurs de ImgConvRedim

	private:	void ImgConvRedim::GUI_Redim_bouton_effectuer_tache_Click(System::Object^, System::EventArgs^);
	private: 	void ImgConvRedim::GUI_Redim_liste_SelectedIndexChanged(System::Object^, System::EventArgs^);
	private:	void ImgConvRedim::GUI_Redim_bouton_apercu_Click(System::Object^, System::EventArgs^);

	#pragma endregion

	/// <summary>
	/// Variables nécessaires au concepteur.
	/// </summary>
	private: System::Windows::Forms::ToolTip^  GUI_Redim_toolTip;
	private: System::Windows::Forms::ComboBox^  GUI_Redim_listeTypesRedim;
	private: System::Windows::Forms::Button^  GUI_Redim_bouton_apercu;
	private: System::Windows::Forms::Button^  GUI_Redim_bouton_effectuer_tache;


	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->GUI_Redim_toolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->GUI_Redim_listeTypesRedim = (gcnew System::Windows::Forms::ComboBox());
			this->GUI_Redim_bouton_apercu = (gcnew System::Windows::Forms::Button());
			this->GUI_Redim_bouton_effectuer_tache = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// GUI_Redim_listeTypesRedim
			// 
			this->GUI_Redim_listeTypesRedim->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->GUI_Redim_listeTypesRedim->FormattingEnabled = true;
			this->GUI_Redim_listeTypesRedim->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Etirer avec pixels gris", L"Etirer avec pixels gris inversé", 
				L"Etirer avec pixels gris lumineux", L"Etirer avec pixels gris sombres", L"Ne rien faire"});
			this->GUI_Redim_listeTypesRedim->Location = System::Drawing::Point(52, 13);
			this->GUI_Redim_listeTypesRedim->Name = L"GUI_Redim_listeTypesRedim";
			this->GUI_Redim_listeTypesRedim->Size = System::Drawing::Size(189, 21);
			this->GUI_Redim_listeTypesRedim->TabIndex = 0;
			this->GUI_Redim_listeTypesRedim->SelectedIndexChanged += gcnew System::EventHandler(this, &ImgConvRedim::GUI_Redim_liste_SelectedIndexChanged);
			// 
			// GUI_Redim_bouton_apercu
			// 
			this->GUI_Redim_bouton_apercu->Location = System::Drawing::Point(121, 238);
			this->GUI_Redim_bouton_apercu->Name = L"GUI_Redim_bouton_apercu";
			this->GUI_Redim_bouton_apercu->Size = System::Drawing::Size(51, 23);
			this->GUI_Redim_bouton_apercu->TabIndex = 15;
			this->GUI_Redim_bouton_apercu->Text = L"Aperçu";
			this->GUI_Redim_bouton_apercu->UseVisualStyleBackColor = true;
			this->GUI_Redim_bouton_apercu->Click += gcnew System::EventHandler(this, &ImgConvRedim::GUI_Redim_bouton_apercu_Click);
			// 
			// GUI_Redim_bouton_effectuer_tache
			// 
			this->GUI_Redim_bouton_effectuer_tache->Location = System::Drawing::Point(101, 209);
			this->GUI_Redim_bouton_effectuer_tache->Name = L"GUI_Redim_bouton_effectuer_tache";
			this->GUI_Redim_bouton_effectuer_tache->Size = System::Drawing::Size(90, 23);
			this->GUI_Redim_bouton_effectuer_tache->TabIndex = 14;
			this->GUI_Redim_bouton_effectuer_tache->Text = L"Effectuer tâche";
			this->GUI_Redim_bouton_effectuer_tache->UseVisualStyleBackColor = true;
			this->GUI_Redim_bouton_effectuer_tache->Click += gcnew System::EventHandler(this, &ImgConvRedim::GUI_Redim_bouton_effectuer_tache_Click);
			// 
			// ImgConvRedim
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 273);
			this->Controls->Add(this->GUI_Redim_bouton_apercu);
			this->Controls->Add(this->GUI_Redim_bouton_effectuer_tache);
			this->Controls->Add(this->GUI_Redim_listeTypesRedim);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ImgConvRedim";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Redimensionner image";
			this->ResumeLayout(false);

		}
#pragma endregion

	}; //public ref class ImgConvRedim : public System::Windows::Forms::Form
} //namespace ImgConv
