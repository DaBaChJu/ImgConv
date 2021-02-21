#pragma once

#ifndef IMGCONVTOOLS_H
#define IMGCONVTOOLS_H

namespace ImgConvTools {

	///<summary>Permet de passer en paramètre un objet .NET qui ne contient qu'un entier</summary>
	public ref class Entier_partage {
	public:
		int valeur;
	};


	///Permet de passer en paramètre un objet .NET qui ne contient qu'un bitmap
	public ref class Bitmap_partage {
	public:
		System::Drawing::Bitmap^ image;
	};



	
	/// <summary>
	/// Algorithme d'inversion des couleurs (255-valeurs couleurs)
	/// </summary>
	static System::Drawing::Bitmap^ Inverser_couleurs(System::Drawing::Bitmap^ source,Entier_partage^ nProgress=nullptr) {

		int x,y;

		if (!nProgress) {
			for (x=0;x<source->Width;x++) {
				for (y=0;y<source->Height;y++) {

					//récupère la couleur du pixel
					System::Drawing::Color pixelColor = source->GetPixel(x,y);

					//génère la couleur inverse
					System::Drawing::Color newColor = System::Drawing::Color::FromArgb(255-pixelColor.R,255-pixelColor.G,255-pixelColor.B);

					//change la couleur actuelle du pixel en la version inversée
					source->SetPixel(x,y,newColor);

				}
			}
		}
		else {

			nProgress->valeur=0;

			for (x=0;x<source->Width;x++) {
				for (y=0;y<source->Height;y++) {

					//récupère la couleur du pixel
					System::Drawing::Color pixelColor = source->GetPixel(x,y);

					//génère la couleur inverse
					System::Drawing::Color newColor = System::Drawing::Color::FromArgb(255-pixelColor.R,255-pixelColor.G,255-pixelColor.B);

					//change la couleur actuelle du pixel en la version inversée
					source->SetPixel(x,y,newColor);

					//met à jour nProgress
					nProgress->valeur++;

				}
			}
		}

		return source;
	}//static System::Drawing::Bitmap^ Inverser_couleurs(System::Drawing::Bitmap^ source,Entier_partage^ nProgress=nullptr)

	
	/// <summary>
	/// Algorithmes pour griser une image
	/// </summary>
	static System::Drawing::Bitmap^ Griser(System::Drawing::Bitmap^ source,int type_grisage=0,Entier_partage^ nProgress=nullptr) {

		int x,y;

		if (nProgress)
			nProgress->valeur=0;

		//grise avec la moyenne des valeurs de couleurs
		//plus de moyenne => plus de blanc
		if (type_grisage==0) { 

			for (x=0;x<source->Width;x++) {
				for (y=0;y<source->Height;y++) {

					//récupère la couleur du pixel
					System::Drawing::Color pixelColor = source->GetPixel(x,y);

					//définit la valeur de gris comme la moyenne des 3 couleurs
					System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
						(pixelColor.R+pixelColor.G+pixelColor.B)/3,
						(pixelColor.R+pixelColor.G+pixelColor.B)/3,
						(pixelColor.R+pixelColor.G+pixelColor.B)/3
					);

					//change la couleur actuelle du pixel en la version grisée
					source->SetPixel(x,y,newColor);

					//met à jour l'indicateur de progression si disponible
					if (nProgress) nProgress->valeur++;

				}
			}

		} //grise avec la moyenne des valeurs de couleurs,moyenne->blanc
		else

