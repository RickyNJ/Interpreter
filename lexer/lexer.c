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
    char* literal = (char*)malloc(strlen(ch)+1);
    if (literal != NULL) {
        strcpy(literal, ch);
    }
    
    t->Type = tokenType;
    t->Literal = literal;

    return t;
}

void readchar(Lexer* l) {
    int inputlength = strlen(l->input);

    if (l->readPosition >= inputlength) {
        l->ch = '\0';
    } else {
        l->ch = l->input[l->readPosition];
    }

    printf("read char: %c\n", l->ch);

    l->position = l->readPosition;
    l->readPosition++;
}

char* sliceInput(const char* input, int start, int end) {
    if (start < 0 || end < 0 || start >= end || start >= strlen(input)){
        return NULL;
    }

    int length = end - start;
    char* res = malloc((length + 1) * sizeof(char));
    if (res == NULL) {
        return NULL;
    }

    strncpy(res, input+start, length);
    res[length] = '\0';

    return res;
}

char* readIdentifier(Lexer *l) {
    int position = l->position;

    while (isLetter(l->ch)) {
        readchar(l);
    }
    for (int i = 0; i > (l->position - position); i++) {

    }
    return sliceInput(l->input, position, l->position);
}


int isLetter(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
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
            printf("this got triggered \n");
            if (isLetter(l->ch)){
                t->Literal = readIdentifier(l);
            } else {
                t = newToken(ILLEGAL, &l->ch);
            }

            break;
    }

    readchar(l);
    return t;
}
