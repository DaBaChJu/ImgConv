#pragma once

#include "ImgConvParametresGris.h"
#include "ImgConvEchangeCouleurs.h"
#include "ImgConvApercu.h"
#include "ImgConvProgress.h"
#include "ImgConvRedim.h"
#include "ImgConvMonochrome.h"
#include "ImgConvTools.h"

namespace ImgConv {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Form1
	///
	/// AVERTISSEMENT : si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propriété 'Nom du fichier de ressources' de l'outil de compilation de ressource managée
	///          pour tous les fichiers .resx dont dépend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localisées associées à ce formulaire.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form {

	/// <summary>
	/// Constructeur par défaut.
	/// </summary>
	public:
		Form1(void) {
			InitializeComponent();
			InitializeComponent2();
		}

	/// <summary>
	/// Constructeur avec argument (pour compatibilité avec "Ouvrir avec..." de windows
	/// </summary>
	public:
		Form1(System::String^ fichier_parametre) {
			InitializeComponent();
			InitializeComponent2();
			GUI_chemin_fichier->Text=fichier_parametre;
			Ouvrir_image();
		}

	protected:

		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>

		~Form1() {
			if (components)
				delete components;
			if (image_bitmap->image)
				delete image_bitmap->image;
			delete image_bitmap;
		}

	/// <summary>
	/// Variables du programme général.
	/// </summary>
	public: ImgConvTools::Bitmap_partage^ image_bitmap;	//image actuellement traitée
	public: bool bImageSauvee;

	/// <summary>
	/// Variables du concepteur.
	/// </summary>

