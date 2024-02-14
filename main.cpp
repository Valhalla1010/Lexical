#include <iostream>
#include "lexer.h"
#include "expr.h"

//12 + 3 * 42
/*
 *
 * factor> → <exp> ** <factor>
    <exp>
    <exp> → (<expr>)
    | id
    <factor> -> id
 */
factor* parse_factor(lexer &lexer);
term* parse_term(lexer &lexer);
expr* parse_expr(lexer& l);

/*
 * <term> ->
 * */
term* parse_term(lexer &lexer) {
    auto fac = parse_factor(lexer);
    term* result = nullptr;
    auto mult = lexer.lex();
    if(mult == lexer::MULT_OP){
        auto child = parse_term(lexer);
        fac->add(child);

    }
    return result;

}

factor* parse_factor(lexer &lexer) {
    factor* result = nullptr;
    if(lexer.lex() == lexer::DIGIT){
        result = new factor(lexer.lexeme());
    }
    return result;

}

/*<expr> → <term> + <expr>
 * <term> - <expr>
 * <term>
 */

expr* parse_expr(lexer& l){
   auto term = parse_term(l);
   expr* result = nullptr;
   if(term){
       result = new expr(term);
   }
    auto token =l.lex();

    if(token == lexer::ADD_OP){
       auto child = parse_expr(l);
       result->add(child);
    }
    return result;
}


int main(int argc, char* argv[]) {
    if(argc < 2){
        std::cerr << "No program givenn";
        return EXIT_FAILURE;
    }
    std::string program = argv[1];
    lexer lex(program);
    auto expr = parse_expr(lex);
    std::cout << expr->eval();
}
