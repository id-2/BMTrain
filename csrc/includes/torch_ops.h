#pragma once
#include <torch/extension.h>
#include <ATen/cuda/CUDAContext.h>

#define CHECK_CUDA(x) AT_ASSERTM(x.is_cuda(), #x " must be a CUDA tensor")
#define CHECK_CONTIGUOUS(x) AT_ASSERTM(x.is_contiguous(), #x " must be contiguous")
#define CHECK_INPUT(x) CHECK_CUDA(x); CHECK_CONTIGUOUS(x)

torch::Tensor bmm(const torch::Tensor &A, bool aT, const torch::Tensor &B, bool bT);
torch::Tensor round(const torch::Tensor &x, bool transpose, const torch::Tensor &scale);
torch::Tensor calc_scale(const torch::Tensor &x, bool transpose);
torch::Tensor scale(const torch::Tensor &x, const torch::Tensor &scale_1, const torch::Tensor &scale_2);

torch::Tensor layernorm_forward (const torch::Tensor& x, bool rd_mean, float eps);
torch::Tensor layernorm_backward(const torch::Tensor& x, const torch::Tensor& grad_, bool rd_mean, float eps);

torch::Tensor position_bucket(int32_t query_len, int32_t key_len, int32_t num_buckets, int32_t max_distance, bool bidirectional);

torch::Tensor softmax_forward(const torch::Tensor& x);
torch::Tensor softmax_backward(const torch::Tensor& out, const torch::Tensor& grad_);