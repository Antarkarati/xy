#include<bits/stdc++.h>
using namespace std;

#define INF 99999

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if(!inFile)
    {
        cout<<"Error .input.txt not found.creste it.";
        return 1;
    } 


    int n;
    inFile>>n;

    int path[10][10];

    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            inFile>>path[i][j];

            if(path[i][j]==0) path[i][j]=INF;
        }
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(path[i][j]>path[i][k]+path[k][j])
                    path[i][j]=path[i][k]+path[k][j];
            }
        }

    }


    outFile<<"The Shortest Path Matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(path[i][j]==INF) outFile<<"0 ";
            else
            outFile<<path[i][j]<<" ";
        }
        outFile<<"\n";
    }

    cout<<"Success\n";

    inFile.close();
    outFile.close();

    return 0;
}