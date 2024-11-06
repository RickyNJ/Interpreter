#include <stdio.h>
#include <string.h>
#include "../include/token.h"
#include "../include/lexer.h"

int main() {
    char* input = "=+(){},;";
    Token want[] = {
        {.Type = ASSIGN, .Literal = "="},
        {.Type = PLUS, .Literal = "+"},
        {.Type = LPAREN, .Literal = "("},
        {.Type = RPAREN, .Literal = ")"},
        {.Type = LBRACE, .Literal = "{"},
        {.Type = RBRACE, .Literal = "}"},
        {.Type = COMMA, .Literal = ","},
        {.Type = SEMICOLON, .Literal = ";"}
    };

    Lexer* l = New(input);

    for (int i = 0; i < 8; i++) {
        Token* t = NextToken(l);

        if (t->Type != want[i].Type) {
            printf("Test failed at token %d: expected Type=%s, Literal=%s but got Type=%s, Literal=%s\n", i, want[i].Type, want[i].Literal, t->Type, t->Literal);
            break;
        } else {
            printf("Token %d passed: Type: %s, Literal: %s\n", i, t->Type, t->Literal);
            printf("Wanted type: %s, literal: %s\n\n", want[i].Type, want[i].Literal);
        }
    }

    return 0;
}
