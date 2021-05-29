
/*      Created By -

        MD. Samrat Hosssen
        gmail: nayakemily50@gmail.com

*/
#include<stdio.h>
#include<string.h>

/*********~~~~~~~~~~~~~STRUCTURES TO BE USED~~~~~~~~~~~************/

struct time
{
    int iHrs,iMins;

};

struct bus
{
    int iBusNum;
    int iBusCode;
    char chSeat[8][4][20];
    char chDrivers_Name[20];
    struct time stDeparture_Time, stArrival_Time;
    char chGoesTo[20];
    char chGoesFrom[20];
    float fFare;
    int iTicketSold;
};



char chEmpty[]="Empty";

static int iNumber=1;
char i=':';
struct bus stBus[40];


void fnNew_Bus();
void fnMainMenu();
void fnShowBuses();
void fnEmpty();
void fnSeatReservation();
void fnShowStatus();
void fnPrintLine();
void fnDailyReport();


void main()
{
    fnMainMenu();
}

/***************************************************************************
FUNCTION DEFINITIONS
***************************************************************************/


void fnMainMenu()
{
    int iChoice;
    printf("\n\n\t\t\t______________________");
    printf("\n\n\t\t\tBUS RESERVATION SYSTEM");
    printf("\n\n\t\t\t______________________\n");
    fnPrintLine();

    printf("\n\n\t\t1.Bus Installation");
    printf("\n\t\t2.Allotment");
    printf("\n\t\t3.Show details");
    printf("\n\t\t4.Status");
    printf("\n\t\t5.Daily Report");
    printf("\n\t\t6.Exit");
    printf("\n\n\n\tEnter your choice as(1/2/3/4/5):-\t");
    fflush(stdin);
    scanf("%d",&iChoice);

    switch(iChoice)
    {
    case 1 :
        fnNew_Bus();
        break;
    case 2:
        fnSeatReservation();
        break;

    case 3:
        fnShowBuses();
        break;
    case 4:
        fnShowStatus();
        break;
    case 5:
        fnDailyReport();
        break;
    case 6:
        exit(0);
    default:
        printf("\t\t\tU have entered Wrong Choice!!!!");
        getchar();
        fnMainMenu();


    }
}
void fnNew_Bus()

{

    char chChoice;
    printf("\n\n\t\tEnter Information about bus\n");
    do
    {
        fnPrintLine();
        printf("\n\n\t\t Bus No:\t%d",iNumber);
busC:
        printf("\n\n\tEnter Bus Code:\t");
        fflush(stdin);

        stBus[iNumber].iBusNum=iNumber;
        scanf("%d",&stBus[iNumber].iBusCode);
        if(stBus[iNumber].iBusCode<1||stBus[iNumber].iBusCode>9999)
        {
            printf("\n\t\tInvalid Bus Code!!!!");
            goto busC;
        }


dname:
        printf("\n\n\tEnter driver's name:\t");
        fflush(stdin);
        gets(stBus[iNumber].chDrivers_Name);

        if(strlen(stBus[iNumber].chDrivers_Name)>20)
        {
            printf("Maximum 20 characters are allowed");
            goto dname;
        }
artime:
        printf("\n\tEnter arrival time:\t");
        fflush(stdin);
        scanf("%d%c%d",&stBus[iNumber].stArrival_Time.iHrs,&i,&stBus[iNumber].stArrival_Time.iMins);

        if((i!=':')||(stBus[iNumber].stArrival_Time.iHrs>=24)||(stBus[iNumber].stArrival_Time.iHrs<0)||(stBus[iNumber].stArrival_Time.iMins>=60)||(stBus[iNumber].stArrival_Time.iMins<0))
        {
            printf("\n\t\tInvalid Time!!!!\n");
            printf("\t\tEnter only--hh:mm!!!!");
            goto artime;
        }
deptime:
        printf("\n\tEnter departure time:\t");
        fflush(stdin);
        scanf("%d%c%d",&stBus[iNumber].stDeparture_Time.iHrs,&i,&stBus[iNumber].stDeparture_Time.iMins);

        if((i!=':')||(stBus[iNumber].stDeparture_Time.iHrs>=24)||(stBus[iNumber].stDeparture_Time.iHrs<0)||(stBus[iNumber].stDeparture_Time.iMins>=60)||(stBus[iNumber].stDeparture_Time.iMins<0))
        {
            printf("\n\t\tInvalid Time!!!!");
            printf("\n\t\tEnter only--hh:mm");
            goto deptime;
        }
from:
        printf("\n\tFrom:\t");
        fflush(stdin);
        gets(stBus[iNumber].chGoesFrom);
        if(strlen(stBus[iNumber].chGoesFrom)>20)
        {
            printf("Maximum 20 characters are allowed");
            goto from;
        }

to:
        printf("\n\tTo:\t");
        fflush(stdin);
        gets(stBus[iNumber].chGoesTo);
        if(strlen(stBus[iNumber].chGoesTo)>20)
        {
            printf("Maximum 20 characters are allowed");
            goto to;
        }
        printf("\n\tFare:\t");
        fflush(stdin);
        scanf("%f",&stBus[iNumber].fFare);
        stBus[iNumber].iTicketSold=0;
        printf("\n");
        fnEmpty();
        fnPrintLine();


        printf("\n\n\n\tDo u want to continue to add information about new bus(y/n)?? ");
        fflush(stdin);
        scanf("%c",&chChoice);

        iNumber++;
    }
    while(chChoice=='y'||chChoice=='Y');
    fnMainMenu();

}


