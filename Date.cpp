#include <cstdio>
#include <string.h>

int month[13][2] ={{0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}};
char week1[][15]={"Wednesday","Thursday","Friday","Saturday","Sunday","Monday","Tuesday"};	//大于基点日期 
char week2[][15]={"Wednesday","Tuesday","Monday","Sunday","Saturday","Friday","Thursday"};
char mon[][13] = {"0","January","February","March","April","May","June","July","August","septemper","October","November","December"};
bool isleap(int year){
	return (year%4==0&&year%100!=0) || (year%400==0);
}

int main(){
	int time1,y1,m1,d1;
	int y2,m2,d2;
	char m[15];
	int time2=20190522;
	while(scanf("%d%s%d",&d1,m,&y1)!=EOF){
		int p=0;
		for(int i=1;i<13;i++){
			if(strcmp(m,mon[i])==0) m1=i;
		}
		time1=y1*10000+m1*100+d1;
		if(time1>time2){
			p=1;
			int temp=time1;
			time1=time2;
			time2=temp;
		}
		y1=time1/10000, m1=time1%10000/100, d1=time1%100;
		y2=time2/10000, m2=time2%10000/100, d2=time2%100;
		int ans=1;
		while(y1<y2 || m1<m2 || d1<d2){
			d1++;
			if(d1==month[m1][isleap(y1)]+1){
				m1++;
				d1=1;
			}
			if(m1==13){
				y1++;
				m1=1;
			}
			ans++;
		}
		int x=(ans-1)%7;
		if(p==0) printf("%s",week2[x]); 
		if(p==1) printf("%s",week1[x]);
		
	}
	return 0;
}
