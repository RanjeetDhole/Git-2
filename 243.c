// Open the file and write data into file
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

// O_RDONLY  Read
// O_WRONLY  Write
// O_RDWR    Read+ Write

int main()
{
     char Fname[20];
     char Data[10];         //Mug
     int iRet = 0;

     int fd = 0;   //File Discriptor
     
     printf("Enter File name to open\n");
     scanf("%s",Fname);


     fd = open(Fname,O_RDWR);
     if(fd == -1)
     {
          printf("Unable to open the file\n");
          return -1;            ///Failure
     }

     printf("File is succefully open with FD %d\n",fd);

     while((iRet = read(fd,Data,sizeof(Data))) !=0)
     {
          write(1,Data,iRet);
     }

     close(fd);


     

     return 0;
}
