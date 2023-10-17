#include<iostream>
using namespace std;
#define size 5
int A[size],top=-1;
bool isempty()
{
 if(top==-1)
   return true;
 else
   return false;
}
void push(int value)
{
   if(top==size-1){
      cout<<"Stack is full";}
   else{
      top++;
      A[top]=value;
   }
}
void pop()
{
   if(isempty())
      cout<<"Stack is empty";
   else
   top--;
}
void show_top(){
if(isempty())
   cout<<"stack is empty";
else cout<<"element at top is:"<<A[top];
}
void displaystack()
{
if(isempty())
    {
       cout<<"Stack is empty";}
       else{
         for(int i=0; i<=top; i++)
            cout<<A[i]<<" ";
         cout<<"\n";
       }

}
int main(){
int value;
push(23);
push(40);
push(47);
displaystack();
pop();
displaystack();
show_top();

}
