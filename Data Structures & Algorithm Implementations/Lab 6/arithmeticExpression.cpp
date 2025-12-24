#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <stack>
#include "arithmeticExpression.h"

using namespace std;

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void arithmeticExpression::infix(TreeNode* currRootNode){
    //do nothing if current node is a nullptr
	if (currRootNode == nullptr){
		return;
	}
    //check operator priority
    //output currRootNode's left data
	if (priority(currRootNode->data)){
		cout << "(";
		infix(currRootNode->left);
		cout << currRootNode->data;
		infix(currRootNode->right);
		cout << ")";
    }
    //double check if it moves on
	else {
		infix(currRootNode->left);
		cout << currRootNode->data;
		infix(currRootNode->right);
	}
}

void arithmeticExpression::prefix(TreeNode* currRootNode){
	//do nothing if current node is a nullptr
    if (currRootNode == nullptr){
		return;
	}
    //output currRootNode's left data and continues
	cout << currRootNode->data;
	prefix(currRootNode->left);
	prefix(currRootNode->right);
}

void arithmeticExpression::postfix(TreeNode* currRootNode){
	//do nothing if current node is a nullptr
    if (currRootNode == nullptr){
		return;
	}
    //output currRootNode's right data and continues
	postfix(currRootNode->left);
	postfix(currRootNode->right);
	cout << currRootNode->data;
}

void arithmeticExpression::visualizeTree(ofstream& out, TreeNode* currRootNode){
    //output currRootNode's data first
    if (currRootNode != nullptr){
    	out << currRootNode->key << "[ label = \"";
        out << currRootNode->data << "\" ]" << endl;
        //output currRootNode's left data
        if (currRootNode->left){
            out << currRootNode->key << "->" << currRootNode->left->key;
            out << "[ label = \"" << currRootNode->left->data << "\" ]" << endl;
            visualizeTree(out, currRootNode->left);
        }
        //output currRootNode's right data
        if (currRootNode->right){
            out << currRootNode->key << "->" << currRootNode->right->key;
            out << "[ label =  \"" << currRootNode->right->data << "\" ]" << endl;
            visualizeTree(out, currRootNode->right);
        }
        out << endl;
    }
}

void arithmeticExpression::buildTree() {
	infixExpression = infix_to_postfix();
	stack <TreeNode*> stacks;

	for (unsigned i = 0; i < infixExpression.size(); ++i) {
		TreeNode* nodeUpdate = new TreeNode(infixExpression.at(i), 'a' + i);
        //adds if empty
		if (!priority(infixExpression.at(i))) {
			stacks.push(nodeUpdate);
		}
        //not empty, adds accordingly
        //pop everytime it stacks to the top
		else if (priority(infixExpression.at(i)) > 0) {
			nodeUpdate->right = stacks.top();
			stacks.pop();
			nodeUpdate->left = stacks.top();
			stacks.pop();
			stacks.push(nodeUpdate);
			root = nodeUpdate;
		}
	}
}