#ifndef SORTED_QUEUE_H
#define SORTED_QUEUE_H
#include <list>
#include "MinSpanTree.h"

using std::list;

class SortedQueue
{
private:
    list<MSTEdgeNode> edgeList;

public:
    void insert(MSTEdgeNode x); //������С��
    void sort();
    MSTEdgeNode removeMin(); //���沢ɾ���Ѷ��ϵ���СԪ��
};

#endif
