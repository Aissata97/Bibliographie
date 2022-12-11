/**
 * \file validationFormat.cpp
 * \brief Contient les fonctions de validation
 * \author Aissata
 * \date 12 octobre 2022
 */
#include <string>
#include<cctype>
#include<algorithm>
#include <vector>
#include <regex>
#include "validationFormat.h"
using namespace std;

/**
 * \namespace util
 * \brief Namespace contenant les fonctions de validation
 */
namespace util
{
  //Mes fonctions utilitaires
  char calculCleDeControleISSN (const string& groupeChiffreIssn);
  vector<string>splitIntoArray (const string& str, const char& separateur);
  int calculCleDeControleISBN (const string& chiffresDansIsbn);


  /**
   * \brief Méthode permettant de valider le nom
   * \param p_nom, le nom
   * \return un boolean, True si le code est dans le bon format et False si le format n'est pas correcte
   */
  bool
  validerFormatNom (const string& p_nom)
  {
    bool validation = true;
    int longeurNom = p_nom.length ();

    if (longeurNom <= 1)
      {
        validation = false;
      }

    // Si il y'a de l'espace au debut ou à la fin
    if (p_nom[0] == ' ' || p_nom[longeurNom - 1] == ' ')
      {
        validation = false;
      }

    for (int i = 0; i < longeurNom; i++)
      {
        //À partir de deux espaces ou deux - consécutifs
        if ( (p_nom[i] == ' '  && p_nom[i + 1] == ' ') || (p_nom[i] == '-'  && p_nom[i + 1] == '-') || (p_nom[i] == '-'  && p_nom[i + 1] == ' ') || ((p_nom[i] == ' '  && p_nom[i + 1] == '-')))
          {
            validation = false;
          }

        //Si il y'a des caractères spéciaux
        if ( (p_nom[i] != ' ') && (p_nom[i] != '-'))
          {
            if (!isalpha (p_nom[i]))
              {
                validation = false;
              }
          }
      }
    return validation;
  }


  /**
   * \brief Méthode permettant de valider le code ISSN
   * \param p_issn, code ISSN
   * \return un boolean, True si le code est dans le bon format et False si le format n'est pas correcte
   */
  bool
  validerCodeIssn (const string& p_issn)
  {
    const int longeurIssn = p_issn.length ();
    const int TAILLE_MAX = 14;


    bool validation = true;


    //Verifier si le nombre de caractère max est verifié
    if (longeurIssn != TAILLE_MAX)
      {
        validation = false;
      }
    else
      {
        string premierGroupeIssn = p_issn.substr (0, p_issn.find (" "));
        string deuxiemeGroupeIssn = p_issn.substr (5, 4);
        string troisiemeGroupeIssn = p_issn.substr (10, 3);
        string septDernierChiffreISSN = deuxiemeGroupeIssn + troisiemeGroupeIssn;

        char huitiemeChiffreISSN = p_issn[13]; //Le check digit
        char delimiterEspace = p_issn[4];
        char delimiterTiret = p_issn[9];

        if ((delimiterEspace != ' ') || (delimiterTiret != '-'))
          {
            validation = false;
          }
        else if (premierGroupeIssn != "ISSN") //Validation du premier groupe
          {
            validation = false;
          }
        else
          {
            //Verifier si tous les caractères sont des chiffres
            if (!validerNombre (septDernierChiffreISSN))
              {
                validation = false;
              }
            else
              {
                //Valider la valeur du dernier chiffre
                if (calculCleDeControleISSN (septDernierChiffreISSN) == huitiemeChiffreISSN)
                  {
                    validation = true;
                  }
                else if (calculCleDeControleISSN (septDernierChiffreISSN) != huitiemeChiffreISSN )
                  {
                    validation = false;
                  }
              }
          }
      }

    return validation;
  }


