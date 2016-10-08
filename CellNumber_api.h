/**
* 通用返回码定义
* 建议不同类型的返回码分段定义，且都集中到此处
* 返回码分段有利于根据错误码分析性能问题
*/

enum RETCODE{
    EN_SUCCESS = 0,
    EN_FAILURE = 1,
    EN_NULL_PTR = 2,
};

/* 存储数据的冲突链表 */
typedef struct  
{
    NODE* PrevNode;
    NODE* NextNode;
    void* Data;
}List;

/**
* 每个节点都是一个冲突链表的首节点
* 因为节点采用（key->value)的组织方式，而实际使用过程中可能存在一个号码(key)对应多个(value)的情形
*/
typedef struct
{
    NODE* Father;
    NODE* OldestSon;
    NODE* Brother;
    List* DataList;
}NODE;

/**
* 树的组织方式采用以下方式
          8(root)
         /
        6->8->10
       /
      1->2->3->4
* 这种组织方式的好处在于每个父节点不需要知道自己有多少个子节点，只需要记住自己的长子即可
*/
typedef struct  
{
    NODE* root;       /* 树的根节点 */
    int NodeNum;      /* 树中节点个数 */
    int AllocTimes;   /* 申请节点的次数 */
    int ReleaseTimes; /* 释放节点的次数 */
}TREE;
