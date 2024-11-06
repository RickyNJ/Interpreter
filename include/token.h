// prevent multiple inclusions
#ifndef  TOKEN_H
#define TOKEN_H


// Define TokeType as a const char* to represent token types
typedef const char* TokenType;

// Define the Token struct
typedef struct {
    TokenType Type;
    const char* Literal;
} Token;

typedef struct {
    char* Key;
    TokenType Type;
} Keyword;


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

//
extern const TokenType LPAREN;
extern const TokenType RPAREN;
extern const TokenType LBRACE;
extern const TokenType RBRACE;


// Keywords
extern const TokenType FUNCTION;
extern const TokenType LET;


#endif // TOKEN_H
