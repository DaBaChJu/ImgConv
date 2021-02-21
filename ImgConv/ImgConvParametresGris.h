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
	/// Description résumée de ImgConvParametresGris
	///
	/// AVERTISSEMENT : si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propriété 'Nom du fichier de ressources' de l'outil de compilation de ressource managée
	///          pour tous les fichiers .resx dont dépend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localisées associées à ce formulaire.
	/// </summary>

public ref class ImgConvParametresGris : public System::Windows::Forms::Form {

	public:
		ImgConvParametresGris(void) {
			InitializeComponent();
			InitializeComponent2();
		}

	public:
		ImgConvParametresGris(System::Drawing::Bitmap^ source) {
			InitializeComponent();
			image_bitmap=source;
			InitializeComponent2();
		}


	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~ImgConvParametresGris() {
			if (components) {
				delete components;
			}
		}

    /// <summary>
	/// Variables du programme général.
	/// </summary>
	public: Bitmap^ image_bitmap;	//image actuellement traitée

	/// <summary>
	/// Variables nécessaires au concepteur.
	/// </summary>

	private: System::Windows::Forms::Label^  GUI_paramsgris_label;
	private: System::Windows::Forms::ToolTip^  GUI_params_toolTip1;
	private: System::Windows::Forms::Button^  GUI_params_bouton_apercu;
	private: System::Windows::Forms::Button^  GUI_params_bouton_effectuer_tache;
	private: System::Windows::Forms::ListBox^  GUI_paramsgris_liste;

 	/// <summary>
	/// Variable nécessaire au concepteur.
	/// </summary>
	private: 
		System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->GUI_paramsgris_label = (gcnew System::Windows::Forms::Label());
			this->GUI_params_toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->GUI_params_bouton_apercu = (gcnew System::Windows::Forms::Button());
			this->GUI_params_bouton_effectuer_tache = (gcnew System::Windows::Forms::Button());
			this->GUI_paramsgris_liste = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// GUI_paramsgris_label
			// 
			this->GUI_paramsgris_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GUI_paramsgris_label->AutoSize = true;
			this->GUI_paramsgris_label->Location = System::Drawing::Point(11, 9);
			this->GUI_paramsgris_label->Name = L"GUI_paramsgris_label";
			this->GUI_paramsgris_label->Size = System::Drawing::Size(212, 13);
			this->GUI_paramsgris_label->TabIndex = 0;
			this->GUI_paramsgris_label->Text = L"Types de transformation en gris disponibles:";
			// 
			// GUI_params_toolTip1
			// 
			this->GUI_params_toolTip1->AutoPopDelay = 10000;
			this->GUI_params_toolTip1->InitialDelay = 500;
			this->GUI_params_toolTip1->ReshowDelay = 100;
			this->GUI_params_toolTip1->UseAnimation = false;
			this->GUI_params_toolTip1->UseFading = false;
			// 
			// GUI_params_bouton_apercu
			// 
			this->GUI_params_bouton_apercu->Location = System::Drawing::Point(92, 165);
			this->GUI_params_bouton_apercu->Name = L"GUI_params_bouton_apercu";
			this->GUI_params_bouton_apercu->Size = System::Drawing::Size(51, 23);
			this->GUI_params_bouton_apercu->TabIndex = 11;
			this->GUI_params_bouton_apercu->Text = L"Aperçu";
			this->GUI_params_bouton_apercu->UseVisualStyleBackColor = true;
			this->GUI_params_bouton_apercu->Click += gcnew System::EventHandler(this, &ImgConvParametresGris::GUI_bouton_apercu_Click);
			// 
			// GUI_params_bouton_effectuer_tache
			// 
			this->GUI_params_bouton_effectuer_tache->Location = System::Drawing::Point(72, 136);
			this->GUI_params_bouton_effectuer_tache->Name = L"GUI_params_bouton_effectuer_tache";
			this->GUI_params_bouton_effectuer_tache->Size = System::Drawing::Size(90, 23);
			this->GUI_params_bouton_effectuer_tache->TabIndex = 10;
			this->GUI_params_bouton_effectuer_tache->Text = L"Effectuer tâche";
			this->GUI_params_bouton_effectuer_tache->UseVisualStyleBackColor = true;
			this->GUI_params_bouton_effectuer_tache->Click += gcnew System::EventHandler(this, &ImgConvParametresGris::GUI_params_bouton_effectuer_tache_Click);
			// 
			// GUI_paramsgris_liste
			// 
			this->GUI_paramsgris_liste->Items->AddRange(gcnew cli::array< System::Object^  >(9) {L"Moyenne->Blanc", L"Rouge->Noir", L"Vert->Noir", 
				L"Bleu->Noir", L"Moyenne->Noir", L"Rouge->Blanc", L"Vert->Blanc", L"Bleu->Blanc", L"Ne rien faire"});
			this->GUI_paramsgris_liste->Location = System::Drawing::Point(14, 30);
			this->GUI_paramsgris_liste->Name = L"GUI_paramsgris_liste";
			this->GUI_paramsgris_liste->Size = System::Drawing::Size(208, 82);
			this->GUI_paramsgris_liste->TabIndex = 12;
			this->GUI_paramsgris_liste->SelectedIndexChanged += gcnew System::EventHandler(this, &ImgConvParametresGris::GUI_paramsgris_liste_SelectedIndexChanged);
			// 
			// ImgConvParametresGris
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(234, 206);
			this->ControlBox = false;
			this->Controls->Add(this->GUI_paramsgris_liste);
			this->Controls->Add(this->GUI_params_bouton_apercu);
			this->Controls->Add(this->GUI_params_bouton_effectuer_tache);
			this->Controls->Add(this->GUI_paramsgris_label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ImgConvParametresGris";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Griser";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion //Windows Form Designer generated code

	private:

		/// <summary>
		/// Initialisation partie manuelle (non créée par Visual Studio)
		/// </summary>

		void InitializeComponent2(void) {

			if (!image_bitmap) {
				MessageBox::Show(L"Une erreur est survenue lors du chargement de l'image",L"Erreur",MessageBoxButtons::OK,MessageBoxIcon::Error);
				this->Close();
			}

			GUI_paramsgris_liste->SelectedIndex::set(8);
			GUI_params_toolTip1->SetToolTip(GUI_paramsgris_liste,L"Sélectionner une action et placez la souris sur le bouton effectuer tâche pour plus d'informations.");
			GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Ne fais rien et retourne à la fenêtre principale.");
			GUI_params_toolTip1->SetToolTip(GUI_params_bouton_apercu,L"Affiche l'image modifiée par la tâche sélectionnée");

		}

#pragma region Ecouteurs de ImgConvParametresGris

	private: 

		/// <summary>
		/// Gère le bouton Effectuer Tâche
		/// </summary>

		System::Void GUI_params_bouton_effectuer_tache_Click(System::Object^  sender, System::EventArgs^  e) {

			if (GUI_paramsgris_liste->SelectedIndex>=0 && GUI_paramsgris_liste->SelectedIndex<=7) {
				ImgConvTools::Griser(image_bitmap,GUI_paramsgris_liste->SelectedIndex); //0=Moyenne->blanc,1=rouge->noir,2=vert->noir,3=bleu->noir,
																						//4=Moyenne->noir,5=rouge->blanc,6=vert->blanc,7=bleu->blanc
				MessageBox::Show(L"Le changement a été effectué\nEnregistrez l'image pour voir les modifications",L"Opération réussie");

				//confirme que l'image a changé
				this->DialogResult=System::Windows::Forms::DialogResult::OK;
			}
			else
				//confirme que l'image n'a pas changé
				this->DialogResult=System::Windows::Forms::DialogResult::Cancel;

			this->Close();
		} //GUI_params_bouton_effectuer_tache_Click

	private: 

		/// <summary>
		/// Gère le changement d'info-bulle quand la sélection de la liste change
		/// </summary>

		System::Void GUI_paramsgris_liste_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			switch(GUI_paramsgris_liste->SelectedIndex) { //0=Moyenne->blanc,1=rouge->noir,2=vert->noir,3=bleu->noir,
														  //4=Moyenne->noir,5=rouge->blanc,6=vert->blanc,7=bleu->blanc

				case 0:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Chaque pixel prend une valeur de gris correspondant à la moyenne de ses 3 couleurs (moyenne plus élevée => plus de noir)");
					break;

				case 1:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Chaque pixel prend une valeur de gris correspondant au rouge (plus de rouge => plus de noir)");
					break;

				case 2:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Chaque pixel prend une valeur de gris correspondant au vert (plus de vert => plus de noir)");
					break;

				case 3:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Chaque pixel prend une valeur de gris correspondant au bleu (plus de bleu => plus de noir)");
					break;

				case 4:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Chaque pixel prend une valeur au gris correspondant à la moyenne de ses 3 couleurs (moyenne plus élevée => plus de blanc)");
					break;

				case 5:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Chaque pixel prend une valeur de gris correspondant au rouge (plus de rouge => plus de blanc)");
					break;

				case 6:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Chaque pixel prend une valeur de gris correspondant au vert (plus de vert => plus de blanc)");
					break;

				case 7:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Chaque pixel prend une valeur de gris correspondant au bleu (plus de bleu => plus de blanc)");
					break;

				default:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Ne fais rien et retourne à la fenêtre principale.");
					break;
			}
		} //GUI_paramsgris_liste_SelectedIndexChanged

	private: 

		/// <summary>
		/// Gestion du bouton Aperçu
		/// </summary>

		System::Void GUI_bouton_apercu_Click(System::Object^  sender, System::EventArgs^  e) {

			Bitmap^ image_apercu = gcnew Bitmap(image_bitmap);
			ImgConvTools::Griser(image_apercu,GUI_paramsgris_liste->SelectedIndex); //0=Moyenne->blanc,1=rouge->noir,2=vert->noir,3=bleu->noir,
																					//4=Moyenne->noir,5=rouge->blanc,6=vert->blanc,7=bleu->blanc

			ImgConvApercu^ fenetre_apercu=gcnew ImgConvApercu(image_apercu);
			fenetre_apercu->ShowDialog();

			delete fenetre_apercu;
			delete image_apercu;

		}//GUI_bouton_apercu_Click

	}; //ImgConvParametresGris

#pragma endregion //Ecouteurs de ImgConvParametresGris

} //ImgConv
