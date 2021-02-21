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
	/// Description résumée de ImgConvMonochrome
	///
	/// AVERTISSEMENT : si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propriété 'Nom du fichier de ressources' de l'outil de compilation de ressource managée
	///          pour tous les fichiers .resx dont dépend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localisées associées à ce formulaire.
	/// </summary>
	public ref class ImgConvMonochrome : public System::Windows::Forms::Form
	{
	public:
		ImgConvMonochrome(void){
			InitializeComponent();
			InitializeComponent2();
		}

	public:
		ImgConvMonochrome(System::Drawing::Bitmap^ source) {
			InitializeComponent();
			image_bitmap=source;
			InitializeComponent2();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~ImgConvMonochrome() {
			if (components)
				delete components;
		}



    /// <summary>
	/// Variables du programme général.
	/// </summary>
	public: Bitmap^ image_bitmap;	//image actuellement traitée

	/// <summary>
	/// Variables nécessaires au concepteur.
	/// </summary>

	private: System::Windows::Forms::Label^  GUI_params_label;
	private: System::Windows::Forms::ToolTip^  GUI_params_toolTip1;
	private: System::Windows::Forms::Button^  GUI_params_bouton_apercu;
	private: System::Windows::Forms::Button^  GUI_params_bouton_effectuer_tache;
	private: System::Windows::Forms::ListBox^  GUI_params_liste;
	private: System::Windows::Forms::CheckBox^  GUI_params_checkBox_inverser_couleurs;

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
			this->GUI_params_label = (gcnew System::Windows::Forms::Label());
			this->GUI_params_toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->GUI_params_bouton_apercu = (gcnew System::Windows::Forms::Button());
			this->GUI_params_bouton_effectuer_tache = (gcnew System::Windows::Forms::Button());
			this->GUI_params_liste = (gcnew System::Windows::Forms::ListBox());
			this->GUI_params_checkBox_inverser_couleurs = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// GUI_params_label
			// 
			this->GUI_params_label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GUI_params_label->AutoSize = true;
			this->GUI_params_label->Location = System::Drawing::Point(-2, 9);
			this->GUI_params_label->Name = L"GUI_params_label";
			this->GUI_params_label->Size = System::Drawing::Size(247, 13);
			this->GUI_params_label->TabIndex = 0;
			this->GUI_params_label->Text = L"Types de transformations monochrome disponibles:";
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
			this->GUI_params_bouton_apercu->Location = System::Drawing::Point(96, 175);
			this->GUI_params_bouton_apercu->Name = L"GUI_params_bouton_apercu";
			this->GUI_params_bouton_apercu->Size = System::Drawing::Size(51, 23);
			this->GUI_params_bouton_apercu->TabIndex = 13;
			this->GUI_params_bouton_apercu->Text = L"Aperçu";
			this->GUI_params_bouton_apercu->UseVisualStyleBackColor = true;
			this->GUI_params_bouton_apercu->Click += gcnew System::EventHandler(this, &ImgConvMonochrome::GUI_bouton_apercu_Click);
			// 
			// GUI_params_bouton_effectuer_tache
			// 
			this->GUI_params_bouton_effectuer_tache->Location = System::Drawing::Point(76, 146);
			this->GUI_params_bouton_effectuer_tache->Name = L"GUI_params_bouton_effectuer_tache";
			this->GUI_params_bouton_effectuer_tache->Size = System::Drawing::Size(90, 23);
			this->GUI_params_bouton_effectuer_tache->TabIndex = 12;
			this->GUI_params_bouton_effectuer_tache->Text = L"Effectuer tâche";
			this->GUI_params_bouton_effectuer_tache->UseVisualStyleBackColor = true;
			this->GUI_params_bouton_effectuer_tache->Click += gcnew System::EventHandler(this, &ImgConvMonochrome::GUI_params_bouton_effectuer_tache_Click);
			// 
			// GUI_params_liste
			// 
			this->GUI_params_liste->Items->AddRange(gcnew cli::array< System::Object^  >(25) {L"Dégradé blanc=>rouge", L"Dégradé rouge=>blanc", 
				L"Dégradé rouge=>noir", L"Dégradé noir=>rouge", L"Dégradé blanc=>vert", L"Dégradé vert=>blanc", L"Dégradé vert=>noir", L"Dégradé noir=>vert", 
				L"Dégradé blanc=>bleu", L"Dégradé bleu=>blanc", L"Dégradé bleu=>noir", L"Dégradé noir=>bleu", L"Dégradé blanc=>jaune", L"Dégradé jaune=>blanc", 
				L"Dégradé jaune=>noir", L"Dégradé noir=>jaune", L"Dégradé blanc=>violet", L"Dégradé violet=>blanc", L"Dégradé violet=>noir", 
				L"Dégradé noir=>violet", L"Dégradé blanc=>cyan", L"Dégradé cyan=>blanc", L"Dégradé cyan=>noir", L"Dégradé noir=>cyan", L"Ne rien faire"});
			this->GUI_params_liste->Location = System::Drawing::Point(17, 30);
			this->GUI_params_liste->Name = L"GUI_params_liste";
			this->GUI_params_liste->Size = System::Drawing::Size(208, 82);
			this->GUI_params_liste->TabIndex = 10;
			this->GUI_params_liste->SelectedIndexChanged += gcnew System::EventHandler(this, &ImgConvMonochrome::GUI_params_liste_SelectedIndexChanged);
			// 
			// GUI_params_checkBox_inverser_couleurs
			// 
			this->GUI_params_checkBox_inverser_couleurs->AutoSize = true;
			this->GUI_params_checkBox_inverser_couleurs->Location = System::Drawing::Point(60, 121);
			this->GUI_params_checkBox_inverser_couleurs->Name = L"GUI_params_checkBox_inverser_couleurs";
			this->GUI_params_checkBox_inverser_couleurs->Size = System::Drawing::Size(123, 17);
			this->GUI_params_checkBox_inverser_couleurs->TabIndex = 11;
			this->GUI_params_checkBox_inverser_couleurs->Text = L"Inverser les couleurs";
			this->GUI_params_checkBox_inverser_couleurs->UseVisualStyleBackColor = true;
			// 
			// ImgConvMonochrome
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(242, 206);
			this->Controls->Add(this->GUI_params_checkBox_inverser_couleurs);
			this->Controls->Add(this->GUI_params_liste);
			this->Controls->Add(this->GUI_params_bouton_apercu);
			this->Controls->Add(this->GUI_params_bouton_effectuer_tache);
			this->Controls->Add(this->GUI_params_label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ImgConvMonochrome";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Monochromiser";
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

			GUI_params_liste->SelectedIndex::set(24);
			GUI_params_toolTip1->SetToolTip(GUI_params_checkBox_inverser_couleurs,L"Inverse les couleurs lors d'une transofrmation.Donne un effet similaire à une autre option de la liste.");
			GUI_params_toolTip1->SetToolTip(GUI_params_liste,L"Sélectionner une action et placez la souris sur le bouton effectuer tâche pour plus d'informations.");
			GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Ne fais rien et retourne à la fenêtre principale.");
			GUI_params_toolTip1->SetToolTip(GUI_params_bouton_apercu,L"Affiche l'image modifiée par la tâche sélectionnée");

		}

#pragma region Ecouteurs de ImgConvMonochrome

	private: 

		/// <summary>
		/// Gère le bouton Effectuer Tâche
		/// </summary>

		System::Void GUI_params_bouton_effectuer_tache_Click(System::Object^  sender, System::EventArgs^  e) {

			if (GUI_params_liste->SelectedIndex>=0 && GUI_params_liste->SelectedIndex<=23) {

			// 0:Dégradé blanc=>rouge
			// 1:Dégradé rouge=>blanc
			// 2:Dégradé rouge=>noir
			// 3:Dégradé noir=>rouge
			// 4:Dégradé blanc=>vert
			// 5:Dégradé vert=>blanc
			// 6:Dégradé vert=>noir
			// 7:Dégradé noir=>vert
			// 8:Dégradé blanc=>bleu
			// 9:Dégradé bleu=>blanc
			//10:Dégradé bleu=>noir
			//11:Dégradé noir=>bleu
			//12:Dégradé blanc=>jaune
			//13:Dégradé jaune=>blanc
			//14:Dégradé jaune=>noir
			//15:Dégradé noir=>jaune
			//16:Dégradé blanc=>violet
			//17:Dégradé violet=>blanc
			//18:Dégradé violet=>noir
			//19:Dégradé noir=>violet
			//20:Dégradé blanc=>cyan
			//21:Dégradé cyan=>blanc
			//22:Dégradé cyan=>noir
			//23:Dégradé noir=>cyan
			//24:Ne rien faire

				ImgConvTools::Monochrome(image_bitmap,GUI_params_liste->SelectedIndex,GUI_params_checkBox_inverser_couleurs->Checked); 
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

		System::Void GUI_params_liste_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

			switch(GUI_params_liste->SelectedIndex) {

			// 0:Dégradé blanc=>rouge
			// 1:Dégradé rouge=>blanc
			// 2:Dégradé rouge=>noir
			// 3:Dégradé noir=>rouge
			// 4:Dégradé blanc=>vert
			// 5:Dégradé vert=>blanc
			// 6:Dégradé vert=>noir
			// 7:Dégradé noir=>vert
			// 8:Dégradé blanc=>bleu
			// 9:Dégradé bleu=>blanc
			//10:Dégradé bleu=>noir
			//11:Dégradé noir=>bleu
			//12:Dégradé blanc=>jaune
			//13:Dégradé jaune=>blanc
			//14:Dégradé jaune=>noir
			//15:Dégradé noir=>jaune
			//16:Dégradé blanc=>violet
			//17:Dégradé violet=>blanc
			//18:Dégradé violet=>noir
			//19:Dégradé noir=>violet
			//20:Dégradé blanc=>cyan
			//21:Dégradé cyan=>blanc
			//22:Dégradé cyan=>noir
			//23:Dégradé noir=>cyan
			//24:Ne rien faire

				case 0:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du blanc au rouge");
					break;

				case 1:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du rouge au blanc");
					break;

				case 2:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du rouge au noir");
					break;

				case 3:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du noir au rouge");
					break;

				case 4:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du blanc au vert");
					break;

				case 5:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du vert au blanc");
					break;

				case 6:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du vert au noir");
					break;

				case 7:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du noir au vert");
					break;

				case 8:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du blanc au bleu");
					break;

				case 9:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du bleu au blanc");
					break;

				case 10:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du bleu au noir");
					break;

				case 11:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du noir au bleu");
					break;

				case 12:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du blanc au jaune");
					break;

				case 13:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du jaune au blanc");
					break;

				case 14:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du jaune au noir");
					break;

				case 15:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du noir au jaune");
					break;

				case 16:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du blanc au violet");
					break;

				case 17:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du violet au blanc");
					break;

				case 18:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du violet au noir");
					break;

				case 19:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du noir au violet");
					break;

				case 20:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du blanc au cyan");
					break;

				case 21:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du cyan au blanc");
					break;

				case 22:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du cyan au noir");
					break;

				case 23:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Transforme l'image en un dégradé d'une couleur allant du noir au cyan");
					break;

				default:
					GUI_params_toolTip1->SetToolTip(GUI_params_bouton_effectuer_tache,L"Ne fais rien et retourne à la fenêtre principale.");
					break;
			}
		} //GUI_params_liste_SelectedIndexChanged

	private: 

		/// <summary>
		/// Gestion du bouton Aperçu
		/// </summary>

		System::Void GUI_bouton_apercu_Click(System::Object^  sender, System::EventArgs^  e) {

			// 0:Dégradé blanc=>rouge
			// 1:Dégradé rouge=>blanc
			// 2:Dégradé rouge=>noir
			// 3:Dégradé noir=>rouge
			// 4:Dégradé blanc=>vert
			// 5:Dégradé vert=>blanc
			// 6:Dégradé vert=>noir
			// 7:Dégradé noir=>vert
			// 8:Dégradé blanc=>bleu
			// 9:Dégradé bleu=>blanc
			//10:Dégradé bleu=>noir
			//11:Dégradé noir=>bleu
			//12:Dégradé blanc=>jaune
			//13:Dégradé jaune=>blanc
			//14:Dégradé jaune=>noir
			//15:Dégradé noir=>jaune
			//16:Dégradé blanc=>violet
			//17:Dégradé violet=>blanc
			//18:Dégradé violet=>noir
			//19:Dégradé noir=>violet
			//20:Dégradé blanc=>cyan
			//21:Dégradé cyan=>blanc
			//22:Dégradé cyan=>noir
			//23:Dégradé noir=>cyan
			//24:Ne rien faire

			Bitmap^ image_apercu = gcnew Bitmap(image_bitmap);
			ImgConvTools::Monochrome(image_apercu,GUI_params_liste->SelectedIndex,GUI_params_checkBox_inverser_couleurs->Checked); 

			ImgConvApercu^ fenetre_apercu=gcnew ImgConvApercu(image_apercu);
			fenetre_apercu->ShowDialog();

			delete fenetre_apercu;
			delete image_apercu;

		}//GUI_bouton_apercu_Click

	}; //ImgConvMonochrome

#pragma endregion //Ecouteurs de ImgConvMonochrome

} //namespace ImgConv