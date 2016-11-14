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
typedef struct ElemType {		//�������е���ֵ��Ľṹ����
	int key;
	char data;
}TElemType;
typedef struct BiTNode {		//���������ṹ����
	TElemType alldata;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
typedef struct QNode {			//������������õĶ���Ԫ�ؽṹ����
	BiTree sTree;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {				//���нṹ����
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;


status InitBiTree(BiTree &T);						//����������
status DestroyBiTree(BiTree &T);					//���ٶ�����
status Destroy(BiTree &p);	
status CreateBiTree(BiTree &T);						//Ϊ��������ӳ�ʼ����
status Create(BiTree &p);
status ClearBiTree(BiTree &T);						//��ն�����
status BiTreeEmpty(BiTree T);						//�ж϶������Ƿ�Ϊ��
status BiTreeDepth(BiTree T);						//Ѱ������������
status Depth(BiTree p);	
BiTree Root(BiTree T);								//Ѱ��������ĸ��ڵ�
status Value(BiTree T,TElemType &e);				//eΪ��������㣬���ش˽ڵ��ֵ
status Assign(BiTree T,TElemType &e);				//eΪ�������ڵ㣬�ı�˽ڵ��ֵ
BiTree Parent(BiTree T,TElemType e);				//Ѱ��ĳ�ڵ�ĸ��ڵ�
status ParentJudge(BiTree p, BiTree q,BiTree &x, TElemType e);
BiTree LeftChild(BiTree T,TElemType e);				//Ѱ��ĳ�ڵ�����ӽڵ�
status LeftChildJudge(BiTree p, BiTree &x, TElemType e);
BiTree RightChild(BiTree T,TElemType e);			//Ѱ��ĳ�ڵ���Һ��ӽڵ�
status RightChildJudge(BiTree p, BiTree &x, TElemType e);
BiTree LeftSibing(BiTree T,TElemType e);			//Ѱ��ĳ�ڵ�����ֵܽڵ�
status LeftSibingJudge(BiTree p, BiTree &x, TElemType e);
BiTree RightSibing(BiTree T,TElemType e);			//Ѱ��ĳ�ڵ�����ֵܽڵ�
status RightSibingJudge(BiTree p, BiTree &x, TElemType e);
status InsertChild(BiTree &T,TElemType p,int LR,BiTree &c);	//Ϊ�������������
status DeleteChild(BiTree &T,TElemType p,int LR);	//Ϊ������ɾ������
status PreOrderTraverse(BiTree T);					//ʵ�ֶ�������ǰ�����
status PreOrderTraverseJudge(BiTree p);
status InOrderTraverse(BiTree T);					//ʵ�ֶ��������������
status InOrderTraverseJudge(BiTree p);
status PostOrderTraverse(BiTree T);					//ʵ�ֶ������ĺ������
status PostOrderTraverseJudge(BiTree p);
status LevelOrderTraverse(BiTree T);				//ʵ�ֶ������Ĳ������
status Find(BiTree T, BiTree &x,TElemType p);		//Ѱ��ĳ�ڵ��Ƿ�Ϊ�����Ľڵ�
status InitQueue(LinkQueue &Q);						//��������
status QueueEmpty(LinkQueue Q);						//�ж϶����Ƿ�Ϊ��
status EnQueue(LinkQueue &Q, BiTree num);			//�����
status DeQueue(LinkQueue &Q, BiTree &num);			//������
status BiTreeSave(BiTree &T);						//ʵ�ֶ��������ļ�ʽ����
status SaveJudge(FILE *psave, BiTree Tsave);
status BiTreeRead(BiTree &T);						//ʵ�ֶ��������ļ�ʽ��ȡ
status ReadJudge(FILE *pread, BiTree &Tread);
int main() {
	BiTree T = nullptr; int op = 1;
	int i = 0, judge = 0;		//�˴���judgeΪ�ж��Ƿ���ڶ������ı���
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
		printf("    ��ѡ����Ĳ���[0~20]:");
		scanf("%d", &op);
		printf("*********************************************************\n");
		switch (op) {
		case 1:
			if (judge == 1) {
				int intBiTree;
				printf("�������Ѵ��ڣ��Ƿ�������д˲�����\n1-��  0-��\n");
				scanf("%d", &intBiTree);
				if (intBiTree) {
					if (InitBiTree(T))printf("�����������ɹ���\n");
					else printf("����������ʧ�ܣ�\n");
					judge = 1;
					break;
				}
				else break;
			}
			else {
				if (InitBiTree(T))printf("�����������ɹ���\n");
				else printf("����������ʧ�ܣ�\n");
				judge = 1;
				break;
			}
		case 2:
			if (judge) {
				judge = 0;
				if (DestroyBiTree(T))printf("���������ٳɹ���\n");
				else printf("����������ʧ�ܣ�\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 3:
			if (judge) {
				printf("������������ĳ�ʼ���ݣ���ǰ�������˳�����벢���пռ��������롰0�� ����Ϊ�ռ�����\n");
				if (CreateBiTree(T))printf("����������ʱ��������ӳɹ���\n");
				else printf("����������ʱ���������ʧ�ܣ�\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 4:
			if (judge) {
				if (ClearBiTree(T))printf("��������ճɹ���\n");
				else printf("���������ʧ�ܣ�\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 5:
			if (judge) {
				if (BiTreeEmpty(T)) printf("�˶������ǿ�����\n");
				else printf("�˶��������ǿ�����\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 6:
			if (judge) {
				printf("�˶����������Ϊ%d\n", BiTreeDepth(T));
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 7:
			if (judge) {
				BiTree use1 = Root(T);
				if (use1) printf("�˶������ĸ��ڵ��������Ϊ%d%c.\n", use1->alldata.key, use1->alldata.data);
				else printf("�˶��������ڵ��ô���\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 8:
			if (judge) {
				TElemType e1;
				printf("������ڵ�e��key���ֵ��\n");
				scanf("%d", &e1.key);
				Value(T, e1);
				if (!e1.key) {
					printf("�˽ڵ��data���ֵΪ��%c.\n", e1.data);
				}
				else printf("�ڵ�eΪ����ڵ㣡\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 9:
			if (judge) {
				TElemType e2;
				printf("������Ҫ���Ľڵ��key��ֵ�Լ����ĺ��data��ֵ��\n");
				scanf("%d%c", &e2.key, &e2.data);
				Assign(T, e2);
				if (!e2.key) {
					printf("�ڵ���ĳɹ���\n");
				}
				else printf("�ڵ����ʧ�ܣ�\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 10:
			if (judge) {
				BiTree use3;
				TElemType e3;
				printf("��������ҪѰ��˫�׽ڵ�Ľڵ�e��key��data��ֵ��\n");
				scanf("%d%c", &e3.key, &e3.data);
				if (use3 = Parent(T, e3)) {
					printf("e��˫�׽ڵ�ĵ�ַΪ%p��key��ֵΪ%d��data��ֵΪ%c��\n", use3, use3->alldata.key, use3->alldata.data);
				}
				else printf("�����������\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 11:
			if (judge) {
				BiTree use4;
				TElemType e4;
				printf("��������ҪѰ�����ӽڵ�Ľڵ�e��key��data��ֵ��\n");
				scanf("%d%c", &e4.key, &e4.data);
				if (use4 = LeftChild(T, e4)) {
					printf("e�����ӽڵ�ĵ�ַΪ%p��key��ֵΪ%d��data��ֵΪ%c��\n", use4, use4->alldata.key, use4->alldata.data);
				}
				else printf("e�Ǵ˶������Ľڵ��e�����ӣ������������\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 12:
			if (judge) {
				BiTree use5;
				TElemType e5;
				printf("��������ҪѰ���Һ��ӽڵ�Ľڵ�e��key��data��ֵ��\n");
				scanf("%d%c", &e5.key, &e5.data);
				if (use5 = RightChild(T, e5)) {
					printf("e���Һ��ӽڵ�ĵ�ַΪ%p��key��ֵΪ%d��data��ֵΪ%c��\n", use5, use5->alldata.key, use5->alldata.data);
				}
				else printf("e�Ǵ˶������Ľڵ��e���Һ��ӣ������������\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 13:
			if (judge) {
				BiTree use6;
				TElemType e6;
				printf("��������ҪѰ�����ֵܽڵ�Ľڵ�e��key��data��ֵ��\n");
				scanf("%d%c", &e6.key, &e6.data);
				if (use6 = LeftSibing(T, e6)) {
					printf("e�����ֵܽڵ�ĵ�ַΪ%p��key��ֵΪ%d��data��ֵΪ%c��\n", use6, use6->alldata.key, use6->alldata.data);
				}
				else printf("e�Ǵ˶������Ľڵ��e�����ֵܣ������������\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 14:
			if (judge) {
				BiTree use7;
				TElemType e7;
				printf("��������ҪѰ�����ֵܽڵ�Ľڵ�e��key��data��ֵ��\n");
				scanf("%d%c", &e7.key, &e7.data);
				if (use7 = RightSibing(T, e7)) {
					printf("e�����ֵܽڵ�ĵ�ַΪ%p��key��ֵΪ%d��data��ֵΪ%c��\n", use7, use7->alldata.key, use7->alldata.data);
				}
				else printf("e�Ǵ˶������Ľڵ��e�����ֵܣ������������\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 15:
			if (judge) {
				BiTree c;
				TElemType p;
				int LR;
				printf("��������Ҫ������c�Ľڵ�p��key��data��ֵ��\n");
				scanf("%d%c", &p.key, &p.data);
				printf("��������Ҫ������p������������������0-������ 1-������\n");
				scanf("%d", &LR);
				if (InsertChild(T, p, LR, c)) {
					printf("������c����ɹ���\n");
				}
				else printf("�������������\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 16:
			if (judge) {
				TElemType p;
				int LR;
				printf("��������Ҫɾ�������Ľڵ�p��key��data��ֵ��\n");
				scanf("%d%c", &p.key, &p.data);
				printf("��������Ҫɾ��p������������������0-������ 1-������\n");
				scanf("%d", &LR);
				if (DeleteChild(T, p, LR)) {
					printf("����ɾ���ɹ���\n");
				}
				else printf("����ɾ��ʧ�ܣ�\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 17:
			if (judge) {
				if (PreOrderTraverse(T)) {
					printf("��������Ϊ�˶�������ǰ�����С�\n");
				}
				else printf("�˶�����Ϊ�����������������\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 18:
			if (judge) {
				if (InOrderTraverse(T)) {
					printf("��������Ϊ�˶��������������С�\n");
				}
				else printf("�˶�����Ϊ�����������������\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 19:
			if (judge) {
				if (PostOrderTraverse(T)) {
					printf("��������Ϊ�˶������ĺ������С�\n");
				}
				else printf("�˶�����Ϊ�����������������\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 20:
			if (judge) {
				if (LevelOrderTraverse(T)) {
					printf("\n����Ϊ�˶������Ĳ������С�\n");
				}
				else printf("�˶�����Ϊ�����������������\n");
			}
			else printf("�����ڶ��������˲����޷����У��봴��һ����������\n");
			break;
		case 0:
			printf("��ӭ�´��ٴ�ʹ�ñ�ϵͳ��\n");
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


status InitBiTree(BiTree &T) {						//��ʼ��������
	if (!(T = (BiTree)malloc(sizeof(BiTNode))))exit(OVERFLOW);
	T->lchild = NULL;
	T->rchild = NULL;
	return OK;
}				
status DestroyBiTree(BiTree &T) {					//ʵ�����ٶ�����
	BiTree p;
	p = T->lchild;
	Destroy(p);
	free(T);
	T = NULL;
	return OK;
}
status Destroy(BiTree &p) {							//ʵ�����ٶ������ĵݹ�ѭ��
	if (p) {
		if (p->lchild)Destroy(p->lchild);
		if (p->rchild)Destroy(p->rchild);
		free(p);
		p = NULL;
		return OK;
	}
	else return ERROR;
}	
status CreateBiTree(BiTree &T) {					//ʵ�ִ���������
	BiTree p;
	if(!(p= (BiTree)malloc(sizeof(BiTNode))))exit(OVERFLOW);
	if (Create(p)) {
		T->lchild = p;
		return OK;
	}
	else return ERROR;

}
status  Create(BiTree &p) {							//ʵ�ִ������������ڲ��ݹ�ѭ��
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
status ClearBiTree(BiTree &T) {						//��ն�����
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
status BiTreeEmpty(BiTree T) {					    //�ж϶������Ƿ�Ϊ����
	if (T && !T->lchild&&!T->rchild)return OK;
	else return ERROR;
}
status BiTreeDepth(BiTree T) {						//��������õ������������
	BiTree p;
	int depth;
	p = T->lchild;
	return (depth = Depth(p));
}
status Depth(BiTree p) {						   //���õĵõ���ȵĵݹ�ѭ��
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
status Value(BiTree T, TElemType &e) {		//eΪ��������ĳ���ڵ㣬����������Ӧ��ֵ
	if (T) {
		if (T->alldata.key == e.key) {
			e.data = T->alldata.data;
			e.key = 0;		//�����ж�ȡֵ�����������У����ڲ���־
			return OK;
		}
		Value(T->lchild, e);
		Value(T->rchild, e);	
	}
	else return ERROR;
}
status Assign(BiTree T, TElemType &e/*, TElemType value*/) {		//���������е�e�ڵ�ı�ֵ
	if (T) {
		if (T->alldata.key == e.key) {
			T->alldata.data = e.data;
			e.key = 0;	//�����жϸ�ֵ�����������У���Ϊ�ڲ���־
			return OK;
		}
		Assign(T->lchild, e);
		Assign(T->rchild, e);
	}
	else return ERROR;
}
BiTree Parent(BiTree T, TElemType e) {	//Ѱ��ָ���ڵ��˫�׽ڵ�
	BiTree p,x;
	x = nullptr;
	p = T->lchild;
	ParentJudge(T, p, x, e);
	if (!x) {
		printf("�˽ڵ�Ƕ�������㣡");
	}
	if (x == T) {
		printf("�˽ڵ�Ϊ�������ĸ��ڵ㣡");
		x = nullptr;
	}
	return x;
}
status ParentJudge(BiTree p, BiTree q,BiTree &x, TElemType e) {		//����Ѱ��˫�׽ڵ�ĵݹ�ѭ��
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
BiTree LeftChild(BiTree T, TElemType e) {		//Ѱ��ָ���ڵ�����ӽڵ�
	BiTree p, x;
	p = T->lchild;
	x = nullptr;
	LeftChildJudge(p, x, e);
	return x;
}
status LeftChildJudge(BiTree p, BiTree &x, TElemType e) {	//����Ѱ�����ӽڵ�ĵݹ�ѭ��
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
BiTree RightChild(BiTree T, TElemType e) {		//Ѱ��ָ���ڵ���Һ��ӽڵ�
	BiTree p, x;
	p = T->lchild;
	x = nullptr;
	RightChildJudge(p, x, e);
	return x;
}
status RightChildJudge(BiTree p, BiTree &x, TElemType e) {		//����Ѱ���Һ��ӽڵ�ĵݹ�ѭ��
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
BiTree LeftSibing(BiTree T, TElemType e) {		//Ѱ��ָ���ڵ�����ֵ�
	BiTree p, x;
	p = T->lchild;
	x = nullptr;
	LeftSibingJudge( p, x, e);
	return x;
}
status LeftSibingJudge( BiTree p, BiTree &x, TElemType e) {		//����Ѱ�����ֵܵĵݹ�ѭ��
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
BiTree RightSibing(BiTree T, TElemType e) {			//Ѱ��ָ���ڵ�����ֵܽڵ�
	BiTree p, x;
	p = T->lchild;
	x = nullptr;
	RightSibingJudge(p, x, e);
	return x;
}
status RightSibingJudge(BiTree p, BiTree &x, TElemType e) {		//����Ѱ�����ֵܵĵݹ�ѭ��
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

status InsertChild(BiTree &T, TElemType p, int LR, BiTree &c) {				//Ϊ��������������
	if (!(c = (BiTree)malloc(sizeof(BiTNode))))exit(OVERFLOW);
	BiTree x = nullptr;
	Find(T->lchild, x, p);
	if (!x) {
		printf("�ڵ�p���ݴ���\n");
		return ERROR;
	}
	printf("��������Ҫ��������������Ķ�����c:\n");
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
		printf("����Ķ�����c���������ǿգ����ݴ���\n");
		return ERROR;
	}
}
status DeleteChild(BiTree &T, TElemType p, int LR) {			//Ϊ������ɾ������
	BiTree x = nullptr;
	Find(T->lchild, x, p);
	if (!x) {
		printf("�ڵ�p���ݴ���\n");
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
status PreOrderTraverse(BiTree T) {					//ʵ�ֶ�������ǰ�����
	BiTree p;
	p = T->lchild;
	if (PreOrderTraverseJudge(p)) {
		putchar('\n');
		return OK;
	}
	else return ERROR;
}
status PreOrderTraverseJudge(BiTree p) {			//ʵ�ֶ�������ǰ������ĵݹ�ѭ��
	if (p) {
		printf("%d%c ", p->alldata.key, p->alldata.data);
		PreOrderTraverseJudge(p->lchild);
		PreOrderTraverseJudge(p->rchild);
		return OK;
	}
	else return ERROR;
}
status InOrderTraverse(BiTree T) {					//ʵ�ֶ��������������
	BiTree p;
	p = T->lchild;
	if (InOrderTraverseJudge(p)) {
		putchar('\n');
		return OK;
	}
	else return ERROR;
}
status InOrderTraverseJudge(BiTree p) {				//ʵ�ֶ���������������ĵݹ�ѭ��
	if (p) {
		InOrderTraverseJudge(p->lchild);
		printf("%d%c ", p->alldata.key, p->alldata.data);
		InOrderTraverseJudge(p->rchild);
		return OK;
	}
	else return ERROR;
}
status PostOrderTraverse(BiTree T) {				//ʵ�ֶ������ĺ������
	BiTree p;
	p = T->lchild;
	if (PostOrderTraverseJudge(p)) {
		putchar('\n');
		return OK;
	}
	else return ERROR;
}
status PostOrderTraverseJudge(BiTree p) {			///ʵ�ֶ������ĺ�������ĵݹ�ѭ��
	if (p) {
		PostOrderTraverseJudge(p->lchild);
		PostOrderTraverseJudge(p->rchild);
		printf("%d%c ", p->alldata.key, p->alldata.data);
		return OK;
	}
	else return ERROR;
}
status LevelOrderTraverse(BiTree T) {				//ʵ�ֶ������Ĳ������
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


status Find(BiTree T, BiTree &x, TElemType p) {				//�ж�ĳ�ڵ��Ƿ�Ϊ�������Ľڵ㣬���������ֵַ
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
status InitQueue(LinkQueue &Q) {					//��������
	QueuePtr p;
	if (!(p = (QueuePtr)malloc(sizeof(QNode))))exit(OVERFLOW);
	Q.front = p;
	Q.rear = p;
	Q.front->next = NULL;
	return OK;
}
status QueueEmpty(LinkQueue Q) {					//�ж϶����Ƿ�Ϊ��
	if (Q.front == Q.rear)return TRUE;
	else return ERROR;
}
status EnQueue(LinkQueue &Q, BiTree num) {			//�����
	QueuePtr p;
	if (!(p = (QueuePtr)malloc(sizeof(QNode))))exit(OVERFLOW);
	p->sTree = num;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
status DeQueue(LinkQueue &Q, BiTree &num) {			//������
	QueuePtr p;
	if (Q.front == Q.rear)return ERROR;
	p = Q.front->next;
	num = p->sTree;
	Q.front->next = p->next;
	if (Q.rear == p)Q.rear = Q.front;
	free(p);
	return OK;

}
status BiTreeRead(BiTree &T) {						//ʵ�ֶ��������ļ�ʽ��ȡ
	FILE *pread; BiTree Tread;
	if (!(pread = fopen("BiTreeDat.txt", "rb"))) {
		printf("���ݼ���ʧ�ܻ����ݲ����ڣ�");
		return FALSE;
	}
	if (!(Tread = (BiTree)malloc(sizeof(BiTNode))))exit(OVERFLOW);
	InitBiTree(T);
	ReadJudge(pread, Tread);
	T->lchild = Tread;
	fclose(pread);
	return OK;
}
status ReadJudge(FILE *pread, BiTree &Tread) {			//ʵ�ֶ�ȡ�ĵݹ�ѭ��
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
status BiTreeSave(BiTree &T) {						//ʵ�ֶ��������ļ�ʽ����
	FILE *psave; BiTree Tsave;
	if (!(psave = fopen("BiTreeDat.txt", "wb")))return FALSE;
	Tsave = T;
	SaveJudge(psave, Tsave->lchild);
	fclose(psave);
	return OK;
}
status SaveJudge(FILE *psave, BiTree Tsave) {			//ʵ�ִ���ĵݹ�ѭ��
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