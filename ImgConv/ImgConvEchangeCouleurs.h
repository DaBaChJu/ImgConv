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
	/// Description résumée de ImgConvEchangeCouleurs
	///
	/// AVERTISSEMENT : si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propriété 'Nom du fichier de ressources' de l'outil de compilation de ressource managée
	///          pour tous les fichiers .resx dont dépend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localisées associées à ce formulaire.
	/// </summary>
	public ref class ImgConvEchangeCouleurs : public System::Windows::Forms::Form {
	public:
		/// <summary>
		/// Constructeur par défaut
		/// </summary>
		ImgConvEchangeCouleurs(void) {
			InitializeComponent();
		}

	public:
		/// <summary>
		/// Constructeur personnalisé
		/// </summary>
		ImgConvEchangeCouleurs(System::Drawing::Bitmap^ source) {
			InitializeComponent();
			image_bitmap=source;
			InitializeComponent2();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~ImgConvEchangeCouleurs() {
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
	private: System::Windows::Forms::Button^  GUI_params_bouton_apercu;
	private: System::Windows::Forms::Button^  GUI_params_bouton_effectuer_tache;
	private: System::Windows::Forms::Label^  GUI_params_texte_couleur_1;
	private: System::Windows::Forms::Label^  GUI_params_texte_couleur_2;
	private: System::Windows::Forms::ComboBox^  GUI_params_comboBox1;
	private: System::Windows::Forms::ComboBox^  GUI_params_comboBox2;
	private: System::Windows::Forms::Label^  GUI_params_texte_couleur_dominante2;
	private: System::Windows::Forms::ComboBox^  GUI_params_comboBox_dominante2;


	private: System::Windows::Forms::ToolTip^  GUI_params_toolTip;
	private: System::Windows::Forms::Label^  GUI_params_texte_couleur_origine_exemple;
	private: System::Windows::Forms::Label^  GUI_params_texte_couleur_finale_exemple;
	private: System::Windows::Forms::ComboBox^  GUI_params_comboBox_dominante1;

	private: System::Windows::Forms::Label^  GUI_params_texte_couleur_dominante1;



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
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->GUI_params_bouton_apercu = (gcnew System::Windows::Forms::Button());
			this->GUI_params_bouton_effectuer_tache = (gcnew System::Windows::Forms::Button());
			this->GUI_params_texte_couleur_1 = (gcnew System::Windows::Forms::Label());
			this->GUI_params_texte_couleur_2 = (gcnew System::Windows::Forms::Label());
			this->GUI_params_comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->GUI_params_comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->GUI_params_texte_couleur_dominante2 = (gcnew System::Windows::Forms::Label());
			this->GUI_params_comboBox_dominante2 = (gcnew System::Windows::Forms::ComboBox());
			this->GUI_params_toolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->GUI_params_texte_couleur_origine_exemple = (gcnew System::Windows::Forms::Label());
			this->GUI_params_texte_couleur_finale_exemple = (gcnew System::Windows::Forms::Label());
			this->GUI_params_comboBox_dominante1 = (gcnew System::Windows::Forms::ComboBox());
			this->GUI_params_texte_couleur_dominante1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// GUI_params_bouton_apercu
			// 
			this->GUI_params_bouton_apercu->Location = System::Drawing::Point(119, 218);
			this->GUI_params_bouton_apercu->Name = L"GUI_params_bouton_apercu";
			this->GUI_params_bouton_apercu->Size = System::Drawing::Size(51, 23);
			this->GUI_params_bouton_apercu->TabIndex = 13;
			this->GUI_params_bouton_apercu->Text = L"Aperçu";
			this->GUI_params_bouton_apercu->UseVisualStyleBackColor = true;
			this->GUI_params_bouton_apercu->Click += gcnew System::EventHandler(this, &ImgConvEchangeCouleurs::GUI_bouton_apercu_Click);
			// 
			// GUI_params_bouton_effectuer_tache
			// 
			this->GUI_params_bouton_effectuer_tache->Location = System::Drawing::Point(101, 189);
			this->GUI_params_bouton_effectuer_tache->Name = L"GUI_params_bouton_effectuer_tache";
			this->GUI_params_bouton_effectuer_tache->Size = System::Drawing::Size(90, 23);
			this->GUI_params_bouton_effectuer_tache->TabIndex = 12;
			this->GUI_params_bouton_effectuer_tache->Text = L"Effectuer tâche";
			this->GUI_params_bouton_effectuer_tache->UseVisualStyleBackColor = true;
			this->GUI_params_bouton_effectuer_tache->Click += gcnew System::EventHandler(this, &ImgConvEchangeCouleurs::GUI_params_bouton_effectuer_tache_Click);
			// 
			// GUI_params_texte_couleur_1
			// 
			this->GUI_params_texte_couleur_1->AutoSize = true;
			this->GUI_params_texte_couleur_1->Location = System::Drawing::Point(14, 19);
			this->GUI_params_texte_couleur_1->Margin = System::Windows::Forms::Padding(10, 10, 0, 0);
			this->GUI_params_texte_couleur_1->Name = L"GUI_params_texte_couleur_1";
			this->GUI_params_texte_couleur_1->Size = System::Drawing::Size(102, 13);
			this->GUI_params_texte_couleur_1->TabIndex = 14;
			this->GUI_params_texte_couleur_1->Text = L"Echanger la couleur";
			// 
			// GUI_params_texte_couleur_2
			// 
			this->GUI_params_texte_couleur_2->AutoSize = true;
			this->GUI_params_texte_couleur_2->Location = System::Drawing::Point(14, 84);
			this->GUI_params_texte_couleur_2->Margin = System::Windows::Forms::Padding(10, 20, 0, 0);
			this->GUI_params_texte_couleur_2->Name = L"GUI_params_texte_couleur_2";
			this->GUI_params_texte_couleur_2->Size = System::Drawing::Size(86, 13);
			this->GUI_params_texte_couleur_2->TabIndex = 15;
			this->GUI_params_texte_couleur_2->Text = L"contre la couleur";
			// 
			// GUI_params_comboBox1
			// 
			this->GUI_params_comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->GUI_params_comboBox1->FormattingEnabled = true;
			this->GUI_params_comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"Rouge", L"Vert", L"Bleu", L"Jaune", 
				L"Violet", L"Cyan", L"Aucune"});
			this->GUI_params_comboBox1->Location = System::Drawing::Point(119, 16);
			this->GUI_params_comboBox1->Name = L"GUI_params_comboBox1";
			this->GUI_params_comboBox1->Size = System::Drawing::Size(161, 21);
			this->GUI_params_comboBox1->TabIndex = 16;
			this->GUI_params_comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &ImgConvEchangeCouleurs::GUI_liste_SelectedIndexChanged);
			// 
			// GUI_params_comboBox2
			// 
			this->GUI_params_comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->GUI_params_comboBox2->FormattingEnabled = true;
			this->GUI_params_comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"Rouge", L"Vert", L"Bleu", L"Jaune", 
				L"Violet", L"Cyan", L"Aucune"});
			this->GUI_params_comboBox2->Location = System::Drawing::Point(119, 81);
			this->GUI_params_comboBox2->Name = L"GUI_params_comboBox2";
			this->GUI_params_comboBox2->Size = System::Drawing::Size(161, 21);
			this->GUI_params_comboBox2->TabIndex = 17;
			this->GUI_params_comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &ImgConvEchangeCouleurs::GUI_liste_SelectedIndexChanged);
			// 
			// GUI_params_texte_couleur_dominante2
			// 
			this->GUI_params_texte_couleur_dominante2->AutoSize = true;
			this->GUI_params_texte_couleur_dominante2->Location = System::Drawing::Point(19, 117);
			this->GUI_params_texte_couleur_dominante2->Margin = System::Windows::Forms::Padding(10, 20, 0, 0);
			this->GUI_params_texte_couleur_dominante2->Name = L"GUI_params_texte_couleur_dominante2";
			this->GUI_params_texte_couleur_dominante2->Size = System::Drawing::Size(83, 13);
			this->GUI_params_texte_couleur_dominante2->TabIndex = 18;
			this->GUI_params_texte_couleur_dominante2->Text = L"avec dominante";
			this->GUI_params_texte_couleur_dominante2->Visible = false;
			// 
			// GUI_params_comboBox_dominante2
			// 
			this->GUI_params_comboBox_dominante2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->GUI_params_comboBox_dominante2->FormattingEnabled = true;
			this->GUI_params_comboBox_dominante2->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Rouge", L"Vert", L"Bleu", 
				L"Aucune"});
			this->GUI_params_comboBox_dominante2->Location = System::Drawing::Point(119, 114);
			this->GUI_params_comboBox_dominante2->Name = L"GUI_params_comboBox_dominante2";
			this->GUI_params_comboBox_dominante2->Size = System::Drawing::Size(161, 21);
			this->GUI_params_comboBox_dominante2->TabIndex = 19;
			this->GUI_params_comboBox_dominante2->Visible = false;
			this->GUI_params_comboBox_dominante2->SelectedIndexChanged += gcnew System::EventHandler(this, &ImgConvEchangeCouleurs::GUI_liste_SelectedIndexChanged);
			// 
			// GUI_params_toolTip
			// 
			this->GUI_params_toolTip->AutoPopDelay = 10000;
			this->GUI_params_toolTip->InitialDelay = 500;
			this->GUI_params_toolTip->ReshowDelay = 100;
			this->GUI_params_toolTip->UseAnimation = false;
			this->GUI_params_toolTip->UseFading = false;
			// 
			// GUI_params_texte_couleur_origine_exemple
			// 
			this->GUI_params_texte_couleur_origine_exemple->AutoSize = true;
			this->GUI_params_texte_couleur_origine_exemple->Location = System::Drawing::Point(47, 155);
			this->GUI_params_texte_couleur_origine_exemple->Name = L"GUI_params_texte_couleur_origine_exemple";
			this->GUI_params_texte_couleur_origine_exemple->Size = System::Drawing::Size(85, 13);
			this->GUI_params_texte_couleur_origine_exemple->TabIndex = 20;
			this->GUI_params_texte_couleur_origine_exemple->Text = L"Couleur d\'origine";
			// 
			// GUI_params_texte_couleur_finale_exemple
			// 
			this->GUI_params_texte_couleur_finale_exemple->AutoSize = true;
			this->GUI_params_texte_couleur_finale_exemple->Location = System::Drawing::Point(158, 155);
			this->GUI_params_texte_couleur_finale_exemple->Name = L"GUI_params_texte_couleur_finale_exemple";
			this->GUI_params_texte_couleur_finale_exemple->Size = System::Drawing::Size(71, 13);
			this->GUI_params_texte_couleur_finale_exemple->TabIndex = 21;
			this->GUI_params_texte_couleur_finale_exemple->Text = L"Couleur finale";
			// 
			// GUI_params_comboBox_dominante1
			// 
			this->GUI_params_comboBox_dominante1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->GUI_params_comboBox_dominante1->FormattingEnabled = true;
			this->GUI_params_comboBox_dominante1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Rouge", L"Vert", L"Bleu", 
				L"Aucune"});
			this->GUI_params_comboBox_dominante1->Location = System::Drawing::Point(119, 49);
			this->GUI_params_comboBox_dominante1->Name = L"GUI_params_comboBox_dominante1";
			this->GUI_params_comboBox_dominante1->Size = System::Drawing::Size(161, 21);
			this->GUI_params_comboBox_dominante1->TabIndex = 23;
			this->GUI_params_comboBox_dominante1->Visible = false;
			// 
			// GUI_params_texte_couleur_dominante1
			// 
			this->GUI_params_texte_couleur_dominante1->AutoSize = true;
			this->GUI_params_texte_couleur_dominante1->Location = System::Drawing::Point(19, 52);
			this->GUI_params_texte_couleur_dominante1->Margin = System::Windows::Forms::Padding(10, 20, 0, 0);
			this->GUI_params_texte_couleur_dominante1->Name = L"GUI_params_texte_couleur_dominante1";
			this->GUI_params_texte_couleur_dominante1->Size = System::Drawing::Size(83, 13);
			this->GUI_params_texte_couleur_dominante1->TabIndex = 22;
			this->GUI_params_texte_couleur_dominante1->Text = L"avec dominante";
			this->GUI_params_texte_couleur_dominante1->Visible = false;
			// 
			// ImgConvEchangeCouleurs
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 253);
			this->Controls->Add(this->GUI_params_comboBox_dominante1);
			this->Controls->Add(this->GUI_params_texte_couleur_dominante1);
			this->Controls->Add(this->GUI_params_texte_couleur_finale_exemple);
			this->Controls->Add(this->GUI_params_texte_couleur_origine_exemple);
			this->Controls->Add(this->GUI_params_comboBox_dominante2);
			this->Controls->Add(this->GUI_params_texte_couleur_dominante2);
			this->Controls->Add(this->GUI_params_comboBox2);
			this->Controls->Add(this->GUI_params_comboBox1);
			this->Controls->Add(this->GUI_params_texte_couleur_2);
			this->Controls->Add(this->GUI_params_texte_couleur_1);
			this->Controls->Add(this->GUI_params_bouton_apercu);
			this->Controls->Add(this->GUI_params_bouton_effectuer_tache);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ImgConvEchangeCouleurs";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Echanger des couleurs";
			this->ResumeLayout(false);
			this->PerformLayout();

		} //void InitializeComponent(void)
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

			GUI_params_comboBox1->SelectedIndex=6;
			GUI_params_comboBox2->SelectedIndex=6;
			GUI_params_comboBox_dominante1->SelectedIndex=3;
			GUI_params_comboBox_dominante2->SelectedIndex=3;

			GUI_params_toolTip->SetToolTip(GUI_params_bouton_effectuer_tache,L"Effectue le remplacement sélectionné si tout est paramètré correctement.");
			GUI_params_toolTip->SetToolTip(GUI_params_bouton_apercu,L"Affiche l'image modifiée par la tâche sélectionnée");
			GUI_params_toolTip->SetToolTip(GUI_params_comboBox1,L"Sélectionnez la couleur à remplacer,puis faites à nouveau apparaitre cette aide pour plus d'information.");
			GUI_params_toolTip->SetToolTip(GUI_params_comboBox2,L"Sélectionnez la couleur de remplacement,puis faites à nouveau apparaitre cette aide pour plus d'information.");
			GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante1,L"Sélectionnez la dominante de la couleur à remplacer,puis faites à nouveau apparaitre cette aide pour plus d'information.");
			GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante2,L"Sélectionnez la dominante de la couleur de remplacement,puis faites à nouveau apparaitre cette aide pour plus d'information.");
			GUI_params_toolTip->SetToolTip(GUI_params_texte_couleur_finale_exemple,L"La couleur de ce texte n'est qu'un exemple,les couleurs effectivement remplacées le sont sur les critères décrits sur la liste correspondante.");
			GUI_params_toolTip->SetToolTip(GUI_params_texte_couleur_origine_exemple,L"La couleur de ce texte n'est qu'un exemple,les couleurs de remplacement dépendent de l'organisation des couleurs initiales des pixels recolorés.");

		}

