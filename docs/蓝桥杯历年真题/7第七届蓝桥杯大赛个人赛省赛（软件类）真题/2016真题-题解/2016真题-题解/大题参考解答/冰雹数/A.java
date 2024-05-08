
/*
  偶数 / 2
  奇数 * 3 + 1
*/

import java.math.BigInteger;
import java.util.*;

public class A
{
	static void g(int n)
	{
		while(n>1){
			System.out.println(n);
			n = (n%2==0)? n/2 : n*3+1;
		}
	}
	
	/*
	static BigInteger f(int n)
	{
		BigInteger two = BigInteger.valueOf(2);
		BigInteger three = BigInteger.valueOf(3);
		BigInteger max = BigInteger.ONE;
		
		
		BigInteger x = BigInteger.valueOf(n);
		while(x.equals(BigInteger.ONE)==false){
			if(x.intValue() % 2 == 0)
				x = x.divide(two);
			else
				x = x.multiply(three).add(BigInteger.ONE);
			
			if(x.compareTo(max) > 0) max = x;
		}
		
		return max;
	}
	*/
	
	// n以内的冰雹数，最高升至多少？

	static BigInteger f(int n)
	{
		BigInteger[] buf = new BigInteger[n+1];
		buf[0] = BigInteger.ZERO;
		buf[1] = BigInteger.valueOf(4);
		buf[2] = BigInteger.valueOf(4);
		
		for(int i=3; i<=n; i++){				
			BigInteger max1 = buf[i-1];
			if(i%2==0){
				buf[i] = max1;
				continue;
			}
			
			BigInteger t = BigInteger.valueOf(i).multiply(BigInteger.valueOf(3)).add(BigInteger.ONE);
			BigInteger max = t;
			while(true){
				t = (t.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO))? 
					t.divide(BigInteger.valueOf(2))
					: t.multiply(BigInteger.valueOf(3)).add(BigInteger.ONE);
				if(t.compareTo(max) > 0) max = t;
				if(t.compareTo(BigInteger.valueOf(i))<=0) break;
			}
			
			buf[i] = max1.max(max);
		}
		
		return buf[n];
	}
	
	
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		
		int x = Integer.parseInt(scan.nextLine());
		
		System.out.println(f(x));		
	}
}