#include"iostream"
#include"cstring"

using namespace std;

int main(){
	
	bool *m = new bool[1000000];
	
	int inputA,inputB,i;
	
	while(cin>>inputA>>inputB){
		
		memset(m,0,sizeof(bool) * 1000000);
		
		m[inputA] = true;
		m[inputB] = true;
		
		for(i = 0;i < 1000000;i++)
			
			if(m[i])
			
				m[i+inputA] = m[i+inputB] = 1;
				
		for(i = 1000000;i >= 1;i--)
		
			if(!m[i]){
			
				cout<<i<<endl;
				
				break;
				
			}
		
	}
	
	return 0;
	
}
