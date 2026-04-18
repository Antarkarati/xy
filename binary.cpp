#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int n,int t)
{
    int left=0;
    int right=n-1;

    while(left<=right)
    {
        int mid=left+(right-left)/2;

        if(arr[mid]==t) return mid;
        if(arr[mid]<t) left=mid+1;
        else right=mid-1;
    }

    return -1;
}

int main()
{
    int arr[]={10,20,40,50,70,890};

    int t=90;
    int n=sizeof(arr)/sizeof(arr[0]);

    int r=binarySearch(arr,n,t);

    if(r==-1) cout<<" Not found";
    else cout<<" found at"<<r+1;

    return 0;
}
