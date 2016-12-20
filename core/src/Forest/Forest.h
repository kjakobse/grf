#ifndef GRADIENTFOREST_FOREST_H_
#define GRADIENTFOREST_FOREST_H_

#include "../Tree/TreeModel.h"
#include "globals.h"
#include "Tree.h"
#include "Data.h"
#include "prediction/PredictionStrategy.h"

class Forest {
public:
  Forest(std::vector<Tree*>* trees,
         Data* data,
         std::unordered_map<std::string, size_t> observables);
  virtual ~Forest();

  const std::unordered_map<std::string, std::vector<double>> get_original_observations() const {
    return original_observations;
  };

  const std::vector<Tree*>* get_trees() const {
    return trees;
  }

protected:
  std::vector<Tree*>* trees;

  Data* data;
  std::unordered_map<std::string, size_t> observables_by_ID;
  std::unordered_map<std::string, std::vector<double>> original_observations;

private:
  DISALLOW_COPY_AND_ASSIGN(Forest);
};

#endif /* GRADIENTFOREST_FOREST_H_ */