#pragma region Ecouteurs de ImgConvEchangeCouleurs

	private: 

		/// <summary>
		/// Gestion du bouton Aperçu
		/// </summary>

		System::Void GUI_bouton_apercu_Click(System::Object^  sender, System::EventArgs^  e) {

			Bitmap^ image_apercu = gcnew Bitmap(image_bitmap);

			if (GUI_params_comboBox1->SelectedIndex!=6 && GUI_params_comboBox2->SelectedIndex!=6)
				ImgConvTools::Echange_couleurs(	image_apercu,
												GUI_params_comboBox1->SelectedIndex,
												GUI_params_comboBox2->SelectedIndex,
												GUI_params_comboBox_dominante1->SelectedIndex,
												GUI_params_comboBox_dominante2->SelectedIndex
				);

			ImgConvApercu^ fenetre_apercu=gcnew ImgConvApercu(image_apercu);
			fenetre_apercu->ShowDialog();

			delete fenetre_apercu;
			delete image_apercu;

		}//GUI_bouton_apercu_Click

	private: 

		/// <summary>
		/// Réaction au changement de sélection des listes
		///
		/// Gère le changement d'info-bulle
		/// Change la couleur des textes d'exemple
		/// Active et désactive la liste de couleur dominante
		/// </summary>

		System::Void GUI_liste_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

