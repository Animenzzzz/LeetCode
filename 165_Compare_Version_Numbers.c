// 解题思路：
// 1.通过.来进行分组，将每个.分割出的字符变成整形存到数组中
// 2.遍历两个数组进行比较
int compareVersion(char* version1, char* version2) {
    int leng1 = strlen(version1);
    int leng2 = strlen(version2);
    int index1 = 0;
    int index2 = 0;

    int v1Array[1000000];
    int v2Array[1000000];
    int a1 = 0;
    int a2 = 0;
    long int sum1 = 0;
    long int sum2 = 0;

    while(leng1 || leng2){

        //过滤前导0
        if(version1[index1]!='\0'){
            if (version1[index1] != '.') { // 数字
                sum1 = sum1*10 + version1[index1] - '0';
                v1Array[a1] = sum1;
            }else{// 小数点
                sum1 = 0;
                a1++;
            }

            leng1--;
            index1++;
        }

        if(version2[index2]!='\0'){
            if (version2[index2] != '.') {// 数字
                sum2 = sum2*10 + version2[index2] - '0';
                v2Array[a2] = sum2;
            }else{// 小数点
                sum2 = 0;
                a2++;
            }

            leng2--;
            index2++;
        }
    }


    index1 = 0;
    index2 = 0;
    int tmpa1 = a1; 
    int tmpa2 = a2;
    while(a1>=0 || a2>=0){
        if (v1Array[index1] > v2Array[index2]) {
            return 1;
        }else if (v1Array[index1] == v2Array[index2]) {
            a1--;
            a2--;
            index1++;
            index2++;
            if (a1 < 0 && a2 < 0) {
                return 0;
            }else if (a1 < 0) {

                int result = -1;
                for(int i = index2; i <= tmpa2; i++)
                {
                    if (v2Array[i] == 0) {
                        result = 0;
                    }else{
                        result = -1;
                    }
                    
                }

                return result;
            }else if (a2 < 0) {

                int result = 1;
                for(int i = index1; i <= tmpa1; i++)
                {
                    if (v1Array[i] == 0) {
                        result = 0;
                    }else{
                        result = 1;
                    }
                    
                }

                return result;
            }
            
            
        }else{
            return -1;
        }
    }

    return 0;
}