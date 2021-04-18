#ifndef MONITOR_H
#define MONITOR_H

#include "File.h"

class Monitor
{
  public:
  static uint top_n_to_show;
  static std::string dictionary_path;
  static const constexpr uint txtfile_num = 9;

  static void setDEM_TXT_dir_path(std::string path);
  static void setTopNtoShow(uint n);
  
  private:
  std::vector<File> all_data_;
  
  public:
  Monitor();
  Monitor(const Monitor&) = delete;
  void showEachFile(void);
};

#endif //MONITOR_H