#include<stdio.h>
#include<unistd.h>
#include<string.h>

main()
{
  int p1[2],p2[2],p3[2];
  int i,j=0,k=0,l=0;
  char r[10],s[10],t[10];
  printf("\n PROCESS 1.Enter the string\n");
  scanf("%s",r);
  pipe(p1);
  write(p1[1],r,sizeof(r));
  int a=fork();
  if(a==0)
  {
    printf("\np2 %d\n",getpid());
    printf("\n PROCESS 2.Splits the given string\n");
    
    read(p1[0],r,sizeof(r));
    int n=strlen(r);
    
    for(i=n/2;i<=n;i++)
    {
      t[j++]=r[i];
    }
    
    pipe(p2);
    write(p2[1],t,sizeof(t));
    
    int c=fork();
    if(c==0)
    {
      printf("\np3 %d\n",getpid());
      read(p2[0],t,sizeof(t));
      printf("\n PROCESS 3.Second half is %s \n",t);
      printf("\nNo of characters = %d \n",strlen(t));
     }
   }
}
