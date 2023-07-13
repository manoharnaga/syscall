## OSANDNW  - Assignment - 1
### RollNO: **2021101128**

        typedef long long ll    -     is used in all 3 questions.
        MAX INPUT ARGUMENT SIZE -     1e4/PER ARGUMENT
        BUFF - BUFFER FOR INPUT FILE READING
        rev_BUFF - BUFFER FOR OUTPUT FILE WRITING
        BUFF1 - BUFFER TO CHECK STRINGS - Q3


### **Q1**
**Compilation Format:**

    - gcc q1.c
    - ./a.out inputFilePath
    - OUTPUT FILE_NAME: 1_inputFilePath

    The OUTPUT FILE will be stored Under Assignment Directory - Assignment/1_inputFilePath
    Assignment Directory is created in the Current Working Directory.
    CHUNK SIZE --> BUFF_SIZE = 1e6
    reverse_chunk - Function copies the reverse of BUFF TO rev_BUFF
    The code Contains to Parts:
      1.REVERSE BY CHUNKS  : Reverses the text by chunks of size BUFF_SIZE.Percentage increases CHUNK BY CHUNK
      2.REVERSE BY CHARACTERS: For Remaining text less than CHUNK size it is reversed Character By Character.Percentage increases CHARACTER BY CHARACTER


### **Q2**
**Compilation Format:**

    - gcc q2.c
    - ./a.out inputFilePath start _char end_char
    - OUTPUT FILE_NAME: 2_inputFilePath

    The OUTPUT FILE will be stored Under Assignment Directory - Assignment/2_inputFilePath
    Assignment Directory is created in the Current Working Directory.
    CHUNK SIZE --> BUFF_SIZE = 1e6
    reverse_chunk - Function copies the reverse of BUFF TO rev_BUFF
    The code Contains to 3 Parts:
                    1. 0 TO START_CHAR  : REVERSES the Text from 0 to START_CHAR-1
                    2. START_CHAR TO END_CHAR : Writes the Text from START_CHAR to END_CHAR as it is
                    3. END_CHAR TO END OF FILE : REVERSES the Text from END_CHAR to END OF FILE

    FOR EACH PART code Contains 3 SUB Parts:
      1.REVERSE BY CHUNKS  : Reverses the text by chunks of size BUFF_SIZE.Percentage increases CHUNK BY CHUNK
      2.REVERSE BY CHARACTERS: For Remaining text less than CHUNK size it is reversed Character By Character.Percentage increases CHARACTER BY CHARACTER


### **Q3**
**Compilation Format:**

    - gcc q3.c
    - ./a.out inputFileName oldFileName Directory_Name
    THE OUPUT IS PRINTED WITH 9 PROPERTIES FOR NEWFILE,OLDFILE,DIRECTORY
    Example Output:
    
            Directory is created: Yes

            User has read permissions on newfile: Yes
            User has write permission on newfile: Yes
            User has execute permission on newfile: No
            Group has read permissions on newfile: No
            Group has write permissions on newfile: No
            Group has execute permissions on newfile: No
            Others has read permissions on newfile: No
            Others has write permissions on newfile: No
            Others has execute permissions on newfile: No

            User has read permissions on oldfile: Yes
            User has write permission on oldfile: Yes
            User has execute permission on oldfile: No
            Group has read permissions on oldfile: No
            Group has write permissions on oldfile: No
            Group has execute permissions on oldfile: No
            Others has read permissions on oldfile: No
            Others has write permissions on oldfile: No
            Others has execute permissions on oldfile: No

            User has read permissions on Directory: Yes
            User has write permission on Directory: Yes
            User has execute permission on Directory: Yes
            Group has read permissions on Directory: No
            Group has write permissions on Directory: No
            Group has execute permissions on Directory: No
            Others has read permissions on Directory: No
            Others has write permissions on Directory: No
            Others has execute permissions on Directory: No

            Whether file contents are reversed in newfile: Yes


