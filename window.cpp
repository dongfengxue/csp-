#include<iostream>
#include<cstdio>


using namespace std;

struct
{
    int winno;
    int x1,y1,x2,y2;
} win[10];

struct
{
    int x,y;
} point[10];

int main()
{
    int m,n;
    int now_win;
    cin>>m;
    cin>>n;
//int x1,y1,x2,y2;
   // int a[2560][1440];
    for(int i=0; i<m; i++)                  //����������
    {
        win[i].winno=i+1;
        cin>>win[i].x1>>win[i].y1>>win[i].x2>>win[i].y2;
        //cin>>win[i].y1;
        //cin>>win[i].x2;
       // cin>>win[i].y2;
    }
    now_win=m;
    for(int j=0; j<n; j++)          //����������
        cin>>point[j].x>>point[j].y;
       // cin>>click[j].b;
    int win_num,tmp;
    int order[10];
    for(int k=0;k<m;k++)        //����˳��
        order[k]=m-1-k;
    for(int i=0;i<n;i++)
 {
     win_num=-1;             //��ʼ��Ϊ-1 ����ʾδ�����
    for(int j=0; j<m; j++)
    {
        if(win[order[j]].x1 <= point[i].x && point[i].x <= win[order[j]].x2 &&
            win[order[j]].y1 <= point[i].y && point[i].y <= win[order[j]].y2)  //������ڸô��ڷ�Χ��
        {
            win_num=win[order[j]].winno;
            cout<<win[i].winno<<endl;

            tmp=order[j];
            for(int k=j;k>0;k--)
                order[k]=order[k-1];
            order[0]=tmp;

        break;
        }
    }

    if(win_num == -1)
        cout<<"IGNORED"<<endl;
 }
return 0;
}
