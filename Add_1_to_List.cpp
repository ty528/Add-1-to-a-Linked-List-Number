//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node * newHead;
    int  helper(Node * temp)
    {
        int carry=0;
        if(temp->next!=NULL)
        {
            carry=helper(temp->next);
            temp->data+=carry;
            carry=temp->data/10;
            temp->data%=10;
        }
        else
        {
            temp->data+=1;
            carry=temp->data/10;
            temp->data%=10;
        }
        if(temp==newHead && carry!=0)
        {
            //cout<<"kaise ho?";
            Node * tempNewNode=new Node(carry);
            //cout<<newHead->data;
            tempNewNode->next=newHead;
            newHead=tempNewNode;
        }
        return carry;
    }
    Node* addOne(Node* head) 
    {
        newHead=head;
        helper(head);
        return head=newHead;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends