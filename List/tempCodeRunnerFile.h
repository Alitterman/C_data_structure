//定义所需函数
bool InitList(List &L);                                     //初始化顺序表
bool DestoryList(List &L);                                  //销毁顺序表
bool ClearList(List &L);                                    //重置为空表
bool isEmptyList(List L);                                   //判断表是否为空
int ListLength(List L);                                     //判断表长
bool GetElem(List L, int i, ElemType &e);                   //用e返回L中第i个元素的值
bool locateElem(List L, ElemType &e, ElemType (*ptr)(...)); //返回L中第一个与e满足关系compare（）的数据元素的位序，若不存在，返回0
bool PriorElem(List L, ElemType cur, ElemType &prior);      //返回元素cur的前驱元素
bool NextElem(List L, ElemType cur, ElemType &next);        //返回元素cur的后继元素
bool InsertElem(List &L, int i, ElemType e);                //将e插入到顺序表第i个位置上
bool DeleteElem(List &L, int i, ElemType &e);               //删除顺序表第i个位置上的元素，并用e返回其值，L长度减一

bool InitList(List &L)
{
    //初始化数组，初始长度为0
    // L.elem = (ElemType*) malloc(MAXSIZE * sizeof(ElemType));//c中malloc语法分配内存
    L.elem = new ElemType[MAXSIZE];

    if (L.elem == NULL)
    {
        exit(OVERFLOW);
    };

    L.lenght = 0;         //初始长度为0
    L.listsize = MAXSIZE; //初始分配容量

    return true;
}

bool DestoryList(List &L)
{
    if (&L == NULL || L.elem == NULL)
    {
        return false; // 确保顺序表结构存在
    }

    free(L.elem); //释放内存空间

    //全部置零
    L.elem = NULL;
    L.lenght = 0;
    L.listsize = 0;

    return true;
}

bool ClearList(List &L)
{
    if (&L == NULL || L.elem == NULL)
    {
        return false; // 确保顺序表结构存在
    }

    L.lenght = 0;

    return true;
}

bool isEmpty(List L)
{
    if (&L == NULL || L.elem == NULL)
    {
        return false; // 确保顺序表结构存在
    }
    return (L.lenght == 0 ? true : false);
}

int ListLength(List L)
{
    if (&L == NULL || L.elem == NULL)
    {
        return false; // 确保顺序表结构存在
    }
    return L.lenght;
}

bool GetElem(List L, int i, ElemType &e)
{
    if (&L == NULL || L.elem == NULL)
    {
        return false; // 确保顺序表结构存在
    }

    if (i < 0 || i > L.lenght)
    {
        return false; // 数组越界报错
    }

    e = L.elem[i - 1];

    return true;
}

bool PriorElem(List L, ElemType cur, ElemType &prior)
{
    if (&L == NULL || L.elem == NULL)
    {
        return false; // 确保顺序表结构存在
    }

    for (int i = 1; i < L.lenght; i++)
    {
        if (L.elem[i] == cur)
        {
            prior = L.elem[i - 1];
            return true;
        }
    }
    return false;
}

bool NextElem(List L, ElemType cur, ElemType &next)
{
    if (&L == NULL || L.elem == NULL)
    {
        return false; // 确保顺序表结构存在
    }

    for (int i = L.lenght - 2; i >= 0; i--)
    {
        if (L.elem[i] == cur)
        {
            next = L.elem[i + 1];
            return true;
        }
    }
    return false;
}

bool InsertElem(List &L, int i, ElemType e)
{
    ElemType temp1;
    ElemType temp2;
    if (i < 1 || i > L.lenght + 1)
    {
        return false; //数组越界
    }
    if (L.lenght + 1 > L.listsize)
    {
        // return false; //数组已满
        //也可以扩容
        int newlistsize = L.listsize + 10;
        ElemType *newlist = new ElemType[newlistsize];          //重新分配内存
        memcpy(newlist, L.elem, sizeof(ElemType) * L.listsize); //拷贝内存数据到新数组中

        if (newlist == NULL)
            exit(OVERFLOW);

        L.elem = newlist;
        L.listsize = newlistsize;
    }

    if (&L == NULL || L.elem == NULL)
    {
        return false; // 确保顺序表结构存在
    }

    ElemType *insertIndex = &L.elem[i - 1];

    for (ElemType *p = &L.elem[L.lenght - 1]; p >= insertIndex; p--)
    {
        *(p + 1) = *p;
    }

    *insertIndex = e;
    // printf("The insert value is:%d\n",e);
    L.lenght++;
    return true;
}

bool DeleteElem(List &L, int i, ElemType &e)
{
    ElemType temp1;
    ElemType temp2;
    if (i < 1 || i > L.lenght)
    {
        return false; //数组越界
    }

    if (&L == NULL || L.elem == NULL)
    {
        return false; // 确保顺序表结构存在
    }

    e = L.elem[i - 1];

    for (ElemType *p = &L.elem[i - 1]; p >= &L.elem[L.lenght - 1]; p--)
    {
        *p = *(p + 1);
    }
    L.lenght--;

    return true;
}

int main()
{