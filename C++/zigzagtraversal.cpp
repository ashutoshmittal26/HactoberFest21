#include <bits/stdc++.h>
using namespace std;
template <typename T>
class binarytreenode
{
public:
    T data;
    binarytreenode *left;
    binarytreenode *right;
    binarytreenode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~binarytreenode()
    {
        delete left;
        delete right;
    }
};
binarytreenode<int> *takeinput()
{
    int rootdata;
    cout << "Enter root  data" << endl;
    cin >> rootdata;
    if (rootdata == -1)
    {
        return NULL;
    }
    binarytreenode<int> *root = new binarytreenode<int>(rootdata);
    queue<binarytreenode<int> *> pendingnodes;
    pendingnodes.push(root);
    while (pendingnodes.size() != 0)
    {
        binarytreenode<int> *front = pendingnodes.front();
        pendingnodes.pop();
        cout << "ENTER LEFT CHILD OF" << front->data << endl;
        int leftchilddata;
        cin >> leftchilddata;
        if (leftchilddata != -1)
        {
            binarytreenode<int> *child = new binarytreenode<int>(leftchilddata);
            front->left = child;
            pendingnodes.push(child);
        }

        cout << "ENTER RIGHT  CHILD OF" << front->data << endl;
        int rightchilddata;
        cin >> rightchilddata;
        if (rightchilddata != -1)
        {
            binarytreenode<int> *child = new binarytreenode<int>(rightchilddata);
            front->right = child;
            pendingnodes.push(child);
        }
    }

    return root;
}
// void zigZag_Order(binarytreenode<int> *root)
// {
//     if (!root)
//         return;
//     stack<binarytreenode<int> *> a; // R->L
//     stack<binarytreenode<int> *> b; // L->R
//     a.push(root);
//     while (a.size() != 0 || b.size() != 0)
//     {
//         while (a.size() != 0)
//         {
//             binarytreenode<int> *curr = a.top();
//             // cout << curr->data << " ";
//             a.pop();
//             cout << curr->data << " ";

//             if (curr->left != NULL)
//                 b.push(curr->left);

//             if (curr->right != NULL)
//                 b.push(curr->right);

//              if (a.size() == 0)
//                 cout << endl;
//         }
//         while (b.size() != 0)
//         {
//             binarytreenode<int> *curr = b.top();
//             // cout << curr->data << " ";
//             b.pop();
//             cout << curr->data << " ";

//             if (curr->right != NULL)
//                 a.push(curr->right);

//             if (curr->left != NULL)
//                 a.push(curr->left);

//             if (b.size() == 0)
//                 cout << endl;
//         }
//     }
// }
vector<int> zigzagLevelOrder(binarytreenode<int> *root)
{
    vector<int> ans;
    queue<binarytreenode<int> *> q;
    q.push(root);

    int count = 0;
    if (root == NULL)
        return ans;

    while (!q.empty())
    {
        vector<int> val;

        int size = q.size();
        if (size == 0)
            return ans;
        count++;

        while (size--)
        {
            binarytreenode<int> *temp = q.front();
            q.pop();

            val.push_back(temp->data);
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        if (count % 2 == 0)
            reverse(val.begin(), val.end());
        for (int i = 0; i < val.size(); i++)
        {
            ans.push_back(val[i]);
        }
    }
    return ans;
}
int main()
{

    binarytreenode<int> *root = takeinput();
    vector<int> v = zigzagLevelOrder(root);
    for (int i = 0; i < v.size(); i++)
    { // to print the order
        cout << v[i] << " ";
    }

    return 0;
}
