#include "Monitor.h"


std::string Monitor::dictionary_path = ".\\DEM_TXT\\";
uint Monitor::top_n_to_show = 30;

void Monitor::setDEM_TXT_dir_path(std::string path)
{
  Monitor::dictionary_path = path;
}
void Monitor::setTopNtoShow(uint n)
{
  Monitor::top_n_to_show = n;
}

Monitor::Monitor()
{
  assert(this->all_data_.empty());
  for (int i = 1; i <= Monitor::txtfile_num; i++)
  {
    all_data_.emplace_back(std::string(Monitor::dictionary_path + std::to_string(i) + ".txt"));
  }
}

void Monitor::showEachFile(void)
{
  for(auto& data : all_data_)
    data.init(), data.showLimit(), data.showTop(Monitor::top_n_to_show);
}
