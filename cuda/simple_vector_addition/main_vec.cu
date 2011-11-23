#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define NUM_ELEMS 10

/**
  This function will add the vectors a and b together and save it into N
  */
extern __global__ void vec_add(float *a, float *b, float *c, int n);

int main() {
  // cuda specific configs
  int blocksize = NUM_ELEMS;
  int numblocks = 1;

  // declaring variables
  float *a,*b,*c;
  a = (float*)malloc(sizeof(float)*NUM_ELEMS);
  b = (float*)malloc(sizeof(float)*NUM_ELEMS);
  c = (float*)calloc(sizeof(float),NUM_ELEMS);


  // fill variables with data
  for (int i=0;i<NUM_ELEMS;i++) {
    a[i] = (float) i;
    b[i] = ((float) NUM_ELEMS-i);
  }

  // allocate device memory
  float *d_a, *d_b, *d_c;  
  cudaMalloc((void**)&d_a,sizeof(float)*NUM_ELEMS);
  cudaMalloc((void**)&d_b,sizeof(float)*NUM_ELEMS);
  cudaMalloc((void**)&d_c,sizeof(float)*NUM_ELEMS);

  // copy data from host to device
  cudaMemcpy(d_a,a,NUM_ELEMS*sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy(d_b,b,NUM_ELEMS*sizeof(float), cudaMemcpyHostToDevice);
  
  // launch kernel
  dim3 dimBlock(blocksize);
  dim3 dimGrid(numblocks);
  vec_add<<<dimGrid,dimBlock>>>(d_a,d_b,d_c,NUM_ELEMS);
  
  cudaThreadSynchronize();
  // copy data from device back to host
  cudaMemcpy(c,d_c,NUM_ELEMS*sizeof(float),cudaMemcpyDeviceToHost);

  // print everything
  printf("Finished, printing data\n");
  for (int i=0;i<NUM_ELEMS;i++) {
    printf("%f = %f + %f\n",c[i],a[i],b[i]);
  }

  return 0;
}
