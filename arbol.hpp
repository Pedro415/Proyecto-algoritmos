#include <vector>
#ifndef __ARBOL_HPP
#define __ARBOL_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include <set>


template <typename keyType>
class bst {
    struct bstNode {
        keyType key;
        std::vector<int> value;
        bool ruc= false;
        bstNode *left;
        bstNode *right;
    };

    size_t count;  // number of nodes: internal and leaves
    bstNode *tree; // root of the binary search tree
    void ordenar(bstNode * & bush, keyType key);
    void insert(bstNode * & bush, keyType key, std::vector<int> y);
    bstNode * find_element(bstNode * bush, keyType key);

    void remove(bstNode * & bush, keyType key);
    bstNode * min(bstNode * bush);
    void search_element(bstNode * & bush, keyType key, int y);
public:
    bst();
    ~bst();
    keyType min();
    void insert(keyType key, std::vector<int> y);
    void ordenar(keyType key);
    bool find_element(keyType key);

    void remove(keyType key);
    void search_element(keyType key, int y);
};

template <typename keyType>
bst<keyType>::bst() {
    tree = nullptr;
    count = 0;
}


template <typename keyType>
bst<keyType>::~bst() {
//    clear();
}

template <typename keyType>
void bst<keyType>::search_element(bstNode * & bush, keyType key, int y) {

    if (bush->key == key) {
        if(bush->ruc==true){
        std::vector<int> v;
        v= bush->value;
        int left = 0, right = v.size()-1;

        while(left <= right){
            int mid = (right+left) / 2;
            if(v[mid] == y){
                std::cout << " el resultado de la busqueda binaria es   " << mid <<std::endl;
                return;
            }
            else{
                if(y > v[mid]){
                    left = mid+1;
                }else{
          right = mid-1;
          }
      }
  }
  std::cout << " el numero no esta " <<std::endl;
  return;
 }



} else {
        if (key != bush->key) {
            if (key < bush->key) {
                search_element(bush->left, key, y);
            } else {
                search_element(bush->right, key, y);
            }
        }
    }

}


template <typename keyType>
void bst<keyType>::search_element(keyType key,int y) {
    search_element(tree, key, y);
}

template <typename keyType>
void bst<keyType>::ordenar(bstNode * & bush, keyType key) {
    if (bush->key == key) {
        std::vector<int> z;
        z = bush->value;
        for(int y=0; y<bush->value.size();y++){
            std::cout<< z[y]<< "  ";
        }
        std::cout<<" "<<std::endl; // Prueba
        for(int i = 0; i < z.size()-1; ++i){
            int po = i;
            for(int j = i+1; j < z.size(); ++j){
                if(z[j] < z[po])
                    po = j;
        }
        int temp = z[i];
        z[i] = z[po];
        z[po] = temp;
    }


        for(int y=0; y<bush->value.size();y++){
            std::cout<< z[y]<< "  ";
        }
        std::cout<<" "<<std::endl; // Prueba
        bush->value=z;
        bush->ruc=true;
    } else {
        if (key != bush->key) {
            if (key < bush->key) {
                ordenar(bush->left, key);
            } else {
                ordenar(bush->right, key);
            }
        }
    }
}

template <typename keyType>
void bst<keyType>::ordenar(keyType key) {
    ordenar(tree, key);
}
template <typename keyType>
void bst<keyType>::insert(bstNode * & bush, keyType key, std::vector<int> y) {
    if (bush == nullptr) {
        count++;
        bush = new bstNode;
        bush->key = key;
        bush ->value=y;
        bush->left = nullptr;
        bush->right = nullptr;
        for(int y=0; y<bush->value.size();y++){
            std::cout<< bush->value[y]<< "  ";
        }
        std::cout<<" "<<std::endl;
    } else {
        if (key != bush->key) {
            if (key < bush->key) {
                insert(bush->left, key, y);
            } else {
                insert(bush->right, key, y);
            }
        }
    }
}


template <typename keyType>
void bst<keyType>::insert(keyType key, std::vector<int> y) {
    insert(tree, key, y);
}


template <typename keyType>
typename bst<keyType>::bstNode * bst<keyType>::find_element(bstNode * bush, keyType key) {
    if (bush == nullptr) return nullptr;
    if (key == bush->key) return bush;

    if (key < bush->key) {
        return find_element(bush->left, key);
    } else {
        return find_element(bush->right, key);
    }
}


template <typename keyType>
bool bst<keyType>::find_element(keyType key) {
    if (find_element(tree, key) != nullptr) {
        return true;
    } else {
        return false;
    }
}



template <typename keyType>
void bst<keyType>::remove(bstNode * & bush, keyType key) {
    if (bush == nullptr) return;

    if (key < bush->key) {
        remove(bush->left, key);
    } else if (key > bush->key) {
        remove(bush->right, key);
    } else if (bush->left == nullptr) {
        bstNode *tmp = bush;
        bush = bush->right;
        delete tmp;
        count--;
    } else if (bush->right == nullptr) {
        bstNode *tmp = bush;
        bush = bush->left;
        delete tmp;
        count--;
    } else if (bush->left != nullptr && bush->right != nullptr) {
        bush->key = min(bush->right)->key;
        remove(bush->right, bush->key);
    }
}


template <typename keyType>
void bst<keyType>::remove(keyType key) {
    remove(tree, key);
}
template <typename keyType>
typename bst<keyType>::bstNode * bst<keyType>::min(bstNode *bush) {
    if (bush == nullptr) {
        return nullptr;
    }
    while (bush->left != nullptr) {
        bush = bush->left;
    }
    return bush;
}

#endif
