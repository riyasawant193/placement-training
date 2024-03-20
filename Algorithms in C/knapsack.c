#include<stdio.h>
void main()
{
int n,w[50],p[50],i,j;
float xr,x[50],total_profit=0,total_weight=0,ratio[50],u,m,temp;
printf("\nEnter number of items : ");
scanf("%d",&n);
printf("Enter capacity of knapsack : ");
scanf("%f",&m);
u=m;
for(i=0;i<n;i++)
{
x[i]=0;
}
printf("\nEnter the weights of each object\n");
for(i=0;i<n;i++)
{
printf("\tWeights of object %d = ", i+1);
scanf("%d",&w[i]);
}
printf("\nEnter the profit of each object \n");
for(i=0;i<n;i++)
{
printf("\tProfit of object %d = ", i+1);
scanf("%d",&p[i]);
}
for(i=0;i<n;i++)
{
ratio[i]=((float)p[i] / (float)w[i]);
}
int obj[n];
for(i=0;i<n;i++)
{
obj[i]=i+1;
}
for(i=0;i<n;i++)
{
for(j=0;j<n-1;j++)
{
if(ratio[j]<ratio[i])
{
temp=ratio[i];
ratio[i]=ratio[j];
ratio[j]=temp;
temp=w[i];
w[i]=w[j];
w[j]=temp;
temp=p[i];
p[i]=p[j];
p[j]=temp;
temp=obj[i];
obj[i]=obj[j];
obj[j]=temp;
}
}
}
printf("\n Table after sorting according to profit-weight ratio : \n");
printf("\nObject:\t\t");
for(i=0;i<n;i++)
{
printf("%d\t\t",obj[i]);
}
printf("\nProfit:\t\t");
for(i=0;i<n;i++)
{
printf("%d\t\t",p[i]);
}
printf("\nWeights:\t");
for(i=0;i<n;i++)
{
printf("%d\t\t",w[i]);
}
printf("\nRatio:\t\t");
for(i=0;i<n;i++)
{
    printf("%f\t",ratio[i]);
}
printf("\n");
for(i=0;i<n;i++)
{
if(w[i]<=u)
{
x[i]=1;
u=u-w[i];
}
else if(w[i]>u)
{
break;
}
}
if(i<=n)
{
xr=(float)u/(float)w[i];
x[i]=xr;
}
printf("\n X=[");
for(i=0;i<n;i++)
{
printf("%.3f, ",x[i]);
}
printf("]");
for(i=0;i<n;i++)
{
total_profit+=x[i]*p[i];
total_weight+=x[i]*w[i];
}
printf("\n\nTotal weight=%.2f",total_weight);
printf("\nTotal profit=%.2f\n",total_profit);
}