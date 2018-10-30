# COStream 重构
## 1. 目录说明
- `src` 源码目录
    - `bin` 编译生成的`.o`文件,会被<kbd>make clean</kbd>删除掉
    - `config` 词法分析和语法分析配置文件
    - `include` 
    - `src`
    - `Makefile`
    - `a` 临时使用的作为`a.out`存在的可执行程序
- `tests` 测试用例
- `doc` 文档
    - `0.makefile.md` makefile 文件解读
    - `1.lex.md` 词法分析
    - `2.yacc.md` 语法分析
    - `...`
    - `7.heap.md` 鸡肋的内存分配封装

## 2. 功能覆盖说明 & ~~吐槽~~
> 这是一个实验性的项目, 我只在其中实现 `COStream`前端代码的一个子集,

~~事实上它原本前端代码那么繁杂也不知道都发挥作用了没, 例如`123.`和`.123F`~~
- 数据类型
    - 暂不支持 unsigned , 精力集中于 int double, 尽量少用 long 和 float
- Node 类型目前支持到了:
    - `IdNode` `ConstNode`
- Analysis 暂不支持

## 3.截图展示效果
- [x] 目前已经达到的效果: `v1.3.0` - 能输出 type 为 Sint 的节点了(包括八进制和十六进制的识别,此时为简化处理都把它们处理为 Sint)
![](https://i.loli.net/2018/10/30/5bd7f6c6880de.png)
