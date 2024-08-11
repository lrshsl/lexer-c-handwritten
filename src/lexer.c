#include "lexer.h"
#include <ctype.h>

Token next(Lexer *l) {
  skip_whitespace(l);

  char ch = l->src[l->i];

  if (ch == '\0')
    return TOK_EOF;

  if (ch == '"')
    return parse_string(l);
  if (isalpha(ch))
    return parse_ident(l);
  if (isdigit(ch))
    return parse_number(l);

  /* Symbol */
  l->token_start = l->i;
  ++l->i;
  l->token_end = l->i;
  return TOK_SYMBOL;
}

Token parse_ident(Lexer *l) {
  l->token_start = l->i;

  while (isalnum(l->src[l->i]) || l->src[l->i] == '_')
    ++l->i;

  l->token_end = l->i;
  return TOK_IDENT;
}

Token parse_number(Lexer *l) {
  l->token_start = l->i;

  while (isdigit(l->src[l->i]) || l->src[l->i] == '.')
    ++l->i;

  l->token_end = l->i;
  return TOK_NUMBER;
}

Token parse_string(Lexer *l) {
  ++l->i;

  while (l->src[l->i] != '\0' && l->src[l->i] != '"')
    ++l->i;

  l->token_end = l->i;
  ++l->i;
  return TOK_STRING;
}

void skip_whitespace(Lexer *l) {
  while (isspace(l->src[l->i]))
    ++l->i;
}

// vim: foldmethod=marker foldmarker=Section,EndSection