		//grise sur la valeur du rouge
		//plus de rouge => plus de noir
		if (type_grisage==1) { 

			for (x=0;x<source->Width;x++) {
				for (y=0;y<source->Height;y++) {

					//récupère la couleur du pixel
					System::Drawing::Color pixelColor = source->GetPixel(x,y);

					//définit la valeur de gris comme étant l'inverse de la valeur du rouge
					System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
						 255- pixelColor.R,
						 255- pixelColor.R,
						 255- pixelColor.R
					);

					//change la couleur actuelle du pixel en la version grisée
					source->SetPixel(x,y,newColor);

					//met à jour l'indicateur de progression si disponible
					if (nProgress) nProgress->valeur++;

				}
			}

		} //grise sur la valeur du rouge
		else

		//grise sur la valeur du vert
		//plus de vert => plus de noir
		if (type_grisage==2) { 

			for (x=0;x<source->Width;x++) {
				for (y=0;y<source->Height;y++) {

					//récupère la couleur du pixel
					System::Drawing::Color pixelColor = source->GetPixel(x,y);

					//définit la valeur de gris comme étant l'inverse de la valeur du vert
					System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
						 255- pixelColor.G,
						 255- pixelColor.G,
						 255- pixelColor.G
					);

					//change la couleur actuelle du pixel en la version grisée
					source->SetPixel(x,y,newColor);

					//met à jour l'indicateur de progression si disponible
					if (nProgress) nProgress->valeur++;

				}
			}

		} //grise sur la valeur du vert
		else

		//grise sur la valeur du bleu
		//plus de bleu => plus de noir
		if (type_grisage==3) {

			for (x=0;x<source->Width;x++) {
				for (y=0;y<source->Height;y++) {

					//récupère la couleur du pixel
					System::Drawing::Color pixelColor = source->GetPixel(x,y);

					//définit la valeur de gris comme étant l'inverse de la valeur du bleu
					System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
						 255- pixelColor.B,
						 255- pixelColor.B,
						 255- pixelColor.B
					);

					//change la couleur actuelle du pixel en la version grisée
					source->SetPixel(x,y,newColor);

					//met à jour l'indicateur de progression si disponible
					if (nProgress) nProgress->valeur++;

				}
			}

		} //grise sur la valeur du bleu

		//grise avec la moyenne des valeurs de couleurs
		//plus de moyenne => plus de noir
		if (type_grisage==4) {

			for (x=0;x<source->Width;x++) {
				for (y=0;y<source->Height;y++) {

					//récupère la couleur du pixel
					System::Drawing::Color pixelColor = source->GetPixel(x,y);

					//définit la valeur de gris comme la moyenne des 3 couleurs
					System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
						 255- (pixelColor.R+pixelColor.G+pixelColor.B)/3,
						 255- (pixelColor.R+pixelColor.G+pixelColor.B)/3,
						 255- (pixelColor.R+pixelColor.G+pixelColor.B)/3
					);

					//change la couleur actuelle du pixel en la version grisée
					source->SetPixel(x,y,newColor);

					//met à jour l'indicateur de progression si disponible
					if (nProgress) nProgress->valeur++;

				}
			}

		} //grise avec la moyenne des valeurs de couleurs
		else

		//grise sur la valeur du rouge
		//plus de rouge => plus de blanc
		if (type_grisage==5) { 

			for (x=0;x<source->Width;x++) {
				for (y=0;y<source->Height;y++) {

					//récupère la couleur du pixel
					System::Drawing::Color pixelColor = source->GetPixel(x,y);

					//définit la valeur de gris comme étant la valeur du rouge
					System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
						pixelColor.R,
						pixelColor.R,
						pixelColor.R
					);

					//change la couleur actuelle du pixel en la version grisée
					source->SetPixel(x,y,newColor);

					//met à jour l'indicateur de progression si disponible
					if (nProgress) nProgress->valeur++;

				}
			}

		} //grise sur la valeur du rouge
		else

		//grise sur la valeur du vert
		//plus de vert => plus de blanc
		if (type_grisage==6) {

			for (x=0;x<source->Width;x++) {
				for (y=0;y<source->Height;y++) {

					//récupère la couleur du pixel
					System::Drawing::Color pixelColor = source->GetPixel(x,y);

					//définit la valeur de gris comme étant la valeur du vert
					System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
						pixelColor.G,
						pixelColor.G,
						pixelColor.G
					);

					//change la couleur actuelle du pixel en la version grisée
					source->SetPixel(x,y,newColor);

					//met à jour l'indicateur de progression si disponible
					if (nProgress) nProgress->valeur++;

				}
			}

		} //grise sur la valeur du vert
		else

		//grise sur la valeur du bleu
		//plus de bleu => plus de blanc
		if (type_grisage==7) {

			for (x=0;x<source->Width;x++) {
				for (y=0;y<source->Height;y++) {

					//récupère la couleur du pixel
					System::Drawing::Color pixelColor = source->GetPixel(x,y);

					//définit la valeur de gris comme étant la valeur du bleu
					System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
						pixelColor.B,
						pixelColor.B,
						pixelColor.B
					);

					//change la couleur actuelle du pixel en la version grisée
					source->SetPixel(x,y,newColor);

					//met à jour l'indicateur de progression si disponible
					if (nProgress) nProgress->valeur++;

				}
			}

		} //grise sur la valeur du bleu

		return source;

	} //static System::Drawing::Bitmap^ Griser(System::Drawing::Bitmap^ source,int type_grisage=0)

	
	/// <summary>
	/// Algorithmes pour faire d'une image une variation simple d'une seule couleur (basée sur le niveau de gris)
	/// </summary>
	static System::Drawing::Bitmap^ Monochrome(System::Drawing::Bitmap^ source,int type_coloration=0,bool bInverseCouleurs=false,Entier_partage^ nProgress=nullptr) {

#define MOYENNE_COULEURS (pixelColor.R+pixelColor.G+pixelColor.B)/3

		int x,y;

		if (nProgress)
			nProgress->valeur=0;

		if(!bInverseCouleurs) {

#pragma region Monochrome_normal

			//Transforme l'image en niveaux de rouge
			//La couleur varie du blanc au rouge
			if (type_coloration==0) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du blanc jusqu'au rouge
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255,
							255 - MOYENNE_COULEURS,
							255 - MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de rouge,de blanc à rouge
			else

			//Transforme l'image en niveaux de rouge
			//La couleur varie du rouge au blanc
			if (type_coloration==1) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du blanc jusqu'au blanc
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255,
							MOYENNE_COULEURS,
							MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de rouge,de rouge à blanc
			else

			//Transforme l'image en niveaux de rouge
			//La couleur varie du rouge au noir
			if (type_coloration==2) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du rouge jusqu'au noir
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - MOYENNE_COULEURS,
							  0,
							  0
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de rouge,de rouge à noir
			else

			//Transforme l'image en niveaux de rouge
			//La couleur varie du noir au rouge
			if (type_coloration==3) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du rouge jusqu'au rouge
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							MOYENNE_COULEURS,
							  0,
							  0
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de rouge,de noir à rouge
			else

			//Transforme l'image en niveaux de vert
			//La couleur varie du blanc au vert
			if (type_coloration==4) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du blanc jusqu'au vert
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - MOYENNE_COULEURS,
							255,
							255 - MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de vert,de blanc à vert
			else

			//Transforme l'image en niveaux de vert
			//La couleur varie du vert au blanc
			if (type_coloration==5) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du blanc jusqu'au blanc
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							MOYENNE_COULEURS,
							255,
							MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de vert,de vert à blanc
			else

			//Transforme l'image en niveaux de vert
			//La couleur varie du vert au noir
			if (type_coloration==6) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du vert jusqu'au noir
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							  0,
							  255 - MOYENNE_COULEURS,
							  0
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de vert,de vert à noir
			else

			//Transforme l'image en niveaux de vert
			//La couleur varie du noir au vert
			if (type_coloration==7) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du vert jusqu'au vert
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							  0,
							  MOYENNE_COULEURS,
							  0
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de vert,de noir à vert
			else

			//Transforme l'image en niveaux de bleu
			//La couleur varie du blanc au bleu
			if (type_coloration==8) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du blanc jusqu'au bleu
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - MOYENNE_COULEURS,
							255 - MOYENNE_COULEURS,
							255
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de bleu,de blanc à bleu
			else

			//Transforme l'image en niveaux de bleu
			//La couleur varie du bleu au blanc
			if (type_coloration==9) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du blanc jusqu'au blanc
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							MOYENNE_COULEURS,
							MOYENNE_COULEURS,
							255
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de bleu,de bleu à blanc
			else

			//Transforme l'image en niveaux de bleu
			//La couleur varie du bleu au noir
			if (type_coloration==10) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du bleu jusqu'au noir
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							  0,
							  0,
							  255 - MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de bleu,de bleu à noir
			else

			//Transforme l'image en niveaux de bleu
			//La couleur varie du noir au bleu
			if (type_coloration==11) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du bleu jusqu'au bleu
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							  0,
							  0,
							  MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de bleu,de noir à bleu
			else

			//Transforme l'image en niveaux de jaune
			//La couleur varie du blanc au jaune
			if (type_coloration==12) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du blanc jusqu'au jaune
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255,
							255,
							255 - MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de jaune,de blanc à jaune
			else

			//Transforme l'image en niveaux de jaune
			//La couleur varie du jaune au blanc
			if (type_coloration==13) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du blanc jusqu'au blanc
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255,
							255,
							MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de jaune,de jaune à blanc
			else

			//Transforme l'image en niveaux de jaune
			//La couleur varie du jaune au noir
			if (type_coloration==14) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du jaune jusqu'au noir
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - MOYENNE_COULEURS,
							255 - MOYENNE_COULEURS,
							  0
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de jaune,de jaune à noir
			else

			//Transforme l'image en niveaux de jaune
			//La couleur varie du noir au jaune
			if (type_coloration==15) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du jaune jusqu'au jaune
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							MOYENNE_COULEURS,
							MOYENNE_COULEURS,
							  0
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de jaune,de noir à jaune
			else

			//Transforme l'image en niveaux de violet
			//La couleur varie du blanc au violet
			if (type_coloration==16) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du blanc jusqu'au violet
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255,
							255 - MOYENNE_COULEURS,
							255
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de violet,de blanc à violet
			else

			//Transforme l'image en niveaux de violet
			//La couleur varie du violet au blanc
			if (type_coloration==17) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du blanc jusqu'au blanc
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255,
							MOYENNE_COULEURS,
							255
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de violet,de violet à blanc
			else

			//Transforme l'image en niveaux de violet
			//La couleur varie du violet au noir
			if (type_coloration==18) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du violet jusqu'au noir
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - MOYENNE_COULEURS,
							  0,
							255 - MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de violet,de violet à noir
			else

			//Transforme l'image en niveaux de violet
			//La couleur varie du noir au violet
			if (type_coloration==19) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du violet jusqu'au violet
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							MOYENNE_COULEURS,
							  0,
							MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de violet,de noir à violet
			else

			//Transforme l'image en niveaux de cyan
			//La couleur varie du blanc au cyan
			if (type_coloration==20) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du blanc jusqu'au cyan
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - MOYENNE_COULEURS,
							255,
							255
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de cyan,de blanc à cyan
			else

			//Transforme l'image en niveaux de cyan
			//La couleur varie du cyan au blanc
			if (type_coloration==21) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du blanc jusqu'au blanc
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							MOYENNE_COULEURS,
							255,
							255
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de cyan,de cyan à blanc
			else

			//Transforme l'image en niveaux de cyan
			//La couleur varie du cyan au noir
			if (type_coloration==22) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du cyan jusqu'au noir
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							  0,
							255 - MOYENNE_COULEURS,
							255 - MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de cyan,de cyan à noir
			else

			//Transforme l'image en niveaux de cyan
			//La couleur varie du noir au cyan
			if (type_coloration==23) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du cyan jusqu'au cyan
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							  0,
							MOYENNE_COULEURS,
							MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de cyan,de noir à cyan

#pragma endregion Monochrome_normal

		} //if(!bInverseCouleurs)

		else { //if(bInverseCouleurs)

#pragma region Monochrome_inverse

			//Transforme l'image en niveaux de rouge
			//La couleur varie du blanc au rouge
			if (type_coloration==0) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du blanc jusqu'au rouge
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							0,
							255 - (255 - MOYENNE_COULEURS),
							255 - (255 - MOYENNE_COULEURS)
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de rouge,de blanc à rouge
			else

			//Transforme l'image en niveaux de rouge
			//La couleur varie du rouge au blanc
			if (type_coloration==1) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du blanc jusqu'au blanc
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							0,
							255 - MOYENNE_COULEURS,
							255 - MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de rouge,de rouge à blanc
			else

			//Transforme l'image en niveaux de rouge
			//La couleur varie du rouge au noir
			if (type_coloration==2) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du rouge jusqu'au noir
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - (255 - MOYENNE_COULEURS),
							255,
							255
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de rouge,de rouge à noir
			else

			//Transforme l'image en niveaux de rouge
			//La couleur varie du noir au rouge
			if (type_coloration==3) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du rouge jusqu'au rouge
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - MOYENNE_COULEURS,
							255,
							255
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de rouge,de noir à rouge
			else

			//Transforme l'image en niveaux de vert
			//La couleur varie du blanc au vert
			if (type_coloration==4) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du blanc jusqu'au vert
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - (255 - MOYENNE_COULEURS),
							0,
							255 - (255 - MOYENNE_COULEURS)
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de vert,de blanc à vert
			else

			//Transforme l'image en niveaux de vert
			//La couleur varie du vert au blanc
			if (type_coloration==5) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du blanc jusqu'au blanc
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - MOYENNE_COULEURS,
							0,
							255 - MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de vert,de vert à blanc
			else

			//Transforme l'image en niveaux de vert
			//La couleur varie du vert au noir
			if (type_coloration==6) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du vert jusqu'au noir
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							  255,
							  255 - (255 - MOYENNE_COULEURS),
							  255
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de vert,de vert à noir
			else

			//Transforme l'image en niveaux de vert
			//La couleur varie du noir au vert
			if (type_coloration==7) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du vert jusqu'au vert
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							  255,
							  255 - MOYENNE_COULEURS,
							  255
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de vert,de noir à vert
			else

			//Transforme l'image en niveaux de bleu
			//La couleur varie du blanc au bleu
			if (type_coloration==8) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du blanc jusqu'au bleu
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - (255 - MOYENNE_COULEURS),
							255 - (255 - MOYENNE_COULEURS),
							0
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de bleu,de blanc à bleu
			else

			//Transforme l'image en niveaux de bleu
			//La couleur varie du bleu au blanc
			if (type_coloration==9) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du blanc jusqu'au blanc
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - MOYENNE_COULEURS,
							255 - MOYENNE_COULEURS,
							0
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de bleu,de bleu à blanc
			else

			//Transforme l'image en niveaux de bleu
			//La couleur varie du bleu au noir
			if (type_coloration==10) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du bleu jusqu'au noir
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							  255,
							  255,
							  255 - (255 - MOYENNE_COULEURS)
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de bleu,de bleu à noir
			else

			//Transforme l'image en niveaux de bleu
			//La couleur varie du noir au bleu
			if (type_coloration==11) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du bleu jusqu'au bleu
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							  255,
							  255,
							  255 - MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de bleu,de noir à bleu
			else

			//Transforme l'image en niveaux de jaune
			//La couleur varie du blanc au jaune
			if (type_coloration==12) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du blanc jusqu'au jaune
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							0,
							0,
							255 - (255 - MOYENNE_COULEURS)
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de jaune,de blanc à jaune
			else

			//Transforme l'image en niveaux de jaune
			//La couleur varie du jaune au blanc
			if (type_coloration==13) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du blanc jusqu'au blanc
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							0,
							0,
							255 - MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de jaune,de jaune à blanc
			else

			//Transforme l'image en niveaux de jaune
			//La couleur varie du jaune au noir
			if (type_coloration==14) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du jaune jusqu'au noir
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - (255 - MOYENNE_COULEURS),
							255 - (255 - MOYENNE_COULEURS),
							255
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de jaune,de jaune à noir
			else

			//Transforme l'image en niveaux de jaune
			//La couleur varie du noir au jaune
			if (type_coloration==15) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du jaune jusqu'au jaune
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - MOYENNE_COULEURS,
							255 - MOYENNE_COULEURS,
							255
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de jaune,de noir à jaune
			else

			//Transforme l'image en niveaux de violet
			//La couleur varie du blanc au violet
			if (type_coloration==16) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du blanc jusqu'au violet
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							0,
							255 - (255 - MOYENNE_COULEURS),
							0
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de violet,de blanc à violet
			else

			//Transforme l'image en niveaux de violet
			//La couleur varie du violet au blanc
			if (type_coloration==17) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du blanc jusqu'au blanc
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							0,
							255 - MOYENNE_COULEURS,
							0
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de violet,de violet à blanc
			else

			//Transforme l'image en niveaux de violet
			//La couleur varie du violet au noir
			if (type_coloration==18) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du violet jusqu'au noir
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - (255 - MOYENNE_COULEURS),
							255,
							255 - (255 - MOYENNE_COULEURS)
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de violet,de violet à noir
			else

			//Transforme l'image en niveaux de violet
			//La couleur varie du noir au violet
			if (type_coloration==19) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du violet jusqu'au violet
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - MOYENNE_COULEURS,
							255,
							255 - MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de violet,de noir à violet
			else

			//Transforme l'image en niveaux de cyan
			//La couleur varie du blanc au cyan
			if (type_coloration==20) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du blanc jusqu'au cyan
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - (255 - MOYENNE_COULEURS),
							0,
							0
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de cyan,de blanc à cyan
			else

			//Transforme l'image en niveaux de cyan
			//La couleur varie du cyan au blanc
			if (type_coloration==21) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du blanc jusqu'au blanc
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255 - MOYENNE_COULEURS,
							0,
							0
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de cyan,de cyan à blanc
			else

			//Transforme l'image en niveaux de cyan
			//La couleur varie du cyan au noir
			if (type_coloration==22) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//diminue l'influence du cyan jusqu'au noir
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255,
							255 - (255 - MOYENNE_COULEURS),
							255 - (255 - MOYENNE_COULEURS)
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de cyan,de cyan à noir
			else

			//Transforme l'image en niveaux de cyan
			//La couleur varie du noir au cyan
			if (type_coloration==23) { 

				for (x=0;x<source->Width;x++) {
					for (y=0;y<source->Height;y++) {

						//récupère la couleur du pixel
						System::Drawing::Color pixelColor = source->GetPixel(x,y);

						//augmente l'influence du cyan jusqu'au cyan
						System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
							255,
							255 - MOYENNE_COULEURS,
							255 - MOYENNE_COULEURS
						);

						//change la couleur actuelle du pixel en la version monochrome
						source->SetPixel(x,y,newColor);

						//met à jour l'indicateur de progression si disponible
						if (nProgress) nProgress->valeur++;

					}
				}

			} //niveaux de cyan,de noir à cyan

#pragma endregion Monochrome_inverse

		} //if(bInverseCouleurs)

		return source;

