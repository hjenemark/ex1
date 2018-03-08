#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_LENGTH 0xFF

uint8_t* rmNdub(uint8_t *input, uint8_t n, uint8_t input_length, uint8_t output[], uint8_t *output_length)
{
  uint8_t temp[MAX_LENGTH] = { 0 };
  uint8_t i = 0;

  if(input == NULL)
  {
    return NULL;
  }

  if(n >= MAX_LENGTH)
  {
    return NULL;
  }
  
  if(output == NULL)
  {
    output = (uint8_t*)malloc(sizeof(uint8_t) * MAX_LENGTH);
  }
  
  *output_length = 0;
  for(i = 0; i < input_length; i++)
  {
    if(++temp[input[i]] >= n)
    {
      continue;
    }
    else
    {
      output[*output_length] =  input[i];
      *output_length += 1;
    }
      
  }
  return output;
}

int main(int argc, char *argv[])
{
  uint8_t n = 3;
  uint8_t array[] = {1, 2, 2, 3, 5, 2, 4, 5, 5, 2};
  
  uint8_t *output_array = NULL;
  uint8_t output_length = 0;
  uint8_t i, array_length;

  array_length = sizeof(array)/sizeof(array[0]);

  printf("Input:\t");
  for(i = 0; i < array_length; i++)
  {
    printf("%d, ", array[i]);
  }
  printf("\n");
  
  output_array = rmNdub(array, n, array_length, output_array, &output_length);

  if(output_array == NULL)
  {
    printf("Something went wrong... \n");
    return 0;
  }
  printf("Output:\t");
  for(i = 0; i < output_length; i++)
  {
    printf("%d, ", output_array[i]);
  }
  printf("\n");

  if(output_array != NULL)
  {
    free(output_array);
  }
  return 0;
}
