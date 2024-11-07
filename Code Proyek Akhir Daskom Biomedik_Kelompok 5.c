/* FINAL PROJECT SYSTEM RESERVATION CINEMA'S TICKET
   B.V.J. - 2006xxxxxx
   Fatimah Kayla Kameela - 2006xxxxxx
   A.S.K. - 2006xxxxxx
   A.L.P. -  2006xxxxxx */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nama[255];
	char tlp[15];
	char buy[6];
	int data;
	int total;
	int total1;
	int total2;
	int book_id;
	int price;
	int number;
	int fg;
}movie;

typedef struct{
	char pilfilm[255];
	int seat[100];
	char time[10];
	int hall;
	int l;
	int ag;
}film;

typedef struct {
	char food[255];
	int harga[100];
}move;

void header();
void awal();
void login();
void menu();
void data();
void schedule();
void choice();
void seat(char chair[], int a);
void ticket();
void bayar();
void reserved();
void etiket();
void items();
void fcho();
void food();
void bought();
void receipt();
void download();
void red();

int kl, item[100], nf;
movie cinema;
move cinem[100];
film fil;

int main(){
	fil.ag=0;
	login();
	menu();
}

void header(){
	printf("\t\t=============================================\n");
	printf("\t\t          ||   CINCO's CINEMA   ||\n");
	printf("\t\t=============================================\n\n");
}

void awal(){
	printf("\n\n\tFinal Project Dasar Komputer dan Praktikum\n");
	sleep(1);
	printf("\n\t              Kelompok 5\n");
	printf("\n\t  Brigitta Vanessa Jolly     2006521925\n"
           "\t  Fatimah Kayla Kameela      2006525305\n"
           "\t  Adila Shofa Kamila         2006532102\n"
           "\t  Anzelya Laurentzya Putri   2006529354");
	sleep(3);
	system("cls");
}

//username dan password merupakan case sensitive
void login(){
	char username[3]= "xxi", pass[3]= "xxi";
	char user[3], passlog[3];
	int attempt, failed=3, i, j;
	awal();
	header();
	while(attempt!=1){
		printf("\nUsername: ");
		scanf("%s", &user);
		printf("Password: ");
		for(i=0;i<3;i++){
			passlog[i] = getch();
			printf("*");
		}
		printf("\n");
		if(strcmp(username, user)==0 && strcmp(pass, passlog)==0){
			printf("\nLogin successful\n\n");
			attempt=1;
			break;
		}else{
			failed--;
			if(failed==0){
				printf("\nLogin attempt unavailable. Please try again in");
				for(j=5;j>0;j--){
					printf(" %d", j);
					sleep(1);
				}
				system("cls");
				failed=3;
				header();
			}else{
				printf("\nUsername/password is incorrect. Please try again.");
			}
		}
	}
	red();
}

//menu yang digunakan user untuk memilih setelah login
void menu(){
	int pilmenu;
	while(pilmenu!=0){
		system("cls");
		header();
		printf("CINCO's CINEMA MENU\n1. Buy Ticket\n2. Reserved E-ticket\n3. Payment\n4. Receipt\n5. Food & Beverages\n0. Logout\n\nSelect Menu: ");
		scanf("%d", &pilmenu);
		switch(pilmenu){
			case 1:
				system("cls");
				header();
				data();
				schedule();
				continue;
			case 2:
				system("cls");
				header();
				reserved();
				continue;
			case 3:
				bayar();
				continue;
			case 4:
				system("cls");
				header();
				receipt();
				continue;
			case 5:
				system("cls");
				food();
				continue;
			case 0:
				system("cls");
				printf("You have logged out");
				break;
			default:
				printf("\nMenu choices unavailable. Please choose again.\n\n");
				continue;
		}
	}
}

