/*
枚举

enum 枚举名 {枚举元素1,枚举元素2,......};
注意：第一个枚举成员的默认值为整型的0，后续枚举成员的值在前一个成员上加1。
    可以定义第一个枚举成员的值，例如 enum1 = 1
*/

#include <stdio.h>

enum DAY
{
    MON = 1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};

int main()
{
    enum DAY day;
    day = WED;
    printf("enum DAY : %d\n", day);

    // 遍历枚举
    /*
    非连续枚举不能遍历, 例如：
    enum
    {
        ENUM_0,
        ENUM_10 = 10,
        ENUM_11,
    }
    */
    for (day = MON; day <= SUN; day++)
        printf("枚举元素遍历：%d\n", day);

    // 枚举在switch中
    enum color
    {
        red = 1,
        green,
        blue
    };
    enum color favorite_color;

    printf("请输入你喜欢的颜色（1.red, 2.green, 3.blue)");
    scanf("%d", &favorite_color);

    switch (favorite_color)
    {
    case red:
        printf("你喜欢的颜色是红色\n");
        break;
    case green:
        printf("你喜欢的颜色是绿色\n");
        break;
    case blue:
        printf("你喜欢的颜色是蓝色\n");
        break;
    default:
        printf("你没有选择你喜欢的颜色\n");
    }

    // 将整数转换为枚举
    enum day
    {
        saturday,
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        friday
    } workday;

    int a = 1;
    enum day weekend;

    weekend = (enum day)a; // 类型转换
    // weekend = a; // 错误，需要转换类型
    printf("weekend: %d\n", weekend);

    return 0;
}