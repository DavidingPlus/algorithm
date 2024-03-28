/*
描述
走进世博园某信息通信馆，参观者将获得前所未有的尖端互动体验，一场充满创想和喜悦的信息通信互动体验秀将以全新形式呈现，从观众踏入展馆的第一步起，就将与手持终端密不可分，人类未来梦想的惊喜从参观者的掌上展开。

在等候区的梦想花园中，参观者便开始了他们奇妙的体验之旅，等待中的游客可利用手机等终端参与互动小游戏，与梦想剧场内的虚拟人物Kr. Kong 进行猜数比赛。当屏幕出现一个整数X时，若你能比Kr. Kong更快的发出最接近它的素数答案，你将会获得一个意想不到的礼物。

例如：当屏幕出现22时，你的回答应是23；当屏幕出现8时，你的回答应是7；若X本身是素数，则回答X;若最接近X的素数有两个时，则回答大于它的素数。

 

输入
第一行：N 要竞猜的整数个数
接下来有N行，每行有一个正整数X
1<=N<=5 1<=X<=1000
输出
输出有N行，每行是对应X的最接近它的素数
样例输入
4
22
5
18
8
样例输出
23
5
19
7
*/
#include <stdio.h>

int is_permit(int num)
{
	int i;
	if(num<=1)
	return 0;
	for(i=2;i*i<num+1;i++)
	{
		if(num%i==0)
		return 0;
	}
	return 1;
}

main()
{
	int N;
	
	scanf("%d",&N);
	while(N--)
	{
		int X;
		int i;
		
		scanf("%d",&X);
		for(i=0;;i++)
		{
			if(is_permit(X+i))
			{
				printf("%d\n",X+i);
				break;
			}
			if(is_permit(X-i))
			{
				printf("%d\n",X-i);
				break;
			}
		}
	}
	return 0;
}
