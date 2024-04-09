#pragma once

#include <iostream>
#include <iomanip>  // Включение стандартной библиотеки для манипуляций с выводом


using std::cout;
using std::cin;
using std::setw;


enum class BinaryTreeMenu {
    VOID,
    ADDING,
    SEARCHING,
    REMOVING,
    REMOVING_ALL,
    PRINTING,
    RETURNING
};


struct Node {
    int info = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

/*
Обход дерева сверху вниз (в прямом порядке): A, B, C - префиксная форма.
Обход дерева в симметричном порядке (слева направо): B, A, C - инфиксная форма.
Обход дерева в обратном порядке (снизу вверх): B, C, A - постфиксная форма.
*/

/*
void BinarySearchTreeprint(tnode* BinarySearchTree) {
  if (BinarySearchTree != NULL) { //Пока не встретится пустой узел
    cout << BinarySearchTree->field; //Отображаем корень дерева
    BinarySearchTreeprint(BinarySearchTree->left); //Рекурсивная функция для левого поддерева
    BinarySearchTreeprint(BinarySearchTree->right); //Рекурсивная функция для правого поддерева
  }
}

void BinarySearchTreeprint(tnode* BinarySearchTree) {
  if (BinarySearchTree != NULL) { //Пока не встретится пустой узел
    BinarySearchTreeprint(BinarySearchTree->left); //Рекурсивная функция для левого поддерева
    cout << BinarySearchTree->field; //Отображаем корень дерева
    BinarySearchTreeprint(BinarySearchTree->right); //Рекурсивная функция для правого поддерева
  }
}

void BinarySearchTreeprint(tnode* BinarySearchTree) {
  if (BinarySearchTree != NULL) { //Пока не встретится пустой узел
    BinarySearchTreeprint(BinarySearchTree->left); //Рекурсивная функция для левого поддерева
    BinarySearchTreeprint(BinarySearchTree->right); //Рекурсивная функция для правого поддерева
    cout << BinarySearchTree->field; //Отображаем корень дерева
  }
}

*/

class BinarySearchTree {

    Node* root = nullptr; // Указатель на корневой узел
    bool is_tree_empty = true;
    bool is_finded = true;

public:

    BinarySearchTree() {
        cout << "\t\t\t\tДерево создано :)" << '\n';
    }

    BinarySearchTree(int root) {
        this->root = new Node; // Создание нового корневого узла
        this->root->info = root; // Присвоение значению корневого узла
    }

    ~BinarySearchTree() {
        remove_all();
        cout << "\n\t\t\t\tДерево удалено :(" << '\n';
    }


    void add(int info) {
        if (root == nullptr) {
            root = new Node; // Создание нового корневого узла
            root->info = info; // Присвоение значению корневого узла
        }
        else {
            root = add(info, root); // Добавление узла
        }

        is_tree_empty = false;
    }


    Node* add(int info, Node* BinarySearchTree) {
        // Рекурсивное добавление узла в дерево
        if (BinarySearchTree == nullptr) {
            BinarySearchTree = new Node;
            BinarySearchTree->info = info;
        }
        else  if (info < BinarySearchTree->info) BinarySearchTree->left = add(info, BinarySearchTree->left);
        else  if (info > BinarySearchTree->info) BinarySearchTree->right = add(info, BinarySearchTree->right);
        else cout << "\t\t\t\tПовторилось, " << info << " уже есть." << '\n';

        return BinarySearchTree;
    }


    // Методы удаления узлов из дерева
    void dell(Node* BinarySearchTree) {
        // Рекурсивное удаление узлов из дерева
        if (BinarySearchTree != nullptr) {
            dell(BinarySearchTree->left);
            dell(BinarySearchTree->right);
            delete BinarySearchTree; // Удаление текущего узла
            BinarySearchTree = nullptr;
        }
    }


    //void dell(int info, Node* BinarySearchTree, Node* BinarySearchTree_pred, char leftOrRight) {
    //    // Удаление узла по значению
    //    if (BinarySearchTree == nullptr) {
    //        cout << "\t\t\t\tУдаление невозможно, элемент отсутствует :(" << '\n';
    //    }
    //    else {
    //        if (info == BinarySearchTree->info) {
    //            dell(BinarySearchTree->left);
    //            dell(BinarySearchTree->right);
    //            delete BinarySearchTree;

    //            switch (leftOrRight) {
    //            case 'l': BinarySearchTree_pred->left = nullptr; break;
    //            case 'r': BinarySearchTree_pred->right = nullptr; break;
    //            default: cout << "\t\t\t\tError."; break;
    //            }
    //        }
    //        else if (info < BinarySearchTree->info) dell(info, BinarySearchTree->left, BinarySearchTree, 'l');
    //        else if (info > BinarySearchTree->info) dell(info, BinarySearchTree->right, BinarySearchTree, 'r');
    //        else cout << "\t\t\t\tError." << '\n';
    //    }
    //}


