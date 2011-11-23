__global__ void vec_add(float *a, float *b, float *c, int N) {
  int idx = threadIdx.x;
  if (idx < N) {
    c[idx] = a[idx]+b[idx];
  }
}

