#include<dirent.h>

main()
 {
   struct dirent**namelist;
   int n;
   n=scandir("/media/athira/Education/Labs/Systems Lab_S6",&namelist,0,alphasort);
   if(n<0)
     perror("scandir");
   else
     {
        while(n--)
          {
            printf("%s \n",namelist[n]->d_name);
            free(namelist[n]);
          }
       free(namelist);
    }
 }
 
