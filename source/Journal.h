/**
 * \file Journal.h
 * \brief Prototype de la classe Journal, derivée de la classe Reference
 * \author Aissata
 * \date 23 novembre 2022
 */

#ifndef JOURNAL_H
#define JOURNAL_H
#include "Reference.h"

/**
 * \namespace biblio
 * \brief namespace contenant la classe Reference avec ses derivés
 */
namespace biblio
{

  /**
   * \class Journal
   * \brief Classe modelisant le journal, qui représente les références de la catégorie Journal
   */
  class Journal : public Reference
  {
  public:
    Journal (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant, const std::string& p_nom, int p_volume, int p_numero, int p_page);

    const std::string& reqNom () const;
    int reqVolume () const;
    int reqNumero () const;
    int reqPage () const;

    virtual Reference* clone () const;
    virtual std::string reqReferenceFormate () const;

  private:
    std::string m_nom;
    int m_volume;
    int m_numero;
    int m_page;

    void verifieInvariant () const;
  };


}


#endif /* JOURNAL_H */

