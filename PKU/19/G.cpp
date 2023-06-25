// 18:36
// 19:05
#include <iostream>
#include <cstdio>
#include <cstring>

struct node {
    char data;
    node* left;
    node* right;
  public:
    node(char data, node* left, node* right): data(data), left(left), right(right) {}
    void insert(char d) {
        if (d < data) {
            if (left == nullptr) {
                left = new node(d, nullptr, nullptr);
            } else {
                left->insert(d);
            }
        } else {
            if (right == nullptr) {
                right = new node(d, nullptr, nullptr);
            } else {
                right->insert(d);
            }
        }
    }

    void preorderTravesal() {
        printf("%c", data);
        if (left != nullptr) {
            left->preorderTravesal();
        }
        if (right != nullptr) {
            right->preorderTravesal();
        }
    }
};


int main() {
    char inputs[30][30];
    node* root;
    bool end = false;
    while (!end) {
        root = nullptr;
        scanf("%s", inputs[0]);
        int lines = 1;
        while (inputs[lines - 1][0] != '*' && inputs[lines - 1][0] != '$') {
            scanf("%s", inputs[lines]);
            lines++;
        }
        lines--;

        root = new node(inputs[lines - 1][0], nullptr, nullptr);
        
        for (int i = 1; i < lines; i++) {
            char* elems = inputs[lines - 1 - i];
            for (int j = 0; j < strlen(elems); j++) {
                root->insert(elems[j]);
            }
        }

        root->preorderTravesal();
        printf("\n");

        end = inputs[lines][0] == '$';
    }

    return 0;
}