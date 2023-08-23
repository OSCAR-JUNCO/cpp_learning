#include <iostream>
#include <string>

#include "recursion.h"
#include "functions.h"
#include "array_recursion.h"
#include "patterns.h"
#include "templates.h"
#include "sort.h"
#include "pr_unpr.h"
#include "binary_tree.h"
#include "BST.h"

int main(){
    vector<int> nums {5, 2, 7, 1, 4, 6, 9, 8, 3, 10 };
    vector<int> numsSorted {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	BST bst = BST();
    bst.populateSorted(numsSorted);
    bst.display();
    std::cout << std::boolalpha << "Is empty: " << bst.isEmpty() << std::endl;
    std::cout << std::boolalpha << "Is balanced: " << bst.balanced() << std::endl;
    std::cout << "Pre-order traversal:  ";
    bst.preOrder();
    std::cout << "In-order traversal:   ";
    bst.inOrder();
    std::cout << "Post-order traversal: ";
    bst.postOrder();
    

    std::cout << "Done!" << std::endl;

    return 0;
}