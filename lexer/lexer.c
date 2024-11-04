#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/lexer.h"
#include "../include/token.h"

Lexer* New(const char* input) {
    Lexer* l = (Lexer*)malloc(sizeof(Lexer));
    l->input = input;
    l->position = 0; 
    l->readPosition = 0; 
    l->ch = '\0';

    readchar(l);
    return l;
}

Token* newToken(TokenType tokenType, char* ch) {
    Token* t = (Token*)malloc(sizeof(Token));
    t->Type = tokenType;
    t->Literal = ch;

    return t;
}

void readchar(Lexer* l) {
    int inputlength = strlen(l->input);
    if (l->readPosition >= inputlength) {
        l->ch = 0;
    } else {
        l->ch = l->input[l->readPosition];
    }

    l->position = l->readPosition;
    l->readPosition++;
}

Token* NextToken(Lexer* l) {
    Token* t;
    switch (l->ch) {
        case '=':
            t = newToken(ASSIGN, &l->ch);
            break;
        case ';':
            t = newToken(SEMICOLON, &l->ch);
            break;
        case '(':
            t = newToken(LPAREN, &l->ch);
            break;
        case ')':
            t = newToken(RPAREN, &l->ch);
            break;
        case ',':
            t = newToken(COMMA, &l->ch);
            break;
        case '+':
            t = newToken(PLUS, &l->ch);
            break;
        case '{':
            t = newToken(LBRACE, &l->ch);
            break;
        case '}':
            t = newToken(RBRACE, &l->ch);
            break;
        case '\0':
            t = newToken(END_OF_FILE, &l->ch);
            break;
        default:
            t = newToken(ILLEGAL, &l->ch);
            break;
    }
    readchar(l);
    return t;
}
