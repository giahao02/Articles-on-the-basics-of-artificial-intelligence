#include<iostream>
#include<fstream>
using namespace std;

int n,p,v,cs;
int Cost;
int mtTP[20][20];
int Tour[10][20];
int mCost[10];
int Flag[20];

void Input()
{
     ifstream f("Input.txt", ifstream::in);; // mo file
     if(f.bad()) // kiem tra file, neu file chua dc tao
     {
                printf("\n\t File khong ton tai. \n\n");
     }
     f>>n>>v;
     for(int i=0;i<n;i++)
             for(int j=0;j<n;j++)
             {
                     f>>mtTP[i][j];
                     cout<<"sds";
             }          
     f.close();
}

int GTS1(int v)
{
     for(int i=0;i<=n;i++) Flag[i]=0;
     int t=v;
     int dem=0;
     Tour[t][0]=v;
     Cost=0;
     Flag[v]=1;
     int tmp=v;
     while(dem!=n-1)
     {
            int tmpCost=100;
            int co;
            for(int i=1;i<=n;i++)
            {
                    if(tmpCost>mtTP[v][i] && Flag[i]==0 && mtTP[v][i]!=-1)
                    {
                                          tmpCost=mtTP[v][i];
                                          co=i;
                    }
            }
            dem++;
            Tour[t][dem]=co;
            Cost+=tmpCost;
            Flag[v]=1;
            v=co;
     }
     Cost+=mtTP[v][tmp];
     mCost[t]=Cost;
     return Cost;
}

void GTS2()
{
     int tmp=100;
     for(int i=1;i<=p;i++)
     {
             int a =GTS1(i);
             if(tmp>a)
             {
                      tmp=a;
                      cs=i;
             }
     }
}

void Output(int cs)
{
     ofstream g;
     g.open("Output.txt");
     g<<"Chi phi cho qua trinh :"<<mCost[cs]<<endl;
     g<<"Hanh trinh nhu sau :";
     for(int i=0;i<n;i++)
             g<<Tour[cs][i]<<" -->";
     g<<Tour[cs][0]<<endl;
}

int main()
{
    Input();
    GTS2();
    Output(cs);
    return 0;
}
