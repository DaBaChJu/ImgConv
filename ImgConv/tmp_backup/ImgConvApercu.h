#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ImgConv {

	/// <summary>
	/// Description r�sum�e de ImgConvApercu
	///
	/// AVERTISSEMENT�: si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propri�t� 'Nom du fichier de ressources' de l'outil de compilation de ressource manag�e
	///          pour tous les fichiers .resx dont d�pend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localis�es associ�es � ce formulaire.
	/// </summary>
	public ref class ImgConvApercu : public System::Windows::Forms::Form {

	public:
		/// <summary>
		/// Constructeur par d�faut
		/// </summary>
		ImgConvApercu(void) {
			InitializeComponent();
		}

	public:
		/// <summary>
		/// Constructeur personnalis�
		/// </summary>
		ImgConvApercu(Bitmap^ image_en_cours) {

			InitializeComponent();

			int nWidthMin,nHeightMin;
			int nNewWidthMax,nNewHeightMax;

			nWidthMin=image_en_cours->Size.Width+10;
			nHeightMin=image_en_cours->Size.Height+30+GUI_apercuimage_bouton->Size.Height;

			//r�cup�re la zone d'affichage maximale
			Rectangle screen_res=Screen::AllScreens[0]->WorkingArea;

			nNewWidthMax=screen_res.Width;
			nNewHeightMax=screen_res.Height;

			if(nWidthMin > (90*screen_res.Width)/100)
				nNewWidthMax = (90*screen_res.Width)/100;

			if(nHeightMin > (90*screen_res.Height)/100)
				nNewHeightMax = (90*screen_res.Height)/100;

			this->MaximumSize = System::Drawing::Size(nNewWidthMax,nNewHeightMax);
			
			GUI_apercuimage_pictureBox->Image=image_en_cours;
			GUI_apercuimage_panel1->Controls->Add(GUI_apercuimage_pictureBox);

		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilis�es.
		/// </summary>
		~ImgConvApercu() {
			if (components) {
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable n�cessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

		/// <summary>
		/// Composants graphiques
		/// </summary>
	private: System::Windows::Forms::Button^  GUI_apercuimage_bouton;
	private: System::Windows::Forms::Panel^  GUI_apercuimage_panel1;





	private: System::Windows::Forms::PictureBox^  GUI_apercuimage_pictureBox;





	/// <summary>
	/// Variables du programme g�n�ral.
	/// </summary>
	//public: Bitmap^ image_bitmap;	//image actuellement trait�e

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�thode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette m�thode avec l'�diteur de code.
		/// </summary>
		void InitializeComponent(void) {
			this->GUI_apercuimage_bouton = (gcnew System::Windows::Forms::Button());
			this->GUI_apercuimage_pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->GUI_apercuimage_panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GUI_apercuimage_pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// GUI_apercuimage_bouton
			// 
			this->GUI_apercuimage_bouton->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->GUI_apercuimage_bouton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->GUI_apercuimage_bouton->Location = System::Drawing::Point(38, 79);
			this->GUI_apercuimage_bouton->MaximumSize = System::Drawing::Size(75, 23);
			this->GUI_apercuimage_bouton->MinimumSize = System::Drawing::Size(75, 23);
			this->GUI_apercuimage_bouton->Name = L"GUI_apercuimage_bouton";
			this->GUI_apercuimage_bouton->Size = System::Drawing::Size(75, 23);
			this->GUI_apercuimage_bouton->TabIndex = 1;
			this->GUI_apercuimage_bouton->Text = L"Retour";
			this->GUI_apercuimage_bouton->UseVisualStyleBackColor = true;
			// 
			// GUI_apercuimage_pictureBox
			// 
			this->GUI_apercuimage_pictureBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GUI_apercuimage_pictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->GUI_apercuimage_pictureBox->Location = System::Drawing::Point(31, 8);
			this->GUI_apercuimage_pictureBox->Margin = System::Windows::Forms::Padding(0);
			this->GUI_apercuimage_pictureBox->Name = L"GUI_apercuimage_pictureBox";
			this->GUI_apercuimage_pictureBox->Size = System::Drawing::Size(89, 64);
			this->GUI_apercuimage_pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->GUI_apercuimage_pictureBox->TabIndex = 2;
			this->GUI_apercuimage_pictureBox->TabStop = false;
			// 
			// GUI_apercuimage_panel1
			// 
			this->GUI_apercuimage_panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GUI_apercuimage_panel1->AutoScroll = true;
			this->GUI_apercuimage_panel1->AutoSize = true;
			this->GUI_apercuimage_panel1->Location = System::Drawing::Point(71, 36);
			this->GUI_apercuimage_panel1->Name = L"GUI_apercuimage_panel1";
			this->GUI_apercuimage_panel1->Size = System::Drawing::Size(8, 8);
			this->GUI_apercuimage_panel1->TabIndex = 3;
			// 
			// ImgConvApercu
			// 
			this->AcceptButton = this->GUI_apercuimage_bouton;
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoScroll = true;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->CancelButton = this->GUI_apercuimage_bouton;
			this->ClientSize = System::Drawing::Size(150, 131);
			this->Controls->Add(this->GUI_apercuimage_panel1);
			this->Controls->Add(this->GUI_apercuimage_bouton);
			this->Controls->Add(this->GUI_apercuimage_pictureBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->MinimumSize = System::Drawing::Size(160, 160);
			this->Name = L"ImgConvApercu";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Aper�u des changements";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GUI_apercuimage_pictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		} //InitializeComponent
#pragma endregion //Windows Form Designer generated code
	}; //public ref class ImgConvApercu : public System::Windows::Forms::Form
} //namespace ImgConv
