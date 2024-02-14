//
// Created by davii on 1/30/2024.
//

#ifndef LABB_1_EXPR_H
#define LABB_1_EXPR_H

#include <vector>
#include <string>

struct op{
    virtual int eval()=0;
    void add(op* child){
        children.push_back(child);
    }
    std::vector<op*> children;
};
struct factor: op{
    factor(std::string digits){
        value = std::stoi(digits);
    }
    int eval() override{
        auto result = children[0]->eval();
        if(children.size() > 1){
            result += children[1]->eval();
        }
        return result;
    }
    int value;
};
struct term: op{
    term(factor*  fac){
        add(fac);
    }
    int eval() override{
        auto result = children[0]->eval();
        if(children.size() > 1){
            result += children[1]->eval();
        }
        return result;
    }
};

struct expr: op {

    expr(term *child){
        add(child);
    };
    int eval() override{
        auto result = children[0]->eval();
        if(children.size() > 1){
            result += children[1]->eval();
        }
        return result;
    }

};



#endif //LABB_1_EXPR_H