	private: System::Windows::Forms::TextBox^  GUI_chemin_fichier;
	private: System::Windows::Forms::MenuStrip^  GUI_menu_principal;
	private: System::Windows::Forms::ToolStripMenuItem^  GUI_fichier;
	private: System::Windows::Forms::ToolStripMenuItem^  GUI_fichier_ouvrir;
	private: System::Windows::Forms::ToolStripMenuItem^  GUI_fichier_enregistrer;
	private: System::Windows::Forms::ToolStripMenuItem^  GUI_fichier_enregistrer_sous;
	private: System::Windows::Forms::ToolStripMenuItem^  GUI_fichier_fermer;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  GUI_fichier_quitter;
	private: System::Windows::Forms::ToolStripMenuItem^  GUI_aide;
	private: System::Windows::Forms::ToolStripMenuItem^  GUI_a_propos;
	private: System::Windows::Forms::ComboBox^  GUI_liste_operations;
	private: System::Windows::Forms::Label^  GUI_chemin_fichier_label;
	private: System::Windows::Forms::Button^  GUI_bouton_effectuer_tache;
	private: System::Windows::Forms::Button^  GUI_bouton_ouvrir;
	private: System::Windows::Forms::Label^  GUI_liste_operations_label;
	private: System::Windows::Forms::Button^  GUI_bouton_apercu;
	private: System::Windows::Forms::ToolTip^  GUI_toolTip;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->GUI_chemin_fichier = (gcnew System::Windows::Forms::TextBox());
			this->GUI_menu_principal = (gcnew System::Windows::Forms::MenuStrip());
			this->GUI_fichier = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GUI_fichier_ouvrir = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->GUI_fichier_enregistrer = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GUI_fichier_enregistrer_sous = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->GUI_fichier_fermer = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->GUI_fichier_quitter = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GUI_aide = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GUI_a_propos = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GUI_liste_operations = (gcnew System::Windows::Forms::ComboBox());
			this->GUI_chemin_fichier_label = (gcnew System::Windows::Forms::Label());
			this->GUI_bouton_effectuer_tache = (gcnew System::Windows::Forms::Button());
			this->GUI_bouton_ouvrir = (gcnew System::Windows::Forms::Button());
			this->GUI_liste_operations_label = (gcnew System::Windows::Forms::Label());
			this->GUI_bouton_apercu = (gcnew System::Windows::Forms::Button());
			this->GUI_toolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->GUI_menu_principal->SuspendLayout();
			this->SuspendLayout();
			// 
			// GUI_chemin_fichier
			// 
			this->GUI_chemin_fichier->AllowDrop = true;
			this->GUI_chemin_fichier->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->GUI_chemin_fichier->BackColor = System::Drawing::SystemColors::Window;
			this->GUI_chemin_fichier->Location = System::Drawing::Point(36, 51);
			this->GUI_chemin_fichier->Name = L"GUI_chemin_fichier";
			this->GUI_chemin_fichier->ReadOnly = true;
			this->GUI_chemin_fichier->Size = System::Drawing::Size(400, 20);
			this->GUI_chemin_fichier->TabIndex = 1;
			this->GUI_chemin_fichier->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::GUI_chemin_fichier_DragDrop);
			this->GUI_chemin_fichier->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::GUI_chemin_fichier_DragEnter);
			// 
			// GUI_menu_principal
			// 
			this->GUI_menu_principal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->GUI_menu_principal->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->GUI_fichier, 
				this->GUI_aide});
			this->GUI_menu_principal->Location = System::Drawing::Point(0, 0);
			this->GUI_menu_principal->Name = L"GUI_menu_principal";
			this->GUI_menu_principal->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->GUI_menu_principal->Size = System::Drawing::Size(472, 24);
			this->GUI_menu_principal->TabIndex = 2;
			this->GUI_menu_principal->Text = L"menuStrip1";
			// 
			// GUI_fichier
			// 
			this->GUI_fichier->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->GUI_fichier_ouvrir, 
				this->toolStripSeparator2, this->GUI_fichier_enregistrer, this->GUI_fichier_enregistrer_sous, this->toolStripSeparator3, this->GUI_fichier_fermer, 
				this->toolStripSeparator1, this->GUI_fichier_quitter});
			this->GUI_fichier->Name = L"GUI_fichier";
			this->GUI_fichier->Size = System::Drawing::Size(50, 20);
			this->GUI_fichier->Text = L"Fichier";
			// 
			// GUI_fichier_ouvrir
			// 
			this->GUI_fichier_ouvrir->Name = L"GUI_fichier_ouvrir";
			this->GUI_fichier_ouvrir->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->GUI_fichier_ouvrir->Size = System::Drawing::Size(227, 22);
			this->GUI_fichier_ouvrir->Text = L"Ouvrir...";
			this->GUI_fichier_ouvrir->Click += gcnew System::EventHandler(this, &Form1::GUI_fichier_ouvrir_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(224, 6);
			// 
			// GUI_fichier_enregistrer
			// 
			this->GUI_fichier_enregistrer->Name = L"GUI_fichier_enregistrer";
			this->GUI_fichier_enregistrer->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->GUI_fichier_enregistrer->Size = System::Drawing::Size(227, 22);
			this->GUI_fichier_enregistrer->Text = L"Enregistrer";
			this->GUI_fichier_enregistrer->Click += gcnew System::EventHandler(this, &Form1::GUI_fichier_enregistrer_Click);
			// 
			// GUI_fichier_enregistrer_sous
			// 
			this->GUI_fichier_enregistrer_sous->Name = L"GUI_fichier_enregistrer_sous";
			this->GUI_fichier_enregistrer_sous->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::S));
			this->GUI_fichier_enregistrer_sous->Size = System::Drawing::Size(227, 22);
			this->GUI_fichier_enregistrer_sous->Text = L"Enregistrer sous...";
			this->GUI_fichier_enregistrer_sous->Click += gcnew System::EventHandler(this, &Form1::GUI_fichier_enregistrer_sous_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(224, 6);
			// 
			// GUI_fichier_fermer
			// 
			this->GUI_fichier_fermer->Name = L"GUI_fichier_fermer";
			this->GUI_fichier_fermer->Size = System::Drawing::Size(227, 22);
			this->GUI_fichier_fermer->Text = L"Fermer";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(224, 6);
			// 
			// GUI_fichier_quitter
			// 
			this->GUI_fichier_quitter->Name = L"GUI_fichier_quitter";
			this->GUI_fichier_quitter->ShortcutKeyDisplayString = L"Alt+F4";
			this->GUI_fichier_quitter->Size = System::Drawing::Size(227, 22);
			this->GUI_fichier_quitter->Text = L"Quitter";
			this->GUI_fichier_quitter->Click += gcnew System::EventHandler(this, &Form1::GUI_fichier_quitter_Click);
			// 
			// GUI_aide
			// 
			this->GUI_aide->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->GUI_a_propos});
			this->GUI_aide->Name = L"GUI_aide";
			this->GUI_aide->Size = System::Drawing::Size(24, 20);
			this->GUI_aide->Text = L"\?";
			// 
			// GUI_a_propos
			// 
			this->GUI_a_propos->Name = L"GUI_a_propos";
			this->GUI_a_propos->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->GUI_a_propos->Size = System::Drawing::Size(136, 22);
			this->GUI_a_propos->Text = L"À propos";
			this->GUI_a_propos->Click += gcnew System::EventHandler(this, &Form1::GUI_a_propos_Click);
			// 
			// GUI_liste_operations
			// 
			this->GUI_liste_operations->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->GUI_liste_operations->FormattingEnabled = true;
			this->GUI_liste_operations->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"Inverser les couleurs", L"Griser", 
				L"Echanger une couleur", L"Redimensionner", L"Monochromiser", L"Ne rien faire"});
			this->GUI_liste_operations->Location = System::Drawing::Point(176, 231);
			this->GUI_liste_operations->Name = L"GUI_liste_operations";
			this->GUI_liste_operations->Size = System::Drawing::Size(121, 21);
			this->GUI_liste_operations->TabIndex = 4;
			this->GUI_liste_operations->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::GUI_liste_operations_SelectedIndexChanged);
			// 
			// GUI_chemin_fichier_label
			// 
			this->GUI_chemin_fichier_label->AutoSize = true;
			this->GUI_chemin_fichier_label->Location = System::Drawing::Point(169, 35);
			this->GUI_chemin_fichier_label->Name = L"GUI_chemin_fichier_label";
			this->GUI_chemin_fichier_label->Size = System::Drawing::Size(135, 13);
			this->GUI_chemin_fichier_label->TabIndex = 5;
			this->GUI_chemin_fichier_label->Text = L"Chemin du fichier en cours:";
			// 
			// GUI_bouton_effectuer_tache
			// 
			this->GUI_bouton_effectuer_tache->Location = System::Drawing::Point(191, 260);
			this->GUI_bouton_effectuer_tache->Name = L"GUI_bouton_effectuer_tache";
			this->GUI_bouton_effectuer_tache->Size = System::Drawing::Size(90, 23);
			this->GUI_bouton_effectuer_tache->TabIndex = 6;
			this->GUI_bouton_effectuer_tache->Text = L"Effectuer tâche";
			this->GUI_bouton_effectuer_tache->UseVisualStyleBackColor = true;
			this->GUI_bouton_effectuer_tache->Click += gcnew System::EventHandler(this, &Form1::GUI_bouton_effectuer_tache_Click);
			// 
			// GUI_bouton_ouvrir
			// 
			this->GUI_bouton_ouvrir->AllowDrop = true;
			this->GUI_bouton_ouvrir->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"GUI_bouton_ouvrir.Image")));
			this->GUI_bouton_ouvrir->Location = System::Drawing::Point(440, 51);
			this->GUI_bouton_ouvrir->Name = L"GUI_bouton_ouvrir";
			this->GUI_bouton_ouvrir->Size = System::Drawing::Size(20, 20);
			this->GUI_bouton_ouvrir->TabIndex = 7;
			this->GUI_bouton_ouvrir->UseVisualStyleBackColor = true;
			this->GUI_bouton_ouvrir->Click += gcnew System::EventHandler(this, &Form1::GUI_fichier_ouvrir_Click);
			this->GUI_bouton_ouvrir->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::GUI_chemin_fichier_DragDrop);
			this->GUI_bouton_ouvrir->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::GUI_chemin_fichier_DragEnter);
			// 
			// GUI_liste_operations_label
			// 
			this->GUI_liste_operations_label->AutoSize = true;
			this->GUI_liste_operations_label->Location = System::Drawing::Point(158, 207);
			this->GUI_liste_operations_label->Name = L"GUI_liste_operations_label";
			this->GUI_liste_operations_label->Size = System::Drawing::Size(156, 13);
			this->GUI_liste_operations_label->TabIndex = 8;
			this->GUI_liste_operations_label->Text = L"Choix de l\'opération à effectuer:";
			// 
			// GUI_bouton_apercu
			// 
			this->GUI_bouton_apercu->Location = System::Drawing::Point(211, 294);
			this->GUI_bouton_apercu->Name = L"GUI_bouton_apercu";
			this->GUI_bouton_apercu->Size = System::Drawing::Size(51, 23);
			this->GUI_bouton_apercu->TabIndex = 9;
			this->GUI_bouton_apercu->Text = L"Aperçu";
			this->GUI_bouton_apercu->UseVisualStyleBackColor = true;
			this->GUI_bouton_apercu->Click += gcnew System::EventHandler(this, &Form1::GUI_bouton_apercu_Click);
			// 
			// GUI_toolTip
			// 
			this->GUI_toolTip->AutoPopDelay = 10000;
			this->GUI_toolTip->InitialDelay = 500;
			this->GUI_toolTip->ReshowDelay = 100;
			this->GUI_toolTip->UseAnimation = false;
			this->GUI_toolTip->UseFading = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(472, 333);
			this->Controls->Add(this->GUI_bouton_apercu);
			this->Controls->Add(this->GUI_liste_operations_label);
			this->Controls->Add(this->GUI_bouton_ouvrir);
			this->Controls->Add(this->GUI_bouton_effectuer_tache);
			this->Controls->Add(this->GUI_chemin_fichier_label);
			this->Controls->Add(this->GUI_liste_operations);
			this->Controls->Add(this->GUI_chemin_fichier);
			this->Controls->Add(this->GUI_menu_principal);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->GUI_menu_principal;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Editeur d\'images passif";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->GUI_menu_principal->ResumeLayout(false);
			this->GUI_menu_principal->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		} //InitializeComponent
