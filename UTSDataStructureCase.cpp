#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 200
#define cls system("cls");
#define sign printf("=> ");

typedef struct{
	char name[max];
	char bday[max];
	int age;
	char address[max];
	int stat;
}patient;

typedef struct{
	int clinic;
	int doctorName;
	char dignose[max];
	char medicine[max];
	int clinicCost;
	int cost;
	char date[max];
}doctor;

int admin = 5000;

patient data1;
doctor data2;

struct node{
	patient data1;
	doctor data2;
	struct node *next;
};

struct node *front[9];
struct node *rear[9];

char clinicList[4][200] = {"Dental", "Pedriatic", "General", "Oculist"};
char doctorA[8][100] = {"[1] dr. Doni","[2] dr. Samuel","[3] dr. Ayu", "[4] dr. Tyas","[5] dr. Dina","[6] dr. Joni","[7] dr. Agung", "[8] dr. Rama"};
int q1,q2,q3,q4,q5,q6,q7,q8;

struct node *createNewNode(patient p, doctor d){
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data1 = p;
	newNode->data2 = d;
	newNode->next = NULL;
	return newNode;
}

void menu(){
	printf("HOSPITAL - MENU : \n");
	printf("[1] List of doctor\n");
	printf("[2] Registration\n");
	printf("[3] Clinic queue\n");
	printf("[4] Outpatient\n");
	printf("[5] Pharmacy queue\n");
	printf("[6] Drug taken\n");
	printf("[7] Payment\n");
	printf("[8] Exit\n");
	sign;
}

void doctorList(){
	int j;
	printf("Clinic [1] %s: \n", clinicList[0]);
	for(j = 0; j < 2; j++){
		printf("%s\n", doctorA[j]);
	}
	printf("\n");
	printf("Clinic [2] %s: \n", clinicList[1]);
	for(j = 2; j < 4; j++){
		printf("%s\n", doctorA[j]);
	}
	printf("\n");
	printf("Clinic [3] %s: \n", clinicList[j]);
	for(j = 4; j < 6; j++){
		printf("%s\n", doctorA[j]);
	}
	printf("\n");
	printf("Clinic [4] %s: \n", clinicList[3]);
	for(j = 6; j < 8; j++){
		printf("%s\n", doctorA[j]);
	}	
}

void enqueue(patient p, doctor d, int target){
	struct node *newNode = createNewNode(p , d);
	if(front[target]==NULL){
		front[target] = newNode;
		rear[target] = newNode;
	}else{
		rear[target]->next = newNode;
		rear[target] = newNode;
	}
}

void dequeue(int target){
	if(front[target]==NULL){
		return;
	}else if(front[target]==rear[target]){
		free(front[target]);
		front[target] = rear[target] = NULL;
	} else {
		struct node *temp = front[target]->next;
		front[target]->next = NULL;
		free(front[target]);
		front[target] = temp;
	}
}

