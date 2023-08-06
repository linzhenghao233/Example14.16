/* func_ptr.c -- ʹ�ú���ָ�� */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
char* s_gets(char* st, int n);
char showmenu(void);
void eatline(void);							//��ȡ����ĩβ
void show(void(*fp)(char*), char* str);
void ToUpper(char*);					//���ַ���ת��Ϊ��д
void ToLower(char*);					//���ַ���ת��ΪСд
void Transpose(char*);					//��Сдת��
void Dummy(char*);						//�������ַ���

int main(void) {
	char line[LEN];
	char copy[LEN];
	char choice;
	void(*pfun)(char*);		//����һ������ָ�룬��ָ��ĺ�������char*���͵Ĳ������޷���ֵ

	puts("Enter a string (empty line to quit):");
	while (s_gets(line, LEN) != NULL && line[0] != '\0') {
		while ((choice = showmenu()) != 'n') {
			switch (choice) {		//switch�������ָ��
			case	'u'	:pfun = ToUpper; break;
			case	'l':pfun = ToLower; break;
			case 't':pfun = Transpose; break;
			case 'o':pfun = Dummy; break;
			}
			strcpy(copy, line);		//Ϊshow()��������һ��
			show(pfun, copy);		//�����û���ѡ��ʹ��ѡ���ĺ���
		}
		puts("Enter a string (empty line to quit):");
	}
	puts("Bye!");

	return 0;
}