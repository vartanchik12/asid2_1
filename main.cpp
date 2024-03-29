#include<bintree.h>
#include<iomanip>

int main()
{
    BinSearchTree<int> tree1;
    BinSearchTree<int> tree2;
    tree1.insert(5);
    tree1.insert(7);
    tree1.insert(10);
    tree1.insert(8);
    tree2.insert(5);
    tree2.insert(7);
    tree2.insert(100);
    tree2.insert(80);
    tree1.insert(11);

    tree1.print();
    cout << "\n";
    tree2.print();
    cout << "\n";
    unificationTrees(tree1, tree2);
    cout << "\n";
    BinDifferenceTrees(tree1, tree2);


}