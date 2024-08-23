#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
	struct node * prev;
};

struct node * head = NULL;

int insert_last(int);
int insert_first(int);
int insert_kth(int, int);

int delete_first();
int delete_last();
int delete_kth();

int display();

void main(){

    int val, i;
	for(i = 0; i<10; i++){
		val = i*10;
		insert_last(val);
	}

	insert_last(999);
    insert_first(89);
    insert_kth(78,11);
    display();
    delete_first();
    delete_last();
    delete_kth(2);
	display();

}

int display(){
	
	if(head == NULL){
		printf("The linked list is empty");
        return 0;
	}
	else{
		printf("The elements in the linked list are: \n");
		struct node * temp = head;
        do {
            printf("prev: %p, %d @ %p , next: %p", temp->prev, temp->data, temp, temp->next);
            temp = temp->next;
            if (temp != head){
                printf(" -> \n");
            }
        }while(temp != head);
        printf("\nhead : %p", temp);
        printf("\n");
        return 0;
	}
}

int insert_last(int val){
    struct node * newnode = (struct node *) malloc (sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    
    if (head == NULL){
        head = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    else{

        struct node * temp = head;
		while (temp->next != head){
			temp = temp->next;
		}
        temp->next = newnode;
        newnode->prev = temp;
        head->prev = newnode;
    }
    return 0;
}

int insert_first(int val){
    // newnode creation
    struct node * newnode = (struct node *) malloc (sizeof(struct node));
    
    
    if (head == NULL){
        head = newnode;
        newnode->data = val;
        newnode->next = head;
        newnode->prev = head;
    }
    else{
        newnode->data = head->data;
        newnode->next = head->next;
        newnode->prev = head;
        head->data = val;
        head->next = newnode;
        newnode->next->prev = newnode;
    }
}

int insert_kth(int val, int pos){
    struct node * newnode = (struct node *) malloc (sizeof(struct node));

    if (head == NULL){
        head = newnode;
        newnode->data = val;
        newnode->next = head;
        newnode->prev = head;
    }
    else if(pos == 0){
        newnode->data = head->data;
        newnode->next = head->next;
        newnode->prev = head;
        head->data = val;
        head->next = newnode;
        newnode->next->prev = newnode;
    }
    else{
        struct node * temp = head;
        int k = 0;
        do{
            temp = temp->next;
            k++;
        }while(k != pos);

        newnode->data = temp->data;
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->data = val;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
    return 0;
}

int delete_first(){
    if (head == NULL){
        printf("The LL is empty");
    }
    else if (head->next == head){
        free(head);
        head = NULL;
    }
    else{
        struct node * temp = head;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        head = temp->next;
        free(temp);
    }
    return 0;
}

int delete_last(){
    if (head == NULL){
        printf("The LL is empty");
    }
    else if (head->next == head){
        free(head);
        head = NULL;
    }    
    else{
        struct node * temp = head;
        while(temp->next->next != head){
            temp = temp->next;
        }
        struct node * temp1 = temp->next;
        temp1->prev->next = head; 
        head->prev = temp1->prev;
        free(temp1);
        return 0;
    }
}

int delete_kth(int pos){
    if (head == NULL){
        printf("The LL is empty");
    }
    else if (head->next == head){
        if (pos == 0){
            free(head);
            head = NULL;
        }
        else{
            printf("\n Can't delete \n");
        }
    }    
    else{
        struct node * temp = head;
        int k = 0;
        while((temp->next->next != head) && (k != pos-1)){
            temp = temp->next;
            k++;
        }
        if (k == pos-1){
            struct node * temp1 = temp->next;
            temp1->prev->next = temp1->next; 
            temp1->next->prev = temp1->prev;
            free(temp1);
        }
        return 0;
    }
}