void registration(){
	patient p;
	doctor d;
	printf("Name \t\t: ");
	scanf("%[^\n]", &p.name);
	getchar();
	printf("Date of Birth \t: ");
	scanf("%[^\n]", &p.bday);
	getchar();
	printf("Age \t\t: ");
	scanf("%d", &p.age);
	getchar();
	printf("Addres \t\t: ");
	scanf("%[^\n]", &p.address);
	getchar();
	printf("Status \t\t: \n");
	printf("[1] BPJS\n[2] INHEALTH\n[3] MANDIRI\n");
	scanf("%d", &p.stat);
	getchar();
	printf("Clinic \t\t: \n");
	printf("[1] Dental\n[2] Pedriatic\n[3] General\n[4] Oculist\n");
	sign;
	scanf("%d", &d.clinic);
	switch (d.clinic){
		case 1:
			for(int j = 0; j < 2; j++){
				printf("%s\n", doctorA[j]);
			}
			printf("Doctor : ");
			scanf("%d", &d.doctorName);
			sign;
			if(d.doctorName==1){
				q1+=1;
				printf("Queue Number : %d\n", q1);
				printf("Doctor Name : %s\n", doctorA[0]);
			}else{
				q2+=1;
				printf("Queue Number : %d\n", q2);
				printf("Doctor Name : %s\n", doctorA[1]);
			}
			enqueue(p,d,d.doctorName);
			break;
		case 2:
			for(int j = 2; j < 4; j++){
				printf("%s\n", doctorA[j]);
			}
			printf("Doctor : ");
			scanf("%d", &d.doctorName);
			sign;
			if(d.doctorName==3){
				q3+=1;
				printf("Queue Number : %d\n", q3);
				printf("Doctor Name : %s\n", doctorA[2]);
			}else{
				q4+=1;
				printf("Queue Number : %d\n", q4);
				printf("Doctor Name : %s\n", doctorA[3]);
			}
			enqueue(p,d,d.doctorName);
			break;
		case 3:
			for(int j = 4; j < 6; j++){
				printf("%s\n", doctorA[j]);
			}
			printf("Doctor : ");
			scanf("%d", &d.doctorName);
			sign;
			if(d.doctorName==5){
				q5+=1;
				printf("Queue Number : %d\n", q5);
				printf("Doctor Name : %s\n", doctorA[4]);
			}else{
				q6+=1;
				printf("Queue Number : %d\n", q6);
				printf("Doctor Name : %s\n", doctorA[5]);
			}
			enqueue(p,d,d.doctorName);
			break;
		case 4:
			for(int j = 6; j < 8; j++){
				printf("%s\n", doctorA[j]);
			}
			printf("Doctor : ");
			sign;
			scanf("%d", &d.doctorName);
			if(d.doctorName==7){
				q7+=1;
				printf("Queue Number : %d\n", q7);
				printf("Doctor Name : %s\n", doctorA[6]);
			}else{
				q8+=1;
				printf("Queue Number : %d\n", q8);
				printf("Doctor Name : %s\n", doctorA[7]);
			}
			enqueue(p,d,d.doctorName);
			break;
	}
	getchar();
}

void clinicQueue(){
	cls;
	int queue = 1;
	printf("Clinic : %s\n", clinicList[0]);
	struct node *q1 = front[1];
	printf("%s\n",doctorA[0]);
	if(q1==NULL){
		printf("Queue is Empty\n");
	}else{
		while(q1!=NULL){
		printf("%d. %s \n", queue, q1->data1.name);
		q1 = q1->next;
		queue+=1;
		}
	}
	printf("\n");
	
	struct node *q2 = front[2];
	printf("%s\n",doctorA[1]);
	if(q2==NULL){
		printf("Queue is Empty\n");
	}else{
		while(q2!=NULL){
		printf("%d. %s \n", queue, q2->data1.name);
		q2 = q2->next;
		queue+=1;
		}
	}
	printf("\n");
	printf("Clinic : %s\n", clinicList[1]);
	struct node *q3 = front[3];
	printf("%s\n",doctorA[2]);
	if(q3==NULL){
		printf("Queue is Empty\n");
	}else{
		while(q3!=NULL){
			printf("%d. %s \n", queue, q3->data1.name);
			q3 = q3->next;
			queue+=1;
		}
	}
	printf("\n");
	struct node *q4 = front[4];
	printf("%s\n",doctorA[3]);
	if(q4==NULL){
		printf("Queue is Empty\n");
	}else{
		while(q4!=NULL){
			printf("%d. %s \n", queue, q4->data1.name);
			q4 = q4->next;
			queue+=1;
		}
	}
	printf("\n");
	printf("Clinic : %s\n", clinicList[2]);
	struct node *q5 = front[5];
	printf("%s\n",doctorA[4]);
	if(q5==NULL){
		printf("Queue is Empty\n");
	}else{
		while(q5!=NULL){
			printf("%d. %s \n", queue, q5->data1.name);
			q5 = q5->next;
			queue+=1;
		}
	}
	printf("\n");
	struct node *q6 = front[6];
	printf("%s\n",doctorA[5]);
	if(q6==NULL){
		printf("Queue is Empty\n");
	}else{
		while(q6!=NULL){
			printf("%d. %s \n", queue, q6->data1.name);
			q6 = q6->next;
			queue+=1;
		}
	}	
	printf("\n");
	printf("Clinic : %s\n", clinicList[3]);
	struct node *q7 = front[7];
	printf("%s\n",doctorA[6]);
	if(q7==NULL){
		printf("Queue is Empty\n");
	}else{
		while(q7!=NULL){
			printf("%d. %s \n", queue, q7->data1.name);
			q7 = q7->next;
			queue+=1;
		}
	}
	printf("\n");
	struct node *q8 = front[8];
	printf("%s\n",doctorA[7]);
	if(q8==NULL){
		printf("Queue is Empty\n");
	}else{
		while(q8!=NULL){
			printf("%d. %s \n", queue, q8->data1.name);
			q8 = q8->next;
			queue+=1;
		}
	}
	printf("\n");
}

