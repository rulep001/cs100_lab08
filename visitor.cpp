#include "composite.h"
#include "visitor.h"
#include <string>
#include <sstream>

using namespace std;

PrintVisitor::PrintVisitor()
{}

void PrintVisitor::rootNode()
{
	return;
}

void PrintVisitor::sqrNode()
{
	output += "^2\n";
}

void PrintVisitor::multNode()
{
	output += "*\n";
}

void PrintVisitor::subNode()
{
	output += "-\n";
}

void PrintVisitor::addNode()
{
	output += "+\n";
}

void PrintVisitor::opNode(Op* op)
{
	ostringstream ss;
	ss << op->evaluate();
	output += ss.str() + '\n';
}

void PrintVisitor::execute()
{

}
