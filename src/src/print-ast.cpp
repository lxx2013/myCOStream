/*这个文件用于编写 输出抽象语法树 所用的函数*/
#include <ctype.h>
#define DEBUG
#include "print-ast.h"
#include <stdio.h>
#include <string.h>

GLOBAL void CharToText(char *array, unsigned char value)
{
  if (value < ' ') {
    static const char *names[32] = {
      "nul","soh","stx","etx","eot","enq","ack","bel",
      "\\b", "\\t", "\\n", "\\v", "ff", "cr", "so", "si",
      "dle","dc1","dc2","dc3","dc4","nak","syn","etb",
      "can","em", "sub","esc","fs", "gs", "rs", "us" };
    sprintf(array, "0x%02x (%s)", value, names[value]);
  } else if (value < 0x7f) {
    sprintf(array, "'%c'", value);
  } else if (value == 0x7f) {
    strcpy(array, "0x7f (del)");
  } else { /* value >= 0x80 */
    sprintf(array, "0x%x", value);
  }
}

GLOBAL short PassCounter = 0;
GLOBAL int PrintInvocations = 0; /* number of pending PrintNodes on call stack */
GLOBAL void PrintNode(FILE *out, Node *node, int offset)
{
  Bool norecurse;
  if (node == NULL)
  {
    fprintf(out, "\n[print-ast.cpp] PrintNode: null");
    return;
  }
  if (PrintInvocations++ == 0)
  {
    /* then we're the first invocation for this pass over the tree */
    ++PassCounter;
  }
  norecurse = (node->pass == PassCounter);
  node->pass = PassCounter;

#define CODE(name, node, union) Print##name(out, node, union, offset, norecurse)
  ASTSWITCH(node, CODE);
#undef CODE
  --PrintInvocations;
}

/*************************************************************************/
/*                          Expression nodes                             */
/*************************************************************************/
PRIVATE void PrintConst(FILE *out, Node *node, ConstNode *u, int offset, Bool norecurse)
{
  fprintf(out, "\nConst: ");
  PrintConstant(out, node, TRUE);
}

/*************************************************************************/
/*                      Low-level output routines                        */
/*************************************************************************/
GLOBAL int PrintConstant(FILE *out, Node *c, Bool with_name)
{
  int len = 0;
  std::string type = std::string(c->u.Const.type); 
  if(type == "Sint")
  {
    debug("I am Sint! My value is:%d\n",c->u.Const.value.i);   
  }
  else if(type == "Double"){
    debug("I am Double! My value is:%lf\n", c->u.Const.value.d);
  }
  else{
    error("[%s:%d]Unrecognized constant type ", __FILE__, __LINE__);
  }
  return 0;
}
PRIVATE void PrintId(FILE *out, Node *node, idNode *u, int offset, Bool norecurse){
  debug("I am PrintId");
}
