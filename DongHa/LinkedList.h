#include "Node.h"
class LinkedList {
private:
  Node _org;
  unsigned int _length;
public:
  LinkedList(): _org(0), _length(0) {}
  ~LinkedList() { clear(); }
  void clear() { while(!isEmpty()) delete remove4clear(0); }
  int size() { return _length; }
  Node* getHead() { return _org.getLink(); }
  bool isEmpty() { return getHead()==NULL; }
  Node* getEntry(int pos) {
    Node* n = &_org;
    for(int i=-1; i<pos; i++, n=n->getLink())
      if ( n == NULL ) break;
    return n;
  }

  void insert(int pos, Node *n) {
    Node* prev = getEntry(pos-1);
    if(prev != NULL ) {
      prev->insertNext(n);
      _length++;
    } 
  }

  Node* remove4clear(int pos) {
    Node* prev = getEntry(pos-1);
    return prev->removeNext();
  }

  bool isValidPosition(int pos) {
    bool val = true;
    if ( pos >= _length )
      val = false;
    
    return val;
  }

  void remove(int pos) {
    if ( isValidPosition(pos) ) {
      Node* prev = getEntry(pos-1);
  	  _length--;
      delete prev->removeNext();
    } else {
      std::cout << "error, remove()" << std::endl;
    }
  }

  void replace(int pos, Node *n) {
    if ( isValidPosition(pos) ) {
  	  Node* prev = getEntry(pos-1);
      prev->removeNext();
      insert(pos, n);
      _length--;
    } else {
      std::cout << "error, replace()" << std::endl;
    }
  }

  void display() {
    printf( "[Length = %2d] : ", size());
    for( Node *p = getHead() ; p != NULL ; p=p->getLink() ) {
      p->display();
      printf(" + ");
		}
    printf("\n");
	}
};
