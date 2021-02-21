#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ImgConv {

	/// <summary>
	/// Description résumée de ImgConv2
	///
	/// AVERTISSEMENT : si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propriété 'Nom du fichier de ressources' de l'outil de compilation de ressource managée
	///          pour tous les fichiers .resx dont dépend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localisées associées à ce formulaire.
	/// </summary>
	public ref class ImgConvApercu : public System::Windows::Forms::Form {

	public:
		ImgConvApercu(void) {
			InitializeComponent();
		}

	public:
		/// <summary>
		/// Constructeur personnalisé
		/// </summary>
		ImgConvApercu(Bitmap^ image_en_cours) {

			InitializeComponent();

			int nWidthMin,nHeightMin;
			int nNewWidthMax,nNewHeightMax;

			nWidthMin=image_en_cours->Size.Width+10;
			nHeightMin=image_en_cours->Size.Height+30+GUI_apercuimage_bouton->Size.Height;

			//récupère la zone d'affichage maximale
			Rectangle screen_res=Screen::AllScreens[0]->WorkingArea;

			nNewWidthMax=screen_res.Width;
			nNewHeightMax=screen_res.Height;

			if(nWidthMin > (90*screen_res.Width)/100)
				nNewWidthMax = (90*screen_res.Width)/100;

			if(nHeightMin > (90*screen_res.Height)/100)
				nNewHeightMax = (90*screen_res.Height)/100;

			this->MaximumSize = System::Drawing::Size(nNewWidthMax,nNewHeightMax);
			
			GUI_apercuimage_panel_zoneimage->Controls->Add(GUI_apercuimage_pictureBox);
			GUI_apercuimage_pictureBox->Image=image_en_cours;

		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~ImgConvApercu() {
			if (components)
				delete components;
		}

	private: System::Windows::Forms::Panel^  GUI_apercuimage_panel_zonebouton;
	private: System::Windows::Forms::Panel^  GUI_apercuimage_panel_zoneimage;
	private: System::Windows::Forms::Button^  GUI_apercuimage_bouton;
	private: System::Windows::Forms::PictureBox^  GUI_apercuimage_pictureBox;

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
		void InitializeComponent(void)
		{
			this->GUI_apercuimage_panel_zonebouton = (gcnew System::Windows::Forms::Panel());
			this->GUI_apercuimage_bouton = (gcnew System::Windows::Forms::Button());
			this->GUI_apercuimage_panel_zoneimage = (gcnew System::Windows::Forms::Panel());
			this->GUI_apercuimage_pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->GUI_apercuimage_panel_zonebouton->SuspendLayout();
			this->GUI_apercuimage_panel_zoneimage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GUI_apercuimage_pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// GUI_apercuimage_panel_zonebouton
			// 
			this->GUI_apercuimage_panel_zonebouton->Controls->Add(this->GUI_apercuimage_bouton);
			this->GUI_apercuimage_panel_zonebouton->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->GUI_apercuimage_panel_zonebouton->Location = System::Drawing::Point(0, 60);
			this->GUI_apercuimage_panel_zonebouton->MinimumSize = System::Drawing::Size(82, 30);
			this->GUI_apercuimage_panel_zonebouton->Name = L"GUI_apercuimage_panel_zonebouton";
			this->GUI_apercuimage_panel_zonebouton->Size = System::Drawing::Size(85, 30);
			this->GUI_apercuimage_panel_zonebouton->TabIndex = 1;
			// 
			// GUI_apercuimage_bouton
			// 
			this->GUI_apercuimage_bouton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->GUI_apercuimage_bouton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->GUI_apercuimage_bouton->Location = System::Drawing::Point(5, 4);
			this->GUI_apercuimage_bouton->MaximumSize = System::Drawing::Size(75, 23);
			this->GUI_apercuimage_bouton->MinimumSize = System::Drawing::Size(75, 23);
			this->GUI_apercuimage_bouton->Name = L"GUI_apercuimage_bouton";
			this->GUI_apercuimage_bouton->Size = System::Drawing::Size(75, 23);
			this->GUI_apercuimage_bouton->TabIndex = 0;
			this->GUI_apercuimage_bouton->Text = L"Retour";
			this->GUI_apercuimage_bouton->UseVisualStyleBackColor = true;
			// 
			// GUI_apercuimage_panel_zoneimage
			// 
			this->GUI_apercuimage_panel_zoneimage->AutoScroll = true;
			this->GUI_apercuimage_panel_zoneimage->AutoSize = true;
			this->GUI_apercuimage_panel_zoneimage->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->GUI_apercuimage_panel_zoneimage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->GUI_apercuimage_panel_zoneimage->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->GUI_apercuimage_panel_zoneimage->Controls->Add(this->GUI_apercuimage_pictureBox);
			this->GUI_apercuimage_panel_zoneimage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->GUI_apercuimage_panel_zoneimage->Location = System::Drawing::Point(0, 0);
			this->GUI_apercuimage_panel_zoneimage->Margin = System::Windows::Forms::Padding(0);
			this->GUI_apercuimage_panel_zoneimage->Name = L"GUI_apercuimage_panel_zoneimage";
			this->GUI_apercuimage_panel_zoneimage->Padding = System::Windows::Forms::Padding(1);
			this->GUI_apercuimage_panel_zoneimage->Size = System::Drawing::Size(85, 60);
			this->GUI_apercuimage_panel_zoneimage->TabIndex = 2;
			// 
			// GUI_apercuimage_pictureBox
			// 
			this->GUI_apercuimage_pictureBox->Location = System::Drawing::Point(1, 1);
			this->GUI_apercuimage_pictureBox->Margin = System::Windows::Forms::Padding(0);
			this->GUI_apercuimage_pictureBox->Name = L"GUI_apercuimage_pictureBox";
			this->GUI_apercuimage_pictureBox->Size = System::Drawing::Size(84, 60);
			this->GUI_apercuimage_pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->GUI_apercuimage_pictureBox->TabIndex = 0;
			this->GUI_apercuimage_pictureBox->TabStop = false;
			// 
			// ImgConvApercu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->CancelButton = this->GUI_apercuimage_bouton;
			this->ClientSize = System::Drawing::Size(85, 90);
			this->Controls->Add(this->GUI_apercuimage_panel_zoneimage);
			this->Controls->Add(this->GUI_apercuimage_panel_zonebouton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"ImgConvApercu";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Aperçu des changements";
			this->GUI_apercuimage_panel_zonebouton->ResumeLayout(false);
			this->GUI_apercuimage_panel_zoneimage->ResumeLayout(false);
			this->GUI_apercuimage_panel_zoneimage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GUI_apercuimage_pictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	}; //public ref class ImgConvApercu : public System::Windows::Forms::Form
} //namespace ImgConv
