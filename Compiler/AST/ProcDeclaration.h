#ifndef _ProcDeclaration
#define _ProcDeclaration


#include "./AST/Declaration.h"
#include "./AST/Identifier.h"
#include "./AST/FormalParameterSequence.h"
#include "./AST/Command.h"
#include "SourcePosition.h"
#include <string>
using namespace std;

class ProcDeclaration : public Declaration {

public:
  Identifier* I;
  FormalParameterSequence* FPS;
  Command* C;

	ProcDeclaration (Identifier* iAST, FormalParameterSequence* fpsAST,
		Command* cAST, SourcePosition* thePosition): Declaration(thePosition){
    I = iAST;
    FPS = fpsAST;
    C = cAST;
  }
  
  Object* visit (Visitor* v, Object* o) {
    return v->visitProcDeclaration(this, o);
  }

	string class_type(){
		string temp = "PROCDECLARATION";
		return temp;
	}  
};

#endif

