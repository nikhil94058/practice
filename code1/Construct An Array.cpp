#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int N=2010,M=1e9+7;
int cn[N], a[N], b[N];

int main() {
	int t; scanf("%d",&t);
	while(t--){
	    
	    for(int i =0; i <N; ++i) cn[i]=0;
        
	    int n,m; scanf("%d %d",&n, &m);
	    for(int i =0; i <n; ++i){
	        scanf("%d",&a[i]);
	    }
	    
	    for(int i =0,c=0; i <n; ++i){
	        if(cn[a[i]]==c){
	            b[i]=a[i]; ++cn[a[i]];
	        }
	        else {
				int f = 0;
            	for(int j =1; j <=m; ++j){
            	    if(cn[j]==c){
            	        b[i]=j; ++cn[j]; f=1;break;
            	    }
                }
				if(!f){
					b[i]=a[i];++cn[a[i]];++c;
	            }
	        }
	    }

	    for(int i =0; i <n; ++i) printf("%d ", b[i]);
	    printf("\n");
	}
	return 0;
}