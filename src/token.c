#include "token.h"

const char *token_to_str(Token t) {
  switch (t) {
  case TOK_EOF:
    return "Eof   ";
  case TOK_IDENT:
    return "Ident ";
  case TOK_NUMBER:
    return "Number";
  case TOK_SYMBOL:
    return "Symbol";
  case TOK_STRING:
    return "String";
  }
}

// vim: foldmethod=marker foldmarker=Section,EndSection
