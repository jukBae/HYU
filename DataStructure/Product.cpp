#include <iostream>
#include <string>

using std::string;
using std::ws;
using std::cin;
using std::cout;
using std::endl;

class Product {
private:
  string mName;
  unsigned int mPrice;
  string mEvaluation;
public:
  Product();
  ~Product() {};
  //getter
  string getName() { return mName; }
  unsigned int getPrice() { return mPrice; }
  string getEvaluation() { return mEvaluation; }
  //setter
  bool setName(string name);
  bool setPrice(int price);
  bool setEvaluation(string evaluation);
  //method
  bool setAllVars();
  void comparePrice(Product x, Product y);
  void printProduct();
};

Product::Product() {
  mName = "noName";
  mPrice = 0;
  mEvaluation = "noEvaluation";
}

bool Product::setName(string name) {
  mName = name;

  return true;
}

bool Product::setPrice(int price) {
  if ( price < 0 )  //Price cannot be minus data
    return false;
  
  mPrice = price;

  return true;
}

bool Product::setEvaluation(string evaluation) {
  mEvaluation = evaluation;

  return true;
}

bool Product::setAllVars() {
  int tmpPrice;
  cout << "Fill out following information" << endl;

  cout << "Enter name : ";
  ws(cin);
  getline(cin, mName);

  cout << "Enter price : ";
  cin >> tmpPrice;
  if (tmpPrice < 0) {    // Price cannot be minus data.
    cout << "You tried to enter invalid data." << endl;
    return false;
  }
  mPrice = tmpPrice;

  cout << "Enter evaluation : ";
  ws(cin);
  getline(cin, mEvaluation);

  return true;
}

void Product::comparePrice(Product x, Product y) {
  int xPrice = x.getPrice();
  int yPrice = y.getPrice();

  if (xPrice > yPrice)
    cout << "First thing is greater than second thing" << endl;
  else if (xPrice == yPrice)
    cout << "It's same price" << endl;
  else
    cout << "Second thing is greater than first thing" << endl;
}

void Product::printProduct() {
  cout << "Name : " << mName << endl;
  cout << "Price : " << mPrice << endl;
  cout << "Evaluation : " << mEvaluation << endl;
}

void main() {
  Product p1, p2;

  // loop for testing
  while (1) {
    if (p1.setAllVars())
      p1.printProduct();  
    cout << "-------------------\n";
    if (p2.setAllVars()) 
      p2.printProduct();
    cout << "-------------------\n";

    p1.comparePrice(p1, p2);
    cout << "-------------------\n";
  }
}
