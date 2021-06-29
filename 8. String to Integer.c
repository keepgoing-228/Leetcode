#include<stdio.h>
#include<stdlib.h>

int myAtoi(char* s){
    if(s == NULL)
        return 0;
    
    int i =0;
    bool neg = false;
    char c = s[i];
    
    while (c != '\0'){
        if (isdigit(c))
            break;
        
        char nextChar = s[i+1];
        if (nextChar =='\0')
            return 0;
        else if (c == '.' && isdigit(nextChar))
            return 0;
        else if (c == '+' || c =='-'){
            if ( !isdigit(nextChar))
                return 0;
            
            i++;
            
            if (c == '-')
                neg = true;
            
            break;
        }
        else if(isalpha(c))
            return 0;
        
        
        c = s[++i];
    }
    
    
    
    int res = 0;
    printf("i=%d c=%c\n", i, s[i]);
    while(isdigit(s[i]))
    {
        int d = s[i] - '0';
        
        if (neg)
            d = -d;
        
        if (res > INT_MAX/10 || (res == INT_MAX/10 && d > 7))
            return INT_MAX;
        
        if (res < INT_MIN/10 || (res == INT_MIN/10 && d < -8))
            return INT_MIN;
        
        res = res*10 + d;
        
        i++;
    }
    
    return res;

}