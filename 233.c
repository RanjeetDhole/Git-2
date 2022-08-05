#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


//Read = 4
//Write = 2
//Execute = 1

//Permission = 0_Owner_Group_Other 

int main()
{
     char Fname[20];

     int fd = 0;   //File Discriptor
     printf("Enter File name to create\n");
     scanf("%s",Fname);

     fd = creat(Fname,0777);
     if(fd == -1)
     {
          printf("Unable to create the file\n");
          return -1;
     }

     printf("File is succefully created with FD %d\n",fd);



     return 0;
}