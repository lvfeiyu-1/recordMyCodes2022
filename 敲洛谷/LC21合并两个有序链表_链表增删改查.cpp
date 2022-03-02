#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void addNode(int x){
        ListNode* head=this;
        ListNode* tmp=new ListNode(x);
        while(head->next!=nullptr){
            head=head->next;
        }
        head->next=tmp;
        this->val++;
    }
   void display(){
        ListNode* head=this;
        while(head->next!=nullptr){
            head=head->next;
            cout<<head->val<<" ";
        }
        cout<<endl<<"1"<<endl;
    }
};

///注意，力扣上的输出 和 上面的display不一样，力扣上头结点也照样输出
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if(!list1&&!list2)
            return nullptr;
        else if(list1 && !list2)
            return list1;
        else if(!list1 && list2)
            return list2;
        ListNode* ans;
        if(list1->val<list2->val){
            ans=new ListNode(list1->val);
            list1=list1->next;
        }
        else{
            ans=new ListNode(list2->val);
            list2=list2->next;
        }
        //list1=list1->next;
        //list2=list2->next;
        while(list1&&list2){
            if(list1->val<list2->val){
                ListNode* head=ans;
                ListNode* tmp=new ListNode(list1->val);
                while(head->next!=nullptr){
                    head=head->next;
                }
                head->next=tmp;
                //ans->addNode(list1->val);
                //ans->next=list1;
                list1=list1->next;
            }else{
                ListNode* head=ans;
                ListNode* tmp=new ListNode(list2->val);
                while(head->next!=nullptr){
                    head=head->next;
                }
                head->next=tmp;
                //ans->addNode(list2->val);
                list2=list2->next;
            }
        }
        if(!list1){
            while(list2){
                //ans->addNode(list2->val);
                ListNode* head=ans;
                ListNode* tmp=new ListNode(list2->val);
                while(head->next!=nullptr){
                    head=head->next;
                }
                head->next=tmp;
                list2=list2->next;
            }
            //ans->next=list2;
        }
        else{
            while(list1){
                //ans->addNode(list1->val);
                ListNode* head=ans;
                ListNode* tmp=new ListNode(list1->val);
                while(head->next!=nullptr){
                    head=head->next;
                }
                head->next=tmp;
                list1=list1->next;
            }
        }
        return ans;
    }
};

int main() {
    int val;
    Solution sol;
    ListNode* list1=new ListNode();
    while (cin >> val) {
        if(val==999)
            break;
        list1->addNode(val);
    }
    list1->display();

    ListNode* list2=new ListNode();
    while (cin >> val) {
        if(val==999)
            break;
        list2->addNode(val);
    }
    list2->display();

    ListNode* ans=sol.mergeTwoLists(list1,list2);
    ans->display();
    return 0;
}