  /**
   * \brief Méthode permettant de valider le code ISBN
   * \param p_isbn, code ISBN
   * \return un boolean, True si le code est dans le bon format et False si le format n'est pas correcte
   */
  bool
  validerCodeIsbn (const string& p_isbn)
  {
    bool validation;



    if (p_isbn.length () != 22)
      {
        validation = false;
      }
    else
      {
        string chiffresIsbnTemp =  p_isbn.substr (5, 17); //Chaine coupé après le prefixe
        vector<string> chiffresIsbnIntoArray =  splitIntoArray (chiffresIsbnTemp, '-'); //convertir les chiffres en array
        string prefixe = chiffresIsbnIntoArray[0];
        string sigleIsbn = p_isbn.substr (0, 5);
        int domaine = stoi (chiffresIsbnIntoArray[1]);
        int numEditeur = stoi (chiffresIsbnIntoArray[2]);


        //Couper la chaine de caractère pour avoir seulement les chiffres du isbn
        string chiffresDansIsbn = p_isbn.substr (5, 17);
        chiffresDansIsbn.erase (remove (chiffresDansIsbn.begin (), chiffresDansIsbn.end (), '-'), chiffresDansIsbn.end ());
        int chiffreDeControle = chiffresDansIsbn[12] - '0';
        //Nombre de - dans la chaine après le préfixe
        string::difference_type nbTiret = count (chiffresIsbnTemp.begin (), chiffresIsbnTemp.end (), '-');

        if (sigleIsbn != "ISBN ")
          {
            validation = false;
          }
        else if (((prefixe != "978") && (prefixe != "979")))
          {
            validation = false;
          }
        else if ((chiffresDansIsbn.length () != 13))
          {
            validation = false;
          }
        else if ((nbTiret !=  4))
          {
            validation = false;
          }
        else if (calculCleDeControleISBN (chiffresDansIsbn) != chiffreDeControle)
          {
            validation = false;
          }
        else if ((domaine >= 0 && domaine <= 5) || (domaine == 7) || (domaine >= 600 && domaine <= 649) || (domaine >= 80 &&              domaine <= 94) || (domaine >= 950 && domaine <= 989) || (domaine >= 9900 && domaine <= 9989) || (domaine >= 99900 &&            domaine <= 99999))
          {

            //validation = false;
            if ((numEditeur >= 0 && numEditeur <= 19) || (numEditeur >= 200 && numEditeur <= 699) || (numEditeur  >= 7000 &&                  numEditeur <= 8499) || (numEditeur <= 85000 && numEditeur <= 89999) || (numEditeur <= 900000 >= 949999) || (numEditeur <= 9500000 && numEditeur >= 9999999))
              {
                validation = true;
              }
            else
              {
                validation = false;
              }

          }

      }
    return validation;
  }

  ///////////////////////////////////////Mes fonctions utilitaires////////////////////////


  /**
   * \brief Méthode permettant de calculer le 8ème chiffre (check digit) du code ISSN
   * \param groupeChiffreIssn, les 7 premiers chiffres du ISSN
   * \return le 8ème chiffre (check digit)
   */
  char
  calculCleDeControleISSN (const string& septDernierChiffreISSN)
  {
    int cptPonderation = 8;
    int ponderation = 0;  //pour calcul du 8ème chiffre
    char checkDigit;   //le 8ème chiffre
    const int TAILLE_DIGIT_GROUPE = 7; //Les 7 premier chiffres du ISSN


    //Calcul du 8ème chiffre du code ISSN
    for (int i = 0; i < TAILLE_DIGIT_GROUPE; i++)
      {
        ponderation += (septDernierChiffreISSN[i] - '0') * cptPonderation;
        cptPonderation--;
      }

    if ((ponderation % 11) == 0)
      {
        checkDigit = '0';
      }
    else if ((ponderation % 11) == 1)
      {
        checkDigit = 'X';
      }
    else
      {
        int resultat = 11 - (ponderation % 11);
        checkDigit = resultat + '0';
      }
    return checkDigit;
  }


  /**
   * \brief Méthode permettant de valider les chiffres
   * \param groupeChiffre, donnée entrée par l'utilisateur à verifier
   * \return boolean, true si ce sont tous des chiffres, false si non
   */
  bool
  validerNombre (const string& groupeChiffre)
  {
    return regex_match (groupeChiffre, regex ("^[0-9]*$"));
  }


  /**
   * \brief Méthode permettant de convertir le string en array
   * \param str, la chaine de caractère qui va être convertit en array
   * \param separateur, le separateur entre les chiffres
   * \return le string convertit en array
   */
  vector<string>
  splitIntoArray (const string& str, const char& separateur)
  {
    string next;
    vector<string> result;

    for (string::const_iterator it = str.begin (); it != str.end (); it++)
      {
        if (*it == separateur)
          {
            if (!next.empty ())
              {
                result.push_back (next);
                next.clear ();
              }
          }
        else
          {
            next += *it;
          }
      }


    if (!next.empty ())
      result.push_back (next);
    return result;
  }


  /**
   * \brief Méthode permettant de calculer le chiffre de controle du ISBN
   * \param chiffresDansIsbn, les chiffres dans le ISBN
   * \return le chiffre de controle du ISBN
   */
  int
  calculCleDeControleISBN (const string& chiffresDansIsbn)
  {
    int chiffreDeControle = 0;
    int sommeProduitPondere = 0;

    ////Somme des produits pondéré sur les 12 premiers chiffres
    for (int i = 0; i < 11; i += 2)
      {
        sommeProduitPondere += (chiffresDansIsbn[i] - '0') * 1;
      }

    for (int i = 1; i < 12; i += 2)
      {
        sommeProduitPondere += (chiffresDansIsbn[i] - '0') * 3;
      }

    if ((sommeProduitPondere % 10) == 0 )
      {
        chiffreDeControle = 0;
      }
    else
      {
        chiffreDeControle = 10 - (sommeProduitPondere % 10);
      }


    return chiffreDeControle;
  }

}

