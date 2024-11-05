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

// read the next identifier to tokenize
char* readIdentifier(Lexer* l);

// checks if char is a letter
int isLetter(char ch);

// return a new array 
char* sliceInput(const char* input, int start, int end);

#endif // LEXER_H
