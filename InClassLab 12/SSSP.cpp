#include<iostream>
#include<stdio.h>
using namespace std;
#define INFINITY 9999
#define max 6
void dijkstra(int G[max][max],int n,int startnode);
int main() {
    int G[max][max]={{0,10,0,0,15,5},{10,0,10,30,0,0},{0,10,0,12,5,0},{0,30,12,0,0,20},{15,0,5,0,0,0},{5,0,0,20,0,0}};
    int n=6;
    int u=5;
    dijkstra(G,n,u);
    return 0;
}
void dijkstra(int G[max][max],int n,int startnode) {
    int cost[max][max],distance[max],pred[max];
    int visited[max],count,mindistance,nextnode,i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];
    for(i=0;i<n;i++) {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1) {
        mindistance=INFINITY;
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i]) {
                mindistance=distance[i];
                nextnode=i;
            }
        visited[nextnode]=1;
        for(i=0;i<n;i++)
            if(!visited[i])
                if(mindistance+cost[nextnode][i]<distance[i]) {
                    distance[i]=mindistance+cost[nextnode][i];
                    pred[i]=nextnode;
                }
        count++;
    }
    cout<<"\nWhen the source city is 5:";

    double sum=0.0;
    for(i=0;i<n;i++)
        if(i!=startnode) {
            cout<<"\nTime duration of node city "<<i<<" = "<<distance[i];
            sum+=distance[i];
            /*cout<<"\nPath="<<i;
            j=i;
            do {
                j=pred[j];
                cout<<"<-"<<j;
            }while(j!=startnode);*/
        }
    cout<<"\nThe total time : "<<sum<<endl;
    double avg= sum/5;
    cout<<"The average time: "<<avg<<endl;
}