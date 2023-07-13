#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE 1000000
typedef long long ll;

// void swap_char(char* a,char* b){
//     char temp;
//     temp=*a;
//     *a=*b;
//     *b=temp;
// }


void reverse_chunk(char* s1,char* s2,int n){
    int j=0;
    for(int i=n-1;i>=0;i--){
        s2[j++]=s1[i];
        // swap_char(&s[i],&s[n-i-1]);
    }
}


int main(int argc,char** argv){
    
    char dir_file[10000],new_file[10000],old_file[10000];
    char *BUFF = (char *) calloc(BUFF_SIZE+100, sizeof(char)); 
    char *rev_BUFF = (char *) calloc(BUFF_SIZE+100, sizeof(char)); 
    char *BUFF1 = (char *) calloc(BUFF_SIZE+100, sizeof(char));
    char msg[10000];

    strcpy(new_file,argv[1]);
    strcpy(old_file,argv[2]);
    strcpy(dir_file,argv[3]);

    // OPEN OLD FILE
    int fd1 = open(old_file,O_RDONLY);
    if(fd1 == -1){          // error handling
        perror("Program");  // print program detail "Success or failure" 
        return 0;
    }
    struct stat dirStat;    // STAT FOR DIRECTORY
    int fd_dir = open(dir_file,O_RDONLY);
    stat(dir_file,&dirStat);
    
    if(dirStat.st_mode & S_IFDIR){
        strcpy(msg,"Directory is created: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Directory is created: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    write(STDOUT_FILENO,"\n",1);
    
    strcat(dir_file,"/");
    strcat(dir_file,new_file);

    // OPEN NEW FILE
    int fd2 = open(dir_file,O_RDONLY);
    if(fd2 == -1){          // error handling
        perror("Program");  // print program detail "Success or failure" 
        return 0;
    }


    struct stat newFileStat;   // STAT FOR  NEW FILE IN DIRECTORY
    stat(dir_file,&newFileStat);
    // USER
    if(newFileStat.st_mode & S_IRUSR){
        strcpy(msg,"User has read permissions on newfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"User has read permissions on newfile: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(newFileStat.st_mode & S_IWUSR){
        strcpy(msg,"User has write permission on newfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"User has write permission on newfile: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(newFileStat.st_mode & S_IXUSR){
        strcpy(msg,"User has execute permission on newfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"User has execute permission on newfile: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    // GROUP
    if(newFileStat.st_mode & S_IRGRP){
        strcpy(msg,"Group has read permissions on newfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Group has read permissions on newfile: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(newFileStat.st_mode & S_IWGRP){
        strcpy(msg,"Group has write permissions on newfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Group has write permissions on newfile: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(newFileStat.st_mode & S_IXGRP){
        strcpy(msg,"Group has execute permissions on newfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Group has execute permissions on newfile: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    // OTHERS
    if(newFileStat.st_mode & S_IROTH){
        strcpy(msg,"Others has read permissions on newfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Others has read permissions on newfile: No\n"); 
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(newFileStat.st_mode & S_IWOTH){
        strcpy(msg,"Others has write permissions on newfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Others has write permissions on newfile: No\n"); 
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(newFileStat.st_mode & S_IXOTH){
        strcpy(msg,"Others has execute permissions on newfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Others has execute permissions on newfile: No\n"); 
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    write(STDOUT_FILENO,"\n",1);


    struct stat oldFileStat;   // STAT FOR  OLD FILE IN DIRECTORY
    stat(dir_file,&oldFileStat);
    // USER
    if(oldFileStat.st_mode & S_IRUSR){
        strcpy(msg,"User has read permissions on oldfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"User has read permissions on oldfile: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(oldFileStat.st_mode & S_IWUSR){
        strcpy(msg,"User has write permission on oldfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"User has write permission on oldfile: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(oldFileStat.st_mode & S_IXUSR){
        strcpy(msg,"User has execute permission on oldfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"User has execute permission on oldfile: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    // GROUP
    if(oldFileStat.st_mode & S_IRGRP){
        strcpy(msg,"Group has read permissions on oldfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Group has read permissions on oldfile: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(oldFileStat.st_mode & S_IWGRP){
        strcpy(msg,"Group has write permissions on oldfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Group has write permissions on oldfile: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(oldFileStat.st_mode & S_IXGRP){
        strcpy(msg,"Group has execute permissions on oldfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Group has execute permissions on oldfile: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    // OTHERS
    if(oldFileStat.st_mode & S_IROTH){
        strcpy(msg,"Others has read permissions on oldfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Others has read permissions on oldfile: No\n"); 
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(oldFileStat.st_mode & S_IWOTH){
        strcpy(msg,"Others has write permissions on oldfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Others has write permissions on oldfile: No\n"); 
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(oldFileStat.st_mode & S_IXOTH){
        strcpy(msg,"Others has execute permissions on oldfile: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Others has execute permissions on oldfile: No\n"); 
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    write(STDOUT_FILENO,"\n",1);

    // DIRECTORY
    // USER
    if(dirStat.st_mode & S_IRUSR){
        strcpy(msg,"User has read permissions on Directory: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"User has read permissions on Directory: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(dirStat.st_mode & S_IWUSR){
        strcpy(msg,"User has write permission on Directory: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"User has write permission on Directory: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(dirStat.st_mode & S_IXUSR){
        strcpy(msg,"User has execute permission on Directory: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"User has execute permission on Directory: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    // GROUP
    if(dirStat.st_mode & S_IRGRP){
        strcpy(msg,"Group has read permissions on Directory: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Group has read permissions on Directory: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(dirStat.st_mode & S_IWGRP){
        strcpy(msg,"Group has write permissions on Directory: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Group has write permissions on Directory: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(dirStat.st_mode & S_IXGRP){
        strcpy(msg,"Group has execute permissions on Directory: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Group has execute permissions on Directory: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    // OTHERS
    if(dirStat.st_mode & S_IROTH){
        strcpy(msg,"Others has read permissions on Directory: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Others has read permissions on Directory: No\n"); 
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(dirStat.st_mode & S_IWOTH){
        strcpy(msg,"Others has write permissions on Directory: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Others has write permissions on Directory: No\n"); 
        write(STDOUT_FILENO,msg,strlen(msg));
    }

    if(dirStat.st_mode & S_IXOTH){
        strcpy(msg,"Others has execute permissions on Directory: Yes\n");
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    else{
        strcpy(msg,"Others has execute permissions on Directory: No\n"); 
        write(STDOUT_FILENO,msg,strlen(msg));
    }
    write(STDOUT_FILENO,"\n",1);
    
    ll size_val=-1;
    ll size_total = lseek(fd1,0,SEEK_END);
    ll i=1;

    int flag=1;
    while((size_total-BUFF_SIZE*i)>=0){
        lseek(fd1,size_total-BUFF_SIZE*i,SEEK_SET);
        
        // READ INPUT FILE
        size_val = read(fd1,BUFF,BUFF_SIZE);
        if(size_val==-1){
            perror("Error in READING the File!! -");
            break;
        }
        BUFF[size_val] = '\0';

        // REVERSE THE CHUNK OF STRING READ 
        reverse_chunk(BUFF,rev_BUFF,size_val);

        ll ret_val = read(fd2, BUFF1, strlen(BUFF));
        if(ret_val==-1){
            perror("Error in READING the File!! -");
            break;
        }

        // CHECK FOR FILE REVERSAL
        if(strcmp(rev_BUFF,BUFF1)!=0){
            flag=0;
            break;
        }
        i++; // NEXT CHUNK
    }
    
    if(!flag){
        strcpy(msg,"Whether file contents are reversed in newfile: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
        return 0;
    }

    //REMAINING DATA LESS THAN CHUNK SIZE - BUFF_SIZE
    ll start=(size_total%BUFF_SIZE)-1;
    i=start;
    while(i>=0){
        lseek(fd1,i,SEEK_SET);

        // READ CHARACTER BY CHARACTER
        size_val = read(fd1,BUFF,1);
        if(size_val==-1){
            perror("Error in READING the File!! -");
            break;
        }
        BUFF[size_val] = '\0';

        // READ CHARACTER BY CHARACTER
        ll ret_val = read(fd2, BUFF1, strlen(BUFF));
        if(ret_val==-1){
            perror("Error in READING the File!! -");
            break;
        }
 
        // CHECK FOR FILE REVERSAL - CHARACTER BY CHARACTER
        if(BUFF[0]!=BUFF1[0]){
            flag=0;
            break;
        }

        i--;    //NEXT CHARACTER
    }
    
    if(!flag){
        strcpy(msg,"Whether file contents are reversed in newfile: No\n");
        write(STDOUT_FILENO,msg,strlen(msg));
        return 0;
    }
    
    strcpy(msg,"Whether file contents are reversed in newfile: Yes\n");
    write(STDOUT_FILENO,msg,strlen(msg));

    if(close(fd1)<0){
        perror("Program"); 
        return 0;
    }
    if(close(fd2)<0){
        perror("Program"); 
        return 0;
    }
    return 0;
}