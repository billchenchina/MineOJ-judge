//Before the project complete,main.cpp will be exclude from all the build.
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <sstream>
int main(int argc,char **argv){
    // TODO use log4cxx
    // http://logging.apache.org/log4cxx/
    time_t current_time;
    time(&current_time);
    tm *time_p=new tm;
    time_p=localtime(&current_time);
    std::string time_str;
    std::stringstream ss;
    ss<<std::fixed<<std::setw(4)<<(time_p->tm_year+1900)
                  <<std::setw(2)<<(time_p->tm_mon+1)
                  <<std::setw(2)<<(time_p->tm_mday);
    ss>>time_str;
    std::ofstream logfile(time_str+".log");
    std::clog.rdbuf(logfile.rdbuf());
    return 0;
}
