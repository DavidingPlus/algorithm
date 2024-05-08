
import java.util.*;
public class Main
{
	static int[] prm = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107};
	static long[] kkey;
	static int N = 8;
	
	static void create_kkey(String mother){
		kkey = new long[mother.length()-N+1];
		
		kkey[0] = 1;
		for(int i=0; i<N; i++) kkey[0] *= prm[mother.charAt(i)-'a'];
		
		for(int i=1; i<kkey.length; i++){
			kkey[i]=kkey[i-1] / prm[mother.charAt(i-1)-'a'] * prm[mother.charAt(i+N-1)-'a'];
		}	
	}
	
	public static int find(String child)
	{
		long key = 1;
		for(int j=0; j<child.length(); j++) 
			key *= prm[child.charAt(j)-'a'];
		
		int n = 0;
		for(int i=0; i<kkey.length; i++) if(kkey[i]==key) n++;
		
		return n;
	}
	
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		String mother = scan.nextLine();
		
		create_kkey(mother);
		
		int n = Integer.parseInt(scan.nextLine());
			
		int sum = 0;
		for(int i=0; i<n; i++){
			sum += find(scan.nextLine());
		}
		
		System.out.println(sum);				
	}
}