//menu untuk menampilkan nomor booking id
void data(){
	system("cls");
	header();
	if(cinema.data==1){
		printf("Your data:\n\n");
		printf("Name         : %s\n", cinema.nama);
		printf("Phone Number : %s\n", cinema.tlp);
		printf("Booking ID   : %d\n\n", cinema.book_id);
		cinema.data=1;
	}else{
		printf("Please fill in your data:\n\n");
		printf("Full Name           : ");
		scanf(" %[^\n]%*c", &cinema.nama);
		printf("Phone Number        : ");
		scanf("%s", &cinema.tlp);
		cinema.book_id = rand()%9999999+1000000;
		printf("Your Booking Number : %d \n\n", cinema.book_id);
		cinema.data=1;
	}
	system("pause");
}

//menu untuk memilih film yang akan ditonton
void schedule(){
	int rbk;
	system("cls");
	header();
	nf=0;
	while(nf<1||nf>4){
		printf("Available Movie:"
		"\n1. The Lion King\n\t12:45-13:35"
		"\n2. Pocahontas\n\t13:30-16:30"
		"\n3. The Little Mermaid\n\t15:00-16:30"
		"\n4. Hercules\n\t16:00-17:35\n");
		printf("Select Menu: ");
		scanf("%d", &nf);
		if(nf==1){
			if(fil.l==1){
				printf("\nYou have already booked a seat on a film. Would you like to rebook? (1 for yes): ");
				scanf("%d", &rbk);
				if(rbk==1){
					if(cinema.fg==2){
						printf("\nYou have paid for the ticket. Rebook is prohibited\n");
						red();
					}else{
						fil.l=0;
					}
				}else{
					red();
				}
			}if(fil.l==0){
				strcpy(fil.pilfilm, "The Lion King");
				strcpy(fil.time, "12:45"); 
				fil.hall = 1;
				choice();
				fil.l=1;
			}
		}else if(nf==2){
			if(fil.l==1){
				printf("\nYou have already booked a seat on a film. Would you like to rebook? (1 for yes): ");
				scanf("%d", &rbk);
				if(rbk==1){
					if(cinema.fg==2){
						printf("\nYou have paid for the ticket. Rebook is prohibited");
						red();
					}else{
						fil.l=0;
					}
				}else{
					red();
				}
			}if(fil.l==0){
				strcpy(fil.pilfilm, "Pocahontas");
				strcpy(fil.time, "13:30");
				fil.hall = 2;
				choice();
				fil.l=1;
			}
		}else if(nf==3){
			if(fil.l==1){
				printf("\nYou have already booked a seat on a film. Would you like to rebook? (1 for yes): ");
				scanf("%d", &rbk);
				if(rbk==1){
					if(cinema.fg==2){
						printf("\nYou have paid for the ticket. Rebook is prohibited");
						red();
					}else{
						fil.l=0;
					}
				}else{
					red();
				}
			}if(fil.l==0){
				strcpy(fil.pilfilm, "The Little Mermaid");
				strcpy(fil.time, "15:00");
				fil.hall = 3;
				choice();
				fil.l=1;
			}
		}else if(nf==4){
			if(fil.l==1){
				printf("\nYou have already booked a seat on a film. Would you like to rebook? (1 for yes): ");
				scanf("%d", &rbk);
				if(rbk==1){
					if(cinema.fg==2){
						printf("\nYou have paid for the ticket. Rebook is prohibited");
						red();
					}else{
						fil.l=0;
					}
				}else{
					red();
				}
			}if(fil.l==0){
				strcpy(fil.pilfilm, "Hercules");
				strcpy(fil.time, "16:00");
				fil.hall = 4;
				choice();
				fil.l=1;
			}
		}else if(nf<1||nf>4){
			printf("\nThis film is unavailable. Please select again.\n");
			sleep(1);
		}
		printf("\n");
		system("cls");
		header();
	}
}

