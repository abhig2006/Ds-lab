#include <stdio.h>
#define MAX 100

int stack[MAX], top=-1;

void push(int x){
    if(top==MAX-1) return;
    stack[++top]=x;
}
int pop(){
    if(top==-1) return -1;
    return stack[top--];
}
int isEmpty(){
    return top==-1;
}
int isFull(){
    return top==MAX-1;
}
int peek(){
    if(top==-1) return -1;
    return stack[top];
}
void display(){
    int i;
    if(top==-1) return;
    for(i=top;i>=0;i--) printf("%d ",stack[i]);
    printf("\n");
}

int main(){
    int ch,x;
    while(1){
        scanf("%d",&ch);
        if(ch==1){ scanf("%d",&x); push(x); }
        else if(ch==2) printf("%d\n",pop());
        else if(ch==3) printf("%d\n",isEmpty());
        else if(ch==4) printf("%d\n",isFull());
        else if(ch==5) display();
        else if(ch==6) printf("%d\n",peek());
        else if(ch==7) return 0;
    }
}




#include <stdio.h>
#include <string.h>

int main(){
    char s[100], st[100];
    int top=-1,i;
    gets(s);
    for(i=0;s[i]!='\0';i++) st[++top]=s[i];
    while(top!=-1) printf("%c",st[top--]);
    return 0;
}




#include <stdio.h>

int main(){
    char s[100], st[100];
    int top=-1,i;
    gets(s);
    for(i=0;s[i]!='\0';i++){
        char c=s[i];
        if(c=='('||c=='{'||c=='[') st[++top]=c;
        else if(c==')'){
            if(top==-1||st[top]!='('){ printf("Not Balanced"); return 0; }
            top--;
        }
        else if(c=='}'){
            if(top==-1||st[top]!='{'){ printf("Not Balanced"); return 0; }
            top--;
        }
        else if(c==']'){
            if(top==-1||st[top]!='['){ printf("Not Balanced"); return 0; }
            top--;
        }
    }
    if(top==-1) printf("Balanced");
    else printf("Not Balanced");
    return 0;
}



#include <stdio.h>
#include <ctype.h>

int prec(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}

int main(){
    char in[100], st[100], post[100];
    int top=-1,j=0,i;
    gets(in);
    for(i=0;in[i]!='\0';i++){
        char c=in[i];
        if(isalnum(c)) post[j++]=c;
        else if(c=='(') st[++top]=c;
        else if(c==')'){
            while(top!=-1 && st[top]!='(') post[j++]=st[top--];
            top--;
        }
        else{
            while(top!=-1 && prec(st[top])>=prec(c)) post[j++]=st[top--];
            st[++top]=c;
        }
    }
    while(top!=-1) post[j++]=st[top--];
    post[j]='\0';
    puts(post);
    return 0;
}



#include <stdio.h>
#include <ctype.h>

int main(){
    char p[100];
    int st[100],top=-1,i;
    gets(p);
    for(i=0;p[i]!='\0';i++){
        if(isdigit(p[i])) st[++top]=p[i]-'0';
        else{
            int b=st[top--];
            int a=st[top--];
            switch(p[i]){
                case '+': st[++top]=a+b; break;
                case '-': st[++top]=a-b; break;
                case '*': st[++top]=a*b; break;
                case '/': st[++top]=a/b; break;
            }
        }
    }
    printf("%d",st[top]);
    return 0;
}
