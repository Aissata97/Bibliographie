/**
 * \file   Ouvrage.cpp
 * \brief Implémentation de la classe Ouvrage
 * \author Aissata
 * \date 18 novembre 2022
 */

#include <sstream>
#include <string>
#include "Ouvrage.h"
#include "validationFormat.h"
#include "ContratException.h"

using namespace std;
using namespace util;

namespace biblio
{


  /**
   *
   * \brief constructeur avec paramètre de la classe Ouvrage, derivé de Reference
   *
   *  Ce Constructeur construit un objet de la classe Ouvrage à partir des données passées en paramètre
   *
   * \param[in] p_auteurs le nom l'auteur (ou du premier auteur s’ils sont plusieurs) de la référence
   * \param[in] p_titre   le titre du livre
   * \param[in] p_annee    l'année d'édition de la référence
   * \param[in] p_identifiant l’identifiant de la référence, le code ISBN
   * \param[in] p_editeur le nom de l'éditeur de l’ouvrage
   * \param[in] p_ville la ville d’édition de l’ouvrage
   *
   * \pre p_editeur doit être dans un format valide tel que determiné par la fonction validerFormatNom
   * \pre p_ville doit être dans un format valide tel que determiné par la fonction validerFormatNom
   * \pre p_identifiant doit être dans un format valide tel que determiné par la fonction validerCodeIsbn
   *
   * \post m_editeur prend la valeur de p_editeur
   * \post m_ville prend la valeur p_ville
   */
  Ouvrage::Ouvrage (const string& p_auteurs, const string& p_titre, int p_annee, const string& p_identifiant, const string& p_editeur, const string& p_ville) : Reference (p_auteurs, p_titre, p_annee, p_identifiant), m_editeur (p_editeur), m_ville (p_ville)

  {
    PRECONDITION (validerFormatNom (p_editeur));
    PRECONDITION (validerFormatNom (p_ville));
    PRECONDITION (validerCodeIsbn (p_identifiant));

    POSTCONDITION (m_editeur == p_editeur);
    POSTCONDITION (m_ville == p_ville);

    INVARIANTS ();
  }


  /**
   *
   * \brief Méthode permettant d'accéder en lecture (accesseur) à l'attribut m_editeur de la classe Ouvrage
   * \return m_editeur l'éditeur de l'ouvrage
   */
  const string&
  Ouvrage::reqEditeur () const
  {
    return m_editeur;
  }


  /**
   * \brief Méthode permettant d'accéder en lecture (accesseur) à l'attribut m_ville de la classe Ouvrage
   * \return m_ville la ville d'édition de l'ouvrage
   */
  const string&
  Ouvrage::reqVille () const
  {
    return m_ville;
  }


  /**
   * \brief Méthode affichant les informations de l'Ouvrage sous forme d'une chaine formatée
   * \return un objet string avec les informations correspondant à un ouvrage formatée
   */
  string
  Ouvrage::reqReferenceFormate () const
  {
    ostringstream os;
    os << Reference::reqReferenceFormate ()
            << " " << m_ville << " : " << m_editeur << ", " << m_annee << ". " <<  m_identifiant << ".";
    return os.str ();
  }


  /**
   * \brief Méthode permettant de faire une copie sur le monceau de l'objet courant
   * \return Objet copié
   */
  Reference*
  Ouvrage::clone () const
  {
    return new Ouvrage (*this);
  }


  /**
   *
   * \brief Méthode permettant de vérifier tous les variants de la classe Ouvrage
   */
  void
  Ouvrage::verifieInvariant () const
  {
    INVARIANT (validerFormatNom (m_ville));
    INVARIANT (validerFormatNom (m_editeur));
    INVARIANT (validerCodeIsbn (m_identifiant));
  }


}

