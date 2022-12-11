/**
 * \file ReferenceTesteur.cpp
 * \brief Test unitaire de la classe Reference
 * \author Aissata
 * \date 17 novembre 2022
 */

#include <gtest/gtest.h>
#include "Reference.h"
#include "ContratException.h"

using namespace std;
using namespace biblio;

/**
 * \class ReferenceDeTest
 * \brief Classe de test permettant de tester la classe abstraite Reference
 */
class ReferenceDeTest : public Reference
{

public:


  ReferenceDeTest (const string& p_auteurs, const string& p_titre, int p_annee, const string& p_identifiant) : Reference (p_auteurs, p_titre, p_annee, p_identifiant) { }


  virtual ReferenceDeTest*
  clone () const
  {
    return ReferenceDeTest::clone ();
  }

} ;


/**
 *
 * \test Test du constructeur par defaut de Reference
 *      Cas valides: Création d'un objet Reference et vérification de l'assignation de tous les attributs
 *      Cas invalides:
 *                Auteurs qui respecte pas le format invalide tel que determiné par la fonction validerFormatNom
 *                Titre vide
 *                Annee <= 0
 *                Identifiant ISSN ou ISBN invalide
 */

TEST (Reference, ConstructeurParDefaut)
{
  ReferenceDeTest maReference ("Homayoon Beigi", "Fundamentals of Speaker Recognition", 2011, "ISBN 978-0-387-77591-3");

  ASSERT_EQ ("Homayoon Beigi", maReference.reqAuteurs ());
  ASSERT_EQ ("Fundamentals of Speaker Recognition", maReference.reqTitre ());
  ASSERT_EQ (2011, maReference.reqAnnee ());
  ASSERT_EQ ("ISBN 978-0-387-77591-3", maReference.reqIdentifiant ());
}

//Cas invalide


TEST (Reference, ConstructeurAuteursInvalide)
{
  ASSERT_THROW (ReferenceDeTest maReference ("1", "Devenir Michelle", 2018, "ISBN 978-0-387-77591-3"), PreconditionException) << "Le nom de l'auteur doit être dans un format valide, sans caractères spéciaux";
}


TEST (Reference, ConstructeurTitreInvalide)
{
  ASSERT_THROW (ReferenceDeTest maReference ("Michelle", "", 2018, "ISBN 978-0-387-77591-3"), PreconditionException) << "Le titre de la reference ne peut pas être vide";
}


TEST (Reference, ConstructeurAnneeInvalide)
{
  ASSERT_THROW (ReferenceDeTest maReference ("Michelle", "Devenir Michelle", -1, "ISBN 978-0-387-77591-3"), PreconditionException) << "La reference n'accepte pas une année inférieur ou égale à 0";
}


TEST (Reference, ConstructeurIdentifiantInvalide)
{
  ASSERT_THROW (ReferenceDeTest maReference ("Michelle", "Devenir Michelle", 2018, "ISBN 000-0-000-0000-0"), PreconditionException) << "L'identifiant doit être dans un format valide de ISSN ou ISBN";
}

/**
 * \brief Creation d’une fixture à utiliser pour les méthodes publiques de la classe de test
 */
class ReferenceValide : public::testing::Test
{

public:


  ReferenceValide () : f_reference ("Michelle", "Devenir Michelle", 2018, "ISBN 978-0-387-77591-3") { }
  ReferenceDeTest f_reference;

} ;


/**
 * \test Test de la méthode reqAuteurs()
 *      Cas valide: vérifier le retour du nom de l'auteur
 *      Cas invalide: aucun
 */
TEST_F (ReferenceValide, reqAuteurs)
{
  ASSERT_EQ ("Michelle", f_reference.reqAuteurs ());
}


/**
 * \test Test de la méthode reqTitre()
 *      Cas valide: vérifier le retour du titre de la reference
 *      Cas invalide: aucun
 */
TEST_F (ReferenceValide, reqTitre)
{
  ASSERT_EQ ("Devenir Michelle", f_reference.reqTitre ());
}


/**
 * \test Test de la méthode reqAnnee()
 *      Cas valide: vérifier le retour de l'année de la reference
 *      Cas invalide: aucun
 */
TEST_F (ReferenceValide, reqAnnee)
{
  ASSERT_EQ (2018, f_reference.reqAnnee ());
}


/**
 * \test Test de la méthode reqIdentifiant()
 *      Cas valide: vérifier le retour de l'identifiant de la reference
 *      Cas invalide: aucun
 */
TEST_F (ReferenceValide, reqIdentifiant)
{
  ASSERT_EQ ("ISBN 978-0-387-77591-3", f_reference.reqIdentifiant ());
}


/**
 * \test Test de la méthode asgAnnee()
 *      Cas valide: Assigner une nouvelle valeur à l'année
 *      Cas invalide: Assigner à l'année une valeur inférieur ou égale à 0
 */
TEST_F (ReferenceValide, asgAnneeValide)
{
  f_reference.asgAnnee (2020);
}


//Cas invalide


TEST_F (ReferenceValide, asgAnneeInvalide)
{
  ASSERT_THROW (f_reference.asgAnnee (-1), PreconditionException) << "On ne peut pas modifier l'année avec une valeur inférieur ou égale à 0";
}


/**
 * \test Test de la méthode reqReferenceFormate()
 *      Cas valide: vérifier le retour des informations sur l’objet Reference formaté
 *      Cas invalide : aucun
 */
TEST_F (ReferenceValide, reqReferenceFormate)
{
  std::ostringstream os;
  os << f_reference.reqAuteurs () << ". " << f_reference.reqTitre () << "." ;
  ASSERT_EQ (os.str (), f_reference.reqReferenceFormate ());
}


/**
 * \test Test de l'opérateur de comparaison d’égalité operator== (const Reference& p_reference)
 *      Cas valide: Retoune True si les objets sont egaux et False si les objets ne sont pas égaux
 *      Cas invalide: aucun
 */
TEST (Reference, OperateurEgalEgalValide)
{
  ReferenceDeTest premiereReference ("Michelle", "Devenir Michelle", 2018, "ISBN 978-0-387-77591-3");
  ReferenceDeTest deuxiemeReference ("Michelle", "Devenir Michelle", 2018, "ISBN 978-0-387-77591-3");

  ASSERT_EQ (true, premiereReference.operator == (deuxiemeReference));
}







