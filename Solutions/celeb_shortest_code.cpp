// AUTHOR: Rodchananat Khunakornophat
#include<bits/stdc++.h>
#define R(i,n)for(i=0;i<n;++i)
int c[1000],n,i,j,t,q=0;main(){std::cin>>n;R(i,n)c[i]=1;R(i,n)R(j,n){std::cin>>t;i-j?c[i]&=!t,c[j]&=t:0;}R(i,n)if(c[i])q=i+1;std::cout<<q;}