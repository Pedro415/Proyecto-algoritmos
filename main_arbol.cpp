#include <iostream>
#include <vector>
#include <set>
#include "arbol.hpp"
using namespace std;


int main() {
    std::string msg;
    std::vector<int> t;
    t.push_back(78);


    bst<int> test;

//    Llenando el arbol
    for (int i = 0; i < 10; i++) {
        std::vector<int> t;
        t.push_back(i+1);
        t.push_back((i+2)*2);
        t.push_back(4);
        t.push_back(9);
        int nodo = i;
        std::cout << "number " << nodo << std::endl;
        test.insert(nodo, t);
    }



    test.remove(4);
    for (int i = -9; i <= 9; i++){
        msg = test.find_element(i) ? "true" : "false";
        std::cout << "find: " << i << " " << msg << std::endl;
    }
    test.ordenar(5);
    test.ordenar(6);
    test.ordenar(2);

    test.search_element(2, 4); //solo se imnplementara si esta ordenaado
    test.search_element(2, 8);








    return 0;
}
