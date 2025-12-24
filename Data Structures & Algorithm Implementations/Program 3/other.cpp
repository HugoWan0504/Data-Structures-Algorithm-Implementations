void split(Node* n, Node *other, const string &s, string where);

Node* insert(Node* node, const string &key);

Node* Tree::insert(Node* node, const string &key){
    Node *leftchild = nullptr;
    Node *middle1 = nullptr;
    Node *middle2 = nullptr;
    Node *rightchild = nullptr;
    //create a new node for an empty root
    if (node == nullptr) {
        root = new Node(key);
    }
    else if (key < node->small )  {// if word is smaller
        if (node->left == 0) { //empty left
            if (node->small != "" && node->large == "") { // if there is an empty large (so you can insert here/no split)
                node->large = node->small;
                node->small = key;
            }
            else { //have to split because no choice
                split(node, key, leftchild, middle1, middle2, rightchild);
            }
        }
        else { //if left is not a new and empty root, insert and since its recursive it will go through
            insert(node, key);
        }
    }
    else if (key > node->small && node->large == "") { //saying that word is greater than samll and large is empty
        node->large = key;
    }
    else if (key > node->small && key < node->large) { //in the middle
        if (node->middle == 0) {
            split(node, key, leftchild, middle1, middle2, rightchild);
        }
        else {
            insert(node->middle, key);
        }
    }
    else if (node->large != "" && node->right == 0) { //you have full large but no right
        if (node->right == 0) {
            insert(node->right, key);
        }
        else {
            insert(node->right, key);
        }
    }
    else if (node->large != "" && node->right != 0) { //if large is full but right side isnt, insert to the right
        insert(node->right, key);
    }
}

void Tree::split(Node* n, Node *other, const string &s, string where) {
     bool setRoot = false;
    Node *p, *n1, *n2, *n3, *temp;
    temp = new Node("");
    
    if(n->small == root->small)
    {
        p = new Node("");
        setRoot = true;
    }
    else
    {
        p = n->parent;
    }
    
    
    if(s < n->small)
    {
        n1 = new Node(s);
        n2 = new Node(n->small);
        n3 = new Node(n->large);
    }
    else if(s > n->small && s < n->large)
    {
        n1 = new Node(n->small);
        n2 = new Node(s);
        n3 = new Node(n->large);
    }
    else
    {
        n1 = new Node(n->small);
        n2 = new Node(n->large);
        n3 = new Node(s);
    }
    n->parent = 0;
    n1->parent = p;
    n3->parent = p;
    if(n->left != 0)
    {
        if(where == "left")
        {
                n1->left = other->left;
                other->left->parent = n1;
                n1->right = other->right;
                other->right->parent = n1;
                n3->left = n->middle;
                n->middle->parent = n3;
                n3->right = n->right;
                n->right->parent = n3;
        }
        else if(where == "middle")
        {
                n1->left = n->left;
                n->left->parent = n1;
                n1->right = other->left;
                other->left->parent = n1;
                n3->left = other->right;
                other->right->parent = n3;
                n3->right = n->right;
                n->right->parent = n3;
        }
        else if(where == "right")
        {
                n1->left = n->left;
                n->left->parent = n1;
                n1->right = n->middle;
                n->middle->parent = n1;
                n3->left = other->left;
                other->left->parent = n3;
                n3->right = other->right;
                other->right->parent = n3;
        }
        else 
        {
                cout << "hey this did NOT work fam" << endl;
        }
        
        
    }
    temp->left = n1;
    temp->right = n3;
    string x = n2->small;
    if(p->hasLarge())
    {
        split(p, temp, x, where);
    }
    else
    {
        if(p->small == "")
        {
            p->small = x;
        }
        else if(x < p->small)
        {
            p->large = p->small;
            p->small = x;
        }
        else
        {
            p->large = x;
        }
    }
    
    if(p->left == 0)
    {
            p->left = temp->left;
            p->right = temp->right;
    }
    else if(p->left->small == n->small)
    {

        p->left = temp->left;
        p->middle = temp->right;
    }
    else if(p->right->small == n->small)
    {

        p->middle = temp->left;
        p->right = temp->right;
    }
    
    
    if(setRoot)
    {
        p->left = n1;
        p->right = n3;
        root = p;
    }   
}

void Tree::remove(const string &s) {
    Node* n = search(root, s);
        
        Node *successor, *leafNode;
        if(n)
        {
                if(n->left != 0)
                {
                        if(n->small == s && !n->hasLarge())
                        {
                                successor = inOrderSuccessorSmall(n->right);
                        }
                        else if(n->small == s && n->hasLarge())
                        {
                                successor = inOrderSuccessorSmall(n->middle);
                        }
                        else
                        {
                                successor = inOrderSuccessorSmall(n->right);
                        }
                        
                        string temp = successor->small;
                        if(n->small == s)
                        {
                                successor->small = n->small;
                                n->small = temp;
                        }
                        else 
                        {
                                successor->small = n->large;
                                n->large = temp;
                        }
                        leafNode = successor;
                        
                }
                else
                {
                     leafNode = n;   
                }
                bool leafIsGone = false;
                
                if(s == leafNode->small)
                {

                        if(leafNode->large != "")
                        {
                                string temp1 = leafNode->large;
                                leafNode->small = temp1;
                                leafNode->large = "";
                        }
                        else
                        {
                                leafNode->small = "";
                                leafIsGone = true;
                        }
                }
                else 
                {
                        // cout << "AWWWW" << endl;
                        // cout << leafNode->large << endl;
                        leafNode->large = "";
                }
                
                if(leafIsGone)
                {
                        fix(leafNode);
                }
        }
}