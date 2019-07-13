char* addBinary(char* a, char* b) {
    int lengA = strlen(a);
    int lengB = strlen(b);
    char *tmpA = (char *)malloc(lengA*sizeof(char));
    char *tmpB = (char *)malloc(lengB*sizeof(char));
    if(lengA>=lengB){
        tmpA = a;
        tmpB = (char *)malloc(lengA+1);
        for(int i = 0;i < lengA-lengB;i++){
            tmpB[i] = '0';
        }

        int tmpindex = 0;
        for(int i = lengA-lengB;i < lengA;i++){
            tmpB[i] = b[tmpindex];
            tmpindex++;
        }

        tmpB[lengA] = '\0';
        // tmpA[lengA] = '\0';
    }else{
        tmpB = b;
        tmpA = (char *)malloc(lengB+1);
        for(int i = 0;i < lengB-lengA;i++){
            tmpA[i] = '0';
        }

        int tmpindex = 0;
        for(int i = lengB-lengA;i < lengB;i++){
            tmpA[i] = a[tmpindex];
            tmpindex++;
        }

        tmpA[lengB] = '\0';

    }

    // printf("AA:%s\n",tmpA);
    // printf("BB:%s\n",tmpB);
  
    

    int indextmp = strlen(tmpB);


    char *result = (char *)malloc((indextmp+2)*sizeof(char));
    memset(result,'0',indextmp+2);
    result[indextmp+1] = '\0';
    
    int jin = 0;
    while(indextmp){

        char c_a = tmpA[indextmp - 1];
        char c_b = tmpB[indextmp - 1];
        int res = c_a - '0' + c_b - '0' + jin;
        if(res == 3){
            jin = 1;
            result[indextmp] = '1';
        }else if(res == 2){
            jin = 1;
            result[indextmp] = '0';

        }else if(res == 1){
            jin = 0;
            result[indextmp] = '1';
        }else{
            jin = 0;
            result[indextmp] = '0';
        }
       
        --indextmp;
        if (indextmp == 0 && jin == 1) {
            result[0] = '1';
        }
        
    }

    if(result[0] == '0') return result+1;
    // printf("函数结果：%s \n",result);
    return result;
}