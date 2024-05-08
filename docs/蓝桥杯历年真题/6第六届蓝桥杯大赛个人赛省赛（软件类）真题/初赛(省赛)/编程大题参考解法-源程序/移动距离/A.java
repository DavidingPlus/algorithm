
public class A
{
	public static int row(int w, int k)
	{
		return (k-1)/w;
	}
	
	public static int col(int w, int k)
	{
		int r = row(w,k);
		if(r%2==0)
			return (k-1)%w;
		else
			return (w-1)-(k-1)%w; 
	}
	
	public static void main(String[] args)
	{
		String[] ss = new java.util.Scanner(System.in).nextLine().trim().split(" ");
		int w = Integer.parseInt(ss[0]);
		int m = Integer.parseInt(ss[1]);
		int n = Integer.parseInt(ss[2]);
		
		System.out.println(Math.abs(row(w,m)-row(w,n)) + Math.abs(col(w,m)-col(w,n)));
	}
}