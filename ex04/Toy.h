#ifndef TOY_H_
#define TOY_H_

#include <ostream>
#include <string>
#include "Picture.h"
class Toy{
 public:
  enum ToyType{ BASIC_TOY, ALIEN, BUZZ, WOODY };
 protected:
  Picture _picture;
  ToyType _type;
  std::string _name;
  std::string e;
 public:

  Toy();
  Toy(const Toy &);
  Toy(ToyType type, const std::string &name, const std::string &file);
  virtual ~Toy(){};
  //get
  ToyType getType() const;
  std::string getName() const;
  std::string getAscii() const;
  //set
  void setData(std::string a);
  bool setAscii(const std::string &fn);
  void setName(const std::string &fn);

  virtual void speak(const std::string &s);
  virtual bool speak_es(const std::string &s);

  Toy	operator=(const Toy &s);
    
  class Error{
  public:
    Error(){};
    ~Error(){};
    typedef enum { UNKNOWN, PICTURE, SPEAK } ErrorType;
    ErrorType type;
    std::string _what;
    std::string _where;
    std::string where(){ return _where; }
    std::string what(){ return _what; }
  };
  Toy::Error getLastError();
};

std::ostream &operator<<(std::ostream &f, const Toy &a);
Toy &operator<<(Toy &a, const std::string &str);

#endif /* dream0630 */
