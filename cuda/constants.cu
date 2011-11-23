#include "cuda_utils.h"

__device__ __constant__ int elements;

int main() {
  int elems = 1;
  CUDA_SAFE_CALL(cudaMemcpyToSymbol("elements", &elems, sizeof(int)));
}
