#include<stdio.h>  
#include<math.h>  
int main()  
{  
    double x;//从2开始   
    for(x=2.0;x<3.0;x+=0.00000001)//8个小数位的形式递增   
    {  
        //pow 函数求x的y次方，然后减去10.0再取绝对值看之差是否在10的-6次方以内以满足精度要求   
        if(fabs(pow(x,x)-10.0)<0.000001)   
        {  
            printf("%.8lf\n",x);  
            //break; //因为要求4舍5入所以多输出几个数字来做判断   
        }   
    }  
    return 0;  
} 
