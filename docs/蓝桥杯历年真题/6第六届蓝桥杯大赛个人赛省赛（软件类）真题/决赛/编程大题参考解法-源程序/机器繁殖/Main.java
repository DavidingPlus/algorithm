
import java.util.*;
import java.math.BigInteger;
public class Main
{
	static boolean test(int begin, int n, BigInteger sum0)
	{
		//System.out.println("de: " + begin + "," + n + "," + sum0);
		
		BigInteger a = BigInteger.valueOf(begin);
		BigInteger sum = a;
		
		for(int i=1; i<=n; i++){
			a = a.add(a).subtract(BigInteger.ONE);
			sum = sum.add(a);
		}		
		
		return sum.equals(sum0);
	}
	
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		
		String[] ss = scan.nextLine().split(" ");
		
		int a = Integer.parseInt(ss[0]);
		BigInteger b = new BigInteger(ss[1]);
		
		
		for(int i=1; i<100; i++) { 
			if(test(i,a,b)) {
				System.out.println(i); 
				break;
			}
		}
	}
}