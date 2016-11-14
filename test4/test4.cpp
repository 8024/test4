#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
typedef int status;
typedef struct ElemType {		//二叉树中的数值域的结构定义
	int key;
	char data;
}TElemType;
typedef struct BiTNode {		//二叉树结点结构定义
	TElemType alldata;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
typedef struct QNode {			//层序遍历中所用的队列元素结构定义
	BiTree sTree;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {				//队列结构定义
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


status InitBiTree(BiTree &T);						//创建二叉树
status DestroyBiTree(BiTree &T);					//销毁二叉树
status Destroy(BiTree &p);	
status CreateBiTree(BiTree &T);						//为二叉树添加初始数据
status Create(BiTree &p);
status ClearBiTree(BiTree &T);						//清空二叉树
status BiTreeEmpty(BiTree T);						//判断二叉树是否为空
status BiTreeDepth(BiTree T);						//寻求二叉树的深度
status Depth(BiTree p);	
BiTree Root(BiTree T);								//寻求二叉树的根节点
status Value(BiTree T,TElemType &e);				//e为二叉树结点，返回此节点的值
status Assign(BiTree T,TElemType &e);				//e为二叉树节点，改变此节点的值
BiTree Parent(BiTree T,TElemType e);				//寻求某节点的父节点
status ParentJudge(BiTree p, BiTree q,BiTree &x, TElemType e);
BiTree LeftChild(BiTree T,TElemType e);				//寻求某节点的左孩子节点
status LeftChildJudge(BiTree p, BiTree &x, TElemType e);
BiTree RightChild(BiTree T,TElemType e);			//寻求某节点的右孩子节点
status RightChildJudge(BiTree p, BiTree &x, TElemType e);
BiTree LeftSibing(BiTree T,TElemType e);			//寻求某节点的左兄弟节点
status LeftSibingJudge(BiTree p, BiTree &x, TElemType e);
BiTree RightSibing(BiTree T,TElemType e);			//寻求某节点的右兄弟节点
status RightSibingJudge(BiTree p, BiTree &x, TElemType e);
status InsertChild(BiTree &T,TElemType p,int LR,BiTree &c);	//为二叉树添加子树
status DeleteChild(BiTree &T,TElemType p,int LR);	//为二叉树删除子树
status PreOrderTraverse(BiTree T);					//实现二叉树的前序遍历
status PreOrderTraverseJudge(BiTree p);
status InOrderTraverse(BiTree T);					//实现二叉树的中序遍历
status InOrderTraverseJudge(BiTree p);
status PostOrderTraverse(BiTree T);					//实现二叉树的后序遍历
status PostOrderTraverseJudge(BiTree p);
status LevelOrderTraverse(BiTree T);				//实现二叉树的层序遍历
status Find(BiTree T, BiTree &x,TElemType p);		//寻求某节点是否为此树的节点
status InitQueue(LinkQueue &Q);						//创建队列
status QueueEmpty(LinkQueue Q);						//判断队列是否为空
status EnQueue(LinkQueue &Q, BiTree num);			//入队列
status DeQueue(LinkQueue &Q, BiTree &num);			//出队列
status BiTreeSave(BiTree &T);						//实现二叉树的文件式保存
status SaveJudge(FILE *psave, BiTree Tsave);
status BiTreeRead(BiTree &T);						//实现二叉树的文件式读取
status ReadJudge(FILE *pread, BiTree &Tread);
int main() {
	BiTree T = nullptr; int op = 1;
	int i = 0, judge = 0;		//此处的judge为判断是否存在二叉树的变量
	BiTreeRead(T);
	if (T->lchild) {
		judge = 1;
	}
	while (op) {
		system("cls");
		if (judge) {
			printf("################## LevelOrderTraverse ###################\n");
			LevelOrderTraverse(T);
			printf("\n#########################################################\n");
		}
		printf("\n\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		printf("*********************************************************\n");
		printf("    	  1. InitBiTree        11. LeftChild\n");
		printf("    	  2. DestroyBiTree     12. RightChild\n");
		printf("    	  3. CreateBiTree      13. LeftSibing\n");
		printf("    	  4. ClearBiTree       14. RightSibing\n");
		printf("    	  5. BiTreeEmpty       15. InsertChild\n");
		printf("    	  6. BiTreeDepth       16. DeleteChild\n");
		printf("          7. Root              17. PreOrderTraverse\n");
		printf("          8. Value             18. InOrderTraverse\n");
		printf("          9. Assign            19. PostIrderTraverse\n");
		printf("         10. Parent            20. LevelOrderTraverse\n");
		printf("    	  0. Exit\n");
		printf("*********************************************************\n");
		printf("    请选择你的操作[0~20]:");
		scanf("%d", &op);
		printf("*********************************************************\n");
		switch (op) {
		case 1:
			if (judge == 1) {
				int intBiTree;
				printf("二叉树已存在，是否继续进行此操作：\n1-是  0-否\n");
				scanf("%d", &intBiTree);
				if (intBiTree) {
					if (InitBiTree(T))printf("二叉树创建成功！\n");
					else printf("二叉树创建失败！\n");
					judge = 1;
					break;
				}
				else break;
			}
			else {
				if (InitBiTree(T))printf("二叉树创建成功！\n");
				else printf("二叉树创建失败！\n");
				judge = 1;
				break;
			}
		case 2:
			if (judge) {
				judge = 0;
				if (DestroyBiTree(T))printf("二叉树销毁成功！\n");
				else printf("二叉树销毁失败！\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 3:
			if (judge) {
				printf("请输入二叉树的初始数据，以前序遍历的顺序输入并带有空集，（输入“0‘ ’”为空集）：\n");
				if (CreateBiTree(T))printf("二叉树创建时的数据添加成功！\n");
				else printf("二叉树创建时的数据添加失败！\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 4:
			if (judge) {
				if (ClearBiTree(T))printf("二叉树清空成功！\n");
				else printf("二叉树清空失败！\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 5:
			if (judge) {
				if (BiTreeEmpty(T)) printf("此二叉树是空树！\n");
				else printf("此二叉树不是空树！\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 6:
			if (judge) {
				printf("此二叉树的深度为%d\n", BiTreeDepth(T));
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 7:
			if (judge) {
				BiTree use1 = Root(T);
				if (use1) printf("此二叉树的根节点的数据域为%d%c.\n", use1->alldata.key, use1->alldata.data);
				else printf("此二叉树根节点获得错误！\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 8:
			if (judge) {
				TElemType e1;
				printf("请输入节点e的key域的值：\n");
				scanf("%d", &e1.key);
				Value(T, e1);
				if (!e1.key) {
					printf("此节点的data域的值为：%c.\n", e1.data);
				}
				else printf("节点e为错误节点！\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 9:
			if (judge) {
				TElemType e2;
				printf("请输入要更改节点的key的值以及更改后的data的值：\n");
				scanf("%d%c", &e2.key, &e2.data);
				Assign(T, e2);
				if (!e2.key) {
					printf("节点更改成功！\n");
				}
				else printf("节点更改失败！\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 10:
			if (judge) {
				BiTree use3;
				TElemType e3;
				printf("请输入需要寻找双亲节点的节点e的key和data的值：\n");
				scanf("%d%c", &e3.key, &e3.data);
				if (use3 = Parent(T, e3)) {
					printf("e的双亲节点的地址为%p，key的值为%d，data的值为%c。\n", use3, use3->alldata.key, use3->alldata.data);
				}
				else printf("数据输入错误！\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 11:
			if (judge) {
				BiTree use4;
				TElemType e4;
				printf("请输入需要寻找左孩子节点的节点e的key和data的值：\n");
				scanf("%d%c", &e4.key, &e4.data);
				if (use4 = LeftChild(T, e4)) {
					printf("e的左孩子节点的地址为%p，key的值为%d，data的值为%c。\n", use4, use4->alldata.key, use4->alldata.data);
				}
				else printf("e非此二叉树的节点或e无左孩子，数据输入错误！\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 12:
			if (judge) {
				BiTree use5;
				TElemType e5;
				printf("请输入需要寻找右孩子节点的节点e的key和data的值：\n");
				scanf("%d%c", &e5.key, &e5.data);
				if (use5 = RightChild(T, e5)) {
					printf("e的右孩子节点的地址为%p，key的值为%d，data的值为%c。\n", use5, use5->alldata.key, use5->alldata.data);
				}
				else printf("e非此二叉树的节点或e无右孩子，数据输入错误！\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 13:
			if (judge) {
				BiTree use6;
				TElemType e6;
				printf("请输入需要寻找左兄弟节点的节点e的key和data的值：\n");
				scanf("%d%c", &e6.key, &e6.data);
				if (use6 = LeftSibing(T, e6)) {
					printf("e的左兄弟节点的地址为%p，key的值为%d，data的值为%c。\n", use6, use6->alldata.key, use6->alldata.data);
				}
				else printf("e非此二叉树的节点或e无左兄弟，数据输入错误！\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 14:
			if (judge) {
				BiTree use7;
				TElemType e7;
				printf("请输入需要寻找右兄弟节点的节点e的key和data的值：\n");
				scanf("%d%c", &e7.key, &e7.data);
				if (use7 = RightSibing(T, e7)) {
					printf("e的右兄弟节点的地址为%p，key的值为%d，data的值为%c。\n", use7, use7->alldata.key, use7->alldata.data);
				}
				else printf("e非此二叉树的节点或e无右兄弟，数据输入错误！\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 15:
			if (judge) {
				BiTree c;
				TElemType p;
				int LR;
				printf("请输入需要插入树c的节点p的key和data的值：\n");
				scanf("%d%c", &p.key, &p.data);
				printf("请输入需要插入在p的左子树或右子树：0-左子树 1-右子树\n");
				scanf("%d", &LR);
				if (InsertChild(T, p, LR, c)) {
					printf("二叉树c插入成功！\n");
				}
				else printf("二叉树插入错误！\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 16:
			if (judge) {
				TElemType p;
				int LR;
				printf("请输入需要删除子树的节点p的key和data的值：\n");
				scanf("%d%c", &p.key, &p.data);
				printf("请输入需要删除p的左子树或右子树：0-左子树 1-右子树\n");
				scanf("%d", &LR);
				if (DeleteChild(T, p, LR)) {
					printf("子树删除成功！\n");
				}
				else printf("子树删除失败！\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 17:
			if (judge) {
				if (PreOrderTraverse(T)) {
					printf("以上数据为此二叉树的前序排列。\n");
				}
				else printf("此二叉树为空树，无数据输出。\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 18:
			if (judge) {
				if (InOrderTraverse(T)) {
					printf("以上数据为此二叉树的中序排列。\n");
				}
				else printf("此二叉树为空树，无数据输出。\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 19:
			if (judge) {
				if (PostOrderTraverse(T)) {
					printf("以上数据为此二叉树的后序排列。\n");
				}
				else printf("此二叉树为空树，无数据输出。\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 20:
			if (judge) {
				if (LevelOrderTraverse(T)) {
					printf("\n以上为此二叉树的层序排列。\n");
				}
				else printf("此二叉树为空树，无数据输出。\n");
			}
			else printf("不存在二叉树，此操作无法进行！请创建一个二叉树！\n");
			break;
		case 0:
			printf("欢迎下次再次使用本系统。\n");
			break;
		}
		printf("*********************************************************\n");
		system("pause");
	}
	if (judge) {
		BiTreeSave(T);
	}
	else {
		InitBiTree(T);
		BiTreeSave(T);
		free(T);
		T = NULL;
	}

}


status InitBiTree(BiTree &T) {						//初始化二叉树
	if (!(T = (BiTree)malloc(sizeof(BiTNode))))exit(OVERFLOW);
	T->lchild = NULL;
	T->rchild = NULL;
	return OK;
}				
status DestroyBiTree(BiTree &T) {					//实现销毁二叉树
	BiTree p;
	p = T->lchild;
	Destroy(p);
	free(T);
	T = NULL;
	return OK;
}
status Destroy(BiTree &p) {							//实现销毁二叉树的递归循环
	if (p) {
		if (p->lchild)Destroy(p->lchild);
		if (p->rchild)Destroy(p->rchild);
		free(p);
		p = NULL;
		return OK;
	}
	else return ERROR;
}	
status CreateBiTree(BiTree &T) {					//实现创建二叉树
	BiTree p;
	if(!(p= (BiTree)malloc(sizeof(BiTNode))))exit(OVERFLOW);
	if (Create(p)) {
		T->lchild = p;
		return OK;
	}
	else return ERROR;

}
status  Create(BiTree &p) {							//实现创建二叉树的内部递归循环
	TElemType c;
	scanf("%d", &c.key);
	scanf("%c", &c.data);
	if (c.key == 0 && c.data == ' ')p = NULL;
	else {
		if (!(p = (BiTree)malloc(sizeof(BiTNode))))exit(OVERFLOW);
		p->alldata.key = c.key;
		p->alldata.data = c.data;
		Create(p->lchild);
		Create(p->rchild);
	}
	return OK;
} 
status ClearBiTree(BiTree &T) {						//清空二叉树
	if (T && (T->lchild || T->rchild)) {
		if (T->lchild && (T->lchild->lchild || T->lchild->rchild))ClearBiTree(T->lchild);
		if (T->rchild && (T->rchild->lchild || T->rchild->rchild))ClearBiTree(T->rchild);
		if (T->lchild) {
			free(T->lchild);
			T->lchild = NULL;
		}
		if (T->rchild) {
			free(T->rchild);
			T->rchild = NULL;
		}
		return OK;
	}
	else return ERROR;
}   
status BiTreeEmpty(BiTree T) {					    //判断二叉树是否为空树
	if (T && !T->lchild&&!T->rchild)return OK;
	else return ERROR;
}
status BiTreeDepth(BiTree T) {						//经过运算得到二叉树的深度
	BiTree p;
	int depth;
	p = T->lchild;
	return (depth = Depth(p));
}
status Depth(BiTree p) {						   //运用的得到深度的递归循环
	int lnum,rnum;
	if (p) {
		if (!p->lchild)lnum = 0;
		if (!p->rchild)rnum = 0;
		if (p->lchild)lnum = Depth(p->lchild);
		if (p->rchild)rnum = Depth(p->rchild);
		return (lnum > rnum ? lnum + 1 : rnum + 1);
	}
	else return 0;
}
BiTree Root(BiTree T) {
	if (T) {
		return T->lchild;
	}
	else return NULL;
}
status Value(BiTree T, TElemType &e) {		//e为二叉树的某个节点，函数返回相应的值
	if (T) {
		if (T->alldata.key == e.key) {
			e.data = T->alldata.data;
			e.key = 0;		//用来判断取值操作正常进行，是内部标志
			return OK;
		}
		Value(T->lchild, e);
		Value(T->rchild, e);	
	}
	else return ERROR;
}
status Assign(BiTree T, TElemType &e/*, TElemType value*/) {		//给二叉树中的e节点改变值
	if (T) {
		if (T->alldata.key == e.key) {
			T->alldata.data = e.data;
			e.key = 0;	//用来判断赋值操作正常进行，是为内部标志
			return OK;
		}
		Assign(T->lchild, e);
		Assign(T->rchild, e);
	}
	else return ERROR;
}
BiTree Parent(BiTree T, TElemType e) {	//寻找指定节点的双亲节点
	BiTree p,x;
	x = nullptr;
	p = T->lchild;
	ParentJudge(T, p, x, e);
	if (!x) {
		printf("此节点非二叉树结点！");
	}
	if (x == T) {
		printf("此节点为二叉树的根节点！");
		x = nullptr;
	}
	return x;
}
status ParentJudge(BiTree p, BiTree q,BiTree &x, TElemType e) {		//用于寻找双亲节点的递归循环
	if (q) {
		ParentJudge(q, q->lchild, x, e);
		if (q->alldata.data == e.data&&q->alldata.key == e.key) {
			x = p;
			return OK;
		}
		ParentJudge(q, q->rchild, x, e);
	}
	else return ERROR;
}
BiTree LeftChild(BiTree T, TElemType e) {		//寻找指定节点的左孩子节点
	BiTree p, x;
	p = T->lchild;
	x = nullptr;
	LeftChildJudge(p, x, e);
	return x;
}
status LeftChildJudge(BiTree p, BiTree &x, TElemType e) {	//用于寻找左孩子节点的递归循环
	if (p) {
		LeftChildJudge(p->lchild, x, e);
		if (p->alldata.data == e.data&&p->alldata.key == e.key) {
			if (p->lchild) {
				x = p->lchild;
				return OK;
			}
			else return ERROR;
		}
		LeftChildJudge(p->rchild, x, e);
	}
	else return ERROR;
}
BiTree RightChild(BiTree T, TElemType e) {		//寻找指定节点的右孩子节点
	BiTree p, x;
	p = T->lchild;
	x = nullptr;
	RightChildJudge(p, x, e);
	return x;
}
status RightChildJudge(BiTree p, BiTree &x, TElemType e) {		//用于寻找右孩子节点的递归循环
	if (p) {
		RightChildJudge(p->lchild, x, e);
		if (p->alldata.data == e.data&&p->alldata.key == e.key) {
			if (p->rchild) {
				x = p->rchild;
				return OK;
			}
			else return ERROR;
		}
		RightChildJudge(p->rchild, x, e);
	}
	else return ERROR;
}
BiTree LeftSibing(BiTree T, TElemType e) {		//寻找指定节点的左兄弟
	BiTree p, x;
	p = T->lchild;
	x = nullptr;
	LeftSibingJudge( p, x, e);
	return x;
}
status LeftSibingJudge( BiTree p, BiTree &x, TElemType e) {		//用于寻找左兄弟的递归循环
	if (p) {
		LeftSibingJudge(p->lchild, x, e);
		if (p->rchild) {
			if (p->rchild->alldata.data == e.data&&p->rchild->alldata.key == e.key) {
				if (p->lchild) {
					x = p->lchild;
					return OK;
				}
				else return ERROR;
			}
		}
		LeftSibingJudge(p->rchild, x, e);
	}
	else return ERROR;
}
BiTree RightSibing(BiTree T, TElemType e) {			//寻找指定节点的右兄弟节点
	BiTree p, x;
	p = T->lchild;
	x = nullptr;
	RightSibingJudge(p, x, e);
	return x;
}
status RightSibingJudge(BiTree p, BiTree &x, TElemType e) {		//用于寻找右兄弟的递归循环
	if (p) {
		RightSibingJudge(p->lchild, x, e);
		if (p->lchild) {
			if (p->lchild->alldata.data == e.data&&p->lchild->alldata.key == e.key) {
				if (p->rchild) {
					x = p->rchild;
					return OK;
				}
				else return ERROR;
			}
		}
		RightSibingJudge(p->rchild, x, e);
	}
	else return ERROR;
}

status InsertChild(BiTree &T, TElemType p, int LR, BiTree &c) {				//为二叉树插入子树
	if (!(c = (BiTree)malloc(sizeof(BiTNode))))exit(OVERFLOW);
	BiTree x = nullptr;
	Find(T->lchild, x, p);
	if (!x) {
		printf("节点p数据错误！\n");
		return ERROR;
	}
	printf("请输入需要插入的无右子树的二叉树c:\n");
	Create(c);
	if (!c->rchild) {
		if (LR == 0) {
			c->rchild = x->lchild;
			x->lchild = c;
			return OK;
		}
		if (LR == 1) {
			c->rchild = x->rchild;
			x->rchild = c;
			return OK;
		}
	}
	else {
		printf("输入的二叉树c的右子树非空，数据错误！\n");
		return ERROR;
	}
}
status DeleteChild(BiTree &T, TElemType p, int LR) {			//为二叉树删除子树
	BiTree x = nullptr;
	Find(T->lchild, x, p);
	if (!x) {
		printf("节点p数据错误！\n");
		return ERROR;
	}
	if (LR == 0) {
		Destroy(x->lchild);
		return OK;
	}
	if (LR == 1) {
		Destroy(x->rchild);
		return OK;
	}
	else return ERROR;
}
status PreOrderTraverse(BiTree T) {					//实现二叉树的前序遍历
	BiTree p;
	p = T->lchild;
	if (PreOrderTraverseJudge(p)) {
		putchar('\n');
		return OK;
	}
	else return ERROR;
}
status PreOrderTraverseJudge(BiTree p) {			//实现二叉树的前序遍历的递归循环
	if (p) {
		printf("%d%c ", p->alldata.key, p->alldata.data);
		PreOrderTraverseJudge(p->lchild);
		PreOrderTraverseJudge(p->rchild);
		return OK;
	}
	else return ERROR;
}
status InOrderTraverse(BiTree T) {					//实现二叉树的中序遍历
	BiTree p;
	p = T->lchild;
	if (InOrderTraverseJudge(p)) {
		putchar('\n');
		return OK;
	}
	else return ERROR;
}
status InOrderTraverseJudge(BiTree p) {				//实现二叉树的中序遍历的递归循环
	if (p) {
		InOrderTraverseJudge(p->lchild);
		printf("%d%c ", p->alldata.key, p->alldata.data);
		InOrderTraverseJudge(p->rchild);
		return OK;
	}
	else return ERROR;
}
status PostOrderTraverse(BiTree T) {				//实现二叉树的后序遍历
	BiTree p;
	p = T->lchild;
	if (PostOrderTraverseJudge(p)) {
		putchar('\n');
		return OK;
	}
	else return ERROR;
}
status PostOrderTraverseJudge(BiTree p) {			///实现二叉树的后序遍历的递归循环
	if (p) {
		PostOrderTraverseJudge(p->lchild);
		PostOrderTraverseJudge(p->rchild);
		printf("%d%c ", p->alldata.key, p->alldata.data);
		return OK;
	}
	else return ERROR;
}
status LevelOrderTraverse(BiTree T) {				//实现二叉树的层序遍历
	LinkQueue Q;
	BiTree p;
	p = T->lchild;
	InitQueue(Q);
	if (p) {
		EnQueue(Q, p);
		while (!QueueEmpty(Q)) {
			DeQueue(Q, p);
			printf("%d%c ",p->alldata.key,p->alldata.data);
			if (p->lchild)EnQueue(Q, p->lchild);
			if (p->rchild)EnQueue(Q, p->rchild);
		}
		return OK;
	}
	else return ERROR;
}


status Find(BiTree T, BiTree &x, TElemType p) {				//判断某节点是否为二叉树的节点，并返回其地址值
	if (T) {
		Find(T->lchild, x, p);
		if (T->alldata.data == p.data&&T->alldata.key == p.key) {
			x = T;
			return OK;
		}
		Find(T->rchild, x, p);
	}
	else return ERROR;
}
status InitQueue(LinkQueue &Q) {					//创建队列
	QueuePtr p;
	if (!(p = (QueuePtr)malloc(sizeof(QNode))))exit(OVERFLOW);
	Q.front = p;
	Q.rear = p;
	Q.front->next = NULL;
	return OK;
}
status QueueEmpty(LinkQueue Q) {					//判断队列是否为空
	if (Q.front == Q.rear)return TRUE;
	else return ERROR;
}
status EnQueue(LinkQueue &Q, BiTree num) {			//入队列
	QueuePtr p;
	if (!(p = (QueuePtr)malloc(sizeof(QNode))))exit(OVERFLOW);
	p->sTree = num;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
status DeQueue(LinkQueue &Q, BiTree &num) {			//出队列
	QueuePtr p;
	if (Q.front == Q.rear)return ERROR;
	p = Q.front->next;
	num = p->sTree;
	Q.front->next = p->next;
	if (Q.rear == p)Q.rear = Q.front;
	free(p);
	return OK;

}
status BiTreeRead(BiTree &T) {						//实现二叉树的文件式读取
	FILE *pread; BiTree Tread;
	if (!(pread = fopen("BiTreeDat.txt", "rb"))) {
		printf("数据加载失败或数据不存在！");
		return FALSE;
	}
	if (!(Tread = (BiTree)malloc(sizeof(BiTNode))))exit(OVERFLOW);
	InitBiTree(T);
	ReadJudge(pread, Tread);
	T->lchild = Tread;
	fclose(pread);
	return OK;
}
status ReadJudge(FILE *pread, BiTree &Tread) {			//实现读取的递归循环
	if (!(Tread = (BiTree)malloc(sizeof(BiTNode))))exit(OVERFLOW);
	fread(Tread, sizeof(BiTNode), 1, pread);
	if (Tread->alldata.key != 0 || Tread->alldata.data != ' ') {
		ReadJudge(pread, Tread->lchild);
		ReadJudge(pread, Tread->rchild);
	}
	else {
		free(Tread);
		Tread = NULL;
	}
	return OK;
}
status BiTreeSave(BiTree &T) {						//实现二叉树的文件式储存
	FILE *psave; BiTree Tsave;
	if (!(psave = fopen("BiTreeDat.txt", "wb")))return FALSE;
	Tsave = T;
	SaveJudge(psave, Tsave->lchild);
	fclose(psave);
	return OK;
}
status SaveJudge(FILE *psave, BiTree Tsave) {			//实现储存的递归循环
	if (Tsave) {
		fwrite(Tsave, sizeof(BiTNode), 1, psave);
		SaveJudge(psave, Tsave->lchild);
		SaveJudge(psave, Tsave->rchild);
		return OK;
	}
	else {
		BiTree newuse;
		if (!(newuse = (BiTree)malloc(sizeof(BiTNode))))exit(OVERFLOW);
		newuse->alldata.key = 0;
		newuse->alldata.data = ' ';
		newuse->lchild = newuse->rchild = NULL;
		fwrite(newuse, sizeof(BiTNode), 1, psave);
		return OK;
	}
}