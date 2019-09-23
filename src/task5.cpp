#include "task5.h"
#include <malloc.h>
#include <string.h>

using namespace std;

void split(char ***result, int *N, char *buf, char ch) {
	int len = strlen(buf);// / sizeof(buf[0]);
	*N = 1;
	for (int i = 0;i < len;i++)
		if (buf[i] == ch)(*N)++;
	int *siz = new int[*N];
	for (int i = 0;i < *N;i++)siz[i] = 0;
	*result = (char**)malloc((*N)*(sizeof(char*)));
	char *sub = (char*)malloc((len+1) * sizeof(char));
	int sublen = 0;
	int num = 0;
	for (int i = 0;i < len;i++) {
		if (buf[i] == ch) {
			char *add = (char*)malloc((sublen+1) * sizeof(char));
			for (int j = 0;j < sublen;j++)add[j] = sub[j];
			add[sublen] = 0;
			(*result)[num] = add;
			num++;
			sublen = 0;
		}
		else {
			sub[sublen] = buf[i];
			sublen++;
		}
	}
	char *add = (char*)malloc((sublen + 1) * sizeof(char));
	for (int j = 0;j < sublen;j++)add[j] = sub[j];
	add[sublen] = 0;
	(*result)[num] = add;
	free(sub);
}