#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include"server.h"
#define MAX 5

void Init_simulation(int *simulation_time, double *probability_takeoff, double *probability_landing)
{
  printf("How many units of time will the simulation run?");
  scanf("%d", simulation_time);
  printf("Expected number of arrivals per unit time: ");
  scanf("%lf",probability_landing);
  printf("Expected number of departures per unit time: ");
  scanf("%lf",probability_takeoff);
}

int randoms(double expect)
{
  int n=0;
  float x = rand()/(double)RAND_MAX;
  while(x >exp(-(expect*2)))
  {
    n++;
    x *= rand()/(double)RAND_MAX;
  }
  return n;
}

void new_plane(plane_queue **front, plane_queue **rear, int x)
{
  plane_queue *temp =(plane_queue *)malloc(sizeof(plane_queue));
  temp->plane = x;
  temp->next = NULL;

  if(*front == NULL && *rear == NULL)
  {
    *front = temp;
    *rear = temp;
  }
  else{
    (*rear)->next = temp;
    *rear = temp;
  }
}


int del_plane(plane_queue **front, plane_queue **rear)
{
  plane_queue *temp = (plane_queue *)malloc(sizeof(plane_queue));

  if(*front == *rear)
  {
    temp = *front;
    *front = NULL;
    *rear = NULL;
    return temp->plane;

  }
  else
  {
    temp = *front;
    *front = (*front)-> next;
    return temp->plane;

  }
}

int count(plane_queue **front)
{
  int count = 0;
  plane_queue *temp = (plane_queue *)malloc(sizeof(plane_queue));
  temp = *front;
  while(temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  return count;
}
