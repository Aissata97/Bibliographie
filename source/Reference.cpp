/**
 * \file Reference.cpp
 * \brief Implementation de la classe Reference
 * \author Aissata
 * \date 12 octobre 2022
 *
 */

#include <sstream>
#include <string>
#include "Reference.h"
#include "ContratException.h"
#include "validationFormat.h"

using namespace std;
using namespace util;

/**
 * \namespace biblio
 * \brief Ce namespace contient la classe Reference et ses derivés
 */
namespace biblio
{


  /**
   * \brief constructeur avec paramètre de la classe Reference
   *
   *  Ce Constructeur construit un objet de la classe Reference à partir des données passées en paramètre
   *
   * \param[in] p_auteurs : le nom l'auteur (ou du premier auteur s’ils sont plusieurs) de la référence
   * \param[in] p_titre   : le titre du livre
   * \param[in] p_annee   : l'année d'édition de la référence
   * \param[in] p_identifiant : l’identifiant de la référence, code ISSN ou code ISBN
   * \pre p_auteurs, p_titre, p_annee, et p_identifiant doivent correspondre à un format valide
   * \post m_auteurs prend la valeur de p_auteurs
   * \post m_titre prend la valeur de p_titre
   * \post m_annee prend la valeur de p_annee
   * \post m_identifiant prend la valeur de p_identifiant
   *
   */
  Reference::Reference (const string& p_auteurs, const string& p_titre, int p_annee, const string& p_identifiant) : m_auteurs (p_auteurs), m_titre (p_titre), m_annee (p_annee), m_identifiant (p_identifiant)
  {

    PRECONDITION (validerFormatNom (p_auteurs));
    PRECONDITION (!p_titre.empty ());
    PRECONDITION (p_annee > 0);
    PRECONDITION (validerCodeIssn (p_identifiant) || validerCodeIsbn (p_identifiant));

    POSTCONDITION (m_auteurs == p_auteurs);
    POSTCONDITION (m_titre == p_titre);
    POSTCONDITION (m_annee == p_annee);
    POSTCONDITION (m_identifiant == p_identifiant);

    INVARIANTS ();
  }


  /**
   * \brief Méthode permettant d'accéder en lecture (accesseur) à l'attribut m_auteurs de la classe Reference
   * \return m_auteurs : le nom l'auteur (ou du premier auteur s’ils sont plusieurs) de la référence
   */
  const string&
  Reference::reqAuteurs () const
  {
    return m_auteurs;
  }


  /**
   * \brief Méthode permettant d'accéder en lecture (accesseur) à l'attribut m_titre de la classe Reference
   * \return m_titre : le titre du livre
   */
  const string&
  Reference::reqTitre () const
  {
    return m_titre;
  }


  /**
   * \brief Méthode permettant d'accéder en lecture (accesseur) à l'attribut m_identifiant de la classe Reference
   * \return m_identifiant : l’identifiant de la référence
   */
  const string&
  Reference::reqIdentifiant () const
  {
    return m_identifiant;
  }


  /**
   * \brief Méthode permettant d'accéder en lecture (accesseur) à l'attribut m_annee de la classe Reference
   * \return m_annee : l'année d'édition de la référence
   */
  int
  Reference::reqAnnee () const
  {
    return m_annee;
  }


  /**
   * \brief Méthode permettant de modifier l'attribut  m_annee de la classe Reference en assignant une nouvelle année
   * \param[in] p_annee : la nouvelle valeur que l'année d'édition de la référence aura après modification
   * \pre p_annee doit correspondre à une année valide, soit nombre strictement supérieur à 0
   * \post m_annee prend la valeur de p_annee
   */
  void
  Reference::asgAnnee (int p_annee)
  {
    PRECONDITION (p_annee > 0);
    m_annee = p_annee;
    POSTCONDITION (m_annee == p_annee);
    INVARIANTS ();
  }


  /**
   * \brief Méthode retournant une partie des informations sur une reference formatée.
   *        Elle doit être implémentée dans les classes filles.
   * \return un objet string d'une partie de la reference formatée
   *
   */
  string
  Reference::reqReferenceFormate () const
  {
    ostringstream os;
    os << m_auteurs << ". " << m_titre << "." ;
    return os.str ();
  }


  /**
   * \brief Operateur de comparaison d'égalité qui va permettre de comparer deux objets de la classe Reference
   * \param[in] p_reference un objet de la classe Reference qui va être comparé à un autre
   * \return un booleen, true si les objets sont égaux ou false si ils ne le sont pas
   */
  bool Reference::operator== (const Reference& p_reference) const
  {
    return m_auteurs == p_reference.m_auteurs && m_titre == p_reference.m_titre && m_annee == p_reference.m_annee && m_identifiant == p_reference.m_identifiant;
  }


  /**
   *
   * \brief Méthode permettant de verfier tous les invariants de notre classe
   *
   */
  void
  Reference::verifieInvariant () const
  {
    INVARIANT (validerFormatNom (m_auteurs));
    INVARIANT (!m_titre.empty ());
    INVARIANT (m_annee > 0);
    INVARIANT (validerCodeIssn (m_identifiant) || validerCodeIsbn (m_identifiant));
  }

}






