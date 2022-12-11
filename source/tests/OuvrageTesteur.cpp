/**
 * \file OuvrageTesteur.cpp
 * \brief Test unitaire de la classe Ouvrage
 * \author Aissata
 * \date 23 novembre 2022
 */

#include <gtest/gtest.h>
#include "Ouvrage.h"
#include "ContratException.h"

using namespace biblio;


/**
 * \test Test du constructeur avec paramètre de Ouvrage
 *      Cas valide : Création d'un objet Ouvrage et verification de l'assignation de tous les attributs
 *      Cas invalide :
 *                  Identifiant ne respecte pas le format valide d'un ISBN
 *                  Editeur ne respecte pas le format tel que determiné par validerFormatNom
 *                  Ville  ne respecte pas le format tel que determiné par validerFormatNom
 *
 */
TEST (Ouvrage, ConstructeurParDefaut)
{
  Ouvrage monOuvrage ("Michelle Obama", "Devenir Michelle", 2018, "ISBN 978-0-387-77591-3", "Le livre de poche", "Paris");

  ASSERT_EQ ("Michelle Obama", monOuvrage.reqAuteurs ());
  ASSERT_EQ ("Devenir Michelle", monOuvrage.reqTitre ());
  ASSERT_EQ (2018, monOuvrage.reqAnnee ());
  ASSERT_EQ ("ISBN 978-0-387-77591-3", monOuvrage.reqIdentifiant ());
  ASSERT_EQ ("Le livre de poche", monOuvrage.reqEditeur ());
  ASSERT_EQ ("Paris", monOuvrage.reqVille ());
}

//Cas invalide


TEST (Ouvrage, ConstructeurIdenfiantInvalide)
{
  ASSERT_THROW (Ouvrage monOuvrage ("Michelle Obama", "Devenir Michelle", 2018, "ISBN 978-0-33", "Le livre de poche", "Paris"), PreconditionException) << "L'ouvrage n'accepte pas un identifiant ne correspondant pas à un ISBN valide";
}


TEST (Ouvrage, ConstructeurEditeurInvalide)
{
  ASSERT_THROW (Ouvrage monOuvrage ("Michelle Obama", "Devenir Michelle", 2018, "ISBN 978-0-387-77591-3", "", "Paris"), PreconditionException) << "Le nom de l'editeur doit être dans un format valide ";
}


TEST (Ouvrage, ConstructeurVilleInvalide)
{
  ASSERT_THROW (Ouvrage monOuvrage ("Michelle Obama", "Devenir Michelle", 2018, "ISBN 978-0-387-77591-3", "Le livre de poche", "Pas1.!is"), PreconditionException) << "La ville doit être dans un format valide";
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test de Ouvrage
 */
class OuvrageValide : public::testing::Test
{

public:


  OuvrageValide () : f_ouvrage ("Michelle Obama", "Devenir Michelle", 2018, "ISBN 978-0-387-77591-3", "Le livre de poche", "Paris") { }
  Ouvrage f_ouvrage;

} ;


/**
 * \test Test de la méthode reqEditeur()
 *      Cas valide : Vérifier le retour du nom de l'auteur
 *      Cas invalide: aucun
 */
TEST_F (OuvrageValide, reqEditeur)
{
  ASSERT_EQ ("Le livre de poche", f_ouvrage.reqEditeur ());
}


/**
 * \test Test de la méthode reqVille()
 *      Cas valide : Vérifier le retour de la ville
 *      Cas invalide : Aucun
 */
TEST_F (OuvrageValide, reqVille)
{
  ASSERT_EQ ("Paris", f_ouvrage.reqVille ());
}


/**
 * \test Test de la méthode reqReferenceFormate()
 *      Cas valide : Vérifier le retour des informations sur l'objet Ouvrage formaté
 *      Cas invalide : Invalide
 */
TEST_F (OuvrageValide, reqReferenceFormate)
{
  std::ostringstream os;
  os << f_ouvrage.reqAuteurs () << ". " << f_ouvrage.reqTitre () << "."
          << " " << f_ouvrage.reqVille () << " : " << f_ouvrage.reqEditeur () << ", " << f_ouvrage.reqAnnee () << ". " << f_ouvrage.reqIdentifiant () << ".";

  ASSERT_EQ (os.str (), f_ouvrage.reqReferenceFormate ());
}


/**
 * \test Test de la méthode clone
 *      Cas valide : Verifier que l'objet est identique à l'ouvrage f_ouvrage
 *      Cas invalide: Aucun
 */
TEST_F (OuvrageValide, cloneValide)
{
  Reference* clone = f_ouvrage.clone ();
  ASSERT_EQ (f_ouvrage.reqAuteurs (), clone->reqAuteurs ());
  ASSERT_EQ (f_ouvrage.reqTitre (), clone->reqTitre ());
  ASSERT_EQ (f_ouvrage.reqAnnee (), clone->reqAnnee ());
  ASSERT_EQ (f_ouvrage.reqIdentifiant (), clone->reqIdentifiant ());
  ASSERT_EQ (f_ouvrage.reqReferenceFormate (), clone->reqReferenceFormate ());

  delete clone;
}