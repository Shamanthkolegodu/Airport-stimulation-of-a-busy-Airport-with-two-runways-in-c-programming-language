typedef struct queue 
{
  int plane;
  struct queue *next;
}plane_queue;


void Init_simulation(int *, double *, double *);
void new_plane(plane_queue **, plane_queue **, int);
int del_plane(plane_queue **, plane_queue **);
int count(plane_queue **);
int randoms(double);