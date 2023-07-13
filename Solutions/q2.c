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


    ll start_char=atoi(argv[2]);
    ll end_char=atoi(argv[3]);

    int fd1 = open(file_name,O_RDWR);
    if(fd1 == -1){          // error handling
        perror("Program");  // print program detail "Success or failure" 
    }

    mkdir("Assignment/",S_IRUSR | S_IWUSR | S_IXUSR );
    strcat(file_path,"2_");
    strcat(file_path,file_name);


    int fd2 = open(file_path,O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if(fd2 == -1){          // error handling
        perror("Program");  // print program detail "Success or failure"
    }
    
    ll size_val=-1;
    ll TOTAL_SIZE = lseek(fd1,0,SEEK_END);
    ll i=1;


    // 0 TO START_CHAR
    while((start_char-BUFF_SIZE*i)>=0){
        lseek(fd1,start_char-BUFF_SIZE*i,SEEK_SET);
        
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
        long double val=(((long double)BUFF_SIZE*i*100)/TOTAL_SIZE);
        int LengthUsed = sprintf(msg, "\rPercentage: %Lf%c", val,'%');
        write(STDOUT_FILENO, msg, LengthUsed);

        i++; // NEXT CHUNK
    }
    

    //REMAINING DATA LESS THAN CHUNK SIZE - BUFF_SIZE
    ll start=(start_char%BUFF_SIZE)-1;
    for(i=start;i>=0;i--){
        lseek(fd1,i,SEEK_SET);

        // READ CHARACTER BY CHARACTER
        size_val = read(fd1,BUFF,1);
        if(size_val==-1){
            perror("Error in READING the File!! -");
            break;
        }
        BUFF[size_val] = '\0';

        // WRITE CHARACTER BY CHARACTER
        int ret_val = write(fd2, BUFF, strlen(BUFF));
        if(ret_val!=size_val){
            perror("Error - (Read Buff != Write Buff) !! -");
            break;
        }

        // PRINTING THE FILE TRANSFER RATE
        strcpy(msg,"");
        long double val=(((long double)(start_char-i)*100)/TOTAL_SIZE);
        int LengthUsed = sprintf(msg, "\rPercentage: %Lf%c", val,'%');
        write(STDOUT_FILENO, msg, LengthUsed); 
    }
    



    // START_CHAR TO END_CHAR
    i=start_char;
    while((i+BUFF_SIZE-1)<=end_char){
        lseek(fd1,i,SEEK_SET);
        
        // READ INPUT FILE
        size_val = read(fd1,BUFF,BUFF_SIZE);
        if(size_val==-1){
            perror("Error in READING the File!! -");
            break;
        }
        BUFF[size_val] = '\0';

        // WRITE OUTPUT FILE
        ll ret_val = write(fd2, BUFF, strlen(BUFF));
        if(ret_val!=size_val){
            perror("Error - (Read Buff != Write Buff) !! -");
            break;
        }

        // PRINTING THE FILE TRANSFER RATE
        i+=BUFF_SIZE; // NEXT CHUNK
        strcpy(msg,"");
        long double val=(((long double)(i)*100)/TOTAL_SIZE);
        int LengthUsed = sprintf(msg, "\rPercentage: %Lf%c", val,'%');
        write(STDOUT_FILENO, msg, LengthUsed);

    }

    
    //REMAINING DATA LESS THAN CHUNK SIZE - BUFF_SIZE
    while(i<=end_char){
        lseek(fd1,i,SEEK_SET);

        // READ CHARACTER BY CHARACTER
        size_val = read(fd1,BUFF,1);
        if(size_val==-1){
            perror("Error in READING the File!! -");
            break;
        }
        BUFF[size_val] = '\0';

        // WRITE CHARACTER BY CHARACTER
        int ret_val = write(fd2, BUFF, strlen(BUFF));
        if(ret_val!=size_val){
            perror("Error - (Read Buff != Write Buff) !! -");
            break;
        }
        i++;
        // PRINTING THE FILE TRANSFER RATE
        strcpy(msg,"");
        long double val=(((long double)(i)*100)/TOTAL_SIZE);
        int LengthUsed = sprintf(msg, "\rPercentage: %Lf%c", val,'%');
        write(STDOUT_FILENO, msg, LengthUsed); 
    }
    



    // END_CHAR TO END OF FILE
    i=1;
    while((TOTAL_SIZE-BUFF_SIZE*i)>end_char){
        lseek(fd1,TOTAL_SIZE-BUFF_SIZE*i,SEEK_SET);
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
            strcpy(msg,"Error - (Read Buff != Write Buff) !!\n");
            write(STDOUT_FILENO, msg, strlen(msg));
            break;
        }

        // PRINTING THE FILE TRANSFER RATE
        strcpy(msg,"");
        long double val=((((long double)(BUFF_SIZE*i+end_char+1))*100)/TOTAL_SIZE);
        int LengthUsed = sprintf(msg, "\rPercentage: %Lf%c", val,'%');
        write(STDOUT_FILENO, msg, LengthUsed);

        i++; // NEXT CHUNK
    }

    //REMAINING DATA LESS THAN CHUNK SIZE - BUFF_SIZE
    start=((TOTAL_SIZE-end_char-1)%BUFF_SIZE)+end_char;
    for(i=start;i>end_char;i--){
        lseek(fd1,i,SEEK_SET);

        // READ CHARACTER BY CHARACTER
        size_val = read(fd1,BUFF,1);
        if(size_val==-1){
            perror("Error in READING the File!! -");
            break;
        }
        BUFF[size_val] = '\0';

        // WRITE CHARACTER BY CHARACTER
        int ret_val = write(fd2, BUFF, strlen(BUFF));
        if(ret_val!=size_val){
            perror("Error - (Read Buff != Write Buff) !! -");
            break;
        }

        // PRINTING THE FILE TRANSFER RATE
        strcpy(msg,"");
        long double val=(((long double)(TOTAL_SIZE-i+end_char+1)*100)/TOTAL_SIZE);
        int LengthUsed = sprintf(msg, "\rPercentage: %Lf%c", val,'%');
        write(STDOUT_FILENO, msg, LengthUsed); 
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