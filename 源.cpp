#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void test1(int arr[])
{//			传过来首元素的地址，实际上计算指针的大小 - 8
	printf("%d\n", sizeof(arr));
}

void test2(char ch[])
{//			传过来首元素的地址，实际上计算指针的大小 - 8
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
	int c = a && b;//  逻辑与 ： 两个都为真（非0），则输出1
	int d = a & b; //  按位与
	int e = a || b;//  逻辑或 ： 两个都为假（0），则输出0；
	int f = a | b;//   按位或
	printf("%d\n", c);
	printf("%d\n", d);
	printf("%d\n", e);
	printf("%d\n", f);
	return 0;
}

int main()
{
	int i = 0, j = 0, a = 1, b = 2, c = 3, d = 4;
 i = a++ && ++b && d++;//1 2 3 4 0 ,&&左边a为0使用后为假，右边不执行，但a仍需要++一次
    j = a++ || ++b || d++;//1 3 3 4 0,同理:||坐标a为1使用后为真，右边不执行
	printf(" a=%d\n b=%d\n c=%d\n d=%d\n i=%d\n j=%d\n", a, b, c, d, i, j);

	return 0;
}

			三 目 操 作 符
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

				 逗 号 表 达 式
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


			结 构 体 类 型
struct Stu
{
	  成员变量
	char name[20];
	int age;
	char id[20];
};
int main()
{
		int		a = 5;
	  使用 struct stu这个类型创建一个学生对象S1，并初始化 
	struct Stu S1 = { "陈鸿标",21,"3205302051" };
	 1.
	/*printf("%s\n", S1.name);
	printf("%s\n", S1.id);
	printf("%d\n", S1.age);*/
		   结构体变量.成员名 - S1.id

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
	     结构体指针->成员名
	return 0;
}

int main()
{			// 整型提升 ： 有符号位，前面补符号位到32bits，无符号位，直接补0
	char a = 3;
	 char 类型只有1个字节  8比特位，需要32bits截断为8bits，所以 a = 000000011
	 整型提升 ：		   00000000000000000000 00000011

	char b = 127;
	 依然 8 比特位， b = 00000000000000000000 01111111

	char c = a + b;
	 a + b :		   c = 00000000000000000000 10000010
	 继续截断，并存储到 char c 里，，char c = 10000010
	printf("%d\n", c);
  打印出 %d ,整型提升，  1111111111111111111110000010 - 补码
						   1111111111111111111110000001 - 反码 = 补码 - 1
						   1000000000000000000001111110 - 原码 = - 126

	return 0;
}

int main()
{
	char a = 0xb6; 
	short b = 0xb600;
	int c = 0xb6000000;
	if (a == 0xb6) // 因为有运算（比较），所以a整型提升，完了后不等于原来的0xb6，b同理
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
	printf("%u\n", sizeof(+c));// 进行运算，整型提升为int - 4
	printf("%u\n", !c);
	printf("%u\n", sizeof(!b));
	printf("%d\n", sizeof(!c));// 1
	return 0;
}

			操 作 符 的 属 性
  1.操作符的优先级
  2.操作符的结合性
  3.是否控制求值顺序 : && 左边为假（0），则右边不再进行。
int main()
{
	int a = 10, b = 20, c = b + a * 5;
	printf("%d\n", c);
	return 0;
}