//menu untuk memilih nomor tempat duduk
void choice(){
	int i, j=0, number=0, a=0;
	char chair[100];
	system("pause");
	seat(chair, a);
	while(number>100||number<1){
		printf("Enter the number of ticket you want to buy (maximal 100 Ticket): ");
		scanf("%d", &number);
		if(number>100||number<1){
			printf("\nThe ticket you want to buy is over/under the limit. Please input the total ticket again.\n\n");
		}
		cinema.number = number;
	}
	for(i=0;i<cinema.number;i++){
		printf("\nSeat Number Ticket %d: ", j+1);
		scanf("%d", &fil.seat[i]);
		while(fil.seat[i]<1||fil.seat[i]>100){
			if(fil.seat[i]<1||fil.seat[i]>100){
				printf("\nThe seat number unavailable. Please try again.\n");
				printf("\nSeat Number Ticket %d: ", j++);
				scanf("%d", &fil.seat[i]);
			}
		}
		j++;
		chair[fil.seat[i]-1]= 0;
		a=1;
	}
	sleep(2);
	seat(chair, a);
	system("pause");
	ticket();
}

//menu untuk menampilkan nomor tempat duduk yang dipilih oleh user
void seat(char chair[], int a){
	int i;
	system("cls");
	header();
	printf("Film Name: %s\n", fil.pilfilm);
	printf("\n\t\t\t\tSCREEN\n\n");
	for(i=1;i<=100;i++){
		if(a==0){
			chair[i-1]=i;
		}if(chair[i-1]==0){
			printf("*\t");
		}else{
			printf("%d\t", chair[i-1]);
		}
		if(i%10==0){
			printf("\n\n");
		}
	}
}

//menu untuk menampilkan ringkasan tiket sebelum dibayar
void ticket(){
	int total, i, lanjut;
	system("cls");
	header();
	cinema.price = 50000;
	cinema.total1 = cinema.number*cinema.price;
	printf("\t\tReceipt Ticket\n\n");
	printf("Booking ID\t: %d", cinema.book_id);
	printf("\nName\t\t: %s", cinema.nama);
	printf("\nPhone Number\t: %s", cinema.tlp);
	printf("\nFilm Name\t: %s", fil.pilfilm);
	printf("\nTotal Price\t: Rp. %d\n", cinema.total1);
	printf("\nProceed to payment? (type 1 to continue or type 0 to undo the ticket reservation): ");
	scanf("%d", &lanjut);
	switch(lanjut){
		case 1:
			cinema.fg=1;
			bayar();
			break;
		case 0:
			red();
			break;
		default:
			cinema.fg=1;
			system("cls");
			header();
			printf("The ticket has been booked. Please go to payment to complete the ticket reservation.\n\n");
			red();
			break;
	}
}

