////
////  unix_1.c
////
////
////  Created by Administrator on 2020/1/31.
////
//
//#include <stdio.h>
//
////types and constants used in the functions below
//
//typedef unsigned __int64 uint64;  //assume this gives 64-bits
//
//const uint64 m1 = 0x5555555555555555; //binary: 0101...
//const uint64 m2 = 0x3333333333333333; //binary: 00110011..
//const uint64 m4 = 0x0f0f0f0f0f0f0f0f; //binary:  4 zeros,  4 ones ...
//const uint64 m8 = 0x00ff00ff00ff00ff; //binary:  8 zeros,  8 ones ...
//const uint64 m16 = 0x0000ffff0000ffff; //binary: 16 zeros, 16 ones ...
//const uint64 m32 = 0x00000000ffffffff; //binary: 32 zeros, 32 ones ...
//const uint64 hff = 0xffffffffffffffff; //binary: all ones
//const uint64 h01 = 0x0101010101010101; //the sum of 256 to the power of 0,1,2,3...
//
////This is better if most bits in x are 0.
////It uses 2 arithmetic operations and one comparison/branch  per "1" bit in x.
////It is the same as the previous function, but with the loop unrolled.
//#define f(y) if ((x &= x-1) == 0) return y;
////Use this instead if most bits in x are 1 instead of 0
//#define f(y) if ((x |= x+1) == hff) return 64-y;
//
//int32_t swar(int32_t i);
//int popcount_1(uint64 x);
//
//void main()
//{
//
//}
//
//// 计算32位二进制的汉明重量
//int32_t swar(int32_t i)
//{
//    i = (i & 0x55555555) + ((i >> 1) & 0x55555555);
//    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
//    i = (i & 0x0F0F0F0F) + ((i >> 4) & 0x0F0F0F0F);
//    i = (i * (0x01010101) >> 24);
//    return i
//}
//
////This is a naive implementation, shown for comparison,
////and to help in understanding the better functions.
////It uses 24 arithmetic operations (shift, add, and).
//int popcount_1(uint64 x)
//{
//    x = (x & m1 ) + ((x >>  1) & m1 ); //put count of each  2 bits into those  2 bits
//    x = (x & m2 ) + ((x >>  2) & m2 ); //put count of each  4 bits into those  4 bits
//    x = (x & m4 ) + ((x >>  4) & m4 ); //put count of each  8 bits into those  8 bits
//    x = (x & m8 ) + ((x >>  8) & m8 ); //put count of each 16 bits into those 16 bits
//    x = (x & m16) + ((x >> 16) & m16); //put count of each 32 bits into those 32 bits
//    x = (x & m32) + ((x >> 32) & m32); //put count of each 64 bits into those 64 bits
//    return x;
//}
//
////This uses fewer arithmetic operations than any other known
////implementation on machines with slow multiplication.
////It uses 17 arithmetic operations.
//int popcount_2(uint64 x)
//{
//    x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
//    x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits
//    x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits
//    x += x >>  8;  //put count of each 16 bits into their lowest 8 bits
//    x += x >> 16;  //put count of each 32 bits into their lowest 8 bits
//    x += x >> 32;  //put count of each 64 bits into their lowest 8 bits
//    return x &0xff;
//}
//
////This uses fewer arithmetic operations than any other known
////implementation on machines with fast multiplication.
////It uses 12 arithmetic operations, one of which is a multiply.
//int popcount_3(uint64 x)
//{
//    x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
//    x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits
//    x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits
//    return (x * h01)>>56;  //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ...
//}
//
////This is better when most bits in x are 0
////It uses 3 arithmetic operations and one comparison/branch per "1" bit in x.
//int popcount_4(uint64 x)
//{
//    uint64 count;
//    for (count=0; x; count++)
//        x &= x-1;
//    return count;
//}
//
//int popcount_5(uint64 x)
//{
//    if (x == 0) return 0;
//    f( 1) f( 2) f( 3) f( 4) f( 5) f( 6) f( 7) f( 8)
//    f( 9) f(10) f(11) f(12) f(13) f(14) f(15) f(16)
//    f(17) f(18) f(19) f(20) f(21) f(22) f(23) f(24)
//    f(25) f(26) f(27) f(28) f(29) f(30) f(31) f(32)
//    f(33) f(34) f(35) f(36) f(37) f(38) f(39) f(40)
//    f(41) f(42) f(43) f(44) f(45) f(46) f(47) f(48)
//    f(49) f(50) f(51) f(52) f(53) f(54) f(55) f(56)
//    f(57) f(58) f(59) f(60) f(61) f(62) f(63)
//    return 64;
//}
//
//


//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <stdafx.h>
//
//typedef unsigned char Byte;
//
//static const Byte Sbox[16] = {
//    0x0c, 0x05, 0x06, 0x0b,
//    0x09, 0x00, 0x0a, 0x0d,
//    0x03, 0x0e, 0x0f, 0x08,
//    0x04, 0x07, 0x01, 0x02
//};
//
//static const Byte DSbox[16] = {
//    0x05,0x0e, 0x0f, 0x08,
//    0x0c,0x01, 0x02, 0x0d,
//    0x0b,0x04, 0x06, 0x03,
//    0x00,0x07, 0x09, 0x0a
//};
//
//static  Byte Px[64]={
//    0,16,32,48,1,17,33,49,2,18,34,50,3,19,35,51,
//    4,20,36,52,5,21,37,53,6,22,38,54,7,23,39,55,
//    8,24,40,56,9,25,41,57,10,26,42,58,11,27,43,59,
//    12,28,44,60,13,29,45,61,14,30,46,62,15,31,47,63
//};
//
//static  Byte rPx[64]={
//    0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,
//    1,5,9,13,17,21,25,29,33,37,41,45,49,53,57,61,
//    2,6,10,14,18,22,26,30,34,38,42,46,50,54,58,62,
//    3,7,11,15,19,23,27,31,35,39,43,47,51,55,59,63
//};
//
//static  Byte testPx[8]={
//    7,6,5,4,3,2,1,0
//};
//
//
//
//
//
//int main(int argc, char* argv[])
//{
//    int i;
//    Byte p[8];
//    Byte c[8];
//    Byte k[10];
//    Byte e[256];
//    memset(p,0,8);
//    memset(k,0,10);
//    for( i=0;i<8;i++)
//        p[i]=0;
//    for( i=0;i<10;i++)
//        k[i]=0;
//    printf("\nº”√‹√˜Œƒ\n");
//       for( i=0;i<8;i++)
//    {
//        printf("%2x ",p[i]);
//    }
//    Key(64,k,e);
//      Encrypt(p,e,c);
//     printf("\nº”√‹√‹Œƒ\n");
//       for( i=0;i<8;i++)
//    {
//        printf("%2x ",c[i]);
//    }
//     Decrypt(c,e,p);
//    printf("\nΩ‚√‹√˜Œƒ\n");
//    
//     for( i=0;i<8;i++)
//    {
//        printf("%2x ",p[i]);
//    }
//    return 0;
//}
