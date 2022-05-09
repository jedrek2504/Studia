#ifndef STATEKMKAR2020_LADUNEK_HPP
#define STATEKMKAR2020_LADUNEK_HPP

#include <string>

class Ladunek {
public:
  virtual ~Ladunek()= default;
  virtual uint32_t obliczMase() const =0 ;
  virtual std::string toString() const=0;

protected:
  std::string nazwa;
};


#endif //STATEKMKAR2020_LADUNEK_HPP
