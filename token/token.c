#include <stdio.h>
#include <stdlib.h>
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
const TokenType TRUE = "TRUE";
const TokenType FALSE = "FALSE";
const TokenType IF = "IF";
const TokenType ELSE = "ELSE";
const TokenType RETURN = "RETURN";

int hashFunction(char *key) {
    unsigned long hash = 5381;
    int c;

    while (c = *key++) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % TABLE_SIZE;
};

void insertKeyword(Keywords* kwds, KeywordsEntry* kwe) {
    int index = hashFunction(kwe->Ident);
    printf("%d\n", index);

    while (kwds->Entry[index].Type) {

    };
}

Keywords* keywordsInit() {
    Keywords* kwds = (Keywords*)malloc(sizeof(Keywords));
    kwds->size = TABLE_SIZE;
    kwds->Entry = (KeywordsEntry*)calloc(kwds->size, sizeof(KeywordsEntry));

    for (size_t i = 0; i < TABLE_SIZE; i++) {
        kwds->Entry[i].Ident = NULL;
    }

    KeywordsEntry* func = (KeywordsEntry*)malloc(sizeof(KeywordsEntry));
    func->Ident = "func";
    func->Type = FUNCTION;

    insertKeyword(kwds, func);
    free(func);

    return kwds;
}
