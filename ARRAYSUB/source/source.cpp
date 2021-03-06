#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class node;
class heapMax
{
	std::vector<node*> heap;
	int size;
public:
	heapMax()
{
		size = 0;
}
	void insert(node*);
	node* extractMax();
	void deleteNode(node*);
	void decompile();
	int getSize()
	{return size;}
	void freeHeap();
};
class node {

public:
	int data;
	int indexInHeap;
	node(int data)
	{
		this->data = data;
		indexInHeap = 0;
	}
	node();

};
int main()
{
	int N,k,temp;
	cin>>N;
	vector<node*> array(N);
	for (int i=0;i<N;i++)
	{
		cin>>temp;
		array[i] =new node(temp);
	}
	cin>>k;
	heapMax heap;
	node* returnNode;
	for(int i=0;i<N-k+1;i++)
	{
		if(i==0)
		{
			for(int j=i;j<i+k;j++)
			{
				heap.insert(array[j]);
			}
		}
		else
			heap.insert(array[i+k-1]);
		returnNode = heap.extractMax();
		if(i != N-k)
		cout<<returnNode->data<<" ";
		else
			cout<<returnNode->data;
		heap.deleteNode(array[i]);
	}

	for(int i=0;i<N;i++)
	{
		delete array[i];
	}
	return 0;
}

void heapMax::insert(node* Edge)
{
	int parent,child;
	node* tempEdge;
	heap.push_back(Edge);
	Edge->indexInHeap = size;
	size++;
	child = size;
	parent = (child)/2;
	while((parent >=1) && (heap[parent-1]->data < heap[child-1]->data))
	{
		tempEdge = heap[child-1];
		heap[child-1] = heap[parent-1];
		heap[child-1]->indexInHeap = child - 1;
		heap[parent-1] = tempEdge;
		heap[parent-1]->indexInHeap = parent - 1;
		child = parent;
		parent = parent/2;
	}

}

node* heapMax::extractMax(void)
{
	return heap[0];
}
void heapMax::deleteNode(node* del)
{
	node* tempEdge;
	int parent = del->indexInHeap + 1;
	tempEdge = heap[del->indexInHeap];
	heap[del->indexInHeap] = heap[size-1];
	heap[del->indexInHeap]->indexInHeap = del->indexInHeap;
	heap[size-1] = tempEdge;
	heap[size-1]->indexInHeap = size-1;
	vector<node*> :: iterator itr = heap.begin();
	itr = itr + size -1;
	size--;

	int child = parent;
	while(2*parent <= size)
	{
		if(2*parent != size)
		{
		child = (heap[(2*parent)-1]->data >= heap[(2*parent)]->data) ? 2*parent : 2*parent + 1;
		if(heap[child-1]->data > heap[parent-1]->data)
		{
			tempEdge = heap[child -1];
			heap[child - 1] = heap[parent - 1];
			heap[child-1]->indexInHeap = child-1;
			heap[parent - 1] = tempEdge;
			heap[parent-1]->indexInHeap = parent-1;
			parent = child;
		}
		else
			break;
		}
		else
		{
			child = 2*parent;
			if(heap[child-1]->data > heap[parent-1]->data)
			{
				tempEdge = heap[child -1];
				heap[child - 1] = heap[parent - 1];
				heap[child-1]->indexInHeap = child-1;
				heap[parent - 1] = tempEdge;
				heap[parent-1]->indexInHeap = parent-1;
				parent = child;
			}
			else
				break;
		}
	}
	(*itr)->indexInHeap = 0;
	heap.erase(itr);
}
void heapMax::decompile()
{
	for(vector<node*>::iterator itr = heap.begin();itr!=heap.end();itr++)
	{
		cout<<(*itr)->data<<" ";
	}
	cout<<endl;
		for(vector<node*>::iterator itr = heap.begin();itr!=heap.end();itr++)
		{
			cout<<(*itr)->indexInHeap<<" ";
		}
		cout<<endl;

}
