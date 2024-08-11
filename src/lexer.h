#ifndef LEXER_H
#define LEXER_H

#include "header.h"
#include "token.h"

typedef struct Lexer {
  const char *src;
  usize src_len;
  usize i;
  usize token_start;
  usize token_end;
} Lexer;

Token next(Lexer *l);
Token parse_ident(Lexer *l);
Token parse_number(Lexer *l);
Token parse_string(Lexer *l);

void skip_whitespace(Lexer *l);

#endif
// vim: foldmethod=marker foldmarker=Section,EndSection
