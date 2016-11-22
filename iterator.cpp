#include "iterator.h"

using namespace std;

void OperatorIterator::first() {
    if (self_ptr->get_left()) { 
        current_ptr = self_ptr->get_left();
    }
}

void OperatorIterator::next() {
    if (current_ptr == self_ptr->get_left()) {
        current_ptr = self_ptr->get_right();
    }
    else if (current_ptr == self_ptr->get_right()) {
        current_ptr = NULL;
    }
}

bool OperatorIterator::is_done() {
    return current_ptr == NULL;
}

Base* OperatorIterator::current() {
    return current_ptr;
}

void UnaryIterator::first() {
    if (self_ptr->get_left()) {
        current_ptr = self_ptr->get_left();
    }
}

void UnaryIterator::next() {
    current_ptr = self_ptr->get_right();
}

bool UnaryIterator::is_done() {
    return current_ptr == NULL;
}

Base* UnaryIterator::current() {
    return current_ptr;    
}

void NullIterator::first() {}

void NullIterator::next() {}

bool NullIterator::is_done() {
    return true;
}

Base* NullIterator::current() {
    return NULL;
}

void PreOrderIterator::first() {
    Iterator *it = this->self_ptr->create_iterator();

    if (it) {
        while (!iterators.empty()) {
            iterators.pop();
        }
    }
    it->first();
    this->iterators.push(it);
}

void PreOrderIterator::next() {
    Iterator *it = iterators.top()->current()->create_iterator();
    
    it->first();
    iterators.push(it);
    
    while (!iterators.empty() && iterators.top()->is_done()) {
        this->iterators.pop();
        if (iterators.empty()) {
            break;
        }
        this->iterators.top()->next();
    }
}

bool PreOrderIterator::is_done() {
    if (iterators.empty()) {
        return true;
    }
    return false;
}

Base* PreOrderIterator::current() {
    if (!iterators.empty()) {
        return this->iterators.top()->current();
    }
    return NULL;
}