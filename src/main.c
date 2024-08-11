#include "lexer.h"
#include <stdio.h>

const char *input =
    "hey\n"
    "what\n"
    "69 < 42\n"
    "move(x,y);\n"
    "\n"
    "\n"
    "mov x      <- y\n"
    "\n"
    "      veryLongWeird___function_name89_8thatCouldBE_POSSIBLE_4();\n";

int main() {
  Lexer lexer = {
      .src = input,
  };
  Token tok;
  while ((tok = next(&lexer)) != TOK_EOF)
    printf("%s | %.*s\n", token_to_str(tok),
           (int)(lexer.token_end - lexer.token_start),
           (const char *)(lexer.src + lexer.token_start));
  return 0;
}
