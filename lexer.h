//
// Created by davii on 1/30/2024.
//

#ifndef LABB_1_LEXER_H
#define LABB_1_LEXER_H


#include <string>
using token = int;
class lexer {
public:
    enum{
        DIGIT,
        ADD_OP,
        MULT_OP,
        END
    };
    lexer() = delete;

    lexer(std::string program);
    token lex();
    std::string lexeme();

private:
    std::string input;
    std::string current_lexeme;
    size_t index = 0;

    char add_char();



    bool is_whitespace(char c);
};


#endif //LABB_1_LEXER_H
