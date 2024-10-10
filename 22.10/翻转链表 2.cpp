#include <iostream>
#include<queue>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
};
class Solution {
public:
    pair<ListNode*,ListNode*> splitX(ListNode* left,int x){// [x,)
        if(x==0) return {nullptr,left};
        ListNode* tmp=left;
        for(int i=1;i<x;i++)
            tmp=tmp->next;
        ListNode* right=tmp->next;
        tmp->next=nullptr;
        return {left,right};
    }
    ListNode* merge(ListNode* a,ListNode* b){//合并两个链表
        if(a==nullptr) return b;
        if(b==nullptr) return a;
        ListNode* now=a;
        for(;now->next!=nullptr;now=now->next);
        now->next=b;
        return a;
    }
    ListNode* reverse(ListNode* head){
        if(head==nullptr) return nullptr;
        ListNode* last=head;
        for(auto now=head->next;now!=nullptr;){
            auto tmp=now->next;
            now->next=head;
            head=now;
            now=tmp;
        }
        last->next=nullptr;
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {//(,]
        auto [a1,c]=splitX(head, n);
        auto [a,b]=splitX(a1,m);
        b=reverse(b);
        auto res=merge(merge(a,b),c);
        return res;
    }
};
ListNode* create(vector<int> va){
    ListNode* ret=new ListNode{va[0]};
    auto t=ret;
    for(int i=1;i<(int)va.size();i++){
        t->next=new ListNode{va[i]};
        t=t->next;
    }
    return ret;
}
void print_list(ListNode* li){
    for(;li!=nullptr;li=li->next)
        cout<<li->val<<" ";
    cout<<"\n";
}
int main(){
    vector<int> ar={1,2,3,4,5,6,7};
    auto li=create(ar);
    print_list(li);
    Solution s;
    auto t=s.reverseBetween(li,2,4);
    print_list(t);
    print_list(s.reverseBetween(create(ar),0,3));
    print_list(s.reverseBetween(create(ar),1,1));
    print_list(s.reverseBetween(create(ar),1,2));
    print_list(s.reverseBetween(create(ar),7,7));
    print_list(s.reverseBetween(create(ar),6,7));
    print_list(s.reverseBetween(create(ar),5,7));
    print_list(s.reverseBetween(create(ar),0,7));
}
