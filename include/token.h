// prevent multiple inclusions
#ifndef  TOKEN_H
#define TOKEN_H

// define keyword hashtable size
#include <stdio.h>
#define TABLE_SIZE 32

// Define TokeType as a const char* to represent token types
typedef const char* TokenType;

// Define the Token struct
typedef struct {
    TokenType Type;
    const char* Literal;
} Token;


// TypenType values (external linkage for use in other files)
extern const TokenType ILLEGAL;
extern const TokenType END_OF_FILE;

// Identifiers + literals
extern const TokenType IDENT;
extern const TokenType INT;

// Operators
extern const TokenType ASSIGN;
extern const TokenType PLUS;

// Delimiters
extern const TokenType COMMA;
extern const TokenType SEMICOLON;

extern const TokenType LPAREN;
extern const TokenType RPAREN;
extern const TokenType LBRACE;
extern const TokenType RBRACE;

// Keywords
extern const TokenType FUNCTION;
extern const TokenType LET;
extern const TokenType TRUE;
extern const TokenType FALSE;
extern const TokenType IF;
extern const TokenType ELSE;
extern const TokenType RETURN;

typedef struct {
    char* Ident;
    TokenType Type;
} KeywordsEntry;

typedef struct {
    KeywordsEntry* Entry;
    size_t size;
} Keywords;

// Function prototypes
// Initialize keyword hashtable 
Keywords* keywordsInit();

KeywordsEntry* createItem(char* key, TokenType type);
void insertKeyword(Keywords* kwds, KeywordsEntry* kwe);
int hashFunction(char* key);

// Look up a identifier in a hashtable
TokenType LookupIdent(char* key);

#endif // TOKEN_H
