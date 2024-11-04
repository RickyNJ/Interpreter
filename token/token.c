#include "../include/token.h"


const TokenType ILLEGAL = "ILLEGAL";
const TokenType END_OF_FILE = "EOF";

// identifiers + literals
const TokenType IDENT = "IDENT";
const TokenType INT = "INT";

// operators
const TokenType ASSIGN = "=";
const TokenType PLUS = "+";

// delimiters
const TokenType COMMA = ",";
const TokenType SEMICOLON = ";";

const TokenType LPAREN = "(";
const TokenType RPAREN = ")";
const TokenType LBRACE = "{";
const TokenType RBRACE = "}";

// keywords
const TokenType FUNCTION = "FUNCTION";
const TokenType LET = "LET";
