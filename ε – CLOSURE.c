#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char state[5][10],closure[10][10][10];
int n;
void print_closure(char c_state[5]){
for(int i=0;i<n;i++){
if(strcmp(c_state,state[i])==0){
print("%s ",closure[i][0]);
print_closure(closure[i][0]);
}
}
}
void main(){
FILE *fp=fopen("transi ons.txt","r");
char trans[5][3], epsilon[5][20]; int i=0,j;
prin ("Enter the number of states: "); scanf("%d",&n);
prin ("Enter the states:\n"); for(i=0;i<n;i++){
scanf("%s",state[i]);
}
for(i=0;i<n;i++){
j=0;
while(fscanf(fp,"%s%s%s",trans[0],trans[1],trans[2])!=EOF){
if(strcmp(trans[1],"e")==0 && strcmp(trans[0],state[i])==0){
strcpy(closure[i][j],trans[2]); j++;
}
}
rewind(fp);
}
for(i=0;i<n;i++){
print("\n%s={%",state[i],state[i]);
print_closure(state[i]); print ("}");
}
print ("\n");
}
TRANSITIONS.TXT
q0 0 q0 q0
1 q1 q0 e
q1 q1 e q2
