bool buddyStrings(char* A, char* B) {
        int lengthA = strlen(A);
    int lengthB = strlen(B);

    if (lengthA != lengthB) {
        return false;
    }

    for(int i = 0; i<lengthA; i++){
        char a = A[i];
        if(strchr(B,a)){//包含这个字符

            if (i == lengthA - 2) {//最后两个字符的交换
                char *tmpA = (char*)malloc(lengthA*sizeof(char));
                strcpy(tmpA,A);
                char tmp = A[i];
                char tmpNext = A[i+1];
                tmpA[i] = tmpNext;
                tmpA[i+1] = tmp;
                if (!strcmp(tmpA,B)) {
                    free(tmpA);
                    return true;
                }
                free(tmpA);
            }
            
            if (a != A[i+1]) {
                for(int j = i+1; j < lengthA; j++)
                {
                    char *tmpA = (char*)malloc(lengthA*sizeof(char));
                    strcpy(tmpA,A);
                    char tmp = A[i];
                    char tmpNext = A[j];
                    tmpA[i] = tmpNext;
                    tmpA[j] = tmp;
                    if (!strcmp(tmpA,B)) {
                        free(tmpA);
                        return true;
                    }
                    free(tmpA);
                
                }
            }
            
            

        }else{
            return false;
        }
    }

    return false;
}