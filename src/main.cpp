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
#include "AVL.h"

int main(){

	AVL avl = AVL();
    
    for (int i = 0; i < 1000; i++)
    {
        avl.insert(i);
    }
    

    std::cout << avl << std::endl;
    std::cout << std::boolalpha << "Is empty: " << avl.isEmpty() << std::endl;
    std::cout << std::boolalpha << "Is balanced: " << avl.balanced() << std::endl;
    std::cout << "Height: " << avl.getHeight() << std::endl;
    std::cout << "Done!" << std::endl;

    return 0;
}