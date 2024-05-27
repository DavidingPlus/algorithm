
import java.util.*;


public class B
{
	static Map map = new HashMap();
	
	// a: 第一个串开始位置， b第二个串开始位置（逆序）
	static int lcs(char[] cc, int a, int b)
	{
		if(a==cc.length || b<0) return 0;
		
		int k = a*1000 + b;
		if(map.get(k) != null) 	return (Integer)map.get(k);
			
		
		if(cc[a]==cc[b]){ 
			int t = lcs(cc, a+1,b-1) + 1;
			map.put(k,t);
			return t;
		}
		
		int t = Math.max(lcs(cc,a+1,b),lcs(cc,a,b-1));
		map.put(k,t);
		return t;
	}
	
	static int f(String s)
	{
		char[] cc = s.toCharArray();
		return cc.length - lcs(cc,0,cc.length-1);
	}
	
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		
		String s = scan.nextLine();
		System.out.println(f(s));		
	}
}