#pragma endregion

	private:

		/// <summary>
		/// Initialisation d'éléments personnalisés (non automatisés par Visual Studio)
		/// </summary>

		void InitializeComponent2(void) {
			GUI_liste_operations->SelectedIndex=GUI_liste_operations->Items->Count-1;
			GUI_toolTip->SetToolTip(GUI_liste_operations,L"Ne change rien à l'image");
			GUI_toolTip->SetToolTip(GUI_bouton_apercu,L"Affiche l'image telle qu'elle sera après la modification actuellement sélectionnée");
			GUI_toolTip->SetToolTip(GUI_bouton_effectuer_tache,L"Effectue l'opération choisie.Placer le curseur sur la liste pour plus d'informations.");
			image_bitmap=gcnew ImgConvTools::Bitmap_partage;
			bImageSauvee=true;
		}

#pragma region Ecouteurs de composants de Form1

	private: 

		/// <summary>
		/// Gestion de la commande Fichier/Ouvrir
		/// </summary>

		System::Void GUI_fichier_ouvrir_Click(System::Object^  sender, System::EventArgs^  e) {

			//boite de dialogue d'ouverture d'image,démarre sur les *.png,à priori supporte les .bmp,.png,.jpg et peut-être d'autres
			OpenFileDialog^ ofn = gcnew OpenFileDialog();
			ofn->Filter = L"Bitmap (*.bmp)|*.bmp|PNG (*.png)|*.png|JPEG (*.jpg,*.jpeg)|*.jpg;*.jpeg|GIF (*.gif)|*.gif|TIFF (*.tiff,*.tif)|*.tif;*.tiff|Tous fichiers (*.*)|*.*";
			ofn->FilterIndex = 6;
			ofn->ShowDialog();

			if (ofn->FileName != "") {

				//réussite de récupération du nom de fichier
				GUI_chemin_fichier->Text=ofn->FileName;

				//charger l'image dans la variable image_bitmap
				Ouvrir_image();
			}
		} //GUI_fichier_ouvrir_Click

	private: 

		/// <summary>
		/// Gestion de la commande Fichier/Enregistrer
		/// </summary>

		System::Void GUI_fichier_enregistrer_Click(System::Object^  sender, System::EventArgs^  e) {
			if (GUI_chemin_fichier->Text!="") {
				try {
					image_bitmap->image->Save(GUI_chemin_fichier->Text,image_bitmap->image->RawFormat);
					bImageSauvee=true;
				}
				catch (Exception^) {
					MessageBox::Show(L"Erreur,la sauvegarde de l'image a échoué",L"Erreur");
				}
			}
		} //GUI_fichier_enregistrer_Click

	private: 

		/// <summary>
		/// Gestion de la commande Fichier/Enregistrer sous
		/// </summary>

		System::Void GUI_fichier_enregistrer_sous_Click(System::Object^  sender, System::EventArgs^  e) {

			System::Windows::Forms::DialogResult choix;
			bool bFormatConnu=true;

			SaveFileDialog^ enregistrer_fichier=gcnew SaveFileDialog();

			//Configuration de la boite de dialogue d'enregistrement de fichier
			enregistrer_fichier->Filter=L"Bitmap (*.bmp)|*.bmp|PNG (*.png)|*.png|JPEG (*.jpg,*.jpeg)|*.jpg;*.jpeg|GIF (*.gif)|*.gif|TIFF (*.tiff,*.tif)|*.tif;*.tiff";

			if (System::IO::Path::GetExtension(GUI_chemin_fichier->Text)==L".bmp")
				enregistrer_fichier->FilterIndex=1;else
			if (System::IO::Path::GetExtension(GUI_chemin_fichier->Text)==L".png")
				enregistrer_fichier->FilterIndex=2;else
			if (System::IO::Path::GetExtension(GUI_chemin_fichier->Text)==L".jpg")
				enregistrer_fichier->FilterIndex=3;else
			if (System::IO::Path::GetExtension(GUI_chemin_fichier->Text)==L".jpeg")
				enregistrer_fichier->FilterIndex=3;else
			if (System::IO::Path::GetExtension(GUI_chemin_fichier->Text)==L".gif")
				enregistrer_fichier->FilterIndex=4;else
			if (System::IO::Path::GetExtension(GUI_chemin_fichier->Text)==L".tiff")
				enregistrer_fichier->FilterIndex=5;else
			if (System::IO::Path::GetExtension(GUI_chemin_fichier->Text)==L".tif")
				enregistrer_fichier->FilterIndex=5;
			else {
				enregistrer_fichier->FilterIndex=2; //par défaut,sauve en .png
				bFormatConnu=false;
			}

			
			//if(System::IO::Path::GetExtension(GUI_chemin_fichier->Text)==".bmp")

			//enregistrer_fichier->FilterIndex = 6;					//6=Format d'origine
			if (bFormatConnu)
				enregistrer_fichier->FileName=GUI_chemin_fichier->Text;	//Nom de fichier par défaut=ancien nom
			else
				enregistrer_fichier->FileName=String::Format("{0}.png",System::IO::Path::GetFileNameWithoutExtension(GUI_chemin_fichier->Text));

			enregistrer_fichier->RestoreDirectory=true;

			//Affiche la boite de dialogue et sauvegarde le résultat des actions effectuées dans la variable choix
			choix=enregistrer_fichier->ShowDialog();

			//Si le choix d'un fichier dans lequel enregistrer a réussi
			if (choix==System::Windows::Forms::DialogResult::OK) {

				GUI_chemin_fichier->Text=enregistrer_fichier->FileName;

				try {

					switch (enregistrer_fichier->FilterIndex) {

						case 1://BMP
							image_bitmap->image->Save(GUI_chemin_fichier->Text,System::Drawing::Imaging::ImageFormat::Bmp);
							break;

						case 2: //PNG
							image_bitmap->image->Save(GUI_chemin_fichier->Text,System::Drawing::Imaging::ImageFormat::Png);
							break;

						case 3: //JPEG
							image_bitmap->image->Save(GUI_chemin_fichier->Text,System::Drawing::Imaging::ImageFormat::Jpeg);
							break;

						case 4: //GIF
							image_bitmap->image->Save(GUI_chemin_fichier->Text,System::Drawing::Imaging::ImageFormat::Gif);
							break;

						case 5: //TIFF
							image_bitmap->image->Save(GUI_chemin_fichier->Text,System::Drawing::Imaging::ImageFormat::Tiff);
							break;

					}

					bImageSauvee=true;

				}
				catch (Exception^) {
					MessageBox::Show(L"Erreur,la sauvegarde de l'image a échoué",L"Erreur");
				}

			} //if (choix==System::Windows::Forms::DialogResult::OK)

		} //GUI_fichier_enregistrer_sous_Click

	private: 

		/// <summary>
		/// Gestion de la commande Fichier/Quitter
		/// </summary>

		System::Void GUI_fichier_quitter_Click(System::Object^  sender, System::EventArgs^  e) {
			Application::Exit();
		} //GUI_fichier_quitter_Click

	private: 

		/// <summary>
		/// Gestion de la commande Fichier/A propos
		/// </summary>

		System::Void GUI_a_propos_Click(System::Object^  sender, System::EventArgs^  e) {
			MessageBox::Show(L"Programme développé par Damien Barral\nIcônes provenant du site:\nhttp://www.famfamfam.com/lab/icons/silk",L"À propos",MessageBoxButtons::OK,MessageBoxIcon::Information);
		} //GUI_a_propos_Click

	private: 

		/// <summary>
		/// Gestion du cliquer-déplacer d'un fichier sur la zone de chemin de fichier
		/// Evènement qui survient après DragEnter quand le bouton de la souris est relâché
		/// </summary>

		System::Void GUI_chemin_fichier_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {

			//Le drag&drop peut contenir plusieurs fichiers,donc il faut utiliser un tableau
			array<String^>^ fichiers_deplaces=gcnew array<String^>(1);

			//on récupère les données de type inconnu du drag&drop en les convertissant en tableau de chaines
			fichiers_deplaces=(array<String^>^)e->Data->GetData(DataFormats::FileDrop);

			if (fichiers_deplaces->Length!=1)
				MessageBox::Show(L"Impossible d'ouvrir plusieurs fichiers en même temps!",L"Erreur",MessageBoxButtons::OK,MessageBoxIcon::Exclamation);
			else {

				//Demande de confirmation que l'on veut bien ouvrir le fichier sélectionné
				System::Windows::Forms::DialogResult choix;
				choix=MessageBox::Show(String::Format(L"Ouvrir le fichier {0}?",fichiers_deplaces[0]),L"Cliquer-Déplacer",MessageBoxButtons::YesNo);
				if (choix==System::Windows::Forms::DialogResult::Yes) {

					//Si aucun fichier n'est ouvert,la réponse à "voulez-vous enregistrer?" est Non.
					choix=System::Windows::Forms::DialogResult::No;

					if (GUI_chemin_fichier->Text!="" && !bImageSauvee)
						choix=MessageBox::Show(String::Format(L"Le fichier {0} est déjà ouvert.Enregistrer ses modifications?",GUI_chemin_fichier->Text),L"Cliquer-Déplacer",MessageBoxButtons::YesNoCancel);

					if (choix!=System::Windows::Forms::DialogResult::Cancel) {

						//enregistre l'image précédente
						if (choix==System::Windows::Forms::DialogResult::Yes)
							GUI_fichier_enregistrer_Click(sender,e);

						//Mise à jour du nom de fichier ouvert (pour que l'ouverture de fichier fonctionne)
						GUI_chemin_fichier->Text=fichiers_deplaces[0];

						//Chargement de la nouvelle image
						Ouvrir_image();

						//Pas de modifications pour le moment sur la nouvelle image
						bImageSauvee=true;

					}
					else
						MessageBox::Show(String::Format(L"Le fichier {0} n'a pas été ouvert.",fichiers_deplaces[0]),L"Annulation cliquer-déplacer");
				} //confirmation que l'on veut ouvrir le fichier
			} //fichiers_deplaces->Length!=1
		} //GUI_chemin_fichier_DragDrop

	private: 

		/// <summary>
		/// Gestion du cliquer-glisser d'un fichier sur la zone de chemin de fichier
		/// Le bouton n'a pas encore été relâché (cas de l'évènement DragDrop)
		/// </summary>

		System::Void GUI_chemin_fichier_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^  e) {
			if (e->Data->GetDataPresent(DataFormats::FileDrop))
				e->Effect = DragDropEffects::Copy;
		} //GUI_chemin_fichier_DragEnter

	private:

		/// <summary>
		/// Gestion du bouton Effectuer tâche
		/// </summary>

		System::Void GUI_bouton_effectuer_tache_Click(System::Object^  sender, System::EventArgs^  e) {

			if (image_bitmap->image) {
				switch(GUI_liste_operations->SelectedIndex) {

					//Inverser les couleurs
					case 0:	{
						image_bitmap->image=ImgConvTools::Inverser_couleurs(image_bitmap->image/*,valeur_progression*/);
						MessageBox::Show(L"L'inversion des couleurs a été effectuée\nEnregistrez l'image pour voir les modifications",L"Opération réussie");
						bImageSauvee=false; //permet d'afficher l'avertissement comme quoi l'image n'a pas été sauvée
						break;
					}

					//Griser
					case 1: {
						ImgConvParametresGris^ ecran_parametres=gcnew ImgConvParametresGris(image_bitmap->image);
						if(ecran_parametres) {
							if ( ecran_parametres->ShowDialog() == ::DialogResult::OK )
								bImageSauvee=false; //permet d'afficher l'avertissement comme quoi l'image n'a pas été sauvée
							delete ecran_parametres;
						}
						break;
					}

					//Echanger une couleur
					case 2: {
						
						ImgConvEchangeCouleurs^ ecran_parametres=gcnew ImgConvEchangeCouleurs(image_bitmap->image);
						if(ecran_parametres) {
							if ( ecran_parametres->ShowDialog() == ::DialogResult::OK )
								bImageSauvee=false; //permet d'afficher l'avertissement comme quoi l'image n'a pas été sauvée
							delete ecran_parametres;
						}
						
						break;
					}

					//Redimensionnement
					case 3: {

						ImgConvRedim^ ecran_parametres=gcnew ImgConvRedim(image_bitmap);
						if(ecran_parametres) {
							if ( ecran_parametres->ShowDialog() == ::DialogResult::OK )
								bImageSauvee=false; //permet d'afficher l'avertissement comme quoi l'image n'a pas été sauvée
							delete ecran_parametres;
						}
						break;
					}

					//Monochromiser
					case 4: {

						ImgConvMonochrome^ ecran_parametres=gcnew ImgConvMonochrome(image_bitmap->image);
						if(ecran_parametres) {
							if ( ecran_parametres->ShowDialog() == ::DialogResult::OK )
								bImageSauvee=false; //permet d'afficher l'avertissement comme quoi l'image n'a pas été sauvée
							delete ecran_parametres;
						}
						break;
					}

					//Rien à faire
					case 5:
						MessageBox::Show(L"Le programme est parvenu avec succès à ne rien faire.",L"Opération réussie");
						break;

					default:
						MessageBox::Show(L"Choisissez une action à effectuer auparavant",L"Aucune action sélectionnée");
						break;

				} //switch(GUI_liste_operations->SelectedIndex)
			}
			else
				MessageBox::Show(L"Ouvrez une image à modifier avant.",L"Aucune image ouverte");

		}//GUI_bouton_effectuer_tache_Click

	private: 

		/// <summary>
		/// Changement de l'info-bulle en fonction de la sélection
		/// </summary>

		System::Void GUI_liste_operations_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

			switch(GUI_liste_operations->SelectedIndex) { //0=inverser les couleurs,1=griser,2=échanger une couleur
				
				case 0:
					GUI_toolTip->SetToolTip(GUI_liste_operations,L"Inverse les couleurs de l'image (255-chaque couleur)");
					break;

				case 1:
					GUI_toolTip->SetToolTip(GUI_liste_operations,L"Colore l'image en niveaux de gris,selon plusieurs algorithmes");
					break;

				case 2:
					GUI_toolTip->SetToolTip(GUI_liste_operations,L"Echange un type de couleur dans l'image,voir menu avancé");
					break;

				case 3:
					GUI_toolTip->SetToolTip(GUI_liste_operations,L"Redimensionne une image");
					break;

				case 4:
					GUI_toolTip->SetToolTip(GUI_liste_operations,L"Colore l'image en 1 dégradé d'une couleur,basé sur les niveaux de gris");
					break;

				default:
					GUI_toolTip->SetToolTip(GUI_liste_operations,L"Ne change rien à l'image");
					break;
			}

		}//GUI_liste_operations_SelectedIndexChanged

	private:

		/// <summary>
		/// Intercepte la fermeture de l'application si des modifications n'ont pas été sauvées
		/// </summary>

		System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

			System::Windows::Forms::DialogResult choix=System::Windows::Forms::DialogResult::No;

			if (!bImageSauvee)
				choix=MessageBox::Show(L"Enregistrer les modifications avant de quitter?",L"Quitter",MessageBoxButtons::YesNoCancel);

			if (choix!=System::Windows::Forms::DialogResult::Cancel) {

				if (choix==System::Windows::Forms::DialogResult::Yes) //enregistre l'image précédente
					GUI_fichier_enregistrer_sous_Click(sender,e);

			}
			else
				e->Cancel=true;

		}//Form1_FormClosing

	private: 

		/// <summary>
		/// Gestion du bouton Aperçu
		/// </summary>

		System::Void GUI_bouton_apercu_Click(System::Object^  sender, System::EventArgs^  e) {

			if (image_bitmap->image) {

				//créé une copie de l'image,modifiée pour l'aperçu
				Bitmap^ image_apercu=gcnew Bitmap(image_bitmap->image);

				switch (GUI_liste_operations->SelectedIndex) {

					case 0: //inverser couleurs
						ImgConvTools::Inverser_couleurs(image_apercu);
						MessageBox::Show(L"Inversion des couleurs réussie,cliquer sur OK pour voir l'aperçu.",L"Création de l'aperçu réussie");
						break;

					default: //pas de modifications
						MessageBox::Show(L"L'image sera affichée telle qu'elle est actuellement.",L"Pas de modification pour l'aperçu");
						break;

				}

				ImgConvApercu^ fenetre_apercu=gcnew ImgConvApercu(image_apercu);
				fenetre_apercu->ShowDialog();

				//Nettoie les éléments utilisés pour l'aperçu
				delete fenetre_apercu;
				delete image_apercu;
			}
			else
				MessageBox::Show(L"Aucun aperçu disponible,chargez une image avant tout",L"Aperçu");

		}//GUI_bouton_apercu_Click

#pragma endregion //Ecouteurs de composants de Form1

#pragma region Fonctions interagissant avec les membres privés de Form1

	public:

		/// <summary>
		/// Fonction qui charge une image en mémoire depuis le fichier dont le
		/// chemin figure dans le champ texte GUI_chemin_fichier
		/// </summary>

		void Ouvrir_image() {

			//variable de stockage de l'image créée depuis le fichier
			Bitmap^ image_bitmap_fichier;
			
			try {

				//créé une image depuis le fichier sélectionné
				image_bitmap_fichier=gcnew Bitmap(GUI_chemin_fichier->Text);

				//créé l'image qui sera modifié à partir de la précédente
				image_bitmap->image=gcnew Bitmap(image_bitmap_fichier);

				//supprime l'image créée depuis le fichier,pour permettre la sauvegarde sur le fichier
				delete image_bitmap_fichier;

			}
			catch ( ArgumentException^ ) {
				MessageBox::Show(L"Erreur lors du chargement de l'image",L"Erreur");
				GUI_chemin_fichier->Text="";
			}
		}

#pragma endregion //Fonctions interagissant avec les membres privés de Form1

	}; //public ref class Form1 : public System::Windows::Forms::Form
} //namespace ImgConv

