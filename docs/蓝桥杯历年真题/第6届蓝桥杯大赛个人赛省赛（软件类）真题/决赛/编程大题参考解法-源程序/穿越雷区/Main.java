
public class Main
{	
	public static int f(char[][] data, int x, int y)
	{
		if(data[x][y]=='B') return 0;
		
		char old = data[x][y];
		data[x][y]=0;
		
		int m = Integer.MAX_VALUE;
		
		if(x>0 && data[x-1][y]!= 0 && data[x-1][y] != old) m = Math.min(m, f(data, x-1, y));
		if(x<data.length-1 && data[x+1][y] != 0 && data[x+1][y] != old) m = Math.min(m, f(data, x+1, y));
		if(y<data.length-1 && data[x][y+1] != 0 && data[x][y+1] != old) m = Math.min(m, f(data, x, y+1));
		if(y>0 && data[x][y-1] != 0 && data[x][y-1] != old) m = Math.min(m, f(data, x, y-1));
		
		
		data[x][y] = old;
		
		if(m==Integer.MAX_VALUE) 
			return m;
		else
			return m+1;
	}
	
	public static int so(char[][] data, int x, int y){
		return f(data, x, y);
	}
	
	public static void main(String[] args)
	{
		java.util.Scanner scan = new java.util.Scanner(System.in);
		
		int n = Integer.parseInt(scan.nextLine());
		char[][] data = new char[n][n];
		
		int x=-1;
		int y=-1;
		
		for(int i=0; i<n; i++){
			String[] ss = scan.nextLine().split(" ");
			for(int j=0; j<n; j++){ 
				data[i][j] = ss[j].charAt(0);
				if(data[i][j]=='A'){ 
					x=i; y=j;
				}
			}
		}
				
		int r = so(data, x, y);
		System.out.println(r);
	}
}