void outpatient(){
	cls;
	int count;
	patient p;
	doctor d;
	
	printf("Queue Number : "); 
	scanf("%d",&count);
	getchar();
	switch(count){
		case 1:
			if(front[count]){
				printf("Treatment Date : "); 
				scanf("%[^\n]", front[count]->data2.date); 
				getchar();
				printf("Diagnose : "); 
				scanf("%[^\n]", front[count]->data2.dignose);
				getchar();
				printf("Medicine : "); 
				scanf("%[^\n]", front[count]->data2.medicine); 
				getchar();
				printf("Cost : "); 
				scanf("%d", &front[count]->data2.cost); 
				getchar();
				enqueue(front[count]->data1, front[count]->data2,0);
				dequeue(count);
			}
			break;
		case 2:
			if(front[count]){
				printf("Treatment Date : "); 
				scanf("%[^\n]", front[count]->data2.date);
				getchar();
				printf("Diagnose : "); 
				scanf("%[^\n]", front[count]->data2.dignose);
				getchar();
				printf("Medicine : "); 
				scanf("%[^\n]", front[count]->data2.medicine);
				getchar();
				printf("Cost : "); 
				scanf("%d", &front[count]->data2.cost);
				getchar();
				enqueue(front[count]->data1, front[count]->data2,0);
				dequeue(count);
			}
			break;
		case 3:
			if(front[count]){
				printf("Treatment Date : "); 
				scanf("%[^\n]", front[count]->data2.date);
				getchar();
				printf("Diagnose : "); 
				scanf("%[^\n]", front[count]->data2.dignose);
				getchar();
				printf("Medicine : "); scanf("%[^\n]", front[count]->data2.medicine); getchar();
				printf("Cost : "); 
				scanf("%d", &front[count]->data2.cost);
				getchar();
				enqueue(front[count]->data1, front[count]->data2,0);
				dequeue(count);
			}
			break;
		case 4:
			if(front[count]){
				printf("Treatment Date : "); 
				scanf("%[^\n]", front[count]->data2.date);
				getchar();
				printf("Diagnose : "); 
				scanf("%[^\n]", front[count]->data2.dignose);
				getchar();
				printf("Medicine : "); 
				scanf("%[^\n]", front[count]->data2.medicine);
				getchar();
				printf("Cost : "); 
				scanf("%d", &front[count]->data2.cost);
				getchar();
				enqueue(front[count]->data1, front[count]->data2,0);
				dequeue(count);
			}
			break;
		case 5:
			if(front[count]){
				printf("Treatment Date : "); 
				scanf("%[^\n]", front[count]->data2.date);
				getchar();
				printf("Diagnose : "); 
				scanf("%[^\n]", front[count]->data2.dignose);
				getchar();
				printf("Medicine : "); 
				scanf("%[^\n]", front[count]->data2.medicine);
				getchar();
				printf("Cost : "); scanf("%d", &front[count]->data2.cost);
				getchar();
				enqueue(front[count]->data1, front[count]->data2,0);
				dequeue(count);
			}
			break;
		case 6:
			if(front[count]){
				printf("Treatment Date : "); 
				scanf("%[^\n]", front[count]->data2.date);
				getchar();
				printf("Diagnose : "); 
				scanf("%[^\n]", front[count]->data2.dignose);
				getchar();
				printf("Medicine : "); 
				scanf("%[^\n]", front[count]->data2.medicine);
				getchar();
				printf("Cost : "); 
				scanf("%d", &front[count]->data2.cost);
				getchar();
				enqueue(front[count]->data1, front[count]->data2,0);
				dequeue(count);
			}
			break;
		case 7:
			if(front[count]){
				printf("Treatment Date : "); 
				scanf("%[^\n]", front[count]->data2.date);
				getchar();
				printf("Diagnose : "); 
				scanf("%[^\n]", front[count]->data2.dignose);
				getchar();
				printf("Medicine : "); 
				scanf("%[^\n]", front[count]->data2.medicine);
				getchar();
				printf("Cost : "); 
				scanf("%d", &front[count]->data2.cost);
				getchar();
				enqueue(front[count]->data1, front[count]->data2,0);
				dequeue(count);
			}
			break;
		case 8:
			if(front[count]){
				printf("Treatment Date : "); 
				scanf("%[^\n]", front[count]->data2.date);
				getchar();
				printf("Diagnose \t: "); 
				scanf("%[^\n]", front[count]->data2.dignose);
				getchar();
				printf("Medicine \t: "); 
				scanf("%[^\n]", front[count]->data2.medicine);
				getchar();
				printf("Cost \t\t: "); 
				scanf("%d", &front[count]->data2.cost);
				getchar();
				enqueue(front[count]->data1, front[count]->data2,0);
				dequeue(count);
			}
			break;
	}	
}

