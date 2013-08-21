/**=====================================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @source      : uva-10254 The Priest Mathematician
 *   @description : dp | 汉诺塔 | 找规律 | 大数
 *   @author      : shuangde
 *   @blog        : blog.csdn.net/shuangde800
 *   @email       : zengshuangde@gmail.com
 *   Copyright (C) 2013/08/21 12:34 All rights reserved. 
 *======================================================*/

/*
题意：
   汉诺塔游戏请看 百度百科
   正常的汉诺塔游戏是只有3个柱子，并且如果有n个圆盘，至少需要2^n-1步才能达到目标。
   但是在这题中，有4根柱子，并且按照下面规则来玩：
   1. 先把圆盘顶部前k个盘子全部搬到第四根柱子上，
   2. 然后把剩下的n-k个盘子在前3根柱子中按照经典的规则搬到某个柱子上（假设是a柱），
   3. 最后再把那k个盘子搬到目标a柱上。
   问按照这样的规则，最少需要几步？

思路：
   我们先设g[n]表示按照经典的游戏规则（3根柱子），n个盘子最少需要g[n]步，可以知道g[n] = 2^n-1
   然后我们再设f[n]表示按照4根柱子的规则来，n个盘子最少需要f[n]步。
   那么按照上面步骤可以推出：
   1. 把圆盘顶部前k个盘子全部搬到第四根柱子 上 ==》 需要f[k]步
   2. 把剩下的n-k个盘子在前3根柱子中按照经典的规则搬到某个柱子上 （假设是a柱） ==》需要g[n-k]步
   3. 最后再把那k个盘子搬到目标a柱上 ==》需要f[k]步
   所以，f[n] = f[k]*2+g[n-k]
   因为f[n]要最小，且k不确定，所以枚举一下k，取最小值即可：
   f[n]  =  min{ f[k]*2+g[n-k] , 1<=k<=n }

   由于n过大，所以要用到大数。

   由于本题的n为10000，上面的算法复杂度为O(n^2)，所以不能用上面方法。

   那么就打表找规律一下，并不难找

 */

import java.math.*;
import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        
        BigInteger f[] = new BigInteger[10010];
        f[0] = BigInteger.valueOf(0);
        f[1] = BigInteger.valueOf(1);
        int i = 2;
        int k=1;
        while(i <= 10000){
            BigInteger add = BigInteger.valueOf(1).shiftLeft(k);
            for(int j=0; j<k+1 && i<=10000; ++j){
                f[i] = f[i-1].add(add);
                ++i;
            }
            ++k;
        }  
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext()){
            int n = cin.nextInt();
            System.out.println(f[n]);       
        }
    }
}

