#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void test1(int arr[])
{//			��������Ԫ�صĵ�ַ��ʵ���ϼ���ָ��Ĵ�С - 8
	printf("%d\n", sizeof(arr));
}

void test2(char ch[])
{//			��������Ԫ�صĵ�ַ��ʵ���ϼ���ָ��Ĵ�С - 8
	printf("%d\n", sizeof(ch));
}

int main()
{
	int arr[10] = { 0 };
	char ch[10] = { 0 };
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(ch));
	test1(arr);
	test2(ch);
	return 0;
}

int main()
{
	int a = 3;
	int b = 5;
	int c = a && b;//  �߼��� �� ������Ϊ�棨��0���������1
	int d = a & b; //  ��λ��
	int e = a || b;//  �߼��� �� ������Ϊ�٣�0���������0��
	int f = a | b;//   ��λ��
	printf("%d\n", c);
	printf("%d\n", d);
	printf("%d\n", e);
	printf("%d\n", f);
	return 0;
}

int main()
{
	int i = 0, j = 0, a = 1, b = 2, c = 3, d = 4;
 i = a++ && ++b && d++;//1 2 3 4 0 ,&&���aΪ0ʹ�ú�Ϊ�٣��ұ߲�ִ�У���a����Ҫ++һ��
    j = a++ || ++b || d++;//1 3 3 4 0,ͬ��:||����aΪ1ʹ�ú�Ϊ�棬�ұ߲�ִ��
	printf(" a=%d\n b=%d\n c=%d\n d=%d\n i=%d\n j=%d\n", a, b, c, d, i, j);

	return 0;
}

			�� Ŀ �� �� ��
int main()
{
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	if (a > b)
		printf("%d\n",a);
	else
		printf("%d\n",b);
	int c = (a > b ? a : b);
	printf("%d\n", c);

	return 0;
}

				 �� �� �� �� ʽ
int main()
{
	/*int a = 1;
	int b = 2;
	int c = (a > b, a = b + 10, a, b = a + 1);
	printf("%d\n", c);*/
	int a = 0, b = 1, c = 0, d = 1;
	if (a = b + 1, c = a / 2, d > 0)
		printf("%d\n",a);
		printf("%d\n", b);
		printf("%d\n", c);
	return 0;
}


			�� �� �� �� ��
struct Stu
{
	  ��Ա����
	char name[20];
	int age;
	char id[20];
};
int main()
{
		int		a = 5;
	  ʹ�� struct stu������ʹ���һ��ѧ������S1������ʼ�� 
	struct Stu S1 = { "�º��",21,"3205302051" };
	 1.
	/*printf("%s\n", S1.name);
	printf("%s\n", S1.id);
	printf("%d\n", S1.age);*/
		   �ṹ�����.��Ա�� - S1.id

	 2.
	struct Stu* P1 = &S1;
	printf("%s\n", (*P1).name);
	printf("%s\n", (*P1).id);
	printf("%d\n", (*P1).age);

	 3.
	struct Stu* P1 = &S1;
	printf("%s\n", P1->name);
	printf("%s\n", P1->id);
	printf("%d\n", P1->age);
	     �ṹ��ָ��->��Ա��
	return 0;
}

int main()
{			// �������� �� �з���λ��ǰ�油����λ��32bits���޷���λ��ֱ�Ӳ�0
	char a = 3;
	 char ����ֻ��1���ֽ�  8����λ����Ҫ32bits�ض�Ϊ8bits������ a = 000000011
	 �������� ��		   00000000000000000000 00000011

	char b = 127;
	 ��Ȼ 8 ����λ�� b = 00000000000000000000 01111111

	char c = a + b;
	 a + b :		   c = 00000000000000000000 10000010
	 �����ضϣ����洢�� char c ���char c = 10000010
	printf("%d\n", c);
  ��ӡ�� %d ,����������  1111111111111111111110000010 - ����
						   1111111111111111111110000001 - ���� = ���� - 1
						   1000000000000000000001111110 - ԭ�� = - 126

	return 0;
}

int main()
{
	char a = 0xb6; 
	short b = 0xb600;
	int c = 0xb6000000;
	if (a == 0xb6) // ��Ϊ�����㣨�Ƚϣ�������a�������������˺󲻵���ԭ����0xb6��bͬ��
		printf("a");
	if (b == 0xb600)
		printf("b");
	if (c == 0xb6000000)
		printf("c");
	return 0;
}
int main()
{
	char c = 1;
	int b = 0;
	printf("%u\n", sizeof(c)); // 1
	printf("%u\n", sizeof(+c));// �������㣬��������Ϊint - 4
	printf("%u\n", !c);
	printf("%u\n", sizeof(!b));
	printf("%d\n", sizeof(!c));// 1
	return 0;
}

			�� �� �� �� �� ��
  1.�����������ȼ�
  2.�������Ľ����
  3.�Ƿ������ֵ˳�� : && ���Ϊ�٣�0�������ұ߲��ٽ��С�
int main()
{
	int a = 10, b = 20, c = b + a * 5;
	printf("%d\n", c);
	return 0;
}