void fnShowBuses()
{
    int i1;
    printf("\n\n\t\t\t______________________");
    printf("\n\n\t\t\t BUSES AVALAIBLE");
    printf("\n\n\t\t\t______________________\n");

    for(i1=1; i1<iNumber; i1++)
    {
        printf("\n");
        fnPrintLine();
        printf("\n\t\tbus no-\t\t%d",stBus[i1].iBusNum);
        printf("\n\t\tbus code-\t%d",stBus[i1].iBusCode);
        printf("\n\t\tDrivers Name-\t%s",stBus[i1].chDrivers_Name);
        printf("\n\t\tFrom-\t\t%s",stBus[i1].chGoesFrom);
        printf("\n\t\tTo-\t\t%s",stBus[i1].chGoesTo);
        printf("\n\t\tArrival time-\t%d%c%d",stBus[i1].stArrival_Time.iHrs,i,stBus[i1].stArrival_Time.iMins);
        printf("\n\t\tDeparture time-\t%d%c%d",stBus[i1].stDeparture_Time.iHrs,i,stBus[i1].stDeparture_Time.iMins);
        printf("\n\t\tFare-\t\t%.4f",stBus[i1].fFare);
        printf("\n\t\tTickets Sold-\t%d",stBus[i1].iTicketSold);
        printf("\n");
        fnPrintLine();

    }

    getchar();

    fnMainMenu();
}

