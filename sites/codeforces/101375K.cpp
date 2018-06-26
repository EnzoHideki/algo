#include <bits/stdc++.h>
using namespace std;

char st[212];

int main(){
	scanf(" %[^\n]", st);
	int sz = strlen(st);

	if (st[sz-1] == '?') {
		printf("7\n");
		return 0;
	}

	for (int i=0; i+5<sz; i++) {
		if (i == 0) {
			if (st[i] == 'S' && st[i+1] == 'u' && st[i+2] == 's' && st[i+3] == 's' && st[i+4] == 'u' 
				&& (st[i+5] == '.' || st[i+5] == '!' || st[i+5] == ' ')) {
				printf("AI SUSSU!\n");
				return 0;
			}
		} else {
			if (st[i-1] == ' ' && st[i] == 'S' && st[i+1] == 'u' && st[i+2] == 's' && st[i+3] == 's' && st[i+4] == 'u' 
				&& (st[i+5] == '.' || st[i+5] == '!' || st[i+5] == ' ')) {
				printf("AI SUSSU!\n");
				return 0;
			}
		}
	}	

	printf("O cara é bom!\n");
}