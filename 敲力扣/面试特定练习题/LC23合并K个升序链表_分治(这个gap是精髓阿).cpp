#include<iostream>
#include<vector>
using namespace std;

//执行用时：0 ms, 在所有 C++ 提交中击败了94.32%的用户
//内存消耗：6 MB, 在所有 C++ 提交中击败了43.09%的用户

struct ListNode{
    int val;
    ListNode* next;
    ListNode(){
        val=0;
        next=nullptr;
    }
    ListNode(int x){
        val=x;
        next=nullptr;
    }
    ListNode(int x,ListNode* next){
        val=x;
        this->next=next;
    }
};

class List{
public:
    ListNode* head;
    vector<ListNode*> lists;

    void addList(){
        int len;
        cin>>len;
        ListNode* H=new ListNode();
        head=H;
        while(len--){
            int num;
            cin>>num;
            ListNode* node=new ListNode(num);
            H->next=node;
            H=H->next;
        }
        lists.push_back(head->next);
//        while(head!=nullptr){
//            cout<<head->val<<" ";
//            head=head->next;
//        }
//        cout<<endl;
    }
};

class Solution {
public:
    ListNode* merge(ListNode* list1,ListNode* list2){
        if(!list1&&!list2)
            return nullptr;
        if(list1&&!list2)
            return list1;
        else if(!list1&&list2)
            return list2;

        ListNode* ans=new ListNode();
        ListNode* head=ans;
        while(list1&&list2){
            if(list1->val<list2->val){
                //ListNode* tmp=new ListNode(list1->val);
                ans->next=list1;
                list1=list1->next;
            }else{
                //ListNode* tmp=new ListNode(list1->val);
                ans->next=list2;
                list2=list2->next;
            }
            ans=ans->next;
        }
        if(list1)
            ans->next=list1;
        else if(list2)
            ans->next=list2;
        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int num=lists.size();
        if(!num)
            return nullptr;
        int gap=1;
        while(gap<num){
            for(int i=0;i+gap<num;i+=(gap*2)){
                lists[i]=merge(lists[i],lists[i+gap]);
            }
            gap*=2;
        }
        return lists[0];
    }
};

int main(){
    int n;
    cin>>n;
    Solution sol;
    List list;
    while(n--){
        list.addList();
    }
    ListNode* ans=sol.mergeKLists(list.lists);
    while(ans!=nullptr){
        cout<<ans->val<<" ";
        ans=ans->next;
    }
    cout<<endl;
    return 0;
}