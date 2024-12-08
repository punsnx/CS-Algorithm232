#include <iostream>
#include <string>
#include <cctype>
using namespace std;

typedef struct _Product{
    string name;
    string nameOrigin;
    double price; 
    _Product *parent;
    _Product *left;
    _Product *right;
} Product;

string lowerString(string str){
    for(int i = 0;i<str.length();i++){
        str[i] = tolower(str[i]);
    }
    return str;
}
class Tree{
public:
    Product *root;
    Tree(){
        root = NULL;
    }
    Product *createNode(){
        Product *newNode = new Product;
        newNode->parent = NULL;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    void insert(string name,double price){
        Product *newNode = createNode();
        newNode->nameOrigin = name;
        newNode->name = lowerString(name);
        newNode->price = price;

        Product *node = root;
        Product *parent = NULL;
        while(node != NULL){
            parent = node;
            if(newNode->name.compare(node->name) <= 0){
                node = node->left;
            }else{
                node = node->right;
            }
        }
        newNode->parent = parent;
        if(parent != NULL){
            if(newNode->name.compare(parent->name) <= 0){
                parent->left = newNode;
            }else{
                parent->right = newNode;
            }
        }else{
            root = newNode;
        }
    }
    void inorder(Product *node){
        if(node->left != NULL){
            inorder(node->left);
        }
        cout << node->name << " " << node->price << endl;
        if(node->right != NULL){
            inorder(node->right);
        }
    }
    Product *search(string name,Product *node){
        
        if((node == NULL) || name.compare(node->name) == 0 || node->name.find(name) != string::npos){
            return node;
        }
        if(name.compare(node->name) < 0){
            return search(name,node->left);
        }else{
            return search(name,node->right);
        }
    }
    
};

int main(){
    int n;
    cin >> n;
    Tree products;


    for(int i = 0;i<n;i++){
        string name;double price;
        cin >> name >> price;
        products.insert(name,price);
    }

    // products.inorder(products.root);

    string queryItem;
    cin >> queryItem;
    queryItem = lowerString(queryItem);
    Product *result = products.search(queryItem,products.root);
    cout << result->name;

    // string a = "hello";
    // cout << (a.compare("HEllo"));







    return 0;
}