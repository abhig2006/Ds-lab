#include <stdio.h>
int binary_search(int a[], int n, int key) {
    int l=0, r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==key) return m;
        else if(a[m]<key) l=m+1;
        else r=m-1;
    }
    return -1;
}

int main() {
    int a[]={10,20,30,40,50,60}, n=6, key;
    scanf("%d",&key);
    int pos = binary_search(a,n,key);
    printf("%d",pos);
    return 0;
}


#include <stdio.h>
int main() {
    int a[]={64,34,25,12,22,11,90}, n=7, i, j, t;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]){ t=a[j]; a[j]=a[j+1]; a[j+1]=t; }
    for(i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}


#include <stdio.h>
int main() {
    int a[]={1,2,3,5,6}, n=6, i;
    for(i=0;i<n-1;i++)
        if(a[i]+1!=a[i+1]){ printf("%d",a[i]+1); break; }
    return 0;
}


#include <stdio.h>
int main() {
    int a[]={1,2,3,5,6}, n=6, l=0,r=n-2,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]==mid+1) l=mid+1;
        else r=mid-1;
    }
    printf("%d",l+1);
    return 0;
}


#include <stdio.h>
int main(){
    char a[100],b[100];
    int i,j;
    gets(a); gets(b);
    for(i=0;a[i]!='\0';i++);
    for(j=0;b[j]!='\0';j++) a[i++]=b[j];
    a[i]='\0';
    puts(a);
    return 0;
}


#include <stdio.h>
#include <string.h>
int main(){
    char s[100]; gets(s);
    int i,n=strlen(s);
    for(i=0;i<n/2;i++){
        char t=s[i]; s[i]=s[n-i-1]; s[n-i-1]=t;
    }
    puts(s);
    return 0;
}


#include <stdio.h>
int main(){
    char s[100],r[100]; 
    int i,j=0;
    gets(s);
    for(i=0;s[i]!='\0';i++){
        char c=s[i];
        if(c!='a'&&c!='e'&&c!='i'&&c!='o'&&c!='u'&&
           c!='A'&&c!='E'&&c!='I'&&c!='O'&&c!='U')
            r[j++]=c;
    }
    r[j]='\0';
    puts(r);
    return 0;
}


#include <stdio.h>
#include <string.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    char s[n][100],t[100];
    for(i=0;i<n;i++) scanf("%s",s[i]);
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(strcmp(s[i],s[j])>0){
                strcpy(t,s[i]); strcpy(s[i],s[j]); strcpy(s[j],t);
            }
    for(i=0;i<n;i++) printf("%s\n",s[i]);
    return 0;
}


#include <stdio.h>
int main(){
    char c;
    scanf("%c",&c);
    if(c>='A'&&c<='Z') c=c+32;
    printf("%c",c);
    return 0;
}

#include <stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    int d[n];
    for(i=0;i<n;i++) scanf("%d",&d[i]);
    for(i=0;i<n;i++) printf("%d ",d[i]);
    return 0;
}

#include <stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    int t[3*n-2];
    for(i=0;i<3*n-2;i++) scanf("%d",&t[i]);
    for(i=0;i<3*n-2;i++) printf("%d ",t[i]);
    return 0;
}


#include <stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    int size=n*(n+1)/2;
    int a[size];
    for(i=0;i<size;i++) scanf("%d",&a[i]);
    for(i=0;i<size;i++) printf("%d ",a[i]);
    return 0;
}

#include <stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    int size=n*(n+1)/2;
    int a[size];
    for(i=0;i<size;i++) scanf("%d",&a[i]);
    for(i=0;i<size;i++) printf("%d ",a[i]);
    return 0;
}

#include <stdio.h>
int main(){
    int t[10][3],tr[10][3],i,j,k;
    scanf("%d%d%d",&t[0][0],&t[0][1],&t[0][2]);
    for(i=1;i<=t[0][2];i++) scanf("%d%d%d",&t[i][0],&t[i][1],&t[i][2]);
    tr[0][0]=t[0][1]; tr[0][1]=t[0][0]; tr[0][2]=t[0][2];
    k=1;
    for(i=0;i<t[0][1];i++)
        for(j=1;j<=t[0][2];j++)
            if(t[j][1]==i){
                tr[k][0]=t[j][1];
                tr[k][1]=t[j][0];
                tr[k][2]=t[j][2];
                k++;
            }
    for(i=0;i<=t[0][2];i++)
        printf("%d %d %d\n",tr[i][0],tr[i][1],tr[i][2]);
    return 0;
}


#include <stdio.h>
int main(){
    int a[10][3],b[10][3],c[20][3],i,j,k;
    scanf("%d%d%d",&a[0][0],&a[0][1],&a[0][2]);
    for(i=1;i<=a[0][2];i++) scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
    scanf("%d%d%d",&b[0][0],&b[0][1],&b[0][2]);
    for(i=1;i<=b[0][2];i++) scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);

    i=j=k=1;
    while(i<=a[0][2] && j<=b[0][2]){
        if(a[i][0]==b[j][0] && a[i][1]==b[j][1]){
            c[k][0]=a[i][0]; c[k][1]=a[i][1]; c[k][2]=a[i][2]+b[j][2];
            i++; j++; k++;
        }
        else if(a[i][0]<b[j][0] || (a[i][0]==b[j][0] && a[i][1]<b[j][1])){
            c[k][0]=a[i][0]; c[k][1]=a[i][1]; c[k][2]=a[i][2];
            i++; k++;
        }
        else{
            c[k][0]=b[j][0]; c[k][1]=b[j][1]; c[k][2]=b[j][2];
            j++; k++;
        }
    }
    while(i<=a[0][2]){ c[k][0]=a[i][0]; c[k][1]=a[i][1]; c[k][2]=a[i][2]; i++; k++; }
    while(j<=b[0][2]){ c[k][0]=b[j][0]; c[k][1]=b[j][1]; c[k][2]=b[j][2]; j++; k++; }
    c[0][0]=a[0][0]; c[0][1]=a[0][1]; c[0][2]=k-1;

    for(i=0;i<k;i++) printf("%d %d %d\n",c[i][0],c[i][1],c[i][2]);
    return 0;
}


#include <stdio.h>
int main(){
    int a[]={2,4,1,3,5}, n=5, i,j,c=0;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(a[i]>a[j]) c++;
    printf("%d",c);
    return 0;
}


#include <stdio.h>
int main(){
    int a[]={1,2,2,3,4,4,5},n=7,i,j,count=0,f;
    for(i=0;i<n;i++){
        f=0;
        for(j=0;j<i;j++) if(a[i]==a[j]) { f=1; break; }
        if(!f) count++;
    }
    printf("%d",count);
    return 0;
}


