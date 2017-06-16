#include "LinkedList.h"

class SparsePoly {
private:
  LinkedList polyList;
public:
  SparsePoly() {}
  ~SparsePoly() {}

  void setSparsePoly() {
    int n;
    double coef;
    int degree;
    Node* tNode;

    std::cout << "Enter number = ";
    std::cin >> n;
    for ( int i = 0; i < n; i++ ) {
      std::cout << i+1 << ": coef degree = ";
      std::cin >> coef;
      std::cin >> degree;

      tNode = new Node(coef, degree);
      polyList.insert(i, tNode);
    }
  }

  void addFrom(SparsePoly * b) {
    int pos = -1;
    Node * tNode;
    Node * bNode;
 
    for ( int i = 0; i < b->size(); i++ ) {
      bNode = b->getNodeAt(i);
   
      pos = 0;
      for ( int i = 0; i < polyList.size(); i++ ) {
        tNode = polyList.getEntry(i);
        if ( tNode->getDegree() >= bNode->getDegree() )
          pos = i+1;
      }
      
      if ( polyList.getEntry(pos-1)->getDegree() == bNode->getDegree() ) {
        tNode = polyList.getEntry(pos-1);
        tNode->setCoef(tNode->getCoef() + bNode->getCoef());
      } else {
        tNode = new Node(bNode->getCoef(), bNode->getDegree());
        polyList.insert(pos, tNode);
      }
    }
  }

  Node *getNodeAt(int pos) { return polyList.getEntry(pos); }
  void display() { polyList.display(); }
  int size() { return polyList.size(); }
};

int main() {
  SparsePoly a, b;
  a.setSparsePoly();
  b.setSparsePoly();

  std::cout << " A : ";
  a.display();

  a.addFrom(&b);

  std::cout << " B : ";
  b.display();
  std::cout << "A+B : ";
  a.display();

  return 0;
}
