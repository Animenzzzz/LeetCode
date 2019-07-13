int calculate(char* s) {
    char *noSpace = (char *)malloc(strlen(s)+1);
    memset(noSpace,'0',strlen(s));
    noSpace[strlen(s)] = '\0';
    int spaceindex = 0;
    while(*s){
        
        if (*s != ' ') {
            noSpace[spaceindex] = *s;
            spaceindex++;
            noSpace[spaceindex] = '\0';
        }
        
        *s++;
        
    }

    if(!strchr(noSpace,'-') && !strchr(noSpace,'+')&&!strchr(noSpace,'*')&&!strchr(noSpace,'/')){
        return atoi(noSpace);
    }

    int index_dig = 0;
    int index_char = 0;
    long int sum = 0;
    long int digitArray[1000000];
    char fuhao[1000000];
    while(*noSpace){
        
        if (*noSpace >= '0' && *noSpace <= '9') {
            sum = sum*10 + (*noSpace - '0');
            digitArray[index_dig] = sum;
        }else if (*noSpace == '+' || *noSpace == '-') {
            sum = 0;
            index_dig++;

            fuhao[index_char] = *noSpace;
            index_char++;
        }else if (*noSpace == '/' || *noSpace == '*') {
            sum = 0;
            index_dig++;

            fuhao[index_char] = *noSpace;
            index_char++;
        }else{
            sum = 0;
            index_dig++;
        }
        *noSpace++;
    }

    if (sum) {
        index_dig++;
    }
    


    //计算乘除
    sum = 0;
    for(int i = 0;i<index_char;i++){
        char zifu = fuhao[i];
        if (zifu == '/') {
            fuhao[i] = '+';
            if (i>0) {
                if(fuhao[i-1] == '-'){
                    fuhao[i] = '-';
                }
            }
            sum = digitArray[i] / digitArray[i+1];
            digitArray[i] = 0;
            digitArray[i+1] = sum;
        }else if (zifu == '*') {
            fuhao[i] = '+';
            if (i>0) {
                if(fuhao[i-1] == '-'){
                    fuhao[i] = '-';
                }
            }
            
            sum = digitArray[i] * digitArray[i+1];
            digitArray[i] = 0;
            digitArray[i+1] = sum;
        }
        
        
    }

    //计算加减
    sum = 0;
   
    for(int i = 1;i<index_dig;i++){
        char zifu = fuhao[i-1];
        if (zifu == '-') {
            sum = digitArray[i-1] - digitArray[i];
            digitArray[i] = sum;
        }else{
            sum = digitArray[i-1] + digitArray[i];
            digitArray[i] = sum;
        }
        
    }


    return sum;
}