/**
 * \file   Bibliographie.cpp
 * \brief Implementation de la classe Bibliographie permettant de faire la gestion des références
 * \author Aissata
 * \date 23 novembre 2022
 */
#include <sstream>
#include <string>
#include "Bibliographie.h"
#include "ContratException.h"

using namespace std;

namespace biblio
{


  /**
   *
   * \brief Constructeur avec paramètre de la classe la Bibliographie
   * Ce constructeur construit un objet de la classe Bibliographie
   *
   * \param[in] p_nomBibliographie represente le nom d'une bibliographie
   *
   * \pre p_nomBibliographie ne doit pas être vide
   * \post m_nomBibliographie prend la valeur de p_nomBibliographie
   */

  Bibliographie::Bibliographie (const string& p_nomBibliographie) : m_nomBibliographie (p_nomBibliographie)
  {
    PRECONDITION (!m_nomBibliographie.empty ());
    POSTCONDITION (m_nomBibliographie == p_nomBibliographie);
    INVARIANTS ();
  }


  /**
   * \brief Constructeur de copie. Il copie une bibliographie
   * \param[in] p_bibliographie represente un objet de la classe Bibliographie
   *
   * \post m_nomBibliographie prend la valeur de m_nomBibliographie de l'objet passé en paramètre
   */
  Bibliographie::Bibliographie (const Bibliographie& p_bibliographie) : m_nomBibliographie (p_bibliographie.m_nomBibliographie)
  {
    PRECONDITION (m_vReferences.empty ());

    for (size_t i = 0; i < p_bibliographie.m_vReferences.size (); ++i)
      {
        ajouterReference (*p_bibliographie.m_vReferences[i]);
      }
    POSTCONDITION (m_nomBibliographie == p_bibliographie.m_nomBibliographie);
    INVARIANTS ();
  }


  /**
   * \brief Destructeur de la classe Bibliograpgie. Il va désalloué toutes les references d'une bibliographie dans le vecteur
   */
  Bibliographie::~Bibliographie ()
  {
    for (size_t i = 0; i < m_vReferences.size (); ++i)
      {
        delete m_vReferences[i];
      }
    m_vReferences.clear ();
  }


  /**
   * \brief Méthode permettant d'accéder en lecture (accesseur) à l'attribut m_nomBibliographie de la classe Reference
   * \return m_nomBibliographie le nom de la bibliographie
   */
  string
  Bibliographie::reqNomBibliographie () const
  {
    return m_nomBibliographie;
  }


  /**
   * \brief Cette méthode parcourt toutes les reference de la bibliographie et retourne les informations des references.
   * \return un objet string avec les informations correspondant à chaque référence
   */
  string
  Bibliographie::reqBibliographieFormate () const
  {
    ostringstream os;
    os << m_nomBibliographie << endl << "===============================" << endl;

    for (size_t i = 0; i < m_vReferences.size (); ++i)
      {
        os << "[" << i + 1 << "] " << m_vReferences[i] -> reqReferenceFormate () <<  endl;
      }

    return os.str ();
  }


  /**
   * \brief Méthode permettant de vérifier si une reference est déjà présente dans le vecteur de reference
   * \param[in] p_identifiant l'identifiant de la reference
   * \return un booléen, true si la reference est déjà presente ou false sinon
   */
  bool
  Bibliographie::referenceEstDejaPresente (const string& p_identifiant) const
  {
    bool estDejaPresente = false;
    for (size_t i = 0; i < m_vReferences.size (); ++i)
      {
        if (m_vReferences[i]->reqIdentifiant () == p_identifiant)
          {
            estDejaPresente = true;
            break;
          }
      }
    return estDejaPresente;
  }


  /**
   * \brief Méthode permettant d'assigner une bibliographie
   * \param[in] p_bibliographie un objet de la classe Bibliographipe
   * \return Une bibliographie
   */
  Bibliographie& Bibliographie::operator= (const Bibliographie& p_bibliographie)
  {
    m_nomBibliographie = p_bibliographie.m_nomBibliographie;
    //Vider le vecteur de Reference
    for (size_t i = 0; i < m_vReferences.size (); ++i)
      {
        delete m_vReferences[i];
      }
    m_vReferences.clear ();


    //Remplir le vecteur de Reference
    for (size_t i = 0; i < p_bibliographie.m_vReferences.size (); ++i)
      {
        ajouterReference (*p_bibliographie.m_vReferences[i]);
      }

    INVARIANTS ();

    return *this;
  }


  /**
   * \brief Méthode permettant d'ajouter une nouvelle reference au vecteur de Reference
   * \param[in] p_nouvelleReference la nouvelle reference à ajouter au vecteur de Reference.
   *
   * \pre p_nouvelleReference ne doit pas être deja presente dans le vecteur de Reference
   */
  void
  Bibliographie::ajouterReference (const Reference & p_nouvelleReference)
  {
    PRECONDITION (!referenceEstDejaPresente (p_nouvelleReference.reqIdentifiant ()));
    m_vReferences.push_back (p_nouvelleReference.clone ());
    INVARIANTS ();
  }


  /**
   * \brief Méthode permettant de verifier tous les invariants
   */
  void
  Bibliographie::verifieInvariant () const
  {
    INVARIANT (!m_nomBibliographie.empty ());
    //INVARIANT (!m_vReferences.empty ());
  }
}

