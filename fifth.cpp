#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head = NULL;
void insert_begin(int x){
    struct node* n = malloc(sizeof(struct node));
    n->data = x;
    n->next = head;
    head = n;
}
void insert_end(int x){
    struct node* n = malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;
    if(head == NULL){ head = n; return; }
    struct node* t = head;
    while(t->next) t = t->next;
    t->next = n;
}
void insert_before(int val, int x){
    if(head == NULL) return;
    if(head->data == val){
        insert_begin(x);
        return;
    }
    struct node *t = head, *p = NULL;
    while(t && t->data != val){
        p = t;
        t = t->next;
    }
    if(t){
        struct node* n = malloc(sizeof(struct node));
        n->data = x;
        p->next = n;
        n->next = t;
    }
}
void insert_after(int val, int x){
    struct node* t = head;
    while(t && t->data != val) t = t->next;
    if(t){
        struct node* n = malloc(sizeof(struct node));
        n->data = x;
        n->next = t->next;
        t->next = n;
    }
}
void delete_begin(){
    if(head == NULL) return;
    struct node* t = head;
    head = head->next;
    free(t);
}
void delete_end(){
    if(head == NULL) return;
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    struct node *t = head, *p = NULL;
    while(t->next){
        p = t;
        t = t->next;
    }
    p->next = NULL;
    free(t);
}
void delete_value(int val){
    if(head == NULL) return;
    if(head->data == val){
        delete_begin();
        return;
    }
    struct node *t = head, *p = NULL;
    while(t && t->data != val){
        p = t;
        t = t->next;
    }
    if(t){
        p->next = t->next;
        free(t);
    }
}
void search(int val){
    struct node* t = head;
    int pos = 1;
    while(t){
        if(t->data == val){
            printf("%d\n", pos);
            return;
        }
        t = t->next;
        pos++;
    }
    printf("-1\n");
}
void display(){
    struct node* t = head;
    while(t){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}
int main(){
    int ch, x, val;
    while(1){
        scanf("%d", &ch);
        if(ch == 1){ scanf("%d",&x); insert_begin(x); }
        else if(ch == 2){ scanf("%d",&x); insert_end(x); }
        else if(ch == 3){ scanf("%d%d",&val,&x); insert_before(val,x); }
        else if(ch == 4){ scanf("%d%d",&val,&x); insert_after(val,x); }
        else if(ch == 5){ delete_begin(); }
        else if(ch == 6){ delete_end(); }
        else if(ch == 7){ scanf("%d",&val); delete_value(val); }
        else if(ch == 8){ scanf("%d",&val); search(val); }
        else if(ch == 9){ display(); }
        else if(ch == 10){ return 0; }
    }
}





#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head = NULL;
void insert_end(int x){
    struct node* n = malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;
    if(head == NULL){ head = n; return; }
    struct node* t = head;
    while(t->next) t = t->next;
    t->next = n;
}
int delete_key(int key){
    int count = 0;
    while(head && head->data == key){
        struct node* t = head;
        head = head->next;
        free(t);
        count++;
    }
    struct node *t = head, *p = NULL;
    while(t){
        if(t->data == key){
            p->next = t->next;
            free(t);
            count++;
            t = p->next;
        } else {
            p = t;
            t = t->next;
        }
    }
    return count;
}
void display(){
    struct node* t = head;
    while(t){
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}
int main(){
    int n,i,x,key,c;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insert_end(x);
    }
    scanf("%d",&key);
    c = delete_key(key);
    printf("Count: %d\n", c);
    display();
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
    struct node* n = malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;
    if(head == NULL){ head = n; return; }
    struct node* t = head;
    while(t->next) t = t->next;
    t->next = n;
}
int find_middle(){
    struct node *slow=head, *fast=head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
int main(){
    int n,x,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insert_end(x);
    }
    printf("%d", find_middle());
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
    struct node* n = malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;
    if(head == NULL){ head = n; return; }
    struct node* t = head;
    while(t->next) t = t->next;
    t->next = n;
}
void reverse(){
    struct node *prev=NULL, *cur=head, *next=NULL;
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}
void display(){
    struct node* t = head;
    while(t){
        printf("%d ", t->data);
        t = t->next;
    }
}
int main(){
    int n,x,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insert_end(x);
    }
    reverse();
    display();
    return 0;
}
