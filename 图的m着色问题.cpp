#include <stdio.h> 
int n, m;//����������ɫ��
int graph[130][130] = {0};//������ͨͼ
int color[130] = {0};
int a, b;//��������� 
int s = 0;//������
//�ж��Ƿ�����ɫ 
bool cancColoring(int x) {
	for (int i = 1; i <= n; ++i) {
		//��������������ɫ��ͬ
		if (graph[i][i] && color[i] == color[i]) {
			return false;
		}
	}
	return true;
}
//��ɫ 
void coloring(int x){
	if (x>n) {
		for (int i = 1; i <= n; i++){
			printf("%d ", color[i]);
		}
		s++;
		printf("\n");
	} 
	else {
		for (int i = 1; i <= m; ++i) {
			color[x] = i;
			if (cancColoring(x)) {
				coloring(x+1);
			}
			color[x] = 0;
		}
	}
}
int main(){
	printf("���붥��������ɫ��:\n");
	scanf("%d %d", &n, &m);
	printf("�����:\n");
	while (scanf("%d %d", &a, &b) && a != 0 && b != 0){
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	coloring(1);
	if (s==0){
		printf("NO\n");
	}
	else{
		printf("��ɫ������Ϊ%d\n", s);
	}
	return 0;
}
