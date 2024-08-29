#include<iostream>
using namespace std;
int no_of_shops(int S[],int E[],int k,int n)
{
    int cnt=0;
    int arr[k]={0};
    for(int i=0;i<n;i++)
    {
        int start=S[i];
        int end=E[i];
        for(int j=0;j<k;j++)
        {
            if(arr[j]<=start)
            {
                arr[j]=end;
                cnt++;
                break;
            }
         }
        }
        return cnt;
        }
    int main()
    {
        int S[]={1,8,3,3,6};
        int E[]={5,10,6,5,9};
        int k=2;
        cout<<"Max shops are"<<no_of_shops(S,E,k,5);
        return 0;
    }