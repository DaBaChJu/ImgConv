#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace ImgConv {

	/// <summary>
	/// Description résumée de ImgConvApercu
	///
	/// AVERTISSEMENT : si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propriété 'Nom du fichier de ressources' de l'outil de compilation de ressource managée
	///          pour tous les fichiers .resx dont dépend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localisées associées à ce formulaire.
	/// </summary>
	public ref class ImgConvApercu : public System::Windows::Forms::Form {

	public:
		/// <summary>
		/// Constructeur par défaut
		/// </summary>
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
			
			GUI_apercuimage_pictureBox->Image=image_en_cours;
			GUI_apercuimage_panel1->Controls->Add(GUI_apercuimage_pictureBox);
			GUI_apercuimage_tableLayoutPanel->Controls->Add(GUI_apercuimage_panel1,0,0);
			GUI_apercuimage_tableLayoutPanel->Controls->Add(GUI_apercuimage_bouton,0,1);

		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~ImgConvApercu() {
			if (components) {
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

		/// <summary>
		/// Composants graphiques
		/// </summary>
	private: System::Windows::Forms::Button^  GUI_apercuimage_bouton;
	private: System::Windows::Forms::Panel^  GUI_apercuimage_panel1;
	private: System::Windows::Forms::TableLayoutPanel^  GUI_apercuimage_tableLayoutPanel;






	private: System::Windows::Forms::PictureBox^  GUI_apercuimage_pictureBox;





	/// <summary>
	/// Variables du programme général.
	/// </summary>
	//public: Bitmap^ image_bitmap;	//image actuellement traitée

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void) {
			this->GUI_apercuimage_bouton = (gcnew System::Windows::Forms::Button());
			this->GUI_apercuimage_pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->GUI_apercuimage_panel1 = (gcnew System::Windows::Forms::Panel());
			this->GUI_apercuimage_tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GUI_apercuimage_pictureBox))->BeginInit();
			this->GUI_apercuimage_panel1->SuspendLayout();
			this->GUI_apercuimage_tableLayoutPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// GUI_apercuimage_bouton
			// 
			this->GUI_apercuimage_bouton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->GUI_apercuimage_bouton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->GUI_apercuimage_bouton->Location = System::Drawing::Point(38, 97);
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
			this->GUI_apercuimage_pictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->GUI_apercuimage_pictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->GUI_apercuimage_pictureBox->Location = System::Drawing::Point(0, 0);
			this->GUI_apercuimage_pictureBox->Margin = System::Windows::Forms::Padding(0);
			this->GUI_apercuimage_pictureBox->Name = L"GUI_apercuimage_pictureBox";
			this->GUI_apercuimage_pictureBox->Size = System::Drawing::Size(140, 76);
			this->GUI_apercuimage_pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->GUI_apercuimage_pictureBox->TabIndex = 2;
			this->GUI_apercuimage_pictureBox->TabStop = false;
			// 
			// GUI_apercuimage_panel1
			// 
			this->GUI_apercuimage_panel1->AutoScroll = true;
			this->GUI_apercuimage_panel1->AutoSize = true;
			this->GUI_apercuimage_panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->GUI_apercuimage_panel1->Controls->Add(this->GUI_apercuimage_pictureBox);
			this->GUI_apercuimage_panel1->Location = System::Drawing::Point(5, 5);
			this->GUI_apercuimage_panel1->Name = L"GUI_apercuimage_panel1";
			this->GUI_apercuimage_panel1->Size = System::Drawing::Size(142, 78);
			this->GUI_apercuimage_panel1->TabIndex = 3;
			// 
			// GUI_apercuimage_tableLayoutPanel
			// 
			this->GUI_apercuimage_tableLayoutPanel->AutoScroll = true;
			this->GUI_apercuimage_tableLayoutPanel->AutoSize = true;
			this->GUI_apercuimage_tableLayoutPanel->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Inset;
			this->GUI_apercuimage_tableLayoutPanel->ColumnCount = 1;
			this->GUI_apercuimage_tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->GUI_apercuimage_tableLayoutPanel->Controls->Add(this->GUI_apercuimage_bouton, 0, 1);
			this->GUI_apercuimage_tableLayoutPanel->Controls->Add(this->GUI_apercuimage_panel1, 0, 0);
			this->GUI_apercuimage_tableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->GUI_apercuimage_tableLayoutPanel->GrowStyle = System::Windows::Forms::TableLayoutPanelGrowStyle::FixedSize;
			this->GUI_apercuimage_tableLayoutPanel->Location = System::Drawing::Point(0, 0);
			this->GUI_apercuimage_tableLayoutPanel->Name = L"GUI_apercuimage_tableLayoutPanel";
			this->GUI_apercuimage_tableLayoutPanel->RowCount = 2;
			this->GUI_apercuimage_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->GUI_apercuimage_tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				40)));
			this->GUI_apercuimage_tableLayoutPanel->Size = System::Drawing::Size(150, 131);
			this->GUI_apercuimage_tableLayoutPanel->TabIndex = 4;
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
			this->Controls->Add(this->GUI_apercuimage_tableLayoutPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->MinimumSize = System::Drawing::Size(160, 160);
			this->Name = L"ImgConvApercu";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Aperçu des changements";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->GUI_apercuimage_pictureBox))->EndInit();
			this->GUI_apercuimage_panel1->ResumeLayout(false);
			this->GUI_apercuimage_panel1->PerformLayout();
			this->GUI_apercuimage_tableLayoutPanel->ResumeLayout(false);
			this->GUI_apercuimage_tableLayoutPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		} //InitializeComponent
#pragma endregion //Windows Form Designer generated code
	}; //public ref class ImgConvApercu : public System::Windows::Forms::Form
} //namespace ImgConv
