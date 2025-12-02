#include <stdio.h>
#include <stdlib.h>

struct CNode{ int data; struct CNode* next; };
struct DNode{ int data; struct DNode* prev, *next; };

struct CNode* chead = NULL;
struct DNode* dhead = NULL;

void c_insert_first(int x){
    struct CNode* n = malloc(sizeof(struct CNode));
    n->data = x;
    if(!chead){ chead = n; n->next = chead; return; }
    struct CNode* t = chead;
    while(t->next != chead) t = t->next;
    n->next = chead; t->next = n; chead = n;
}

void c_insert_last(int x){
    struct CNode* n = malloc(sizeof(struct CNode));
    n->data = x;
    if(!chead){ chead = n; n->next = chead; return; }
    struct CNode* t = chead;
    while(t->next != chead) t = t->next;
    t->next = n; n->next = chead;
}

void c_delete(int val){
    if(!chead) return;
    struct CNode *t = chead, *p = NULL;
    do{
        if(t->data == val){
            if(t == chead){
                if(t->next == chead){ free(t); chead = NULL; return; }
                struct CNode* last = chead;
                while(last->next != chead) last = last->next;
                chead = chead->next; last->next = chead; free(t); return;
            }
            p->next = t->next; free(t); return;
        }
        p = t; t = t->next;
    } while(t != chead);
}

int c_search(int val){
    if(!chead) return -1;
    struct CNode* t = chead; int pos = 1;
    do{
        if(t->data == val) return pos;
        pos++; t = t->next;
    } while(t != chead);
    return -1;
}

void c_display(){
    if(!chead) return;
    struct CNode* t = chead;
    do{ printf("%d ", t->data); t = t->next; } while(t != chead);
    printf("\n");
}

void d_insert_first(int x){
    struct DNode* n = malloc(sizeof(struct DNode));
    n->data = x; n->prev = NULL; n->next = dhead;
    if(dhead) dhead->prev = n;
    dhead = n;
}

void d_insert_last(int x){
    struct DNode* n = malloc(sizeof(struct DNode));
    n->data = x; n->next = NULL;
    if(!dhead){ n->prev = NULL; dhead = n; return; }
    struct DNode* t = dhead;
    while(t->next) t = t->next;
    t->next = n; n->prev = t;
}

void d_delete(int val){
    struct DNode* t = dhead;
    while(t){
        if(t->data == val){
            if(t == dhead){ dhead = t->next; if(dhead) dhead->prev = NULL; }
            else{
                if(t->next) t->next->prev = t->prev;
                t->prev->next = t->next;
            }
            free(t); return;
        }
        t = t->next;
    }
}

int d_search(int val){
    struct DNode* t = dhead; int pos = 1;
    while(t){ if(t->data == val) return pos; pos++; t = t->next; }
    return -1;
}

void d_display(){
    struct DNode* t = dhead;
    while(t){ printf("%d ", t->data); t = t->next; }
    printf("\n");
}

int main(){
    int type, ch, x;
    scanf("%d", &type); // 1 for Circular, 2 for Doubly
    while(1){
        scanf("%d", &ch);
        if(ch == 1){ scanf("%d", &x); type==1 ? c_insert_first(x) : d_insert_first(x); }
        else if(ch == 2){ scanf("%d", &x); type==1 ? c_insert_last(x) : d_insert_last(x); }
        else if(ch == 3){ scanf("%d", &x); type==1 ? c_delete(x) : d_delete(x); }
        else if(ch == 4){ scanf("%d", &x); printf("%d\n", type==1 ? c_search(x) : d_search(x)); }
        else if(ch == 5){ type==1 ? c_display() : d_display(); }
        else if(ch == 6) break;
    }
    return 0;
}






#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;

void insert_end(int x){
    struct node* n=malloc(sizeof(struct node));
    n->data=x;
    if(head==NULL){
        head=n;
        n->next=head;
        return;
    }
    struct node* t=head;
    while(t->next!=head) t=t->next;
    t->next=n;
    n->next=head;
}

void display(){
    if(head==NULL) return;
    struct node* t=head;
    do{
        printf("%d ",t->data);
        t=t->next;
    }while(t!=head);
    printf("%d",head->data);
}

int main(){
    int n,x,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insert_end(x);
    }
    display();
    return 0;
}



#include <stdio.h>
#include <stdlib.h>

struct dnode{
    int data;
    struct dnode* prev;
    struct dnode* next;
};

struct dnode* head=NULL;

void insert_end(int x){
    struct dnode* n=malloc(sizeof(struct dnode));
    n->data=x;
    n->next=NULL;
    if(head==NULL){
        n->prev=NULL;
        head=n;
        return;
    }
    struct dnode* t=head;
    while(t->next) t=t->next;
    t->next=n;
    n->prev=t;
}

int get_size(){
    int c=0;
    struct dnode* t=head;
    while(t){ c++; t=t->next; }
    return c;
}

int main(){
    int n,x,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){ scanf("%d",&x); insert_end(x); }
    printf("%d", get_size());
    return 0;
}



#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;

void insert_end(int x){
    struct node* n=malloc(sizeof(struct node));
    n->data=x;
    if(head==NULL){
        head=n;
        n->next=head;
        return;
    }
    struct node* t=head;
    while(t->next!=head) t=t->next;
    t->next=n;
    n->next=head;
}

int get_size(){
    if(head==NULL) return 0;
    int c=0;
    struct node* t=head;
    do{
        c++;
        t=t->next;
    }while(t!=head);
    return c;
}

int main(){
    int n,x,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){ scanf("%d",&x); insert_end(x); }
    printf("%d", get_size());
    return 0;
}



#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node* prev;
    struct node* next;
};

struct node* head=NULL;

void insert_end(char c){
    struct node* n=malloc(sizeof(struct node));
    n->data=c;
    n->next=NULL;
    if(head==NULL){
        n->prev=NULL;
        head=n;
        return;
    }
    struct node* t=head;
    while(t->next) t=t->next;
    t->next=n;
    n->prev=t;
}

int is_palindrome(){
    if(!head) return 1;
    struct node *l=head, *r=head;
    while(r->next) r=r->next;
    while(l!=r && r->next!=l){
        if(l->data!=r->data) return 0;
        l=l->next;
        r=r->prev;
    }
    return 1;
}

int main(){
    char s[100];
    int i;
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++) insert_end(s[i]);
    if(is_palindrome()) printf("Palindrome");
    else printf("Not Palindrome");
    return 0;
}



#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert_end(int x){
    struct node* n=malloc(sizeof(struct node));
    n->data=x;
    n->next=NULL;
    if(head==NULL){ head=n; return; }
    struct node* t=head;
    while(t->next) t=t->next;
    t->next=n;
}

int isCircular(){
    if(head==NULL) return 1;
    struct node* t=head->next;
    while(t && t!=head) t=t->next;
    return t==head;
}

int main(){
    int n,i,x,opt;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insert_end(x);
    }
    scanf("%d",&opt);
    if(opt==1){
        struct node* t=head;
        while(t->next) t=t->next;
        t->next=head;
    }
    if(isCircular()) printf("Circular");
    else printf("Not Circular");
    return 0;
}
