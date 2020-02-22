//
//  unix_3.c
//  chapter 3:数据结构决定程序结构
//
//  Created by Administrator on 2020/2/1.
//

#include <stdio.h>
#include <string.h>

/*problem1:美国纳税问题*/
double calculateTaxOld(double income,double *taxArr,double *taxIncome);
/*problem2:K阶常系数线性递归定义的级数 K= 15*/
/*m>k,k>=1 a[0] = 0,c[0] = 0*/
void calculateK(double *a,double *c,int m,int k);
/*problem3:信函式编程*/
void printInputChar(char c);
/*problem4:计算给定两个日期，返回日期之间的天数+给定日期返回周几+给定年月，字符数组生成该月的日历*/
int calculateDays(int yyyy1,int mm1,int dd1,int yyyy2,int mm2,int dd2);
char isLeapYear(int yyyy);

int calculateWeekDay(int year,int month,int day);
void presentCalender(int year,int month);
/*problem5:连字符问题*/

/*problem8:16位整数图形化显示*/
void presentDigit16(uint16_t digit);
void printDigit(char **digitArr,int n);

//int main()
//{
//    /*problem1*/
////    double taxArr[29] = {0.14,0.15,0.16,0.17,0.18,0.19,0.20,0.21,0.22,0.23,0.24,0.25,0.26,0.27,0.28,0.27,0.28,0.29,0.30,0.31,0.32,0.33,0.34,0.35,0.36,0.37,0.38,0.39,0.40};
////
////    double taxIncome[29] = {2200,2700,3200,3700,4200,4700,5200,5700,6200,6700,7200,7700,8200,8700,9200,9700,10200,10700,11200,11700,12200,12700,13200,13700,14200,14700,15200,15700,16200};
////
////    double income;
////
////    scanf("%lf",&income);
////
////    double tax = calculateTaxOld(income,taxArr,taxIncome);
////
////    printf("income :%.2lf,tax:%.2lf\n",income,tax);
//
//}

double calculateTaxOld(double income,double *taxArr,double *taxIncome)
{
    if(income <= taxIncome[0])
    {
        return 0.00;
    }
    int i = 1;
    double tax[29];
    tax[0] = 0.00;
    while(i<30)
    {
        if(income <= taxIncome[i])
        {
            break;
        }
        else
        {
            tax[i] = taxArr[i-1] * (taxIncome[i]-taxIncome[i-1]) +tax[i-1];
            i++;
        }
    }
    
    return tax[i-1]+(income - taxIncome[i-1])*taxArr[i-1];
}

/*O(n2)*/
void calculateK(double *a,double *c,int m,int k)
{
    for(int i = k+1;i <= m;++i)
    {
        int j = k;
        a[i]+=c[k+1];
        while(j>=1)
        {
            a[i]+=c[j]*a[i-j];
            k--;
        }
    }
}

void printInputChar(char c)
{
    /*表示方法：5*9的字符(*)矩阵，像素矩阵*/
    
    /*A:*/
    /*
         *
        * *
       *****
      *     *
     *       *
     
     */
    
    /*B:*/
    /*
     ********
     *       *
     *********
     *       *
     ********
     
     */
    
    /*
         ********
        *
        *
        *
         ********
        
    */
    /*
        *******
        *       *
        *       *
        *       *
        *******
        
    */
    /*
        *********
        *
        *********
        *
        *********
        
    */
    
    /*
        *********
        *
        *********
        *
        *
     
    */
    
}

int calculateDays(int yyyy1,int mm1,int dd1,int yyyy2,int mm2,int dd2)
{
    int mon_1[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int mon_2[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    /*yyyy2>=yyyy1,if yyyy1==yyyy2,mm2>mm1*/
    int sumDays = 0;
    if(yyyy1 == yyyy2)
    {
        for(int i =mm1;i<=mm2;++i)
        {
            if(isLeapYear(yyyy1) == '1')
            {
                sumDays += mon_2[i];
            }
            else
            {
                sumDays += mon_1[i];
            }
        }
        sumDays -= dd1;
        sumDays += dd2;
    }
    else
    {
        for(int i = yyyy1;i<=yyyy2;++i)
        {
            if(isLeapYear(i) == '1')
            {
                sumDays +=mon_2[mm1] - dd1;
                int j =mm1;
                while(++j<=13)
                {
                    sumDays +=mon_2[j];
                }
                ++i;
                if(i>yyyy2)
                {
                    sumDays +=366;
                }
            }
            else
            {
                sumDays +=mon_1[mm1] - dd1;
                int j =mm1;
                while(++j<=13)
                {
                    sumDays +=mon_1[j];
                }
                ++i;
                if(i>yyyy2)
                {
                    sumDays +=365;
                }
            }
        }
    }
    return sumDays;
}

char isLeapYear(int year)
{
    if(year%4 == 0 && year%100 != 0)
    {
        return '1';
    }
    else if(year % 400 ==0)
    {
        return '1';
    }
    else
    {
        return '0';
    }
}

int calculateWeekDay(int year,int month,int day)
{
    /*基姆拉尔森计算公式
    W= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) mod 7*/
    if(month == 1 || month == 2)
    {
        month +=12;
        year--;
    }
    return (day+2*month+3*(month+1)/5+year+year/4-year/100+year/400) % 7;
    
}

void presentCalender(int year,int month)
{
    
}

void presentDigit16(uint16_t digit)
{
    /*
      __
     |  |
      __
     |  |
      --
     1111111--8
     
     第一位：最下面
     第二位：中间
     第三位：最上面
     第四位：左上
     第五位：右上
     第六位：左下
     第七位：右下
     
     七个显示管都亮
     */
    char *p[10] ={"1011111","0000101","1110110",\
        "1110101","0101101","1111001","1111011","0010101",\
        "111111","0111101"
    };
    
    char *digitArr[5]={};
    
    int i = 4;
    uint16_t temp = digit;
    while(temp!=0 && i>0)
    {
        int mod = temp %10;
        digitArr[i] = p[mod];
        temp /=10;
        i--;
    }
    printDigit(digitArr,5);
}


void printDigit(char **digitArr,int n)
{
    for(int i = 0;i<5;++i)
    {
        for(int j =0;j<n;++j)
        {
            
        }
    }
}
