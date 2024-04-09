#pragma once

#include <iostream>
#include <iomanip>  // ��������� ����������� ���������� ��� ����������� � �������


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
����� ������ ������ ���� (� ������ �������): A, B, C - ���������� �����.
����� ������ � ������������ ������� (����� �������): B, A, C - ��������� �����.
����� ������ � �������� ������� (����� �����): B, C, A - ����������� �����.
*/

/*
void BinarySearchTreeprint(tnode* BinarySearchTree) {
  if (BinarySearchTree != NULL) { //���� �� ���������� ������ ����
    cout << BinarySearchTree->field; //���������� ������ ������
    BinarySearchTreeprint(BinarySearchTree->left); //����������� ������� ��� ������ ���������
    BinarySearchTreeprint(BinarySearchTree->right); //����������� ������� ��� ������� ���������
  }
}

void BinarySearchTreeprint(tnode* BinarySearchTree) {
  if (BinarySearchTree != NULL) { //���� �� ���������� ������ ����
    BinarySearchTreeprint(BinarySearchTree->left); //����������� ������� ��� ������ ���������
    cout << BinarySearchTree->field; //���������� ������ ������
    BinarySearchTreeprint(BinarySearchTree->right); //����������� ������� ��� ������� ���������
  }
}

void BinarySearchTreeprint(tnode* BinarySearchTree) {
  if (BinarySearchTree != NULL) { //���� �� ���������� ������ ����
    BinarySearchTreeprint(BinarySearchTree->left); //����������� ������� ��� ������ ���������
    BinarySearchTreeprint(BinarySearchTree->right); //����������� ������� ��� ������� ���������
    cout << BinarySearchTree->field; //���������� ������ ������
  }
}

*/

class BinarySearchTree {

    Node* root = nullptr; // ��������� �� �������� ����
    bool is_tree_empty = true;
    bool is_finded = true;

public:

    BinarySearchTree() {
        cout << "\t\t\t\t������ ������� :)" << '\n';
    }

    BinarySearchTree(int root) {
        this->root = new Node; // �������� ������ ��������� ����
        this->root->info = root; // ���������� �������� ��������� ����
    }

    ~BinarySearchTree() {
        remove_all();
        cout << "\n\t\t\t\t������ ������� :(" << '\n';
    }


    void add(int info) {
        if (root == nullptr) {
            root = new Node; // �������� ������ ��������� ����
            root->info = info; // ���������� �������� ��������� ����
        }
        else {
            root = add(info, root); // ���������� ����
        }

        is_tree_empty = false;
    }


    Node* add(int info, Node* BinarySearchTree) {
        // ����������� ���������� ���� � ������
        if (BinarySearchTree == nullptr) {
            BinarySearchTree = new Node;
            BinarySearchTree->info = info;
        }
        else  if (info < BinarySearchTree->info) BinarySearchTree->left = add(info, BinarySearchTree->left);
        else  if (info > BinarySearchTree->info) BinarySearchTree->right = add(info, BinarySearchTree->right);
        else cout << "\t\t\t\t�����������, " << info << " ��� ����." << '\n';

        return BinarySearchTree;
    }


    // ������ �������� ����� �� ������
    void dell(Node* BinarySearchTree) {
        // ����������� �������� ����� �� ������
        if (BinarySearchTree != nullptr) {
            dell(BinarySearchTree->left);
            dell(BinarySearchTree->right);
            delete BinarySearchTree; // �������� �������� ����
            BinarySearchTree = nullptr;
        }
    }


    //void dell(int info, Node* BinarySearchTree, Node* BinarySearchTree_pred, char leftOrRight) {
    //    // �������� ���� �� ��������
    //    if (BinarySearchTree == nullptr) {
    //        cout << "\t\t\t\t�������� ����������, ������� ����������� :(" << '\n';
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

        // ����� ���� ��� ��������
        while (curr && curr->info != info) {
            parent = curr;
            if (info < curr->info)
                curr = curr->left;
            else
                curr = curr->right;
        }

        // ���� ���� �� ������, ������������
        if (!curr)
            return;

        // �������� ���� � ����� ��� ��� ��������
        if (curr->left == nullptr || curr->right == nullptr) {
            Node* child = (curr->left != nullptr) ? curr->left : curr->right;

            if (parent == nullptr) {
                root = child; // ��������� ������, ���� ��������� ���� ��� ������
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

        // �������� ���� � ����� ���������
        Node* replace = curr->right;
        while (replace->left)
            replace = replace->left;
        int replace_value = replace->info;
        erase(replace_value); // ���������� ������� ���������� ������� �� ������� ���������
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
            cout << "������!\n";
        }
        else { cout << "�� ������!\n"; }
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
            cout << "������!\n";
        }
        else { cout << "�� ������!\n"; }

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
            cout << "\t\t\t\t������ ������ :(" << '\n';
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
            cout << "\t\t\t\t������ ������ :(" << '\n';
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
            cout << "\t\t\t\t������ ������ :(" << '\n';
        }
    }


    void input_value(int& value) {
        cout << "������� �������� ���� --> ";   cin >> value;   cout << '\n';
    }
};