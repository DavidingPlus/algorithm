
import java.util.*;

public class A
{
	static int f(String x)
	{
		if(x.length()<=1) return 0;
		
		if(x.charAt(0)!=x.charAt(x.length()-1)){
			int a = f(x.substring(1));
			int b = f(x.substring(0,x.length()-1));
			return Math.min(a,b) + 1;
		}
		
		return f(x.substring(1,x.length()-1));
	}
	
	public static void main(String[] args)
	{
		//System.out.println(f("ABCBA"));
		//System.out.println(f("ABECDCBABC"));
		//System.out.println(f("ABECDCBA"));
		
		Scanner scan = new Scanner(System.in);
		
		String s = scan.nextLine();
		System.out.println(f(s));
	}
}