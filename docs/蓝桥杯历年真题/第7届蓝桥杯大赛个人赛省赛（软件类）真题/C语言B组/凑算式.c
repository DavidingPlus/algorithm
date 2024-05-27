#include "stdio.h"
int main(void)
{
	int q,w,e,r,t,y,u,i,o;
	int A,B,C,D,E,F,G,H,I,P,Q,count = 0;
	for(q = 1;q <=9;q++){
		A = q;
		{
			for(w = 1;w<=9;w++){
				if(w != A){
					B = w;
					{
						for(e = 1;e <= 9;e++){
							if(e != A && e!=B){
								C = e;
								{
									for(r = 1;r<=9;r++){
										if(r !=A && r!=B && r!=C){
											D = r;
											{
												for(t = 1;t <=9;t++){
													if(t != A && t != B &&t!=C &&t !=D){
														E = t;
														for(y = 1;y <=9;y++){
															if(y!=A && y!=B && y!=C &&y!=D && y!=E){
																F = y;
																for(u = 1;u <= 9;u++){
																	if(u!=A && u!=B && u!=C &&u!=D && u!=E && u!=F){
																		G = u;
																		for(i = 1;i <= 9;i++){
																			if(i!=A && i!=B && i!=C &&i!=D && i!=E && i!=F && i!= G){
																				H = i;
																				for(o = 1;o <=9;o++){
																					if(o!=A && o!=B && o!=C &&o!=D && o!=E && o!=F && o!= G && o!=H){
																						I = o;
																						P = D*100+E*10+F;
																						Q = G*100+H*10+I;
																						if(A*C*Q+B*Q+C*P == 10*C*Q){
																							printf("%d %d %d %d %d\n",A,B,C,P,Q);
																							count += 1;
																						}
																					}
																				}
																			}
																		}
																	}
																}
													
															}
														}
													}
												}
											}
										}
									}	
								}
							}
						}	
					}
			}	}
		}
	}
	printf("%d",count);
	return 0;
}
