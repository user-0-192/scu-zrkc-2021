#ifndef FILE_H
#define FILE_H

#include "Obj.h"

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

class File
{
  private:
  std::fstream in_;

  std::string file_name_;

  std::vector<Object> data_;

  uint max_lat_, min_lat_, max_lon_, min_lon_;

  //suffix of ecah object in target file
  std::string grid_;
  std::string lon_;
  std::string lat_;

  public:
  File() = delete;
  File(const std::string& file_name);
  File(const File&);

  void init();
  void showTop(int n);
  void showLimit();
  ~File();

  private:
  void setSuffix();
  void inputObj(std::string& line);
  void sortData();
  std::string format(Object& obj);
};
#endif  //FILE_H