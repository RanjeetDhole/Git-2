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
     char Data[100];
     int iRet = 0;

     int fd = 0;   //File Discriptor
     
     printf("Enter File name to open\n");
     scanf("%s",Fname);


     fd = open(Fname,O_RDWR|O_APPEND);
     if(fd == -1)
     {
          printf("Unable to open the file\n");
          return -1;            ///Failure
     }

     printf("File is succefully open with FD %d\n",fd);


     iRet = read(fd,Data,10);

     printf("%d bytes gets succesfully read from file\n",iRet);

     printf("Data from file is: %s\n",Data);

   

  

     return 0;
}