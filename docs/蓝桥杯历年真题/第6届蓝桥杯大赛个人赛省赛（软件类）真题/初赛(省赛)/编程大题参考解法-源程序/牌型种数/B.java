

public class B
{
	public static long f(int[] x,int k,int num)
	{
		if(num<0) return 0;
		if(num==0) return 1;
		if(k==x.length) return 0; 
		
		long r = 0;
		
		for(int i=0; i<=x[k]; i++){
			r = r + f(x,k+1,num-i);
		}
		
		return r;
	}
	
	public static void main(String[] args)
	{
		int[] x = {4,4,4,4,4,4,4,4,4,4,4,4,4};

		
		System.out.println(f(x, 0, 13));
	}
}