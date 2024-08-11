#ifndef TOKEN_H
#define TOKEN_H

#include "header.h"

typedef enum Token {
  TOK_IDENT,
  TOK_NUMBER,
  TOK_STRING,
  TOK_SYMBOL,

  TOK_EOF,
} Token;

const char *token_to_str(Token t);

#endif
// vim: foldmethod=marker foldmarker=Section,EndSection
