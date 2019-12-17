#include "../header/Tree.h"
#include <iostream>

using namespace std;

void printOrders(Tree *);

int menu();

int main() {

    Tree tree;
    cout << "2-3 Tree, supports string" << endl;
    int choice = menu();

    string entry;

    while (choice != 4) {
        if (choice == 1) {
            cout << "Enter element to insert: ";
            getline(cin, entry);
            cout << endl;

            tree.insert(entry);

        }
            /*
            else if (choice == 2) {
              cout << "Enter movie title to remove: ";
              getline(cin, entry);
              cout << endl;

              tree.remove(entry);

            } */
        else if (choice == 2) {
            printOrders(&tree);
        } else if (choice == 3) {
            cout << "Enter element to search for: ";
            getline(cin, entry);
            cout << endl;

            if (tree.search(entry)) {
                cout << entry << " Found" << endl;
            } else {
                cout << entry << " Not Found" << endl;
            }
        }


        //fix buffer just in case non-numeric choice entered
        choice = menu();
    }

    cout << "End of Program" << endl;
    return 0;
}

void printOrders(Tree *tree) {
    cout << "Preorder = ";
    tree->preOrder();
    cout << "Inorder = ";
    tree->inOrder();
    cout << "Postorder = ";
    tree->postOrder();
}

int menu() {
    int choice = 0;

    cout << "Enter menu choice: ";
    cout << endl;
    cout
            << "1. Insert" << endl
            // << "2. Remove" << endl
            << "2. Print" << endl
            << "3. Search" << endl
            << "4. Quit" << endl;
    cin >> choice;

    // fix buffer just in case non-numeric choice entered
    // also gets rid of newline character
    cin.clear();
    cin.ignore(256, '\n');
    return choice;
}