#include<cstring>
#include<cstdio>
#define M 100
typedef struct
{
    int x;    //非零元素行
    int y;    //非零元素列
    int v;   //非零元素本身的值
}node;         //即非零元素所对应的三元组
typedef struct
{
    int nu;   //矩阵的行
    int mu;   //矩阵的列
    int tu;   //矩阵非零元素的个数
    node data[2000];
}matrix;       //整个矩阵的所有三元组所组成的结构
matrix A;
matrix B;
void trans_A()     //矩阵转置
{
    B.mu=A.nu;
    B.nu=A.mu;
    B.tu=A.tu;
    if(B.tu>0)
    {
        int p=1;
        for(int j=1;j<=A.mu;j++)
        {
            for(int i=1;i<=A.tu;i++)
            {
                if(A.data[i].y==j)
                {
                    B.data[p].x=A.data[i].y;
                    B.data[p].y=A.data[i].x;
                    B.data[p].v=A.data[i].v;
                    p++;
                }
            }
        }
    }
}
int main()
{
    int r,c;
    int num;
    int t=1;
    printf("请输入你要转置矩阵的行与列(中间用空格隔开)：\n"); 
    scanf("%d%d",&r,&c);
    A.mu=r;
    A.nu=c;
    A.tu=0;
    printf("请输入矩阵\n");
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            scanf("%d",&num);
            if(num!=0)       //非零元素进三元表
            {
                A.data[t].x=i;
                A.data[t].y=j;
                A.data[t].v=num;
                t++;
                A.tu++;
            }
        }
    }
    trans_A();         //矩阵转置
    t=1;
    int sum=0;
    printf("转置后的矩阵\n"); 
    for(int i=1;i<=c;i++)
    {
        for(int j=1;j<=r;j++)
        {
            if(B.data[t].x==i&&B.data[t].y==j)
            {
                printf("%d ",B.data[t].v);
                t++;
            }
            else
                printf("0 ");
            sum++;
            if(sum%r==0)
                printf("\n");
        }
    }
    return 0;
}
































