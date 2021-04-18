#include "File.h"

File::File(const std::string& file_name)
  :file_name_(file_name),
  in_(file_name, std::ios::in),
  data_(),
  max_lat_(0), min_lat_(UINT32_MAX), max_lon_(0), min_lon_(UINT32_MAX),
  grid_(), lon_(), lat_()  {}

File::File(const File& f)
    :file_name_(f.file_name_),
    in_(f.file_name_, std::ios::in),
    data_(),
    max_lat_(f.max_lat_), min_lat_(f.min_lat_), max_lon_(f.max_lon_), min_lon_(f.min_lon_),
    grid_(), lon_(), lat_() {}

void File::sortData()
{  std::sort(this->data_.begin(), this->data_.end()); }

void File::inputObj(std::string& line)
{
  size_t pos = line.find_last_of(',');
  uint lat = std::stoi(std::string(line, pos + 1, line.find_last_of('.') - pos - 1));
  line.erase(pos, line.size() - 1);

  pos = line.find_last_of(',');
  uint lon = std::stoi(std::string(line, pos + 1, line.find_last_of('.') - pos - 1));
  line.erase(pos, line.size() - 1);

  pos = line.find_last_of(',');
  uint grid = std::stoi(std::string(line, pos + 1, line.find_last_of('.') - pos - 1));

  uint id = std::stoi(std::string(line, 0, line.find_first_of(',')));
 
  this->data_.emplace_back(id, grid, lon, lat);
  this->max_lat_ = lat > this->max_lat_ ? lat : this->max_lat_;
  this->min_lat_ = lat < this->min_lat_ ? lat : this->min_lat_;
  this->max_lon_ = lon > this->max_lon_ ? lon : this->max_lon_;
  this->min_lon_ = lon < this->min_lon_ ? lon : this->min_lon_;
}

void File::setSuffix()
{
  this->grid_ = ".0000000";
  this->lat_  = ".5000000";
  this->lon_  = ".8750000";
}

void File::init()
{
  this->data_.reserve(125000);
  this->setSuffix();

  std::string line;
  std::getline(this->in_, line, '\n');


  while (in_.good() && std::getline(in_, line, '\n'))
    this->inputObj(line);
}

void File::showTop(int n)
{
  if (this->data_.size() != 0)
  {
    this->data_.shrink_to_fit();
    this->sortData();
    std::cout << "Top " << n << " is : \n" 
              << "-------------" << std::endl;
    for(size_t i = 0; i < n; i++)
      std::cout << data_.at(i) << '\n';
    std::cout << std::endl;
  }
}

void File::showLimit()
{
  if (this->data_.size() != 0)
  {
    std::cout << "in file : " << this->file_name_ << '\n';
    std::cout << "Lon in range [" << this->min_lon_ << ','
              << this->max_lon_ << "]\n";
    std::cout << "Lat in range [" << this->min_lat_ << ','
              << this->max_lat_ << ']' << std::endl;
  }
  else
  {
    std:: cout << "accessing file :" << this->file_name_ << " failed!" <<std::endl;
  }
}


File::~File()
{
  this->in_.close();
}