#undef MOYENNE_COULEURS

	} //static System::Drawing::Bitmap^ Monochrome(System::Drawing::Bitmap^ source,int type_coloration=0)

	
	/// <summary>
	/// Algorithmes pour échanger une couleur

	/// Lorsqu'on remplace une couleur simple par une autre simple,on échange seulement leurs valeurs. (R:5,G:2,B:4 rouge->vert R:2,G:5,B:3)
	/// Lorsqu'on remplace une couleur simple par une couleur composée avec dominante,la dominante reçoit la valeur de la simple,et la secondaire reçoit (valeur_couleur_non_incluse+valeur_maximale)/2
	///	Si la valeur non incluse est l'ancienne valeur maximale,on prend (couleur_non_dominante+valeur_maximale)/2,et l'ancienne valeur de la secondaire devient la valeur courante de l'ancienne maximale
	/// Lorsqu'on remplace une couleur simple par une couleur composée sans dominante,les 2 composantes reçoivent la valeur de la couleur simple

	/// Lorsqu'on remplace une couleur composée par une couleur simple,la couleur voulue est à la valeur maximale des couleurs du pixel,tandis que les autres tombent à la valeur minimale.
	/// Lorsqu'on remplace une couleur composée par une couleur composée avec dominante,les valeurs correspondantes sont échangées.
	//  Lorsqu'on remplace une couleur composée par une couleur composée sans dominante,les 2 composantes reçoivent la moyenne des valeurs composants la couleur initiale

	/// La dominante de la couleur initiale n'influe que sur la sélection des pixels à remplacer,pas sur la phase d'échange (puisque les pixels n'ayant pas la bonne dominante ne passent pas dans la phase d'échange de couleur).

	/// </summary>
