#pragma once

#include <iostream>
#include <iomanip>


using std::cout;
using std::setw;


enum class AVLTreeMenu {
    VOID,
    ADDING,
    PRINTING,
    RETURNING
};


struct AVL_Node {
    int info = 0;
    int height = 0;
    AVL_Node* left = {};
    AVL_Node* right = {};
};


class AVLTree {

private:
    AVL_Node* root;


    int height(AVL_Node* AVL_Node) {
        if (AVL_Node == nullptr)
            return 0;
        return AVL_Node->height;
    }


    int max(int a, int b) {
        return (a > b) ? a : b;
    }


    AVL_Node* newAVL_Node(int info) {
        AVL_Node* avl_node = new AVL_Node;
        avl_node->info = info;
        avl_node->left = nullptr;
        avl_node->right = nullptr;
        avl_node->height = 1;
        return avl_node;
    }


    AVL_Node* rightRotate(AVL_Node* pivot_AVL_Node) {
        AVL_Node* new_root = pivot_AVL_Node->left;          // Новый корень поддерева после поворота
        AVL_Node* subtree_to_move = new_root->right;    // Поддерево, которое перемещается в результате поворота

        // Поворот
        new_root->right = pivot_AVL_Node;
        pivot_AVL_Node->left = subtree_to_move;

        // Обновляем высоты узлов
        pivot_AVL_Node->height = max(height(pivot_AVL_Node->left), height(pivot_AVL_Node->right)) + 1;
        new_root->height = max(height(new_root->left), height(new_root->right)) + 1;

        return new_root;
    }


    AVL_Node* leftRotate(AVL_Node* new_root) {
        AVL_Node* pivot_AVL_Node = new_root->right;         // Узел, вокруг которого происходит поворот
        AVL_Node* subtree_to_move = pivot_AVL_Node->left;   // Поддерево, которое перемещается в результате поворота

        // Поворот
        pivot_AVL_Node->left = new_root;
        new_root->right = subtree_to_move;

        // Обновляем высоты узлов
        new_root->height = max(height(new_root->left), height(new_root->right)) + 1;
        pivot_AVL_Node->height = max(height(pivot_AVL_Node->left), height(pivot_AVL_Node->right)) + 1;

        return pivot_AVL_Node;
    }


    int getBalance(AVL_Node* AVL_Node) {
        if (AVL_Node == nullptr)
            return 0;
        return height(AVL_Node->left) - height(AVL_Node->right);
    }


    AVL_Node* insert(AVL_Node* AVL_Node, int info) {
        if (AVL_Node == nullptr)
            return newAVL_Node(info);

        if (info < AVL_Node->info)
            AVL_Node->left = insert(AVL_Node->left, info);
        else if (info > AVL_Node->info)
            AVL_Node->right = insert(AVL_Node->right, info);
        else
            return AVL_Node;

        // Обновляем высоту текущего узла
        AVL_Node->height = 1 + max(height(AVL_Node->left), height(AVL_Node->right));

        // Получаем коэффициент балансировки текущего узла
        int balance = getBalance(AVL_Node);

        // Перебалансировка дерева, если необходимо
        if (balance > 1 && info < AVL_Node->left->info)
            return rightRotate(AVL_Node);

        if (balance < -1 && info > AVL_Node->right->info)
            return leftRotate(AVL_Node);

        if (balance > 1 && info > AVL_Node->left->info) {
            AVL_Node->left = leftRotate(AVL_Node->left);
            return rightRotate(AVL_Node);
        }

        if (balance < -1 && info < AVL_Node->right->info) {
            AVL_Node->right = rightRotate(AVL_Node->right);
            return leftRotate(AVL_Node);
        }

        return AVL_Node;
    }


public:

    AVLTree() : root(nullptr) {}


    void insert(int info) {
        root = insert(root, info);
    }


    void insert() {
        // 2 0 1 6 3 4 5    - условие Варианта №4
        insert(2);
        showSymmetricalOrder();
        

        insert(0);
        showSymmetricalOrder();


        insert(1);
        showSymmetricalOrder();


        insert(6);
        showSymmetricalOrder();


        insert(3);
        showSymmetricalOrder();


        insert(4);
        showSymmetricalOrder();


        insert(5);
        showSymmetricalOrder();
    }


    void showDirectOrder(AVL_Node* AVL_Node, int indent) {
        double width = 7;

        if (AVL_Node != nullptr) {
            cout << "\t\t\t\t" << setw(indent) << AVL_Node->info << " (" << getBalance(AVL_Node) << ")" << '\n';
            showDirectOrder(AVL_Node->left, indent + 6);
            showDirectOrder(AVL_Node->right, indent + 6);
        }
        else {
            cout << "\t\t\t\t" << setw(indent + width) << "- nullptr" << '\n';
        }
    }


    void showDirectOrder(int indent = 5) {
        double width = 5;

        if (root != nullptr) {
            cout << "\t\t\t\t" << setw(indent + width) << root->info << " (" << getBalance(root) << ")" << '\n';
            showDirectOrder(root->left, indent + 12);
            showDirectOrder(root->right, indent + 12);
        }
        else {
            cout << "\t\t\t\tДерево пустое :(" << '\n';
        }
    }


    void showSymmetricalOrder(AVL_Node* AVL_Node, int indent) {
        double width = 7;

        if (AVL_Node != nullptr) {
            showSymmetricalOrder(AVL_Node->left, indent + 6);
            cout << "\t\t\t\t" << setw(indent) << AVL_Node->info << " (" << getBalance(AVL_Node) << ")" << '\n';
            showSymmetricalOrder(AVL_Node->right, indent + 6);
        }
        else {
            cout << "\t\t\t\t" << setw(indent + width) << "- nullptr" << '\n';
        }
    }


    void showSymmetricalOrder(int indent = 5) {
        double width = 5;

        if (root != nullptr) {
            showSymmetricalOrder(root->left, indent + 12);
            cout << "\t\t\t\t" << setw(indent + width) << root->info << " (" << getBalance(root) << ")" << '\n';
            showSymmetricalOrder(root->right, indent + 12);
        }
        else {
            cout << "\t\t\t\tДерево пустое :(" << '\n';
        }

        cout << "\n--------------------------------------------------------------------------------------------------------------\n\n";
    }


    void showReverseOrder(AVL_Node* AVL_Node, int indent) {
        double width = 7;

        if (AVL_Node != nullptr) {
            showReverseOrder(AVL_Node->left, indent + 6);
            showReverseOrder(AVL_Node->right, indent + 6);
            cout << "\t\t\t\t" << setw(indent) << AVL_Node->info << " (" << getBalance(AVL_Node) << ")" << '\n';
        }
        else {
            cout << "\t\t\t\t" << setw(indent + width) << "- nullptr" << '\n';
        }
    }


    void showReverseOrder(int indent = 5) {
        double width = 5;

        if (root != nullptr) {
            showReverseOrder(root->left, indent + 12);
            showReverseOrder(root->right, indent + 12);
            cout << "\t\t\t\t" << setw(indent + width) << root->info << " (" << getBalance(root) << ")" << '\n';
        }
        else {
            cout << "\t\t\t\tДерево пустое :(" << '\n';
        }
    }

};