void fnSeatReservation()
{

    char chName[20];
    int iBusN;
    int iSeat;
    char chChoice;
    printf("\n\n\t\t\t______________________");
    printf("\n\n\t\t\t ALLOTMENT");
    printf("\n\n\t\t\t______________________\n");
    fnPrintLine();
    printf("\n\n\t\tEnter the Bus Number-\t");
    fflush(stdin);
    scanf("%d",&iBusN);
    if(iBusN>=iNumber)
    {
        printf("\n\t\t\tSorry Bus Doesn,t Exist!!!!");
        fnSeatReservation();
    }

seat:
    printf("\n\t\tEnter the Seat number-\t");
    fflush(stdin);
    scanf("%d",&iSeat);
    if(iSeat>32)
    {
        printf("\n\t\tSorry!! There r only 32 seats in the bus!!!!") ;
        goto seat;
    }
    else if(strcmp(stBus[iBusN].chSeat[iSeat/4][(iSeat%4)-1],"Empty")==0)
    {
        printf("\n\t\tEnter the passenger's name-\t");
name:
        fflush(stdin);
        gets(chName);
        if(strlen(chName)>20)
        {
            printf("\n\t\tplz enter only 20 characters!!!!");
            goto name;
        }
        else
        {
            strcpy(stBus[iBusN].chSeat[iSeat/4][iSeat%4-1],chName);
            printf("\n\t\tYour seat is reserved now!!");
            stBus[iBusN].iTicketSold++;
            printf("\n\t do u want to continue with reservation(y/n)??");
            fflush(stdin);
            chChoice=getchar();
            if(chChoice=='y'||chChoice=='Y')
                fnSeatReservation();
            else
                fnMainMenu();
        }


    }
    else
    {
        printf("\n\tThis seat is already reserved!!!!");
        printf("\n\t do u want to try again??");
        fflush(stdin);
        chChoice=getchar();
        if(chChoice=='y'||chChoice=='Y')
            fnSeatReservation();
        else
            fnMainMenu();
    }
}

void fnDailyReport()
{
    int i;
    double dDailyTotal=0;
    double dBusTotal=0;
    printf("\n\n\t\t\t______________________");
    printf("\n\n\t\t\t DAILY REPORT");
    printf("\n\n\t\t\t______________________\n");
    fnPrintLine();
    for(i=1; i<iNumber; i++)
    {
        dBusTotal=stBus[i].iTicketSold*stBus[i].fFare;
        printf("\n\t\tBus no-\t%d\t Total tickets Sold-\t%d",i,stBus[i].iTicketSold);
        printf("\n\t\t\tTotal Fare-\t%.4lf\n",dBusTotal);
        dDailyTotal+=dBusTotal;

    }
    printf("\n\n\t\t\tDaily Total=\t%lf",dDailyTotal);
    getchar();
    fnMainMenu();

}

void fnEmpty()
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<4; j++)
        {
            strcpy(stBus[iNumber].chSeat[i][j],chEmpty);
        }

    }
}


void fnShowStatus()
{
    int iBusN,index=0,j,k;
    char chChoice;
    printf("\n\n\t\tEnter Bus no.-\t");
    fflush(stdin);
    scanf("%d",&iBusN);
    if(iBusN>=iNumber)
    {
        printf("\n\t\tBus doesn't Exist!!!!");
        fnShowStatus();
    }
    else
    {
        fnPrintLine();
        printf("\nBus code-\t%d\t\tDriver's Name-\t%s",stBus[iBusN].iBusCode,stBus[iBusN].chDrivers_Name);
        printf("\nArrival Time-\t%d%c%d\t\tDeparture Time\t%d%c%d",stBus[iBusN].stArrival_Time.iHrs,i,stBus[iBusN].stArrival_Time.iMins,stBus[iBusN].stDeparture_Time.iHrs,i,stBus[iBusN].stDeparture_Time.iMins);
        printf("\nFrom-\t\t%s\t\tTo-\t\t%s",stBus[iBusN].chGoesFrom,stBus[iBusN].chGoesTo);
        printf("\nFare-\t\t%f\tTickets Sold-\t%d",stBus[iBusN].fFare,stBus[iBusN].iTicketSold);
        printf("\n");
        fnPrintLine();
        for(j=0; j<8; j++)
        {
            printf("\n");
            for(k=0; k<4; k++)
            {
                index++;
                printf("%d .%s\t",index,stBus[iBusN].chSeat[j][k]);
            }
        }
    }
    printf("\n\n\t\tDo u want to continue with another bus(y/n)??");
    fflush(stdin);
    chChoice=getchar();
    if(chChoice=='y'||chChoice=='Y')
        fnShowStatus();
    else
        fnMainMenu();
}


void fnPrintLine()
{
    int j;
    for(j=0; j<60; j++)
        printf("*");
}