//menu untuk memilih metode pembayaran tiket
void bayar(){
	int pay, i, j, lnjt, payt;
	system("cls");
	header();
	if(cinema.fg==1||fil.ag==1){
		printf("\n\nWould you like to pay? (1 if yes): ");
		scanf("%d", &lnjt);
		if(lnjt==1){
			while(payt<1||payt>3){
				printf("\nPayment Menu:\n1. Ticket Payment\n2. Food & Beverages Payment\n3. Both\n\nPayment: ");
				scanf("%d", &payt);
				if(payt==1){
					if(cinema.fg!=1){
						printf("\nThere are no Cinema ticket payment in waiting. Please choose another menu.\n");
						payt=0;
					}else{
						cinema.fg=2;
					}
				}else if(payt==2){	
					if(fil.ag!=1){
						printf("\nThere are no Food & Beverages payment in waiting. Please choose another menu.\n");
						payt=0;
					}else{
						fil.ag=2;
					}
				}else if(payt==3){
					if(cinema.fg!=1||fil.ag!=1){
						printf("\nThere are no Cinema ticket/Food & Beverages payment in waiting. Please choose another menu.\n");
						payt=0;
					}else{
						cinema.fg=2;
						fil.ag=2;
					}
				}else if(payt<1||payt>3){
					printf("\nPayment menu unavailable.Please choose again.\n");
				}
				sleep(1);
				system("cls");
				header();
			}
			printf("\nPayment Methode:\n1. GoPay\n2. OVO\n3. Mastercard\n4. Debitcard\n\nPayment Method:");
			scanf("%d", &pay);
			while(pay<1||pay>4){
				if(pay<1||pay>4){
					printf("\nThe payment method unavailable. Please try again.\n");
				}
				printf("\nPayment method: ");
				scanf("%d", &pay);
			}
			if(pay==1||pay==2){
				system("cls");
				header();
				printf("\nQR Code\n");
				printf("\t\t@@@@@@@@@@@@@@@@@@@@@\n\t\t"
					   "@ @@@@ @ @ @ @ @@@@ @\n\t\t"
					   "@ @  @ @ @ @ @ @  @ @\n\t\t"
					   "@ @@@@ @@@@@@@ @@@@ @\n\t\t"
					   "@  @@  @  @@  @  @@ @\n\t\t"
					   "@ @  @@  @  @@  @  @@\n\t\t"
					   "@@  @  @   @ @@ @@  @\n\t\t"
					   "@@@@@@@@@@@@@@@@@@@@@\n");
				printf("\nUse the QR Code above to pay the ticket.\n\n");
				system("pause");
			}else if(pay==3||pay==4){
				system("cls");
				header();
				printf("\nVirtual Account Number: %d", rand()%999999999+100000000);
				printf("\n\nUse the virtual account number above to pay the ticket.\n\n");
				system("pause");
			}
			system("cls");
			for(i=0;i<3;i++){
				header();
				printf("Transaction is loading");
				for(j=0;j<3;j++){
					printf(".");
					sleep(1);
				}
				sleep(4/5);
				system("cls");
			}
			header();
			printf("\nTransaction successful!\n\nBack to the menu for the receipt.\n\n");
			red();
		}else{
			printf("\n");
			red();
		}	
	}else{
		printf("\n\n\tThere are no payment in waiting.\n\n\n");
		system("pause");
	}
}


//menu untuk menampilkan ringkasan tiket yang telah dibeli untuk ditukarkan
void reserved(){
	int i;
	if(cinema.fg==0){
		printf("\n\n\tThere are no booking history.\n\n\n");
		system("pause");
	}else if(cinema.fg==1){
		strcpy(cinema.buy, "Unpaid");
		etiket();
		system("pause");
	}else{
		strcpy(cinema.buy, "Paid");
		etiket();
		printf("\nDownload E-Ticket? (type 1 for continue) : ");
		download();
	}
}

void etiket(){
	int i;
	for(i=0;i<cinema.number;i++){
	printf("\t----------------------CINCO's cinema BOOKING TICKET----------------\n");
	printf("\t=================================================================\n");
    printf("\t Booking ID : %d \t\t\tShow Name : %s\n", cinema.book_id, fil.pilfilm);
    printf("\t Customer   : %s\n",cinema.nama);
    printf("\t                                              Time      : %s pm\n", fil.time);
    printf("\t                                              Hall      : %d\n", fil.hall);
    printf("\t                                              Seats No. : %d\n",fil.seat[i]);
    printf("\t                                              Price     : Rp. %d\n\n",cinema.price);
    printf("\t Status     : %s\n", cinema.buy);
    printf("\t=================================================================\n");
    printf("\n");
	}
	cinema.data=1;
}

