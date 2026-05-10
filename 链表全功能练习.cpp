#include<stdio.h>
#include<stdlib.h>

//定义单链表节点
typedef struct list{
	int data;
	struct list* next; 
}Node, *List; 

//初始化链表
void InitList(List* L){
	*L=(List)malloc(sizeof(Node));
	(*L)->next=NULL;
	return; 
}

//创建链表，添加元素
int createList(List L){
	List p=L;
	int x;
	printf("请输入数据，输入零结束创建：\n");
	while(1){
		scanf("%d",&x);
		if(x==0){
			return 0;	
		}
		List r=(List)malloc(sizeof(Node));
		r->data=x;
		r->next=NULL;
		p->next=r;
		p=r;
	}
	return 0;	
} 
//打印链表的元素
int printList(List L){
	List p=L;
	if(p->next==NULL){
		printf("不好意思啦，链表是空的，没有元素在里面哦！\n");
		return 0;
	}
	p=p->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	return 0;
}

//插入元素
int insertList(List *L,int i,int e){
	List p=*L;
	int j=1;
	while(p!=NULL&&j<i){
		p=p->next;
		j++;
	}
	 if (p == NULL) return 0;
	List r=(List)malloc(sizeof(Node));
	r->data=e;
	r->next=p->next;
	p->next=r;
	return 0;	
} 

//指定位置删除
int ListDelete(List L, int i, int *e) {
    Node *p = L;
    int j = 1;
    while (p != NULL && j < i   ) {
        p = p->next;
        j++;
    }
    if (p == NULL|| p->next == NULL) return 0;
    List q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return 1;
}

//按序号查找元素
int numList(List L, int i,int *e){
	List p=L->next;
	int j=1;
	while(p!=NULL&&j<i){
	 p = p->next;
        j++;	
	}
	if (p == NULL) return 0;
	*e=p->data;
	return 1;
} 
 
//按值查找链表元素
int getList(List L,int e){
	List p=L->next;
	int j=1;
	while(p!=NULL){
		if(p->data==e){
			return j;
		}
		p=p->next;
		j++;
	}
	return 0;
} 

//直接改链表里面的值
int monifyList(List L,int i,int e){
	List p=L->next;
	int j=1;
	while(p!=NULL&&j<i){
		p=p->next;
		j++;
	}
	 if (p == NULL) return 0;
	 p->data=e;
	 return 1;
} 

//链表翻转功能的实现
int reverseList(List L){
	List pre=NULL;
	List cur=L->next;
	List nex=NULL;
	if(L->next==NULL) return 0;
	while(cur!=NULL){
		nex=cur->next;
		cur->next=pre;
		pre=cur;
		cur=nex;	
	}
	L->next=pre;
	return 1; 
} 

//链表插入升序排序
int sortedList1(List L){
	//判断这里面有没有至少两个元素 
	 if(L->next == NULL || L->next->next == NULL){
        return 0;
    }
    //将数据变成两份 
	List sorted=L->next;
	List unsorted=sorted->next;
	 sorted->next=NULL;
	while(unsorted!=NULL){
		//后移遍历 ，p链接的是这里面的第二个数据点，牵住链表 
		List p=unsorted;
		unsorted=unsorted->next;
		//另外起变量进行遍历 
		List pre=L;
		while(pre->next!=NULL&&pre->next->data<p->data){
			pre=pre->next;
		}
		p->next=pre->next;
		pre->next=p;
	}
	return 1; 
} 

// 链表插入降序排序
int sortedList2(List L){
	//判断这里面有没有至少两个元素 
	 if(L->next == NULL || L->next->next == NULL){
        return 0;
    }
    //将数据变成两份 
	List sorted=L->next;
	List unsorted=sorted->next;
	 sorted->next=NULL;
	while(unsorted!=NULL){
		//后移遍历 ，p链接的是这里面的第二个数据点，牵住链表 
		List p=unsorted;
		unsorted=unsorted->next;
		//另外起变量进行遍历 
		List pre=L;
		while(pre->next!=NULL&&pre->next->data>p->data){
			pre=pre->next;
		}
		p->next=pre->next;
		pre->next=p;
	}
	return 1;
} 

//链表的去重处理
int removeList(List L){
	if(L->next==NULL||L->next->next==NULL) return 0;
	List p=L->next;
	while(p!=NULL){
		List r=L;
		while(r->next != NULL&&r->next->data!=p->data){
			r=r->next;
		}
	if(r->next!=p&&r->next!=NULL){
		List q=r->next;
		r->next=q->next;
		free(q);
	}
	p=p->next;	
	}
	return 1;	
} 

//销毁整个链表
int destoryList(List *L){
	List q,p;
	p=(*L)->next;
	while(p!=NULL){
		q=p;
		p=p->next; 
		free(q);
	}
	(*L)->next=NULL;
	return 1;
} 

