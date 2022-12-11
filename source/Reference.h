/**
 * \file Reference.h
 * \brief Prototype de la classe Reference
 * \author Aissata
 * \date 12 octobre 2022
 */

#ifndef REFERENCE_H
#define REFERENCE_H

#include <string>
/**
 * \namespace biblio
 * \brief Namespace contenant les classes Reference, Ouvrage, Journal et Bibliotheque
 */
namespace biblio
{

  /**
   * \class Reference
   * \brief Classe modélisant les références bibliographiques
   */
  class Reference
  {
  public:
    Reference (const std::string& p_auteurs, const std::string& p_titre, int p_annee, const std::string& p_identifiant);

    const std::string& reqAuteurs () const;
    const std::string& reqTitre () const;
    const std::string& reqIdentifiant () const;
    int reqAnnee () const;

    void asgAnnee (int p_annee);

    bool operator== (const Reference& p_reference) const;

    virtual std::string reqReferenceFormate () const;
    virtual Reference* clone () const = 0;

    virtual
    ~Reference () { };

  protected:
    std::string m_auteurs;
    std::string m_titre;
    int m_annee;
    std::string m_identifiant;

  private:
    void verifieInvariant () const;
  };
}

#endif /* REFERENCE_H */

