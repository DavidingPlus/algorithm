#include "stdio.h"
#include "math.h" 
int main(void)
{
	int q,w,e,r,t,y,u,i,o,p;
	int A,B,C,D,E,F,G,H,I,L; 
	int count = 0;
	for(q = 1;q <=10;q++){
		A = q;
			for(w = 1;w<=10;w++){
				if(w == A) continue;{
					B = w;
						for(e = 1;e <= 10;e++){
							if(e == A || e==B) continue;{
								C = e;
									for(r = 1;r<=10;r++){
										if(r ==A || r==B || r==C) continue;{
											D = r;
												for(t =1;t <=10;t++){
													if(t == A || t == B || t ==C || t ==D) continue;{
														E = t;
														for(y = 1;y <=10;y++){
															if(y==A || y==B || y==C || y==D || y==E) continue;{
																F = y;
																for(u = 1;u <= 10;u++){
																	if(u==A || u==B || u==C || u==D || u==E || u==F) continue;{
																		G = u;
																		for(i = 1;i <= 10;i++){
																			if(i==A || i==B || i==C || i==D || i==E || i==F || i== G) continue;{
																				H = i;
																				for(o = 1;o <=10;o++){
																					if(o==A || o==B || o==C || o==D || o==E || o==F || o==G || o==H) continue;{
																						I = o;
																						for(p = 1;p <= 10;p++){
																							if(p==A || p==B || p==C || p==D || p==E || p==F || p==G || p==H || p==I) continue;{
																								L = p;
																								if(abs(A-D)==1 || abs(A-E)==1 || abs(A-F)==1 || abs(A-B)==1 || abs(B-E)==1 || abs(B-F)==1 || abs(B-C)==1 || abs(B-G)==1 || abs(C-F)==1 || abs(C-G)==1 || abs(D-H)==1 || abs(D-I)==1 || abs(D-E)==1 || abs(E-H)==1 || abs(E-I)==1 || abs(E-L)==1 || abs(E-F)==1 || abs(F-I)==1 || abs(F-L)==1 || abs(F-G)==1 || abs(G-L)==1 || abs(H-I)==1 || abs(I-L)==1) continue;
																									count++;
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
	}	
	printf("%d",count);
	return 0;
}
