/*
 * \file gestionBibliographie.cpp
 * \brief Programme de test de la bibliographie
 * \author Aissata
 * \date 25 novembre 2022
 */

#include <iostream>
#include "Bibliographie.h"
#include "validationFormat.h"
#include "Ouvrage.h"
#include "Journal.h"

using namespace std;
using namespace biblio;
using namespace util;


/*
 *
 */
int
main (int argc, char** argv)
{

  //Création de l'objet Bibliographie
  Bibliographie maBibliographie ("Bibliographie");

  cout << "Bienvenue dans l'outil de gestion de references bibliographiques" << endl;
  cout << "================================================================" << endl;
  cout << "----------------------------------------------------------------" << endl;
  cout << "-                Ajoutez un ouvrage                            -" << endl;
  cout << "----------------------------------------------------------------" << endl;

  //Saisie et validation du nom du ou des auteurs
  string auteurOuvrage;
  char bufferAuteurOuvrage[256];
  cout << "Entrez le nom du ou des auteurs :" << endl;
  cin.getline (bufferAuteurOuvrage, 256);
  auteurOuvrage = bufferAuteurOuvrage;

  while (!validerFormatNom (auteurOuvrage))
    {
      cout << "Le nom du ou des auteurs n'est pas valide, recommencez" << endl;
      cin.getline (bufferAuteurOuvrage, 256);
      auteurOuvrage = bufferAuteurOuvrage;
    }

  //Saisie et Validation du titre de l'ouvrage
  string titreOuvrage;
  char bufferTitreOuvrage[256];
  cout << "Entrez le titre : " << endl;
  cin.getline (bufferTitreOuvrage, 256);
  titreOuvrage = bufferTitreOuvrage;

  while (titreOuvrage.empty ())
    {
      cout << "Le titre ne peut pas être vide, recommencez " << endl;
      cin.getline (bufferTitreOuvrage, 256);
      titreOuvrage = bufferTitreOuvrage;
    }

  //Saisie et validation de la ville d'édition
  string villeOuvrage;
  char bufferVilleOuvrage[256];
  cout << "Entrez la ville d’édition :" << endl;
  cin.getline (bufferVilleOuvrage, 256);
  villeOuvrage = bufferVilleOuvrage;

  while (!validerFormatNom (villeOuvrage))
    {
      cout << "La ville d'edition n'est pas valide , recommencez " << endl;
      cin.getline (bufferVilleOuvrage, 256);
      villeOuvrage = bufferVilleOuvrage;
    }

  //Saisie et Validation du nom d'éditeur de l'Ouvrage
  string editeurOuvrage;
  char bufferEditeurOuvrage[256];
  cout << "Entrez l'éditeur : " << endl;
  cin.getline (bufferEditeurOuvrage, 256);
  editeurOuvrage = bufferEditeurOuvrage;

  while (!validerFormatNom (editeurOuvrage))
    {
      cout << "Le nom d'Éditeur n'est pas valide, recommencez " << endl;
      cin.getline (bufferEditeurOuvrage, 256);
      editeurOuvrage = bufferEditeurOuvrage;
    }

  //Saisie et validation de l'année d'édition de l'ouvrage
  char bufferAnneeEditionOuvrage[100];
  bool validationSaisieAnnneeOuvrage;
  int anneeEditionOuvrage = 0;

  cout << "Entrez l'année d'édition : " << endl;
  cin.getline (bufferAnneeEditionOuvrage, 100);

  //Verifier si l'utilisateur a saisi un chiffre avant de convertir en int
  if (validerNombre (bufferAnneeEditionOuvrage))
    {
      anneeEditionOuvrage = stoi (bufferAnneeEditionOuvrage);
    }
  validationSaisieAnnneeOuvrage = validerNombre (bufferAnneeEditionOuvrage) && (anneeEditionOuvrage > 0);

  while (!validationSaisieAnnneeOuvrage)
    {
      cout << "L'année d'édition doit être strictement plus grande que 0. Recommencez" << endl;
      cin.getline (bufferAnneeEditionOuvrage, 100);
      if (validerNombre (bufferAnneeEditionOuvrage))
        {
          anneeEditionOuvrage = stoi (bufferAnneeEditionOuvrage);
        }
      validationSaisieAnnneeOuvrage = validerNombre (bufferAnneeEditionOuvrage) && (anneeEditionOuvrage > 0);
    }

  //Saisie et Validation de l'identifiant de l'Ouvrage (Code ISBN)
  string identifiantOuvrage;
  char bufferIdentifiantOuvrage[256];
  cout << "Entrez le code ISBN : " << endl;
  cin.getline (bufferIdentifiantOuvrage, 256);
  identifiantOuvrage = bufferIdentifiantOuvrage;

  while (!validerCodeIsbn (identifiantOuvrage))
    {
      cout << "Le code ISBN n'est pas valide. Recommencez " << endl;
      cin.getline (bufferIdentifiantOuvrage, 256);
      identifiantOuvrage = bufferIdentifiantOuvrage;
    }

  cout << "-------------------------------------------------------" << endl;
  cout << "-  Ajoutez une référence de type article de journal   -" << endl;
  cout << "-------------------------------------------------------" << endl;

  //Saisie et Validation du nom de l'auteur d'un Journal
  string auteurJournal;
  char bufferAuteurJournal[256];
  cout << "Entrez le nom du ou des auteurs :" << endl;
  cin.getline (bufferAuteurJournal, 256);
  auteurJournal = bufferAuteurJournal;

  while (!validerFormatNom (auteurJournal))
    {
      cout << "Le nom du ou des auteurs n'est pas valide, recommencez  " << endl;
      cin.getline (bufferAuteurJournal, 256);
      auteurJournal = bufferAuteurJournal;
    }

  //Saisie et Validation du titre de Journal
  string titreJournal;
  char bufferTitreJournal[256];
  cout << "Entrez le titre : " << endl;
  cin.getline (bufferTitreJournal, 256);
  titreJournal = bufferTitreJournal;

  while (titreJournal.empty ())
    {
      cout << "Le titre du journal ne peut pas être vide, Recommencez " << endl;
      cin.getline (bufferTitreJournal, 256);
      titreJournal = bufferTitreJournal;
    }

  //Saisie et Validation du titre de Journal
  string nomJournal;
  char bufferNomJournal[256];
  cout << "Entrez le nom de la revue dans laquelle a été publiée la référence :" << endl;
  cin.getline (bufferNomJournal, 256);
  nomJournal = bufferNomJournal;

  while (nomJournal.empty ())
    {
      cout << "Le nom de la revue ne peut pas être vide, Recommencez " << endl;
      cin.getline (bufferNomJournal, 256);
      nomJournal = bufferNomJournal;
    }


  //Saisie et validation du volume du journal
  char bufferVolumeJournal[100];
  bool validationSaisieVolumeJournal;
  int volumeJournal = 0;

  cout << "Entrez le volume : " << endl;
  cin.getline (bufferVolumeJournal, 100);
  //Verifier si l'utilisateur a saisi un chiffre avant de convertir en int
  if (validerNombre (bufferVolumeJournal))
    {
      volumeJournal = stoi (bufferVolumeJournal);
    }
  validationSaisieVolumeJournal = validerNombre (bufferVolumeJournal) && (volumeJournal > 0);

  while (!validationSaisieVolumeJournal)
    {
      cout << "Le volume doit être strictement plus grand que 0. Recommencez" << endl;
      cin.getline (bufferVolumeJournal, 100);
      if (validerNombre (bufferVolumeJournal))
        {
          volumeJournal = stoi (bufferVolumeJournal);
        }
      validationSaisieVolumeJournal = validerNombre (bufferVolumeJournal) && (volumeJournal > 0);
    }

  //Saisie et validation du numero du Journal
  char bufferNumeroJournal[100];
  bool validationSaisieNumeroJournal;
  int numeroJournal = 0;

  cout << "Entrez le numero :" << endl;
  cin.getline (bufferNumeroJournal, 100);
  //On verifie d'abord si l'utilisateur a entrée des chiffres avant de faire la conversion
  if (validerNombre (bufferNumeroJournal))
    {
      numeroJournal = stoi (bufferNumeroJournal);
    }
  validationSaisieNumeroJournal = validerNombre (bufferNumeroJournal) && (numeroJournal > 0);

  while (!validationSaisieNumeroJournal)
    {
      cout << "Le numero doit être strictement plus grand que 0." << endl;
      cin.getline (bufferNumeroJournal, 100);
      if (validerNombre (bufferNumeroJournal))
        {
          numeroJournal = stoi (bufferNumeroJournal);
        }
      validationSaisieNumeroJournal = validerNombre (bufferNumeroJournal) && (numeroJournal > 0);
    }


  //Saisie et validation de la page du Journal
  char bufferPageJournal[100];
  bool validationSaisiePageJournal;
  int pageJournal = 0;

  cout << "Entrez la page où commence la référence :" << endl;
  cin.getline (bufferPageJournal, 100);
  //Verifier si l'utilisateur a saisi un chiffre avant de convertir en int
  if (validerNombre (bufferPageJournal))
    {
      pageJournal = stoi (bufferPageJournal);
    }
  validationSaisiePageJournal = validerNombre (bufferPageJournal) && (pageJournal > 0);

  while (!validationSaisiePageJournal)
    {
      cout << "Le page doit être strictement plus grande que 0. Recommencez" << endl;
      cin.getline (bufferPageJournal, 100);
      if (validerNombre (bufferPageJournal))
        {
          pageJournal = stoi (bufferPageJournal);
        }
      validationSaisiePageJournal = validerNombre (bufferPageJournal) && (pageJournal > 0);
    }

  //Saisie et validation de l'année d'édition du Journal
  char bufferAnneeEditionJournal[100];
  bool validationSaisieAnnneeJournal;
  int anneeEditionJournal = 0;

  cout << "Entrez l'année :" << endl;
  cin.getline (bufferAnneeEditionJournal, 100);
  //Verifier si l'utilisateur a saisi un chiffre avant de convertir en int
  if (validerNombre (bufferAnneeEditionJournal))
    {
      anneeEditionJournal = stoi (bufferAnneeEditionJournal);
    }
  validationSaisieAnnneeJournal = validerNombre (bufferAnneeEditionJournal) && (anneeEditionJournal > 0);

  while (!validationSaisieAnnneeJournal)
    {
      cout << "L'année d'édition n'est pas valide, Recommencez" << endl;
      cin.getline (bufferAnneeEditionJournal, 100);
      //Verifier si l'utilisateur a saisi un chiffre avant de convertir en int
      if (validerNombre (bufferAnneeEditionJournal))
        {
          anneeEditionJournal = stoi (bufferAnneeEditionJournal);
        }
      validationSaisieAnnneeJournal = validerNombre (bufferAnneeEditionJournal) && (anneeEditionJournal > 0);
    }

  //Saisie et Validation de l'identifiant (Code ISSN) du Journal
  string identifiantJournal;
  char bufferIdentifiantJournal[256];

  cout << "Entrez le code ISSN : " << endl;
  cin.getline (bufferIdentifiantJournal, 256);
  identifiantJournal = bufferIdentifiantJournal;

  while (!validerCodeIssn (identifiantJournal))
    {
      cout << "Le code ISSN n'est pas valide. Recommencez " << endl;
      cin.getline (bufferIdentifiantJournal, 256);
      identifiantJournal = bufferIdentifiantJournal;
    }

  //Création des objets Ouvrage et Journal
  Ouvrage unOuvrage (auteurOuvrage, titreOuvrage, anneeEditionOuvrage, identifiantOuvrage, editeurOuvrage, villeOuvrage);
  Journal unJournal (auteurJournal, titreJournal, anneeEditionJournal, identifiantJournal, nomJournal, volumeJournal, numeroJournal, pageJournal);

  //Ajout des references crées dans la bibliographie
  maBibliographie.ajouterReference (unOuvrage);
  maBibliographie.ajouterReference (unJournal);

  //Affichage des references crées
  cout << endl << "Références bibliographiques enregistrées :" << endl;
  cout << maBibliographie.reqBibliographieFormate () <<  endl;

  return 0;
}

