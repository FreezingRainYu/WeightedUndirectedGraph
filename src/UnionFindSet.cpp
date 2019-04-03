#include "../inc/UnionFindSet.h"

UnionFindSet::UnionFindSet(int sz)
{
    size = sz;
    parent = new int[size];
    for (int i = 0; i < size; ++i)
    {
        parent[i] = -1;
    }
}

UnionFindSet::~UnionFindSet()
{
    delete[] parent;
}

//�����Ӽ��ϲ�����Ȩ����
void UnionFindSet::setUnion(int root1, int root2)
{
    int r1 = find(root1), r2 = find(root2), temp;
    if (r1 != r2)
    {
        temp = parent[r1] + parent[r2];
    }
    if (parent[r2] < parent[r1])
    {
        parent[r1] = r2;
        parent[r2] = temp;
    }
    else
    {
        parent[r2] = r1;
        parent[r1] = temp;
    }
}

//��Ѱ����x�ĸ����۵�����ѹ��·����
int UnionFindSet::find(int x)
{
    int j;
    for (j = x; parent[j] >= 0; j = parent[j]);
    while (x != j)
    {
        int temp = parent[x];
        parent[x] = j;
        x = temp;
    }
    return j;
}
