/*
 * \file Ouvrage.h
 * \brief Prototype de la classe Ouvrage, dérivée de la classe Reference
 * \author Aissata
 * \date 18 novembre 2022
 */

#ifndef OUVRAGE_H
#define OUVRAGE_H

#include <string>
#include "Reference.h"

/**
 * \namespace biblio
 * \brief Namespace contenant les classes Reference, Ouvrage, Journal et Bibliotheque
 */
namespace biblio
{

  /**
   * \class Ouvrage
   * \brief Classe modélisant les Ouvrages qui representent les references de la categorie Ouvrage, derivé de Reference
   */
  class Ouvrage : public Reference
  {
  public:
    Ouvrage (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant, const std::string& p_editeur, const std::string& p_ville);

    const std::string& reqEditeur () const;
    const std::string& reqVille () const;

    virtual Reference* clone () const;
    virtual std::string reqReferenceFormate () const;

  private:
    std::string m_editeur;
    std::string m_ville;

    void verifieInvariant () const;
  };

}

#endif /* OUVRAGE_H */

