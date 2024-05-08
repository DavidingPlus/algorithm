
public class A
{
	public static void main(String[] args)
	{
		int n = Integer.parseInt((new java.util.Scanner(System.in)).nextLine());
		
		int sum = n;
		int rem  = 0; // ÁãÍ·
		while(n>0){
			int m = (n+rem) / 3;
			rem = (n+rem) % 3;
			sum += m;
			//System.out.println("--" + m);
			n = m;
		}
		System.out.println(sum);
	}
}