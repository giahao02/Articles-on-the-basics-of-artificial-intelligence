#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;

int n,v;
int Cost;
int Tour[20];
int mtTP[20][20];
int Flag[20];

void Input()
{
     ifstream f; // tao file
     f.open("Input.txt"); // mo file
     if(f.bad()) // kiem tra file, neu file chua dc tao
     {
                printf("\n\t File khong ton tai. \n\n");
     }
     f>>n>>v;
     for(int i=1;i<=n;i++)
             for(int j=1;j<=n;j++)
             {
                     f>>mtTP[i][j];

             }
     for(int i=0;i<=n;i++) 
             Flag[i]=0;                
     f.close();
}

void Output()
{
     ofstream g;
     g.open("Output.txt");
     g<<"Chi phi cho qua trinh :"<<Cost<<endl;
     g<<"Hanh trinh nhu sau :";
     for(int i=0;i<n;i++)
             g<<Tour[i]<<" -->";
     g<<Tour[0]<<endl;
}
// theo thuat giai
void GTS1()
{
     int dem=0;
     Tour[0]=v;
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
            Tour[dem]=co;
            Cost+=tmpCost;
            Flag[v]=1;
            v=co;
     }
     Cost+=mtTP[v][tmp];
}
int main()
{
 printf("**************** TRI TUE NHAN TAO ******************* \n");
 printf("|                                                   | \n");  
 printf("************ KHOA CNTT - DH GTVT TPHCM ************** \n");
 printf("|     bai toan ung dung giai thuat GTS1             | \n");
 printf("***************************************************** \n\n\n\n\n");
    Input();
    GTS1();
    Output();
    return 0;
}
