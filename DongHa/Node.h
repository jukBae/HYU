#include <iostream>
class Node {
private:
  double _coef;
  int _degree;
  Node * link;
public:
  Node(double coef=0, int degree=0) {
    _coef = coef;
    _degree = degree;
    link = NULL;
  }
  Node* getLink() { return link; }
	void setLink(Node* next) { link=next; }
  void setDegree(int val) { _degree = val; }
  void setCoef(int val) { _coef = val; }
  int getDegree() { return _degree; }
  double getCoef() { return _coef; }
  void display() { printf("%.1f x^%d", _coef, _degree); }
  bool hasDegree(int val) { return _degree == val;}
  void insertNext( Node *n ) {
    if ( n != NULL ) {
      n->link = link;
      link = n;
    }
  }
  Node* removeNext() {
    Node* removed = link;
    if ( removed != NULL )
      link = removed->link;
    return removed;
  }
};
