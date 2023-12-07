
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* for fork */
#include <sys/types.h> /* for pid_t */
#include <sys/wait.h> /* for wait */
int main(int argc,char** argv)
{
/*Spawn a child to run the program.*/
pid_t pid=fork();
if (pid==0)
{ /* child process */
execv("/bin/ls",argv);
exit(127); /* only if execv fails */
}
else
{ /* pid!=0; parent process */
printf("\nWaiting Child process to finish");
//waitpid(pid,0,0); /* wait for child to exit */
wait(NULL);
}
printf("\nExiting main process\n");
return 0;
}
Output:
ui
dsfg
gfh
tyrert
yuk
sdg
cat p
ui
dsfg
gfh
tyrert
yuk
sdg

                             FIFO ALGORITHM
#include<stdio.h>
int main( )
{
int a [20],c[10],i,k,ps,nop,npf=0,nps=0;
printf ("\n\tEnter no of pages :" ) ;
scanf ("%d",& nop) ;
printf ("\n\tEnter pages :" ) ;
for (i=0;i<nop;i++)
{
scanf("%d",&a[i]);
}
printf("\n \t Enter no of page frames :") ;
scanf("%d",&ps);
for(i=0;i<nop;i++)
{
for(k=0;c[k]!=a[i]&&k<nps;k++);
if(k==nps)
{ npf++;
if(nps==ps)
for(k=0;k<nps-1;k++)
c[k]=c[k+1];
c[k]=a[i];
if(nps<ps)
nps++;
}
printf("\n");
for(k=0;k<nps;k++)
printf("%d",c[k]);
}
printf("\n \tNo of page faults occurred are %d",npf) ;
}
OUTPUT:
Enter no of pages: 20
Enter pages: 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
Enter no of page frames: 3
7
70
701
012
012
123
230
304
042
423
230
230
230
301
012
012
012
127
270
701
No of page faults occurred are 15


//                ROUND ROBIN
#include<stdio.h>
#include<string.h>
int main()
{
char p[10][5];
int et[10],wt[10],timer,count,pt[25],rt,i,j,totwt=0,n,found=0,m,tat[10],ttt=0;
float avgwt;
printf("Enter the no of process:\n");
scanf("%d",&n);
printf("Enter time slice:\n");
scanf("%d",&timer);
for(i=0;i<n;i++)
{
printf("Enter the process name:\n");
scanf("%s",&p[i]);
printf("Enter the process time:\n");
scanf("%d",&pt[i]);
}
m=n;
wt[0]=0;
i=0;
do
{
if(pt[i]>timer)
{
rt=pt[i]-timer;
strcpy(p[n],p[i]);
pt[n]=rt;
et[i]=timer;
n++;
}
else
{
et[i]=pt[i];
}
i++;
wt[i]=wt[i-1]+et[i-1];
}
while(i<n);
count=0;
for(i=0;i<n;i++)
{
for(j=i+1;j<=n;j++)
{
if(strcmp(p[i],p[j])==0)
{
count++;
found=j;
}
if(found!=0)
{
wt[i]=wt[found]-(count*timer);
count=0;
found=0;
}
}
}
for(i=0;i<m;i++)
{
totwt+=wt[i];
tat[i]=wt[i]+pt[i];
ttt=ttt+tat[i];
}
avgwt=(float)totwt/m;
printf("pname \t ptime \t wtime \tturnaroundtime\n");
for(i=0;i<m;i++)
{
printf("\n %s \t %d \t %d \t\t %d",p[i],pt[i],wt[i],tat[i]);
}
printf("\n Total waiting time: %d \n",totwt);
printf("\n Avg wating time: %f",avgwt);
printf("\n Total turnaroundtime: %d",ttt);
printf("\n Avg turnaround time: %f",(float)ttt/m);
}
OUTPUT:
Enter the number of Processes:3
Enter time slice:4
Enter the process name:A1
Enter the process time:4
Enter the process name:A2
Enter the process time:6
Enter the process name:A3
Enter the process time:3
pname ptime wtime turnaroundtime
A1 4 0 4
A2 6 7 13
A3 3 8 11
Total waiting time: 15
Avg.wating time: 5.000000
Total turnaroundtime: 28
Avg.turnaround time: 9.333333
