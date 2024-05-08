
import java.util.*;

public class A
{
	static int N = 2000;
	static Map PP = new HashMap();
	static{
		for(int i=0; i<N; i++){
			for(int j=i; j<N; j++){	
				int k = i * i + j*j;
				int v = i * N + j;
				if(PP.get(k)==null) PP.put(k,v);
			}
		}
	}
	
	 
	static void f(int x)
	{
		for(int i=0; i<N; i++){
			for(int j=i; j<N; j++){	
				int k = i * i + j * j;
				
				if(PP.get(x-k)!=null){
					System.out.print("" + i + " " + j + " ");
					int b = (Integer)PP.get(x-k);
					System.out.println("" + b/N + " " + b%N);	
					return;				
				}
			}
		}		
	}	

	
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);	
		int n = Integer.parseInt(scan.nextLine());
		f(n);
		
		/*
		int base = 3000500;
		for(int k=0; k<100; k++){
			System.out.print(k+base + ": ");
			f(k+base);
		}
		*/
	}
}