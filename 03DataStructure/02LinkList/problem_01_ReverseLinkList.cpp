#include <iostream>

using namespace std;

struct Node;
typedef struct Node* pNode;
typedef char DataType;
struct Node
{
	DataType info;
	struct Node* link;
};

typedef struct Node*  LinkList;

/**
@common:创建空链表
@param：void
@return: 指向链表的指针
*/
LinkList createNULLLinkList()
{
	LinkList linklist = (LinkList)malloc(sizeof(struct Node));
	if (linklist != NULL)
	{
		linklist->link = NULL;
	}
	else
	{
		printf("out of space!\n");
	}
	return linklist;
}

/**
@common:创建链表（头插法）
@param：
@return: 指向顺序表的指针
*/

LinkList createLinkListFromHead()
{
	LinkList llist, s;
	s = NULL;
	//头插法先得有头，先申请空间 
	llist = (LinkList) malloc(sizeof(struct Node));
	llist->link = NULL;
	//s = llist->link ;

	//s = NULL;
	char ch = getchar();
	while (ch != '#')
	{
		s = (LinkList)malloc(sizeof(struct Node));
		//检验自己写
		s->info = ch;
		s->link = llist->link;
		llist->link = s;
		ch = getchar();
	}
	return llist;
}

/**
@common:创建链表（尾插法）
@param：
@return: 指向顺序表的指针
*/

LinkList createLinlListFromTail()
{
	LinkList llist = NULL;
	LinkList  s;//待插指针
	LinkList r = NULL;//尾指针
	char ch = getchar();
	while (ch != '#')
	{
		s = (LinkList)malloc(sizeof(struct Node));
		s->info = ch;
		//llist为空说明链表中只有llist
		if (llist == NULL)
		{
			llist = s;
		}
		else
			//否则插到尾指针的下一个节点	
		{
			r->link = s;
		}
		//改变尾指针的指向
		r = s;
		ch = getchar();
	}
	//把尾指针的下一个节点设置为空
	if (r != NULL)
	{
		r->link = NULL;
	}
	return llist;
}

/**
@common:创建链表（引入头结点的尾插法）
@param：
@return: 指向顺序表的指针
*/

LinkList createLinkListWithHeadFromTail()
{
	LinkList llist;//头结点
	LinkList r;//尾节点
	LinkList s;//待插节点
	char ch = getchar();
	//为头结点分配内存（重要）
	llist = (LinkList)malloc(sizeof(struct Node));

	//尾指针指向头结点
	r = llist;
	while (ch != '#')
	{
		//为待存节点分配空间
		s = (LinkList)malloc(sizeof(struct Node));
		//赋值
		s->info = ch;
		//待插节点放位置
		r->link = s;
		//改变尾指针的指向
		r = s;
		//再次接收字符进行下一次的处理
		ch = getchar();
	}
	r->link = NULL;

	return llist;
}


/**
@common:尾插法插入元素
@param：llist指向链表的指针，在p节点之后插入元素，x为元素类型
@return: 1为成功，0为失败
*/

int insertLinkListPost(LinkList llist, pNode p, DataType x)
{
	//分配节点空间
	pNode q = (LinkList)malloc(sizeof(struct Node));
	if (q == NULL)
	{
		printf("out of space!");
	}
	//赋值
	q->info = x;
	//q的下一个节点变为是p的下一个节点，因为插入了新的元素值
	q->link = p->link;
	p->link = q;
	return 1;
}

/**
@common:头插法插入元素
@param：在p节点之前插入元素，x为元素类型
@return: 1为成功，0为失败
*/

int insertLinkListPre(LinkList p, DataType x)
{
	LinkList q;//辅助变量，用于寻找合适的插入位置
	LinkList s;//待插入节点
	LinkList head;//头结点
	//头结点申请内存
	head = (LinkList)malloc(sizeof(struct Node));
	if (head == NULL)
	{
		printf("malloc head error!\n");
		return false;
	}
	//待插节点申请内存
	s = (LinkList)malloc(sizeof(struct Node));
	if (s == NULL)
	{
		printf("out of space!\n");
		return 0;
	}
	//q指向头结点
	q = head;
	//循环找到位置p，在前面插入，断指针，再连起来
	while (q != p)
	{
		q = q->link;
	}
	//在前面插入
	s->link = p;
	//修改q的位置
	q->link = s;
	return 1;
}

/**
  打印节点
*/
void printLinkList(LinkList llist)
{
	if (llist == NULL)
	{
		printf("llist is NULL!\n");
	}
	LinkList p = llist;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p->link;
	}
}




pNode reverseLinkList(pNode head) {
	//1->2->3->4->null
	// null<-1<-2<-3<-4
	pNode newHead = NULL;
	pNode tmp;

	//先处理头结点
	while (head != NULL) {
		
		tmp = head;//保存当前的头结点
		head = head->link;//头结点往下走

		//头插法
		tmp->link = newHead;//刚开始设置为NULL,(1-->NULL)后来同步tmp更新
		newHead = tmp;//将tmp节点设置为新头
	}
	return newHead;
}


//也是头插法，3个指针
//利用if语句来判断旧链表是否已经到达尾部
pNode reverseLinkList2(pNode head) {

	if (head == NULL) {
		return NULL;
	}
	pNode p0 = NULL;
	pNode p1 = head;
	pNode p2 = head->link;

	while (p1 != NULL) {
		p1->link = p0;

		p0 = p1;
		p1 = p2;

		if (p2 != NULL) {
			p2 = p2->link;
		}
	}
	return p0;
}


//测试ok
/**
int main() {

	//LinkList list = createNULLLinkList();
	//LinkList list = createLinlListFromTail();
	//LinkList list = createLinkListFromHead();
	//pNode p = reverseLinkList(list);
	//printLinkList(p);

	//int a = (int)(((int*)0) + 4);
	//cout << a << endl;//16
	return 0;
}*/