//définition de constantes pour faciliter la lecture
#define C_ROUGE		0
#define C_VERT		1
#define C_BLEU		2
#define C_AUCUNE	3
#define C_JAUNE		3
#define C_VIOLET	4
#define C_CYAN		5

			if (sender==GUI_params_comboBox1) {
				switch(GUI_params_comboBox1->SelectedIndex) {

					case C_ROUGE:
						GUI_params_toolTip->SetToolTip(GUI_params_comboBox1,L"Tout pixel possédant plus de rouge que de vert et de bleu verra sa couleur changer.");
						GUI_params_texte_couleur_dominante1->Visible::set(false);
						GUI_params_comboBox_dominante1->Visible::set(false);
						GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(255,0,0);
						break;

					case C_VERT:
						GUI_params_toolTip->SetToolTip(GUI_params_comboBox1,L"Tout pixel possédant plus de vert que de rouge et de bleu verra sa couleur changer.");
						GUI_params_texte_couleur_dominante1->Visible::set(false);
						GUI_params_comboBox_dominante1->Visible::set(false);
						GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(0,255,0);
						break;

					case C_BLEU:
						GUI_params_toolTip->SetToolTip(GUI_params_comboBox1,L"Tout pixel possédant plus de bleu que de rouge et de vert verra sa couleur changer.");
						GUI_params_texte_couleur_dominante1->Visible::set(false);
						GUI_params_comboBox_dominante1->Visible::set(false);
						GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(0,0,255);
						break;

					case C_JAUNE:
						GUI_params_toolTip->SetToolTip(GUI_params_comboBox1,L"Jaune=Rouge+Vert\n" +
																			L"Tout pixel possédant moins de bleu que de rouge et de vert verra sa couleur changer.");
						GUI_params_texte_couleur_dominante1->Visible::set(true);
						GUI_params_comboBox_dominante1->Visible::set(true);
						GUI_params_comboBox_dominante1->SelectedIndex=C_AUCUNE;
						GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(255,255,0);
						break;

					case C_VIOLET:
						GUI_params_toolTip->SetToolTip(GUI_params_comboBox1,L"Violet=Rouge+Bleu\n" +
																			L"Tout pixel possédant moins de vert que de rouge et de bleu verra sa couleur changer.");
						GUI_params_texte_couleur_dominante1->Visible::set(true);
						GUI_params_comboBox_dominante1->Visible::set(true);
						GUI_params_comboBox_dominante1->SelectedIndex=C_AUCUNE;
						GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(255,0,255);
						break;

					case C_CYAN:
						GUI_params_toolTip->SetToolTip(GUI_params_comboBox1,L"Cyan=Vert+Bleu\n" +
																			L"Tout pixel possédant moins de rouge que de vert et de bleu verra sa couleur changer.");
						GUI_params_texte_couleur_dominante1->Visible::set(true);
						GUI_params_comboBox_dominante1->Visible::set(true);
						GUI_params_comboBox_dominante1->SelectedIndex=C_AUCUNE;
						GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(0,255,255);
						break;

					default:
						GUI_params_toolTip->SetToolTip(GUI_params_comboBox1,L"Sélectionnez la couleur à remplacer,puis faites à nouveau apparaitre cette aide pour plus d'information.");
						GUI_params_texte_couleur_dominante1->Visible::set(false);
						GUI_params_comboBox_dominante1->Visible::set(false);
						GUI_params_comboBox_dominante1->SelectedIndex=C_AUCUNE;
						GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(0,0,0);
						break;

				}
			} //if (sender==GUI_params_comboBox1)
			else
			if (sender==GUI_params_comboBox2) {

				switch(GUI_params_comboBox2->SelectedIndex) {

					case C_ROUGE:
						GUI_params_toolTip->SetToolTip(GUI_params_comboBox2,L"Les pixels remplacés auront plus de rouge que de vert et de bleu.");
						GUI_params_texte_couleur_dominante2->Visible::set(false);
						GUI_params_comboBox_dominante2->Visible::set(false);
						GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(255,0,0);
						break;

					case C_VERT:
						GUI_params_toolTip->SetToolTip(GUI_params_comboBox2,L"Les pixels remplacés auront plus de vert que de rouge et de bleu.");
						GUI_params_texte_couleur_dominante2->Visible::set(false);
						GUI_params_comboBox_dominante2->Visible::set(false);
						GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(0,255,0);
						break;

					case C_BLEU:
						GUI_params_toolTip->SetToolTip(GUI_params_comboBox2,L"Les pixels remplacés auront plus de bleu que de rouge et de vert.");
						GUI_params_texte_couleur_dominante2->Visible::set(false);
						GUI_params_comboBox_dominante2->Visible::set(false);
						GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(0,0,255);
						break;

					case C_JAUNE:
						GUI_params_toolTip->SetToolTip(GUI_params_comboBox2,L"Jaune=Rouge+Vert\n" +
																			L"Les pixels remplacés auront moins de bleu que de rouge et de vert.\n" +
																			L"La quantité de rouge et de vert dépendra de la dominante");
						GUI_params_texte_couleur_dominante2->Visible::set(true);
						GUI_params_comboBox_dominante2->Visible::set(true);
						GUI_params_comboBox_dominante2->SelectedIndex=C_AUCUNE;
						GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(255,255,0);
						break;

					case C_VIOLET:
						GUI_params_toolTip->SetToolTip(GUI_params_comboBox2,L"Violet=Rouge+Bleu\n" +
																			L"Les pixels remplacés auront moins de vert que de rouge et de bleu.\n" +
																			L"La quantité de rouge et de bleu dépendra de la dominante.");
						GUI_params_texte_couleur_dominante2->Visible::set(true);
						GUI_params_comboBox_dominante2->Visible::set(true);
						GUI_params_comboBox_dominante2->SelectedIndex=C_AUCUNE;
						GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(255,0,255);
						break;

					case C_CYAN:
						GUI_params_toolTip->SetToolTip(GUI_params_comboBox2,L"Cyan=Vert+Bleu\n" +
																			L"Les pixels remplacés auront moins de rouge que de vert et de bleu.\n" +
																			L"La quantité de vert et de bleu dépendra de la dominante.");
						GUI_params_texte_couleur_dominante2->Visible::set(true);
						GUI_params_comboBox_dominante2->Visible::set(true);
						GUI_params_comboBox_dominante2->SelectedIndex=C_AUCUNE;
						GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(0,255,255);
						break;

					default:
						GUI_params_toolTip->SetToolTip(GUI_params_comboBox2,L"Sélectionnez la couleur de remplacement,puis faites à nouveau apparaitre cette aide pour plus d'information.");
						GUI_params_texte_couleur_dominante2->Visible::set(false);
						GUI_params_comboBox_dominante2->Visible::set(false);
						GUI_params_comboBox_dominante2->SelectedIndex=C_AUCUNE;
						GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(0,0,0);
						break;

				}

			} //if (sender==GUI_params_comboBox2)
			else
			if (sender==GUI_params_comboBox_dominante1) {

				//si c'est une couleur primaire choisie en couleur d'origine,la dominante n'a pas d'effet,mais normalement la liste n'apparaitra même pas dans ce cas
				if(GUI_params_comboBox1->SelectedIndex==C_ROUGE || GUI_params_comboBox1->SelectedIndex==C_BLEU || GUI_params_comboBox1->SelectedIndex==C_VERT)
					GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante1,L"La dominante ne s'applique pas au cas sélectionnné.");
				else {
					switch(GUI_params_comboBox_dominante1->SelectedIndex) {

						case C_ROUGE:
							if (GUI_params_comboBox1->SelectedIndex==C_JAUNE) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante1,L"La couleur sera remplacée si elle est plus rouge que verte,soit un jaune tendant vers l'orange voire le rouge.");
								GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(255,191,0);
							}
							else
							if (GUI_params_comboBox1->SelectedIndex==C_VIOLET) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante1,L"La couleur sera remplacée si elle est plus rouge que bleue,soit un violet tendant vers le rose voire le rouge.");
								GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(255,0,191);
							}
							else
							if (GUI_params_comboBox1->SelectedIndex==C_CYAN ) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante1,L"Tout pixel possédant moins de rouge que de vert et de bleu verra sa couleur changer.");
								GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(0,255,255);
							}
							break;

						case C_VERT:
							if (GUI_params_comboBox1->SelectedIndex==C_JAUNE) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante1,L"La couleur sera remplacée si elle est plus verte que rouge,soit un jaune tendant vers un vert pâle voire un vert pur.");
								GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(191,255,0);
							}
							else
							if (GUI_params_comboBox1->SelectedIndex==C_VIOLET) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante1,L"Tout pixel possédant moins de vert que de rouge et de bleu verra sa couleur changer.");
								GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(255,0,255);
							}
							else
							if (GUI_params_comboBox1->SelectedIndex==C_CYAN ) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante1,L"La couleur sera remplacée si elle est plus verte que bleu,soit un cyan tendant vers un vert bleuté voire un vert pur.");
								GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(0,255,191);
							}
							break;

						case C_BLEU:
							if (GUI_params_comboBox1->SelectedIndex==C_JAUNE) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante1,L"Tout pixel possédant moins de bleu que de rouge et de vert verra sa couleur changer.");
								GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(255,255,0);
							}
							else
							if (GUI_params_comboBox1->SelectedIndex==C_VIOLET) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante1,L"La couleur sera remplacée si elle est plus bleue que rouge,soit un violet tendant vers le violet foncé voire le bleu.");
								GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(191,0,255);
							}
							else
							if (GUI_params_comboBox1->SelectedIndex==C_CYAN ) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante1,L"La couleur sera remplacée si elle est plus bleue que verte,soit un cyan tendant vers un bleu foncé lumineux voire un bleu pur.");
								GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(0,191,255);
							}
							break;

						case C_AUCUNE:
							if (GUI_params_comboBox1->SelectedIndex==C_JAUNE) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante1,L"Tout pixel possédant moins de bleu que de rouge et de vert verra sa couleur changer.");
								GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(255,255,0);
							}else
							if (GUI_params_comboBox1->SelectedIndex==C_VIOLET) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante1,L"Tout pixel possédant moins de vert que de rouge et de bleu verra sa couleur changer.");
								GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(255,0,255);
							}else
							if (GUI_params_comboBox1->SelectedIndex==C_CYAN ) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante1,L"Tout pixel possédant moins de rouge que de vert et de bleu verra sa couleur changer.");
								GUI_params_texte_couleur_origine_exemple->ForeColor=Color::FromArgb(0,255,255);
							}
							break;

						default:
							GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante1,L"Sélectionnez la dominante de la couleur à remplacer,puis faites à nouveau apparaitre cette aide pour plus d'information.");
							break;

					}
				}

			} //if (sender==GUI_params_comboBox_dominante1)
			else
			if (sender==GUI_params_comboBox_dominante2) {

				//si c'est une couleur primaire choisie en couleur de remplacement,la dominante n'a pas d'effet,mais normalement la liste n'apparaitra même pas dans ce cas
				if(GUI_params_comboBox2->SelectedIndex==C_ROUGE || GUI_params_comboBox2->SelectedIndex==C_BLEU || GUI_params_comboBox2->SelectedIndex==C_VERT)
					GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante2,L"La dominante ne s'applique pas au cas sélectionnné.");
				else {
					switch(GUI_params_comboBox_dominante2->SelectedIndex) {

						case C_ROUGE:
							if (GUI_params_comboBox2->SelectedIndex==C_JAUNE) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante2,L"La couleur sera plus rouge que verte,soit un jaune tendant vers l'orange voire le rouge.");
								GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(255,191,0);
							}
							else
							if (GUI_params_comboBox2->SelectedIndex==C_VIOLET) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante2,L"La couleur sera plus rouge que bleue,soit un violet tendant vers le rose voire le rouge.");
								GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(255,0,191);
							}
							else
							if (GUI_params_comboBox2->SelectedIndex==C_CYAN ) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante2,L"Les couleurs composantes seront réparties de façon égale,car il n'y a pas de rouge dans le cyan.");
								GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(0,255,255);
							}
							break;

						case C_VERT:
							if (GUI_params_comboBox2->SelectedIndex==C_JAUNE) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante2,L"La couleur sera plus verte que rouge,soit un jaune tendant vers un vert pâle voire un vert pur.");
								GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(191,255,0);
							}
							else
							if (GUI_params_comboBox2->SelectedIndex==C_VIOLET) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante2,L"Les couleurs composantes seront réparties de façon égale,car il n'y a pas de vert dans le violet.");
								GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(255,0,255);
							}
							else
							if (GUI_params_comboBox2->SelectedIndex==C_CYAN ) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante2,L"La couleur sera plus verte que bleu,soit un cyan tendant vers un vert bleuté voire un vert pur.");
								GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(0,255,191);
							}
							break;

						case C_BLEU:
							if (GUI_params_comboBox2->SelectedIndex==C_JAUNE) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante2,L"Les couleurs composantes seront réparties de façon égale,car il n'y a pas de bleu dans le jaune.");
								GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(255,255,0);
							}
							else
							if (GUI_params_comboBox2->SelectedIndex==C_VIOLET) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante2,L"La couleur sera plus bleue que rouge,soit un violet tendant vers le violet foncé voire le bleu.");
								GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(191,0,255);
							}
							else
							if (GUI_params_comboBox2->SelectedIndex==C_CYAN ) {
								GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante2,L"La couleur sera plus bleue que verte,soit un cyan tendant vers un bleu foncé lumineux voire un bleu pur.");
								GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(0,191,255);
							}
							break;

						case C_AUCUNE:
							GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante2,L"Les couleurs composantes seront réparties de façon égale.");
							if (GUI_params_comboBox2->SelectedIndex==C_JAUNE)
								GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(255,255,0);else
							if (GUI_params_comboBox2->SelectedIndex==C_VIOLET)
								GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(255,0,255);else
							if (GUI_params_comboBox2->SelectedIndex==C_CYAN )
								GUI_params_texte_couleur_finale_exemple->ForeColor=Color::FromArgb(0,255,255);
							break;

						default:
							GUI_params_toolTip->SetToolTip(GUI_params_comboBox_dominante2,L"Sélectionnez la dominante de la couleur de remplacement,puis faites à nouveau apparaitre cette aide pour plus d'information.");
							break;

					}
				}

			} //if (sender==GUI_params_comboBox_dominante2)

