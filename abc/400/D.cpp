#include <bits/stdc++.h>
using namespace std;

int main() {
	int h,w;
	int a,b,c,d;
	int x,y,z,nx,ny;
	bool wall;
	deque<int>dq;

	const int dx[4]={-1,1,0,0};
	const int dy[4]={0,0,-1,1};

	cin>>h>>w;
	vector<string>s(h);
	vector<vector<int> >ans(h,vector<int>(w,h*w)); 

	for(int i=0;i<h;i++)cin>>s[i];
	cin>>a>>b>>c>>d;
	a--,b--,c--,d--;
	
	ans[a][b]=0;
	dq.push_front(a*w+b);
	while(!dq.empty()){
		z=dq.front();
		dq.pop_front();
		if(z==(c*w+d)){
			cout<<ans[c][d]<<endl;
			return 0;
		}
		x=z/w,y=z%w;
		for(int i=0;i<4;i++){
			wall=false;
			for(int j=1;j<=2;j++){
				nx=x+dx[i]*j;
				ny=y+dy[i]*j;
				if((nx<0)||(nx>=h)||(ny<0)||(ny>=w))break;
				if(s[nx][ny]=='#')wall=true;
				if(!wall){
					if(j==1){
						if(ans[nx][ny]>ans[x][y]){
							ans[nx][ny]=ans[x][y];
							dq.push_front(nx*w+ny);
						}
					}
				}
				else{
					if(ans[nx][ny]>ans[x][y]+1){
						ans[nx][ny]=ans[x][y]+1;
						dq.push_back(nx*w+ny);
					}
				}

			}
		}
	}

	return 0;
}
