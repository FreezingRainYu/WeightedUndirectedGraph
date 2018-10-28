#pragma once
#include<list>
#include"MinSpanTree.h"

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

void SortedQueue::insert(MSTEdgeNode x)
{
	edgeList.push_back(x);
}

void SortedQueue::sort()
{
	edgeList.sort();
}

MSTEdgeNode SortedQueue::removeMin()
{
	MSTEdgeNode ed = edgeList.front();
	edgeList.pop_front();
	return ed;
}
