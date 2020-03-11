#ifndef _TypeDeclaration
#define _TypeDeclaration

#include "./AST/Declaration.h"
#include "./AST/Identifier.h"
#include "./AST/TypeDenoter.h"
#include "SourcePosition.h"
#include <string>
using namespace std;


class TypeDeclaration : public Declaration {

public:
	Identifier* I;
    TypeDenoter* T;

	TypeDeclaration(Identifier* iAST, TypeDenoter* tAST,
		SourcePosition* thePosition): Declaration(thePosition) {
    I = iAST;
    T = tAST;
  }

  Object* visit(Visitor* v, Object* o) {
    return v->visitTypeDeclaration(this, o);
  }

	string class_type(){
		string temp = "TYPEDECLARATION";
		return temp;
	}  
};

#endif

