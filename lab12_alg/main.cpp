#include <iostream>

using namespace std;

struct node{
    int value;
    node* parent;
    node*left;
    node* right;
};

int isEmpty(struct node* tree){
    if(tree == nullptr){
        return 1;
    }else{
        return 0;
    }
}

node* makeNode(int value){
    node*temp = new struct node;
    temp->value = value;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->parent = nullptr;
    return temp;
}

int createKnot(struct node*& root, int value){
    node*temp = new struct node;
    if(isEmpty(root)){
        root = makeNode(value);
        return root->value;
    }else{
        temp = root;
        while(true){
            if(value>temp->value){
                if(temp->right == nullptr){
                    temp->right =makeNode(value);
                    temp->right->parent =temp;
                    return temp->value;
                }else{
                    temp=temp->right;
                }
            }else{
                if(temp->left == nullptr){
                    temp->left =makeNode(value);
                    temp->left->parent =temp;
                    return temp->value;
                }else{
                    temp=temp->left;
                }
            }
        }
    }
}

node* isExist(struct node* root, int value){
    while(root!= nullptr){
        if(root->value==value){
            return root;
        }
        if(root->value<value){
            root=root->right;
        }else{
            root=root->left;
        }
    }
}

void preorder(struct node* root){
    if(root != nullptr){
        cout<<root->value<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->value<<endl;
}

void inorder(struct node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->value<<endl;
    inorder(root->right);
}

node* findSuccessor(struct node* n){
    node*temp = new struct node;
    if(n->right != nullptr){
        n=n->right;
        while(n->left!= nullptr){
            n=n->left;
        }
        return n;
    }
    temp = n->parent;
    while(temp!= nullptr && temp->left!=n){
        n=temp;
        temp=temp->parent;
    }
    return temp;
}

void deleteNode(node* root,node* delete_node)
{
    node *temp1,*temp2;
    if(delete_node->left==nullptr or delete_node->right==nullptr)
        temp1=delete_node;
    else
        temp1=findSuccessor(delete_node);
    if(temp1->left!=nullptr)
        temp2=temp1->left;
    else
        temp2=temp1->right;
    if(temp2!=nullptr)
        temp2->parent=temp1->parent;
    if(temp1->parent==nullptr)
        root=temp2;
    else if(temp1==temp1->parent->left)
        temp1->parent->left=temp2;
    else
        temp1->parent->right=temp2;
    if(temp1!=delete_node)
        delete_node->value=temp1->value;
    delete temp1;
}

int main() {

    node*tree= nullptr;
    node*temp= nullptr;
    int result;
    int value;
    while (true)
    {
        cout << endl;
        cout << "Sprawdzenie czy drzewo jest puste - 1" << endl;
        cout << "Dodanie nowego węzła do drzewa - 2" << endl;
        cout << "Sprawdzenie  czy  klucz  o  podanej  wartości znajduje  się wdrzewie - 3" << endl;
        cout << "Wyświetlenie drzewa –preorder - 4" << endl;
        cout << "Wyświetlenie drzewa –inorder - 5" << endl;
        cout << "Wyświetlenie drzewa –postorder - 6" << endl;
        cout << "Usunięcie węzła o podanej wartości klucza - 7" << endl;
        cout << "Usunięcie  całego  drzewa - 8" << endl;
        cout << "Wyjście z programu - 9" << endl;
        cout << "Wprowadz numer: ";

        int choise = 0;
        cin >> choise;

        switch (choise)
        {
            case 1:
                result = isEmpty(tree);
                if(result == 1){
                    cout<<"Drzewo puste"<<endl;
                }else{
                    cout<<"Drzewo nie puste"<<endl;
                }
                break;
            case 2:
                cout<<"Proszę podać klucz: "<<endl;
                cin>>value;
                cout<<"Przez: "<<endl;
                inorder(tree);
                createKnot(tree, value);
                cout<<"Po: "<<endl;
                inorder(tree);
                break;
            case 3:
                cout<<"Proszę podać klucz: "<<endl;
                cin>>value;
                temp = isExist(tree, value);
                if(temp!= nullptr){
                    cout<<"Istnieje taki klucz"<<endl;
                }else{
                    cout<<"Nie istnieje takiego klucza"<<endl;
                }
                break;
            case 4:
                preorder(tree);
                break;
            case 5:
                inorder(tree);
                break;
            case 6:
                postorder(tree);
                break;
            case 7:
                cout<<"Proszę podać klucz: "<<endl;
                cin>>value;
                temp = isExist(tree, value);
                if(temp!= nullptr){
                    deleteNode(tree, temp);
                }else{
                    cout<<"Nie istnieje takiego klucza"<<endl;
                }
                break;
            case 8:
                break;
            case 9:
                return 0;
            default:
                cout<<"Niepoprawna wartość"<<endl;
        }
    }
}