void items(){
	printf("\n\t================================================================\n");
    printf("\t   |                    FOOD & BEVERAGES                    |\n");
	printf("\t================================================================\n");
    printf("\t   |      Item Code     |  Food & Beverage   |   Price (Rp) |\n");
	printf("\t================================================================\n");
    printf("\t   |         1          | Sistagor           |    25000     |\n");
    printf("\t   |         2          | Burger             |    55000     |\n");
    printf("\t   |         3          | Mini Pangsit Goreng|    50000     |\n");
    printf("\t   |         4          | Roti Sosis Ayam    |    25000     |\n");
    printf("\t   |         5          | Fish and Chips     |    60000     |\n");
    printf("\t   |         6          | Popcorn Large      |    100000    |\n");
    printf("\t   |         7          | Java Tea           |    25000     |\n");
    printf("\t   |         8          | Ice Lychee Tea     |    45000     |\n");
    printf("\t   |         9          | Milo Dinosaurus    |    35000     |\n");
    printf("\t   |         10         | Soft Drink         |    20000     |\n");
    printf("\t================================================================\n\n");
}

void food(){
	int i;
	if(fil.ag==0){
		fcho();
	}else if(fil.ag==1||fil.ag==2){
		header();
		printf("\nYou have already buy food/beverages. Would you like to change your order? (1 for yes): ");
		scanf("%d", &i);
		if(i==1){
			if(fil.ag==2){
				printf("\nYou have already paid. Re-order is prohibited\n");
				red();
			}else{
				system("cls");
				kl=0;
				fcho();
			}
		}else{
			red();
		}
	}
}

void fcho(){
	int beli, beli2, lnjt;
	header();
	items();
	cinema.total2=0;
	printf("\nWould you like to buy something?(1 if yes): ");
	scanf("%d", &beli);
	if(beli==1){
		printf("\nItem code: ");
		scanf("%d", &item[kl]);
		while(item[kl]<1||item[kl]>10){
			if(item[kl]<1||item[kl]>10){
				printf("\nItem not available. Please choose another.\n");
				printf("\nItem code: ");
				scanf("%d", &item[kl]);
			}
		}
		kl++;
		printf("\nWould you like to buy another item?(0 if no): ");
		scanf("%d", &beli2);
		while(beli2!=0){
			printf("\nItem code: ");
			scanf("%d", &item[kl]);
			while(item[kl]<1||item[kl]>10){
				if(item[kl]<1||item[kl]>10){
					printf("\nItem not available. Please choose another.\n");
					printf("\nItem code: ");
					scanf("%d", &item[kl]);
				}
			}
			kl++;
			printf("\nWould you like to buy another item?(0 if no): ");
			scanf("%d", &beli2);
		}
		data();
		system("cls");
		header();
		printf("\n\t================================================================\n");
	    printf("\t   |           Ordered List of Food and Beverages           |\n");
		printf("\t================================================================\n");
	    bought();
		printf("\t================================================================\n\n");
		printf("\nProceed to payment? (type 1 for continue or type 0 to undo the Food & Beverages order): ");
		scanf("%d", &lnjt);
		if(lnjt==1){
			fil.ag=1;
			bayar();
		}else if(lnjt==0){
			red();
		}else{
			fil.ag=1;
		}
	}else{
		red();
	}
}

void bought(){
	int i;
    for(i=0;i<kl;i++){
    	if(item[i]==1){
    		strcpy(cinem[i].food, "Sistagor           ");
			cinem[i].harga[i]=25000;
		}else if(item[i]==2){
			strcpy(cinem[i].food, "Burger             ");
			cinem[i].harga[i]=55000;
		}else if(item[i]==3){
			strcpy(cinem[i].food, "Mini Pangsit Goreng");
			cinem[i].harga[i]=50000;
		}else if(item[i]==4){
			strcpy(cinem[i].food, "Roti Sosis Ayam    ");
			cinem[i].harga[i]=25000;
		}else if(item[i]==5){
			strcpy(cinem[i].food, "Fish and Chips     ");
			cinem[i].harga[i]=60000;
		}else if(item[i]==6){
			strcpy(cinem[i].food, "Popcorn Large      ");
			cinem[i].harga[i]=100000;
		}else if(item[i]==7){
			strcpy(cinem[i].food, "Java Tea           ");
			cinem[i].harga[i]=25000;
		}else if(item[i]==8){
			strcpy(cinem[i].food, "Ice Lychee Tea     ");
			cinem[i].harga[i]=45000;
		}else if(item[i]==9){
			strcpy(cinem[i].food, "Milo Dinosaurus    ");
			cinem[i].harga[i]=35000;
		}else if(item[i]==10){
			strcpy(cinem[i].food, "Soft Drink         ");
			cinem[i].harga[i]=20000;
		}
		printf("\t      %d. %s\t@%d\n", i+1, cinem[i].food, cinem[i].harga[i]);
		cinema.total2+=cinem[i].harga[i];
	}
	printf("\n\t     Total Food Price       :Rp. %d\n", cinema.total2);
}

