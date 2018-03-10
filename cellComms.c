#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


void print_cells(uint8_t *cells, uint8_t cell_count)
{
  int i;
  for( i = 0; i < cell_count; i++)
  {
    printf("%d", cells[i]);
    if(i < (cell_count - 1))
    {
      printf(",");
    }
  }
  printf("\n");
}

int cell_comms(uint8_t *cells, uint8_t cell_count, uint8_t step_count)
{
  uint8_t step, cell;
  uint8_t *next_step[2];
  
  if((cells == NULL) || (cell_count == 0))
  {
    return -1;
  }

  if(step_count == 0)
  {
    return step_count;
  }

  next_step[0] = (uint8_t*)malloc(sizeof(uint8_t) * cell_count);
  next_step[1] = (uint8_t*)malloc(sizeof(uint8_t) * cell_count);
  
  memcpy(next_step[0], cells, cell_count);
  
  for (step = 0; step < step_count; step++)
  {
    for (cell = 0; cell < cell_count; cell++)
    {
      uint8_t right_neighbor = cell == 0 ? cell_count - 1 : cell - 1;
      uint8_t left_neighbor = cell == cell_count - 1 ? 0 : cell + 1;

      if(next_step[step%2][right_neighbor] == next_step[step%2][left_neighbor])
      {
        next_step[(step + 1)%2][cell] = 0;
      }
      else
      {
        next_step[(step + 1)%2][cell] = 1;
      }
    }

    if(step < step_count - 1)
    {
      print_cells(next_step[(step + 1)%2], cell_count);
    }
  }
  
  memcpy(cells, next_step[step%2], cell_count);

  free(next_step[0]);
  free(next_step[1]);

  return 0;
}

int main(int argc, char *argv[])
{
  /*** Input data ***/
  uint8_t cells[] = { 1, 0, 1, 1};
  uint8_t k = 2;
  /******************/

  uint8_t cell_count = sizeof(cells)/sizeof(cells[0]);
  
  print_cells(cells, cell_count);

  cell_comms(cells, cell_count, k);

  print_cells(cells, cell_count);
  return 0;
}
