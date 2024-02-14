//
// Created by davii on 1/30/2024.
//

#include "lexer.h"

lexer::lexer(std::string program):input(program) {

}

token lexer::lex() {
    current_lexeme == "";
    token result;
    auto c = add_char();
    while(is_whitespace(c)){
        current_lexeme +=c;
        result =DIGIT;
        add_char();
    }

    switch (c) {
        case '+':
            current_lexeme = c;
            return ADD_OP;

        case '*':
            current_lexeme = c;
            return MULT_OP;

    }
    return result;
}

char lexer::add_char() {
    return input[index++];
}

std::string lexer::lexeme() {
    return current_lexeme;
}

bool lexer::is_whitespace(char c) {
    return  std::isspace(c);
}

