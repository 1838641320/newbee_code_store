#include<stdio.h>
#include<string.h>
typedef struct {
	char j[660];
}ok;
ok change(ok niubi){
	int k=strlen(niubi.j);
	for(int i=0;i<k;i++) niubi.j[i]++;
	return niubi;
}
void change2(ok *niubi){
	int k=strlen(niubi->j);
	for(int i=0;i<k;i++) niubi->j[i]++;
}
int main(){
	ok niubi;
	scanf("%s",niubi.j);
//	niubi=change(niubi);
	change2(&niubi);
	printf("%s",niubi.j);
}
