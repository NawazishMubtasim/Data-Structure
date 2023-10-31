#include<iostream>
using namespace std;
main()
{
    cout<<"Enter the size of the array:";
    int size;
    cin>>size;
    int arr[size];
    int i,temp=0,j;
    cout<<"Enter the Element of the array:\n";
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }
int First_element=arr[0], Second_element=arr[1],sum, Closest_Zero_Sum=First_element+Second_element;

   for(i=0;i<size-1;i++)
   {

       for(j=i+1;j<size;j++)
       {
            sum=arr[i]+arr[j];
            if(abs(sum)<=abs(Closest_Zero_Sum))
            {
                Closest_Zero_Sum=sum;
                First_element=arr[i];
                Second_element=arr[j];
            }
       }
   }
   cout<<"Closest to Zero Pair is ("<<First_element<<","<< Second_element<<")";
}
