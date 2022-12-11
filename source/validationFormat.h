
/**
 * \file validationFormat.h
 * \brief Prototype des fonctions de validation
 * \author Aissata
 * \date 12 octobre 2022
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H
#include <string>

/**
 * \namespace util
 * \brief Ce namespace contient les fonctions de validation
 */
namespace util
{

  bool validerFormatNom (const std::string& p_nom);
  bool validerCodeIssn (const std::string& p_issn);
  bool validerCodeIsbn (const std::string& p_isbn);

  //Fonctions ajoutés pour la maintenance du TP
  bool validerNombre (const std::string& groupeChiffre);
}




#endif /* VALIDATIONFORMAT_H */