void pharmacyQueue(){
	cls;
	int queue = 1;
	struct node *pharmacy = front[0];
	printf("Pharmacy queue : \n");
	if(pharmacy == NULL){
		printf("Pharmacy Queue is Empty\n");
	}else{
		while(pharmacy){
		printf("%d. %s\n", queue, pharmacy->data1.name);
		pharmacy = pharmacy->next;
		queue+=1;
		}
	}	
}

void drugTaken(){
	cls;
	struct node* curr = front[0];
	printf("Name \t: %s\n", curr->data1.name);
	printf("Medicine : %s\n", curr->data2.medicine);
	printf("Price \t: %d\n", curr->data2.cost);
	printf("Your medicine has been taken !\n");
	enqueue(curr->data1,curr->data2,9);
	dequeue(0);
}


void payment(){
    cls;
    struct node *curr = front[9];
    if(curr->data2.clinic==1){
		curr->data2.clinicCost = 50000 + 3500;
	} 
	if(curr->data2.clinic==2){
		curr->data2.clinicCost = 40000 + 2500;
	} 
	if(curr->data2.clinic==3){
		curr->data2.clinicCost = 30000 + 1500;
	} 
	if(curr->data2.clinic==4){
		curr->data2.clinicCost = 70000 + 2000;
	}
    
	FILE *fp = fopen("Recap.txt","a+");
    printf("Name \\tt: %s\n", curr->data1.name);
    printf("Admin fee \t: %d\n", admin);
    printf("Medicine fee \t: %d\n", curr->data2.cost);
    printf("Doctor fee \t: %d\n", curr->data2.clinicCost);
    printf("Total Payment : %lld\n", curr->data2.cost + curr->data2.clinicCost + admin);
    if(curr->data1.stat==1){
        printf("the costs are covered by insurance\n");
    }
	fprintf(fp, "\n-------------------------------------------------\n");
	fprintf(fp, "Database\n");
	fprintf(fp, "Name : %s\n", curr->data1.name);
	fprintf(fp, "Date of Birth : %s\n", curr->data1.bday);
	fprintf(fp, "Age : %d\n", curr->data1.age);
	fprintf(fp, "Address : %s\n", curr->data1.address);
	fprintf(fp, "Status : %d\n", curr->data1.stat);
	fprintf(fp, "Clinic : %d\n", curr->data2.clinic);
	fprintf(fp, "Doctor : %d\n", curr->data2.doctorName);
	fprintf(fp, "Treatment Date : %s\n", curr->data2.date);
	fprintf(fp, "Medicine : %s\n", curr->data2.medicine);
	fprintf(fp, "Diagnose : %s\n", curr->data2.dignose);
	fprintf(fp, "Payment : %d\n", curr->data2.cost + curr->data2.clinicCost + admin);
	fprintf(fp, "\n-------------------------------------------------\n");
	fclose(fp);
    dequeue(9);
}

int main(){
	int c;
	
	do{
		cls;
		menu();
		scanf("%d", &c);
		getchar();
		switch(c){
			case 1:
				cls;
				doctorList();
				system("pause");
				break;
			case 2:
				cls;
				registration();
				system("pause");
				break;
			case 3:
				cls;
				clinicQueue();
				system("pause");
				break;
			case 4:
				cls;
				outpatient();
				system("pause");
				break;
			case 5:
				cls;
				pharmacyQueue();
				system("pause");
				break;
			case 6:
				cls;
				drugTaken();
				system("pause");
				break;
			case 7:
				cls;
				payment();
				system("pause");
				break;
			case 8:
				cls;
				printf("Thank you\n");
				return 0;
		}
	}while(c != 8);
	
}

