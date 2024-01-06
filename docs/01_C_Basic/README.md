# README

<https://www.bilibili.com/video/BV1je4y187mp>

常量，不可以被改变的量。

```c
int a = 1;
```

字符常量，

```c
char a = 'a';
```

转义字符，

```c
'\n'

'\t'
```

字符串常量，

```c
"abc"
```

符号常量，

```c
#define PI 3.1415926
```

变量，

```c
// 整形数据
int a = 123;
// 字符型
char a = 'a';
// 单精度浮点型
float a = 1.123;
// 双精度浮点型
float a = 1.123;
// 长整型
long a = 1;
// 短整型
short a = 1;
```

数据输入和输出，

```c
// 输出
int a = 100;
printf("%d", a);

// 输入
int a = 0;
scanf("%d", &a);

// 从键盘获取一个字符
char ch = getchar();
//
putchar(ch);
```

## 运算符

逻辑运算符，

```c
// 逻辑与
&&
// 逻辑或
||
// 逻辑非
!
```

位运算符，

```c
// 左移
<<
// 右移
>>
// 按位非
~
// 按位与
&
// 按位或
|
// 按位异或
^
```

条件运算符，

```c
a>b?c=1: c=2;
```

sizeof 运算符，

```c
sizeof(10);
sizeof(char);
sizeof(int);
```

