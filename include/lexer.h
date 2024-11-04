// prevent multiple inclusions
#ifndef LEXER_H
#define LEXER_H

#include "../include/token.h"


// Defining lexer struct
typedef struct {
    const char* input;
    int position;
    int readPosition;
    char ch;
} Lexer;


// Function prototypes
Lexer* New(const char* input);

// read current character and move pointer to next
void readchar(Lexer* l);

// get the next token in the input 
Token* NextToken(Lexer* l);

// create a new token
Token* newToken(TokenType tokenType, char* ch);


#endif // LEXER_H
