/*
typedef

typedef 关键字，可以使用它来为类型取一个新的名字

typedef vs #define
    - typedef 仅限于为类型定义符号名称，#define 不仅可以为类型定义别名，
    也能为数值定义别名，比如您可以定义 1 为 ONE。
    - typedef 是由编译器执行解释的，#define 语句是由预编译器进行处理的。
*/

#include <stdio.h>
#include <string.h>

// C语言 没有 布尔量 ，可以define
// 或者 enum 来设置
#define TRUE 1
#define FALSE 0

typedef struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
} Book;

int main()
{
    // struct Books book;

    Book book;

    strcpy(book.title, "title");
    strcpy(book.author, "author");
    strcpy(book.subject, "subject");
    book.book_id = 12345;

    printf("书标题 : %s\n", book.title);
    printf("书作者 : %s\n", book.author);
    printf("书类目 : %s\n", book.subject);
    printf("书 ID : %d\n", book.book_id);

    printf("TRUE 的值：%d\n", TRUE);
    printf("FALSE 的值：%d\n", FALSE);

    return 0;
}