//effacement des constantes
#undef C_ROUGE
#undef C_VERT
#undef C_BLEU
#undef C_AUCUNE
#undef C_JAUNE
#undef C_VIOLET
#undef C_CYAN

		} //GUI_liste_SelectedIndexChanged

	private:

		/// <summary>
		/// Gère le bouton Effectuer Tâche
		/// </summary> 

		System::Void GUI_params_bouton_effectuer_tache_Click(System::Object^  sender, System::EventArgs^  e) {

			if (GUI_params_comboBox1->SelectedIndex!=6 && GUI_params_comboBox2->SelectedIndex!=6) { //6 est la couleur disant "aucune" pour la couleur à remplacer ou de remplacement

				ImgConvTools::Echange_couleurs(	image_bitmap,
												GUI_params_comboBox1->SelectedIndex,
												GUI_params_comboBox2->SelectedIndex,
												GUI_params_comboBox_dominante1->SelectedIndex,
												GUI_params_comboBox_dominante2->SelectedIndex
				);
				MessageBox::Show(L"Le changement a été effectué\nEnregistrez l'image pour voir les modifications",L"Opération réussie");

				//confirme que les modifications doivent être prises en compte
				this->DialogResult=System::Windows::Forms::DialogResult::OK;
			}
			else
				//annule les modifications (la fonction principale supprimera l'image temporaire passée à cette partie)
				this->DialogResult=System::Windows::Forms::DialogResult::Cancel;

			this->Close();
		}//GUI_params_bouton_effectuer_tache_Click

#pragma endregion //Ecouteurs de ImgConvEchangeCouleurs

	}; //public ref class ImgConvEchangeCouleurs : public System::Windows::Forms::Form
} //namespace ImgConv
