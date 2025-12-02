#include <stdio.h>
#define MAX 100
int q[MAX], front=-1, rear=-1;
void enqueue(int x){
    if(rear==MAX-1) return;
    if(front==-1) front=0;
    q[++rear]=x;
}
int dequeue(){
    if(front==-1||front>rear) return -1;
    return q[front++];
}
int isEmpty(){
    return front==-1||front>rear;
}
int isFull(){
    return rear==MAX-1;
}
int peek(){
    if(front==-1||front>rear) return -1;
    return q[front];
}
void display(){
    int i;
    if(front==-1||front>rear) return;
    for(i=front;i<=rear;i++) printf("%d ",q[i]);
    printf("\n");
}
int main(){
    int ch,x;
    while(1){
        scanf("%d",&ch);
        if(ch==1){ scanf("%d",&x); enqueue(x); }
        else if(ch==2) printf("%d\n",dequeue());
        else if(ch==3) printf("%d\n",isEmpty());
        else if(ch==4) printf("%d\n",isFull());
        else if(ch==5) display();
        else if(ch==6) printf("%d\n",peek());
        else if(ch==7) return 0;
    }
}





#include <stdio.h>
#define MAX 100
int cq[MAX], front=-1, rear=-1;
void enqueue(int x){
    if((rear+1)%MAX==front) return;
    if(front==-1) front=0;
    rear=(rear+1)%MAX;
    cq[rear]=x;
}
int dequeue(){
    if(front==-1) return -1;
    int v=cq[front];
    if(front==rear){ front=rear=-1; return v; }
    front=(front+1)%MAX;
    return v;
}

int isEmpty(){
    return front==-1;
}

int isFull(){
    return (rear+1)%MAX==front;
}

int peek(){
    if(front==-1) return -1;
    return cq[front];
}

void display(){
    int i;
    if(front==-1) return;
    if(front<=rear){
        for(i=front;i<=rear;i++) printf("%d ",cq[i]);
    } else {
        for(i=front;i<MAX;i++) printf("%d ",cq[i]);
        for(i=0;i<=rear;i++) printf("%d ",cq[i]);
    }
    printf("\n");
}
int main(){
    int ch,x;
    while(1){
        scanf("%d",&ch);
        if(ch==1){ scanf("%d",&x); enqueue(x); }
        else if(ch==2) printf("%d\n",dequeue());
        else if(ch==3) printf("%d\n",isEmpty());
        else if(ch==4) printf("%d\n",isFull());
        else if(ch==5) display();
        else if(ch==6) printf("%d\n",peek());
        else if(ch==7) return 0;
    }
}


#include <stdio.h>
int main(){
    int q[100],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&q[i]);
    int h=n/2;
    for(i=0;i<h;i++){
        printf("%d ",q[i]);
        printf("%d ",q[i+h]);
    }
    return 0;
}


#include <stdio.h>
#include <string.h>
int main(){
    char s[100], q[100];
    int freq[256]={0}, front=0, rear=-1, i;
    gets(s);
    for(i=0;s[i]!='\0';i++){
        char c=s[i];
        freq[c]++;
        q[++rear]=c;
        while(front<=rear && freq[q[front]]>1) front++;
        if(front>rear) printf("-1 ");
        else printf("%c ",q[front]);
    }
    return 0;
}



#include <stdio.h>
int main(){
    int q1[100],q2[100],f1=0,r1=-1,f2=0,r2=-1,n,i,x,choice;
    while(1){
        scanf("%d",&choice);
        if(choice==1){
            scanf("%d",&x);
            q2[++r2]=x;
            for(i=f1;i<=r1;i++) q2[++r2]=q1[i];
            f1=0; r1=r2; for(i=0;i<=r2;i++) q1[i]=q2[i];
            f2=0; r2=-1;
        }
        else if(choice==2){
            if(f1>r1) printf("-1\n");
            else printf("%d\n",q1[f1++]);
        }
        else if(choice==3) return 0;
    }
}

#include <stdio.h>
int main(){
    int q[100],f=0,r=-1,i,choice,x,n;
    while(1){
        scanf("%d",&choice);
        if(choice==1){
            scanf("%d",&x);
            q[++r]=x;
            for(i=f;i<r;i++){
                int temp=q[f];
                f++;
                q[++r]=temp;
            }
        }
        else if(choice==2){
            if(f>r) printf("-1\n");
            else printf("%d\n",q[f++]);
        }
        else if(choice==3) return 0;
    }
}
