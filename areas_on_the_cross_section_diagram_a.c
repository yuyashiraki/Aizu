#include<stdio.h>
#include<string.h>

typedef struct Data{
  int area,pos;
} Data;

Data t[20000];

int u[20000];

int n,i;

char str[20001];

int T,U;

int ans,A;

Data B,X;

void D_push(Data data){
  t[T++]=data;
}

Data D_pop(){
  return t[--T];
}

void push(int x){
  u[U++]=x;
}

int pop(){
  return u[--U];
}


void init(){
  ans=T=U=0;
}

Data makeData(int x,int y){
  Data res;
  res.area=x;
  res.pos=y;
  return res;
}

int main(){
  init();
  scanf("%s",str);
  n=strlen(str);

  for(i=0;i<n;i++){

    if(str[i]=='/'){

      if(U==0)continue;
      A=pop();
      X=makeData(i-A,A);
      ans+=i-A;
      while(T>0){
  B=D_pop();
  if(B.pos<A){
    D_push(B);
    break;
  }
  X.area+=B.area;
  if(B.pos<X.pos)X.pos=B.pos;
      }
      D_push(X);
    }else if(str[i]=='\\'){
      push(i);
    }

  }
  
  printf("%d\n%d",ans,T);
  for(i=0;i<T;i++){
    printf(" %d",t[i].area);
  }
  printf("\n");
  return 0;
}
