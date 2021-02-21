#include "StdAfx.h"
#include "ImgConvRedim.h"

using namespace ImgConv;

		ImgConvRedim::ImgConvRedim(void) {
			InitializeComponent();
			InitializeComponent2();
		}


		ImgConvRedim::ImgConvRedim(ImgConvTools::Bitmap_partage^ source) {
			InitializeComponent();
			image_bitmap=source;
			InitializeComponent2();
		}


		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		ImgConvRedim::~ImgConvRedim() {
			if (components) {
				delete components;
			}
		}


		/// <summary>
		/// Initialisation partie manuelle (non créée par Visual Studio)
		/// </summary>
		void ImgConvRedim::InitializeComponent2(void) {

			if (!image_bitmap->image) {
				MessageBox::Show(L"Une erreur est survenue lors du chargement de l'image",L"Erreur",MessageBoxButtons::OK,MessageBoxIcon::Error);
				this->Close();
			}

			GUI_Redim_listeTypesRedim->SelectedIndex::set(GUI_Redim_listeTypesRedim->Items->Count-1);
			GUI_Redim_toolTip->SetToolTip(GUI_Redim_bouton_apercu,L"Affiche l'image modifiée par la tâche sélectionnée");
			GUI_Redim_toolTip->SetToolTip(GUI_Redim_bouton_effectuer_tache,L"Ne fais rien et retourne à la fenêtre principale.");
			GUI_Redim_toolTip->SetToolTip(GUI_Redim_listeTypesRedim,L"Sélectionner une action et placez la souris sur le bouton effectuer tâche pour plus d'informations.");

		}

	
#pragma region Ecouteurs de ImgConvRedim

		/// <summary>
		/// Gère le bouton Effectuer Tâche
		/// </summary>

		void ImgConvRedim::GUI_Redim_bouton_effectuer_tache_Click(System::Object^  sender, System::EventArgs^  e) {

			switch(GUI_Redim_listeTypesRedim->SelectedIndex) {

				case 0: {

					image_bitmap->image=ImgConvTools::Etire_gris(image_bitmap->image);

					MessageBox::Show(L"Le changement a été effectué\nEnregistrez l'image pour voir les modifications",L"Opération réussie");

					//confirme que les modifications doivent être prises en compte
					this->DialogResult=System::Windows::Forms::DialogResult::OK;

					break;

				}

				case 1: {

					image_bitmap->image=ImgConvTools::Etire_gris_interverti(image_bitmap->image);

					MessageBox::Show(L"Le changement a été effectué\nEnregistrez l'image pour voir les modifications",L"Opération réussie");

					//confirme que les modifications doivent être prises en compte
					this->DialogResult=System::Windows::Forms::DialogResult::OK;

					break;

				}

				case 2: {

					//MessageBox::Show("Pas encore implémenté");

					image_bitmap->image=ImgConvTools::Etire_gris_lumineux(image_bitmap->image);

					MessageBox::Show(L"Le changement a été effectué\nEnregistrez l'image pour voir les modifications",L"Opération réussie");

					//confirme que les modifications doivent être prises en compte
					this->DialogResult=System::Windows::Forms::DialogResult::OK;

					break;

				}

				case 3: {

					//MessageBox::Show("Pas encore implémenté");

					image_bitmap->image=ImgConvTools::Etire_gris_sombre(image_bitmap->image);

					MessageBox::Show(L"Le changement a été effectué\nEnregistrez l'image pour voir les modifications",L"Opération réussie");

					//confirme que les modifications doivent être prises en compte
					this->DialogResult=System::Windows::Forms::DialogResult::OK;

					break;

				}

				default:
					this->DialogResult=System::Windows::Forms::DialogResult::Cancel;

			}

			this->Close();

		} //GUI_Redim_bouton_effectuer_tache_Click

		/// <summary>
		/// Gère le changement d'info-bulle quand la sélection de la liste change
		/// </summary>

		void ImgConvRedim::GUI_Redim_liste_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			
			switch(GUI_Redim_listeTypesRedim->SelectedIndex) {

				case 0:
					GUI_Redim_toolTip->SetToolTip(GUI_Redim_bouton_effectuer_tache,L"Un pixel gris sera ajouté entre chaque paire de pixels.\nLa valeur de gris dépendra des couleurs environnantes.");
					break;

				case 1:
					GUI_Redim_toolTip->SetToolTip(GUI_Redim_bouton_effectuer_tache,L"Un pixel sera réajouté entre 2 pixels gris.\nLa valeur de gris dépendra des couleurs environnantes.");
					break;

				case 2:
					GUI_Redim_toolTip->SetToolTip(GUI_Redim_bouton_effectuer_tache,L"Un pixel gris sera ajouté entre chaque paire de pixels.\nLa valeur de gris dépendra des couleurs environnantes.\nUn pixel blanc sera ajouté au calcul pour augmenter la luminosité.");
					break;

				case 3:
					GUI_Redim_toolTip->SetToolTip(GUI_Redim_bouton_effectuer_tache,L"Un pixel gris sera ajouté entre chaque paire de pixels.\nLa valeur de gris dépendra des couleurs environnantes.\nUn pixel noir sera ajouté au calcul pour diminuer la luminosité.");
					break;

				default:
					GUI_Redim_toolTip->SetToolTip(GUI_Redim_bouton_effectuer_tache,L"Ne fais rien et retourne à la fenêtre principale.");
					break;

			}
			
		} //GUI_Redim_liste_SelectedIndexChanged 

		/// <summary>
		/// Gestion du bouton Aperçu
		/// </summary>

		void ImgConvRedim::GUI_Redim_bouton_apercu_Click(System::Object^  sender, System::EventArgs^  e) {

			Bitmap^ image_apercu;

			switch(GUI_Redim_listeTypesRedim->SelectedIndex) {

				//Etirer avec pixels gris
				case 0:
					image_apercu=gcnew Bitmap(
						ImgConvTools::Etire_gris(image_bitmap->image)
						);
					break;

				//Etirer avec pixels gris interverti
				case 1:
					image_apercu=gcnew Bitmap(
						ImgConvTools::Etire_gris_interverti(image_bitmap->image)
						);
					break;

				//Etirer avec pixels gris lumineux
				case 2:
					image_apercu=gcnew Bitmap(
						ImgConvTools::Etire_gris_lumineux(image_bitmap->image)
						);
					break;

				//Etirer avec pixels gris sombre
				case 3:
					image_apercu=gcnew Bitmap(
						ImgConvTools::Etire_gris_sombre(image_bitmap->image)
						);
					break;

				//Ne rien faire
				default:
					image_apercu=gcnew Bitmap(image_bitmap->image);
					break;

			}

			ImgConvApercu^ fenetre_apercu=gcnew ImgConvApercu(image_apercu);
			fenetre_apercu->ShowDialog();

			delete fenetre_apercu;
			delete image_apercu;

		}//GUI_Redim_bouton_apercu_Click

#pragma endregion //Ecouteurs de ImgConvRedim