    void erase(int info) {
        Node* curr = root;
        Node* parent = nullptr;

        // Поиск узла для удаления
        while (curr && curr->info != info) {
            parent = curr;
            if (info < curr->info)
                curr = curr->left;
            else
                curr = curr->right;
        }

        // Если узел не найден, возвращаемся
        if (!curr)
            return;

        // Удаление узла с одним или без потомков
        if (curr->left == nullptr || curr->right == nullptr) {
            Node* child = (curr->left != nullptr) ? curr->left : curr->right;

            if (parent == nullptr) {
                root = child; // Обновляем корень, если удаляемый узел был корнем
            }
            else {
                if (parent->left == curr)
                    parent->left = child;
                else
                    parent->right = child;
            }
            delete curr;
            return;
        }

        // Удаление узла с двумя потомками
        Node* replace = curr->right;
        while (replace->left)
            replace = replace->left;
        int replace_value = replace->info;
        erase(replace_value); // Рекурсивно удаляем наименьший элемент из правого поддерева
        curr->info = replace_value;

        is_tree_empty = true;
    }


    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    void remove_all() {
        destroyTree(root);
        root = nullptr;
    }


    void search(int info) {
        if (root == nullptr) {
            is_finded = false;
        }
        else if (info == root->info) {
            is_finded = true;
        }
        else if (info < root->info) return search(info, root->left);
        else if (info > root->info) return search(info, root->right);
        else {
            cout << "\t\t\t\tError." << '\n';
            is_finded = false;
        }

        if (is_finded) {
            cout << "Найден!\n";
        }
        else { cout << "НЕ найден!\n"; }
    }


    void search(int info, Node* BinarySearchTree) {

        if (BinarySearchTree == nullptr) {
            is_finded = false;
        }
        else if (info == BinarySearchTree->info) {
            is_finded = true;
        }
        else if (info < BinarySearchTree->info) return search(info, BinarySearchTree->left);
        else if (info > BinarySearchTree->info) return search(info, BinarySearchTree->right);
        else {
            cout << "\t\t\t\tError." << '\n';
            is_finded = false;
        }

        if (is_finded) {
            cout << "Найден!\n";
        }
        else { cout << "НЕ найден!\n"; }

    }


    void showDirectOrder(Node* BinarySearchTree, int indent) {
        double width = 7;

        if (BinarySearchTree != nullptr) {
            cout << "\t\t\t\t" << setw(indent) << BinarySearchTree->info << /*" " << BinarySearchTree << " " << BinarySearchTree->left << " " << BinarySearchTree->right <<*/ '\n';
            showDirectOrder(BinarySearchTree->left, indent + 6);
            showDirectOrder(BinarySearchTree->right, indent + 6);
        }
        else {
            cout << "\t\t\t\t" << setw(indent + width) << "- nullptr" << '\n';
        }
    }


    void showDirectOrder(int indent = 5) {
        double width = 5;

        if (root != nullptr) {
            cout << "\t\t\t\t" << setw(indent + width) << root->info << /*" " << root << " " << root->left << " " << root->right <<*/ '\n';
            showDirectOrder(root->left, indent + 12);
            showDirectOrder(root->right, indent + 12);
        }
        else {
            cout << "\t\t\t\tДерево пустое :(" << '\n';
        }
    }


    void showSymmetricalOrder(Node* BinarySearchTree, int indent) {
        double width = 7;
        //cout << is_tree_empty;

        if (BinarySearchTree != nullptr && !is_tree_empty) {
            showSymmetricalOrder(BinarySearchTree->left, indent + 6);
            cout << "\t\t\t\t" << setw(indent) << BinarySearchTree->info << /*" " << BinarySearchTree << " " << BinarySearchTree->left << " " << BinarySearchTree->right <<*/ '\n';
            showSymmetricalOrder(BinarySearchTree->right, indent + 6);
        }
        else {  
            cout << "\t\t\t\t" << setw(indent + width) << "- nullptr" << '\n';
        }
    }


    void showSymmetricalOrder(int indent = 5) {
        double width = 5;

        if (root != nullptr) {
            showSymmetricalOrder(root->left, indent + 12);
            cout << "\t\t\t\t" << setw(indent + width) << root->info << /*" " << root << " " << root->left << " " << root->right <<*/ '\n';
            showSymmetricalOrder(root->right, indent + 12);
        }
        else {
            cout << "\t\t\t\tДерево пустое :(" << '\n';
        }
    }


    void showReverseOrder(Node* BinarySearchTree, int indent) {
        double width = 5;

        if (BinarySearchTree != nullptr) {
            showReverseOrder(BinarySearchTree->left, indent + 6);
            showReverseOrder(BinarySearchTree->right, indent + 6);
            cout << "\t\t\t\t" << setw(indent) << BinarySearchTree->info << /*" " << BinarySearchTree << " " << BinarySearchTree->left << " " << BinarySearchTree->right <<*/ '\n';
        }
        else {
            cout << "\t\t\t\t" << setw(indent + width) << "- nullptr" << '\n';
        }
    }


    void showReverseOrder(int indent = 5) {
        double width = 7;

        if (root != nullptr) {
            showReverseOrder(root->left, indent + 12);
            showReverseOrder(root->right, indent + 12);
            cout << "\t\t\t\t" << setw(indent + width) << root->info << /*" " << root << " " << root->left << " " << root->right <<*/ '\n';
        }
        else {
            cout << "\t\t\t\tДерево пустое :(" << '\n';
        }
    }


    void input_value(int& value) {
        cout << "Введите значение узла --> ";   cin >> value;   cout << '\n';
    }
};