//menu untuk menampilkan ringkasan tiket yang telah dibeli untuk dijadikan arsip
void receipt(){
	int i, resi, x=0, y=0, z=0, ya;
	if(cinema.fg==2||fil.ag==2){
		printf("See receipt? (1 for yes): ");
		scanf("%d", &ya);
		if(ya==1){
			while(resi<1||resi>3){
				printf("\nReceipt Menu: \n1. Cinema Ticket\n2. Food & Beverages\n3. Both\nReceipt: ");
				scanf("%d", &resi);
				if(resi==1){
					if(cinema.fg!=2){
						printf("\nThere are no receipt of Cinema Ticket. Please choose another menu.\n");
						resi=0;
					}else{
						x=1;
					}
				}else if(resi==2){
					if(fil.ag!=2){
						printf("\nThere are no receipt of Food & Beverages. Please choose another menu.\n");
						resi=0;
					}else{
						y=1;
					}
				}else if(resi==3){
					if(fil.ag!=2||cinema.fg!=2){
						printf("\nThere are incomplete receipt. Please choose another menu.\n");
						resi=0;
					}else{
						x = 1;
						y = 1;
						z = 1;
					}
				}else if(resi<1||resi>3){
					printf("\nReceipt menu unavailable.Please choose again.\n");
				}
				sleep(2);
				system("cls");
				header();
			}if(x==1||y==1||z==1){
				printf("\t     -----------------RECEIPT TICKET----------------\n");
				printf("\t    =================================================\n");
				printf("\t     Name                   : %s\n", cinema.nama);
				printf("\t     Phone Number           : %s\n", cinema.tlp);
				printf("\t     Booking ID             : %d\n", cinema.book_id);
				if(x==1){
					printf("\t     Number of Ticket       : %d\n", cinema.number);
					printf("\t     Ticket Price           : Rp. %d\n", cinema.price);
					printf("\t     Total Ticket Price     : Rp. %d\n", cinema.total1);
				}if(y==1){
					printf("\t     Food Payment : ");
					for(i=1;i<=kl;i++){
						printf("\n\t         %d. %s", i, cinem[i-1].food);
						printf("\n\t\t\t\t\t   @%d", cinem[i-1].harga[i-1]);
					}
					printf("\n\t     Total Food Price       : Rp. %d\n", cinema.total2);
				}if(z==1){
					cinema.total=cinema.total1+cinema.total2;
					printf("\t     Total Payment          : Rp. %d\n", cinema.total);
				}
				printf("\t    =================================================\n");
				printf("\nDownload receipt? (type 1 for continue) : ");
				download();	
			}
		}else{
			printf("\n");
			red();
		}
	}else{
		printf("\n\n\tThere are no payment history.\n\n\n");
		system("pause");
	}
}

//menu untuk mengunduh tiket
void download(){
	int unduh, i, j;
	scanf("%d", &unduh);
	if(unduh==1){
		system("cls");
		for(i=0;i<2;i++){
			header();
			printf("Downloading");
			for(j=0;j<3;j++){
				printf(".");
				sleep(1);
			}
			sleep(1);
			system("cls");
		}
		header();
		printf("Download successful!\n\n");
	}else{
		printf("\n");
	}
	red();
}

void red(){
	printf("\nRedirecting to Menu...");
	sleep(2);
}
