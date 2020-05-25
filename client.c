#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include"server.h"
#define MAX 5

int main()
{
  int simulation_time, plane_no=1;
  double probability_takeoff, probability_landing;
  int rand_landings, rand_takeoffs;
  Init_simulation(&simulation_time, &probability_takeoff, &probability_landing);
  plane_queue *land_front = NULL;
  plane_queue *land_rear = NULL;
  plane_queue *takeoff_front = NULL;
  plane_queue *takeoff_rear = NULL;

  for(int T=1; T<=simulation_time; T++)
  {
    rand_takeoffs = randoms(probability_takeoff);
    for(int planes = 0; planes < rand_takeoffs ; planes++)
    {
      printf("plane %d is ready to takeoff\n", plane_no);

      if((count(&takeoff_front)) <= MAX)
        new_plane(&takeoff_front, &takeoff_rear, plane_no);
      else
      {
        printf("plane %d is told to wait", plane_no);
        new_plane(&takeoff_front, &takeoff_rear, plane_no);
      }
      plane_no ++;
    }
    rand_landings = randoms(probability_landing);
    for(int planes = 0; planes < rand_landings; planes++)
    {
      printf("plane %d is ready to land\n", plane_no);
      new_plane(&land_front, &land_rear, plane_no);
      plane_no++;
    }
    if((count(&land_front)> MAX))
    {
      printf("\n%d\n", T);
      printf("plane %d landed using runway 1\n",del_plane(&land_front, &land_rear));
      printf("plane %d landed using runway 2\n",del_plane(&land_front, &land_rear));
    }
    else if((count(&land_front)<= MAX && count(&land_front) > 0) && (count(&takeoff_front) > 0))
    {
      printf("\n%d\n", T);
      printf("plane %d took off using runway 2\n",del_plane(&takeoff_front, &takeoff_rear));
      printf("plane %d landed using runway 1\n",del_plane(&land_front, &land_rear));
    }
    else if(count(&land_front) > 1 && count(&takeoff_front)==0)
    {
      printf("\n%d\n", T);
      printf("plane %d landed using runway 1\n",del_plane(&land_front, &land_rear));
      printf("plane %d landed using runway 2\n",del_plane(&land_front, &land_rear));   
    }
    else if(count(&takeoff_front) > 1 && count(&land_front)==0)
    {
      printf("\n%d\n", T);
      printf("plane %d took off using runway 1\n",del_plane(&takeoff_front, &takeoff_rear));
      printf("plane %d took off using runway 2\n",del_plane(&takeoff_front, &takeoff_rear));
    }
    else if(count(&takeoff_front) ==1 && count(&land_front)==0)
    {
      printf("\n%d\n", T);
      printf("plane %d took off using runway 2\n",del_plane(&takeoff_front, &takeoff_rear));

    }
    else if(count(&land_front) ==1 && count(&takeoff_front)==0)
    {
      printf("\n%d\n", T);
      printf("plane %d landed using runway 1\n",del_plane(&land_front, &land_rear));

    }
    else
    {
      printf("\n%d\n", T);
      printf("Runways are idle\n");

    }

  }
  return 0;
}