#pragma region		System::Drawing::Bitmap^ Echange_couleurs(System::Drawing::Bitmap^ source,int couleur_1,int couleur_2,int couleur_dominante_remplacee,int couleur_dominante_remplacement,Entier_partage^ nProgress=nullptr) {...}
	static System::Drawing::Bitmap^ Echange_couleurs(System::Drawing::Bitmap^ source,int couleur_1,int couleur_2,int couleur_dominante_remplacee,int couleur_dominante_remplacement,Entier_partage^ nProgress=nullptr) {

///////////
// définition des valeurs de couleur: 0=Rouge	1=Vert	2=Bleu	3=Jaune	4=Violet	5=Cyan
///////////
#define C_ROUGE 0
#define C_VERT 1
#define C_BLEU 2
#define C_JAUNE 3
#define C_VIOLET 4
#define C_CYAN 5
#define C_AUCUNE 3

///////////
// définition de macros retournant la plus petite valeur de couleur,la plus grande ou leur moyenne
///////////
#define MIN_ENTRE_BLEU_ET_VERT (nValeurVertAncienne<nValeurBleuAncienne ? nValeurVertAncienne : nValeurBleuAncienne)
#define MIN_ENTRE_ROUGE_ET_BLEU (nValeurRougeAncienne<nValeurBleuAncienne ? nValeurRougeAncienne : nValeurBleuAncienne)
#define MIN_ENTRE_VERT_ET_ROUGE (nValeurRougeAncienne<nValeurVertAncienne ? nValeurRougeAncienne : nValeurVertAncienne)
#define MAX_ENTRE_BLEU_ET_VERT (nValeurVertAncienne>nValeurBleuAncienne ? nValeurVertAncienne : nValeurBleuAncienne)
#define MAX_ENTRE_ROUGE_ET_BLEU (nValeurRougeAncienne>nValeurBleuAncienne ? nValeurRougeAncienne : nValeurBleuAncienne)
#define MAX_ENTRE_VERT_ET_ROUGE (nValeurRougeAncienne>nValeurVertAncienne ? nValeurRougeAncienne : nValeurVertAncienne)
#define MOYENNE_BLEU_ET_VERT ((nValeurVertAncienne+nValeurBleuAncienne)/2)
#define MOYENNE_ROUGE_ET_BLEU ((nValeurRougeAncienne+nValeurBleuAncienne)/2)
#define MOYENNE_VERT_ET_ROUGE ((nValeurRougeAncienne+nValeurVertAncienne)/2)
		
		int x,y;
		int nValeurRougeAncienne;
		int nValeurRougeNouveau;
		int nValeurVertAncienne;
		int nValeurVertNouveau;
		int nValeurBleuAncienne;
		int nValeurBleuNouveau;
		bool bEchangerCouleur=false;

		if (nProgress)
			nProgress->valeur=0;

		for (x=0;x<source->Width;x++) {
			for (y=0;y<source->Height;y++) {

				//récupère la couleur du pixel
				System::Drawing::Color pixelColor = source->GetPixel(x,y);

				////////////
				//Vérifie s'il faut changer le pixel en cours,et si oui,prépare le terrain en sauvant les couleurs actuelles constituant le pixel
				//Si non,ne fait rien ou incrémente l'indicateur de progression (plus rien à faire sur ce pixel) s'il est disponible
				////////////
				if ( 
					
					(pixelColor.R!=pixelColor.G || pixelColor.B!=pixelColor.G || pixelColor.G!=pixelColor.B) && (	/*au moins 2 couleurs doivent être différente sinon c'est du gris*/

						(couleur_1==C_ROUGE && pixelColor.R>pixelColor.G && pixelColor.R>pixelColor.B) ||				/*le rouge doit être supérieur aux autres couleurs pour une dominante rouge*/
						(couleur_1==C_VERT && pixelColor.G>pixelColor.R && pixelColor.G>pixelColor.B) ||				/*le vert doit être supérieur aux autres couleurs pour une dominante verte*/
						(couleur_1==C_BLEU && pixelColor.B>pixelColor.R && pixelColor.B>pixelColor.G) ||				/*le bleu doit être supérieur aux autres couleurs pour une dominante bleue*/

						/*les couleurs entre parenthèses dans les prochains commentaires sont une dominante possible de la couleur sélectionnée,mais pas toujours fidèle à ce qui est effectivement visible,ça reste du pur calcul*/
						(couleur_1==C_JAUNE && (																																
							( ( couleur_dominante_remplacee==C_AUCUNE || couleur_dominante_remplacee==C_BLEU) && pixelColor.B<pixelColor.R && pixelColor.B<pixelColor.G) ||		/*le bleu doit être inférieur aux autres couleurs pour un jaune sans dominante*/
							( couleur_dominante_remplacee==C_ROUGE && pixelColor.B<pixelColor.R && pixelColor.B<pixelColor.G && pixelColor.R>pixelColor.G) ||					/*idem,mais avec rouge supérieur à vert pour un jaune dominante rouge (orange)*/
							( couleur_dominante_remplacee==C_VERT && pixelColor.B<pixelColor.R && pixelColor.B<pixelColor.G && pixelColor.G>pixelColor.R)						/*idem,mais avec vert supérieur à rouge pour un jaune dominante vert (vert pâle)*/
							)
						) ||
						(couleur_1==C_VIOLET && (
							( ( couleur_dominante_remplacee==C_AUCUNE || couleur_dominante_remplacee==C_VERT) && pixelColor.G<pixelColor.R && pixelColor.G<pixelColor.B) ||		/*le vert doit être inférieur aux autres couleurs pour un violet sans dominante*/
							( couleur_dominante_remplacee==C_ROUGE && pixelColor.G<pixelColor.R && pixelColor.G<pixelColor.B && pixelColor.R>pixelColor.B) ||					/*idem,mais avec rouge supérieur à bleu pour un violet dominante rouge (rose)*/
							( couleur_dominante_remplacee==C_BLEU && pixelColor.G<pixelColor.R && pixelColor.G<pixelColor.B && pixelColor.B>pixelColor.R)						/*idem,mais avec bleu supérieur à rouge pour un violet dominante bleu (violet foncé)*/
							)
						) ||
						(couleur_1==C_CYAN && (
							( ( couleur_dominante_remplacee==C_AUCUNE || couleur_dominante_remplacee==C_ROUGE) && pixelColor.R<pixelColor.G && pixelColor.R<pixelColor.B) ||	/*le rouge doit être inférieur aux autres couleurs pour une dominante cyan*/
							( couleur_dominante_remplacee==C_BLEU && pixelColor.R<pixelColor.G && pixelColor.R<pixelColor.B && pixelColor.B>pixelColor.G) ||					/*idem,mais avec bleu supérieur à vert pour un cyan dominante bleu (bleu foncé lumineux)*/
							( couleur_dominante_remplacee==C_VERT && pixelColor.R<pixelColor.G && pixelColor.R<pixelColor.B && pixelColor.G>pixelColor.B)						/*idem,mais avec vert supérieur à bleu pour un cyan dominante vert (vert bleuté)*/
							)
						)

					)

					//(couleur_1==C_JAUNE && pixelColor.B<pixelColor.R && pixelColor.B<pixelColor.G) ||				/*le bleu doit être inférieur aux autres couleurs pour une dominante jaune*/
					//(couleur_1==C_VIOLET && pixelColor.G<pixelColor.R && pixelColor.G<pixelColor.B) ||			/*le vert doit être inférieur aux autres couleurs pour une dominante violette*/
					//(couleur_1==C_CYAN && pixelColor.R<pixelColor.G && pixelColor.R<pixelColor.B) )				/*le rouge doit être inférieur aux autres couleurs pour une dominante cyan*/
				) {
					bEchangerCouleur=true;
					nValeurRougeAncienne=pixelColor.R;
					nValeurVertAncienne=pixelColor.G;
					nValeurBleuAncienne=pixelColor.B;
				}
				//met à jour l'indicateur de progression si disponible
				else if (nProgress) nProgress->valeur++;

				//Définit les couleurs qui doivent constituer le nouveau pixel,s'il doit être changé
				if (bEchangerCouleur) {

					//Echange du rouge
					if (couleur_1==C_ROUGE) {
						if (couleur_2==C_ROUGE)										//Remplacer rouge par rouge,pas de modif
							bEchangerCouleur=false;
						else
						if (couleur_2==C_VERT) {									//Remplacer rouge par vert
							nValeurRougeNouveau=nValeurVertAncienne;
							nValeurVertNouveau=nValeurRougeAncienne;
							nValeurBleuNouveau=nValeurBleuAncienne;
						}else
						if (couleur_2==C_BLEU) {									//Remplacer rouge par bleu
							nValeurRougeNouveau=nValeurBleuAncienne;
							nValeurVertNouveau=nValeurVertAncienne;
							nValeurBleuNouveau=nValeurRougeAncienne;
						}else
						if (couleur_2==C_JAUNE) {
							if (couleur_dominante_remplacement==C_ROUGE) {			//Remplacer rouge par jaune dominante rouge (orange?)
								nValeurRougeNouveau=nValeurRougeAncienne;
								nValeurVertNouveau=MOYENNE_ROUGE_ET_BLEU;
								nValeurBleuNouveau=nValeurBleuAncienne;
							}else
							if (couleur_dominante_remplacement==C_VERT) {			//Remplacer rouge par jaune dominante vert (vert...clair?)
								nValeurRougeNouveau=MOYENNE_ROUGE_ET_BLEU;
								nValeurVertNouveau=nValeurRougeAncienne;
								nValeurBleuNouveau=nValeurBleuAncienne;
							}
							else {													//Remplacer rouge par jaune simple si dominante bleu ou aucune
								nValeurRougeNouveau=nValeurRougeAncienne;
								nValeurVertNouveau=nValeurRougeAncienne;
								nValeurBleuNouveau=nValeurBleuAncienne;
							}
						}else
						if (couleur_2==C_VIOLET) {
							if (couleur_dominante_remplacement==C_ROUGE) {			//Remplacer rouge par violet dominante rouge (rose?)
								nValeurRougeNouveau=nValeurRougeAncienne;
								nValeurVertNouveau=nValeurVertAncienne;
								nValeurBleuNouveau=MOYENNE_VERT_ET_ROUGE;
							}else
							if (couleur_dominante_remplacement==C_BLEU) {			//Remplacer rouge par violet dominante bleu (mauve?)
								nValeurRougeNouveau=MOYENNE_VERT_ET_ROUGE;
								nValeurVertNouveau=nValeurVertAncienne;
								nValeurBleuNouveau=nValeurRougeAncienne;
							}
							else {													//Remplacer rouge par violet simple si dominante vert ou aucune
								nValeurRougeNouveau=nValeurRougeAncienne;
								nValeurVertNouveau=nValeurVertAncienne;
								nValeurBleuNouveau=nValeurRougeAncienne;
							}
						}else
						if (couleur_2==C_CYAN) {
							if (couleur_dominante_remplacement==C_BLEU) {			//Remplacer rouge par cyan dominante bleu (bleu marine?)
								nValeurRougeNouveau=nValeurVertAncienne;
								nValeurVertNouveau=MOYENNE_VERT_ET_ROUGE;
								nValeurBleuNouveau=nValeurRougeAncienne;
							}else
							if (couleur_dominante_remplacement==C_VERT) {			//Remplacer rouge par cyan dominante vert (vert...clair version 2?)
								nValeurRougeNouveau=nValeurBleuAncienne;
								nValeurVertNouveau=nValeurRougeAncienne;
								nValeurBleuNouveau=MOYENNE_ROUGE_ET_BLEU;
							}
							else {													//Remplacer rouge par cyan simple si dominante rouge ou aucune
								nValeurRougeNouveau=MIN_ENTRE_BLEU_ET_VERT;
								nValeurVertNouveau=nValeurRougeAncienne;
								nValeurBleuNouveau=nValeurRougeAncienne;
							}
						}
						else
							bEchangerCouleur=false;									//Couleur 2 inconnue,pas de modif

					}else

					//Echange du vert
					if (couleur_1==C_VERT) {
						if (couleur_2==C_ROUGE) {									//Remplacer vert par rouge
							nValeurRougeNouveau=nValeurVertAncienne;
							nValeurVertNouveau=nValeurRougeAncienne;
							nValeurBleuNouveau=nValeurBleuAncienne;
						}else
						if (couleur_2==C_VERT)										//Remplacer vert par vert,pas de modif
							bEchangerCouleur=false;
						else
						if (couleur_2==C_BLEU) {									//Remplacer vert par bleu
							nValeurRougeNouveau=nValeurRougeAncienne;
							nValeurVertNouveau=nValeurBleuAncienne;
							nValeurBleuNouveau=nValeurVertAncienne;
						}else
						if (couleur_2==C_JAUNE) {
							if (couleur_dominante_remplacement==C_ROUGE) {			//Remplacer vert par jaune dominante rouge (orange?)
								nValeurRougeNouveau=nValeurVertAncienne;
								nValeurVertNouveau=MOYENNE_BLEU_ET_VERT;
								nValeurBleuNouveau=nValeurBleuAncienne;
							}else
							if (couleur_dominante_remplacement==C_VERT) {			//Remplacer vert par jaune dominante vert (vert...clair?)
								nValeurRougeNouveau=MOYENNE_BLEU_ET_VERT;
								nValeurVertNouveau=nValeurVertAncienne;
								nValeurBleuNouveau=nValeurBleuAncienne;
							}
							else {													//Remplacer vert par jaune simple si dominante bleu ou aucune
								nValeurRougeNouveau=nValeurVertAncienne;
								nValeurVertNouveau=nValeurVertAncienne;
								nValeurBleuNouveau=nValeurBleuAncienne;
							}
						}else
						if (couleur_2==C_VIOLET) {
							if (couleur_dominante_remplacement==C_ROUGE) {			//Remplacer vert par violet dominante rouge (rose?)
								nValeurRougeNouveau=nValeurVertAncienne;
								nValeurVertNouveau=nValeurBleuAncienne;
								nValeurBleuNouveau=MOYENNE_BLEU_ET_VERT;
							}else
							if (couleur_dominante_remplacement==C_BLEU) {			//Remplacer vert par violet dominante bleu (mauve?)
								nValeurRougeNouveau=MOYENNE_VERT_ET_ROUGE;
								nValeurVertNouveau=nValeurRougeAncienne;
								nValeurBleuNouveau=nValeurVertAncienne;
							}
							else {													//Remplacer vert par violet simple si dominante vert ou aucune
								nValeurRougeNouveau=nValeurVertAncienne;
								nValeurVertNouveau=MIN_ENTRE_ROUGE_ET_BLEU;
								nValeurBleuNouveau=nValeurVertAncienne;
							}
						}else
						if (couleur_2==C_CYAN) {
							if (couleur_dominante_remplacement==C_BLEU) {			//Remplacer vert par cyan dominante bleu (bleu marine?)
								nValeurRougeNouveau=nValeurRougeAncienne;
								nValeurVertNouveau=MOYENNE_VERT_ET_ROUGE;
								nValeurBleuNouveau=nValeurVertAncienne;
							}else
							if (couleur_dominante_remplacement==C_VERT) {			//Remplacer vert par cyan dominante vert (vert...clair version 2?)
								nValeurRougeNouveau=nValeurRougeAncienne;
								nValeurVertNouveau=nValeurVertAncienne;
								nValeurBleuNouveau=MOYENNE_VERT_ET_ROUGE;
							}
							else {													//Remplacer vert par cyan simple si dominante rouge ou aucune
								nValeurRougeNouveau=nValeurRougeAncienne;
								nValeurVertNouveau=nValeurVertAncienne;
								nValeurBleuNouveau=nValeurVertAncienne;
							}
						}
						else
							bEchangerCouleur=false;									//Couleur 2 inconnue,pas de modif
					}else

					//Echange du bleu
					if (couleur_1==C_BLEU) {
						if (couleur_2==C_ROUGE) {									//Remplacer bleu par rouge
							nValeurRougeNouveau=nValeurBleuAncienne;
							nValeurVertNouveau=nValeurVertAncienne;
							nValeurBleuNouveau=nValeurRougeAncienne;
						}else
						if (couleur_2==C_VERT) {									//Remplacer bleu par vert
							nValeurRougeNouveau=nValeurRougeAncienne;
							nValeurVertNouveau=nValeurBleuAncienne;
							nValeurBleuNouveau=nValeurVertAncienne;
						}else
						if (couleur_2==C_BLEU)										//Remplacer bleu par bleu,pas de modif
							bEchangerCouleur=false;
						else
						if (couleur_2==C_JAUNE)	{
							if (couleur_dominante_remplacement==C_ROUGE) {			//Remplacer bleu par jaune dominante rouge (orange?)
								nValeurRougeNouveau=nValeurBleuAncienne;
								nValeurVertNouveau=MOYENNE_BLEU_ET_VERT;
								nValeurBleuNouveau=nValeurVertAncienne;
							}else
							if (couleur_dominante_remplacement==C_VERT) {			//Remplacer bleu par jaune dominante vert (vert...clair?)
								nValeurRougeNouveau=MOYENNE_ROUGE_ET_BLEU;
								nValeurVertNouveau=nValeurBleuAncienne;
								nValeurBleuNouveau=nValeurRougeAncienne;
							}
							else {													//Remplacer bleu par jaune simple si dominante bleu ou aucune
								nValeurRougeNouveau=nValeurBleuAncienne;
								nValeurVertNouveau=nValeurBleuAncienne;
								nValeurBleuNouveau=MIN_ENTRE_VERT_ET_ROUGE;
							}
						}else
						if (couleur_2==C_VIOLET) {
							if (couleur_dominante_remplacement==C_ROUGE) {			//Remplacer bleu par violet dominante rouge (rose?)
								nValeurRougeNouveau=nValeurBleuAncienne;
								nValeurVertNouveau=nValeurVertAncienne;
								nValeurBleuNouveau=MOYENNE_BLEU_ET_VERT;
							}else
							if (couleur_dominante_remplacement==C_BLEU) {			//Remplacer bleu par violet dominante bleu (mauve?)
								nValeurRougeNouveau=MOYENNE_BLEU_ET_VERT;
								nValeurVertNouveau=nValeurVertAncienne;
								nValeurBleuNouveau=nValeurBleuAncienne;
							}
							else {													//Remplacer bleu par violet simple si dominante verte ou aucune
								nValeurRougeNouveau=nValeurBleuAncienne;
								nValeurVertNouveau=nValeurVertAncienne;
								nValeurBleuNouveau=nValeurBleuAncienne;
							}
						}else
						if (couleur_2==C_CYAN) {
							if (couleur_dominante_remplacement==C_BLEU) {			//Remplacer bleu par cyan dominante bleu (bleu marine?)
								nValeurRougeNouveau=nValeurRougeAncienne;
								nValeurVertNouveau=MOYENNE_ROUGE_ET_BLEU;
								nValeurBleuNouveau=nValeurBleuAncienne;
							}else
							if (couleur_dominante_remplacement==C_VERT) {			//Remplacer bleu par cyan dominante vert (vert...clair version 2?)
								nValeurRougeNouveau=nValeurRougeAncienne;
								nValeurVertNouveau=nValeurBleuAncienne;
								nValeurBleuNouveau=MOYENNE_ROUGE_ET_BLEU;
							}
							else{													//Remplacer bleu par cyan simple si dominante route ou aucune
								nValeurRougeNouveau=nValeurRougeAncienne;
								nValeurVertNouveau=nValeurBleuAncienne;
								nValeurBleuNouveau=nValeurBleuAncienne;
							}
						}
						else
							bEchangerCouleur=false;									//Couleur 2 inconnue,pas de modif
					}else
					//Echange du jaune
					if (couleur_1==C_JAUNE) {
						if (couleur_2==C_ROUGE) {									//Remplacer jaune par rouge
							nValeurRougeNouveau=MAX_ENTRE_VERT_ET_ROUGE;
							nValeurVertNouveau=nValeurBleuAncienne;
							nValeurBleuNouveau=nValeurBleuAncienne;
						}else
						if (couleur_2==C_VERT) {									//Remplacer jaune par vert
							nValeurRougeNouveau=nValeurBleuAncienne;
							nValeurVertNouveau=MAX_ENTRE_VERT_ET_ROUGE;
							nValeurBleuNouveau=nValeurBleuAncienne;
						}else
						if (couleur_2==C_BLEU) {									//Remplacer jaune par bleu
							nValeurRougeNouveau=nValeurBleuAncienne;
							nValeurVertNouveau=nValeurBleuAncienne;
							nValeurBleuNouveau=MAX_ENTRE_VERT_ET_ROUGE;
						}else
						if (couleur_2==C_JAUNE) {
							if (couleur_dominante_remplacement==C_ROUGE) {			//Remplacer jaune par jaune dominante rouge (orange?)
								nValeurRougeNouveau=MAX_ENTRE_VERT_ET_ROUGE;
								nValeurVertNouveau=MIN_ENTRE_VERT_ET_ROUGE;
								nValeurBleuNouveau=nValeurBleuAncienne;
							}else
							if (couleur_dominante_remplacement==C_VERT) {			//Remplacer jaune par jaune dominante vert (vert...clair?)
								nValeurRougeNouveau=MIN_ENTRE_VERT_ET_ROUGE;
								nValeurVertNouveau=MAX_ENTRE_VERT_ET_ROUGE;
								nValeurBleuNouveau=nValeurBleuAncienne;
							}
							else  {													//Remplacer jaune par jaune simple si dominante bleu ou aucune
								nValeurRougeNouveau=MOYENNE_VERT_ET_ROUGE;
								nValeurVertNouveau=MOYENNE_VERT_ET_ROUGE;
								nValeurBleuNouveau=nValeurBleuAncienne;
							}
						}else
						if (couleur_2==C_VIOLET) {
							if (couleur_dominante_remplacement==C_ROUGE) {			//Remplacer jaune par violet dominante rouge (rose?)
								nValeurRougeNouveau=MAX_ENTRE_VERT_ET_ROUGE;
								nValeurVertNouveau=nValeurBleuAncienne;
								nValeurBleuNouveau=MIN_ENTRE_VERT_ET_ROUGE;
							}else
							if (couleur_dominante_remplacement==C_BLEU) {			//Remplacer jaune par violet dominante bleu (mauve?)
								nValeurRougeNouveau=MIN_ENTRE_VERT_ET_ROUGE;
								nValeurVertNouveau=nValeurBleuAncienne;
								nValeurBleuNouveau=MAX_ENTRE_VERT_ET_ROUGE;
							}
							else {													//Remplacer jaune par violet simple si dominante vert ou aucune
								nValeurRougeNouveau=MOYENNE_VERT_ET_ROUGE;
								nValeurVertNouveau=nValeurBleuAncienne;
								nValeurBleuNouveau=MOYENNE_VERT_ET_ROUGE;
							}
						}else
						if (couleur_2==C_CYAN) {
							if (couleur_dominante_remplacement==C_BLEU) {			//Remplacer jaune par cyan dominante bleu (bleu marine?)
								nValeurRougeNouveau=nValeurBleuAncienne;
								nValeurVertNouveau=MIN_ENTRE_VERT_ET_ROUGE;
								nValeurBleuNouveau=MAX_ENTRE_VERT_ET_ROUGE;
							}else
							if (couleur_dominante_remplacement==C_VERT) {			//Remplacer jaune par cyan dominante vert (vert...clair version 2?)
								nValeurRougeNouveau=nValeurBleuAncienne;
								nValeurVertNouveau=MAX_ENTRE_VERT_ET_ROUGE;
								nValeurBleuNouveau=MIN_ENTRE_VERT_ET_ROUGE;
							}
							else {													//Remplacer jaune par cyan simple si dominante rouge ou aucune
								nValeurRougeNouveau=nValeurBleuAncienne;
								nValeurVertNouveau=MOYENNE_VERT_ET_ROUGE;
								nValeurBleuNouveau=MOYENNE_VERT_ET_ROUGE;
							}
						}
						else
							bEchangerCouleur=false;									//Couleur 2 inconnue,pas de modif
					}else
					//Echange du violet
					if (couleur_1==C_VIOLET) {
						if (couleur_2==C_ROUGE) {									//Remplacer violet par rouge
							nValeurRougeNouveau=MAX_ENTRE_ROUGE_ET_BLEU;
							nValeurVertNouveau=nValeurVertAncienne;
							nValeurBleuNouveau=nValeurVertAncienne;
						}else
						if (couleur_2==C_VERT) {									//Remplacer violet par vert
							nValeurRougeNouveau=nValeurVertAncienne;
							nValeurVertNouveau=MAX_ENTRE_ROUGE_ET_BLEU;
							nValeurBleuNouveau=nValeurVertAncienne;
						}else
						if (couleur_2==C_BLEU) {									//Remplacer violet par bleu
							nValeurRougeNouveau=nValeurVertAncienne;
							nValeurVertNouveau=nValeurVertAncienne;
							nValeurBleuNouveau=MAX_ENTRE_ROUGE_ET_BLEU;
						}else
						if (couleur_2==C_JAUNE) {
							if (couleur_dominante_remplacement==C_ROUGE) {			//Remplacer violet par jaune dominante rouge (orange?)
								nValeurRougeNouveau=MAX_ENTRE_ROUGE_ET_BLEU;
								nValeurVertNouveau=MIN_ENTRE_ROUGE_ET_BLEU;
								nValeurBleuNouveau=nValeurVertAncienne;
							}else
							if (couleur_dominante_remplacement==C_VERT) {			//Remplacer violet par jaune dominante vert (vert...clair?)
								nValeurRougeNouveau=MIN_ENTRE_ROUGE_ET_BLEU;
								nValeurVertNouveau=MAX_ENTRE_ROUGE_ET_BLEU;
								nValeurBleuNouveau=nValeurVertAncienne;
							}
							else {													//Remplacer violet par jaune simple si dominante bleu ou aucune
								nValeurRougeNouveau=MOYENNE_ROUGE_ET_BLEU;
								nValeurVertNouveau=MOYENNE_ROUGE_ET_BLEU;
								nValeurBleuNouveau=nValeurVertAncienne;
							}
						}else
						if (couleur_2==C_VIOLET) {
							if (couleur_dominante_remplacement==C_ROUGE) {			//Remplacer violet par violet dominante rouge (rose?)
								nValeurRougeNouveau=MAX_ENTRE_ROUGE_ET_BLEU;
								nValeurVertNouveau=nValeurVertAncienne;
								nValeurBleuNouveau=MIN_ENTRE_ROUGE_ET_BLEU;
							}else
							if (couleur_dominante_remplacement==C_BLEU) {			//Remplacer violet par violet dominante bleu (mauve?)
								nValeurRougeNouveau=MIN_ENTRE_ROUGE_ET_BLEU;
								nValeurVertNouveau=nValeurVertAncienne;
								nValeurBleuNouveau=MAX_ENTRE_ROUGE_ET_BLEU;
							}
							else {													//Remplacer violet par violet simple si dominante vert ou aucune
								nValeurRougeNouveau=MOYENNE_ROUGE_ET_BLEU;
								nValeurVertNouveau=nValeurVertAncienne;
								nValeurBleuNouveau=MOYENNE_ROUGE_ET_BLEU;
							}
						}else
						if (couleur_2==C_CYAN) {
							if (couleur_dominante_remplacement==C_BLEU) {			//Remplacer violet par cyan dominante bleu (bleu marine?)
								nValeurRougeNouveau=nValeurVertAncienne;
								nValeurVertNouveau=MIN_ENTRE_ROUGE_ET_BLEU;
								nValeurBleuNouveau=MAX_ENTRE_ROUGE_ET_BLEU;
							}else
							if (couleur_dominante_remplacement==C_VERT) {			//Remplacer violet par cyan dominante vert (vert...clair version 2?)
								nValeurRougeNouveau=nValeurVertAncienne;
								nValeurVertNouveau=MAX_ENTRE_ROUGE_ET_BLEU;
								nValeurBleuNouveau=MIN_ENTRE_ROUGE_ET_BLEU;
							}
							else {													//Remplacer violet par cyan simple si dominante rouge ou aucune
								nValeurRougeNouveau=nValeurVertAncienne;
								nValeurVertNouveau=MOYENNE_ROUGE_ET_BLEU;
								nValeurBleuNouveau=MOYENNE_ROUGE_ET_BLEU;
							}
						}
						else
							bEchangerCouleur=false;									//Couleur 2 inconnue,pas de modif
					}else
					//Echange du cyan
					if (couleur_1==C_CYAN) {
						if (couleur_2==C_ROUGE) {									//Remplacer cyan par rouge
							nValeurRougeNouveau=MAX_ENTRE_BLEU_ET_VERT;
							nValeurVertNouveau=nValeurRougeAncienne;
							nValeurBleuNouveau=nValeurRougeAncienne;
						}else
						if (couleur_2==C_VERT) {									//Remplacer cyan par vert
							nValeurRougeNouveau=nValeurRougeAncienne;
							nValeurVertNouveau=MAX_ENTRE_BLEU_ET_VERT;
							nValeurBleuNouveau=nValeurRougeAncienne;
						}else
						if (couleur_2==C_BLEU) {									//Remplacer cyan par bleu
							nValeurRougeNouveau=nValeurRougeAncienne;
							nValeurVertNouveau=nValeurRougeAncienne;
							nValeurBleuNouveau=MAX_ENTRE_BLEU_ET_VERT;
						}else
						if (couleur_2==C_JAUNE) {
							if (couleur_dominante_remplacement==C_ROUGE) {			//Remplacer cyan par jaune dominante rouge (orange?)
								nValeurRougeNouveau=MAX_ENTRE_BLEU_ET_VERT;
								nValeurVertNouveau=MIN_ENTRE_BLEU_ET_VERT;
								nValeurBleuNouveau=nValeurRougeAncienne;
							}else
							if (couleur_dominante_remplacement==C_VERT) {			//Remplacer cyan par jaune dominante vert (vert...clair?)
								nValeurRougeNouveau=MIN_ENTRE_BLEU_ET_VERT;
								nValeurVertNouveau=MAX_ENTRE_BLEU_ET_VERT;
								nValeurBleuNouveau=nValeurRougeAncienne;
							}
							else {													//Remplacer cyan par jaune simple si dominante bleu ou aucune
								nValeurRougeNouveau=MOYENNE_BLEU_ET_VERT;
								nValeurVertNouveau=MOYENNE_BLEU_ET_VERT;
								nValeurBleuNouveau=nValeurRougeAncienne;
							}
						}else
						if (couleur_2==C_VIOLET) {
							if (couleur_dominante_remplacement==C_ROUGE) {			//Remplacer cyan par violet dominante rouge (rose?)
								nValeurRougeNouveau=MAX_ENTRE_BLEU_ET_VERT;
								nValeurVertNouveau=nValeurRougeAncienne;
								nValeurBleuNouveau=MIN_ENTRE_BLEU_ET_VERT;
							}else
							if (couleur_dominante_remplacement==C_BLEU) {			//Remplacer cyan par violet dominante bleu (mauve?)
								nValeurRougeNouveau=MIN_ENTRE_BLEU_ET_VERT;
								nValeurVertNouveau=nValeurRougeAncienne;
								nValeurBleuNouveau=MAX_ENTRE_BLEU_ET_VERT;
							}
							else {													//Remplacer cyan par violet simple si dominante vert ou aucune
								nValeurRougeNouveau=MOYENNE_BLEU_ET_VERT;
								nValeurVertNouveau=nValeurRougeAncienne;
								nValeurBleuNouveau=MOYENNE_BLEU_ET_VERT;
							}
						}else
						if (couleur_2==C_CYAN) {
							if (couleur_dominante_remplacement==C_BLEU) {			//Remplacer cyan par cyan dominante bleu (bleu marine?)
								nValeurRougeNouveau=nValeurRougeAncienne;
								nValeurVertNouveau=MIN_ENTRE_BLEU_ET_VERT;
								nValeurBleuNouveau=MAX_ENTRE_BLEU_ET_VERT;
							}else
							if (couleur_dominante_remplacement==C_VERT) {			//Remplacer cyan par cyan dominante vert (vert...clair version 2?)
								nValeurRougeNouveau=nValeurRougeAncienne;
								nValeurVertNouveau=MAX_ENTRE_BLEU_ET_VERT;
								nValeurBleuNouveau=MIN_ENTRE_BLEU_ET_VERT;
							}
							else {													//Remplacer cyan par cyan simple si dominante rouge ou aucune
								nValeurRougeNouveau=nValeurRougeAncienne;
								nValeurVertNouveau=MOYENNE_BLEU_ET_VERT;
								nValeurBleuNouveau=MOYENNE_BLEU_ET_VERT;
							}
						}
						else
							bEchangerCouleur=false;									//Couleur 2 inconnue,pas de modif
					}

				} //if (bEchangerCouleur)

				//Effectue les modifications nécessaires du pixel,s'il doit être changé
				if (bEchangerCouleur) {

					//définit la nouvelle couleur du pixel
					System::Drawing::Color newColor = System::Drawing::Color::FromArgb(
						nValeurRougeNouveau,
						nValeurVertNouveau,
						nValeurBleuNouveau
					);

					//change la couleur actuelle du pixel
					source->SetPixel(x,y,newColor);

					//remet le booléen à false pour que le prochain pixel soit vérifié
					bEchangerCouleur=false;
				}		

			} //for (y=0;y<source->Height;y++)
		} //for (x=0;x<source->Width;x++)

		return source;

///////////
// effacement des macros
///////////
#undef MIN_ENTRE_BLEU_ET_VERT
#undef MIN_ENTRE_ROUGE_ET_BLEU
#undef MIN_ENTRE_VERT_ET_ROUGE
#undef MAX_ENTRE_BLEU_ET_VERT
#undef MAX_ENTRE_ROUGE_ET_BLEU
#undef MAX_ENTRE_VERT_ET_ROUGE
#undef MOYENNE_BLEU_ET_VERT
#undef MOYENNE_ROUGE_ET_BLEU
#undef MOYENNE_VERT_ET_ROUGE

///////////
// effacement des définitions des valeurs de couleur
///////////
#undef C_ROUGE
#undef C_VERT
#undef C_BLEU
#undef C_JAUNE
#undef C_VIOLET
#undef C_CYAN
#undef C_AUCUNE

	} //static System::Drawing::Bitmap^ Echange_couleurs(System::Drawing::Bitmap^ source,int couleur_1,int couleur_2,int couleur_dominante_remplacee,int couleur_dominante_remplacement,Entier_partage^ nProgress=nullptr)
