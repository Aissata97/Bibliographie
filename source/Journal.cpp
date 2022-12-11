/**
 * \file   Journal.cpp
 * \brief Implementation de la classe Journal
 * \author Aissata
 * \date 23 novembre 2022
 */

#include <sstream>
#include <string>
#include "Journal.h"
#include "validationFormat.h"
#include "ContratException.h"


using namespace std;
using namespace util;

/**
 * \namespace biblio
 * \brief Namespace contenant la classe Reference et ses classes derivées
 */
namespace biblio
{


  /**
   * \brief Constructeur avec paramètre de la classe Journal
   *
   * Ce construit construit un objet de la classe Journal, derivé de la classe Reference
   *
   * \param[in] p_auteurs le nom de l'auteur
   * \param[in] p_titre  le titre du Journal
   * \param[in] p_annee  l'année de la publication
   * \param[in] p_identifiant le code ISSN
   * \param[in] p_nom le nom du journal dans lequel a été publié la reference
   * \param[in] p_volume le volume de la reference publié dans le journal
   * \param[in] p_numero  le numéro de la reference publiée dans le journal
   * \param[in] p_page la page où commmence la reference publé dans le journal
   *
   * \pre p_nom ne doit pas être vide
   * \pre p_volume doit être un entier
   * \pre p_numero doit être un entier
   * \pre p_page doit être un entier
   *
   * \post m_nom prend la valeur de p_nom
   * \post m_volume prend la valeur de p_volume
   * \post m_numero prend la valeur de p_numero
   * \post m_page prend la valeur de p_page
   */
  Journal::Journal (const string& p_auteurs, const string& p_titre, int p_annee, const string& p_identifiant, const string& p_nom, int p_volume, int p_numero, int p_page) : Reference (p_auteurs, p_titre, p_annee, p_identifiant), m_nom (p_nom), m_volume (p_volume), m_numero (p_numero), m_page (p_page)
  {

    PRECONDITION (validerCodeIssn (p_identifiant));
    PRECONDITION (!p_nom.empty ());
    PRECONDITION (p_volume > 0);
    PRECONDITION (p_numero > 0);
    PRECONDITION (p_page > 0);

    POSTCONDITION (m_nom == p_nom);
    POSTCONDITION (m_volume == p_volume );
    POSTCONDITION (m_numero == p_numero);
    POSTCONDITION (m_page == p_page);

    INVARIANTS ();
  }


  /**
   * \brief Méthode permettant d'accéder en lecture(accesseur) à l'attribut m_nom
   * \return m_nom le nom du journal dans lequel a été publiée la reference
   */
  const string&
  Journal::reqNom () const
  {
    return m_nom;
  }


  /**
   * \brief Méthode permettant d'accéder en lecture (accesseur) à l'attribut m_volume
   * \return m_volume le volume du journal
   */
  int
  Journal::reqVolume () const
  {
    return m_volume;
  }


  /**
   * \brief Méthode permettant d'accéder en lecture (accesseur) à l'attribut m_numero
   * \return m_numero le numero du journal
   */
  int
  Journal::reqNumero () const
  {
    return m_numero;
  }


  /**
   * \brief Méthode permettant d'accéder en lecture (accesseur) à l'attribut m_page
   * \return m_page le numéro de la page du Journal
   */
  int
  Journal::reqPage () const
  {
    return m_page;
  }


  /**
   * \brief Méthode permettant de faire une copie sur le monceau de l'objet courant
   * \return Objet copié
   */
  Reference*
  Journal::clone () const
  {
    return new Journal (*this);
  }


  /**
   * \brief Méthode affichant les informations du journal sous forme d'une chaine formatée, elle augmente la méthode de la classe de base
   * \return un objet string avec les informations correspondant à un journal formaté
   */
  string
  Journal::reqReferenceFormate () const
  {
    ostringstream os;
    os << Reference::reqReferenceFormate ()
            << " " << m_nom << ", vol. " << m_volume << ", no. " << m_numero << ", pp. " << m_page << ", " << m_annee << ". " << m_identifiant << ".";

    return os.str ();
  }


  /**
   * \brief Méthode permettant de verifier tous les invariants
   */
  void
  Journal::verifieInvariant () const
  {
    INVARIANT (!m_nom.empty ());
    INVARIANT (m_volume > 0);
    INVARIANT (m_numero > 0);
    INVARIANT (m_page > 0);
    INVARIANT (validerCodeIssn (m_identifiant));
  }
}
