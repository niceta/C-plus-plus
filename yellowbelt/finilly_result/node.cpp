#include "node.h"

DateComparisonNode::DateComparisonNode(Comparison cmp, const Date & date)
  : cmp_(cmp), date_(date) {}

bool DateComparisonNode::Evaluate(const Date & date, const std::string & ev) {
  return expComp(cmp_, date, date_);
}

EventComparisonNode::EventComparisonNode(Comparison cmp, const std::string & val) 
  : cmp_(cmp), val_(val) {}

bool EventComparisonNode::Evaluate(const Date & date, const std::string & ev) {
  return expComp(cmp_, ev, val_);
}

bool EmptyNode::Evaluate(const Date & date, const std::string & ev) {
  return true;
}

LogicalOperationNode::LogicalOperationNode(LogicalOperation logOp,
  std::shared_ptr<Node> left, std::shared_ptr<Node> exp) 
  : logOp_(logOp), left_(left), exp_(exp) {}

bool LogicalOperationNode::Evaluate(const Date & date, const std::string & ev) {
  return logComp(logOp_, left_->Evaluate(date, ev), exp_->Evaluate(date, ev));
}
