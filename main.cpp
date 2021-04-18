#include "Monitor.h"

#include <chrono>
using namespace std::chrono;
int main()
{
  auto begin_t = high_resolution_clock::now();
  try 
  {
    //运行时请将此处设置为DEM_TXT目录的路径
    Monitor::setDEM_TXT_dir_path("D:\\CppProject\\scu-zrkc\\DEM_TXT\\");
    //此处表示展示每个文件中的高度前30
    Monitor::setTopNtoShow(30);
    Monitor m;
    m.showEachFile();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
  auto end_t = high_resolution_clock::now();
  duration<double, std::milli> time_span = end_t - begin_t;

  std::cout << time_span.count() << std::endl;
  return 0;
}