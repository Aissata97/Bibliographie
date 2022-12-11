/**
 * \file BibliographieTesteur.cpp
 * \brief Test unitaire de la classe Bibliographie
 * \author Aissata
 * \date 24 novembre 2022
 */

#include <gtest/gtest.h>
#include "Bibliographie.h"
#include "ContratException.h"
#include "Journal.h"
#include "Ouvrage.h"

using namespace biblio;
using namespace std;


/**
 * \test Test du constructeur par defaut de la Bibliographie
 *      Cas valide : Création d'un objet Bibliographie et verification de l'assignation de tous les attributs
 *      Cas invalide:
 *                  Nom de bibliographie vide
 *
 */
TEST (Bibliographie, ConstructeurParDefautValide)
{
  Bibliographie maBibliographie ("Bibliographie");
  ASSERT_EQ ("Bibliographie", maBibliographie.reqNomBibliographie ());
}

//Cas invalide


TEST (Bibliographie, ConstructeurNomInvalide)
{
  ASSERT_THROW (Bibliographie maBibliographie (""), PreconditionException) << "Le nom de la bibliotheque ne doit pas être vide";
}

/**
 * \brief Création d'une fixture pour tester les methodes et le constructeur par copie de Bibliographie
 */
class BibliographieValide : public::testing::Test
{

public:


  BibliographieValide () : f_bibliographie ("Bibliographie"), f_journal ("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges", 24, 6, 113)
  {
    f_bibliographie.ajouterReference (f_journal);
  };

  Bibliographie f_bibliographie;
  Journal f_journal;
} ;


/**
 * \test Test du constructeur de copie
 *      Cas valide : Un constructeur de copie valide
 *      Cas invalide : Aucun
 */

TEST_F (BibliographieValide, ConstructeurDeCopieValide)
{
  Bibliographie copieBiblio (f_bibliographie);
  ASSERT_EQ ("Bibliographie", copieBiblio.reqNomBibliographie ());
  ASSERT_EQ (f_bibliographie.reqBibliographieFormate (), copieBiblio.reqBibliographieFormate ());
}


/**
 * \test Test de la méthode reqNomBibliographie ()
 *      Cas valide : Vérifier le retour du nom de la bibliographie
 *      Cas invalide: Aucun
 */
TEST_F (BibliographieValide, reqNomBibliographie)
{
  ASSERT_EQ ("Bibliographie", f_bibliographie.reqNomBibliographie ());
}


/**
 * \test Test de la méthode reqBibliographieFormate ()
 *      Cas valide : Vérifier le retour des informations sur l'objet Bibliotheque formaté
 *      Cas invalide : Aucun
 */
TEST_F (BibliographieValide, reqBibliographieFormate)
{
  ostringstream os;
  os << "Bibliographie" << endl << "===============================" << endl;
  os << "[1] " << "Hart" << ". " <<  "A survey of source code management tools for programming courses" << "."
          << " " <<  "Journal of Computing Sciences in Colleges" << ", vol. " << 24 << ", no. " << 6 << ", pp. " << 113 << ", " << 2009 << ". " << "ISSN 1937-4771" << "." << endl;

  ASSERT_EQ (os.str (), f_bibliographie.reqBibliographieFormate ());
}


/**
 * \test Test de la methode ajouterReference()
 *      Cas valide : Verifier si la méthode ajoute une reference dans le vecteur de la bibliographie si la reference n'existe pas
 *      Cas invalide:
 *                  La reference existe déjà dans le vecteur de la reference
 */
TEST_F (BibliographieValide, ajouterReferenceNonPresente)
{
  Ouvrage monOuvrage ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3", "Springer", "New York");
  f_bibliographie.ajouterReference (monOuvrage);

  ostringstream os;
  os << "Bibliographie" << endl << "===============================" << endl;
  os << "[1] " << "Hart" << ". " <<  "A survey of source code management tools for programming courses" << "."
          << " " <<  "Journal of Computing Sciences in Colleges" << ", vol. " << 24 << ", no. " << 6 << ", pp. " << 113 << ", " << 2009 << ". " << "ISSN 1937-4771" << "." << endl;

  os << "[2] " << "Homayoon Beigi" << ". " << "Fundamentals of Speaker Recognition" << "."
          << " " << "New York" << " : " << "Springer" << ", " << 2011 << ". " << "ISBN 978-0-387-77591-3" << "." << endl;

  ASSERT_EQ (os.str (), f_bibliographie.reqBibliographieFormate ());
}

// Cas invalide


TEST_F (BibliographieValide, ajouterReferenceDejaPresente)
{

  Journal monJournal ("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges", 24, 6, 113);

  ASSERT_THROW (f_bibliographie.ajouterReference (monJournal), PreconditionException) << "La bibliographie ne peut pas ajouter une reference déjà présente dans le vecteur de reference";
}


/**
 * \test Test de la surcharge de l'opérateur d'assignation
 *      Cas valide : Verifier que l'assignation de l'objet est effectuée avec succès à l'objet auquel il est assigné
 *      Cas invalide : Aucun
 */
TEST_F (BibliographieValide, operateurAssignation)
{
  Bibliographie biblio ("Ma nouvelle bibliographie");
  Ouvrage monOuvrage ("Michelle Obama", "Devenir Michelle", 2018, "ISBN 978-0-387-77591-3", "Le livre de poche", "Paris");
  biblio.ajouterReference (monOuvrage);

  f_bibliographie = biblio;

  ostringstream os;
  os << "Ma nouvelle bibliographie" << endl << "===============================" << endl;
  os << "[1] " << "Michelle Obama" << ". " << "Devenir Michelle" << "."
          << " " << "Paris" << " : " << "Le livre de poche" << ", " << 2018 << ". " << "ISBN 978-0-387-77591-3" << "." << endl;

  ASSERT_EQ ("Ma nouvelle bibliographie", f_bibliographie.reqNomBibliographie ());
  ASSERT_EQ (os.str (), f_bibliographie.reqBibliographieFormate ());
}



