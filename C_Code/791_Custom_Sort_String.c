// 解题思路：
// 1.分开两个数组，T中含有S中的字符，和不含有的字符
// 2.统计含有的字符出现的次数
// 3.计算结果，从S开始遍历，把出现的字符以及次数写入result，最后再把不含有的拼接到result
char* customSortString(char* S, char* T) {
    char *no = (char*)malloc(200);
    memset(no,'0',200);

    int index_no = 0;

  
    char *tmpT = T;

    while(*tmpT){
        if (!strchr(S,*tmpT)) {//不含有
            no[index_no] = *tmpT;
            index_no++;
            no[index_no] = '\0';
        }else{
            no[index_no] = '\0';
        }

        *tmpT++;
    }

    tmpT = (char *)malloc(strlen(T)+1);
    strcpy(tmpT,T);

    char has_letter[26];
    int has_letter_index = 0;
    int has_count[26];
    int has_count_index = 0;
    int lengS = strlen(S);
    int count = 0;
    for(int i = 0; i < lengS; i++)
    {
        char S_char = S[i];
        
        if (strchr(T,S_char)) {
            count = 0;
            has_letter[has_letter_index] = S_char;
            has_letter_index++;

            for(int j = 0; j < strlen(T); j++)
            {
                if (T[j] == S_char){
                    count++;
                    tmpT[j] = '0';
                }
            }

            has_count[has_count_index] = count;
            has_count_index++;
            
        }
        
        
    }

    char *result = (char *)malloc(200);
    int resul_index = 0;
    for(int i = 0; i < has_letter_index; i++)
    {
        for(int j = 0; j < has_count[i]; j++)
        {
            result[resul_index] = has_letter[i];
            resul_index++;
        }
        
    }

    strcat(result,no);
    
    return result;
}