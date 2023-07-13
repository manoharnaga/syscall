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
    
    char file_path[10000],file_name[10000];
    char *BUFF = (char *) calloc(BUFF_SIZE+100, sizeof(char)); 
    char *rev_BUFF = (char *) calloc(BUFF_SIZE+100, sizeof(char)); 
    char msg[10000];

    strcpy(file_name,argv[1]);
    strcpy(file_path,"Assignment/");

    int fd1 = open(file_name,O_RDWR);
    if(fd1 == -1){          // error handling
        perror("Program");  // print program detail "Success or failure" 
    }

    mkdir("Assignment/",S_IRUSR | S_IWUSR | S_IXUSR);
    strcat(file_path,"1_");
    strcat(file_path,file_name);


    int fd2 = open(file_path,O_WRONLY | O_CREAT | O_TRUNC,0600);
    if(fd2 == -1){          // error handling
        perror("Program");  // print program detail "Success or failure"
    }
    
    
    ll size_val=-1;
    ll size_total = lseek(fd1,0,SEEK_END);
    ll i=1;

    // REVERSE BY CHUNKS
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

        // WRITE OUTPUT FILE
        ll ret_val = write(fd2, rev_BUFF, strlen(BUFF));
        if(ret_val!=size_val){
            perror("Error - (Read Buff != Write Buff) !! -");
            break;
        }

        // PRINTING THE FILE TRANSFER RATE
        strcpy(msg,"");
        long double val=(((long double)BUFF_SIZE*i*100)/size_total);
        int LengthUsed = sprintf(msg, "\rPercentage: %Lf%c", val,'%');
        write(STDOUT_FILENO, msg, LengthUsed);

        i++; // NEXT CHUNK
    }
    

    //REVERSE THE REMAINING DATA LESS THAN CHUNK SIZE - BUFF_SIZE
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

        // WRITE CHARACTER BY CHARACTER
        ll ret_val = write(fd2, BUFF, strlen(BUFF));
        if(ret_val!=size_val){
            perror("Error - (Read Buff != Write Buff) !! -");
            break;
        }

        // PRINTING THE FILE TRANSFER RATE
        strcpy(msg,"");
        long double val=(((long double)(size_total-i)*100)/size_total);
        int LengthUsed = sprintf(msg, "\rPercentage: %Lf%c", val,'%');
        write(STDOUT_FILENO, msg, LengthUsed); 

        i--;    //NEXT CHARACTER
    }
    strcpy(msg,"\n");
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