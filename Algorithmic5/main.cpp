#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

struct Node {
    string key;
    vector<int> positions;
    struct Node* left, * right;
};

struct Node* newNode(string item, int pos) {
    struct Node* temp = new Node;
    temp->key = item;
    temp->positions.push_back(pos);
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* Node, string key, int pos) {
    if (Node == NULL) return newNode(key, pos);
    if (key < Node->key)
        Node->left = insert(Node->left, key, pos);
    else if (key > Node->key)
        Node->right = insert(Node->right, key, pos);
    else
        Node->positions.push_back(pos);
    return Node;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << ": ";
        for (int i = 0; i < root->positions.size(); i++)
            cout << root->positions[i] << " ";
        cout << endl;
        inorder(root->right);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    struct Node* root = NULL;
    string word;
    int pos = 0;
    ifstream file("input.txt"); // Открытие файла
    while (file >> word) { // Пока есть слова в файле
        root = insert(root, word, pos);
        pos++;
    }
    file.close(); // Закрытие файла
    inorder(root);
    return 0;
}
