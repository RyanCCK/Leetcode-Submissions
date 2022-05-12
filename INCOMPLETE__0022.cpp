class Solution {
public:
    //Binary Tree Node data structure
    struct TreeNode
    {
        char val;
        TreeNode * left;
        TreeNode * right;
        TreeNode(char p) : val(p), left(nullptr), right(nullptr) {}
    }; 
    
    
    //Helper function to create tree with only valid parenthesis combinations as paths
    void buildTree(TreeNode * curr, int openParens, int pathSize, int maxSize)
    {
        //Return if the current path is at max size
        if(pathSize == maxSize) return;
    
        //Determine what nodes (if any) can be added to the tree:
        //  If both left and right nodes are possible
        if(openParens < maxSize-pathSize && openParens > 0 && maxSize-pathSize > 2)
        {
            TreeNode * left = new TreeNode('(');
            curr->left = left;
            buildTree(left, ++openParens, ++pathSize, maxSize);
            TreeNode * right = new TreeNode(')');
            curr->right = right;
            buildTree(right, --openParens, ++pathSize, maxSize);
        }
        //  If only a left node is possible
        else if(openParens == 0 && maxSize-pathSize == 2)
        {
            TreeNode * left = new TreeNode('(');
            curr->left = left;
            buildTree(left, ++openParens, ++pathSize, maxSize);
        }
        //  If only a right node is possible
        else if(openParens == maxSize-pathSize)
        {
            TreeNode * right = new TreeNode(')');
            curr->right = right;
            buildTree(right, --openParens, ++pathSize, maxSize);
        }
    }
    
    
    //Helper function to create parentheses vector from binary tree
    //DELETES TREE AS IT IS READ
    vector<string> treeToVec(TreeNode * curr, int currIndex, vector<string> vec)
    {
        vec[currIndex] += curr->val;
        if(curr->left)
        {
            treeToVec(curr->left, currIndex, vec);
        }
        if(curr->right)
        {
            vec.push_back(vec[currIndex]);
            treeToVec(curr->right, ++currIndex, vec);
        }
        delete curr; //Delete each node once it (and all its children) have been read
        return vec;
    }
    
    
    vector<string> generateParenthesis(int n) {
        //validParentheses holds our return values. 
        //maxSize is the required size of each element of validParentheses.
        vector<string> validParentheses {""};
        int maxSize = n*2;
        
        //Build base of tree
        TreeNode * head = new TreeNode('(');
        
        //Build remainder of tree
        buildTree(head, 1, 1, maxSize);
        
        //Construct validParentheses vector from tree 
        //and delete tree
        validParentheses = treeToVec(head, 0, validParentheses);
        
        //Return vector
        return validParentheses;
    }    
};
