#pragma once
#include <string>
#include <memory>

#include "date.h"


enum Comparison {
  Less,
  LessOrEqual,
  Greater,
  GreaterOrEqual,
  Equal,
  NotEqual
};

enum LogicalOperation {
  Or,
  And
};

class ExpComp {
public:
  template <class Exp>
  bool operator()(Comparison cmp, const Exp& e1, const Exp& e2) const {
    switch (cmp) {
    case Comparison::Equal:
      return e1 == e2;
      break;
    case Comparison::NotEqual:
      return !(e1 == e2);
      break;
    case Comparison::Less:
      return e1 < e2;
      break;
    case Comparison::LessOrEqual:
      return (e1 < e2) || (e1 == e2);
      break;
    case Comparison::Greater:
      return !((e1 < e2) || (e1 == e2));
      break;
    case Comparison::GreaterOrEqual:
      return !(e1 < e2);
      break;
    default:
      return false;
    }
  }
};

class LogComp {
public:
  template<class Exp>
  bool operator()(LogicalOperation logOp, const Exp& e1, const Exp& e2) const {
    switch (logOp) {
    case Or:
      return e1 || e2;
      break;
    case And:
      return e1 && e2;
      break;
    default:
      return false;
    }
  }
};

class Node {
public:
  virtual bool Evaluate(const Date& date, const std::string& ev) = 0;
};

class EmptyNode : public Node {
public:
  bool Evaluate(const Date& date, const std::string& ev) override;
};

class DateComparisonNode : public Node {
public:
  DateComparisonNode(Comparison cmp, const Date& date);
  bool Evaluate(const Date& date, const std::string& ev) override;
private:  
  const Date date_;
  const Comparison cmp_;
  ExpComp expComp;
};

class EventComparisonNode : public Node {
public:
  EventComparisonNode(Comparison cmp, const std::string& val);
  bool Evaluate(const Date& date, const std::string& ev) override;
private:
  const std::string val_;
  const Comparison cmp_;
  ExpComp expComp;
};

class LogicalOperationNode : public Node {
public:
  LogicalOperationNode(LogicalOperation logOp, 
    std::shared_ptr<Node> left, std::shared_ptr<Node> exp);
  bool Evaluate(const Date& date, const std::string& ev) override;
private:
  LogicalOperation logOp_;
  std::shared_ptr<Node> left_;
  std::shared_ptr<Node> exp_;
  LogComp logComp;
};