//链表长度查询
int quaryList(List L){
	List p=L;
//	if(L->next==NULL){
//		printf("链表长度为零哦！\n");
//		return 0;
//	}
	int j=0;
	while(p->next!=NULL){
		p=p->next;
		j++;
	} 
	return j;
} 

int main() {
	List L;
	InitList(&L);
	int choice;
	 while (1) {
        printf("\n===== 单链表菜单（无限运行）=====\n");
        printf("1. 创建链表（输入0结束本次创建）\n");
        printf("2. 打印链表\n");
        printf("3. 插入元素\n");
        printf("4. 删除元素\n");
        printf("5. 按序号查找\n");
        printf("6. 按值查找\n");
        printf("7. 直接改值\n");
        printf("8. 链表翻转\n");
        printf("9. 链表插入升序排序\n");
        printf("10. 链表结果去重(无序去重)\n");
        printf("11. 链表结果去重(有序去重)\n");
        printf("12. 链表插入降序排序\n");
        printf("13. 销毁链表\n");
        printf("14. 链表长度查询\n");
        printf("0. 退出程序\n");
        printf("请输入操作：");
        scanf("%d", &choice);
        if(choice==0){
        	printf("退出成功！\n");
			return 1;	
		} 
        int e,i,pos;
        switch (choice) {
        	case 1:
        		createList(L);
        		break;
        	case 2:
        		printList(L);
        		break;
        	case 3:
        		{
        			
				}
        		printf("请说出你要插入的位置和元素：");
        		 scanf("%d%d", &i, &e);
        		insertList(&L,i,e);
        		break;
        	case 4:
//        		 if(L->next==NULL) {
//    					printf("链表为空！没办法删除哦！"); 
//				}
        		printf("请说出你要删除的位置：");
        		scanf("%d",&i);
//				ListDelete(L,i,&e);
				  if (ListDelete(L, i, &e)) {
                    printf("删除的值：%d\n", e);
                } else {
                    printf("删除失败，位置无效！\n");
                }
                break;
        	case 5:
			printf("请说出你要查找的序号：");
			scanf("%d",&i);
//			numList(L,i,&e);
//			printf("该序号值为%d",e);
//			break;
 				if (numList(L, i, &e)) {
                    printf("值为：%d\n", e);
                } else {
                    printf("查找失败，位置无效！\n");
                }
                break;
            case 6:
			printf("请说出你想要查询的值："); 
			scanf("%d",&e);
			pos = getList(L, e);
                if (pos != 0) {
                    printf("位置：%d\n", pos);
                } else {
                    printf("未找到该值！\n");
                }
                break;
            case 7:
            	printf("请输入你要改的位置和值：");
				scanf("%d",&i);
				scanf("%d",&e);
				if(monifyList(L,i,e)){
					printf("改值成功。\n");
					break;
				}
				printf("改值失败。\n");
				break;
			case 8:
				printf("链表翻转功能如下：\n");
				reverseList(L);
				{
				List p=L->next;
				while(p!=NULL){
					printf("%d ",p->data);
					p=p->next;
				}
			}
				break;
			case 9:
				sortedList1(L);
				printf("链表排序升序顺序如下：\n");
				{
					List p=L->next;
					while(p!=NULL){
						printf("%d ",p->data);
						p=p->next;
					}
				}
				break;
			case 10:
				printf("链表去重结果如下(无序去重)：\n");
				 if(removeList(L)){
				 	{
				 		List g=L->next;
				 		while(g!=NULL){
				 			printf("%d ",g->data);
				 			g=g->next;
						 }
						 printf("去重成功！\n");
					 }
				 } else {
				 	 printf("去重失败！");
				 }
				break;
			case 11:
			 	printf("链表去重结果如下(有序去重)：\n");
			 	sortedList1(L); 
				 if(removeList(L)){
				 	{
				 		List g=L->next;
				 		while(g!=NULL){
				 			printf("%d ",g->data);
				 			g=g->next;
						 }
						 printf("有序去重成功！\n");
					 }
				 } else {
				 	 printf("去重失败！");
				 }
				break;
			case 12:
				sortedList2(L);
				printf("链表降序排序顺序如下：\n");
				{
					List p=L->next;
					while(p!=NULL){
						printf("%d ",p->data);
						p=p->next;
					}
				}
				break;
			case 13:
				destoryList(&L);
				printf("链表销毁成功！\n"); 
				break;
			case 14:
				{
					int pos=quaryList(L);
					printf("链表长度为%d ",pos);
				 } 
				 break;
				default:
                printf("输入错误！请重新选择。\n");		
		}
	}
	return 1;
}
