//correct tier1,2,3
#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <iomanip>
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
            if(price <= node->price){
                node = node->left;
            }else{
                node = node->right;
            }
        }
        newNode->parent = parent;
        if(parent != NULL){
            if(price <= parent->price){
                parent->left = newNode;
            }else{
                parent->right = newNode;
            }
        }else{
            root = newNode;
        }
    }
    void inorder(string query,Product *node,queue<Product*> *q){
        if(node->left != NULL){
            inorder(query,node->left,q);
        }
        if(node->name.find(query) != string::npos){
            // cout << node->nameOrigin << " " << node->price << endl;
            q->push(node);
        }
        if(node->right != NULL){
            inorder(query,node->right,q);
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


    string query;
    cin >> query;
    query = lowerString(query);

    queue<Product*> searchResult;
    products.inorder(query,products.root,&searchResult);
    if(searchResult.empty()){
        cout << "-- NONE --" << endl;
    }else{
        while(!searchResult.empty()){
            cout << searchResult.front()->nameOrigin << " " << fixed << setprecision(2 ) << searchResult.front()->price << endl;
            searchResult.pop();
        }
    }

    return 0;
}