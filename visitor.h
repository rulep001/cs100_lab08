#ifndef __VISITOR_H__
#define __VISITOR_H__

#include "composite.h"
#include <string>

using namespace std;

class Op;

class Visitor {
	public:
		Visitor() {}
		virtual void rootNode() = 0;
		virtual void sqrNode() = 0;
		virtual void multNode() = 0;
		virtual void subNode() = 0;
		virtual void addNode() = 0;
		virtual void opNode(Op* op) = 0;
		virtual void execute() = 0;
};

class PrintVisitor : public Visitor {
    private:
        string output;
    public:
        PrintVisitor();

        void rootNode();    // for visiting root node, do nothing
        void sqrNode();     // for visiting square node
        void multNode();    // for visiting multiple node
        void subNode();     // for visiting subtract node
        void addNode();     // for visiting addition node
        void opNode(Op* op);    // for visiting leaf node

        void execute();
};

#endif
