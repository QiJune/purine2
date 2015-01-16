// Copyright Lin Min 2015
#ifndef PURINE_ELTWISE
#define PURINE_ELTWISE

#include "operations/operation.hpp"

namespace purine {

/**
 * { ... } >> op >> { top }
 */
class Mul : public Operation {
 public:
  explicit Mul(const vector<Tensor*>& inputs, const vector<Tensor*>& outputs);
  virtual void compute_cpu(const vector<bool>& add);
  virtual void compute_gpu(const vector<bool>& add);
};

/**
 * { ... } >> op >> { top }
 */
class Sum : public Operation {
 public:
  explicit Sum(const vector<Tensor*>& inputs, const vector<Tensor*>& outputs);
  virtual void compute_cpu(const vector<bool>& add);
  virtual void compute_gpu(const vector<bool>& add);
};

/**
 * { ... } >> op >> { top }
 */
class WeightedSum : public Operation {
 protected:
  vector<DTYPE> weights;
 public:
  typedef tuple<vector<DTYPE> > param_tuple;
  explicit WeightedSum(const vector<Tensor*>& inputs,
      const vector<Tensor*>& outputs, const param_tuple& args);
  virtual void compute_cpu(const vector<bool>& add);
  virtual void compute_gpu(const vector<bool>& add);
};

/**
 * { ... } >> op >> { top }
 */
class Average : public Operation {
 public:
  explicit Average(const vector<Tensor*>& inputs,
      const vector<Tensor*>& outputs);
  virtual void compute_cpu(const vector<bool>& add);
  virtual void compute_gpu(const vector<bool>& add);
};

}

#endif