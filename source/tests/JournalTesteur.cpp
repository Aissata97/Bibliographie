/**
 * \file JournalTesteur.cpp
 * \brief Test unitaire de la classe Journal
 * \author Aissata
 * \date 23 novembre 2022
 */

#include <gtest/gtest.h>
#include "Journal.h"
#include "ContratException.h"


using namespace biblio;


/**
 * \test Test du constructeur avec paramètre de la classe Journal
 *      Cas valide : Création d'un objet Journal et vérification de l'assignation de tous les attributs
 *      Cas invalides:
 *                  Nom vide
 *                  Volume <= 0
 *                  Numero <= 0
 *                  Page <= 0
 */
TEST (Journal, ConstructeurParDefaut)
{
  Journal monJournal ("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges", 24, 6, 113);

  ASSERT_EQ ("Hart", monJournal.reqAuteurs ());
  ASSERT_EQ ("A survey of source code management tools for programming courses", monJournal.reqTitre ());
  ASSERT_EQ (2009, monJournal.reqAnnee ());
  ASSERT_EQ ("ISSN 1937-4771", monJournal.reqIdentifiant ());
  ASSERT_EQ ("Journal of Computing Sciences in Colleges", monJournal.reqNom ());
  ASSERT_EQ (24, monJournal.reqVolume ());
  ASSERT_EQ (6, monJournal.reqNumero ());
  ASSERT_EQ (113, monJournal.reqPage ());
}

//Cas invalides


TEST (Journal, ConstructeurNomInvalide)
{
  ASSERT_THROW (Journal monJournal ("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", "", 24, 6, 113), PreconditionException) << "La classe Journal n'accepte pas un nom de journal vide ";
}


TEST (Journal, ConstructeurVolumeInvalide)
{
  ASSERT_THROW (Journal monJournal ("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges", -1, 6, 113), PreconditionException) << "La classe Journal n'accepte pas un volume négatif.";
}


TEST (Journal, ConstructeurNumeroInvalide)
{
  ASSERT_THROW (Journal monJournal ("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges", 24, -1, 113), PreconditionException) << "La classe Journal n'accepte pas un numéro négatif.";
}


TEST (Journal, ConstructeurPageInvalide)
{
  ASSERT_THROW (Journal monJournal ("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges", 24, 6, -113), PreconditionException) << "La classe Journal n'accepte pas un numéro de page négatif.";
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes publiques de la classe de test de Journal
 */
class JournalValide : public::testing::Test
{

public:


  JournalValide () : f_journal ("Hart", "A survey of source code management tools for programming courses", 2009, "ISSN 1937-4771", "Journal of Computing Sciences in Colleges", 24, 6, 113) { }
  Journal f_journal;

} ;


/**
 * \test Test de la méthode reqNom()
 *      Cas valide : Vérifier le retour du nom
 *      Cas invalide : Aucun
 */
TEST_F (JournalValide, reqNom)
{
  ASSERT_EQ ("Journal of Computing Sciences in Colleges", f_journal.reqNom ());
}


/**
 * \test Test de la méthode reqVolume()
 *      Cas valide : Vérifier le retour du volume
 *      Cas invalide : Aucun
 */
TEST_F (JournalValide, reqVolume)
{
  ASSERT_EQ (24, f_journal.reqVolume ());
}


/**
 * \test Test de la méthode reqNumero()
 *      Cas valide : Vérifier le retour du numero
 *      Cas invalide : Aucun
 */
TEST_F (JournalValide, reqNumero)
{
  ASSERT_EQ (6, f_journal.reqNumero ());
}


/**
 * \test Test de la méthode reqPage()
 *      Cas valide : Verifier le retour de la page
 *      Cas invalide: Aucun
 */
TEST_F (JournalValide, reqPage)
{
  ASSERT_EQ (113, f_journal.reqPage ());
}


/**
 * \test Test de la méthode reqReferenceFormate()
 *      Cas valide : Vérifier le retour des informations sur l'objet Journal formaté
 *      Cas invalide : Aucun
 */
TEST_F (JournalValide, reqReferenceFormate)
{
  std::ostringstream os;
  os << f_journal.reqAuteurs () << ". " << f_journal.reqTitre () << "."
          << " " << f_journal.reqNom () << ", vol. " << f_journal.reqVolume () << ", no. " << f_journal.reqNumero () << ", pp. " << f_journal.reqPage () << ", " << f_journal.reqAnnee () << ". " << f_journal.reqIdentifiant () << ".";

  ASSERT_EQ (os.str (), f_journal.reqReferenceFormate ());
}


/**
 * \test Test de la méthode clone()
 *      Cas valide : Verifier que l'objet clone est identique au journal
 *      Cas invalide : Aucun
 */
TEST_F (JournalValide, cloneValide)
{
  Reference* clone = f_journal.clone ();
  ASSERT_EQ (f_journal.reqAuteurs (), clone->reqAuteurs ());
  ASSERT_EQ (f_journal.reqTitre (), clone->reqTitre ());
  ASSERT_EQ (f_journal.reqAnnee (), clone->reqAnnee ());
  ASSERT_EQ (f_journal.reqIdentifiant (), clone->reqIdentifiant ());
  ASSERT_EQ (f_journal.reqReferenceFormate (), clone->reqReferenceFormate ());

  delete clone;
}