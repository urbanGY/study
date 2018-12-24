#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
  string idName;
  string className;

  float width;
  float height;
  float marginTop;
  float marginBottom;
  float marginLeft;
  float marginRight;

  string text;

  Node * child;
  Node * sibling;
public:
  Node(string idName,string className, float width, float height, float marginTop, float marginBottom, float marginLeft, float marginRight)
  :idName(name), className(className), width(width), height(height), marginTop(marginTop), marginBottom(marginBottom), marginLeft(marginLeft), marginRight(marginRight), child(NULL), sibling(NULL)
  {
    cout<<"construct node!"<<endl;
  }
  ~Node()
  {
    cout<<"remove node!"<<endl;
  }
  void setChild(Node * node)
  {
    this->child = node;
  }
  Node * getNextChild(void)
  {
    return this->child;
  }
  
  void setSibling(Node * node)
  {
    this->sibling = node;
  }
  Node * getNextSibling(void)
  {
    return this->sibling;
  }
};

 int main(void){


   return 0;
 }