#pragma endregion

	/// <summary>
	/// Algorithmes pour agrandir une image en ajoutant 1 pixel gris entre chaque pixel existant.
	/// Soit n la taille d'un côté de l'image,ce côté mesurera 2n-1 pixels après modification.
	static System::Drawing::Bitmap^ Etire_gris(System::Drawing::Bitmap^ source,Entier_partage^ nProgress=nullptr) {

		int x_dest,y_dest;

		System::Drawing::Bitmap^ image_agrandie=gcnew System::Drawing::Bitmap(2*(source->Width)-1,2*(source->Height)-1);

		if (nProgress) 
			nProgress->valeur=0;

		for(x_dest=0;x_dest<image_agrandie->Width;x_dest++) {
			
			//pixel pair horizontalement:
			//	-non modifié si pair verticalement (y_dest%2==0)
			//	-modifié selon les pixels à la verticale si impair verticalement
			if (x_dest%2==0) {

				for(y_dest=0;y_dest<image_agrandie->Height;y_dest++) {

					if (y_dest%2==0)	//positionnement du pixel d'origine

						image_agrandie->SetPixel(x_dest,y_dest,source->GetPixel(x_dest/2,y_dest/2));

					else {				//pixel portant la couleur combinée entre le pixel y-1 et y+1

						System::Drawing::Color Pixel1 = source->GetPixel(x_dest/2,y_dest/2);		//couleur du pixel y-1
						System::Drawing::Color Pixel2 = source->GetPixel(x_dest/2,(y_dest/2)+1);	//couleur du pixel y+1

						//stocke les valeurs de gris des pixels à la place de la valeur rouge
						Pixel1.FromArgb((Pixel1.R+Pixel1.G+Pixel1.B)/3,0,0);
						Pixel2.FromArgb((Pixel1.R+Pixel1.G+Pixel1.B)/3,0,0);

						image_agrandie->SetPixel(x_dest,y_dest,System::Drawing::Color::FromArgb(
							 /*255- */(Pixel1.R+Pixel2.R)/2,
							 /*255- */(Pixel1.R+Pixel2.R)/2,
							 /*255- */(Pixel1.R+Pixel2.R)/2)
						);

					} //if (y_dest%2!=0)

					if (nProgress) 
						nProgress->valeur++;

				} //for(y_dest=0;y_dest<image_agrandie->Width;y++)

			} //if (x_dest%2==0)

			//pixel impair horizontalement:
			//	-modifié selon les pixels à l'horizontale si pair verticalement
			//	-modifié selon les (4) pixels à la diagonale) si impair verticalement
			else {

				for(y_dest=0;y_dest<image_agrandie->Height;y_dest++) {

					if (y_dest%2==0) {	//pixel portant la couleur combinée entre le pixel x-1 et x+1

						System::Drawing::Color Pixel1 = source->GetPixel(x_dest/2,y_dest/2);		//couleur du pixel x-1
						System::Drawing::Color Pixel2 = source->GetPixel((x_dest/2)+1,y_dest/2);	//couleur du pixel x+1

						//stocke les valeurs de gris des pixels à la place de la valeur rouge
						Pixel1.FromArgb((Pixel1.R+Pixel1.G+Pixel1.B)/3,0,0);
						Pixel2.FromArgb((Pixel2.R+Pixel2.G+Pixel2.B)/3,0,0);

						image_agrandie->SetPixel(x_dest,y_dest,System::Drawing::Color::FromArgb(
							 /*255- */(Pixel1.R+Pixel2.R)/2,
							 /*255- */(Pixel1.R+Pixel2.R)/2,
							 /*255- */(Pixel1.R+Pixel2.R)/2)
						);

					}

					else {  //pixel portant la couleur combinée entre les pixels aux angles

						System::Drawing::Color Pixel_1 = source->GetPixel(x_dest/2,y_dest/2);			//couleur du pixel x-1,y-1
						System::Drawing::Color Pixel_2 = source->GetPixel((x_dest/2)+1,y_dest/2);		//couleur du pixel x+1,y-1
						System::Drawing::Color Pixel_3 = source->GetPixel(x_dest/2,(y_dest/2)+1);		//couleur du pixel x-1,y+1
						System::Drawing::Color Pixel_4 = source->GetPixel((x_dest/2)+1,(y_dest/2)+1);	//couleur du pixel x+1,y+1

						//stocke les valeurs de gris des pixels à la place de la valeur rouge
						Pixel_1.FromArgb((Pixel_1.R+Pixel_1.G+Pixel_1.B)/3,0,0);
						Pixel_2.FromArgb((Pixel_2.R+Pixel_2.G+Pixel_2.B)/3,0,0);
						Pixel_3.FromArgb((Pixel_3.R+Pixel_3.G+Pixel_3.B)/3,0,0);
						Pixel_4.FromArgb((Pixel_4.R+Pixel_4.G+Pixel_4.B)/3,0,0);

						image_agrandie->SetPixel(	x_dest,
													y_dest,
													System::Drawing::Color::FromArgb(
														 /*255- */(Pixel_1.R+Pixel_2.R+Pixel_3.R+Pixel_4.R)/4,
														 /*255- */(Pixel_1.R+Pixel_2.R+Pixel_3.R+Pixel_4.R)/4,
														 /*255- */(Pixel_1.R+Pixel_2.R+Pixel_3.R+Pixel_4.R)/4
													)
												);
					} //if (y_dest%2!=0)

					if (nProgress) 
						nProgress->valeur++;

				} //for(y_dest=0;y_dest<image_agrandie->Width;y++)

			} //if (x_dest%2==1)

		} //for(x_dest=0;x_dest<image_agrandie->Width;x++)

		return image_agrandie;

	} //static System::Drawing::Bitmap^ Etire_gris(System::Drawing::Bitmap^ source,Entier_partage^ nProgress=nullptr)

	
	/// <summary>
	/// Algorithmes pour agrandir une image en ajoutant chaque pixel existant entre des pixels gris //en remplaçant chaque pixel par un pixel gris entouré de la couleur pré-existante.
	/// Soit n la taille d'un côté de l'image,ce côté mesurera 2n-1 pixels après modification.
	///
	/// 2n-1 ou plus plante ... 2n-2 ou moins perd des informations.
	///
	/// </summary>
	static System::Drawing::Bitmap^ Etire_gris_interverti(System::Drawing::Bitmap^ source,Entier_partage^ nProgress=nullptr) {

		int x_dest,y_dest;

		System::Drawing::Bitmap^ image_agrandie=gcnew System::Drawing::Bitmap(2*(source->Width)-2,2*(source->Height)-2);

		if (nProgress) 
			nProgress->valeur=0;

		for(x_dest=0;x_dest<image_agrandie->Width;x_dest++) {
			
			//pixel pair horizontalement:
			//	-modifié selon les (4) pixels à la diagonale) si impair verticalement		//ancien:non modifié si pair verticalement (y_dest%2==0)
			//	-modifié selon les pixels à l'horizontale si impair verticalement			//ancien:modifié selon les pixels à la verticale si impair verticalement
			if ( !(x_dest%2==0) ) {

				for(y_dest=0;y_dest<image_agrandie->Height;y_dest++) {

					if ( !(y_dest%2==0) )	//positionnement du pixel d'origine

						image_agrandie->SetPixel(x_dest,y_dest,source->GetPixel(x_dest/2,y_dest/2));

					else {				//pixel portant la couleur combinée entre le pixel y-1 et y+1

						System::Drawing::Color Pixel1 = source->GetPixel(x_dest/2,y_dest/2);		//couleur du pixel y-1
						System::Drawing::Color Pixel2 = source->GetPixel(x_dest/2,(y_dest/2)+1);	//couleur du pixel y+1

						//stocke les valeurs de gris des pixels à la place de la valeur rouge
						Pixel1.FromArgb((Pixel1.R+Pixel1.G+Pixel1.B)/3,0,0);
						Pixel2.FromArgb((Pixel1.R+Pixel1.G+Pixel1.B)/3,0,0);

						image_agrandie->SetPixel(x_dest,y_dest,System::Drawing::Color::FromArgb(
							 /*255- */(Pixel1.R+Pixel2.R)/2,
							 /*255- */(Pixel1.R+Pixel2.R)/2,
							 /*255- */(Pixel1.R+Pixel2.R)/2)
						);

					} //if ( !(y_dest%2!=0) )

					if (nProgress) 
						nProgress->valeur++;

				} //for(y_dest=0;y_dest<image_agrandie->Width;y++)

			} //if ( !(x_dest%2==0) )

			//pixel impair horizontalement:
			//	-modifié selon les pixels à la verticale si pair verticalement			//modifié selon les pixels à l'horizontale si pair verticalement
			//	-non modifié si impair verticalement									//modifié selon les (4) pixels à la diagonale) si impair verticalement
			else {

				for(y_dest=0;y_dest<image_agrandie->Height;y_dest++) {

					if ( !(y_dest%2==0) ) {	//pixel portant la couleur combinée entre le pixel x-1 et x+1

						System::Drawing::Color Pixel1 = source->GetPixel(x_dest/2,y_dest/2);		//couleur du pixel x-1
						System::Drawing::Color Pixel2 = source->GetPixel((x_dest/2)+1,y_dest/2);	//couleur du pixel x+1

						//stocke les valeurs de gris des pixels à la place de la valeur rouge
						Pixel1.FromArgb((Pixel1.R+Pixel1.G+Pixel1.B)/3,0,0);
						Pixel2.FromArgb((Pixel2.R+Pixel2.G+Pixel2.B)/3,0,0);

						image_agrandie->SetPixel(x_dest,y_dest,System::Drawing::Color::FromArgb(
							 /*255- */(Pixel1.R+Pixel2.R)/2,
							 /*255- */(Pixel1.R+Pixel2.R)/2,
							 /*255- */(Pixel1.R+Pixel2.R)/2)
						);

					}

					else {  //pixel portant la couleur combinée entre les pixels aux angles

						System::Drawing::Color Pixel_1 = source->GetPixel(x_dest/2,y_dest/2);			//couleur du pixel x-1,y-1
						System::Drawing::Color Pixel_2 = source->GetPixel((x_dest/2)+1,y_dest/2);		//couleur du pixel x+1,y-1
						System::Drawing::Color Pixel_3 = source->GetPixel(x_dest/2,(y_dest/2)+1);		//couleur du pixel x-1,y+1
						System::Drawing::Color Pixel_4 = source->GetPixel((x_dest/2)+1,(y_dest/2)+1);	//couleur du pixel x+1,y+1

						//stocke les valeurs de gris des pixels à la place de la valeur rouge
						Pixel_1.FromArgb((Pixel_1.R+Pixel_1.G+Pixel_1.B)/3,0,0);
						Pixel_2.FromArgb((Pixel_2.R+Pixel_2.G+Pixel_2.B)/3,0,0);
						Pixel_3.FromArgb((Pixel_3.R+Pixel_3.G+Pixel_3.B)/3,0,0);
						Pixel_4.FromArgb((Pixel_4.R+Pixel_4.G+Pixel_4.B)/3,0,0);

						image_agrandie->SetPixel(	x_dest,
													y_dest,
													System::Drawing::Color::FromArgb(
														 /*255- */(Pixel_1.R+Pixel_2.R+Pixel_3.R+Pixel_4.R)/4,
														 /*255- */(Pixel_1.R+Pixel_2.R+Pixel_3.R+Pixel_4.R)/4,
														 /*255- */(Pixel_1.R+Pixel_2.R+Pixel_3.R+Pixel_4.R)/4
													)
												);
					} //if ( !(y_dest%2!=0) )

					if (nProgress) 
						nProgress->valeur++;

				} //for(y_dest=0;y_dest<image_agrandie->Width;y++)

			} //if ( !(x_dest%2==1) )

		} //for(x_dest=0;x_dest<image_agrandie->Width;x++)

		return image_agrandie;

	} //static System::Drawing::Bitmap^ Etire_gris_contour(System::Drawing::Bitmap^ source,Entier_partage^ nProgress=nullptr)



	/// <summary>
	/// Algorithmes pour agrandir une image en ajoutant 1 pixel gris entre chaque pixel existant.
	/// Ajoute un pixel blanc au calcul pour rendre le pixel gris plus lumineux.
	/// Soit n la taille d'un côté de l'image,ce côté mesurera 2n-1 pixels après modification.
	/// </summary>
	static System::Drawing::Bitmap^ Etire_gris_lumineux(System::Drawing::Bitmap^ source,Entier_partage^ nProgress=nullptr) {

		int x_dest,y_dest;

		System::Drawing::Bitmap^ image_agrandie=gcnew System::Drawing::Bitmap(2*(source->Width)-1,2*(source->Height)-1);

		if (nProgress) 
			nProgress->valeur=0;

		for(x_dest=0;x_dest<image_agrandie->Width;x_dest++) {
			
			//pixel pair horizontalement:
			//	-non modifié si pair verticalement (y_dest%2==0)
			//	-modifié selon les pixels à la verticale si impair verticalement
			if (x_dest%2==0) {

				for(y_dest=0;y_dest<image_agrandie->Height;y_dest++) {

					if (y_dest%2==0)	//positionnement du pixel d'origine

						image_agrandie->SetPixel(x_dest,y_dest,source->GetPixel(x_dest/2,y_dest/2));

					else {				//pixel portant la couleur combinée entre le pixel y-1 et y+1

						System::Drawing::Color Pixel1 = source->GetPixel(x_dest/2,y_dest/2);		//couleur du pixel y-1
						System::Drawing::Color Pixel2 = source->GetPixel(x_dest/2,(y_dest/2)+1);	//couleur du pixel y+1

						//stocke les valeurs de gris des pixels à la place de la valeur rouge
						Pixel1.FromArgb((Pixel1.R+Pixel1.G+Pixel1.B)/3,0,0);
						Pixel2.FromArgb((Pixel1.R+Pixel1.G+Pixel1.B)/3,0,0);

						image_agrandie->SetPixel(x_dest,y_dest,System::Drawing::Color::FromArgb(
							 /*255- */(Pixel1.R+Pixel2.R+255)/3,
							 /*255- */(Pixel1.R+Pixel2.R+255)/3,
							 /*255- */(Pixel1.R+Pixel2.R+255)/3)
						);

					} //if (y_dest%2!=0)

					if (nProgress) 
						nProgress->valeur++;

				} //for(y_dest=0;y_dest<image_agrandie->Width;y++)

			} //if (x_dest%2==0)

			//pixel impair horizontalement:
			//	-modifié selon les pixels à l'horizontale si pair verticalement
			//	-modifié selon les (4) pixels à la diagonale) si impair verticalement
			else {

				for(y_dest=0;y_dest<image_agrandie->Height;y_dest++) {

					if (y_dest%2==0) {	//pixel portant la couleur combinée entre le pixel x-1 et x+1

						System::Drawing::Color Pixel1 = source->GetPixel(x_dest/2,y_dest/2);		//couleur du pixel x-1
						System::Drawing::Color Pixel2 = source->GetPixel((x_dest/2)+1,y_dest/2);	//couleur du pixel x+1

						//stocke les valeurs de gris des pixels à la place de la valeur rouge
						Pixel1.FromArgb((Pixel1.R+Pixel1.G+Pixel1.B)/3,0,0);
						Pixel2.FromArgb((Pixel2.R+Pixel2.G+Pixel2.B)/3,0,0);

						image_agrandie->SetPixel(x_dest,y_dest,System::Drawing::Color::FromArgb(
							 /*255- */(Pixel1.R+Pixel2.R+255)/3,
							 /*255- */(Pixel1.R+Pixel2.R+255)/3,
							 /*255- */(Pixel1.R+Pixel2.R+255)/3)
						);

					}

					else {  //pixel portant la couleur combinée entre les pixels aux angles

						System::Drawing::Color Pixel_1 = source->GetPixel(x_dest/2,y_dest/2);			//couleur du pixel x-1,y-1
						System::Drawing::Color Pixel_2 = source->GetPixel((x_dest/2)+1,y_dest/2);		//couleur du pixel x+1,y-1
						System::Drawing::Color Pixel_3 = source->GetPixel(x_dest/2,(y_dest/2)+1);		//couleur du pixel x-1,y+1
						System::Drawing::Color Pixel_4 = source->GetPixel((x_dest/2)+1,(y_dest/2)+1);	//couleur du pixel x+1,y+1

						//stocke les valeurs de gris des pixels à la place de la valeur rouge
						Pixel_1.FromArgb((Pixel_1.R+Pixel_1.G+Pixel_1.B)/3,0,0);
						Pixel_2.FromArgb((Pixel_2.R+Pixel_2.G+Pixel_2.B)/3,0,0);
						Pixel_3.FromArgb((Pixel_3.R+Pixel_3.G+Pixel_3.B)/3,0,0);
						Pixel_4.FromArgb((Pixel_4.R+Pixel_4.G+Pixel_4.B)/3,0,0);

						image_agrandie->SetPixel(	x_dest,
													y_dest,
													System::Drawing::Color::FromArgb(
														 /*255- */(Pixel_1.R+Pixel_2.R+Pixel_3.R+Pixel_4.R+255)/5,
														 /*255- */(Pixel_1.R+Pixel_2.R+Pixel_3.R+Pixel_4.R+255)/5,
														 /*255- */(Pixel_1.R+Pixel_2.R+Pixel_3.R+Pixel_4.R+255)/5
													)
												);
					} //if (y_dest%2!=0)

					if (nProgress) 
						nProgress->valeur++;

				} //for(y_dest=0;y_dest<image_agrandie->Width;y++)

			} //if (x_dest%2==1)

		} //for(x_dest=0;x_dest<image_agrandie->Width;x++)

		return image_agrandie;

	} //static System::Drawing::Bitmap^ Etire_gris(System::Drawing::Bitmap^ source,Entier_partage^ nProgress=nullptr)



	/// <summary>
	/// Algorithmes pour agrandir une image en ajoutant 1 pixel gris entre chaque pixel existant.
	/// Ajoute un pixel noir au calcul pour rendre le pixel gris plus sombre.
	/// Soit n la taille d'un côté de l'image,ce côté mesurera 2n-1 pixels après modification.
	/// </summary>
	static System::Drawing::Bitmap^ Etire_gris_sombre(System::Drawing::Bitmap^ source,Entier_partage^ nProgress=nullptr) {

		int x_dest,y_dest;

		System::Drawing::Bitmap^ image_agrandie=gcnew System::Drawing::Bitmap(2*(source->Width)-1,2*(source->Height)-1);

		if (nProgress) 
			nProgress->valeur=0;

		for(x_dest=0;x_dest<image_agrandie->Width;x_dest++) {
			
			//pixel pair horizontalement:
			//	-non modifié si pair verticalement (y_dest%2==0)
			//	-modifié selon les pixels à la verticale si impair verticalement
			if (x_dest%2==0) {

				for(y_dest=0;y_dest<image_agrandie->Height;y_dest++) {

					if (y_dest%2==0)	//positionnement du pixel d'origine

						image_agrandie->SetPixel(x_dest,y_dest,source->GetPixel(x_dest/2,y_dest/2));

					else {				//pixel portant la couleur combinée entre le pixel y-1 et y+1

						System::Drawing::Color Pixel1 = source->GetPixel(x_dest/2,y_dest/2);		//couleur du pixel y-1
						System::Drawing::Color Pixel2 = source->GetPixel(x_dest/2,(y_dest/2)+1);	//couleur du pixel y+1

						//stocke les valeurs de gris des pixels à la place de la valeur rouge
						Pixel1.FromArgb((Pixel1.R+Pixel1.G+Pixel1.B)/3,0,0);
						Pixel2.FromArgb((Pixel1.R+Pixel1.G+Pixel1.B)/3,0,0);

						image_agrandie->SetPixel(x_dest,y_dest,System::Drawing::Color::FromArgb(
							 /*255- */(Pixel1.R+Pixel2.R)/3,
							 /*255- */(Pixel1.R+Pixel2.R)/3,
							 /*255- */(Pixel1.R+Pixel2.R)/3)
						);

					} //if (y_dest%2!=0)

					if (nProgress) 
						nProgress->valeur++;

				} //for(y_dest=0;y_dest<image_agrandie->Width;y++)

			} //if (x_dest%2==0)

			//pixel impair horizontalement:
			//	-modifié selon les pixels à l'horizontale si pair verticalement
			//	-modifié selon les (4) pixels à la diagonale) si impair verticalement
			else {

				for(y_dest=0;y_dest<image_agrandie->Height;y_dest++) {

					if (y_dest%2==0) {	//pixel portant la couleur combinée entre le pixel x-1 et x+1

						System::Drawing::Color Pixel1 = source->GetPixel(x_dest/2,y_dest/2);		//couleur du pixel x-1
						System::Drawing::Color Pixel2 = source->GetPixel((x_dest/2)+1,y_dest/2);	//couleur du pixel x+1

						//stocke les valeurs de gris des pixels à la place de la valeur rouge
						Pixel1.FromArgb((Pixel1.R+Pixel1.G+Pixel1.B)/3,0,0);
						Pixel2.FromArgb((Pixel2.R+Pixel2.G+Pixel2.B)/3,0,0);

						image_agrandie->SetPixel(x_dest,y_dest,System::Drawing::Color::FromArgb(
							 /*255- */(Pixel1.R+Pixel2.R)/3,
							 /*255- */(Pixel1.R+Pixel2.R)/3,
							 /*255- */(Pixel1.R+Pixel2.R)/3)
						);

					}

					else {  //pixel portant la couleur combinée entre les pixels aux angles

						System::Drawing::Color Pixel_1 = source->GetPixel(x_dest/2,y_dest/2);			//couleur du pixel x-1,y-1
						System::Drawing::Color Pixel_2 = source->GetPixel((x_dest/2)+1,y_dest/2);		//couleur du pixel x+1,y-1
						System::Drawing::Color Pixel_3 = source->GetPixel(x_dest/2,(y_dest/2)+1);		//couleur du pixel x-1,y+1
						System::Drawing::Color Pixel_4 = source->GetPixel((x_dest/2)+1,(y_dest/2)+1);	//couleur du pixel x+1,y+1

						//stocke les valeurs de gris des pixels à la place de la valeur rouge
						Pixel_1.FromArgb((Pixel_1.R+Pixel_1.G+Pixel_1.B)/3,0,0);
						Pixel_2.FromArgb((Pixel_2.R+Pixel_2.G+Pixel_2.B)/3,0,0);
						Pixel_3.FromArgb((Pixel_3.R+Pixel_3.G+Pixel_3.B)/3,0,0);
						Pixel_4.FromArgb((Pixel_4.R+Pixel_4.G+Pixel_4.B)/3,0,0);

						image_agrandie->SetPixel(	x_dest,
													y_dest,
													System::Drawing::Color::FromArgb(
														 /*255- */(Pixel_1.R+Pixel_2.R+Pixel_3.R+Pixel_4.R)/5,
														 /*255- */(Pixel_1.R+Pixel_2.R+Pixel_3.R+Pixel_4.R)/5,
														 /*255- */(Pixel_1.R+Pixel_2.R+Pixel_3.R+Pixel_4.R)/5
													)
												);
					} //if (y_dest%2!=0)

					if (nProgress) 
						nProgress->valeur++;

				} //for(y_dest=0;y_dest<image_agrandie->Width;y++)

			} //if (x_dest%2==1)

		} //for(x_dest=0;x_dest<image_agrandie->Width;x++)

		return image_agrandie;

	} //static System::Drawing::Bitmap^ Etire_gris(System::Drawing::Bitmap^ source,Entier_partage^ nProgress=nullptr)



} //namespace ImgConvTools

#endif //#ifndef IMGCONVTOOLS_H